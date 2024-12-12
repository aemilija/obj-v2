#include "Stud.h"

/**
 * @brief Funkcija, kuri suskaiciuoja studentu namu darbu vidurkis
 * @param student Studentu vektorius, kuriu namu darbu vidurkis skaicuojamas
 * @return Grazinamas namu darbu vidurkis
 */

double ndVidurkis(const Stud &student) { 
    if (student.getNd().empty())
        return 0.0;

    double ndSuma = 0;

    for (int pazymys : student.getNd())
        ndSuma += pazymys;

    return ndSuma / static_cast<double>(student.getNd().size());
};

/**
 * @brief Funkcija, kuri suskaiciuoja studentu namu darbu mediana
 * @param student Studentu vektorius, kuriu namu darbu mediana skaicuojama
 * @return Grazinama namu darbu mediana
 */

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

/**
 * @brief Funkcija, kuri suskaiciuoja galutini rezultata,  naudojantis formule 0.4*ndPasirinkimas+0.6+egz
 * @param student Studentu vektorius, kuriu galutinis pazymys bus skaiciuojamas
 * @param pasirinkimas Pasirinkimas (vidurkis arba mediana), pagal kuri bus skaiciuojamas galutinis pazymis
 * @return Grazinamas studento galutinis pazymys
 */
double galutinis(const Stud &student, char pasirinkimas) {
    double ndPasirinkimas; 
    if (pasirinkimas == 'M' || pasirinkimas == 'm')
            ndPasirinkimas = ndMediana(student);
        else
            ndPasirinkimas = ndVidurkis(student);
    return 0.4 * ndPasirinkimas + 0.6 * student.getEgz();
};

/**
 * @brief Funkcija, kuria ivedami studentu duomenys ranka - vardas, pavarde, namu darbu ir egzamino pazymiai
 * @param student Studentu vektorius, kuriu duomenys ivedami
 */

void ivestiDuomenisRanka(vector<Stud> &student) {

    for (int i = 0; i < student.size(); i++) { //iteruojame per visus studentus, tol kol i reiksme nebus didesne uz vektoriaus dydi (studentu skaiciu)
        cout << "Iveskite " << i + 1 << " studento duomenis: " << endl;
        cin >> student.at(i);
    }
};

/**
 * @brief Funkcija, kuri atsitiktinai generuoja studento pazymius (varda pavarde reikia ivesti ranka)
 * @param student Studentu vektorius, kuriu duomenys generuojami
 * @param ndSkaicius Namu darbu skaicius, kuri reikia ivesti
 */

