#include <iostream>

using namespace std; // Use the 'std' namespace

// Function to swap the first and last elements of an integer array
void swapFrontBack(int arr[], int size) {
    if (size <= 0) {
        cout << "Array is empty. No elements to swap." << endl;
        return;
    }

    // Swap the first and last elements using a temporary variable
    int temp = arr[0];
    arr[0] = arr[size - 1];
    arr[size - 1] = temp;
}

int main() {
    int size;

    // Input the size of the array
    cout << "Enter the size of the array: ";
    cin >> size;

    // Check for valid array size
    if (size < 0) {
        cout << "Invalid array size." << endl;
        return 1;
    }

    int arr[size];

    // Input the elements of the array
    cout << "Enter " << size << " integers: ";
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }

    // Call the swapFrontBack function to swap the first and last elements
    swapFrontBack(arr, size);

    // Output the modified array
    cout << "Array after swapping first and last elements: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }

/*Enter the size of the array: 5
Enter 5 integers: 1
2
3
4
4
Array after swapping first and last elements: 4 2 3 4 1 
Process exited with status 0

*/
    return 0;
}
