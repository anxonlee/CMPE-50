#include <iostream>
#include <cstring>

using namespace std;

class StringVar {
public:
    StringVar(int size);
    StringVar( );
    StringVar(const char a[]);
    StringVar(const StringVar& string_object);
    ~StringVar( );
    int length( ) const;
    void input_line(istream& ins);
    StringVar copy_piece(int pos, int npos);
    char one_char(int pos);
    void set_char(int pos, char ch);
    StringVar& operator=(const StringVar &obj); // Changed return type to StringVar&
    friend ostream& operator <<(ostream& outs, const StringVar& the_string);
    friend istream& operator >>(istream& ins, StringVar& the_string);
    friend bool operator==(const StringVar& sv1, const StringVar& sv2);
    friend StringVar operator+(const StringVar& sv1, const StringVar& sv2);

private:
    char *value; // pointer to dynamic array that holds the string value.
    int max_length; // declared max length of any string value.
};

StringVar::StringVar(int size) {
    value = new char[size + 1];
    max_length = size;
    value[0] = '\0';
}

StringVar::StringVar() : value(nullptr), max_length(0) {
}

StringVar::StringVar(const char a[]) {
    max_length = strlen(a);
    value = new char[max_length + 1];
    strcpy(value, a);
}

StringVar::StringVar(const StringVar& string_object) {
    max_length = string_object.max_length;
    value = new char[max_length + 1];
    strcpy(value, string_object.value);
}

StringVar::~StringVar() {
    delete[] value;
}

int StringVar::length() const {
    return strlen(value);
}

void StringVar::input_line(istream& ins) {
    ins.getline(value, max_length + 1);
}

StringVar StringVar::copy_piece(int pos, int npos) {
    if (pos < 0 || pos >= length() || npos <= 0) {
        return StringVar(); // Return an empty string if pos or npos is invalid
    }

    if (pos + npos > length()) {
        npos = length() - pos; // Adjust npos if it exceeds the length
    }

    char* substring = new char[npos + 1];
    strncpy(substring, value + pos, npos);
    substring[npos] = '\0';

    StringVar result(substring);
    delete[] substring;

    return result;
}

char StringVar::one_char(int pos) {
    if (pos < 0 || pos >= length()) {
        return '\0'; // Return null character if pos is invalid
    }
    return value[pos];
}

void StringVar::set_char(int pos, char ch) {
    if (pos >= 0 && pos < length()) {
        value[pos] = ch;
    }
}

StringVar& StringVar::operator=(const StringVar &obj) {
    if (this != &obj) {
        delete[] value;
        max_length = obj.max_length;
        value = new char[max_length + 1];
        strcpy(value, obj.value);
    }
    return *this;
}

ostream& operator<<(ostream& outs, const StringVar& the_string) {
    outs << the_string.value;
    return outs;
}

istream& operator>>(istream& ins, StringVar& the_string) {
    char temp[the_string.max_length + 1];
    ins >> temp;
    delete[] the_string.value;
    the_string.max_length = strlen(temp);
    the_string.value = new char[the_string.max_length + 1];
    strcpy(the_string.value, temp);
    return ins;
}

bool operator==(const StringVar& sv1, const StringVar& sv2) {
    return strcmp(sv1.value, sv2.value) == 0;
}

StringVar operator+(const StringVar& sv1, const StringVar& sv2) {
    int totalLength = sv1.length() + sv2.length();
    char* resultValue = new char[totalLength + 1];
    strcpy(resultValue, sv1.value);
    strcat(resultValue, sv2.value);

    StringVar result(resultValue);
    delete[] resultValue;

    return result;
}

int main() {
    // Example usage of all functions

    // Creating StringVar objects
    StringVar str1("Hello");
    StringVar str2("World");

    // Concatenation using overloaded operator +
    StringVar str3 = str1 + str2;
    cout << "Concatenated String: " << str3 << endl;

    // Copying a piece of the string using copy_piece
    StringVar subStr = str3.copy_piece(6, 5);
    cout << "Substring: " << subStr << endl;

    // Accessing a single character using one_char
    char ch = str3.one_char(8);
    cout << "Character at position 8: " << ch << endl;

    // Modifying a character using set_char
    str3.set_char(0, 'h');
    cout << "Modified String: " << str3 << endl;

    // Default constructor and input using overloaded operator >>
    StringVar str4;
    cout << "Enter a string: ";
    cin >> str4;
    cout << "Entered String: " << str4 << endl;

    // Displaying the length of the string using length
    cout << "Length of String: " << str4.length() << endl;

    // Overloaded assignment operator =
    StringVar str5;
    str5 = str4;
    cout << "Copied String using assignment operator: " << str5 << endl;

    // Checking equality using overloaded operator ==
    cout << "Are str4 and str5 equal? " << (str4 == str5 ? "Yes" : "No") << endl;

    return 0;
}
/*Concatenated String: HelloWorld
Substring: orld
Character at position 8: l
Modified String: helloWorld
Enter a string: iloveyou
Entered String: iloveyou
Length of String: 8
Copied String using assignment operator: iloveyou
Are str4 and str5 equal? Yes*/