#include "header.h"

class Stud {
    private:
    string vardas;
    string pavarde;
    vector<int> nd; 
    int egz;

    public:
    Stud() : vardas(""), pavarde(""), nd{}, egz(0) { }
    Stud(std::istream& is);

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

    void setNd(const vector<int> n) {
        nd = n;
    }

    int getOnePaz(const vector<int> &nd, int i) const {
        return nd.at(i);
    }

    void setOnePaz(int paz) {
        nd.push_back(paz);
    }

    void valymas() {
        vardas.clear();
        pavarde.clear();
        nd.clear();
    }

};

double ndVidurkis(const Stud &student);
double ndMediana(const Stud &student);
double galutinis(const Stud &student, char pasirinkimas);
void ivestiDuomenisRanka(vector<Stud> &student, int ndSkaicius);
void atsitiktiniaiPazymiai(vector<Stud> &student, double ndSkaicius);
void nuskaitytiFaila(vector<Stud> &student, string failoPav);
void spausdinti(vector<Stud> &student, char pasirinkimas);
void isvestiFaila(vector<Stud> student, char pasirinkimas, string failoPav);
void generuotiFailus(string failoPav, int studSk);
void paskirtytiStud(vector<Stud> &studentai, vector<Stud> &saunuoliai, vector<Stud> &nevykeliai, char pasirinkimas);
std::chrono::steady_clock::time_point dabLaikas();
