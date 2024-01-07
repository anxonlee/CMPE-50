#include <iostream>
#include<iomanip>
using namespace std;

class CDAccount{
private:
    double balance;
    double interest_rate;
    int term; //months until maturity
    double rate_fraction;
    double interest;
public:
    CDAccount(){
        balance=0.0;
        interest_rate=0.0;
        term=0;
    }
    CDAccount (double balanceInput, double interest_rateInput, double termInput) {
        balance = balanceInput;
        interest_rate = interest_rateInput;
        term = termInput;
    }
        
    double getBalance(){
        return balance;
    }

    double getInterestRate(){
        return interest_rate;
    }

    double getTerm(){
        return term;
    }

    void getInput(istream& cin){
        cout<<"balance="<<endl;
        cin>>balance;

        cout<<"Interest rate="<<endl;
        cin>>interest_rate;

        cout<<"term="<<endl;
        cin>>term;

    }

    double maturityBalance(){
        rate_fraction = interest_rate/100.0;
        interest = balance*rate_fraction*(term/12.0);
        return (balance + interest);
    }

    void getOutput(ostream& cout){
        cout<<"Balacnce : $"<<balance<< endl;
        cout<<"Interest Rate : "<<interest_rate<<endl;
        cout <<"Term :"<<term<< endl;
        cout << "Maturity Value : $"<<maturityBalance()<<endl;

}

};

int main(){
    CDAccount account;

    account.getInput(cin);
    account.getOutput(cout);

return 0;
}

/*balance=
10000
Interest rate=
10
term=
12
Balacnce : $10000
Interest Rate : 10
Term :12
Maturity Value : $11000
Process exited with status 0*/

