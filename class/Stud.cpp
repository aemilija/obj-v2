#include "Stud.h"

//funkcija, kuri suskaiciuoja namu darbu vidurki
double ndVidurkis(const Stud &student) { 
    if (student.getNd().empty())
        return 0.0;

    double ndSuma = 0;

    for (int pazymys : student.getNd())
        ndSuma += pazymys;

    return ndSuma / static_cast<double>(student.getNd().size());
};

//funkcija,kuri apskaiciuoja nd mediana
double ndMediana(const Stud &student) {
    if (student.getNd().empty())
        return 0.0;

    vector<int> arr = student.getNd();
    int n = arr.size(); //suskaiciuoja, kiek elementu yra sarase
    
    sort(arr.begin(), arr.end()); //surusiuoja sarasa

    if (n % 2 == 1) //kai nelyginis elementu skaicius
        return static_cast<double>(arr[n/2]);
    else //kai lyginis elementu skaicius
        return static_cast<double>(arr[n/2 - 1] + arr[n/2]) / 2.0;
};


//funkcija, kuri suskaiciuoja galutini rezultata, naudojantis formule 0.4*ndPasirinkimas+0.6+egz, pagal pasirinkima ar skaiciuos pagal vidurki ar mediana
double galutinis(const Stud &student, char pasirinkimas) {
    double ndPasirinkimas; 
    if (pasirinkimas == 'M' || pasirinkimas == 'm')
            ndPasirinkimas = ndMediana(student);
        else
            ndPasirinkimas = ndVidurkis(student);
    return 0.4 * ndPasirinkimas + 0.6 * student.getEgz();
};

