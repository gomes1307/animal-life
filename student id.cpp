#include <iostream>
#include <string>

using namespace std;

struct Student {
  int rollNo;
  string name;
  float marks;
};

int main() {
  int numStudents;
  cout << "Enter the number of students: ";
  cin >> numStudents;

  Student students[numStudents];


  for (int i = 0; i < numStudents; ++i) {
    cout << "\nEnter details for student " << i + 1 << ":" << endl;
    cout << "Roll No: ";
    cin >> students[i].rollNo;
    cout << "Name: ";
    cin.ignore();
    getline(cin, students[i].name);
    cout << "Marks: ";
    cin >> students[i].marks;
  }

  cout << "\nStudent Details:\n";
  for (int i = 0; i < numStudents; ++i) {
    cout << "Roll No: " << students[i].rollNo << endl;
    cout << "Name: " << students[i].name << endl;
    cout << "Marks: " << students[i].marks << endl << endl;
  }

  return 0;
}

