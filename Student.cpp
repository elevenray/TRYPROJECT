/*
 * Student.cpp
 *
 *  Created on: Feb 24, 2018
 *      Author: raymondlaurente
 */

//
//  Student.cpp
//  project1
//
//  Created by Raymond Laurente on 2/8/18.
//  Copyright © 2018 Raymond Laurente. All rights reserved.
//

#include "Student.h"
#include <iostream>
#include <iomanip>
#include <string>

Student::Student() {
    id = "0";
    _courseName = new string[50];
    _grade = new char[50];
    numberOfCourses = 0;
}

Student::~Student(){

   delete [] _courseName;
   delete [] _grade;
}

Student::Student(const Student &rhs){
    id = rhs.id;
    numberOfCourses = rhs.numberOfCourses;
    _courseName = new string[numberOfCourses];
    _grade = new char[numberOfCourses];
    for(int i = 0; i < numberOfCourses; i++)
    {
        _courseName[i] = rhs._courseName[i];
        _grade[i] = rhs._grade[i];
    }

}


Student & Student::operator=(const Student &rhs){
    delete [] _courseName;
    delete [] _grade;
    id = rhs.id;
    numberOfCourses = rhs.numberOfCourses;
    _courseName = new string[numberOfCourses];
    _grade = new char[numberOfCourses];
    for(int i = 0; i < numberOfCourses; i++)
    {
        _courseName[i] = rhs._courseName[i];
        _grade[i] = rhs._grade[i];
    }
    return *this;
}


Student::Student(const string &cwid) {
    _courseName = new string[50];
    _grade = new char[50];
    id = cwid;
    numberOfCourses= 0;
}
void Student::newStudent(string &cwid){
    id = cwid;
}


string Student::getCWID() {
    return id;
}

void Student::addCourseGrade(const string &courseName, char grade) {
    _courseName[numberOfCourses] = courseName;
    _grade[numberOfCourses] = grade;
    numberOfCourses++;
}

double Student::getGPA() {
    double total = 0;
    for (int i = 0; i <= numberOfCourses; i++)
    {
        switch (_grade[i])
        {
            case 'A':
                total += 4.0;
                break;
            case 'B':
                total += 3.0;
                break;
            case 'C':
                total += 2.0;
                break;
            case 'D':
                total += 1.0;
                break;
            case 'F':
                total += 0.0;
                break;
            default:
                break;
        }
    }
    return total/numberOfCourses;
}

void Student::printTranscript(){
    cout << "TRANSCRIPT FOR CWID = " << getCWID() << endl;;
    for(int i = 0; i < numberOfCourses; i++)
    {
        cout << _courseName[i] << setw(4) << _grade[i]<< endl;
    }
    cout << "GPA = " << setprecision(2) << getGPA() << endl;
}




