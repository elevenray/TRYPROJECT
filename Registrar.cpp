/*
 * Registrar.cpp
 *
 *  Created on: Feb 24, 2018
 *      Author: raymondlaurente
 */

//
//  Registrar.cpp
//  project1
//
//  Created by Raymond Laurente on 2/8/18.
//  Copyright © 2018 Raymond Laurente. All rights reserved.
//

#include "Registrar.h"
#include "Student.h"
#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>

using namespace std;

Registrar::Registrar(){
    rStudent = new Student[SIZE];
    numberOfStudent = 0;
}

Registrar::Registrar(Registrar & other){
    rStudent = new Student[SIZE];
    numberOfStudent = other.numberOfStudent;
    for(int i = 0; i < numberOfStudent; i++)
    {
        rStudent[i] = other.rStudent[i];
    }
}

Registrar & Registrar::operator=(const Registrar &rhs){
    numberOfStudent = rhs.numberOfStudent;
    delete [] rStudent;
    rStudent = new Student[SIZE];
    for(int i = 0; i < numberOfStudent; i++)
    {
        rStudent[i] = rhs.rStudent[i];
    }
    return *this;

}

// Load information from a text file with the given filename
// THIS FUNCTION IS COMPLETE
void Registrar::readTextfile(string filename) {
    ifstream myfile(filename);

    if (myfile.is_open()) {
        cout << "Successfully opened file " << filename << endl;
        string courseName;
        string cwid;
        char grade;
        while (myfile >> courseName >> cwid >> grade) {
            //cout << courseName << " " << cwid << " " << grade << endl;
            addLine(courseName, cwid, grade);
        }
        myfile.close();
    }
    else
        throw invalid_argument("Could not open file " + filename);
}

// return Student object corresponding to a given CWID
// getStudent must throw an exception if cwid is invalid
Student& Registrar::getStudent(string cwid) const {
    int index;
    for(index = 0; index <numberOfStudent; index++){
        if(rStudent[index].getCWID() == cwid)
        {
            return rStudent[index];
        }
    }
    throw invalid_argument("Student cwid is invalid" + cwid);
}

// process a line from the text file
void Registrar::addLine(string courseName, string cwid, char grade) {
      try{
        Student &s = getStudent(cwid);
        s.addCourseGrade(courseName, grade);
    }
    catch(const exception & e){

        rStudent[numberOfStudent].newStudent(cwid);
        rStudent[numberOfStudent].addCourseGrade(courseName, grade);
        numberOfStudent++;
    }
    //exist it updates
    //adds a course grade to the information
    //if the student does not exist then add the student to the student dynamic memory
    //and updates the size
}



