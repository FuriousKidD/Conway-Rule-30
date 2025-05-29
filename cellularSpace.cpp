#include "CellularSpace.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <limits>

using namespace std;

namespace cellSpace{

	void screenClear(){

		#ifdef _WIN32
			system("cls");
		#else
			system("clear");
		#endif
    }// end of ScreenClear

	int genRand(){
		int intRand;

		intRand = MIN + rand() % (RANGE+1);

		return intRand;
	}// end of GenRand

	oneD arrDefault(int* arrCurrent, int intSize, int intMiddle){
	    arrCurrent = new int[intSize];

	     for(int i = 0; i < intSize; i++){
            arrCurrent[i] = 0;

            //puts alive in the middle of the cell
            if(i == intMiddle){
                arrCurrent[i] = 1;
            }//end of if

        }//end of for loop
        return arrCurrent;
	}//end of arrDefault

	oneD initialArray(oneD arrCurrent, int intSize, char chOption){

		arrCurrent = new int [intSize];

		//if user chooses option A then random numbers must be populated into the array
		if(toupper(chOption) == 'A'){

			for(int i = 0; i < intSize; i++){
				int intRand = genRand();
				arrCurrent[i] = intRand;
			}//end of if
			cout << "\nInitial Round: Random population successful!";

		}//end of if

		//if user chooses option B then they manually populate the array
		else if(toupper(chOption) == 'B'){

			for(int i = 0; i<intSize; i++){

				cout << "Enter Cell 1 or 0: ";
				cin >> arrCurrent[i];

				//Checks if user put the correct values between 1 and 0
                //if user enters anything that is not an integer 0 or 1, they must try again.
				while(cin.fail() || ( arrCurrent[i] != 1 && arrCurrent[i] != 0 )){
				    cin.clear();
				    cin.ignore(numeric_limits<streamsize>::max(),'\n');
				    cerr << "Invalid Input! Enter Cell (1 or 0): ";
				    cin >> arrCurrent[i];
				    screenClear();
				}//end of while loop

				cin.clear();//clears input buffer
				cout << "\n";
				screenClear();

			}//end of for loop
			cout << "\nInitial Round: Manual population successful!";
		}// end of else if

		return arrCurrent;

	}//end of initialArray

	void ruleThirty(oneD& arrNext, int*& arrCurrent, int& intSize){
		arrNext = new int[intSize];
		oneD arrTemp = new int[intSize];

		//The following initializes the arrNext with default 0
		for(int i = 0; i < intSize; i++){
			arrNext[i] = 0;
		}//end of for loop

		for (int i = 0; i < intSize; i++){//temp array to hold current values
		   arrTemp[i] = arrCurrent[i];
		}//end of for loop

		for(int i = 0; i < intSize; i++){

			//string variable which will aid in checking the pattern of cells to determine alive or dead
			string strPattern;

			//The following conditional checks for cells that are out of bounds
			//Assigns the left neighbour of the first cell to 0
			if((i-1) == -1){
				strPattern += "0";
				strPattern += to_string(arrTemp[i]);
				strPattern += to_string(arrTemp[i+1]);
			}// end of if

			//Assigns the right neighbour of the last cell to 0
			else if ((i+1) == intSize){

			strPattern += to_string(arrTemp[i-1]);
			strPattern += to_string(arrTemp[i]);
			strPattern += "0";

			}//end of else if

			strPattern += to_string(arrTemp[i-1]);
			strPattern += to_string(arrTemp[i]);
			strPattern += to_string(arrTemp[i+1]);

			if(strPattern == "111" || strPattern == "110" || strPattern == "101" || strPattern == "000"){
				arrNext[i] = DEAD;
			}//end of end if

			//Checks if the pattern of a cell and
			else if(strPattern == "100" || strPattern == "011" || strPattern == "010" || strPattern == "001"){
				arrNext[i] = ALIVE;
			}//end of else if

		}//end of for loop

		delete [] arrTemp;

	}//end of ruleThirty

}//end of namespace cellSpace
