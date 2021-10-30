/*
Project 3 - Part 1c / 5
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

1) write the 10th UDT
    come up with an object that is made of 5 smaller parts.
    These parts will not be defined using Primitives, but instead will be their own UDTs you'll define in Part 1d
    
    Here is an example:
    Cell Phone

    A Cell Phone is made up of the following 5 properties:
        Display
        Memory
        CPU
        Radio
        Applications

    A Cell Phone has 3 things it can do:
        make a call
        send a text
        run an application.

    Notice that I did not use "has a display" or "Has memory" or "has a cpu" as one of the properties of the CellPhone
    
    Writing 'has a ___" checks whether or not your object **has the ability to do something**.
    Instead, I wrote "Display" or "CPU".  These are specific objects or amounts. 
    
    In C++ terms, this means to I want you to avoid using 'bool' (has a) as a member variable type.
    Instead, prefer the other primitive types.

    When you choose your 5 smaller parts, remember that each of these 5 Sub Objects will need 
    to be defined with 5 primitive properties and 3 actions EACH.  

2) write the name of the primitive type you'll be using after each property in UDTs 1-4:
    pick properties that can be represented with 'int float double bool char std::string'
    example: 
        Display:
            Number of Pixels (int)
            Amount of Power consumed (milliwatt-hours) (float)
            Brightness (double)
            area in cm2 (int)
            brand (std::string)

3) Move the Thing 10 pseudo-code to after your Thing1-4 in the project.
*/


/*
Thing 1) compressor
5 properties:
    1) threshold value (doublee)
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
Thing 10) sampler
5 properties:
    1) vca (float)
    2) filter (float)
    3) envelope (float)
    4) lfo (double)
    5) waveform (double)
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
