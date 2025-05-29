#include "CellularSpace.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <string>
#include <limits>

using namespace std;
using namespace cellSpace;

int main(int argc, char* argv[])
{
    // validates command line arguments
    if(argc != 2){
        cerr << "Invalid number of arguments! \n";
		cout << "[program.exe numCells]"
        exit(INVALID_ARGUMENTS);
    }//end of if

    //following is the dynamic array initialisation
    int intSize = stoi(argv[1]);	// function stoi converts string into an integer
    oneD arrCurrent = new int[intSize];
	oneD arrNext = new int[intSize];

    //variables to use in main
    int intRounds = intSize;
    int intMiddle = intSize/2;
    char chOptions = '\0';
    bool blContinue = true;

     srand(time(NULL));

	//Sets the parent round to a default value which outputs the rule 30 triangle
    arrCurrent = arrDefault(arrCurrent, intSize, intMiddle);

       cout << "This program runs the cellular automaton for a number of rounds "
            << "specified by the user.\n The program outputs an easy-to-understand "
            << "representation of the automaton as it evolves from one round to the next.\n"
            << "The program has default values for when you choose to run "
            << "the cellular automaton without choosing to populate it.\n"
            << "\nPRESS ENTER TO START";

    cin.get();//Pauses program and aawaits for user to press enter
    screenClear();//clears screen when user presses enter

    do{
        //Menu is displayed
        cout << "A: Have random values assinged to initial round\n"
             << "B: Manualy set initial values \n"
             << "C: Number of rounds \n"
             << "D: Run and Display rounds \n"
             << "R: Reset Program \n"
             << "E: Exit Program \n";

        cin >> chOptions;

        //clears the Menu
        screenClear();

        switch(chOptions){

            case 'A':
            case 'a':{

            //for populating initial array with random numbers
            arrCurrent = initialArray(arrCurrent, intSize, chOptions);
                break;
            }//end of case A

            case 'B':
            case 'b':{
                arrCurrent = initialArray(arrCurrent, intSize, chOptions);
                break;
            }//end of case B

            case 'C':
            case 'c':{

                cout << "Enter number of Rounds: ";
                cin >> intRounds;

                  while(cin.fail() || intRounds < 0){
				    cin.clear();
				    cin.ignore(numeric_limits<streamsize>::max(),'\n');
				    cerr << "Invalid Input! Enter a positive integer: ";
				    cin >> intRounds;
				    screenClear();
				}//end of while validation
				cin.clear();

                break;
            }//end of case C

            case 'D':
            case 'd':{

                //displays the rounds

                //Outputs the initial array by defualt
                cout << "Parent:\t";
                for (int i = 0; i<intSize; i++){
                    cout << arrCurrent[i] << " ";
                }//end of for loop
                cout << "\n";

                //outputs the next generations
                for(int i = 0; i < intRounds; i++){//outter

                    ruleThirty(arrNext, arrCurrent, intSize);// applies rule 30
                    cout << "Gen " << i + 1 <<":\t";

                    //outputs the cells of each generation
                    for(int j = 0; j < intSize; j++){
                        cout << arrNext[j] << " ";
                    }//end of inner1 for loop
                    cout << "\n";

                    //ends up printing the 2nd gen as the first gen when reRun
                    //sets the next generation to be the current generation
                    for(int i = 0; i < intSize; i++){
                        arrCurrent[i] = arrNext[i];
                    }//end of inner2 for loop

                }//end of outter for loop

                break;
            }//end of case D


            //resets everything back to default
            case 'R':
            case 'r':{

                //Sets the parent round to a default value
                arrCurrent = arrDefault(arrCurrent, intSize, intMiddle);
                intRounds = intSize;
                cout << "Program reset back to default\n";

                break;
            }//end of case R

            case 'E':
            case 'e':{
                cout << "Thank You. Goodbye!";
                blContinue = false;
                exit(EXIT_PROGRAM);
                break;
            }//end of case E

            default:{
                cerr << "Out of range! Try Again. \n";
                break;
            }//end of default

        }//end of switch

        //checks if the program is still running and prompts user to press enter to return to Menu
        if( blContinue == true ){
            cout << "\nPlease press enter to return to Menu";
            cin.ignore();
            cin.get();
            screenClear(); // clears everything;

        }//end of if
    }//end of do

    while(blContinue == true);

    delete [] arrCurrent;
    delete [] arrNext;

    return 0;
}// end of main
