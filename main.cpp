/*
 Project 3 - Part 4 / 5
 video: Chapter 2 - Part 9
 Member initialization tasks

 Create a branch named Part4
 
 1) do this for each class in this project: 
    initialize some of your member variables either in-class or in the Constructor member initializer list.

 2) make some of your member functions use those initialized member variables via std::cout statements.
 
 3) click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */

#include <iostream>
namespace Example 
{
struct UDT  
{
    int a; //a member variable
    float b { 2.f }; // in-class initialization
    UDT() : a(0) { } // 'constructor-initializer-list' member variable initialization
    void printThing()  //the member function
    {
        std::cout << "UDT::printThing() a:" << a << " b: " << b << std::endl;  //4) printing out something interesting
    }
};

int main()
{
    UDT foo; //instantiating a Foo in main()
    foo.printThing(); //calling a member function of the instance that was instantiated.
    return 0;
}
}

//call Example::main()


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

struct Bakery
{
    Bakery();
    double flourAmount;
    int numCake;
    int numBread;
    float numMoney;
    int maxOvenTemp;

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

    RyeBread breadToSell;
};

Bakery::Bakery() : flourAmount(22.7), numCake(10), numBread(38), numMoney(8392.21f), maxOvenTemp(350)
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

struct AquaPark
{
    AquaPark();
    int numPools = 5;
    int numSaunas = 3;
    float totalWaterSlidesLength = 121.56f;
    float openAt = 9.30f;
    float regularTicker = 13.21f;

    void relaxMuscles(int swimmingIntensity);
    void haveFun(int numberOfSlides);
    bool learnToSwim(int age, int timeSpent);
};

AquaPark::AquaPark()
{
    std::cout << "AquaPark constructed." << "\n";
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

    void provideShelter();
    void provideRest(float sleepQuality);
    bool getDirty(int numPeople, int numAnimals);
};

House::House() : numWindows(8), livingRoomSize(31.8f), roomHeight(2.8f), numBathRooms(3), totalFloorSize(155.2f)
{
    std::cout << "House constructed." << "\n";
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
    float modAtt = -56.2f;
    int inputs = 2;

    double setInitGain();
    void modulateOutput(float modSpeed);
    void silenceOutput();
};

VCA::VCA()
{
    std::cout << "VCA constructed." << "\n";
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
};

Filter::Filter()
{
    std::cout << "Filter constructed." << "\n";
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

    void setPadPreset();
    void setStaccatoPreset();
    bool loopOver();
};

Envelope::Envelope()
{
    std::cout << "Envelope constructed." << "\n";
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
};

LFO::LFO()
{
    std::cout << "LFO constructed." << "\n";
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

    void zoomIn(float zoomInAmount);
    void zoomOut(float zoomOutAmount);
    void drawWaveform();
};

Waveform::Waveform()
{
    std::cout << "Waveform constructed." << "\n";
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

    void loopSound(std::string sampleName, bool loopForward);
    void modulateFilter(Filter filter, LFO lfo);
    void pitchDown(std::string sampleName);
};

Sampler::Sampler()
{
    std::cout << "Sampler constructed." << "\n";
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
    
    std::cout << "\n";

    bakedBakery.bakeBread(bakedBakery.breadToSell);
    bakedBakery.cakeSell("That cake over there");
    bakedBakery.smellGreat();

    std::cout << "\n";

    aquaPark.relaxMuscles(3);
    aquaPark.haveFun(4);
    aquaPark.learnToSwim(9, 359);

    std::cout << "\n";

    smallHouse.totalFloorSize = 80.2f;
    smallHouse.provideShelter();
    smallHouse.provideRest(3.58f);
    smallHouse.getDirty(2, 0);

    std::cout << "\n";

    bigHouse.totalFloorSize = 280.5f;
    bigHouse.provideShelter();
    bigHouse.provideRest(4.58f);
    bigHouse.getDirty(5, 2);

    std::cout << "\n";

    std::cout << "Initial gain value: " << vcaA.initGain << "\n";
    vcaA.setInitGain();
    vcaA.modulateOutput(1.5f);
    vcaA.silenceOutput();
    std::cout << "Initial gain value: " << vcaA.initGain << "\n";

    std::cout << "\n";

    mainFilter.cutoffFreq = 300.0f;
    mainFilter.cutLows();
    mainFilter.cutoffFreq = 13343.5f;
    mainFilter.cutHighs();
    mainFilter.selfResonate();
    std::cout << "Is filter currently self resonating? " << (mainFilter.selfResonate() == true ? "Answer: YES" : "Answer: NO") << "\n";
    mainFilter.resonance = 0.93f;
    std::cout << "Changed resonance to 0.93, is it resonating now? " << (mainFilter.selfResonate() == true ? "Answer: YES" : "Answer: NO") << "\n";

    std::cout << "\n";

    ampEnv.setPadPreset();
    ampEnv.setStaccatoPreset();
    ampEnv.loopOver();

    std::cout << "\n";

    lfo01.resetState();
    lfo01.modulateFreq(5.2f, 0.9f);
    lfo01.changeSpeed();

    std::cout << "\n";

    compactWaveform.zoomIn(5.3f);
    compactWaveform.waveColor = "Slate Grey";
    compactWaveform.zoomOut(0.78f);
    compactWaveform.drawWaveform();

    std::cout << "\n";

    lofiSampler.loopSound("violin_C3", false);
    lofiSampler.modulateFilter(mainFilter, lfo01);
    lofiSampler.pitchDown("piano_soft_c#2");
    std::cout << "Lofi Sampler filter cutoff settings: " << lofiSampler.mainFilter.cutoffFreq << " Hz \n" << "Lofi sampler filter resonance: " << lofiSampler.mainFilter.resonance << "\n";

    std::cout << "\n";
    
    std::cout << "good to go!" << std::endl;
}
