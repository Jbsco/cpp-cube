/*                               Jacob B. Seman
*********************************************************************************
                                    Program 3                                  */

#include"rubx.h"

using namespace std;

int main(){
    char cubeMap[9][6];                 //  Initialize variables
    int turnNum = 0;
    int timeInit = time(NULL);          //  Initialize starting time
    string input;                       //  Initialize input
    cout << "\nTimer initialized. Your cube is:\n\n";
    cubeInit(cubeMap);                  //  Initialize cubeMap
    scrambler(cubeMap);                 //  Randomize cubeMap
    cubePrint(cubeMap);                 //  Print starting cubeMap
    //  MAIN FUNCTION LOOP
    do{
        cout << "Turn #" << turnNum << ".\n";
        userInput(input);               //  Take move inputs
        turnNum++;
        if(input == "Quit") return 0;
/*      if(input == "RandomSolve"){     //  Commented out, but allows continuous calls of scrambler until cube is solved (tested for 2.4e7 iterations with no solution)
            int i = 0;
            do{
                scrambler(cubeMap);
                cout << "Attempt #" << ++i << endl;
            }
            while(cubeValidate(cubeMap) != true);
            cubePrint(cubeMap);
            cout << "RandomSolve took " << i << " randomizations to solve the cube.\n";
            return 0;
        }*/
        cubeMove(cubeMap, input);       //  Call cubeMove with inputs
        cubePrint(cubeMap);             //  Print current cubeMap 
        timePrint(timeInit);
    }
    while(cubeValidate(cubeMap) != true);
    //  WIN CONDITION
    //  Call cubeTime with conditional flag for win scenario, update external file.
    cubeTime(timeInit, turnNum, cubeValidate(cubeMap));
    return 0;
}