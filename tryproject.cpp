//============================================================================
// Name        : tryproject.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include <fstream>
#include <string>
#include <stdexcept>

#include "Registrar.h"
#include "Student.h"


using namespace std;

template <typename T>
bool testAnswer(const string &nameOfTest, const T &received, const T &expected);

template <typename T>
bool testAnswerEpsilon(const string &nameOfTest, const T &received, const T &expected);

int main() {
    {
        // test only the Student class
        Student student("123456789");
        testAnswer("Student::getCWID test", student.getCWID(), string("123456789"));
        student.addCourseGrade("cs101", 'A');
        testAnswerEpsilon("Student::getGPA test1", student.getGPA(), 4.0);
        student.addCourseGrade("cs201", 'C');
        testAnswerEpsilon("Student::getGPA test2", student.getGPA(), 3.0);
    }

    {
        // test only the Registrar class
        Registrar spring2018;
        spring2018.addLine("cs101", "123456789", 'A');
        Student s = spring2018.getStudent("123456789");
        testAnswerEpsilon("Registrar::getStudent test1", s.getGPA(), 4.0);
        spring2018.addLine("cs101", "456789321", 'B');
        spring2018.addLine("cs201", "456789321", 'C');
        Student t = spring2018.getStudent("456789321");
        testAnswerEpsilon("Registrar::getStudent test1", t.getGPA(), 2.5);
        // test if error checking is done in Registrar::getStudent
        try {
            spring2018.getStudent("9999");
            cout << "FAILED Registrar::getStudent did not throw exception for invalid CWID" << endl;
        }
        catch (exception &e) {
            cout << "Caught exception: " << e.what() << endl;
            cout << "PASSED Registrar::getStudent threw exception for invalid CWID" << endl;
        }
    }

    {
        // test Registrar class with text file
        Registrar spring2018;
        spring2018.readTextfile("gradeslist.txt");
        testAnswerEpsilon("Registrar::readTextfile test1", spring2018.getStudent("279750343").getGPA(), 2.66666);
        testAnswerEpsilon("Registrar::readTextfile test2", spring2018.getStudent("546208080").getGPA(), 3.0);
    }

    {
        // test Registrar class with large text file
        Registrar spring2018;
        spring2018.readTextfile("gradeslistbig.txt");
        testAnswerEpsilon("Registrar::readTextfile test3", spring2018.getStudent("225202362").getGPA(), 2.5);
        testAnswerEpsilon("Registrar::readTextfile test4", spring2018.getStudent("568703135").getGPA(), 26.0/9.0);
        spring2018.getStudent("225202362").printTranscript();
        spring2018.getStudent("568703135").printTranscript();
    }

    {
        //// test copy constructor
        Registrar spring2018;
        spring2018.addLine("cs101", "123456789", 'A');
        spring2018.addLine("cs101", "456789321", 'B');
        spring2018.addLine("cs201", "456789321", 'C');
        Registrar fall2018 = spring2018;     //not working - //IT CRASHES RIGHT AFTERWARDS
        testAnswerEpsilon("Registrar copy constructor test1", fall2018.getStudent("456789321").getGPA(), 2.5);
        fall2018.addLine("cs101", "456789321", 'B');
        testAnswerEpsilon("Registrar copy constructor test2", spring2018.getStudent("456789321").getGPA(), 2.5);

        // test assignment operator
        Registrar summer2018;
        summer2018 = spring2018;
        testAnswerEpsilon("Registrar assignment operator test1", summer2018.getStudent("456789321").getGPA(), 2.5);
        summer2018.addLine("cs101", "456789321", 'B');
        testAnswerEpsilon("Registrar assignment operator test2", spring2018.getStudent("456789321").getGPA(), 2.5);
    }

    //system("pause"); // DELETE
}

template <typename T>
bool testAnswer(const string &nameOfTest, const T &received, const T &expected) {
    if (received == expected) {
        cout << "PASSED " << nameOfTest << ": expected and received " << received << endl;
        return true;
    }
    cout << "FAILED " << nameOfTest << ": expected " << expected << " but received " << received << endl;
    return false;
}

template <typename T>
bool testAnswerEpsilon(const string &nameOfTest, const T &received, const T &expected) {
    const double epsilon = 0.0001;
    if ((received - expected < epsilon) && (expected - received < epsilon)) {
        cout << "PASSED " << nameOfTest << ": expected and received " << received << endl;
        return true;
    }
    cout << "FAILED " << nameOfTest << ": expected " << expected << " but received " << received << endl;
    return false;
}
