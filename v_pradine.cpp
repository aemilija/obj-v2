#include <iostream>
#include <iomanip>
#include <vector>

//to do: man rodos reikia padaryti taip, kad visiem studentams butu vienodas nd skaicius, tai pakeisti dalykus, padaryti isimtis su ifais;
using namespace std;

struct Stud { //sukuriama studento struktura, kurioje saugoma vardas, pavarde, namu darbu (2) ir egzamino pazymiai
    string vardas;
    string pavarde;
    vector<int> nd; //nd saugome vector tipo konteineryje
    int egz;
};

//funkcija, kuri suskaiciuoja namu darbu vidurki
double ndVidurkis(const Stud &student) { 
    if (student.nd.empty())
        return 0.0;

    double ndSuma = 0;

    for (int pazymys : student.nd)
        ndSuma += pazymys;

    return ndSuma / student.nd.size();
};


//funkcija, kuri suskaiciuoja galutini rezultata, naudojantis formule 0.4*ndVid+0.6+egz
double galutinis(const Stud &student) {
    double ndVid = ndVidurkis(student);
    return 0.4 * ndVid + 0.6 * student.egz;
};

//funkcija, kuria ivedami studentu duomenys - vardas, pavarde, namu darbu skaicius (pagal si skaiciu suvedami nd pazymiai), ir egzamino pazymys
void ivestiDuomenisRanka(vector<Stud> &student, int ndSkaicius) {
    for (int i = 0; i < student.size(); ++i) { //iteruojame per visus studentus, tol kol i reiksme nebus didesne uz vektoriaus dydi (studentu skaiciu)
        cout << "Iveskite " << i + 1 << " studento varda ir pavarde: ";
        cin >> student[i].vardas >> student[i].pavarde;
        
        // int ndSkaicius;
        // cout << "Iveskite " << student[i].vardas << " namu darbu skaiciu: ";
        // cin >> ndSkaicius;

        student[i].nd.resize(ndSkaicius); //pakeicia studentu namu darbu vektoriaus dydi, kad sutaptu su ndSkaiciaus reiksme

        cout << "Iveskite " << student[i].vardas << " namu darbu pazymius (" << ndSkaicius << "): ";
        for (int j = 0; j < ndSkaicius; ++j) { //iteruojame per studento namu darbus, tol kol j reiksme nebus didesne uz ndSkaiciaus reiksme
            cin >> student[i].nd[j];
        }

        cout << "Iveskite " << student[i].vardas << " egzamino pazymi: ";
        cin >> student[i].egz;
    }
};

//funkcija, kuri isspausdina studento varda, pavarde ir galutini vidurki 
void spausdinti(vector<Stud> &student) {
    cout << left << setw(15) << "Vardas" << setw(15) << "Pavarde" << "Galutinis (Vid.)" << endl; //lenteles headeris - lygiuojame pagal kaire, set width 15 - tiek simboliu galima ivesti
    cout << "------------------------------------------------------" << endl;

    for (const auto& student : student) { //ciklas, kuris eina per visus studentus, apskaiciuoja galutini pazymi ir atspausdina duomenis
        double galutinisPaz = galutinis(student);
        cout << left << setw(15) << student.vardas << setw(15) << student.pavarde << setprecision(2) << galutinisPaz << endl;
    }
};

int main() {
    int n;
    int ndSkaicius;

    cout << "Iveskite studentu skaiciu: ";
    cin >> n;

    cout << "Iveskite namu darbu skaiciu: ";
    cin >> ndSkaicius;

    vector<Stud> studentai(n);
    ivestiDuomenisRanka(studentai, ndSkaicius);
    spausdinti(studentai);

    return 0;
}
