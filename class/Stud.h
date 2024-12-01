#include "header.h"

class Stud {
    private:
    string vardas;
    string pavarde;
    vector<int> nd; 
    int egz;

    public:
    //konstruktorius
    Stud() : vardas(""), pavarde(""), nd{}, egz(0) {}
    //destruktorius
    ~Stud() {
        vardas.clear();
        pavarde.clear();
        nd.clear();
        egz = 0;
    }

    //kopijavimo konstruktorius
    Stud(const Stud &kitas) : vardas(kitas.vardas), pavarde(kitas.pavarde), nd(kitas.nd), egz(kitas.egz) {}
    
    //kopijavimo priskyrimo operatorius

    Stud& operator = (const Stud &kitas) {
        if (this != &kitas) {
            vardas = kitas.vardas;
            pavarde = kitas.pavarde;
            nd = kitas.nd;
            egz = kitas.egz;
        }
        return *this;
    } 

    //ivesties operatorius
    friend istream& operator >> (istream &is, Stud &stud) {
        cout << "Iveskite studento varda pavarde: ";
        is >> stud.vardas >> stud.pavarde;

        cout << "Iveskite nd skaiciu: ";
        int ndSkaicius;
        is >> ndSkaicius;
        stud.nd.clear();

        cout << "Iveskite " << stud.getNd().size() << " namu darbu pazymius: ";
        for (int i = 0; i < stud.nd.size(); ++i) {
            int paz;
            is >> paz;
            stud.nd.push_back(paz);
        }

        cout << "Iveskite egzamino pazymi: ";
        is >> stud.egz;

        return is;

    }

    //isvesties operatorius

    //getteriaim, setteriai
    string getVardas() const {
        return vardas;
    }

    void setVardas (const string &v) {
        vardas = v;
    }

    string getPavarde() const {
        return pavarde;
    }

    void setPavarde(const string &p) {
        pavarde = p;
    }

    vector<int> getNd() const {
        return nd;
    }

    void setNd(const vector<int> &n) {
        nd = n;
    }

    int getOnePaz(int i) const {
        return nd.at(i);
    }

    void setOnePaz(int paz) {
        nd.push_back(paz);
    }

    int getEgz() const {
        return egz;
    }

    void setEgz(int &e) {
        egz = e;    
    }
};

double ndVidurkis(const Stud &student);
double ndMediana(const Stud &student);
double galutinis(const Stud &student, char pasirinkimas);
void ivestiDuomenisRanka(vector<Stud> &student);
void atsitiktiniaiPazymiai(vector<Stud> &student, double ndSkaicius);
void nuskaitytiFaila(vector<Stud> &student, string failoPav);
void spausdinti(vector<Stud> &student, char pasirinkimas);
void isvestiFaila(vector<Stud> student, char pasirinkimas, string failoPav);
void generuotiFailus(string failoPav, int studSk);
void paskirtytiStud(vector<Stud> &studentai, vector<Stud> &saunuoliai, vector<Stud> &nevykeliai, char pasirinkimas);
std::chrono::steady_clock::time_point dabLaikas();
