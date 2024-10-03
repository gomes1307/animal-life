#include <iostream>
using namespace std;
class Animal {
public:
    static int count;

    static void showCount() {
        cout << "Count: " << count << endl;
    }
};

int Animal::count = 0;

int main() {
    Animal::showCount();

    Animal obj1;
    Animal::count++;
    Animal::showCount();
    return 0;
}

