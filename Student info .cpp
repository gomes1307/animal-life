#include <iostream>

using namespace std;

class Student {
public:
    string name;
    int rollNumber;
    double marks;

    Student() {
        name = "";
        rollNumber = 0;
        marks = 0.0;
    }
};

int main() {
    int n;

    cout << "Enter the number of students: ";
    cin >> n;

    Student *students = new Student[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter details for student " << i + 1 << endl;

        cout << "Name: ";
        cin >> students[i].name;

        cout << "Roll Number: ";
        cin >> students[i].rollNumber;

        cout << "Marks: ";
        cin >> students[i].marks;
    }

    cout << "\nStudent Details:\n";
    for (int i = 0; i < n; i++) {
        cout << "Name: " << students[i].name << endl;
        cout << "Roll Number: " << students[i].rollNumber << endl;
        cout << "Marks: " << students[i].marks << endl;
        cout << endl;
    }

    delete[] students;

    return 0;
}
