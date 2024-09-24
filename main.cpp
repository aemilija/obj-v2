#include "header.h"
#include "Stud.h"

int main() {
    int n;
    int ndSkaicius;
    char ndPasirinkimas;
    char duomPasirinkimas;
    string failas;


    cout << "Ar norite duomenis ivesti ranka (iveskite r), sugeneruoti atsitiktinai (iveskite a) ar nuskaityti is failo (ivesite f)?";
    cin >> duomPasirinkimas;
    vector<Stud> studentai;

    if (duomPasirinkimas == 'R' || duomPasirinkimas == 'r') {
        cout << "Iveskite studentu skaiciu: ";
        cin >> n;
        studentai.resize(n);

        cout << "Iveskite namu darbu skaiciu: ";
        cin >> ndSkaicius;
        ivestiDuomenisRanka(studentai, ndSkaicius);
    }
    else if (duomPasirinkimas == 'A' || duomPasirinkimas == 'a') {
        cout << "Iveskite studentu skaiciu: ";
        cin >> n;
        studentai.resize(n);

        cout << "Iveskite namu darbu skaiciu: ";
        cin >> ndSkaicius;
        atsitiktiniaiPazymiai(studentai, ndSkaicius);
    }
    else if (duomPasirinkimas == 'F' || duomPasirinkimas == 'f')
    {
        nuskaitytiFaila(studentai);
    }
    
    cout << "Ar norite matyti galutini vidurki (iveskite v) ar mediana (iveskite m)?";
    cin >> ndPasirinkimas;

    spausdinti(studentai, ndPasirinkimas);
   
    for (auto &student : studentai) {
        valymas(student);
    }
    return 0;
};