#include "header.h"
#include "Stud.h"

int main() {
    int n;
    int ndSkaicius;
    char ndPasirinkimas;
    char duomPasirinkimas;
    char outputPasirinkimas;
    char sortPasirinkimas;
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

    cout << "Ar norite surusiuoti pagal studento varda (iveskite v) ar pagal pavarde (iveskite p)?";
    cin >> sortPasirinkimas;

    if (sortPasirinkimas == 'V' || sortPasirinkimas == 'v') {
        sort(studentai.begin(), studentai.end(), [](Stud &stud1, Stud &stud2) {
            return stud1.vardas < stud2.vardas; 
        });
    }
    else if (sortPasirinkimas == 'P' || sortPasirinkimas == 'p') {
        sort(studentai.begin(), studentai.end(), [](Stud &stud1, Stud &stud2) {
            return stud1.pavarde < stud2.pavarde; 
        });
    }
    

    cout << "Ar norite duomenis parodyti terminale (iveskite t) ar isvesti i faila (iveskite f)?";
    cin >> outputPasirinkimas;

    if (outputPasirinkimas == 'T' || outputPasirinkimas == 't')
        spausdinti(studentai, ndPasirinkimas);
    else if(outputPasirinkimas == 'F' || outputPasirinkimas == 'f')
        isvestiFaila(studentai, ndPasirinkimas);
   
    for (auto &student : studentai) {
        valymas(student);
    }
    return 0;
};
