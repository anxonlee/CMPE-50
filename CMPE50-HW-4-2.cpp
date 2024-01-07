#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    string inputLine;

    // Read a line of text from the user
    cout << "Enter a line of text: ";
    getline(cin, inputLine);

    int wordCount = 0;
    int letterCount = 0;
    bool inWord = false;


    for (size_t i = 0; i < inputLine.size(); i++) {
        char c = inputLine[i];
        
        // Check if the character is a letter (alphabetical)
        if (isalpha(c)) {
            letterCount++;

            // Set inWord to true if we encounter a letter, indicating we are in the middle of a word
            if (!inWord) {
                inWord = true;
                wordCount++;
            }
        } else {
            // If the character is not a letter, reset inWord to false
            inWord = false;
        }
    }

    // Output the results
    cout << "Number of words: " << wordCount << endl;
    cout << "Number of letters: " << letterCount << endl;
/*
Enter a line of text: I love you so much!
Number of words: 5
Number of letters: 14
*/
    return 0;
}
