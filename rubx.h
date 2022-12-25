#pragma once

#include<iostream>
#include<string>
#include<fstream>
#include<cmath>
#include<time.h>

using namespace std;

void cubeInit(char[9][6]);              //  Initialize cube
char cubeInitSub(int);                  //  Initialize subroutine
void scrambler(char[9][6]);             //  Call cubeMove randomly
void cubePrint(char[9][6]);             //  Print cubeMap
void cubePrintRow(int, int, char[9][6]);//  Print subroutine
void userInput(string &);               //  Update input string for use with cubeMove
void cubeRotate(char[9][6], string);    //  Whole-cube rotations for use in cubeMove
void cubeFRotate(char[9][6], int, string);  //  Face rotations for use in cubeRotate and cubeSRotate
void cubeSRotate(char[9][6], int, string);  //  Slice rotations for use in cubeMove
void initSRotate(char[9][6], char[12], bool);  //  Initialize temp arrays for cubeSRotate
void cubeMove(char[9][6], string);      //  Combination calls of move subroutines
bool cubeValidate(char[9][6]);          //  Create temp array to check for win
void timePrint(int);                    //  Print elapsed time
void cubeTime(int, int, bool);          //  Conditionally record elapsed time, user initials, high-scores and update "hs.txt"
int countLines(ifstream &);             //  High-score: count lines so as to create a dynamic array to hold data
void getData(ifstream &, int, string*); //  High-score: save all data into a dynamic array of type 'string'

void cubeInit(char a[9][6]){    //  Initializes all faces of array
    int i, j;
    for(i = 0; i < 6; i++)
        for(j = 0; j < 9; j++)
            a[j][i] = cubeInitSub(i);   //  Call subroutine based on current index value
}

char cubeInitSub(int a){    //  Returns char, given an int 0-5
    char b;
    switch(a){
        case 0:
            b = 'w';
            break;
        case 1:
            b = 'g';
            break;
        case 2:
            b = 'r';
            break;
        case 3:
            b = 'b';
            break;
        case 4:
            b = 'o';
            break;
        case 5:
            b = 'y';
            break;
        default:
            break;
    }
    return b;
}

void scrambler(char a[9][6]){    //  Call cubeMove with random, valid input values.
//  Inputs: F/F', B/B', L/L', R/R', U/U', D/D', M/M', S/S', E/E'
    srand (time(NULL));
    for(int i = 0; i < (rand() % 50 + 30); i++){
        switch (rand() % 18 + 1){
            case 1:
                cubeMove(a, "F");
                break;
            case 2:
                cubeMove(a, "F\'");
                break;
            case 3:
                cubeMove(a, "B");
                break;
            case 4:
                cubeMove(a, "B\'");
                break;
            case 5:
                cubeMove(a, "L");
                break;
            case 6:
                cubeMove(a, "L\'");
                break;
            case 7:
                cubeMove(a, "R");
                break;
            case 8:
                cubeMove(a, "R\'");
                break;
            case 9:
                cubeMove(a, "U");
                break;
            case 10:
                cubeMove(a, "U\'");
                break;
            case 11:
                cubeMove(a, "D");
                break;
            case 12:
                cubeMove(a, "D\'");
                break;
            case 13:
                cubeMove(a, "M");
                break;
            case 14:
                cubeMove(a, "M\'");
                break;
            case 15:
                cubeMove(a, "S");
                break;
            case 16:
                cubeMove(a, "S\'");
                break;
            case 17:
                cubeMove(a, "E");
                break;
            case 18:
                cubeMove(a, "E\'");
                break;
            default:
                break;

        }
    }
}

void cubePrint(char a[9][6]){   //  Prints cubeMap by calling cubePrintRow
    for(int i = 1; i < 10; i++){
        switch(i){
            case 1 ... 3:
                cout << "      ";
                cubePrintRow(i, 0, a);
                break;
            case 4 ... 6:
                for(int j = 1; j < 5; j++){
                    cubePrintRow((i - 3), j, a);
                }
                break;
            case 7 ... 9:
                cout << "      ";
                cubePrintRow((i - 6), 5, a);
                break;
            default:
                break;
        }
        cout << endl;
    }
    cout << endl;
}

