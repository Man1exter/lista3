// Korzystając z programu opisanego w zadaniu 1  - Lista laboratoryjna nr 2, 
// stwórz tablicę obiektów klasy StudentEdukacja.
// Posortuj tablicę według numeru indeksu studenta wykorzystując mechanizm klasyzaprzyjaźnionej(dodatkowa klasa odpowiedzialna za sortowanie).
// W programie zastosuj podejście obiektowe pokazane na poniższym diagramie UML (klasa Student Edukacja dziedziczy składniki po klasie Student)

#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <ctime>
#include <dos.h>


const int N = 3;


using namespace std;

class Osoba {
    private:
        string imie;
        string nazwisko;
        int wiek;
    protected:
        string getImie(){
            return imie;
        }
        void setImie(string imie) {
            this->imie = imie;
        }
        string getNazwisko(){
            return nazwisko;
        }
        void setNazwisko(string nazwisko) {
            this->nazwisko = nazwisko;
        }
        int getWiek() {
            return wiek;
        }
        void setWiek(int wiek) {
            this->wiek = wiek;
        }
    public:
        void pokaz_dane(){
            cout << endl;
            cout << 
            "Imie:" << getImie() << endl << 
            "Nazwisko:" << getNazwisko() << endl << 
            "Wiek:" << getWiek() << endl;
            cout << endl;
};
        Osoba(string imie, string nazwisko, int wiek){
            setImie(imie);
            setNazwisko(nazwisko);
            setWiek(wiek);
        };
        Osoba(){};
};
class Student : public Osoba {
    private:
        string grupa;
    protected:
        string getGrupa(){
            return grupa;
        }
        void setGrupa(string grupa) {
            this->grupa = grupa;
        }
    public:
        void pokaz_dane(){
            cout << endl;
            cout << 
            "Imie:" << getImie() << endl << 
            "Nazwisko:" << getNazwisko() << endl << 
            "Wiek:" << getWiek() << endl << 
            "Grupa:" << grupa<< endl;
            cout << endl;
        };
        Student(string imie, string nazwisko, int wiek, string grupa){
            setImie(imie);
            setNazwisko(nazwisko);
            setWiek(wiek);
            this->grupa = grupa;
        };
        Student(){};
};
class Pracownik : public Osoba {
private:
    string stanowisko;
public:
    void pokaz_dane() {
         cout << endl;
         cout << 
         "Imie:" << getImie() << endl << 
         "Nazwisko:" << getNazwisko() << endl << 
         "Wiek:" << getWiek() << endl << 
         "Stanowisko:" << stanowisko << endl;
         cout << endl;
    };
    Pracownik(string imie, string nazwisko, int wiek, string stanowisko) {
        setImie(imie);
        setNazwisko(nazwisko);
        setWiek(wiek);
        this->stanowisko = stanowisko;
    };
    Pracownik(){};
};
class StudentEdukacja: public Student 
{
    friend class studentSort;
private:
    int numer_indeksu;
    void setNrIndeksu(int nr_indeksu) {
        this->numer_indeksu = nr_indeksu;
    }
    int getNrIndeksu() {
        return numer_indeksu;
    }
public:
    StudentEdukacja(string imie, string nazwisko, int wiek, string grupa){
        setImie(imie);
        setNazwisko(nazwisko);
        setWiek(wiek);
        setGrupa(grupa);
    };
    StudentEdukacja(){};
    
};
class studentSort {
    private:
        StudentEdukacja students[N];
        void sortArray(){
            StudentEdukacja buf;
            int k;
            for(k=0;k<N-1;k++)
                for(int j=k+1;j<N;j++)
                    if(students[k].getNrIndeksu()>students[j].numer_indeksu){
                        buf=students[k];
                        students[k]=students[j];
                        students[j]=buf;
            }
        };
    public:
        void fillArray(){
            srand(time(NULL));
            int nr_indeksu;
            for (int i=0; i<N; i++) { 
                int ranWiek = rand()% 30 + 25;
                students[i] = StudentEdukacja("Jan", "Kowalski", ranWiek, "Programowanie");
                cout << "Podaj nr indeksu: ";
                cin >> nr_indeksu;
                students[i].setNrIndeksu(nr_indeksu);
            }
        };
        void showArray() {
            sortArray();
            for (int i=0;i<N;i++) { 
                cout << students[i].getImie() 
                << " "  << students[i].getNazwisko() 
                << " "  << students[i].getWiek() 
                << " "  << students[i].getGrupa()
                << " "  << students[i].getNrIndeksu()
                << endl;
            }
        }
      

};

int main() {
  
  studentSort group;
  group.fillArray();
  group.showArray();
  return 0;


}