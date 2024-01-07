#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream inputFile("HWinput3-1.txt"); 
    if (!inputFile) {
        cerr << "Error: Cannot open input file." << endl;
        return 1;
    }

    double sum = 0.0;
    double number;
    int count = 0;

    while (inputFile >> number) {
        sum += number;
        count++;
    }

    inputFile.close();

    if (count == 0) {
        cout << "No numbers found in the input file." << endl;
    } else {
        double average = sum / count;
        cout << "Average of the numbers in the file: " << average << endl;
    }
/*Launching: '/Users/ansonlee/codess/my-app/CMPE50.cpp/CMPE50-HW-3-1'
Working directory: '/Users/ansonlee/codess/my-app/CMPE50.cpp'
1 arguments:
argv[0] = '/Users/ansonlee/codess/my-app/CMPE50.cpp/CMPE50-HW-3-1'
Average of the numbers in the file: 4
Process exited with status 0
*/
    return 0;
}
