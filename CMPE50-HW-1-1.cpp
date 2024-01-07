#include <iostream>
#include <iomanip>

using namespace std;

// Function to calculate hat size
double calculateHatSize(int weight, int height) {
    return (static_cast<double>(weight) / height) * 2.9;
}

// Function to calculate jacket size
double calculateJacketSize(int weight, int height, int age) {
    double baseSize = (static_cast<double>(height) * weight) / 288.0;

    // Calculate adjustment for age
    double ageAdjustment = 0.0;
    if (age > 30) {
        ageAdjustment = static_cast<double>(age - 30) / 10.0 * 0.125;
    }

    return baseSize + ageAdjustment;
}

// Function to calculate waist size
double calculateWaistSize(int weight, int age) {
    double baseSize = static_cast<double>(weight) / 5.7;

    // Calculate adjustment for age
    double ageAdjustment = 0.0;
    if (age > 28) {
        ageAdjustment = static_cast<double>(age - 28) / 2.0 * 0.1;
    }

    return baseSize + ageAdjustment;
}

int main() {
    char repeat;
    
    do {
        int height, weight, age;

        cout << "Give me your height in inches, weight in pounds, and age in years\n"
             << "and I will give you your hat size, jacket size (inches at chest),\n"
             << "and your waist size in inches: ";
        cin >> height >> weight >> age;

        double hatSize = calculateHatSize(weight, height);
        double jacketSize = calculateJacketSize(weight, height, age);
        double waistSize = calculateWaistSize(weight, age);

        // Display the results with two digits after the decimal point
        cout << fixed << setprecision(2);
        cout << "hat size = " << hatSize << endl;
        cout << "jacket size = " << jacketSize << endl;
        cout << "waist size = " << waistSize << endl;

        cout << "\nEnter Y to repeat.";
        cin >> repeat;

    } while (repeat == 'Y');

    return 0;
}



