/*
 * Registrar.h
 *
 *  Created on: Feb 24, 2018
 *      Author: raymondlaurente
 */

#include <stdio.h>
#include <iostream>
#include <string>
#include <stdexcept>
#include "Student.h"

using namespace std;

class Registrar {
public:

    Registrar();
    Registrar(Registrar & other);
    Registrar & operator=(const Registrar &rhs);
    void readTextfile(string filename); // Load information from a text file with the given filename: THIS IS COMPLETE
    void addLine(string courseName, string cwid, char grade); // process a line from the text file
    Student& getStudent(string cwid) const; // return the Student object corresponding to a given CWID
    // getStudent must throw an exception if cwid is invalid
    // add constructors, destructors, assignment operators if needed


private:
    Student *rStudent;
    int numberOfStudent;
    static const int SIZE = 50000;
    // other variables required to implement the public member functions
    // TO BE COMPLETED

};
