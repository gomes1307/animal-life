#include<iostream>
using namespace std;

class rectangle {
private:
    int width;
    int height;

public:

    rectangle() {
        width = 1;
        height = 2;
        cout << "Default Constructor" << endl;
        cout << "width = " << width << endl << "height = " << height << endl << "area = " << width * height << endl << endl;
    }


    rectangle(int w, int h) {
        width = w;
        height = h;
        cout << "Parameterized Constructor" << endl;
        cout << "width = " << width << endl << "height = " << height << endl << "area = " << width * height << endl << endl;
    }


    rectangle(rectangle &rect) {
        width = rect.width;
        height = rect.height;
        cout << "Copy Constructor" << endl;
        cout << "width = " << width << endl << "height = " << height << endl << "area = " << width * height << endl << endl;
    }
    ~rectangle() {
        cout << "Destructor called for rectangle with width = " << width << " and height = " << height << endl;
    }
};

int main() {
    rectangle rect1;
    rectangle rect2(5, 4);
    rectangle rect3 = rect2;

    return 0;
}

