#include<iostream>
using namespace std;

class bankAccount{
private:
    long long accountNumber;
    string holderName;
    long long balance;

public:
    void depositMoney(long long amount){
        balance += amount;
        cout<<"money "<<amount<<" has been deposited."<<endl;
    }
    void withdrawMoney(long long amount){
        balance -= amount;
        cout<<"money "<<amount<<" has been withdrawed"<<endl;
    }
    void viewDetails(){
        cout<<"account Number: "<<accountNumber<<endl;
        cout<<"holder's name: "<<holderName<<endl;
        cout<<"bank balance: "<<balance<<endl;
    }
    bankAccount(long long a, string h, long long b){
        accountNumber = a;
        holderName = h;
        balance = b;
    }
};

int main(){
    bankAccount B(1011, "krishna", 200000);

    B.viewDetails();
    B.depositMoney(50);
    B.viewDetails();
    B.withdrawMoney(100);
    B.viewDetails();
}