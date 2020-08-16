#include<bits/stdc++.h>

using namespace std;

// Adapt Existing Class to Make it flexible to the newer system

// Story: A student becomes a software engineer... so no one treat him as a student.
// so we will make a software engineer class based on Student information

class StudentInterface {

public:
    virtual string firstName() = 0 ;
    virtual string lastName() = 0;
    virtual int rollNo() = 0;
    virtual int income() = 0;
    virtual string livingCity() = 0;
};

class Student : public StudentInterface {

public:
    string firstName() {
        return "Suman";
    }
    string lastName() {
        return "Bhadra";
    }
    int rollNo() {
        return 16;
    }
    int income() {
        return 5000;
    }
    string livingCity() {
        return "Dhaka";
    }
};

class SoftwareEngineerInterface  {
public:
    virtual string name() = 0 ;
    virtual string projectName() = 0;
    virtual int income() = 0;
    virtual string livingCity() = 0;
};

class SoftwareEngineer : public SoftwareEngineerInterface  {

private:
    StudentInterface* student;

public:
    void getStudentInfo(StudentInterface* student) {
        this->student = student;
    }

    string name() {
        return student->firstName() + " " + student->lastName();
    }
    string projectName() {
        return "Streaming Library";
    }

    int income() {
        return 2200;
    }
    string livingCity() {
        return student->livingCity();
    }
};


class GeneralPerson {

private:
    SoftwareEngineerInterface* softwareEngineer;

public:

    void askQuestionTo(SoftwareEngineerInterface* softwareEngineer) {
        this->softwareEngineer = softwareEngineer;
    }

    void comment() {
        if( softwareEngineer->income() < 20000 )  {
            cout<<"Income is Very Poor"<<endl;
        }

        if( softwareEngineer->livingCity() == "Dhaka" ) {
            cout<<"Wow.. you live in capital City"<<endl;
        }

        cout<<"See You again "<<softwareEngineer->name()<<endl;
    }
};

int main(){

    Student* stu = new Student;
    SoftwareEngineer* soft = new SoftwareEngineer;

    GeneralPerson* person = new GeneralPerson;

    // after few years, became Software Engineer From Student
    soft->getStudentInfo(stu);

    // General Person Asking Question
    person->askQuestionTo(soft);

    //Comment
    person->comment();
    return 0;
}
