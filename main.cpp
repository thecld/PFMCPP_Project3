/*
 Project 3 - Part 5 / 5
 video: Chapter 2 - Part 10
 Scope and Lifetime tasks
 
Create a branch named Part5

 video covered:
    variable scope and lifetime relative to { }
    while loops
    for loops()
 
 tasks
 
 1) add some new member functions to EACH of your types. 
 
 2) inside these new member functions, use while() and for() loops to do something interesting 
         a) example: have a loop that modifies a member variable of some object created outside the loop.
         b) when that member variable reaches a certain threshold, return it mid-loop.
         c) maybe use function parameters to control the starting value of that member variable or control the threshold
         
 3) call those new member functions in main()
 
 4) use std::cout statements to print out information about what your loops did.
    Your code should produce a lot of console output now.
 
 5) click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */

#include <iostream>
#include <cmath>

namespace Example 
{
struct Bar 
{ 
    int num = 0; 
    Bar(int n) : num(n) { } 
};
struct Foo
{
    Bar scopeLifetimeFunc( int threshold, int startingVal ) //1), 2c) 
    {
        Bar bar(startingVal);                //2a)
        while( bar.num < threshold )         //2a) 
        { 
            bar.num += 1;                    //2a)
            std::cout << "  increasing bar.num: " << bar.num << std::endl; //4)
            if( bar.num >= threshold )       //2b)
                return bar;
        }
        
        return Bar {-1}; //if your startingValue >= threshold, the while loop never runs
    }
};

int main()
{
    Foo foo;
    auto bar = foo.scopeLifetimeFunc(3, 1);        //3) 
    
    std::cout << "bar.num: " << bar.num << std::endl;     //4) 
    return 0;
}
}

//call Example::main() in main()





struct Compressor
{
    Compressor();
    double threshold { -10.5 };
    float ratio { 4.5f };
    float outputGain { -1.5f };
    float inputGain { -11.0f };
    int compType = 2;

    struct Saturator
    {
        Saturator();
        int satType = 0;
        double gain = -10.5;
        float inputFilter = 10000.0f;
        float outputFilter = 1600.5f;
        float mix = 77.7f;

        void changeType(int satType);
        bool checkClipping();
        void oversample(bool oversampling);
    };

    void compress(double audioIn);
    void volumeMakeUp();
    void saturateInput(Saturator sat);
    double rampThreshold(double desiredThreshold);

    Saturator satA;
};

Compressor::Compressor()
{
    std::cout << "Compressor constructed." << "\n";
}

Compressor::Saturator::Saturator()
{
    std::cout << "Nested type Saturator constructed" << "\n";
}

void Compressor::compress(double audioIn)
{
    if (audioIn > threshold)
    {
        if (compType == 0)
            std::cout << "Compressing with ratio of: " << ratio << " using Peak algorithm." << std::endl << "Threshold is set to: " << threshold << std::endl << "Output gain is set to: " << outputGain << std::endl;
        else
            std::cout << "Compressing with ratio of: " << ratio << " using RMS algorithm." << std::endl << "Threshold is set to: " << threshold << std::endl << "Output gain is set to: " << outputGain << std::endl;
    }
}

void Compressor::volumeMakeUp()
{
    float difference = inputGain - outputGain;
    std::cout << "Adjusting the volume by " << difference << std::endl;
}

void Compressor::saturateInput(Saturator sat)
{
    std::cout << "Saturation engaged! Saturator type: " << sat.satType << std::endl << "Mix parameter is set to: " << sat.mix << std::endl;
}

double Compressor::rampThreshold(double desiredThreshold)
{
    if (desiredThreshold < threshold)
    {
        while (threshold > desiredThreshold)
        {
            if (threshold <= desiredThreshold)
                return threshold;

            threshold -= 0.1;
            std::cout << "Desired threshold is smaller, ramping down threshold: " << threshold << "\n"; 
        }
    }
    else
    {
        while (threshold < desiredThreshold)
        {
            if (threshold >= desiredThreshold)
                return threshold;

            threshold += 0.1;
            std::cout << "Desired threshold is bigger, ramping up threshold: " << threshold << "\n";
        }
    }
    std::cout << "Desired threshold is the same as initial threshold." << "\n";
    return threshold;
}

