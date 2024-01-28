#pragma once
#include "student.h"
#ifndef Roster_h
#define Roster_h
#include <stdio.h>


class Roster {
    public:
        int lastIndex = -1;
        const static int studentDataTable = 5;
        Student* classRosterArray[studentDataTable]; // fixes size of roster array pointer
    
    public:    
        // parses through data in StudentData table
        void parse(string row);
        // creates student object using data collected from parse function
        void add(
            string studentID,
            string firstName,
            string lastName,
            string emailAddress,
            int age,
            int daysInCourse1,
            int daysInCourse2,
            int daysInCourse3,
            DegreeProgram degreeProgram
        );
    
    
        // removes student by ID
        void remove(string studentID);
        void printAll();
        void printAverageNumDays(string studentID);
        void printInvalidEmails();
        void printByDegreeProgram(DegreeProgram degreeProgram);
        ~Roster(); // declaring destructor


};


#endif
