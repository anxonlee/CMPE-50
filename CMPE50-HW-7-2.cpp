#include <iostream>
#include <cstdlib>

using namespace std;

// Function to reverse an array of integers
void reverseArray(int *array, int size) {
  int front = 0;
  int rear = size - 1;
  while (front < rear) {
    // Swap the numbers referenced by front and rear
    int temp = array[front];
    array[front] = array[rear];
    array[rear] = temp;

    // Increment front to point to the next number
    front++;

    // Decrement rear to point to the preceding number
    rear--;
  }
}

int main() {
  cout << "Enter the size of the array: ";
  int size;
  cin >> size;

  int *array = new int[size];

  cout << "Enter the numbers to the array: ";
  for (int i = 0; i < size; i++) {
    cin >> array[i];
  }

  reverseArray(array, size);

  cout << "The reversed array is: ";
  for (int i = 0; i < size; i++) {
    cout << array[i] << " ";
  }
  cout << endl;

  delete[] array;

  return 0;
}
/*Enter the size of the array: 5
Enter the numbers to the array: 1
2
3
4
5
The reversed array is: 5 4 3 2 1 */