struct Bakery
{
    Bakery();
    double flourAmount;
    int numCake;
    int numBread;
    float numMoney;
    int maxOvenTemp;
    int minutesLeft;

    struct RyeBread
    {
        RyeBread();
        int bakingTime = 45;
        float bakingTemp = 350.0f;
        float numPumpkinSeeds = 5.5f;
        float numLinseed = 2.3f;
        bool bioIngredients = 1;

        void mixIngredients();
        float getWeight(float flourUsed, float numPumpkinSeeds, float numLinseed);
        bool burn(int bakingTime);
    };

    void bakeBread(RyeBread brd);
    float cakeSell(std::string cakeName);
    void smellGreat();
    int minuteTimer(int timeAmount);

    RyeBread breadToSell;
};

Bakery::Bakery() : flourAmount(22.7), numCake(10), numBread(38), numMoney(8392.21f), maxOvenTemp(350), minutesLeft(0)
{
    std::cout << "Bakery constructed." << "\n";
}

Bakery::RyeBread::RyeBread()
{
    std::cout << "Nested type RyeBread constructed" << "\n";
}

void Bakery::bakeBread(RyeBread brd)
{
    std::cout << "Flour used: " << flourAmount << std::endl << "Timer set to: " << brd.bakingTime << std::endl << "Oven set to: " << maxOvenTemp << std::endl;
}

float Bakery::cakeSell(std::string cakeName)
{
    if (cakeName == "Sweet Cake")
    {
        std::cout << "Product sold: " << cakeName << std::endl;
        return 9430.f;
    }

    std::cout << "Product unavailable" << std::endl;
    return 0.f;
}

void Bakery::smellGreat()
{
    std::cout << "Smelling great!" << std::endl;
}

int Bakery::minuteTimer(int timeAmount)
{
    minutesLeft = timeAmount;
    while (minutesLeft >= 0)
    {
        if (minutesLeft > 1)
        {
            std::cout << "Baking, time left: " << minutesLeft << " minutes.\n";
        }
        else
        {
            if (minutesLeft > 0)
            {
                std::cout << "Baking, time left: " << minutesLeft << " minute.\n";
            }
            else
            {
                std::cout << "Time left: " << minutesLeft << " minutes. Baking completed.\n";
                return minutesLeft;
            }
        }
        --minutesLeft;        
    }
    std::cout << "Invalid input, please insert positive value. Setting timer to 0.\n";
    return minutesLeft = 0;
}

struct AquaPark
{
    AquaPark();
    int numPools = 5;
    int numSaunas = 3;
    float totalWaterSlidesLength = 121.56f;
    float openAt = 9.30f;
    float regularTicker = 13.21f;
    int numCustomers = 0;

    void relaxMuscles(int swimmingIntensity);
    void haveFun(int numberOfSlides);
    bool learnToSwim(int age, int timeSpent);
    int leavingCustomersCounter(int numCustomersStillInside);
};

AquaPark::AquaPark()
{
    std::cout << "AquaPark constructed." << "\n";
}

int AquaPark::leavingCustomersCounter(int numCustomersStillInside)
{
    numCustomers = numCustomersStillInside;
    while (numCustomers >= 0)
    {
        if (numCustomers == 0)
        {
            std::cout << "No one's left, let's close for today!\n";
            return numCustomers;
        }
        else
        {
            std::cout << "Number of customers still inside: " << numCustomers << "\n";
        }
        --numCustomers;
    }
    std::cout << "You can't have negative number of customers inside, please enter correct value.\n";
    return numCustomers = 0;
}

void AquaPark::relaxMuscles(int swimmingIntensity)
{
    bool goToSauna = false;
    if (swimmingIntensity > 5)
    {
        goToSauna = true;
        std::cout << "You should use one of the sauna's to relax your muscles!" << std::endl;
    }
    else
    {
        std::cout << "Don't need to use a sauna." << std::endl;
    }
}

void AquaPark::haveFun(int numberOfSlides)
{
    std::cout << "Total length of our " << numberOfSlides << " slides is: " << totalWaterSlidesLength << " which means that it's not possible to NOT have fun!" << std::endl;
}

