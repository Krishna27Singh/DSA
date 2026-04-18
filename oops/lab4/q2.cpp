#include<iostream>
using namespace std;

class A{
public:
    virtual int mul(int a, int b){
        return a*b;
    }  
};

class B : public virtual A{
};

class C : public virtual A{
};

class D : public B, public C{
private:
    int a, b;
public:
    int mul(int a, int b) override {
        return B::mul(a, b);
    }
};


int main(){

    D obj;

    // solving diamond problem using abstract class 
    cout<<obj.mul(2, 3)<<endl;

    return 0;
}