//funkcija, kuria ivedami studentu duomenys - vardas, pavarde, namu darbu skaicius (pagal si skaiciu suvedami nd pazymiai), ir egzamino pazymys
void ivestiDuomenisRanka(vector<Stud> &student, int ndSkaicius) {
    for (int i = 0; i < student.size(); i++) { //iteruojame per visus studentus, tol kol i reiksme nebus didesne uz vektoriaus dydi (studentu skaiciu)
        string v, p;

        cout << "Iveskite " << i + 1 << " studento varda ir pavarde: ";
        cin >> v >> p;

        student.at(i).setVardas(v);
        student.at(i).setPavarde(p);
        
        student.at(i).getNd().resize(ndSkaicius); //pakeicia studentu namu darbu vektoriaus dydi, kad sutaptu su ndSkaiciaus reiksme

        cout << "Iveskite " << student.at(i).getVardas() << " namu darbu pazymius (" << ndSkaicius << "): ";
        for (int j = 0; j < ndSkaicius; j++) { //iteruojame per studento namu darbus, tol kol j reiksme nebus didesne uz ndSkaiciaus reiksme
            bool validiIvestis = false;
            do {
                int paz;
                cin >> paz;
                student.at(i).setOnePaz(paz);
                if (cin.fail() || student.at(i).getOnePaz(j) < 1 || student.at(i).getOnePaz(j) > 10) {
                    cout << "klaida, iveskite skacius nuo 1 iki 10. " << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Iveskite " << student.at(i).getVardas() << " namu darbu pazymius (" << ndSkaicius << "): ";
                }
                else 
                    validiIvestis = true;
            } while (!validiIvestis);
        }
            do {
                cout << "Iveskite " << student.at(i).getVardas() << " egzamino pazymi: ";
                int e;
                cin >> e;
                student.at(i).setEgz(e);

                if (cin.fail() || student.at(i).getEgz() < 1 || student.at(i).getEgz() > 10) {
                    cout << "klaida, iveskite skaciu nuo 1 iki 10. " << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            } while (cin.fail() || student.at(i).getEgz() < 1 || student.at(i).getEgz() > 10);
    }
};

//funkcija, kuri atsitiktinai generuoja studento pazymius (varda pavarde ivesti ranka)
void atsitiktiniaiPazymiai(vector<Stud> &student, double ndSkaicius) {
    
    for (int i = 0; i < student.size(); i++) { //iteruojame per visus studentus, tol kol i reiksme nebus didesne uz studentu skaiciu
        cout << "Iveskite " << i + 1 << " studento varda ir pavarde: "; //ranka ivedame studentu vardus ir pavardes
        string v, p;
        cin >> v >> p;

        student.at(i).setVardas(v);
        student.at(i).setPavarde(p);
        student[i].getNd().resize(ndSkaicius); //pakeicia studentu namu darbu vektoriaus dydi, kad sutaptu su ndSkaiciaus reiksme
        for (int j = 0; j < ndSkaicius; j++) { //iteruojame per studento namu darbus, tol kol j reiksme nebus didesne uz ndSkaiciaus reiksme
            int paz;
            paz = rand() % 10 + 1;
            student.at(i).setOnePaz(paz); //sugeneruojami atsitiktiniai nd pazymiai intervale [1,10]
        }
        int e;
        e = rand() % 10 + 1;
        student.at(i).setEgz(e);
    }
};

//funkcija, kuri nuskaito faila
void nuskaitytiFaila(vector<Stud> &student, string failoPav) {
    ifstream file;
    try {
        file.open(failoPav);

        if (!file) {
            throw runtime_error("failo nepavyko atidaryti");
        }

        string line;
        getline(file, line); // praleidziame pirma eilute

        while (getline(file, line)) { // skaito po viena eilute
            istringstream iss(line);
            Stud stud;
            string v, p;

            iss >> v >> p;
            stud.setVardas(v);
            stud.setPavarde(p);

            int paz;
            while (iss >> paz) { // istraukiami visi pazymiai is eilutes ir sudedam i nd vektoriu
                stud.setOnePaz(paz);
            }

            if (!stud.getNd().empty()) { // tikrina ar nd vektorius nera tuscias
                int e;
                e = stud.getNd().back(); // paskutinis nd vektoriaus pazymys yra egz pazymys
                stud.setEgz(e);
                stud.getNd().pop_back(); // pasalina paskutine reiksme is nd vektoriaus
            }

            student.push_back(stud); // Add to main vector
        }
        file.close();

    } catch (const runtime_error &e) {
        cerr << "Klaida: " << e.what() << endl;
        exit(EXIT_FAILURE);
    } catch (const exception &e) {
        cerr << "Kita klaida:" << e.what() << endl;
        exit(EXIT_FAILURE);
    }
}

//funkcija, kuri isspausdina studento varda, pavarde ir galutini vidurki 
void spausdinti(vector<Stud> &student, char pasirinkimas) {
    cout << left << setw(15) << "Vardas" << setw(15) << "Pavarde" 
    << setw(20) << (pasirinkimas == 'M' || pasirinkimas == 'm' ? "Galutinis (Med.)" : "Galutinis(Vid.)") << endl; //lenteles headeris - lygiuojame pagal kaire, set width 15 - tiek simboliu galima ivesti
    cout << "------------------------------------------------------" << endl;

    for (const auto& student : student) {
        double galutinisRez = galutinis(student, pasirinkimas);
        cout << left << setw(15) << student.getVardas() << setw(15) << student.getPavarde()
        << setw(20) << fixed << setprecision(2) << galutinisRez << endl;

    }
};

//funckija, kuri isveda duomenis i faila
void isvestiFaila(vector<Stud> student, char pasirinkimas, string failoPav) {
    ofstream file(failoPav); //isvedama i faila pavadinimu rezultatai.txt

    file << left << setw(15) << "Vardas" << setw(15) << "Pavarde" //analogiska spausdinimo f-jai
    << setw(20) << (pasirinkimas == 'M' || pasirinkimas == 'm' ? "Galutinis (Med.)" : "Galutinis(Vid.)") << endl << "-----------------------------------------------" << endl;

    for (const auto& student : student) {
        double galutinisRez = galutinis(student, pasirinkimas);
        file << left << setw(15) << student.getVardas() << setw(15) << student.getPavarde() 
        << setw(20) << fixed << setprecision(2) << galutinisRez << endl;
    };

    file.close();
    cout << "duomenys isvede i faila " << failoPav << endl;
};

//funkcija, kuri generuoja failus su atsitiktiniais duomenimis
void generuotiFailus(string failoPav, int studSk) {
    vector<string> vardai = {"Tomas", "Egle", "Andrius", "Monika", "Mantas", "Ruta", "Justas", "Ieva", "Darius", "Laura", "Emilija", "Igne", "Viktorija", "Rokas", "Gintaras"};
    vector<string> pavardes = {"Kairys", "Seskaukaite", "Pavilonis", "Zukauskaite", "Jankauskas", "Suminas", "Vasiliauskas", "Stankeviciene", "Petruskevicius", "Jakubavicius", "Abromaityte", "Katinas", "Zefyras", "Bublinskas", "Simenyte"};
    
    ofstream file;
    file.open(failoPav);

    file << left << setw(20) << "Vardas" << setw(20) << "Pavarde"; 
    for (int i = 1; i <= 10; ++i) {
        file << setw(10) << "ND" + to_string(i);
    }
    file << setw(10) << "Egz" << endl;

    for (int i = 0; i < studSk; i++) { 
        Stud student;
        string v, p;

        v = vardai[rand() % 15];
        p =pavardes[rand() % 15];

        student.setVardas(v);
        student.setPavarde(p);

        student.getNd().resize(10);

        for (int j = 0; j < 10; j++) { 
            int nd;
            nd = rand() % 10 + 1;
            student.setOnePaz(nd);
        }
        int e;
        e = rand() % 10 + 1;
        student.setEgz(e);

        file << setw(20) << student.getVardas() << setw(20) << student.getPavarde();

        for (const auto& paz : student.getNd()) {
                file << setw(10) << paz;
            }

        file << setw(10) << student.getEgz() << endl;
    }

    file.close();
    cout << "failas sugeneruotas." << endl;
}

//funkcija, kuri paskirsto studentus i saunuolius ir nevykelius
void paskirtytiStud(std::vector<Stud>& studentai, std::vector<Stud>& saunuoliai, std::vector<Stud>& nevykeliai, char pasirinkimas) {
    auto it = std::partition(studentai.begin(), studentai.end(), [&](const Stud& studentas) { 
        return galutinis(studentas, pasirinkimas) >= 5.0; });
    
    saunuoliai.assign(studentai.begin(), it);
    nevykeliai.assign(it, studentai.end());
}


//funkcija, kuri parodo dabartini laika
std::chrono::steady_clock::time_point dabLaikas() {
    return std::chrono::steady_clock::now();
}

