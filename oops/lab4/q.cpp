#include<iostream>
using namespace std;

class A{
public:
    int mul(int a, int b){
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
};


int main(){

    D obj;
//    obj.mul(2, 3); // error because of ambiguity

    // solving this by using virtual inheritance

    cout<<obj.mul(2, 3)<<endl; 


    return 0;
}