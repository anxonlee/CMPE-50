#include <iostream>
#include <cmath> 

using namespace std;

void avgStdDev(double s1, double s2, double s3, double s4,
double &average, double &stdDev){
    // Calculate the average
    average = (s1 + s2 + s3 + s4) / 4.0;

    // Calculate the standard deviation
    double squaredDiffSum = pow(s1 - average, 2) + pow(s2 - average, 2) + pow(s3 - average, 2) + pow(s4 - average, 2);
    stdDev = sqrt(squaredDiffSum / 4.0);
}

int main(){
char y;
do {
    double s1, s2, s3, s4, average, stdDev;
    cout << "Input 4 numbers:" << endl;
    cin >> s1 >> s2 >> s3 >> s4;
    // Calculate average and standard deviation
        avgStdDev(s1, s2, s3, s4, average, stdDev);

        // Output the results
        cout << "Average: " << average << endl;
        cout << "Standard Deviation: " << stdDev << endl;

        // Ask if the user wants to continue
        cout << "Do you want to calculate again? If so, press 'y'. ";
        cin >> y;
}   while (y=='y');
/*Input 4 numbers:
1
2
3
4
Average: 2.5
Standard Deviation: 1.11803
Do you want to calculate again? If so, press 'y'. */
}