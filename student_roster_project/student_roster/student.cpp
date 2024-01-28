#include "student.h"

Student::Student() // default constructor
{
    this->studentID = ""; // default ID blank
    this->firstName = ""; // default first name blank
    this->lastName = ""; // default last name blank
    this->email = ""; // default email blank
    this->age = 0;  // default age 0
    for (int i = 0; i < daysArray; i++) this-> days[i] = 0;
    this->degreeProgram = DegreeProgram::SECURITY; // sets default degree plan to SECURITY 
}

Student::Student(string studentID, string firstName, string lastName, string email, int age, int days[], DegreeProgram degreeProgram) // constructor with parameters
{
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this-> email = email;
    this->age = age;
    for (int i = 0; i < daysArray; i++) this ->days[i] = days[i];
    this ->degreeProgram = degreeProgram;
}

Student::~Student() {} // destructor

// getters
string Student::getStudentID() {return this->studentID;}
string Student::getFirstName() {return this->firstName;}
string Student::getLastName() {return this->lastName;}
string Student::getEmail() {return this->email;}
int Student::getAge() {return this->age;}
int* Student::getNumDays() {return this->days;}
DegreeProgram Student::getDegreeProgram() {return this->degreeProgram;}

// setters
void Student::setStudentID(string studentID){this->studentID = studentID;}
void Student::setFirstName(string firstName) {this->firstName = firstName;}
void Student::setLastName(string lastName){this->lastName = lastName;}
void Student::setEmail(string email){this->email = email;}
void Student::setAge(int age){ this->age = age;}
void Student::setNumDays(int days[])// sets each number of days by index value
{
    for (int i = 0; i <daysArray; i++) this ->days[i] = days[i];
}
void Student::setDegreeProgram(DegreeProgram degreeProgram) {this ->degreeProgram = degreeProgram;}

void Student::printHeader()// prints header to categorize student data
{
    cout << "ID" << '\t' << "First" << '\t' <<"Last" << '\t' << "Email Address" << '\t' << "Age" << '\t'<< "Days to Complete" << '\t'<< "Degree" << std::endl;//format of printout
}

void Student::print()
{
    cout << this->getStudentID() << '\t';// end each with tab to make output easier to read
    cout << this->getFirstName() << '\t';
    cout << this->getLastName() << '\t';
    cout << this->getEmail() << '\t';
    cout << this->getAge() << '\t';
    cout << "(";
    cout << this->getNumDays()[0] << ',';
    cout << this->getNumDays()[1] << ',';
    cout << this->getNumDays()[2];
    cout << ")  ";
    cout << degreeProgramStrings[this->getDegreeProgram()] << '\n';
}
