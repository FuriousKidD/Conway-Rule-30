#ifndef CELLULARSPACE_H
#define CELLULARSPACE_H


//const variable declaration
const int INVALID_ARGUMENTS = 1; // for command-line arguments
const int EXIT_PROGRAM = 2;
const int ALIVE = 1;
const int DEAD = 0;

//below constant global variables are used for the function used for generating random numbers between 0 and 1
const int RANGE = 1;
const int MIN = 0;
const int MAX = 1;

namespace cellSpace{

    typedef int* oneD;

    //Clears the screen whenever it's called
	void screenClear();

	//generates random numbers between 0 and 1
	int GenRand();

	//Sets a default 1D array in case user chooses to display without choosing to populate
	oneD arrDefault(oneD arrCurrent, int intSize, int intMiddle);

	//Generates the initial array and returns it
	oneD initialArray(oneD arrCurrent, int intSize, char chOption);

	//Function that implements the steps of rule 30
	void ruleThirty(oneD& arrNext, oneD& arrCurrent, int& intSize);

}//end of namespace


#endif
