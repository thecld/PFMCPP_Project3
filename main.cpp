 /*
 Project 3 - Part 2 / 5
 Video: Chapter 2 Part 6
 Implementations tasks
 
Create a branch named Part2

 tasks
 0) delete all of the plain english pseudo-code you added in Part1.
   don't forget to remove the blank lines left behind after you remove your comments
   - you should be left with only your UDTs.
*/
// example:
// if you had something like this at the end of Part1e:
/*
Thing: Car Wash   
    5 properties:
        - number of vacuum cleaners
        - number of eco-friendly cleaning supplies
        - stores the amount of water used per week.
        - stores amount of profit made per week
        - number of cars serviced per day
    3 things it can do:
        - wash and wax car
        - charge customer
        - detail the car interior
 */

#include <iostream>
#include <string>
namespace Part1eVersion 
{
struct CarWash        
{
    //number of vacuum cleaners                     
    int numVacuumCleaners = 3; 
    //number of eco-friendly cleaning supplies      
    int numEcoFriendlyCleaningSupplies = 20;     
    //stores the amount of water used per week.     
    float waterUsedPerWeek = 200.f;            
    //stores amount of profit made per week         
    float profitPerWeek = 495.95f;               
    //number of cars serviced per day               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    //wash and wax car
    void washAndWaxCar( Car car ); 
    //charge customer
    float chargeCustomer(float discountPercentage);
    //detail the car interior
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}

//this is what I want to see after the code is cleaned up: 
namespace Part2Version
{
struct CarWash        
{
    int numVacuumCleaners = 3; 
    int numEcoFriendlyCleaningSupplies = 20;     
    float waterUsedPerWeek = 200.f;            
    float profitPerWeek = 495.95f;               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    void washAndWaxCar( Car car ); 
    float chargeCustomer(float discountPercentage);
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}
  /*
    The above snippet is just an example showing you how to clean up your code.  
    Do not put your cleaned up code into a namespace like I have done here.

 1) write the definition for the Type that leftFoot and rightFoot are instantiations of.
    don't forget to define and implement the member functions 'stepForward()' and 'stepSize()'
    you should be able to deduce the return type of those functions based on their usage in Person::run()
    You'll need to insert the Person struct from the video in the space below.
 */

struct Person
{
    int age;
    int height;
    float hairLength;
    float GPA;
    unsigned int SATScore;
    int distanceTravelled;

    struct HumanFoot
    {
        float footSize = 28.5;

        void stepForward()
        {
        }     

        float stepSize()
        {
            return footSize*3.5f;
        }
    };

    HumanFoot leftFoot;
    HumanFoot rightFoot;

    void run(int howFast, bool startWithLeftFoot);
};

void Person::run(int howFast, bool startWithLeftFoot)
{
    if (startWithLeftFoot)
    {
        leftFoot.stepForward();
        rightFoot.stepForward();
    } 
    else
    {
        rightFoot.stepForward();
        leftFoot.stepForward();
    }
    distanceTravelled += leftFoot.stepSize() + rightFoot.stepSize();
    std::cout << "Person starts to run with a speed of: " << howFast << std::endl;
}



 /*
 2) provide implementations for the member functions you declared in your 10 user-defined types from the previous video outside of your UDT definitions.
    If you have warnings about 'unused parameter', you aren't using one of your function parameters in your implementation.
    use the parameter in your implementation.
    If you have warnings about 'overshadow', a local variable in the function has the same name as a class member.
    change the name of your local variable so it is different from the class member's name.
 
 3) be sure to write the correct full qualified name for the nested type's member functions.
 
 4) After you finish defining each type/function, click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */


/*
 example:  

Thing: Car Wash   
    5 properties:
        - number of vacuum cleaners
        - number of eco-friendly cleaning supplies
        - stores the amount of water used per week.
        - stores amount of profit made per week
        - number of cars serviced per day
    3 things it can do:
        - wash and wax car
        - charge customer
        - detail the car interior
 */

#include <iostream>
#include <string>

struct CarWash //                                   1) define an empty struct for each of your 10 types.       
{
    //number of vacuum cleaners                     2) copied and commented-out plain-english property
    int numVacuumCleaners = 3; //                   3) member variables with relevant data types.
    //number of eco-friendly cleaning supplies      
    int numEcoFriendlyCleaningSupplies = 20;     
    //stores the amount of water used per week.     
    float waterUsedPerWeek = 200.f;            
    //stores amount of profit made per week         
    float profitPerWeek = 495.95f;               
    //number of cars serviced per day               
    int numberOfCarsServiced = 10;               
    
    struct Car //5)                                 Note that the nested type 'Car' is related to the 'CarWash' 
    {
        //2) member variables with relevant data types.  the names are appropriate for the U.D.T.'s purpose.
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        //3) a member function whose parameter has a default value.
        //the parameter name is related to the work the function will perform.
        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    //wash and wax car
    void washAndWaxCar(Car carA); //4) a member function whose parameter is a UDT.
    //charge customer
    float chargeCustomer(float discountPercentage);
    //detail the car interior
    void detailInterior(Car carB);
    
    //5) a member variable whose type is a UDT.
    Car carBeingServiced;  
};

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

