/********************************************************************************
week 04 Programming Assingment
Eric Harrington
*********************************************************************************
1: declare constant strings and a constant int for output formatting

2: include paramaters in main to for cmd arguments

3: declare and initialize int counter variables for vowel counts

4: declare variables for input-file stream, char type, and string for file name

5: set up outer if-else statement that checks whether argc is > 1; if argc is not
> 1, the else statement informs the user they did not include a file-name argument

6: set up a nested if-else statement that checks whether the user's file was 
successfully opened; if the file was not opened successfully, inform the user
within the if statement; if the file was opened successfully, code the rest
of the program within the else structure of the nested if-else statement

7: place a while loop within the else statement of the nested if-else structure
that runs while the input-file stream has not reach the end of file; use the char
variable to get each new character from the input file; use an if...else-if 
structure to check whethet each subsuquent character pulled from the input file
is a verb; if it is, update the relevant counter variable

8: after the while loop, output the vowel count, formatting the output as instructed

9: use ioman to pause the program after the output is displayed



********************************************************************************/
#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>

using namespace std;

//Step 1
const int PROG_WIDTH = 100;
const string TITLE = "Welcome to my Letter Count Program";
const string OUTPUT_A = "The number of A's:";
const string OUTPUT_E = "The number of E's:";
const string OUTPUT_I = "The number of I's:";
const string OUTPUT_O = "The number of O's:";
const string OUTPUT_U = "The number of U's:";
const string OUTPUT_VOW = "The vowel count is:";

const string OUTPUT_X = "The number of X's:";
const string OUTPUT_Y = "The number of Y's:";
const string OUTPUT_Z = "The number of Z's:";
const string OUTPUT_XYZ = "The sum of the number of X's, Y's, and Z's:";


//Step 2
int main(int argc, char *argv[])
{
    //Step 3
    int countA = 0;
    int countE = 0;
    int countI = 0;
    int countO = 0;
    int countU = 0;
    int vowelCount = 0;

    int countX = 0;
    int countY = 0;
    int countZ = 0;
    int countXYZ = 0;

    //Step 4
    string file_name = "";
    char letter;
    ifstream in_file;
    
    cout << setw(PROG_WIDTH) << setfill('*') << "" << endl;
    cout << setw(PROG_WIDTH/2 + TITLE.length()/2) << setfill('*') << TITLE << setw(PROG_WIDTH - (PROG_WIDTH/2 + TITLE.length()/2)) << setfill('*') << "" << endl;
    cout << setw(PROG_WIDTH) << setfill('*') << "" << endl << endl;
   
    //Step 5
    if (argc > 1)
    {
        file_name = argv[1];
        in_file.open(file_name);

        //Step 6
        if (!in_file.is_open())
        {
            cout << "Error opening file." << endl;
        }
        else 
        {   
            //Step 7
            while (!in_file.eof())
            {
                in_file.get(letter);
                if (letter == 'a' || letter == 'A')
                    {
                    countA += 1;
                    vowelCount += 1;
                    }
                else if (letter == 'e' || letter == 'E')
                    {
                    countE +=1;
                    vowelCount += 1;
                    }
                else if (letter == 'i' || letter == 'I')
                    {
                    countI +=1;
                    vowelCount += 1;
                    }
                else if (letter == 'o' || letter == 'O')
                    {
                    countO +=1;
                    vowelCount += 1;
                    }
                else if (letter == 'u' || letter == 'U')
                    {
                    countU +=1;
                    vowelCount += 1;
                    }
                else if (letter == 'x' || letter == 'X')
                    {
                    countX +=1;
                    countXYZ += 1;
                    }
                else if (letter == 'y' || letter == 'Y')
                    {
                    countY +=1;
                    countXYZ += 1;
                    }
                else if (letter == 'z' || letter == 'Z')
                    {
                    countZ +=1;
                    countXYZ += 1;
                    }
                }
            //Step 8
            cout << "Analyzing file '" << file_name << "'..." << endl << endl;
            cout << setw(OUTPUT_A.length()) << OUTPUT_A << setw(PROG_WIDTH - OUTPUT_A.length()-1) << setfill('.') << '.' << countA << endl;
            cout << setw(OUTPUT_E.length()) << OUTPUT_E << setw(PROG_WIDTH - OUTPUT_E.length()-1) << setfill('.') << '.' << countE << endl;
            cout << setw(OUTPUT_I.length()) << OUTPUT_I << setw(PROG_WIDTH - OUTPUT_I.length()-1) << setfill('.') << '.' << countI << endl;
            cout << setw(OUTPUT_O.length()) << OUTPUT_O << setw(PROG_WIDTH - OUTPUT_O.length()-1) << setfill('.') << '.' << countO << endl;
            cout << setw(OUTPUT_U.length()) << OUTPUT_U << setw(PROG_WIDTH - OUTPUT_U.length()-1) << setfill('.') << '.' << countU << endl;
            cout << setw(OUTPUT_VOW.length()) << OUTPUT_VOW << setw(PROG_WIDTH - OUTPUT_VOW.length()-1) << setfill('.') << '.' << vowelCount << endl; 

            cout << setw(OUTPUT_X.length()) << OUTPUT_X << setw(PROG_WIDTH - OUTPUT_X.length()-1) << setfill('.') << '.' << countX << endl;
            cout << setw(OUTPUT_Y.length()) << OUTPUT_Y << setw(PROG_WIDTH - OUTPUT_Y.length()-1) << setfill('.') << '.' << countY << endl;
            cout << setw(OUTPUT_Z.length()) << OUTPUT_Z << setw(PROG_WIDTH - OUTPUT_Z.length()-1) << setfill('.') << '.' << countZ << endl; 
            cout << setw(OUTPUT_XYZ.length()) << OUTPUT_XYZ << setw(PROG_WIDTH - OUTPUT_XYZ.length()-1) << setfill('.') << '.' << countXYZ << endl;

            //Step 9
            system("pause");
        }

    }
    else
    {
        cout << "You did not enter a file name." << endl;
    }

    return 0;
}
