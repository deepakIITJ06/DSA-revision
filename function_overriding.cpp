#include <bits/stdc++.h>
using namespace std;

class animal {
public:
    static int total;
    animal() {
        total++;
    }
    void speak() {
        cout<<"animal is speaking"<<endl;
    }
};

int animal::total = 0;

class dog: public animal {
public:
    void speak() {
        cout<<"sorry i don't speak , i bark ! \n";
        cout<<"this is an example of function overriding"<<endl;
    }
};

int main()
{
    dog d1;
    d1.speak();
    cout<<d1.total<<endl;
    dog d2;
    cout<<d2.total<<endl;
    return 0;
}