void cubePrintRow(int a, int b, char c[9][6]){  //  Subroutine for cubePrint
    //  Usage: int 'x' '1' '2' or '3' for row starting number '0' '3' or '6'
    //  int 'w' for face
    int d;
    switch(a){  //  Interprets 'x' call to start value of intended "row"
        case 1:
            d = 0;
            break;
        case 2:
            d = 3;
            break;
        case 3:
            d = 6;
            break;
        default:
            break;
    }
    for(int i = 0; i < 3; i++)
        cout << c[d + i][b] << " ";
}

void userInput(string &a){  //  Ask for input and update 'a'
    cout << "Possible inputs are X/X\', Y/Y\', Z/Z\', F/F\'/F2, "
    << "B/B\'/B2, L/L\'/L2, R/R\'/R2, U/U\'/U2, D/D\'/D2, M/M\'/M2, S/S\'/S2, E/E\'/E2,"
    << " Scramble, and Quit.\n"
    << "Your input:";
    cin  >> a;
    cout << endl;
    if(a != "Y\'"  and a != "Y" //  deny invalid input
        and a != "X\'" and a != "X"
        and a != "Z\'" and a != "Z"
        and a != "F\'" and a != "F" and a != "F2"
        and a != "R\'" and a != "R" and a != "R2"
        and a != "U\'" and a != "U" and a != "U2"
        and a != "L\'" and a != "L" and a != "L2"
        and a != "B\'" and a != "B" and a != "B2"
        and a != "D\'" and a != "D" and a != "D2"
        and a != "M\'" and a != "M" and a != "M2"
        and a != "S\'" and a != "S" and a != "S2"
        and a != "E\'" and a != "E" and a != "E2"
        and a != "Quit" and a != "Scramble"
        and a != "RandomSolve"){
        cout << "Invalid input, try again.";
        userInput(a);
    }
}

void cubeRotate(char a[9][6], string b){    //  Whole cube rotations around 'X' 'Y' and 'Z' axis
/*  Whole cube rotations to be called by cubeMove, update array 'a'
    according to string 'b'. Call subfunction cubeFRotate to reorient
    specific faces as necessary.  */
    char temp[9][6];
    int i, j;
    for(i = 0; i < 9; i++)  //  Initialize 'temp' with entire cubeMap
        for(j = 0; j < 6; j++)
            temp[i][j] = a[i][j];
    if(b == "Y"){   //  Rotate whole cube 'cw' around Y-axis
        for(i = 1; i < 5; i++){
            for(j = 0; j < 9; j++){
                if(i == 4)
                    a[j][i] = temp[j][1];
                else
                    a[j][i] = temp[j][i + 1];
            }
        }
        cubeFRotate(a, 0, "cw");
        cubeFRotate(a, 5, "ccw");
    }
    if(b == "Y\'"){ //  Rotate whole cube 'ccw' around Y-axis
        for(i = 1; i < 5; i++){
            for(j = 0; j < 9; j++){
                if(i == 1)
                    a[j][i] = temp[j][4];
                else
                    a[j][i] = temp[j][i - 1];
            }
        }
        cubeFRotate(a, 0, "ccw");
        cubeFRotate(a, 5, "cw");

    }
    if(b == "X"){   //  Rotate whole cube 'cw' around X-axis
        for(j = 0; j < 9; j++){
            a[j][0] = temp[j][2];
            a[j][2] = temp[j][5];
            a[j][5] = temp[j][4];
            a[j][4] = temp[j][0];
        }
        for(i = 0; i < 2; i++){
            cubeFRotate(a, 4, "cw");
            cubeFRotate(a, 5, "cw");
        }
        cubeFRotate(a, 3, "cw");
        cubeFRotate(a, 1, "ccw");
    }
    if(b == "X\'"){ //  Rotate whole cube 'ccw' around X-axis
        for(j = 0; j < 9; j++){
            a[j][0] = temp[j][4];
            a[j][2] = temp[j][0];
            a[j][5] = temp[j][2];
            a[j][4] = temp[j][5];
        }
        for(i = 0; i < 2; i++){
            cubeFRotate(a, 4, "cw");
            cubeFRotate(a, 0, "cw");
        }
        cubeFRotate(a, 3, "ccw");
        cubeFRotate(a, 1, "cw");
    }
    if(b == "Z"){   //  Rotate whole cube 'cw' around Z-axis
        for(j = 0; j < 9; j++){
            a[j][0] = temp[j][1];
            a[j][1] = temp[j][5];
            a[j][5] = temp[j][3];
            a[j][3] = temp[j][0];
        }
        for(i = 0; i < 6; i++){
            if(i == 4)
                cubeFRotate(a, i, "ccw");
            else
                cubeFRotate(a, i, "cw");
        }
    }
    if(b == "Z\'"){ //  Rotate whole cube 'ccw' around Z-axis
        for(j = 0; j < 9; j++){
            a[j][0] = temp[j][3];
            a[j][1] = temp[j][0];
            a[j][5] = temp[j][1];
            a[j][3] = temp[j][5];
        }
        for(i = 0; i < 6; i++){
            if(i == 4)
                cubeFRotate(a, i, "cw");
            else
                cubeFRotate(a, i, "ccw");
        }
    }
}

