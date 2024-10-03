#include <iostream>
using namespace std;
class A {
public:
    int *ptr;


   A (int size) {
        ptr = new int[size];
    cout << "Dynamic constructor called with size: " << size << endl;
    }


    ~A() {
        delete[] ptr;
        cout<< "Destructor called" << endl;
    }
};

int main() {

    A obj(5);
    obj.ptr[0] = 10;
    obj.ptr[1] = 20;
    cout << "obj.ptr[0] = " << obj.ptr[0] << endl;
    cout << "obj.ptr[1] = " << obj.ptr[1] << endl;

    return 0;
}
