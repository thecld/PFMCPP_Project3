/*
Project 3 - Part 1b / 5
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

1)  Fill in #1 - 4 with a random UDT in plain english
    These 4 UDTs do not need to be related.
        a) For each plain-english UDT, write out 5 traits or properties and 3 things it can do
        b) remember: these properties will eventually become primitives.
        pick properties that can be represented with 'int float double bool char std::string'
*/

/*
 example:  
 
Thing: Car Wash   
    5 properties:
        - number of vacuum cleaners
        - number of eco-friendly cleaning supplies
        - the amount of water used per week.
        - amount of profit made per week
        - number of cars serviced per day
    3 things it can do:
        - wash and wax car
        - charge customer
        - detail the car interior

    Notice that I did not use "has a vacuum cleaner" or "Has eco-friendly cleaning supplies" as one of the properties
    
    Writing 'has a ___" checks whether or not your object **has the ability to do something**.
    Instead, I wrote "number of vacuum cleaners" and "number of eco-friendly cleaning supplies".  
    
    These are specific objects or amounts. 
    
    In C++ terms, this means to I want you to avoid using 'bool' (has a) as a member variable type.
    Instead, prefer the other primitive types.

    In addition to the usual primitives (covered in Project 2), you can use 'std::string' to represent strings in this project.
 */

/*
Thing 1) compressor
5 properties:
    1) threshold value
    2) knee ratio
    3) output gain
    4) input gain
    5) compression type
3 things it can do:
    1) compress audio
    2) make-up volume gain
    3) saturate input
 */

/*
Thing 2) bakery
5 properties:
    1) number of cookies
    2) number of cakes
    3) number of breads
    4) number of cash registers
    5) number of ovens
3 things it can do:
    1) bake bread
    2) sell cakes
    3) smell great
 */

/*
Thing 3) aqua park
5 properties:
    1) number of pools
    2) number of saunas
    3) number of water slides
    4) number of people
    5) ticket price
3 things it can do:
    1) relax muscles
    2) be fun
    3) learning swimming
 */

/*
Thing 4) house
5 properties:
    1) number of windows
    2) number of doors
    3) number of rooms
    4) number of bathrooms
    5) flooring
3 things it can do:
    1) provide shelter
    2) provide rest
    3) get dirty
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
