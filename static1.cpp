#include <iostream>
using namespace std;
class CSE {
public:
    static int count;

    CSE() {
        count++;
    }
};


int CSE::count = 0;

int main() {
    CSE obj1;
    CSE obj2;
    CSE obj3;
    cout << "Number of objects created: " << CSE::count << endl;
    return 0;
}
