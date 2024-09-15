#include <iostream>

using namespace std;

struct Stud { //sukuriama studento struktura, kurioje saugoma vardas, pavarde, namu darbu (2) ir egzamino pazymiai
    string vardas;
    string pavarde;
    int nd[2]; //kadangi pirma nepasakyta, kad nezinome nd skaiciaus, tariame kad ju yra 2
    int egz;
};

//funkcija, kuri suskaiciuoja namu darbu vidurki
double ndVidurkis(const Stud &student) { 
    return (student.nd[0] + student.nd[1]) / 2.0; 
};

//funkcija, kuri suskaiciuoja galutini rezultata, naudojantis formule 0.4*ndAvg+0.6+egz
double galutinis(const Stud &student) {
    double ndVid = ndVidurkis(student);
    return 0.4 * ndVid + 0.6 * student.egz;
};
