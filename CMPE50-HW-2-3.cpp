#include <iostream>
using namespace std; 

// Function to count even numbers
int countEvens(int arr[], int size) {
    int count = 0; // Initialize the count to zero

    for (int i = 0; i < size; ++i) {
        if (arr[i] % 2 == 0) {
            // If the current element is even, increment the count
            count++;
        }
    }

    return count;
}

int main() {
    int size;

    // Input the size of the array
    cout << "Enter the size of the array: ";
    cin >> size;

    // Check for valid array size
    if (size <= 0) {
        cout << "Invalid array size." << endl;
        return 1;
    }

    int arr[size];

    // Input the elements of the array
    cout << "Enter " << size << " positive integers: ";
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
        if (arr[i] <= 0) {
            cout << "Invalid input." << endl;
            return 1;
        }
    }

    // Call the countEvens function to count even numbers in the array
    int evenCount = countEvens(arr, size);

    // Output the count of even numbers
    cout << "Count of even numbers in the array: " << evenCount << endl;
/*Enter the size of the array: 6
Enter 6 positive integers: 12
33
54
76
54
33
Count of even numbers in the array: 4*/
    return 0;
}