bool AquaPark::learnToSwim(int age, int timeSpent)
{
    if (age < 10 && timeSpent > 60)
    {
        std::cout << "Learned how to swim!" << "\n";
        return true;
    }
    else if (age >= 10 && timeSpent > 120)
    {
        std::cout << "Learned how to swim!" << "\n";
        return true;
    }

    std::cout << "Still can't swim..." << "\n";
    return false;
}

struct House
{
    House();
    int numWindows;
    float livingRoomSize;
    float roomHeight;
    int numBathRooms;
    float totalFloorSize;
    int roomsToClean;

    void provideShelter();
    void provideRest(float sleepQuality);
    bool getDirty(int numPeople, int numAnimals);
    int cleaningProcedure(int numDirtyRooms, int secondsPerRoom);
};

House::House() : numWindows(8), livingRoomSize(31.8f), roomHeight(2.8f), numBathRooms(3), totalFloorSize(155.2f), roomsToClean(0)
{
    std::cout << "House constructed." << "\n";
}

int House::cleaningProcedure(int numDirtyRooms, int secondsPerRoom)
{
    if (secondsPerRoom > -1)
    {
        int cleaningTimer;
        roomsToClean = numDirtyRooms;
        while (roomsToClean >= 0)
        {
            cleaningTimer = secondsPerRoom;
            while (cleaningTimer > 0 && roomsToClean > 0)
            {
                std::cout << "Cleaning. Rooms left: " << roomsToClean << " | Time left: " << (roomsToClean*secondsPerRoom) - (secondsPerRoom-cleaningTimer) << "s. \n";
                --cleaningTimer;
            }
            if (roomsToClean == 0)
            {
                std::cout << "Cleaning completed. There's " << roomsToClean << " rooms left to clean.\n";
                return roomsToClean;
            }
            --roomsToClean;
        }
    }

    std::cout << "Negative values aren't allowed. Please enter correct value.\n";
    return roomsToClean = 0;
}

void House::provideShelter()
{
    std::cout << "Home sweet home!" << std::endl;
}

void House::provideRest(float sleepQuality)
{
    if (sleepQuality > 3)
        std::cout << "Conratulations, you managed to get rest!" << std::endl;
    else
        std::cout << "Sorry buddy, you'll be sleepy for the rest of the day." << std::endl;
}

bool House::getDirty(int numPeople, int numAnimals)
{
    if (totalFloorSize / (numPeople + numAnimals) < (totalFloorSize * 0.4f))
    {
        std::cout << "There's " << numPeople << " people and " << numAnimals << " animals living on " << totalFloorSize << " square meters. House needs some cleaning!" << "\n";
        return true;
    }

    std::cout << "There's " << numPeople << " people and " << numAnimals << " animals living on " << totalFloorSize << " square meters. House is clean, sweet!" << "\n";
    return false;
}

struct VCA
{
    VCA();
    double minGain = -100.66;
    double maxGain = 10.5;
    double initGain = -20.1;
    double currentGain = initGain;
    float modAtt = -56.2f;
    int inputs = 2;

    double setInitGain();
    void modulateOutput(float modSpeed);
    void silenceOutput();
    double updateCurrentGain();
};

VCA::VCA()
{
    std::cout << "VCA constructed." << "\n";
}

double VCA::updateCurrentGain()
{
    currentGain = minGain;
    double currentModPos = 0.0;

    while (currentModPos <= 1.0)
    {
        currentModPos += 0.05;
        currentGain = (maxGain - minGain) * currentModPos + minGain;
        std::cout << "Current gain: " << currentGain << "\n";   

        if (currentModPos >= 1.0)
            return currentGain;
        
    }
    return currentGain;
}

double VCA::setInitGain()
{
    initGain = minGain + maxGain;
    std::cout << "Setting init gain. Current minimum is: " << minGain << " and maximum is: " << maxGain << std::endl;

    return initGain;
}

void VCA::modulateOutput(float modSpeed)
{
    std::cout << "Modulating output by: " << modAtt << " with the frequency of: " << modSpeed << std::endl;
}

void VCA::silenceOutput()
{
    std::cout << "Audio output silenced by VCA." << std::endl;
}

struct Filter
{
    Filter();
    float cutoffFreq = 13200.2f;
    float resonance = 0.77f;
    std::string filterType = "Low Pass";
    double inputGain = -5.3;
    float overdriveAmount = 1.7f;

