#include <iostream>
#include <string>
#include <algorithm> // for std::transform

using namespace std;

class Month {
private:
    int monthNumber;
    string MonthName;


public:
    Month(const string &monthName) {
        MonthName = monthName;
        if (MonthName == "jan") {
            monthNumber = 1;
        } else if (MonthName == "feb") {
            monthNumber = 2;
        } else if (MonthName == "mar") {
            monthNumber = 3;
        } else if (MonthName == "apr") {
            monthNumber = 4;
        } else if (MonthName == "may") {
            monthNumber = 5;
        } else if (MonthName == "jun") {
            monthNumber = 6;
        } else if (MonthName == "jul") {
            monthNumber = 7;
        } else if (MonthName == "aug") {
            monthNumber = 8;
        } else if (MonthName == "sep") {
            monthNumber = 9;
        } else if (MonthName == "oct") {
            monthNumber = 10;
        } else if (MonthName == "nov") {
            monthNumber = 11;
        } else if (MonthName == "dec") {
            monthNumber = 12;
        } else {
            monthNumber = 1; // Default to January if the input is not recognized
        }
    }

    void input(istream& in) {
        in >> monthNumber;
    }

    void output(ostream& out) const {
        out << monthNumber;        
    }

    void output(ostream& out, const string& format) const {
        if (format == "name") {
            switch (monthNumber) {
                case 1: out << "Jan"; break;
                case 2: out << "Feb"; break;
                case 3: out << "Mar"; break;
                case 4: out << "Apr"; break;
                case 5: out << "May"; break;
                case 6: out << "Jun"; break;
                case 7: out << "Jul"; break;
                case 8: out << "Aug"; break;
                case 9: out << "Sep"; break;
                case 10: out << "Oct"; break;
                case 11: out << "Nov"; break;
                case 12: out << "Dec"; break;
                default: out << "Invalid Month";
            }
        } else {
            out << monthNumber;
        }
        
    }

    Month nextMonth() const {
        int next = (monthNumber % 12) + 1;
        return Month("Jan").setMonthNumber(next);
    }

    Month& setMonthNumber(int number) {
        monthNumber = number;
        return *this;
    }


};




int main() {
    string inputMonthName;

    cout << "Enter the name of a month (first 3 letters): ";
    cin >> inputMonthName;

    Month userMonth(inputMonthName);

    cout << "Month as an integer: ";
    userMonth.output(cout);
    cout << endl;

    cout << "Month as the name: ";
    userMonth.output(cout, "name");
    cout << endl;

    Month nextMonth = userMonth.nextMonth();
    cout << "Next Month: ";
    nextMonth.output(cout, "name");
    cout << endl;


  
    return 0;
}