void cubeFRotate(char a[9][6], int b, string c){    //  Rotates face given face 'b' and "cw" or "ccw"
    int i, j = 8;                                   //  Does not change any value except the given face 'b'
    char temp[9];
    temp[2] = a[0][b];
    temp[5] = a[1][b];
    temp[8] = a[2][b];
    temp[1] = a[3][b];
    temp[4] = a[4][b];
    temp[7] = a[5][b];
    temp[0] = a[6][b];
    temp[3] = a[7][b];
    temp[6] = a[8][b];
    if(c == "cw")
        for(i = 0; i < 9; i++)
            a[i][b] = temp[i];
    if(c == "ccw"){
        for(i = 0; i < 9; i++){
            a[i][b] = temp[j];
            j--;
        }
    }
}

void cubeSRotate(char a[9][6], int b, string c){    //  Rotate a slice given adjacent face 'b' and "cw" or "ccw"
/*  Cube slice rotations to be called by cubeMove, update array 'a'
    according to face 'b' and string 'c'. Call subfunction cubeFRotate
    to reorient specific faces as necessary.  */
    int i, j;
    char tempB[12], tempC[12];
    switch(b){  //  Bring face 'b' to face '2'
        case 0:
            cubeRotate(a, "X\'");
            break;
        case 1:
            cubeRotate(a, "Y\'");
            break;
        case 2:
            break;
        case 3:
            cubeRotate(a, "Y");
            break;
        case 4:
            cubeRotate(a, "Y");
            cubeRotate(a, "Y");
            break;
        case 5:
            cubeRotate(a, "X");
            break;
        default:
            break;

    }
//  Call initSRotate, intialize additional temp array, and rotate values "cw" or "ccw"
    initSRotate(a, tempB, false);
    for(i = 0; i < 12; i++) tempC[i] = tempB[i];
    if(c == "cw"){
        for(i = 0; i < 12; i++){
            if(i < 3)
                tempB[i] = tempC[i + 9];
            else
                tempB[i] = tempC[i - 3];
        }
        cubeFRotate(a, 2, "cw");
    }
    else if(c == "ccw"){
        for(i = 0; i < 12; i++){
            if(i < 9)
                tempB[i] = tempC[i + 3];
            else
                tempB[i] = tempC[i - 9];
        }
        cubeFRotate(a, 2, "ccw");
    }
    //  restore new 'tempB' values to array 'a'
    initSRotate(a, tempB, true);
    switch(b){  //  Return face '2' to face 'b'
        case 0:
            cubeRotate(a, "X");
            break;
        case 1:
            cubeRotate(a, "Y");
            break;
        case 2:
            break;
        case 3:
            cubeRotate(a, "Y\'");
            break;
        case 4:
            cubeRotate(a, "Y\'");
            cubeRotate(a, "Y\'");
            break;
        case 5:
            cubeRotate(a, "X\'");
            break;
        default:
            break;

    }
}

void initSRotate(char a[9][6], char b[12], bool c){  //  Initializes or restores temp arrays for cubeSRotate
    if(c == false){
//      Initialize tangent
        b[0] = a[6][0];
        b[1] = a[7][0];
        b[2] = a[8][0];
        b[3] = a[0][3];
        b[4] = a[3][3];
        b[5] = a[6][3];
        b[6] = a[2][5];
        b[7] = a[1][5];
        b[8] = a[0][5];
        b[9] = a[8][1];
        b[10] = a[5][1];
        b[11] = a[2][1];
    }
    else if(c == true){
//      Restore tangent
        a[6][0] = b[0];
        a[7][0] = b[1];
        a[8][0] = b[2];
        a[0][3] = b[3];
        a[3][3] = b[4];
        a[6][3] = b[5];
        a[2][5] = b[6];
        a[1][5] = b[7];
        a[0][5] = b[8];
        a[8][1] = b[9];
        a[5][1] = b[10];
        a[2][1] = b[11];
    }
}