    void cutLows();
    void cutHighs();
    bool selfResonate();
    void modulateCutoff(float modulationAmount);
};

Filter::Filter()
{
    std::cout << "Filter constructed." << "\n";
}

void Filter::modulateCutoff(float modulationAmount)
{
    float currentModPos = -0.05f;
    float startingCutoff = cutoffFreq;
    bool modDirection = true, modActive = true;

    while (modActive)
    {
        if (modDirection)
        {
            currentModPos += 0.05f;
            if (currentModPos > 1.f)
                modDirection = false;
        }
        else
        {
            if (currentModPos <= 0.05f)
                modActive = false; 

            currentModPos -= 0.05f;
        }
                
        cutoffFreq = ((modulationAmount + startingCutoff) - startingCutoff) * currentModPos + startingCutoff;
        std::cout << "Filter Cutoff " << cutoffFreq << " Hz\n";   
    }
}

void Filter::cutLows()
{
    filterType = "High Pass";
    std::cout << "Cutting low frequencies below: " << cutoffFreq << " Hz, with a Q of: " << resonance << std::endl;
}

void Filter::cutHighs()
{
    filterType = "Low Pass";
    std::cout << "Cutting high frequencies above: " << cutoffFreq << " Hz, with a Q of: " << resonance << std::endl;
}

bool Filter::selfResonate()
{
    return resonance > 0.9f && inputGain > -35.0;
}

struct Envelope
{
    Envelope();
    float attackTime { 22.5f };
    float decayTime { 330.2f };
    double sustainLevel { 0.99228 };
    float releaseTime { 675.1f };
    float curve { 0.9f };
    std::string envState { "Env inactive" };

    void setPadPreset();
    void setStaccatoPreset();
    bool loopOver();
    void currentEnvState(float timeSinceStart);
};

Envelope::Envelope()
{
    std::cout << "Envelope constructed." << "\n";
}

void Envelope::currentEnvState(float timeSinceStart)
{
    float totalEnvTime = attackTime + decayTime;
    float i;

    for (i = 0.f; i < timeSinceStart; i += 0.1f)
    {
        if (i < attackTime)
        {
            envState = "Attack stage";
        }
        else
        {
            if (i < totalEnvTime)
            {
                envState = "Decay stage";
            }
            else
            {
                envState = "Sustain stage";
            }
        }
       std::cout << "Time passed: " << i << "ms | Current env state: " << envState << "\n";
    }
    std::cout << "Time passed: " << i << "ms | Function stopped at: " << envState << "\n";
}

void Envelope::setPadPreset()
{
    attackTime = 1500.f;
    sustainLevel = 1.0;
    releaseTime = 4500.f;
    std::cout << "Setting envelope to slow setting, with curve of: " << curve << std::endl;
}

void Envelope::setStaccatoPreset()
{
    attackTime = 2.f;
    decayTime = 300.f;
    sustainLevel = 0.0;
    releaseTime = 300.f;
    std::cout << "Setting envelope to fast setting, with curve of: " << curve << std::endl;
}

bool Envelope::loopOver()
{
    bool eSwitch = false;

    if ((attackTime + decayTime + releaseTime) < 700.f)
    {
        std::cout << "Total envelope time: " << attackTime + decayTime + releaseTime << " ms -> Envelope loop is ON." << "\n";
        eSwitch = true;
        return true;
    }

    std::cout << "Total envelope time: " << attackTime + decayTime + releaseTime << " ms -> Envelope loop is OFF." << "\n";
    return false;
}

struct LFO
{
    LFO();
    float fadeIn = 45.3f;
    double freq = 0.074;
    int shape = 2;
    int retrig = 3;
    bool polyMode = false;

    void resetState();
    void modulateFreq(float modFreq, float intensity);
    void changeSpeed();

    double cycleCounter(int numSeconds);
};

LFO::LFO()
{
    std::cout << "LFO constructed." << "\n";
}

