/*
 Project 3 - Part 3 / 5
 video: Chapter 2 - Part 8
 Constructors tasks

 Create a branch named Part3

 On this new branch:

 0) if you opted to not fill in any of your member functions in part2, 
    fill in ALL of your member functions
    
 1) Add a constructor for each User-Defined-Type.
    add a std::cout message in the constructor that prints out the name of the class being constructed.  
    When you run your code, you'll see the order that your objects are created in the program output. 
 
 2) For each User-Defined-Type:
        amend some of the member functions to print out something interesting via std::cout
 
 3) Instantiate 1 or 2 instances of each of your user-defined types in the main() function.

 4) For each instantiated UDT: 
        call each of that instance's member functions.
        You're doing this to show that your code doesn't produce warnings when you call the functions that take arguments.
 
 5) add some std::cout statements in main() that print out your UDT's member variable values or values returned from your UDT member functions (if they return values)
 
 After you finish defining each type/function:
 click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 
 example:
 */

#include <iostream>
namespace Example 
{
struct UDT  // my user defined type named 'UDT'
{
    int a; //a member variable
    UDT();              //1) the constructor
    void printThing();  //the member function
};

//the function definitions are outside of the class
UDT::UDT()
{
    a = 0;
}

void UDT::printThing()
{
    std::cout << "UDT::printThing() " << a << std::endl;  //2) printing out something interesting
}

int main()
{
    UDT foo;              //3) instantiating a UDT named 'foo' in main()
    foo.printThing();     //4) calling a member function of the UDT instance.
    
    //5) a std::cout statement accessing foo's member variable.
    //It also demonstrates a 'ternary expression', which is syntactic shorthand for an 'if/else' expression
    std::cout << "Is foo's member var 'a' equal to 0? " << (foo.a == 0 ? "Yes" : "No") << "\n";
    
    return 0;
}
} //end namespace Example

//insert Example::main() into main() of user's repo.




struct Compressor
{
    double threshold = -10.5;
    float ratio = 4.5f;
    float outputGain = -1.5f;
    float inputGain = -11.0f;
    int compType = 2;

