#ifndef Student_h
#define Student_h

#pragma once
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include "degree.h"
using std::string;
using std::cout;


class Student {
    
    public:
        const static int daysArray = 3;

    private: 
        string studentID;
        string firstName;
        string lastName;
        string email;
        int age;
        int days[daysArray];
        DegreeProgram degreeProgram;

    public: // methods
        Student(); // Default constructor - takes no parameters
        Student(string studentID, string firstName, string lastName, string email, int age, int days[], DegreeProgram degreeProgram); // constructor with all parameters
        ~Student(); // declaring destructor

        // getters
        string getStudentID();
        string getFirstName();
        string getLastName();
        string getEmail();
        int getAge();
        int* getNumDays();
        DegreeProgram getDegreeProgram();
        
        // setters
        void setStudentID(string studentID);
        void setFirstName(string firstName);
        void setLastName(string lastName);
        void setEmail(string email);
        void setAge(int age);
        void setNumDays(int days[]);
        void setDegreeProgram(DegreeProgram degreeProgram);

        static void printHeader(); // Prints data header

        void print();
};

#endif
