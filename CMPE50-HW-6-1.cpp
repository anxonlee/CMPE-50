#include <iostream>
using namespace std;

class DayOfYear {
public:
    friend bool isAfter(const DayOfYear& date1, const DayOfYear& date2);
    friend bool isBefore(const DayOfYear& date1, const DayOfYear& date2);
    friend DayOfYear add(const DayOfYear& date1, const DayOfYear& date2);

    DayOfYear(int the_month, int the_day);
    //Precondition: the_month and the_day form a
    //possible date. Initializes the date according
    //to the arguments.

    DayOfYear();
    //Initializes the date to January first.

    void input();
    void output();

    int get_month();
        //Returns the month, 1 for January, 2 for February, etc.

    int get_day();
        //Returns the day of the month.


private:
    void check_date();
    int month;
    int day;
};

// Constructor with arguments
DayOfYear::DayOfYear(int the_month, int the_day) : month(the_month), day(the_day) {
    check_date();
}

// Default constructor
DayOfYear::DayOfYear() : month(1), day(1) {
}

// Function to input the date
void DayOfYear::input() {
    cout << "Enter the month: ";
    cin >> month;
    cout << "Enter the day: ";
    cin >> day;
    check_date();
}

// Function to output the date
void DayOfYear::output() {
    cout << "Date: " << month << "/" << day << endl;
}

// Function to get the month
int DayOfYear::get_month() {
    return month;
}

// Function to get the day
int DayOfYear::get_day() {
    return day;
}

// Check if the date is valid
void DayOfYear::check_date() {
    if (month < 1 || month > 12 || day < 1 || day > 30) {
        cout << "Invalid date." << endl;
        exit (0);
    }
}

// Friend function to check if date1 is after date2
bool isAfter(const DayOfYear& date1, const DayOfYear& date2) {
    if (date1.month > date2.month || (date1.month == date2.month && date1.day > date2.day)) {
        return true;
    }
    
    return false;
}

// Friend function to check if date1 is before date2
bool isBefore(const DayOfYear& date1, const DayOfYear& date2) {
    if (date1.month < date2.month || (date1.month == date2.month && date1.day < date2.day)) {
        return true;
    }
    return false;
}

DayOfYear add(const DayOfYear& date1, const DayOfYear& date2) {
    int newM = (date1.month + date2.month - 1) % 12 + 1;
    int newD = date1.day + date2.day;

    if (newD > 30) {
        newM = newM +1;
        newD = newD - 30;
    }

    return DayOfYear(newM, newD);
}

int main() {
    DayOfYear date1, date2, result;

    cout << "Date1 : " << endl;
    date1.input();

    cout << "Date2: " << endl;
    date2.input();

    result = add(date1, date2);

    cout << "Date 1: ";
    date1.output();
    cout << "Date 2: ";
    date2.output();
    cout << "Result: ";
    result.output();

    if (isAfter(date1, date2))
    cout << "Date 1 is after Date 2. "<< endl;
    else
    cout << "Date 1 is not after Date 2." << endl;

    if (isBefore(date1, date2))
    cout << "Date 1 is before Date 2. " << endl;
    else 
    cout << "Date 1 is not before Date 2. " << endl;


    return 0;
}
/*Enter the month: 1
Enter the day: 1
Date2: 
Enter the month: 2
Enter the day: 2
Date 1: Date: 1/1
Date 2: Date: 2/2
Result: Date: 3/3
Date 1 is not after Date 2.
Date 1 is before Date 2.