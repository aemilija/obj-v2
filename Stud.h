#include "header.h"

struct Stud { //sukuriama studento struktura, kurioje saugoma vardas, pavarde, namu darbu (2) ir egzamino pazymiai
    string vardas;
    string pavarde;
    vector<int> nd; 
    int egz;
};

double ndVidurkis(const Stud &student);
double ndMediana(const Stud &student);
double galutinis(const Stud &student, char pasirinkimas);
void ivestiDuomenisRanka(list<Stud> &student, int ndSkaicius);
void atsitiktiniaiPazymiai(list<Stud> &student, double ndSkaicius);
void nuskaitytiFaila(list<Stud> &student, string failoPav);
void spausdinti(list<Stud> &student, char pasirinkimas);
void spausdintiSuAdresu(list<Stud> &student, char pasirinkimas);
void isvestiFaila(list<Stud> student, char pasirinkimas, string failoPav);
void generuotiFailus(string failoPav, int studSk);
void paskirtytiStud(list<Stud> &studentai, list<Stud> &saunuoliai, list<Stud> &nevykeliai, char pasirinkimas);
std::chrono::steady_clock::time_point dabLaikas();
void valymas(Stud & student);
