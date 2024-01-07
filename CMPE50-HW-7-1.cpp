#include <iostream>
#include <string>
using namespace std;
/* Class SuperString for HW7 */
class sstring: public string
{
public:
sstring() : string() { };
sstring(const string &str) : string(str) { }
sstring(const sstring &sstr) : string(sstr) { }
sstring operator= (const sstring &sstr);
sstring operator= (const char *cstr);
friend sstring operator* (const sstring &sstr, int multiple);
friend sstring operator- (const sstring &sstr1, const sstring &sstr2);
friend sstring operator/ (const sstring &sstr, int divider);
friend sstring operator! (const sstring &sstr);
/* prefix increment */
friend sstring operator++ (sstring &sstr);
/* postfix increment */
friend sstring operator++ (sstring &sstr, int dummy);
/* prefix decrement */
friend sstring operator-- (sstring &sstr);
/* postfix decrement */
friend sstring operator-- (sstring &sstr, int dummy);
};
sstring sstring::operator= (const sstring &sstr)
{
// calling base class opertor=
string::operator=(sstr);
return *this;
}
sstring sstring::operator= (const char *cstr)
{
  assign(cstr);
return *this;
}
sstring operator* (const sstring &sstr, int multiple)
{
sstring temp = sstr;
for (int i = 1; i < multiple; i++)
{
temp.append(sstr.c_str());
}
return temp;
}
sstring operator- (const sstring &sstr1, const sstring &sstr2)
{
sstring temp = sstr1;
// fill in the code
return temp;
}
sstring operator/(const sstring &sstr, int divider) {
  if (divider == 0) {
    throw runtime_error("Cannot divide by zero");
  }

  sstring result;
  int length = sstr.length();

  // Round down the length to the nearest multiple of the divider
  length = length / divider;

  // Get the substring of sstr from 0 to length - 1
  result = sstr.substr(0, length);

  return result;
}

sstring operator! (const sstring &sstr)
{
sstring temp = sstr;
  reverse(temp.begin(), temp.end());
return temp;
}

sstring operator++ (sstring &sstr)
{
char temp = sstr.back();
int length = sstr.length();
  sstr.erase(length-1, 1);
  sstr = temp + sstr;

  return sstr;
}

sstring operator++ (sstring &sstr, int dummy) {
  // Save the original string value
  sstring original_value = sstr;

  // Rotate the string by one character to the right
char temp = sstr.back();
int length = sstr.length();
  sstr.erase(length-1, 1);
  sstr = temp + sstr;

  // Return the original value of the string
  return original_value;
}

sstring operator--(sstring &sstr) {
  char temp = sstr.front();
  sstr.erase(0, 1);
  sstr += temp;

  return sstr;
}

 
sstring operator-- (sstring &sstr, int dummy) {
  // Save the original string value
  sstring originalValue = sstr;

  // Rotate the string by one character to the right
  char temp = sstr.front();
  sstr.erase(0, 1);
  sstr += temp;

  // Return the original value of the string
  return originalValue;
}





int main() {
// Some sample test code
sstring sstr("Hello World!"), sstr2, sstr3, sstr4, sstr5, sstr6, sstr7;
cout << "sstr = " << sstr << endl;
sstr2 = sstr;
cout << "sstr2 = " << sstr2 << endl;
sstr3 = sstr * 3;
cout << "sstr3 = " << sstr3 << endl;
sstr4 = sstr / 4;
cout << "sstr4 = " << sstr4 << endl;
sstr5 = !sstr;
cout << "sstr5 = " << sstr5 << endl;
cout << "++sstr = " << ++sstr << ": sstr++ = " << sstr++ << endl;
cout << "--sstr = " << --sstr << "sstr-- = " << sstr-- <<endl;
return 0;
}
/*sstr = Hello World!
sstr2 = Hello World!
sstr3 = Hello World!Hello World!Hello World!
sstr4 = Hel
sstr5 = !dlroW olleH
++sstr = !Hello World: sstr++ = !Hello World
--sstr = !Hello Worldsstr-- = !Hello World*/