/*
Project 3 - Part 1e / 5
Video:  Chapter 2 Part 5
User-Defined Types

Continue your work on branch Part1

Purpose: The entire purpose of this 5-part project is to get you writing C++ code that compiles and to 
reinforce the syntax habits that C++ requires.  
What you create in this project will be used as the basis of Project 5 in the course.   

************************
Part1 purpose:  Learn to write UDTs

You are going to write 10 UDTs in project3.  
Part1 will be broken up into 5 separate steps
    Part 1a: you will learn to think about an object in terms of its sub-objects.
    Part 1b: you will write 4 un-related UDTs in plain english
    Part 1c: you will write 1 UDT in plain english that will be made of 5 related sub-objects
    Part 1d: you will write plain-english UDTs for the 5 sub-objects that form the UDT defined in Part 1c
    Part 1e: you will convert those 10 plain-english UDTs into code that runs.
************************

Convert your 10 Plain-english UDTs into code.

I recommend compiling after finishing each one and making sure it compiles 
without errors or warnings before moving on to writing the next UDT. 

1) define an empty struct below your plain-english UDT. i.e.:

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

#if false //ignore these #if #endif lines. they're just here to prevent compiler errors.
struct CarWash
{

};
#endif
/*
    - Do this for all 10 UDTs

2) Below your plain-english UDT, Copy your 5 properties & 3 actions into the empty struct body.
    - comment them out.
    - Do this for all 10 UDTs
    
3) declare your member variables and member functions underneath each plain-english comment in your struct's body.
    - give the member variables relevant data types
    - Do this for all 10 UDTs
 
4) make the function parameter list for those member functions use some of your User-Defined Types
    - You'll write definitions/implementations for these functions in Project3 Part2
    - you'll call each of these functions in Project3 part3
    - Do this for all 10 UDTs
 
5) make 2 of the 10 user-defined types have a nested class.  
    - this nested class also needs 5 properties and 3 actions.
    - these nested classes are not considered one of your 10 UDTs.
    - this nested class must be related to the class it is nested inside
 
6) your 10th UDT's properties should be instances of your #5-#9 UDTs.   
    - No primitives allowed!
 
7) After you finish defining each type, click the [run] button.  
    Clear up any errors or warnings as best you can. 
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



/*
Thing 1) compressor
5 properties:
    1) threshold value (double)
    2) knee ratio (float)
    3) output gain (float)
    4) input gain (float)
    5) compression type (int)
3 things it can do:
    1) compress audio
    2) make-up volume gain
    3) saturate input
 */

struct Compressor
{
    //threshold value (double)
    double threshold = -10.5;
    //knee ratio (float)
    float ratio = 4.5f;
    //output gain (float)
    float outputGain = -1.5f;
    //input gain (float)
    float inputGain = -11.0f;
    //compression type (int)
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

    //compress audio
    void compress(double threshold, float ratio, int compType);
    //make-up volume gain
    void volumeMakeUp(float inputGain, float outputGain);
    //saturate input
    void saturateInput(Saturator sat);
};

/*
Thing 2) bakery
5 properties:
    1) total amount of flour (double)
    2) number of cakes (int)
    3) number of breads (int)
    4) amount of money in cash register (float)
    5) max oven temperature (int)
3 things it can do:
    1) bake bread
    2) sell cakes
    3) smell great
 */

struct Bakery
{
    //total amount of flour (double)
    double flourAmount = 25.7;
    //number of cakes (int)
    int numCake = 10;
    //number of breads (int)
    int numBread = 38;
    //amount of money in cash register (float)
    float numMoney = 8392.21f;
    //max oven temperature (int)
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

    //bake bread
    void bakeBread(double flourAmount, RyeBread brd);
    //sell cakes
    float cakeSell(std::string cakeName);
    //smell great
    void smellGreat();

    RyeBread breadToSell;
};

/*
Thing 3) aqua park
5 properties:
    1) number of pools (int)
    2) number of saunas (int)
    3) total length of water slides (double)
    4) opening hours (float)
    5) ticket price (float)
3 things it can do:
    1) relax muscles
    2) be fun
    3) learning swimming
 */

struct AquaPark
{
    //number of pools (int)
    int numPools = 5;
    //number of saunas (int)
    int numSaunas = 3;
    //total length of water slides (double)
    float totalWaterSlidesLength = 121.56f;
    //opening hours (float)
    float openAt = 9.30f;
    //ticket price (float)
    float regularTicker = 13.21f;

    //relax muscles
    void relaxMuscles(bool goToSauna, int swimmingIntensity);
    //be fun
    void haveFun(float totalWaterSlidesLength, int numberOfSlides);
    //learning swimming
    bool learnToSwim(int age, int timeSpent);
};

/*
Thing 4) house
5 properties:
    1) number of windows (int)
    2) size of living room (float)
    3) room height (float)
    4) number of bathrooms (int)
    5) total floor size (float)
3 things it can do:
    1) provide shelter
    2) provide rest
    3) get dirty
 */

struct House
{
    //number of windows (int)
    int numWindows = 8;
    //size of living room (float)
    float livingRoomSize = 31.8f;
    //room height (float)
    float roomHeight = 2.8f;
    //number of bathrooms (int)
    int numBathRooms = 3;
    //total floor size (float)
    float totalFloorSize = 155.2f;

