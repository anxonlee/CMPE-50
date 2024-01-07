#include <iostream>
#include <string>
#include <cctype> 

using namespace std;

int main() {
    string first, last;

    cout << "Enter your first name: ";
    cin >> first;
    cout << "Enter your last name: ";
    cin >> last;

    // Convert both strings to lowercase
    for (int i = 0; i < first.length(); i++) {
        first[i] = tolower(first[i]);
    }
    for (int i = 0; i < last.length(); i++) {
        last[i] = tolower(last[i]);
    }

    if (first[0] == 'a' || first[0] == 'e' || first[0] == 'i' || first[0] == 'o' || first[0] == 'u') {
        // If it's a vowel, add "way" to the end
        first += "way";
    } else {
        // If it's a consonant, move it to the end and add "ay"
        char firstLetter = first[0];
        first = first.substr(1) + firstLetter + "ay";
    }

    if (last[0] == 'a' || last[0] == 'e' || last[0] == 'i' || last[0] == 'o' || last[0] == 'u') {
        // If it's a vowel, add "way" to the end
        last += "way";
    } else {
        // If it's a consonant, move it to the end and add "ay"
        char firstLetter2 = last[0];
        last = last.substr(1) + firstLetter2 + "ay";
    }
    // Capitalize the first letter of the first and last names
    first[0] = toupper(first[0]);
    last[0] = toupper(last[0]);

    // Output the full name in Pig Latin
    cout << "Your name in Pig Latin is: " << first << " " << last << endl;

    return 0;
}/*Enter your first name: Anson 
Enter your last name: Lee
Your name in Pig Latin is: Ansonway Eelay*/