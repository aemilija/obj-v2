#include "header.h"
#include "Stud.h"

/**
 * @brief Funkcija, kuria yra vykdoma programa
 * 1. Paklausia, ar norima testuoti konstruktorius ir operatorius
 * 2. Paklausia, ar norima generuoti failus su atsitiktiniais duomenimis
 * 3.Paklausia, ar norima ivesti duomenis ranka, generuoti atsitiktinai ar skaityti is failo
 * 4. Paklausia, ar norima galutini pazymi skaiciuoti pagal vidurki arba mediana
 * 5. Paklausia, ar norima skirstyti studentus i saunuolius ir nevykelius
 * 6. Paklausia, ar norima surusiuoti studentus pagal varda, pavarde arba galutini pazymi
 * 7. Paklausia, ar norima duomenis isvesti i terminala arba i faila
 * 
 * Visos programos metu yra skaiciuojama sparta, kuri isspausdinama gale
 */
int main() {
    auto programaStart = dabLaikas();

    int n;
    char ndPasirinkimas;
    char duomPasirinkimas;
    char outputPasirinkimas;
    char sortPasirinkimas;
    char genPasirinkimas;
    char skirstPasirinkimas;
    char testPasirinkimas;
    string failoPav;
    int ndSkaicius;

    chrono::duration<double> nuskaitytiFailaDuration;
    chrono::duration<double> sortDuration;
    chrono::duration<double> paskirstytiStudDuration; 
    chrono::duration<double> isvestiFailaSaunuoliaiDuration; 
    chrono::duration<double> isvestiFailaNevykeliaiDuration;

    vector<Stud> studentai;
    vector<Stud> saunuoliai;
    vector<Stud> nevykeliai;

    cout << "Ar norite testuoti, iveskite t (taip) arba n (ne)? ";
    cin >> testPasirinkimas;
    while(true) {
        if (testPasirinkimas == 'T' || testPasirinkimas == 't' || testPasirinkimas == 'N' || testPasirinkimas == 'n') {
            break;
        }
        else {
            cout << "Neteisingas pasirinkimas, iveskit t (taip) arba n (ne): ";
        }
    }

    if (testPasirinkimas == 'T' || testPasirinkimas == 't') {
        cout << "--- Testavimas ---" << endl;
        test();
        cout << "-------------------" << endl;
        exit(0);
    }
    
    cout << "Ar norite generuoti failus, iveskite t (taip) arba n (ne)? ";
    cin >> genPasirinkimas;
    while(true) {
        if (genPasirinkimas == 'T' || genPasirinkimas == 't' || genPasirinkimas == 'N' || genPasirinkimas == 'n') {
            break;
        }
        else {
            cout << "Neteisingas pasirinkimas, iveskit t (taip) arba n (ne): ";
        }
    }

    if (genPasirinkimas == 'T' || genPasirinkimas == 't') {
        auto generuotiStart = dabLaikas();
        generuotiFailus("stud100.txt", 100);
        // generuotiFailus("stud1000.txt", 1000);
        // generuotiFailus("stud10000.txt", 10000);
        // generuotiFailus("stud100000.txt", 100000);
        // generuotiFailus("stud1000000.txt", 1000000);
        // generuotiFailus("stud10000000.txt", 10000000);
        auto generuotiEnd = dabLaikas();
        chrono::duration<double> generuotiDuration = generuotiEnd - generuotiStart;
        std::cout << fixed << setprecision(5) << "Failu generavimas uztruko: " << generuotiDuration.count() << " sekundes." << endl;
        exit(0);
    }

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

        ivestiDuomenisRanka(studentai);
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

    cout << "Ar norite suskirstyti studentus, iveskite t (taip) arba n (ne)? ";
    while(true) {
        cin >> skirstPasirinkimas;
        if (skirstPasirinkimas == 'T' || skirstPasirinkimas == 't' || skirstPasirinkimas == 'N' || skirstPasirinkimas == 'n') {
            break;
        }
        else {
            cout << "Neteisingas pasirinkimas, iveskite t (taip) arba n (ne): ";
        }
    }

    if (skirstPasirinkimas == 'T' || skirstPasirinkimas == 't') {
        // vector<Stud> saunuoliai;
        // vector<Stud> nevykeliai;

        auto paskirstytiStudStart = dabLaikas();
        paskirtytiStud(studentai, saunuoliai, nevykeliai, ndPasirinkimas);
        auto paskirstytiStudEnd = dabLaikas();
        paskirstytiStudDuration = paskirstytiStudEnd - paskirstytiStudStart;
    }



    cout << "Ar norite surusiuoti pagal studento varda (iveskite v), pagal pavarde (iveskite p) ar pagal galutini pazymi (iveskite g)? ";
    while(true) {
        cin >> sortPasirinkimas;
        if (sortPasirinkimas == 'V' || sortPasirinkimas == 'v' || sortPasirinkimas == 'P' || sortPasirinkimas == 'p' || sortPasirinkimas == 'G' || sortPasirinkimas == 'g' )
            break;
        else
            cout <<"Neteisingas pasirinkimas, iveskite rusiuoti pagal varda (v), pavarde (p) arba galutini pazymi (g): ";
    }

    auto sortStart = dabLaikas();
    if (sortPasirinkimas == 'V' || sortPasirinkimas == 'v') {
        sort(studentai.begin(), studentai.end(), [&](Stud &stud1, Stud &stud2) {
            return stud1.getVardas() < stud2.getVardas(); 
        });

        if (skirstPasirinkimas == 'T' || skirstPasirinkimas == 't') {
            sort(saunuoliai.begin(), saunuoliai.end(), [&](Stud &stud1, Stud &stud2) {
            return stud1.getVardas() < stud2.getVardas(); 
            });

            sort(nevykeliai.begin(), nevykeliai.end(), [&](Stud &stud1, Stud &stud2) {
            return stud1.getVardas() < stud2.getVardas(); 
            });
        }
    }
    else if (sortPasirinkimas == 'P' || sortPasirinkimas == 'p') {
        sort(studentai.begin(), studentai.end(), [&](Stud &stud1, Stud &stud2) {
            return stud1.getPavarde() < stud2.getPavarde(); 
        });

        if (skirstPasirinkimas == 'T' || skirstPasirinkimas == 't') {
            sort(saunuoliai.begin(), saunuoliai.end(), [&](Stud &stud1, Stud &stud2) {
            return stud1.getPavarde() < stud2.getPavarde(); 
            });

            sort(nevykeliai.begin(), nevykeliai.end(), [&](Stud &stud1, Stud &stud2) {
            return stud1.getPavarde() < stud2.getPavarde(); 
            });
        }
    }
    else {
        sort(studentai.begin(), studentai.end(), [&] (Stud &stud1, Stud &stud2) {
            return galutinis(stud1, ndPasirinkimas) > galutinis(stud2, ndPasirinkimas);
        });

        if (skirstPasirinkimas == 'T' || skirstPasirinkimas == 't') {
            sort(saunuoliai.begin(), saunuoliai.end(), [&](Stud &stud1, Stud &stud2) {
            return galutinis(stud1, ndPasirinkimas) > galutinis(stud2, ndPasirinkimas);
            });

            sort(nevykeliai.begin(), nevykeliai.end(), [&](Stud &stud1, Stud &stud2) {
            return galutinis(stud1, ndPasirinkimas) > galutinis(stud2, ndPasirinkimas);
            });
        }
    }
    auto sortEnd = dabLaikas();
    sortDuration = sortEnd - sortStart;
    
    cout << "Ar norite duomenis parodyti terminale (iveskite t) ar isvesti i faila (iveskite f)? ";
    while(true) {
        cin >> outputPasirinkimas;
        if (outputPasirinkimas == 'T' || outputPasirinkimas == 't' || outputPasirinkimas == 'F' || outputPasirinkimas == 'f' || outputPasirinkimas == 'S' || outputPasirinkimas == 's')
            break;
        else
            cout <<"Neteisingas pasirinkimas, iveskite parodyti terminale (t) arba i faila (f): ";
    }

    if (outputPasirinkimas == 'T' || outputPasirinkimas == 't')
        spausdinti(studentai, ndPasirinkimas);
    else if(outputPasirinkimas == 'F' || outputPasirinkimas == 'f') {
        if (skirstPasirinkimas == 'T' || skirstPasirinkimas == 't') {
            auto isvestiFailaSaunuoliaiStart = dabLaikas();
            isvestiFaila(saunuoliai, ndPasirinkimas, "saunuoliai.txt");
            auto isvestiFailaSaunuoliaiEnd = dabLaikas();
            isvestiFailaSaunuoliaiDuration = isvestiFailaSaunuoliaiEnd - isvestiFailaSaunuoliaiStart;

            auto isvestiFailaNevykeliaiStart = dabLaikas();
            isvestiFaila(nevykeliai, ndPasirinkimas, "nevykeliai.txt");
            auto isvestiFailaNevykeliaiEnd = dabLaikas();
            isvestiFailaNevykeliaiDuration = isvestiFailaNevykeliaiEnd - isvestiFailaNevykeliaiStart;
        }

        else {
            isvestiFaila(studentai, ndPasirinkimas, "studentai.txt");
        }
    }

    auto programaEnd = dabLaikas();
    chrono::duration<double> programaDuration = programaEnd - programaStart;

    cout << fixed << setprecision(5) << "Failo "<< failoPav << " irasu nuskaitymo laikas: " << nuskaitytiFailaDuration.count() << " sekundes." << endl;
    cout << fixed << setprecision(5) << "Failo "<< failoPav << " irasu rusiavimo laikas: " << sortDuration.count() << " sekundes." << endl;
    cout << fixed << setprecision(5) << "Failo "<< failoPav << " irasu paskirtymo i saunuolius ir nevykelius laikas: " << paskirstytiStudDuration.count() << " sekundes." << endl;
    cout << fixed << setprecision(5) << "Failo "<< failoPav << " irasu saunuoliu irasymo i faila laikas: " << isvestiFailaSaunuoliaiDuration.count() << " sekundes." << endl;
    cout << fixed << setprecision(5) << "Failo "<< failoPav << " irasu nevykeliu irasymo i faila laikas: " << isvestiFailaNevykeliaiDuration.count() << " sekundes." << endl;
    cout << fixed << setprecision(5) << "Programos veikimas uztruko: " << programaDuration.count() << " sekundes." << endl;

    system("pause");
    
};
