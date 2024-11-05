#include "header.h"
#include "Stud.h"

int main() {
    auto programaStart = dabLaikas();

    int n;
    int ndSkaicius;
    char ndPasirinkimas;
    char duomPasirinkimas;
    char outputPasirinkimas;
    char sortPasirinkimas;
    string failoPav;

    chrono::duration<double> nuskaitytiFailaDuration;
    chrono::duration<double> sortDuration;
    chrono::duration<double> paskirstytiStudDuration; 
    chrono::duration<double> isvestiFailaSaunuoliaiDuration; 
    chrono::duration<double> isvestiFailaNevykeliaiDuration;

    list<Stud> studentai;

    //uzkomentavau, kad kiekviena karta negeneruotu tu failu
    // auto generuotiStart = dabLaikas();
    // generuotiFailus("stud1000.txt", 1000);
    // generuotiFailus("stud10000.txt", 10000);
    // generuotiFailus("stud100000.txt", 100000);
    // generuotiFailus("stud1000000.txt", 1000000);
    // generuotiFailus("stud10000000.txt", 10000000);
    auto generuotiEnd = dabLaikas();
    // chrono::duration<double> generuotiDuration = generuotiEnd - generuotiStart;
    // std::cout << fixed << setprecision(5) << "Failo stud1000.txt generavimas uztruko: " << generuotiDuration.count() << " sekundes." << endl;


    cout << "Ar norite duomenis ivesti ranka (iveskite r), sugeneruoti atsitiktinai (iveskite a) ar nuskaityti is failo (ivesite f)? ";
    while(true) {
        cin >> duomPasirinkimas;
        if (duomPasirinkimas == 'R' || duomPasirinkimas == 'r' || duomPasirinkimas == 'A' || duomPasirinkimas == 'a' || duomPasirinkimas == 'F' || duomPasirinkimas == 'f')
            break;
        else
            cout <<"Neteisingas pasirinkimas, iveskite ranka (r), atsitiktinai (a), is failo (f): ";
    }

    if (duomPasirinkimas == 'R' || duomPasirinkimas == 'r') {
        do {
            cout << "Iveskite studentu skaiciu: ";
            cin >> n;
            studentai.resize(n);

            if (cin.fail() || n < 0) {
                cout << "klaida, iveskite teigiama sveika skaiciu." << endl;
                cin.clear(); 
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                n = -1;
            }
        } while (n < 0);

        do {
            cout << "Iveskite namu darbu skaiciu: ";
            cin >> ndSkaicius;
            
            if (cin.fail() || ndSkaicius < 0) {
                cout << "klaida, iveskite teigiama sveika skaiciu." << endl;
                cin.clear(); 
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                ndSkaicius = -1;
            }
        } while (ndSkaicius < 0);

        ivestiDuomenisRanka(studentai, ndSkaicius);
    }
    else if (duomPasirinkimas == 'A' || duomPasirinkimas == 'a') {
        do {
            cout << "Iveskite studentu skaiciu: ";
            cin >> n;
            
            if (cin.fail() || n < 0) {
                cout << "klaida, iveskite teigiama sveika skaiciu." << endl;
                cin.clear(); 
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                n = -1;
            }
        } while (n < 0);

        studentai.resize(n);

        do {
            cout << "Iveskite namu darbu skaiciu: ";
            cin >> ndSkaicius;
            
            if (cin.fail() || ndSkaicius < 0) {
                cout << "klaida, iveskite teigiama sveika skaiciu." << endl;
                cin.clear(); 
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                ndSkaicius = -1;
            }
        } while (ndSkaicius < 0);
        
        atsitiktiniaiPazymiai(studentai, ndSkaicius);
    }
    else if (duomPasirinkimas == 'F' || duomPasirinkimas == 'f') {
        cout << "Iveskite failo, kuri norite nuskaityti pavadinima: ";
        cin >> failoPav;

        auto nuskaitytiFailaStart = dabLaikas();
        nuskaitytiFaila(studentai, failoPav);
        auto nuskaitytiFailaEnd = dabLaikas();
        nuskaitytiFailaDuration = nuskaitytiFailaEnd - nuskaitytiFailaStart;
    }   
    
    cout << "Ar norite skaiciuoti galutini pazymi pagal namu darbu vidurki (iveskite v) ar mediana (iveskite m)? ";
     while(true) {
        cin >> ndPasirinkimas;
        if (ndPasirinkimas == 'V' || ndPasirinkimas == 'v' || ndPasirinkimas == 'M' || ndPasirinkimas == 'm')
            break;
        else
            cout <<"Neteisingas pasirinkimas, iveskite vidurki (v) arba mediana (m): ";
    }

    cout << "Ar norite surusiuoti pagal studento varda (iveskite v), pagal pavarde (iveskite p) ar pagal galutini pazymi (iveskite g)? ";
    while(true) {
        cin >> sortPasirinkimas;
        if (sortPasirinkimas == 'V' || sortPasirinkimas == 'v' || sortPasirinkimas == 'P' || sortPasirinkimas == 'p' || sortPasirinkimas == 'G' || sortPasirinkimas == 'g')
            break;
        else
            cout <<"Neteisingas pasirinkimas, iveskite rusiuoti pagal varda (v) arba pavarde (p): ";
    }

    auto sortStart = dabLaikas();
    if (sortPasirinkimas == 'V' || sortPasirinkimas == 'v') {

        studentai.sort([&](Stud &stud1, Stud &stud2) {
            return stud1.vardas < stud2.vardas; 
        });
    }
    else if (sortPasirinkimas == 'P' || sortPasirinkimas == 'p') {
        studentai.sort([&](Stud &stud1, Stud &stud2) {
            return stud1.pavarde < stud2.pavarde; 
        }); 
        }
    else if (sortPasirinkimas == 'G' || sortPasirinkimas == 'g') {
        studentai.sort([&](Stud &stud1, Stud &stud2) {
            return galutinis(stud1, ndPasirinkimas) > galutinis(stud2, ndPasirinkimas);
        });
        }
        
    auto sortEnd = dabLaikas();
    sortDuration = sortEnd - sortStart;
    
    cout << "Ar norite duomenis parodyti terminale (iveskite t), isvesti i faila paprastai (iveskite f) ar suskirstyti ir isvesti i faila (iveskite s)? ";
    while(true) {
        cin >> outputPasirinkimas;
        if (outputPasirinkimas == 'T' || outputPasirinkimas == 't' || outputPasirinkimas == 'F' || outputPasirinkimas == 'f' || outputPasirinkimas == 'S' || outputPasirinkimas == 's')
            break;
        else
            cout <<"Neteisingas pasirinkimas, iveskite parodyti terminale (t) arba i faila (f): ";
    }

    if (outputPasirinkimas == 'T' || outputPasirinkimas == 't') {
        if (duomPasirinkimas == 'R' || duomPasirinkimas == 'r' || duomPasirinkimas == 'A' || duomPasirinkimas == 'a') {
            spausdintiSuAdresu(studentai, ndPasirinkimas);
        }
        else {
            spausdinti(studentai, ndPasirinkimas);
        }
    }
    else if(outputPasirinkimas == 'F' || outputPasirinkimas == 'f')
        isvestiFaila(studentai, ndPasirinkimas, "rezultatai.txt");
    else if (outputPasirinkimas == 'S' || outputPasirinkimas == 's') {
        list<Stud> nevykeliai;

        auto paskirstytiStudStart = dabLaikas();
        paskirtytiStud(studentai, nevykeliai, ndPasirinkimas);
        auto paskirstytiStudEnd = dabLaikas();
        paskirstytiStudDuration = paskirstytiStudEnd - paskirstytiStudStart;

        auto isvestiFailaSaunuoliaiStart = dabLaikas();
        isvestiFaila(studentai, ndPasirinkimas, "saunuoliai.txt");
        auto isvestiFailaSaunuoliaiEnd = dabLaikas();
        isvestiFailaSaunuoliaiDuration = isvestiFailaSaunuoliaiEnd - isvestiFailaSaunuoliaiStart;

        auto isvestiFailaNevykeliaiStart = dabLaikas();
        isvestiFaila(nevykeliai, ndPasirinkimas, "nevykeliai.txt");
        auto isvestiFailaNevykeliaiEnd = dabLaikas();
        isvestiFailaNevykeliaiDuration = isvestiFailaNevykeliaiEnd - isvestiFailaNevykeliaiStart;

    }
    auto programaEnd = dabLaikas();
    chrono::duration<double> programaDuration = programaEnd - programaStart;

    cout << " " << endl;
    cout << "Programos spartos analize: " << endl;

    cout << fixed << setprecision(5) << "Failo "<< failoPav << " irasu nuskaitymo laikas: " << nuskaitytiFailaDuration.count() << " sekundes." << endl;
    cout << fixed << setprecision(5) << "Failo "<< failoPav << " irasu rusiavimo laikas: " << sortDuration.count() << " sekundes." << endl;
    cout << fixed << setprecision(5) << "Failo "<< failoPav << " irasu paskirtymo i saunuolius ir nevykelius laikas: " << paskirstytiStudDuration.count() << " sekundes." << endl;
    cout << fixed << setprecision(5) << "Failo "<< failoPav << " irasu saunuoliu irasymo i faila laikas: " << isvestiFailaSaunuoliaiDuration.count() << " sekundes." << endl;
    cout << fixed << setprecision(5) << "Failo "<< failoPav << " irasu nevykeliu irasymo i faila laikas: " << isvestiFailaNevykeliaiDuration.count() << " sekundes." << endl;
    cout << fixed << setprecision(5) << "Programos veikimas uztruko: " << programaDuration.count() << " sekundes." << endl;

    for (auto &student : studentai) {
        valymas(student);
    }
        
    return 0;
};
