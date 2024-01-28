#include <string>
#include "roster.h"

void Roster::parse(string studentData) // parses through data in StudentData table
{
    int rhs = studentData.find(','); // finds first comma and returns its index
    string studentID = studentData.substr(0, rhs); // extracts subsstring in front of comma

    int lhs = rhs + 1;// moves past previous comma
    rhs = studentData.find(',', lhs);
    string firstName = studentData.substr(lhs, rhs - lhs);// gets first name
    
    lhs = rhs + 1;
    rhs = studentData.find(',', lhs);
    string lastName = studentData.substr(lhs, rhs - lhs);// gets last name
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string emailAddress = studentData.substr(lhs, rhs -lhs); // gets email address
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int age = std::stoi(studentData.substr(lhs, rhs -lhs)); // gets age from string and converts it to integer
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int daysInCourse1 = stod(studentData.substr(lhs, rhs-lhs)); // days in first course
    
    lhs = rhs + 1; // continue
    rhs = studentData.find(",", lhs);
    int daysInCourse2 = stod(studentData.substr(lhs, rhs-lhs)); // days in second course
    
    lhs = rhs + 1; // continue
    rhs = studentData.find(",", lhs);
    int daysInCourse3 = stod(studentData.substr(lhs, rhs-lhs));  // days in third course
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);

    DegreeProgram degreeProgram  = SECURITY; // degree program initialized to security
    
    if (studentData.at(lhs) == 'S' && studentData.at(lhs + 1) == 'E') degreeProgram = SECURITY; // checks first two characters to determine degree program
    else if (studentData.at(lhs) == 'S' && studentData.at(lhs + 1) == 'O') degreeProgram = SOFTWARE; // checks first two characters to determine degree program
    else if (studentData.at(lhs) == 'N') degreeProgram = NETWORK; // network is the only degree program that starts with 'n'
    
    // add method creates object in roster
    add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram); 
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram)
{
    // days array stores number of days in each course
    int daysArray[3] = {daysInCourse1, daysInCourse2, daysInCourse3};
    classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, daysArray, degreeProgram);// using full constructor to add objects to roster. Increment lastIndex before adding because starting at -1
}

// prints all students. Print header first.
void Roster::printAll() {
    Student::printHeader();
    for (int i = 0; i <= Roster::lastIndex; i++) Roster::classRosterArray[i]->print();
}

void Roster::printInvalidEmails() {
    bool anyInvalidEmails = false;
    // assume all emails are valid
    for (int i = 0; i <= Roster::lastIndex; i++) {
        string email = (classRosterArray[i]->getEmail());
        if ((email.find("@") == string::npos) || (email.find(" ") != string::npos) || (email.find(".") == string::npos)) {
            anyInvalidEmails = true;
            // reassigned to true if if-statement met
            cout << email << ": " << classRosterArray[i]->getFirstName() << std::endl;
            // prints invalid email if one is found
        }
    }
    if (!anyInvalidEmails) cout << "No Invalid Emails" << std::endl;
    // Only prints if no invalid emails
}

void Roster::printAverageNumDays(string studentID) {
    for (int i = 0; i <= Roster::lastIndex; i++) {
        if (classRosterArray[i]->getStudentID()==studentID) {
            cout << studentID << ":";
            cout << (classRosterArray[i]->getNumDays() [0]+
                     classRosterArray[i]->getNumDays() [1]+
                     classRosterArray[i]->getNumDays() [2])/3 << std::endl;
                // adds number of course day counts and divides by 3
        }
    }
}

// prints students in specified degree program
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    Student::printHeader();
    for (int i = 0; i <= Roster::lastIndex; i++) {
        if (Roster::classRosterArray[i]->getDegreeProgram() == degreeProgram) classRosterArray[i]->print();
    }
    cout << std::endl;
}

void Roster::remove(string studentID) {
// takes studentID as parameter and removes student from Roster
    bool studentInRoster = false; // assume student does not exist

    for (int i = 0; i <= Roster::lastIndex; i++) {
        if (classRosterArray[i]->getStudentID() == studentID) {
            studentInRoster = true;
            if (i < studentDataTable - 1) {
                Student* temp = classRosterArray[i]; // swaps places with last student in array
                classRosterArray[i] = classRosterArray[studentDataTable - 1]; // moves pointer
                classRosterArray[studentDataTable - 1] = temp;
            }
            Roster::lastIndex--; // hides last student but doesn't destroy
        }
    }
    if (studentInRoster) {
        cout << "Student " << studentID << " has been removed from roster." << std::endl;
    } else {
        cout << "Error: Student " << studentID << " not found!" << std::endl << std::endl;
    }
}

Roster::~Roster() {
    // destructor for roster ojects
    cout << "Calling destructor..." << std::endl << std:: endl;
    for (int i = 0; i < studentDataTable; i++) {
        cout << "Removing student #" << i + 1 << "..." << std::endl;
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
    cout << std::endl << "Destructor finished." << std::endl;
}