void cubeMove(char a[9][6], string b){  //  Combination of cubeRotate and cubeSRotate
//  as necessary to update array 'a' according to string 'b'.
    if(b == "Y" || b == "Y\'" || b == "X" || b == "X\'" || b == "Z" || b == "Z\'"){
        cubeRotate(a, b);
    }
    else if(b == "U"){
        cubeSRotate(a, 0, "cw");
    }
    else if(b == "L"){
        cubeSRotate(a, 1, "cw");
    }
    else if(b == "F"){
        cubeSRotate(a, 2, "cw");
    }
    else if(b == "R"){
        cubeSRotate(a, 3, "cw");
    }
    else if(b == "B"){
        cubeSRotate(a, 4, "cw");
    }
    else if(b == "D"){
        cubeSRotate(a, 5, "cw");
    }
    else if(b == "U\'"){
        cubeSRotate(a, 0, "ccw");
    }
    else if(b == "L\'"){
        cubeSRotate(a, 1, "ccw");
    }
    else if(b == "F\'"){
        cubeSRotate(a, 2, "ccw");
    }
    else if(b == "R\'"){
        cubeSRotate(a, 3, "ccw");
    }
    else if(b == "B\'"){
        cubeSRotate(a, 4, "ccw");
    }
    else if(b == "D\'"){
        cubeSRotate(a, 5, "ccw");
    }
    else if(b == "M"){
        cubeSRotate(a, 1, "cw");
        cubeSRotate(a, 3, "ccw");
        cubeRotate(a, "X");
    }
    else if(b == "M\'"){
        cubeSRotate(a, 1, "ccw");
        cubeSRotate(a, 3, "cw");
        cubeRotate(a, "X\'");
    }
    else if(b == "M2"){
        cubeSRotate(a, 1, "cw");
        cubeSRotate(a, 3, "ccw");
        cubeRotate(a, "X");
        cubeSRotate(a, 1, "cw");
        cubeSRotate(a, 3, "ccw");
        cubeRotate(a, "X");
    }
    else if(b == "E"){
        cubeSRotate(a, 0, "ccw");
        cubeSRotate(a, 5, "cw");
        cubeRotate(a, "Y");
    }
    else if(b == "E\'"){
        cubeSRotate(a, 0, "cw");
        cubeSRotate(a, 5, "ccw");
        cubeRotate(a, "Y\'");
    }
    else if(b == "E2"){
        cubeSRotate(a, 0, "ccw");
        cubeSRotate(a, 5, "cw");
        cubeRotate(a, "Y");
        cubeSRotate(a, 0, "ccw");
        cubeSRotate(a, 5, "cw");
        cubeRotate(a, "Y");
    }
    else if(b == "S"){
        cubeSRotate(a, 2, "ccw");
        cubeSRotate(a, 4, "cw");
        cubeRotate(a, "Z");
    }
    else if(b == "S\'"){
        cubeSRotate(a, 2, "cw");
        cubeSRotate(a, 4, "ccw");
        cubeRotate(a, "Z\'");
    }
    else if(b == "S"){
        cubeSRotate(a, 2, "ccw");
        cubeSRotate(a, 4, "cw");
        cubeRotate(a, "Z");
        cubeSRotate(a, 2, "ccw");
        cubeSRotate(a, 4, "cw");
        cubeRotate(a, "Z");
    }
    else if(b == "Scramble"){
        scrambler(a);
    }
    else if(b == "U2"){
        cubeSRotate(a, 0, "cw");
        cubeSRotate(a, 0, "cw");
    }
    else if(b == "L2"){
        cubeSRotate(a, 1, "cw");
        cubeSRotate(a, 1, "cw");
    }
    else if(b == "F2"){
        cubeSRotate(a, 2, "cw");
        cubeSRotate(a, 2, "cw");
    }
    else if(b == "R2"){
        cubeSRotate(a, 3, "cw");
        cubeSRotate(a, 3, "cw");
    }
    else if(b == "B2"){
        cubeSRotate(a, 4, "cw");
        cubeSRotate(a, 4, "cw");
    }
    else if(b == "D2"){
        cubeSRotate(a, 5, "cw");
        cubeSRotate(a, 5, "cw");
    }
}

