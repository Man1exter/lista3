#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <iomanip>

using namespace std;

class Student
{
    string myName, myStudentID, myClassID;
public:
    Student(string name, string studentID, string classID)
    {
        myName = name;
        myStudentID = studentID;
        myClassID = classID;
    }

    string getName() { return myName; }
    string getStudentID() { return myStudentID; }
    void printInfo() { cout << myName << setw(15) << myStudentID << setw(10) << myClassID << endl; }

};

int main()
{
    int num;
    std::vector<Student> studentList;
    cout << "How many students do you wish to add to the student list ? " << endl;
    cin >> num;


    cin.ignore();
    for (int a = 0; a < num; a++)
    {

        string inputName, inputStudentID, inputClassID;
        //get name
        cout << "Please enter the Student name : ";
        getline(cin, inputName);


        //get student ID
        cout << "Please enter the Student ID number : ";
        getline(cin, inputStudentID);


        //get class ID
        cout << "Please enter the Student class ID : ";
        getline(cin, inputClassID);



        Student thisStudent(inputName, inputStudentID, inputClassID);
        studentList.push_back(thisStudent);

        cout << endl;
    }

    //sort(studentList.begin(), studentList.end());
    /*
    I never figured out how to sort the list by name.
    I do not know how to compare the name of studentList[0] and studentList[1]
    to put them in alphabetical order.
    */
    cout << endl;; // FORMATTING

    cout << "The student list has a size of " << studentList.size() << endl;

    cout << endl;; // FORMATTING


    cout << "Student Name" << setw(15) << "Student ID" << setw(10) << "Class ID" << endl;
    for (int a = 0; a < studentList.size(); a++)
    {
        studentList[a].printInfo();
    }

    cout << endl;; // FORMATTING


    string searchedName;
    char answer;
    do
    {
        cout << endl;; // FORMATTING
        cout << "Please type the name of the person you want to search for: ";
        getline(cin, searchedName);
        for (int a = 0; a < studentList.size(); a++)
        {
            if (searchedName.compare(studentList[a].getName()) == 0)
            {
                studentList[a].printInfo();
                break;
            }
            else
                if (a == (studentList.size() - 1)) //If went to end of the list, tell them name not found.
                    cout << "There is no " << searchedName << " in the list. \n";


        }

        cout << "Would you like to search for another person? \n";
        cout << "Y for Yes, N for No. \n";
        cin >> answer;
        cin.ignore();

    } while (answer == 'Y' || answer == 'y');


    return 0;




}