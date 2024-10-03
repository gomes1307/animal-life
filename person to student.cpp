#include<iostream>
#include<string>
using namespace std;

class person
{
    string name;
    int age;
public:
    void inputperson()
    {
        cout<<"Enter name ";
        cin>> name;
        cout<<"Enter age ";
        cin>> age;
    }
        void displayPersonDetails(){
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
    };
class student : public person {
private:
    int rollNumber;
    float marks;
    public:

    void inputStudentDetails() {
        inputperson();
        cout << "Enter roll number: ";
        cin >> rollNumber;
        cout << "Enter marks: ";
        cin >> marks;
    }
    void displayStudentDetails(){
        displayPersonDetails();
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Marks: " << marks << endl;
    }

};

int main()
{
    student ob1;

    cout << "Enter student details:" << endl;
    ob1.inputStudentDetails();

    cout << "\nDisplaying student details:" << endl;
    ob1.displayStudentDetails();

    return 0;
}