bool cubeValidate(char a[9][6]){    //  Returns true/false based on completed faces
//  Check for win condition by creating a temporary array from a single sample from
//  each face of array 'a', then checking that sample against all values of that same
//  face. If equality comparison loop is true, return true, else return false.
    char temp[6];
    int i, j;
    for(i = 0; i < 6; i++)
        temp[i] = a[4][i];
    for(i = 0; i < 9; i++)
        for(j = 0; j < 6; j++)
            if(temp[j] != a[i][j])
                return false;
    return true;
}

void timePrint(int a){  //  Print elapsed time
//  Where 'a' should be 'timeInit' initialized as 'time(NULL)' at start of program
//  Condense 'time(NULL) - a' into verbose nature formatted using hours, minutes, seconds
//  Initialize 'b' and check before increasing value of 'h', 'm', and 's' for output later
//  As 'h', 'm', and 's' are inreased subtract from 'b' until 0
    int b = time(NULL) - a, h = 0, m = 0, s = 0;
    do{
        if((b / 3600) >= 1){
            h++;
            b -= 3600;
        }
        else if((b / 60) >= 1){
            m++;
            b -= 60;
        }
        else if(b < 60){
            s = b;
            b -= s;
        }
    }
    while(b != 0);
    //  Conditional output of hours and/or minutes if 'h' and/or 'm' are >= 1
    if(h >= 1)
        cout << h << " hours ";
    //  account for possibility that 'm' = 0 while 'h' >= 1
    if(m >= 1 or h >= 1)
        cout << m << " minutes and ";
    cout << s << " seconds have elapsed...";
}

int countLines(ifstream &inf){  //  Subroutine for cubeTime, getData, & high-score file management
    inf.open("hs.txt");
    int i = 0;
    string temp;
    while(getline(inf, temp))
        i++;
    inf.close();
    return i;
}

void getData(ifstream &inf, int n, string* d){  //  Subroutine for cubeTime & high-score file management
//  prints contents of "hs.txt" line-by-line
//  inf is the ifstream object
//  n is the numbers of lines to read in
//  d is a dynamic array with enough memory to hold the data
    inf.open("hs.txt");
    for(int i = 0; i < n; i++){
        getline(inf, d[i]);
        cout << d[i] << endl;
    }
    inf.close();
}

void cubeTime(int a, int b, bool c){
/*  Output total elapsed time, calculate a score based on time and turn count, print and update "hs.txt"
    Print current time minus initial time sampled at program start. Use bool 'd'
    as conditional flag to prevent usage unless cubeValidate returns 'true'. Update external
    file with sorted list of previous times if possible.
    A well optimized solution will garner a high score even if time was spent before executing moves
    A very quickly solved cube will also have a high score even if some moves were unnecesary or wasteful
    Gameplay that used many wasteful moves and took a longer amount of time will have a very low score
    Score should never be zero for any player  */
    int highScore = 10000000 / (pow(2, (log10 ((time(NULL) - a) * b))));
    if(c == true){
        cout << "\nYour score: " << highScore << "\nPlease input your initials, CUBE CHAMPION\n";
        string initials;
        cin >> initials;
        cout << "CUBE solved in " << b << " turns.\n\nHIGH SCORES:\n";
//  Initialize high-score handling
//  Call getData to print existing high-scores in "hs.txt" and then print current score underneath
        ifstream fin;                       
        int lineNumber = countLines(fin);
        string * data = new string[lineNumber];
        getData(fin, lineNumber, data);
        cout << initials[0] << initials[1] << initials[2] << " - " << highScore << endl;
//  Output existing high-scores plus current high-score to update "hs.txt"
        ofstream fout("hs.txt");
        for(int i = 0; i < lineNumber; i++)
            fout << data[i] << endl;
        fout << initials[0] << initials[1] << initials[2] << " - " << highScore << endl;
        fout.close();
    }
}