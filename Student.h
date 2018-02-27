/*
 * Student.h
 *
 *  Created on: Feb 24, 2018
 *      Author: raymondlaurente
 */

#include <stdio.h>
#include <string>

using namespace std;
#pragma once

class Student{
public:
    Student(); // default constructor
    ~Student(); // deconstructor
    Student(const Student &rhs);
    Student(const string &cwid); // constructor with parameter
    Student & operator=(const Student &rhs);
    void addCourseGrade(const string &courseName, char grade); // add course name and grade to student's record
    double getGPA(); // calculate and return GPA
    void printTranscript(); // print transcript - see Student.cpp for the format
    string getCWID(); // return the CWID of this student
    void newStudent(string &cwid);
private:
    // any private member variables and methods go here
    string id;
    string *_courseName;
    char *_grade;
    int numberOfCourses;

};
