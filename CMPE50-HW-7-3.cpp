#include <iostream>
#include <string>
using namespace std;

class StringArray {
private:
    string* dynamicArray;
    int size;

public:
    // Default constructor
    StringArray() : dynamicArray(nullptr), size(0) {}

    // Destructor to free memory when the object is destroyed
    ~StringArray() {
        delete[] dynamicArray;
    }

    // Member function to add a new entry to the dynamicArray
    bool add(const std::string& newEntry) {
        string* newArray = new string[size + 1];

        for (int i = 0; i < size; ++i) {
            newArray[i] = dynamicArray[i];
        }

        newArray[size] = newEntry;

        delete[] dynamicArray;
        dynamicArray = newArray;
        ++size;

        return true;
    }

    // Member function to delete an entry from the dynamicArray
    bool remove(const std::string& deleteEntry) {
        int index = -1;

        // Find the index of the deleteEntry
        for (int i = 0; i < size; ++i) {
            if (dynamicArray[i] == deleteEntry) {
                index = i;
                break;
            }
        }

        // If not found, return false
        if (index == -1) {
            return false;
        }

        // Create a new dynamic array one element smaller
        string* newArray = new string[size - 1];

        // Copy all elements except deleteEntry to the new array
        for (int i = 0, j = 0; i < size; ++i) {
            if (i != index) {
                newArray[j++] = dynamicArray[i];
            }
        }

        delete[] dynamicArray;
        dynamicArray = newArray;
        --size;

        return true;
    }

    // Member function to get a string at a specific position
    std::string get(int pos) const {
        if (pos >= 0 && pos < size) {
            return dynamicArray[pos];
        } else {
            return ""; // Return empty string for out-of-range positions
        }
    }

    // Member function to get the size of the dynamicArray
    int getSize() const {
        return size;
    }
};

int main() {
    StringArray myArray;

    // Add entries
    myArray.add("Apple");
    myArray.add("Banana");
    myArray.add("Orange");

    // Display the array
    cout << "Array contents:" << endl;
    for (int i = 0; i < myArray.getSize(); ++i) {
        cout << myArray.get(i) << endl;
    }

    // Remove an entry
    myArray.remove("Banana");

    // Display the modified array
    cout << "\nArray contents after removal:" << endl;
    for (int i = 0; i < myArray.getSize(); ++i) {
        cout << myArray.get(i) << endl;
    }

    return 0;
}
/*Array contents:
Apple
Banana
Orange

Array contents after removal:
Apple
Orange
*/