    void compress(double threshold, float ratio, int compType);
    void volumeMakeUp(float inputGain, float outputGain);
    void saturateInput(Saturator sat);
};

void Compressor::compress(double cThreshold, float cRatio, int cCompType)
{
    double audioIn = 0.0;

    if (audioIn > cThreshold)
    {
        if (cCompType == 0)
            std::cout << "Compressing with ratio of: " << cRatio << " using Peak algorithm." << std::endl;
        else
            std::cout << "Compressing with ratio of: " << cRatio << " using RMS algorithm." << std::endl;
    }
}

void Compressor::volumeMakeUp(float cInputGain, float cOutputGain)
{
    float difference = cInputGain - cOutputGain;

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

    void bakeBread(double bFlourAmount, RyeBread brd);
    float cakeSell(std::string cakeName);
    void smellGreat();

    RyeBread breadToSell;
};

void Bakery::bakeBread(double bFlourAmount, RyeBread brd)
{
    std::cout << "Flour used: " << bFlourAmount << std::endl << "Timer set to: " << brd.bakingTime << std::endl;
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

    void relaxMuscles(bool goToSauna, int swimmingIntensity);
    void haveFun(float totalWaterSlidesLength, int numberOfSlides);
    bool learnToSwim(int age, int timeSpent);
};

void AquaPark::relaxMuscles(bool goToSauna, int swimmingIntensity)
{
    goToSauna = false;
    if (swimmingIntensity > 5)
    {
        goToSauna = true;
        std::cout << "You should use one of the sauna's to relax your muscles!" << std::endl;
    }
}
void AquaPark::haveFun(float aTotalWaterSlidesLength, int numberOfSlides)
{
    std::cout << "Total length of our " << numberOfSlides << " slides is: " << aTotalWaterSlidesLength << " which means that it's not possible to NOT have fun!" << std::endl;
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
    bool getDirty(int numPeople, int numAnimals, float hTotalFloorSize);
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

bool House::getDirty(int numPeople, int numAnimals, float hTotalFloorSize)
{
    if (hTotalFloorSize / (numPeople+numAnimals) > 20)
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

    double setInitGain(double vMinGain, double vMaxGain);
    void modulateOutput(float vModAtt, float modSpeed);
    void silenceOutput();
};

double VCA::setInitGain(double vMinGain, double vMaxGain)
{
    std::cout << "Setting init gain. Current minimum is: " << vMinGain << " and maximum is: " << vMaxGain << std::endl;

    return (vMinGain-vMaxGain);
}

void VCA::modulateOutput(float vModAtt, float modSpeed)
{
    std::cout << "Modulating output by: " << vModAtt << " with the frequency of: " << modSpeed << std::endl;
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

    void cutLows(float cutoffFreq, float resonance);
    void cutHighs(float cutoffFreq, float resonance);
    bool selfResonate(float fResonance, double fInputGain);
};

void Filter::cutLows(float fCutoffFreq, float fResonance)
{
    std::cout << "Cutting low frequencies below: " << fCutoffFreq << "with a Q of: " << fResonance << std::endl;
}
void Filter::cutHighs(float fCutoffFreq, float fResonance)
{
    std::cout << "Cutting high frequencies above: " << fCutoffFreq << "with a Q of: " << fResonance << std::endl;
}
bool Filter::selfResonate(float fResonance, double fInputGain)
{
    return fResonance > 0.9f && fInputGain > -35.0;
}

struct Envelope
{
    float attackTime = 22.5f;
    float decayTime = 330.2f;
    double sustainLevel = 0.99228;
    float releaseTime = 675.1f;
    float curve = 0.9f;

    void padPreset(float eCurve);
    void staccatoPreset(float eCurve);
    bool loopOver(float eAttackTime, float eDecayTime, float eReleaseTime);
};

void Envelope::padPreset(float eCurve)
{
    std::cout << "Setting envelope to slow setting, with curve of: " << eCurve << std::endl;
}
void Envelope::staccatoPreset(float eCurve)
{
    std::cout << "Setting envelope to fast setting, with curve of: " << eCurve << std::endl;
}
bool Envelope::loopOver(float eAttackTime, float eDecayTime, float eReleaseTime)
{
    bool eSwitch = false;

    if ((eAttackTime + eDecayTime + eReleaseTime) < 700.f)
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
    void modulateFreq(double lFreq, float modFreq, float intensity);
    void changeSpeed(int lShape);
};

void LFO::resetState()
{ 
}

void LFO::modulateFreq(double lFreq, float modFreq, float intensity)
{
    std::cout << "LFO frequency set to: " << lFreq << std::endl << "Modulation speed set to: " << modFreq << std::endl << "Modulation intensity set to: " << intensity << std::endl;
}

void LFO::changeSpeed(int lShape)
{
    if (lShape == 0)
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
    void drawWaveform(float wAmplitude, int wLengthInSamples, int wHeight, int wWidth);
};

void Waveform::zoomIn(float zoomInAmount)
{
    std::cout << "This " << waveColor << " waveform needs some zooming! Commencing zoom in procedure by: " << zoomInAmount << std::endl;
}

void Waveform::zoomOut(float zoomOutAmount)
{
    std::cout << "This " << waveColor << " waveform is too big! Commencing zoom out procedure by: " << zoomOutAmount << std::endl;
}

void Waveform::drawWaveform(float wAmplitude, int wLengthInSamples, int wHeight, int wWidth)
{
    std::cout << "Drawing waveform in a rectangle of size: " << wHeight << " x " << wWidth << " with an amplitude of: " << wAmplitude << " and a total length of: " << wLengthInSamples << " samples." << std::endl;
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
    std::cout << "good to go!" << std::endl;
}
