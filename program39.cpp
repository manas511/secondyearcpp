#include <iostream>
#include <string>
using namespace std;


class Student {
protected:
    int rollNumber;
    string name;

public:
    
    void inputStudentDetails() {
        cout << "Enter roll number: ";
        cin >> rollNumber;
        cout << "Enter student's name: ";
        cin.ignore(); 
        getline(cin, name);
    }


    void displayStudentDetails() {
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Name: " << name << endl;
    }
};


class Exam {
protected:
    string subject;
    int minMarks;
    int maxMarks;
    int obtainedMarks;

public:

    void inputExamDetails() {
        cout << "Enter subject name: ";
        cin.ignore(); 
        getline(cin, subject);
        cout << "Enter minimum marks: ";
        cin >> minMarks;
        cout << "Enter maximum marks: ";
        cin >> maxMarks;
        cout << "Enter obtained marks: ";
        cin >> obtainedMarks;
    }


    void displayExamDetails() {
        cout << "Subject: " << subject << endl;
        cout << "Minimum Marks: " << minMarks << endl;
        cout << "Maximum Marks: " << maxMarks << endl;
        cout << "Obtained Marks: " << obtainedMarks << endl;
    }
};


class Result : public Student, public Exam {
public:

    void displayResult() {
        displayStudentDetails();  
        displayExamDetails();     

        
        if (obtainedMarks >= minMarks)
            cout << "Result: Pass" << endl;
        else
            cout << "Result: Fail" << endl;
    }
};

int main() {
    Result result; 
    result.inputStudentDetails(); 
    result.inputExamDetails(); 
    result.displayResult(); 

    return 0;
}