    struct Saturator
    {
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
};

void Compressor::compress(double audioIn)
{
    if (audioIn > threshold)
    {
        if (compType == 0)
            std::cout << "Compressing with ratio of: " << ratio << " using Peak algorithm." << std::endl;
        else
            std::cout << "Compressing with ratio of: " << ratio << " using RMS algorithm." << std::endl;
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
    double flourAmount = 25.7;
    int numCake = 10;
    int numBread = 38;
    float numMoney = 8392.21f;
    int maxOvenTemp = 350;

    struct RyeBread
    {
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

void Bakery::bakeBread(RyeBread brd)
{
    std::cout << "Flour used: " << flourAmount << std::endl << "Timer set to: " << brd.bakingTime << std::endl;
}

float Bakery::cakeSell(std::string cakeName)
{
    if (cakeName == "Sweet Cake")
    {
        std::cout << "Product sold: " << cakeName << std::endl;
        return 9430.f;
    }
    
    return 0.f;
}

void Bakery::smellGreat()
{
}

struct AquaPark
{
    int numPools = 5;
    int numSaunas = 3;
    float totalWaterSlidesLength = 121.56f;
    float openAt = 9.30f;
    float regularTicker = 13.21f;

    void relaxMuscles(int swimmingIntensity);
    void haveFun(int numberOfSlides);
    bool learnToSwim(int age, int timeSpent);
};

void AquaPark::relaxMuscles(int swimmingIntensity)
{
    bool goToSauna = false;
    if (swimmingIntensity > 5)
    {
        goToSauna = true;
        std::cout << "You should use one of the sauna's to relax your muscles!" << std::endl;
    }
}
void AquaPark::haveFun(int numberOfSlides)
{
    std::cout << "Total length of our " << numberOfSlides << " slides is: " << totalWaterSlidesLength << " which means that it's not possible to NOT have fun!" << std::endl;
}
bool AquaPark::learnToSwim(int age, int timeSpent)
{
    if (age < 10 && timeSpent > 60)
        return true;
    else if (age >= 10 && timeSpent > 120)
        return true;

    return false;
}

struct House
{
    int numWindows = 8;
    float livingRoomSize = 31.8f;
    float roomHeight = 2.8f;
    int numBathRooms = 3;
    float totalFloorSize = 155.2f;

    void provideShelter();
    void provideRest(float sleepQuality);
    bool getDirty(int numPeople, int numAnimals);
};

void House::provideShelter()
{
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
    if (totalFloorSize / (numPeople + numAnimals) > 20)
        return true;

    return false;
}

struct VCA
{
    double minGain = -100.66;
    double maxGain = 10.5;
    double initGain = -20.1;
    float modAtt = -56.2f;
    int inputs = 2;

    double setInitGain();
    void modulateOutput(float modSpeed);
    void silenceOutput();
};

double VCA::setInitGain()
{
    std::cout << "Setting init gain. Current minimum is: " << minGain << " and maximum is: " << maxGain << std::endl;

    return (minGain-maxGain);
}

void VCA::modulateOutput(float modSpeed)
{
    std::cout << "Modulating output by: " << modAtt << " with the frequency of: " << modSpeed << std::endl;
}

void VCA::silenceOutput()
{
}

struct Filter
{
    float cutoffFreq = 13200.2f;
    float resonance = 0.77f;
    std::string filterType = "Low Pass";
    double inputGain = -5.3;
    float overdriveAmount = 1.7f;

    void cutLows();
    void cutHighs();
    bool selfResonate();
};

void Filter::cutLows()
{
    filterType = "High Pass";
    std::cout << "Cutting low frequencies below: " << cutoffFreq << "with a Q of: " << resonance << std::endl;
}
void Filter::cutHighs()
{
    filterType = "Low Pass";
    std::cout << "Cutting high frequencies above: " << cutoffFreq << "with a Q of: " << resonance << std::endl;
}
bool Filter::selfResonate()
{
    return resonance > 0.9f && inputGain > -35.0;
}

struct Envelope
{
    float attackTime = 22.5f;
    float decayTime = 330.2f;
    double sustainLevel = 0.99228;
    float releaseTime = 675.1f;
    float curve = 0.9f;

    void setPadPreset();
    void setStaccatoPreset();
    bool loopOver();
};

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
        eSwitch = true;
        return true;
    }

    return false;
}

struct LFO
{
    float fadeIn = 45.3f;
    double freq = 0.074;
    int shape = 2;
    int retrig = 3;
    bool polyMode = false;

    void resetState();
    void modulateFreq(float modFreq, float intensity);
    void changeSpeed();
};

void LFO::resetState()
{ 
}

void LFO::modulateFreq(float modFreq, float intensity)
{
    std::cout << "LFO frequency set to: " << freq << std::endl << "Modulation speed set to: " << modFreq << std::endl << "Modulation intensity set to: " << intensity << std::endl;
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
    float amplitude = 0.89f;
    int lengthInSamples = 644112;
    std::string waveColor = "Yellow";
    int height = 220;
    int width = 720;

    void zoomIn(float zoomInAmount);
    void zoomOut(float zoomOutAmount);
    void drawWaveform();
};

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
    VCA vca;
    Filter mainFilter;
    Envelope ampEnv;
    LFO lfo01;
    Waveform waveform;

    void loopSound(std::string sampleName, bool loopForward);
    void modulateFilter(Filter filter, LFO lfo);
    void pitchDown(std::string sampleName);
};

void Sampler::loopSound(std::string sampleName, bool loopForward)
{
    if (loopForward)
        std::cout << "Loop mode ON, direction: FORWARD, sample name: " << sampleName << std::endl;
    else
        std::cout << "Loop mode ON, direction: BACKWARD, sample name: " << sampleName << std::endl;
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
    
    
    std::cout << "good to go!" << std::endl;
}
