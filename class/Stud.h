#include "header.h"
class Zmogus {
    protected:
    string vardas;
    string pavarde;

    public:
    //konstruktoriai
    Zmogus() : vardas(""), pavarde("") {}
    Zmogus(const string& v, const string&p) : vardas(v), pavarde(p) {}

    //destruktorius
    virtual ~Zmogus() = 0;

    //getteriai, setteriai
    string getVardas() const { return vardas; }
    string getPavarde() const { return pavarde; }

    string setVardas(const string& v) { return vardas = v; }
    string setPavarde(const string& p) { return pavarde = p; }
};

inline Zmogus::~Zmogus() {}

class Stud : public Zmogus {
    private:
    vector<int> nd; 
    int egz;

    public:
    //konstruktorius
    Stud() : Zmogus("", ""), nd{}, egz(0) {}
    Stud(const string& v, const string& p, const vector<int> n, int e) : Zmogus(v, p), nd(n), egz(e) {}

    //destruktorius
    ~Stud() override {
        vardas.clear();
        pavarde.clear();
        nd.clear();
        egz = 0;

        // cout << "destrukorius ivykdytas" << endl;
    }

    //kopijavimo konstruktorius
    Stud(const Stud &kitas) : Zmogus(kitas.vardas, kitas.pavarde), nd(kitas.nd), egz(kitas.egz) {}
    
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

        cout << "Iveskite " << ndSkaicius << " namu darbu pazymius: ";
        for (int i = 0; i < ndSkaicius; ++i) {
            int paz;
            is >> paz;
            stud.nd.push_back(paz);
        }

        cout << "Iveskite egzamino pazymi: ";
        is >> stud.egz;

        return is;

    }

    //isvesties operatorius
    friend ostream& operator << (ostream &out, const Stud &stud) {
        out << "Vardas: " << stud.getVardas() << endl;
        out << "Pavarde: " << stud.getPavarde() << endl;
        out << "Egzamino rezultatas: " << stud.getEgz() << endl;
        out << "Pazymiai: ";
        vector<int> paz = stud.getNd();
        for (int i = 0; i < paz.size(); i++){
            out << paz.at(i) << " ";
        }
        out << endl;
        return out;
    }

    //getteriai, setteriai
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

    void setEgz(const int &e) {
        egz = e;    
    }
};

double ndVidurkis(const Stud &student);
double ndMediana(const Stud &student);
double galutinis(const Stud &student, char pasirinkimas);
void ivestiDuomenisRanka(vector<Stud> &student, int ndSkaicius);
void atsitiktiniaiPazymiai(vector<Stud> &student, double ndSkaicius);
void nuskaitytiFaila(vector<Stud> &student, string failoPav);
void spausdinti(vector<Stud>& studentai, char pasirinkimas);
void isvestiFaila(vector<Stud> student, char pasirinkimas, string failoPav);
void generuotiFailus(string failoPav, int studSk);
void paskirtytiStud(vector<Stud> &studentai, vector<Stud> &saunuoliai, vector<Stud> &nevykeliai, char pasirinkimas);
std::chrono::steady_clock::time_point dabLaikas();
void patikrinti(bool a, const string& pav);
void test();