    //provide shelter
    void provideShelter();
    //provide rest
    void provideRest(float sleepQuality);
    //get dirty
    bool getDirty(int numPeople, int numAnimals, float totalFloorSize);
};

 /*
Thing 5) vca
5 properties:
    1) minimum gain (double)
    2) maximum gain (double)
    3) initial gain (double)
    4) modulation attenuator (float)
    5) inputs (int)
3 things it can do:
    1) set inital gain
    2) add rhythm to signal
    3) silence the signal
 */

struct VCA
{
    //minimum gain (double)
    double minGain = -100.66;
    //maximum gain (double)
    double maxGain = 10.5;
    //initial gain (double)
    double initGain = -20.1;
    //modulation attenuator (float)
    float modAtt = -56.2f;
    //inputs (int)
    int inputs = 2;

    //set inital gain
    float setInitGain(double minGain, double maxGain);
    //add rhythm to signal
    void modulateOutput(float modAtt, float modSpeed);
    //silence the signal
    void silenceOutput();
};

/*
Thing 6) filter
5 properties:
    1) cutoff frequency (float)
    2) resonance (float)
    3) filter type (std::string)
    4) input gain (double)
    5) overdrive (float)
3 things it can do:
    1) cut low frequencies
    2) cut high frequencies
    3) self-resonate
 */

struct Filter
{
    //1) cutoff frequency (float)
    float cutoffFreq = 13200.2f;
    //2) resonance (float)
    float resonance = 0.77f;
    //3) filter type (std::string)
    std::string filterType = "Low Pass";
    //4) input gain (double)
    double inputGain = -5.3;
    //5) overdrive (float)
    float overdriveAmount = 1.7f;

    //1) cut low frequencies
    void cutLows(float cutoffFreq, float resonance);
    //2) cut high frequencies
    void cutHighs(float cutoffFreq, float resonance);
    //3) self-resonate
    bool selfResonate(float resonance, double inputGain);
};

/*
Thing 7) envelope
5 properties:
    1) attack time (float)
    2) decay time (float)
    3) sustain level (double)
    4) release time (float)
    5) curve (float)
3 things it can do:
    1) create long sustained signals
    2) create short staccato signals
    3) loop over time
 */

struct Envelope
{
    //1) attack time (float)
    float attackTime = 22.5f;
    //2) decay time (float)
    float decayTime = 330.2f;
    //3) sustain level (double)
    double sustainLevel = 0.99228;
    //4) release time (float)
    float releaseTime = 675.1f;
    //5) curve (float)
    float curve = 0.9f;

    //1) create long sustained signals
    void padPreset(float curve);
    //2) create short staccato signals
    void staccatoPreset(float curve);
    //3) loop over time
    bool loopOver(float attackTime, float decayTime, float releaseTime);
};

/*
Thing 8) lfo
5 properties:
    1) fade-in time (float)
    2) frequency (double)
    3) shape (int)
    4) retrigger behaviour (int)
    5) mono / poly switch (bool)
3 things it can do:
    1) reset
    2) modulate
    3) change shape
 */

struct LFO
{
    //1) fade-in time (float)
    float fadeIn = 45.3f;
    //2) frequency (double)
    double freq = 0.074;
    //3) shape (int)
    int shape = 2;
    //4) retrigger behaviour (int)
    int retrig = 3;
    //5) mono / poly switch (bool)
    bool polyMode = false;

    //1) reset
    void resetState();
    //2) modulate
    void modulateFreq(double freq, float modFreq, float intensity);
    //3) change shape
    void changeSpeed(int shape);
};

/*
Thing 9) waveform
5 properties:
    1) amplitude (float)
    2) length in samples (int)
    3) color (std::string)
    4) height (int)
    5) width (int)
3 things it can do:
    1) zoom in
    2) zoom out
    3) draw audio signal
 */

struct Waveform
{
    //1) amplitude (float)
    float amplitude = 0.89f;
    //2) length in samples (int)
    int lengthInSamples = 644112;
    //3) color (std::string)
    std::string waveColor = "Yellow";
    //4) height (int)
    int height = 220;
    //5) width (int)
    int width = 720;

    //1) zoom in
    void zoomIn(float zoomInAmount);
    //2) zoom out
    void zoomOut(float zoomOutAmount);
    //3) draw audio signal
    void drawWaveform(float amplitude, int lengthInSamples, int height, int width);
};

/*
Thing 10) sampler
5 properties:
    1) vca
    2) filter
    3) envelope
    4) lfo
    5) waveform
3 things it can do:
    1) loop sound
    2) modulate filter
    3) pitch down sample
 */

struct Sampler
{
    //1) vca
    VCA vca;
    //2) filter
    Filter mainFilter;
    //3) envelope
    Envelope ampEnv;
    //4) lfo
    LFO lfo01;
    //5) waveform
    Waveform waveform;

    //1) loop sound
    void loopSound(std::string sampleName, bool loopForward);
    //2) modulate filter
    void modulateFilter(Filter filter, LFO lfo);
    //3) pitch down sample
    void pitchDown(std::string sampleName);
};


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
