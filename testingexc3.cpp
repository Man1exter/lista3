#include <iostream>
#include <string>
using namespace std;


class Student
{
private:
    string name,name2,groupID;
    int ageID;

public:
    void getDetails();
    void setDetails();
};


void Student::setDetails()
{
    cout << "Podaj imie : ";
    cin >> name;
    cout << "Podaj wiek : ";
    cin >> ageID;
    cout << "Podaj nazwisko : ";
    cin >> name2;
    cout << "Podaj grupe : ";
    cin >> groupID;

    cout << endl;
    cout << endl;
}


void Student::getDetails()
{
    // cout << "Imie : " << name << " wiek : " << ageID << " Nazwisko : " << name2 << endl;

    cout << "Imie : " << name << endl;
    cout << "Nazwisko : " << name2 << endl;
    cout << "Wiek : " << ageID << endl;
    cout << "Grupa : " << groupID << endl;
}

int main()
{
    
    int count;
    cout << "Podaj ilosc studentow do wpisania : ";
    cin >> count;

    
    if (count > 0)
    {
        
        Student studentArray[count];
        for (int i = 0; i < count; i++)
        {
            cout << "Informacje o studencie " << i + 1 << " :" << endl;
            studentArray[i].setDetails();
        }

       
        cout << "\n[Poukladano alfabetycznie] + Wpisales studentow : " << endl;
        for (int i = 0; i < count; i++)
        {
            studentArray[i].getDetails();
            cout << endl;
        }
    }
    else
    {
        cout << "Podaj poprawnie wartosc." << endl;
    }
    return 0;
}