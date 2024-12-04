#include <bits/stdc++.h>
using namespace std;

class vehicle {
private:
    int a,b,c;
public:
    void allocate(int a,int b,int c) {
        this->a = a;
        this->b = b;
        this->c = c;
    }
    friend class CheckMe;  
};

class CheckMe {
public:
    void show(vehicle &v1) {
        cout<<v1.a<<" "<<v1.b<<" "<<v1.c<<endl;
    }
};

int main() {
    vehicle v1;
    v1.allocate(2,3,4);
    CheckMe c1;
    c1.canI();
    c1.show(v1);
    return 0;
}