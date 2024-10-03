#include <iostream>
using namespace std;
class Base {
public:
    int x = 0;
protected:
    int y = 0;
private:
    int z = 0;
};
class A: public Base {
public:
    void print() {
    cout << "x: " << x << ", y: " << y << endl;
    }
};
class B: protected Base {
public:
    void print() {
    cout << "x: " << x << ", y: " << y << endl;
    }
};
class C : private Base {
public:
    void print() {
   cout << "x: " << x << ", y: " << y << endl;
    }
};
int main() {
    A a;
    a.print();

   B b;
    b.print();

    C c;
    c.print();
    return 0;
}