void atsitiktiniaiPazymiai(vector<Stud> &student, double ndSkaicius) {
    
    for (int i = 0; i < student.size(); i++) { //iteruojame per visus studentus, tol kol i reiksme nebus didesne uz studentu skaiciu
        cout << "Iveskite " << i + 1 << " studento varda ir pavarde: "; //ranka ivedame studentu vardus ir pavardes
        string v, p;
        cin >> v >> p;

        student.at(i).setVardas(v);
        student.at(i).setPavarde(p);
        student.at(i).getNd().resize(ndSkaicius); //pakeicia studentu namu darbu vektoriaus dydi, kad sutaptu su ndSkaiciaus reiksme
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

/**
 * @brief Funkcija, kuri nuskaito faile esancius studentu duomenis
 * @param student Studentu vektorius, kuriu duomenys bus nuskaitomi
 * @param failoPav Failo, kuri nuskaitome pavadinimas
 */

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

/**
 * @brief Funkcija, kuri isspausdina studento varda, pavarde ir galutini vidurki (pagal vidurki arba mediana)
 * @param student Studentu vektorius, kuriu duomenys bus isspausdinami
 * @param pasirinkimas Galutinio pazymio skaiciavimo pasirinkimas (vidurkis arba mediana)
 */

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

/**
 * @brief Funckija, kuri isveda duomenis i faila
 * @param student Studentu vektorius, kurio duomenys bus isvedami i faila 
 * @param pasirinkimas Galutinio pazymio skaiciavimo pasirinkimas (vidurkis arba mediana)
 * @param failoPav Kaip norime pavadinti isvedama faila
 */

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

/**
 * @brief Funkcija, kuri generuoja failus su atsitiktiniais duomenimis
 * @param failoPav Kaip norime pavadinti generuojama faila
 * @param studSk Skaicius studentu, kuriu duomenis norime atsitiktinai sugeneruoti
 */

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

/**
 * @brief Funkcija, kuri paskirsto studentus i saunuolius ir nevykelius pagal ju pazymius
 * @param studentai Studentu vektorius, kur laikomi visi studentai
 * @param saunuoliai Saunuoliu vektorius, kuriame bus laikomi studentai su galutiniu pazymiu >= 5
 * @param nevykeliai Nevykeliu vektorius, kuriame bus laikomi studentai su galutiniu pazymiu <= 5
 * @param pasirinkimas Galutinio pazymio skaiciavimo pasirinkimas (vidurkis arba mediana)
 */

void paskirtytiStud(std::vector<Stud>& studentai, std::vector<Stud>& saunuoliai, std::vector<Stud>& nevykeliai, char pasirinkimas) {
    auto it = std::partition(studentai.begin(), studentai.end(), [&](const Stud& studentas) { 
        return galutinis(studentas, pasirinkimas) >= 5.0; });
    
    saunuoliai.assign(studentai.begin(), it);
    nevykeliai.assign(it, studentai.end());
}


/**
 * @brief Funkcija, kuri parodo dabartini laika, naudoja chrono biblioteka
 */

std::chrono::steady_clock::time_point dabLaikas() {
    return std::chrono::steady_clock::now();
};

/**
 * @brief Funkcija, kuri patikrina ar testas pavyko ar nepavyko
 * @param a Logine reiksme, kuri parodo ar testas sekmingas (true) ar ne (false)
 * @param pav Tekstas, kuris isvedamas su testo rezultatu
 */

void patikrinti(bool a, const string& pav) {
    if(a) {
        cout << pav << " pavyko :)" << endl;
    }
    else {
        cout << pav << " nepavyko :(" << endl;
    }
}

/**
 * @brief Funkcija, kuri demonstruoja Rule Of Three - kopijavimo konstruktoriu, kopijavimo priskyrimo konstruktoriu ir destruktoriu.
 */
void test() {
    Stud s;
    // suteikiamos reiksmes studentui
    s.setVardas("Emilija");
    s.setPavarde("Abromaityte");
    s.setOnePaz(10);
    s.setOnePaz(7);
    s.setEgz(9);
 
    cout << "Isvesties operatoriaus testavimas: " << endl;
    cout << s << endl;

    // kopijavimo konstruktorius
    Stud s2 = s;

    patikrinti(s2.getVardas() == s.getVardas(), "kopijavimo konstruktorius - vardas");
    patikrinti(s2.getPavarde() == s.getPavarde(), "kopijavimo konstruktorius - pavarde");
    patikrinti(s2.getNd() == s.getNd(), "kopijavimo konstruktorius - nd");
    patikrinti(s2.getEgz() == s.getEgz(), "kopijavimo konstruktorius - egz");

    // kopijavimo priskyrimo konstruktorius
    Stud s3;
    s3 = s;

    patikrinti(s3.getVardas() == s.getVardas(), "kopijavimo priskyrimo konstruktorius - vardas");
    patikrinti(s3.getPavarde() == s.getPavarde(), "kopijavimo priskyrimo konstruktorius - pavarde");
    patikrinti(s3.getNd() == s.getNd(), "kopijavimo priskyrimo konstruktorius - nd");
    patikrinti(s3.getEgz() == s.getEgz(), "kopijavimo priskyrimo konstruktorius - egz");

    // pakeiciame pradinio vektoriaus reiksmes
    s.setVardas("Austeja");
    s.setPavarde("Navikaite");

    // patikriname ar kopijos nepasikeite
    patikrinti(s2.getVardas() == "Emilija", "kopija s2 nepasikeite - vardas");
    patikrinti(s2.getPavarde() == "Abromaityte", "kopija s2 nepasikeite - pavarde");
    patikrinti(s3.getVardas() == "Emilija", "kopija s3 nepasikeite - vardas");
    patikrinti(s3.getPavarde() == "Abromaityte", "kopija s3 nepasikeite - pavarde");

    patikrinti(s2.getVardas() == "Austeja", "kopija s2 nepasikeite - vardas");
    patikrinti(s3.getPavarde() == "Navikaite", "kopija s3 nepasikeite - pavarde");

}
