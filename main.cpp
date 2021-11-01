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

/*
Thing 8) lfo
5 properties:
    1) fade-in time (float)
    2) frequency (double)
    3) shape (int)
    4) retrigger behaviour (int)
    5) mono / poly switch (int)
3 things it can do:
    1) reset
    2) modulate
    3) change frequency
 */

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