double LFO::cycleCounter(int numSeconds)
{
    double cyclesPerSeconds = 1.0 / freq;
    double cyclesPassed = 0.0;

    std::cout << "LFOs cycles per second counter. Current LFO speed: " << freq << " Hz. Counter duration set to: " << numSeconds << " seconds\n";

    for (int i = 0; i <= numSeconds; ++i)
    {
        cyclesPassed = i * cyclesPerSeconds;
        std::cout << "Seconds passed: " << i << " LFO cycles passed: " << cyclesPassed << "\n";
    }

    return cyclesPassed;
}

void LFO::resetState()
{
    std::cout << "LFO has been reset." << std::endl;
}

void LFO::modulateFreq(float modFreq, float intensity)
{
    std::cout << "LFO frequency set to: " << freq << " Hz" << std::endl << "Modulation speed set to: " << modFreq << " Hz" << std::endl << "Modulation intensity set to: " << intensity << std::endl;
}

void LFO::changeSpeed()
{
    if (shape == 0)
        std::cout << "Changing sinusoid LFO frequency." << std::endl;
    else
        std::cout << "Changing triangle LFO frequency." << std::endl;
}

struct Waveform
{
    Waveform();
    float amplitude { 0.89f };
    int lengthInSamples { 644112 };
    std::string waveColor { "Yellow" };
    int height { 220 };
    int width { 720 };
    int sampleRate { 44100 };
    float samplesMs { 0.f };

    void zoomIn(float zoomInAmount);
    void zoomOut(float zoomOutAmount);
    void drawWaveform();
    void samplesToMs(int messageInterval);
};

Waveform::Waveform()
{
    std::cout << "Waveform constructed." << "\n";
}

void Waveform::samplesToMs(int messageInterval)
{
    if (messageInterval > 0)
    {
        samplesMs = float(lengthInSamples) / float(sampleRate);
    
        std::cout << "Length of the sample in samples = " << lengthInSamples << "\n";

        for (int i = 0; i <= int(samplesMs); i += messageInterval)
        {
            std::cout << "Time passed: " << i << "ms. Time in samples: " << i * sampleRate << "\n";
        }

        std::cout << "Operation completed. Total length of the sample = " << samplesMs << "ms\n";
    }
    else
    {
        std::cout << "ERROR!\n";
    }
}

void Waveform::zoomIn(float zoomInAmount)
{
    std::cout << "This " << waveColor << " waveform needs some zooming! Commencing zoom in procedure by: " << zoomInAmount << std::endl;
}

void Waveform::zoomOut(float zoomOutAmount)
{
    std::cout << "This " << waveColor << " waveform is too big! Commencing zoom out procedure by: " << zoomOutAmount << std::endl;
}

void Waveform::drawWaveform()
{
    std::cout << "Drawing waveform in a rectangle of size: " << height << " x " << width << " with an amplitude of: " << amplitude << " and a total length of: " << lengthInSamples << " samples." << std::endl;
}

struct Sampler
{
    Sampler();
    VCA vca;
    Filter mainFilter;
    Envelope ampEnv;
    LFO lfo01;
    Waveform waveform;
    float loopCounter = 0.f;

    void loopSound(std::string sampleName, bool loopForward);
    void modulateFilter(Filter filter, LFO lfo);
    void pitchDown(std::string sampleName);
    float countLoops(int msPlayingTime = 10);
};

Sampler::Sampler()
{
    std::cout << "Sampler constructed." << "\n";
}

float Sampler::countLoops(int msPlayingTime)
{
    waveform.samplesMs = waveform.lengthInSamples / waveform.sampleRate;

    for (float i = 0.f; i <= float(msPlayingTime); ++i)
    {
        std::cout << "LOOP COUNTER -> Time passed: " << i << "ms | Loops passed (floored): " << floor(double(i) / double(waveform.samplesMs)) << "\n";
    }

    std::cout << "If you play the sample for " << msPlayingTime << "ms. It'll loop " << float(msPlayingTime) / waveform.samplesMs << " times\n";

    return float(msPlayingTime) / waveform.samplesMs;
}

void Sampler::loopSound(std::string sampleName, bool loopForward)
{
    if (loopForward)
        std::cout << "Loop mode ON, direction: FORWARD, sample name: " << sampleName << std::endl;
    else
        std::cout << "Loop mode ON, direction: BACKWARDS, sample name: " << sampleName << std::endl;
}

