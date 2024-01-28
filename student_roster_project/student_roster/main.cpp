#include <iostream>
#include "roster.h"
using namespace std;



int main()
{
    // string of data to parse
    const string studentData[] =

        {"A1,Greg,Black,GregB1999@gm ail.com,20,30,35,40,SECURITY", "A2,Sarah,Erickson,Erickson_1995@hotmailcom,19,50,30,40,NETWORK", "A3,James,Washington,The_accountant99yahoo.com,19,20,40,33,SOFTWARE", "A4,Eric,White,Eric.white@comcast.net,22,50,58,40,SECURITY", "A5,John,Doe,jdoe29@college.edu,25, 30, 40, 35,SOFTWARE"
        };

    Roster classRoster; // creates roster object using default constructor
    const int studentDataTable = 5; // set array size

    for (int i = 0; i < studentDataTable; i++) classRoster.parse(studentData[i]);
    cout << "All students: " << std::endl << std::endl;
    classRoster.printAll();
    cout << endl;
    // prints all students
    
    cout << "All invalid email addresses:" << std::endl << std::endl;
    classRoster.printInvalidEmails();
    cout << std::endl;
    // prints all students with invalid email addresses
    
    cout << "Average days per class:" << std::endl << std::endl;
    for (int i = 0; i < studentDataTable; i++) {
        classRoster.printAverageNumDays(classRoster.classRosterArray[i]->getStudentID());
    }
    cout << std::endl;
    // prints average numbers of days in 3 classes
    
    cout << "All software students:" << std::endl << std::endl;
    classRoster.printByDegreeProgram(SOFTWARE);
    cout << std:: endl;
    // prints all students in Software program
    
    cout << "Remove student A3." << std::endl;
    classRoster.remove("A3");
    cout << std::endl;
    // Removes student A3
    
    cout << "Remaining Students:" << std::endl << std::endl;
    classRoster.printAll();
    cout << std::endl;
    // second call to printAll function
    
    cout << "Remove student A3." << std::endl;
    classRoster.remove("A3");
    cout << std::endl << std::endl;
    // call function again. Produce error message to show student was removed
    
    // destructor executes and program ends
    
    return 0;
}
