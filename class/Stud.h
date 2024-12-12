#include "header.h"

/**
 * Abstrakti klase Zmogus, kuri apibrezia zmogaus objekto savybes
 * Turi du parametrus - varda ir pavarde, default ir parametrizuotas konstruktoriu, destruktoriu, getterius ir setterius.
 */

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

/**
 * Derived klase Stud, kuri apibrezia studento objekto savybes
 * Paveldi viska is klases Zmogus ir turi savo du parametus - namu darbus ir egzamina. Turi savo default ir parametrizuotus konstruktorius, destruktorius, getterius ir setterius.
 * Apibrezti kopijavimo ir kopijavimo priskyrimo konstruktoriai
 */

class Stud : public Zmogus {
    private:
    vector<int> nd; 
    int egz;

    public:

    /**
     * @brief Konstruktorius, kuris vardui pavardei priskiria tuscia string, namu darbai yra tuscias vektrius ir egzamino pazymys lygus 0
     */

    Stud() : Zmogus("", ""), nd{}, egz(0) {}

    /**
     * Konstruktorius, kuris suteikia visiems klases parametrams reiksmes
     * @param v Studento vardas
     * @param p Studento pavarde
     * @param n Studento namu darbu pazymiai
     * @param e Studento egzamino pazymys
     */

    Stud(const string& v, const string& p, const vector<int> n, int e) : Zmogus(v, p), nd(n), egz(e) {}

    /**
     * @brief Destruktorius, kuris isvalo visus duomenis
     */

    ~Stud() {
        vardas.clear();
        pavarde.clear();
        nd.clear();
        egz = 0;

        // cout << "destrukorius ivykdytas" << endl;
    }

    /**
     * @brief Kopijavimo konstruktorius, kuris sukuria kopija is kito studento objekto
     * @param kitas Studentas, kurio duomenys bus nukopijuoti
     */

    Stud(const Stud &kitas) : Zmogus(kitas.vardas, kitas.pavarde), nd(kitas.nd), egz(kitas.egz) {}
    
    /**
     * @brief Kopijavimo priskyrimo operatorius, kuris priskiria vieno studento duomenis kitam
     * @param kitas Studentas, kurio duomenys bus priskirti kitam
     * @return Grazina nuoroda i dabartini objekta
     */

    Stud& operator = (const Stud &kitas) {
        if (this != &kitas) {
            vardas = kitas.vardas;
            pavarde = kitas.pavarde;
            nd = kitas.nd;
            egz = kitas.egz;
        }
        return *this;
    } 

    /**
     * @brief Ivesties operatorius, kuriuo ivedami studento duomenys
     * @param is Ivesties srautas
     * @param stud Studentas, kurio duomenys ivedami
     * @return Ivesties srautas
     */

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

    /**
     * @brief Isvesties operatorius, kuris isveda studento duomenis
     * @param out Isvesties srautas
     * @param stud Studentas, kurio duomenys bus isvedami
     * @return Isvesties srautas
     */

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

    void setEgz(const int &e) {
        egz = e;    
    }
};

double ndVidurkis(const Stud &student);
double ndMediana(const Stud &student);
double galutinis(const Stud &student, char pasirinkimas);
void ivestiDuomenisRanka(vector<Stud> &student);
void atsitiktiniaiPazymiai(vector<Stud> &student, double ndSkaicius);
void nuskaitytiFaila(vector<Stud> &student, string failoPav);
void spausdinti(vector<Stud>& studentai, char pasirinkimas);
void isvestiFaila(vector<Stud> student, char pasirinkimas, string failoPav);
void generuotiFailus(string failoPav, int studSk);
void paskirtytiStud(vector<Stud> &studentai, vector<Stud> &saunuoliai, vector<Stud> &nevykeliai, char pasirinkimas);
std::chrono::steady_clock::time_point dabLaikas();
void patikrinti(bool a, const string& pav);
void test();