void Sampler::modulateFilter(Filter filter, LFO lfo)
{
    std::cout << "Modulating filter, starting frequency: " << filter.cutoffFreq << std::endl << "Modulation speed is equal to: " << lfo.freq << " Hz" << std::endl;
}

void Sampler::pitchDown(std::string sampleName)
{
    std::cout << "Sample " << sampleName << " is pitched down." << std::endl;
}



/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

#include <iostream>
int main()
{
    Example::main();

    Compressor compA;
    Bakery bakedBakery;
    AquaPark aquaPark;
    House smallHouse;
    House bigHouse;
    VCA vcaA;
    Filter mainFilter;
    Envelope ampEnv;
    LFO lfo01;
    Waveform compactWaveform;
    Sampler lofiSampler;

    std::cout << "\n";

    compA.compress(-4.56);
    compA.volumeMakeUp();
    compA.saturateInput(compA.satA);
    compA.rampThreshold(-7.0);
    compA.rampThreshold(-1.3);
    
    std::cout << "\n";

    bakedBakery.bakeBread(bakedBakery.breadToSell);
    bakedBakery.cakeSell("That cake over there");
    bakedBakery.smellGreat();
    bakedBakery.minuteTimer(13);

    std::cout << "\n";

    aquaPark.relaxMuscles(3);
    aquaPark.haveFun(4);
    aquaPark.learnToSwim(9, 359);
    aquaPark.leavingCustomersCounter(16);

    std::cout << "\n";

    smallHouse.totalFloorSize = 80.2f;
    smallHouse.provideShelter();
    smallHouse.provideRest(3.58f);
    smallHouse.getDirty(2, 0);
    smallHouse.cleaningProcedure(2,28);

    std::cout << "\n";

    bigHouse.totalFloorSize = 280.5f;
    bigHouse.provideShelter();
    bigHouse.provideRest(4.58f);
    bigHouse.getDirty(5, 2);
    bigHouse.cleaningProcedure(3,9);

    std::cout << "\n";

    std::cout << "Initial gain value: " << vcaA.initGain << "\n";
    vcaA.setInitGain();
    vcaA.modulateOutput(1.5f);
    vcaA.silenceOutput();
    vcaA.initGain = vcaA.updateCurrentGain();
    std::cout << "Initial gain value: " << vcaA.initGain << "\n";

    std::cout << "\n";

    mainFilter.cutoffFreq = 300.0f;
    mainFilter.modulateCutoff(10000.f);
    mainFilter.cutLows();
    mainFilter.cutoffFreq = 13343.5f;
    mainFilter.modulateCutoff(-3000.5f);
    mainFilter.cutHighs();
    mainFilter.selfResonate();
    std::cout << "Is filter currently self resonating? " << (mainFilter.selfResonate() == true ? "Answer: YES" : "Answer: NO") << "\n";
    mainFilter.resonance = 0.93f;
    std::cout << "Changed resonance to 0.93, is it resonating now? " << (mainFilter.selfResonate() == true ? "Answer: YES" : "Answer: NO") << "\n";

    std::cout << "\n";

    ampEnv.setPadPreset();
    ampEnv.setStaccatoPreset();
    ampEnv.loopOver();
    ampEnv.currentEnvState(10.5f);

    std::cout << "\n";

    lfo01.resetState();
    lfo01.modulateFreq(5.2f, 0.9f);
    lfo01.changeSpeed();
    lfo01.cycleCounter(5);

    std::cout << "\n";

    compactWaveform.zoomIn(5.3f);
    compactWaveform.waveColor = "Slate Grey";
    compactWaveform.zoomOut(0.78f);
    compactWaveform.drawWaveform();
    compactWaveform.samplesToMs(4);

    std::cout << "\n";

    lofiSampler.loopSound("violin_C3", false);
    lofiSampler.modulateFilter(mainFilter, lfo01);
    lofiSampler.pitchDown("piano_soft_c#2");
    std::cout << "Lofi Sampler filter cutoff settings: " << lofiSampler.mainFilter.cutoffFreq << " Hz \n" << "Lofi sampler filter resonance: " << lofiSampler.mainFilter.resonance << "\n";
    lofiSampler.countLoops(40);

    std::cout << "\n";
    
    std::cout << "good to go!" << std::endl;
}
