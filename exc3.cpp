// zmodyfikowana czesc zadania z listy 3, do latwiejszego wprowadzenia w liste 4 
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
    string myName, myStudentID, myClassID, myAgeID, myGroupID;

public:
    Student(string name, string studentID, string classID, string ageID, string groupID)
    {
        myName = name;
        myStudentID = studentID;
        myClassID = classID;
        myAgeID = ageID;
        myGroupID = groupID;
    }

    string getName() { return myName; }
    string getStudentID() { return myStudentID; }
    void printInfo() { cout << myName << setw(25) << myStudentID << setw(20) << myClassID << setw(20) << myAgeID << setw(20) << myGroupID << endl; }

};

int main()
{
    int num;
    std::vector<Student> studentList;

    
    cout << "Ilu studentow dodac do listy? " << endl;
    cin >> num;


    cin.ignore();
    for (int a = 0; a < num; a++)
    {

        string inputName, inputStudentID, inputClassID, inputAgeID, inputGroupID;

        cout << "Podaj imie: ";
        getline(cin, inputName);


        cout << "Podaj nazwisko: ";
        getline(cin, inputStudentID);


        cout << "Podaj numer katalogu studenta: ";
        getline(cin, inputClassID);

        cout << "Podaj wiek studenta: ";
        getline(cin, inputAgeID);


        cout << "Podaj grupe studenta: ";
        getline(cin, inputGroupID);
 
        Student thisStudent(inputName, inputStudentID, inputClassID, inputAgeID, inputGroupID);
        studentList.push_back(thisStudent);

        cout << endl;

    }

    cout << endl;; 

    cout << "Rozmiar listy studentow to " << studentList.size() << endl;

    cout << endl;; 


    cout << "IMIE STUDENTA" << setw(25) << "NAZWISKO STUDENTA" << setw(20) << "INDEX STUDENTA" << setw(20) << "WIEK STUDENTA" << setw(20) << "GRUPA STUDENTA" << endl;
    for (int a = 0; a < studentList.size(); a++)
    {
        studentList[a].printInfo();
    }

    cout << endl;; 


    string searchedName;
    char answer;
    do
    {
        cout << endl;; 
        cout << "Podaj imie studenta wyszukiwanego na liscie: ";
        getline(cin, searchedName);
        for (int a = 0; a < studentList.size(); a++)
        {
            if (searchedName.compare(studentList[a].getName()) == 0)
            {
                studentList[a].printInfo();
                break;
            }
            else
                if (a == (studentList.size() - 1)) 
                    cout << "Nie ma studenta " << searchedName << " na liscie. \n";


        }

        cout << "Czy chcialbys poszukac innej osoby? \n";
        cout << "Y dla tak, N dla nie. \n";
        cin >> answer;
        cin.ignore();

    } while (answer == 'Y' || answer == 'y');


    return 0;

}