#include "Stud.h"

//funkcija, kuri suskaiciuoja namu darbu vidurki
double ndVidurkis(const Stud &student) { 
    if (student.nd.empty())
        return 0.0;

    double ndSuma = 0;

    for (int pazymys : student.nd)
        ndSuma += pazymys;

    return ndSuma / static_cast<double>(student.nd.size());
};

//funkcija,kuri apskaiciuoja nd mediana
double ndMediana(const Stud &student) {
    if (student.nd.empty())
        return 0.0;

    vector<int> arr = student.nd;
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
    return 0.4 * ndPasirinkimas + 0.6 * student.egz;
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

//funkcija, kuri atsitiktinai generuoja studento pazymius (varda pavarde ivesti ranka)
void atsitiktiniaiPazymiai(vector<Stud> &student, double ndSkaicius) {
    for (int i = 0; i < student.size(); ++i) { //iteruojame per visus studentus, tol kol i reiksme nebus didesne uz studentu skaiciu
        cout << "Iveskite " << i + 1 << " studento varda ir pavarde: "; //ranka ivedame studentu vardus ir pavardes
        cin >> student[i].vardas >> student[i].pavarde;
        student[i].nd.resize(ndSkaicius); //pakeicia studentu namu darbu vektoriaus dydi, kad sutaptu su ndSkaiciaus reiksme
        for (int j = 0; j < ndSkaicius; ++j) { //iteruojame per studento namu darbus, tol kol j reiksme nebus didesne uz ndSkaiciaus reiksme
            student[i].nd[j] = rand() % 10 + 1; //sugeneruojami atsitiktiniai nd pazymiai intervale [1,10]
        }
        student[i].egz = rand() % 10 + 1;
    }
};

//funkcija, kuri nuskaito duomenis is failo
void nuskaitytiFaila(vector<Stud> &student) {
    ifstream file("kursiokai.txt"); //failas, kuri norim nuskaityti
    string line;

    if (!file) {
        throw runtime_error("Failo nepavyko atidaryti");
    }

    getline(file, line); //praleidziame pirma eilute

    while(getline(file, line)) { //skaito po viena eilute
        istringstream iss(line);
        Stud stud;
        iss >> stud.vardas >> stud.pavarde;

        int paz;
        while(iss >> paz) { //istraukiami visi pazymiai is eilutes ir sudedam i nd vektoriu
            stud.nd.push_back(paz);
        }

        if (!stud.nd.empty()) { //tikrina ar nd vektorius nera tuscias
            stud.egz = stud.nd.back(); //paskutinis nd vektoriaus pazymys yra egz pazymys
            stud.nd.pop_back(); //pasalina paskutine  reiksme is nd vektoriaus
        }

        student.push_back(stud);
    }
    file.close();
};

//funkcija, kuri isspausdina studento varda, pavarde ir galutini vidurki 
void spausdinti(vector<Stud> &student, char pasirinkimas) {
    cout << left << setw(15) << "Vardas" << setw(15) << "Pavarde" 
    << setw(20) << (pasirinkimas == 'M' || pasirinkimas == 'm' ? "Galutinis (Med.)" : "Galutinis(Vid.)") << endl; //lenteles headeris - lygiuojame pagal kaire, set width 15 - tiek simboliu galima ivesti
    cout << "------------------------------------------------------" << endl;

    for (const auto& student : student) {
        double galutinisRez = galutinis(student, pasirinkimas);
        cout << left << setw(15) << student.vardas << setw(15) << student.pavarde 
        << setw(20) << fixed << setprecision(2) << galutinisRez << endl;

    }
};

void isvestiFaila(vector<Stud> student, char pasirinkimas) {
    ofstream file("rezultatai.txt");

    file << left << setw(15) << "Vardas" << setw(15) << "Pavarde" 
    << setw(20) << (pasirinkimas == 'M' || pasirinkimas == 'm' ? "Galutinis (Med.)" : "Galutinis(Vid.)") << endl;
    cout << "------------------------------------------------------" << endl;
    
    for (const auto& student : student) {
        double galutinisRez = galutinis(student, pasirinkimas);
        file << left << setw(15) << student.vardas << setw(15) << student.pavarde 
        << setw(20) << fixed << setprecision(2) << galutinisRez << endl;
    };

    file.close();
    cout << "duomenys isvede i faila";
};

//funkcija, kuri isvalo duomenis
void valymas(Stud & student) {
    student.vardas.clear();
    student.pavarde.clear();
    student.nd.clear();
}
