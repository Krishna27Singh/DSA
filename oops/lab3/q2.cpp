#include<iostream>
using namespace std;

class BankAccount{
protected:
    string accountNumber;
    string holderName;
    string branch;
    string IFSC;
public:
    BankAccount(string an, string hn, string b, string ifsc){
        accountNumber = an;
        holderName = hn;
        branch = b;
        IFSC = ifsc;
    }

    void displayAccountNumber(){ cout<< accountNumber<<endl;}
    void displayHoldersName(){ cout<< holderName<<endl;}
    void displayBranch(){ cout<< branch<<endl;}
    void displayIFSC(){ cout<< IFSC<<endl;}
};

class SavingsAccount : public BankAccount{
private:
int balance;
string accountType;
public:
    SavingsAccount(string an, string hn, string b, string ifsc, int bal, string at)
        : BankAccount(an, hn, b, ifsc)  {
            balance = bal;
            accountType = at;
        }
    void displayBalance() {cout<<balance<<endl;}
    void displayAccountType() {cout<<accountType<<endl;}
};

int main(){

    BankAccount b1("5325434", "krishna", "jaipur", "HGIJ432");
    SavingsAccount s1("5325434", "krishna", "jaipur", "HGIJ432", 2000, "savings");

    b1.displayAccountNumber();
    b1.displayBranch();
    b1.displayHoldersName();
    b1.displayIFSC();

    cout<<endl;

    s1.displayAccountNumber();
    s1.displayBranch();
    s1.displayHoldersName();
    s1.displayIFSC();
    s1.displayBalance();
    s1.displayAccountType();

    return 0;
}