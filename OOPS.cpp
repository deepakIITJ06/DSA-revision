#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Teacher {
public:
    // int age;
    // string name;

    // Teacher(int age,string name) {
    //     this->name = name;
    //     this->age = age;
    // }

    virtual void override() {
        cout<<"learning polymorphism"<<"\n";
    }
};

class Student: public Teacher {
public:
    // string course;
    // Student(int age,string name,string course): Teacher(age,name) {
    //     this->course = course;
    // }

    void override() {
        cout<<"learning polymorphism in dericed class\n";
    }
};

signed main() {
    // Teacher t1(21,"deepak");
    // Student s1(23,"deep","DBMS");
    Teacher *t1;
    Student s1;
    t1 = &s1;
    t1->override();
    return 0;
}