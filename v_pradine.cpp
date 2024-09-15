#include <iostream>
using namespace std;

struct Stud { //sukuriama studento struktura, kurioje saugoma vardas, pavarde, namu darbu (2) ir egzamino pazymiai
    string vardas;
    string pavarde;
    int nd[2]; //kadangi pirma nepasakyta, kad nezinome nd skaiciaus, tariame kad ju yra 2
    int egz;
};
