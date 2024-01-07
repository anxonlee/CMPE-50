#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    ifstream inputFile("HWinput3-3.txt"); 
    ofstream outputFile("HWoutput3-3.txt"); 

    if (!inputFile || !outputFile) {
        cerr << "Error: Cannot open input or output files." << endl;
        return 1;
    }

    string lastName;
    double quiz1, quiz2, quiz3, quiz4, quiz5;
    int studentNumber = 0;

    outputFile << fixed << setprecision(2); // Set output to display two decimal places

    while (inputFile >> lastName >> quiz1 >> quiz2 >> quiz3 >> quiz4 >> quiz5) {
        studentNumber++; // Increment student number for each student
        // Organize and write the data to the output file
        outputFile << studentNumber << ". ";
        outputFile << left << setw(10) << lastName;
        outputFile << right << setw(7) << quiz1 << setw(7) << quiz2 << setw(7) << quiz3 << setw(7) << quiz4 << setw(7) << quiz5;
        outputFile << endl;
    }

    // Close the input and output files
    inputFile.close();
    outputFile.close();

    cout << "Student grades organized and written to output.txt." << endl;
/*
1. Jones       80.50  77.00  95.70  88.60 100.00
2. Smith       80.00  99.00 100.00  87.80  93.76
3. Holmes      53.65  84.54  76.67  97.75  89.90
*/
    return 0;
}
