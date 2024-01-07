#include <iostream>
using namespace std;

class Duple
    {
public:
    Duple();
    Duple(int first, int second);
    friend istream& operator>>(istream& ins, Duple& second);
    friend ostream& operator<<(ostream& outs, const Duple& second);

    Duple operator+(const Duple& sec) const;

    Duple operator-(const Duple& sec) const;

private:
    int f;
    int s;
    };

    Duple::Duple() : f(1), s(1) 
    {}

    Duple::Duple(int first, int second) : f(first), s(second) {}

    istream& operator>>(istream& ins, Duple& second)
    {
    ins >> second.f >> second.s;
    return ins;
    }

    ostream& operator<<(ostream& outs, const Duple& second)
    {
    outs << "(" << second.f << "," << second.s << ")";
    return outs;
    }

    Duple Duple::operator+(const Duple& sec) const
    {
    return Duple(this->f + sec.f, this->s + sec.s);
}

Duple Duple::operator-(const Duple& sec) const
{
    return Duple(this->f - sec.f, this->s - sec.s);
}

int main()
{
    Duple d1, d2, d3;
    cout << "First Duple: ";
    cin >> d1;
    cout << "Second Duple: ";
    cin >> d2;

    d3 = d1 + d2;
    cout << "Sum: " << d3 << endl;

    d3 = d1 - d2;
    cout << "Difference: " << d3 << endl;

    return 0;
}

/*First Duple: 1
1
Second Duple: 2
2
Sum: (3,3)
Difference: (-1,-1)*/