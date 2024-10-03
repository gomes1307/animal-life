#include <iostream>
using namespace std;
class Student {
protected:
    int rollNo;
public:
void setRollNo(int r) {
        rollNo = r;
  }
void displayRollNo() {
        cout << "Roll Number: " << rollNo << endl; }
};
class Exam : virtual public Student {
protected:
    float academicMarks;
public:
    void setAcademicMarks(float m) {
        academicMarks = m; }
void displayAcademicMarks() {
        cout << "Academic Marks: " << academicMarks << endl;
    }
};
class Sports : virtual public Student {
protected:
    float sportsMarks;
public:
    void setSportsMarks(float m) {
        sportsMarks = m;
    }
 void displaySportsMarks() {
        cout << "Sports Marks: " << sportsMarks << endl;
    }
};
class Result : public Exam, public Sports {
public:
    void displayResult() {
        float total = academicMarks + sportsMarks;
        displayRollNo();
        displayAcademicMarks();
        displaySportsMarks();
        cout << "Total Marks: " << total << endl;
    }
};
int main() {
    Result studentResult;
    studentResult.setRollNo(101);
    studentResult.setAcademicMarks(88.5);
    studentResult.setSportsMarks(76.3);
    studentResult.displayResult();
return 0;
}

