#include<iostream>
using namespace std;

class Person{
protected:   
    string name;
    int age;
    string dob;
    string height;
    string nationality;
    string position;

public:
    Person(string n, int a, string d, string h, string nn, string p){
        name = n;
        age = a;
        dob = d;
        height = h;
        nationality = nn;
        position = p;
    }

    void displayName(){ cout<<name<<endl; }
    void displayAge(){ cout<<age<<endl; }
    void displayDOB(){ cout<<dob<<endl; }
    void displayHeight(){ cout<<height<<endl; }
    void displayNationality(){ cout<<nationality<<endl; }
    void displayPosition(){ cout<<position<<endl; }
};

class Student : public Person{
private:
    string rollno;
    string branch;

public:
    Student(string n, int a, string d, string h, string nn, string p, string rn, string br)
    : Person(n,a,d,h,nn,p)  
    {
        rollno = rn;
        branch = br;
    }

    void displayRollNo(){ cout<<rollno<<endl; }
    void displayBranch(){ cout<<branch<<endl; }
};

class Teacher : public Person{
private:
    string teachingSubject;
    string department;

public:
    Teacher(string n, int a, string d, string h, string nn, string p, string ts, string de)
    : Person(n,a,d,h,nn,p)
    {
        teachingSubject = ts;
        department = de;
    }

    void TeachingSubject(){ cout<<teachingSubject<<endl; }
    void displayDepartment(){ cout<<department<<endl; }
};

class NonTeaching : public Person{
public:
    NonTeaching(string n, int a, string d, string h, string nn, string p)
    : Person(n,a,d,h,nn,p) {}
};

int main(){
    Student s1("krishna", 20, "27/8/2005", "6", "indian", "student", "24111025", "biotechnology");
    Teacher t1("teacher1", 30, "21/8/1995", "6", "indian", "teacher", "Physics", "Physics");
    NonTeaching nt1("pune1", 35, "21/8/1990", "5'9", "indian", "staff");

    s1.displayName();
    s1.displayAge();
    s1.displayDOB();
    s1.displayHeight();
    s1.displayNationality();
    s1.displayPosition();
    s1.displayBranch();

    cout<<endl;

    t1.displayName();
    t1.displayAge();
    t1.displayDOB();
    t1.displayHeight();
    t1.displayNationality();
    t1.displayPosition();
    t1.TeachingSubject();
    t1.displayDepartment();

    cout<<endl;

    nt1.displayName();
    nt1.displayAge();
    nt1.displayDOB();
    nt1.displayHeight();
    nt1.displayNationality();
    nt1.displayPosition();

    return 0;
}