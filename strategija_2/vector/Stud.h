#include "header.h"

struct Stud { //sukuriama studento struktura, kurioje saugoma vardas, pavarde, namu darbu (2) ir egzamino pazymiai
    string vardas;
    string pavarde;
    vector<int> nd; //nd saugome vector tipo konteineryje
    int egz;
};

double ndVidurkis(const Stud &student);
double ndMediana(const Stud &student);
double galutinis(const Stud &student, char pasirinkimas);
void ivestiDuomenisRanka(vector<Stud> &student, int ndSkaicius);
void atsitiktiniaiPazymiai(vector<Stud> &student, double ndSkaicius);
void nuskaitytiFaila(vector<Stud> &student, string failoPav);
void spausdinti(vector<Stud> &student, char pasirinkimas);
void spausdintiSuAdresu(vector<Stud> &student, char pasirinkimas);
void isvestiFaila(vector<Stud> student, char pasirinkimas, string failoPav);
void generuotiFailus(string failoPav, int studSk);
void paskirtytiStud(vector<Stud> &studentai, vector<Stud> &nevykeliai, char pasirinkimas);
std::chrono::steady_clock::time_point dabLaikas();
void valymas(Stud & student);
