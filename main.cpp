/*
Project 3 - Part 1d / 5
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

    The goal of this step is to get you to think about breaking down an object into smaller and smaller objects, 
    until the smallest object is made of up only C++ primitives and std::string. 

    Continuing the previous example:  Cell Phone

    A Cell Phone is made up of the following 5 properties/sub-objects and 3 actions:
        Display
        Memory
        CPU
        Radio
        Applications
    3 actions:
        make a call
        send a text
        run an application.

    These 5 properties can be broken down into their own sub-objects and properties. 

    If we break down the first property 'Display' into its 5 properties we get:
        brightness
        amount of power consumed.
        pixels
        width in cm
        height in cm

    the Display's brightness can be represented with a Primitive, such as a double. 

    The amount of power consumed can also be represented with a Primitive, such as a float or integer (i.e. 250mWa)
    
    The 'pixels' property must be represented with an array of Pixel instances, as the screen has more than 1 row of pixels.
        Arrays have not been discussed and can't be used in this project.
        Instead, we can use an Integer primitive to store the Number of Pixels:

    Display:
        Number of Pixels
        Amount of Power consumed (milliwatt-hours)
        Brightness
        width in cm
        height in cm
************************

1) Fill in #5 - #9 with plain-english UDTs for the 5 properties you created for UDT #10
    example: 
        If #10's first property was 'Engine', then your `Thing 5)` will be `Engine`
        you will need to provide 5 properties and 3 member functions of that Engine object in plain English
        Remember to pick properties that can be represented with 'int float double bool char std::string'
2) write the name of the primitive type you'll be using after each property
    pick properties that can be represented with 'int float double bool char std::string'
    example: 
        Display:
            Number of Pixels (int)
            Amount of Power consumed (milliwatt-hours) (float)
            Brightness (double)
            width in cm (int)
            height in cm (int)

3) move Thing 5-9 to between your Thing 4 and Thing 10.
*/


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
    1) cutoff frequency
    2) resonance
    3) filter type
    4) input gain
    5) overdrive
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
