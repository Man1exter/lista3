// utwórz w programie egzemplarze klas Student oraz Pracownik,a następnie (przypisz ich składnikom danych wartości pobrane z klawiatury)
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <ctime>
#include <dos.h>

using namespace std;

class Osoba {

    private:

        string imie;
        string nazwisko;
        int wiek;

    protected:

        string zebrane_imie(){
            return imie;
        }
        void imie_wybrane(string imie) {
            this->imie = imie;
        }
        string zebrane_nazwisko(){
            return nazwisko;
        }
        void Nazwisko_wybrane(string nazwisko) {
            this->nazwisko = nazwisko;
        }
        int zebrane_wiek() {
            return wiek;
        }
        void wiek_wybrany(int wiek) {
            this->wiek = wiek;
        }

    public:
        void pokaz_dane(){
            cout << endl;
            cout << 
            "Imie:" << zebrane_imie() << endl << 
            "Nazwisko:" << zebrane_nazwisko() << endl << 
            "Wiek:" << zebrane_wiek() << endl;
            cout << endl;
};

        Osoba(string imie, string nazwisko, int wiek){
            imie_wybrane(imie);
            Nazwisko_wybrane(nazwisko);
            wiek_wybrany(wiek);
        };
        Osoba(){};
};


class Student : public Osoba {

    friend void wprowadz_dane(Student &stu){

        string imie, nazwisko, grupa;
        int wiek;

        cout << "Podaj imie: ";
        cin >> imie;
        cout << "Podaj nazwisko: ";
        cin >> nazwisko;
        cout << "Podaj wiek: ";
        cin >> wiek;
        cout << "Podaj grupe: ";
        cin >> grupa;
        cout << endl;

        stu.imie_wybrane(imie);
        stu.Nazwisko_wybrane(nazwisko);
        stu.wiek_wybrany(wiek);
        stu.grupa = grupa;
    }

    private:

        string grupa;

    public:

        void pokaz_dane(){
            cout << endl;
            cout << 
            "Imie:" << zebrane_imie() << endl << 
            "Nazwisko:" << zebrane_nazwisko() << endl << 
            "Wiek:" << zebrane_wiek() << endl << 
            "Grupa:" << grupa<< endl;
            cout << endl;
        };
        Student(string imie, string nazwisko, int wiek, string grupa){
            imie_wybrane(imie);
            Nazwisko_wybrane(nazwisko);
            wiek_wybrany(wiek);
            this->grupa = grupa;
        };
        Student(){};
};


class Pracownik : public Osoba
{

friend void wprowadz_dane(Pracownik &prac){

    string imie, nazwisko, stanowisko;
    int wiek;

    cout << "Podaj imie: ";
    cin >> imie;
    cout << "Podaj nazwisko: ";
    cin >> nazwisko;
    cout << "Podaj wiek: ";
    cin >> wiek;
    cout << "Podaj stanowisko: ";
    cin >> stanowisko;
    cout << endl;

    prac.imie_wybrane(imie);
    prac.Nazwisko_wybrane(nazwisko);
    prac.wiek_wybrany(wiek);
    prac.stanowisko = stanowisko;

}

private:

    string stanowisko;

public:

    void pokaz_dane() {
         cout << endl;
         cout << 
         "Imie:" << zebrane_imie() << endl << 
         "Nazwisko:" << zebrane_nazwisko() << endl << 
         "Wiek:" << zebrane_wiek() << endl << 
         "Stanowisko:" << stanowisko << endl;
         cout << endl;
    };

    Pracownik(string imie, string nazwisko, int wiek, string stanowisko) {
        imie_wybrane(imie);
        Nazwisko_wybrane(nazwisko);
        wiek_wybrany(wiek);
        this->stanowisko = stanowisko;
    };

    Pracownik(){};
};


int main() {
   
    Student studentTest;
    wprowadz_dane(studentTest);

    Pracownik pracownikTest;
    wprowadz_dane(pracownikTest);

    studentTest.pokaz_dane();
    pracownikTest.pokaz_dane();
}


// Przykład z użyciem wskaznika this->
// #include <iostream>

// class Klasa
// {
// public:
//     void m( Klasa & x )
//     {
//         if( this == & x )
//              std::cout << "Uzyto tego samego obiektu" << std::endl;
//         else
//              std::cout << "Uzyto innego obiektu" << std::endl;
       
//     }
// };

// int main()
// {
//     Klasa a, b;
//     a.m( b );
//     b.m( b );
// }