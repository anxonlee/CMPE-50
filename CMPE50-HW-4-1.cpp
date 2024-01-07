#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    // Open the input file
    ifstream inputFile("HWInput4-1.txt");

    // Check if the file opened successfully
    if (!inputFile.is_open()) {
        cerr << "Error: Unable to open the file." << endl;
        return 1;
    }

    string line;
    int lineNumber = 1; 

    // Read each line from the file
    while (getline(inputFile, line)) {
        // Output the line number, right-adjusted in a field of three spaces
        cout << setw(3) << lineNumber << ": " << line << endl;
        lineNumber++;
    }

    // Close the file
    inputFile.close();
/* 1: With three or four loggerheads amongst three or four
  2: score hogsheads. I have sounded the very
  3: base-string of humility. Sirrah, I am sworn brother
  4: to a leash of drawers; and can call them all by
  5: their christen names, as Tom, Dick, and Francis.
  6: They take it already upon their salvation, that
  7: though I be but the prince of Wales, yet I am king
  8: of courtesy; and tell me flatly I am no proud Jack,
  9: like Falstaff, but a Corinthian, a lad of mettle, a
 10: good boy, by the Lord, so they call me, and when I
 11: am king of England, I shall command all the good
 12: lads in Eastcheap.
*/
    return 0;
}
