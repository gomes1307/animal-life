#include <iostream>
using namespace std;
void staticVariable() {
    static int count = 0;
    count++;
    cout << "Count: " << count << endl;
}

int main() {
    staticVariable();
    staticVariable();
    staticVariable();
    staticVariable();
    staticVariable();
    staticVariable();
    return 0;
}

