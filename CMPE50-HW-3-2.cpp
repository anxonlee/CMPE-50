#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// Merge and write two sorted vectors to an output file
void mergeAndWrite(const vector<int>& vec1, const vector<int>& vec2, ofstream& outputFile) {
    vector<int> mergedVector;
    mergedVector.reserve(vec1.size() + vec2.size());

    // Merge the two sorted vectors into mergedVector
    merge(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), back_inserter(mergedVector));

    // Write the merged and sorted numbers to the output file
    for (size_t i = 0; i < mergedVector.size(); i++) {
        outputFile << mergedVector[i] << " ";
    }
}

int main() {
    ifstream inputFile1("HWinput3-2-1.txt"); 
    ifstream inputFile2("HWinput3-2-2.txt"); 
    ofstream outputFile("HWoutput3-2.txt"); // The merged and sorted output will be written to this file

    if (!inputFile1 || !inputFile2 || !outputFile) {
        cerr << "Error: Cannot open input or output files." << endl;
        return 1;
    }

    vector<int> vec1;
    vector<int> vec2;

    int num;

    // Read the sorted integers from the first input file into vec1
    while (inputFile1 >> num) {
        vec1.push_back(num);
    }

    // Read the sorted integers from the second input file into vec2
    while (inputFile2 >> num) {
        vec2.push_back(num);
    }

    // Call the mergeAndWrite function to merge and write the sorted vectors to the output file
    mergeAndWrite(vec1, vec2, outputFile);

    // Close the input and output files
    inputFile1.close();
    inputFile2.close();
    outputFile.close();

    cout << "Merged and sorted numbers written to output.txt." << endl;

    return 0;
}
