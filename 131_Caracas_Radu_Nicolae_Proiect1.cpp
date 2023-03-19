#include <iostream>
#include <string.h>
#include <string>
#include <fstream>
#include <conio.h>
using namespace std;
ifstream P("prod.in");
ifstream A("art.in");
ifstream S("ses.in");
ifstream E("echi.in");
class Artist;
class Producator
{
    char *nume;
    int discuri_platina;
    bool instrumentist;
    char grad;

public:
    // Constructori
    Producator(const char *nume, int discuri_platina, bool instrumentist, char grad);
    Producator();
    Producator(const Producator &obj);
    ~Producator();
    // Setteri
    void setNume(char *nume);
    void setDiscuri_platina(int discuri_platina);
    void setInstrumentist(bool instrumentist);
    void setGrad(char grad);
    // Getteri
    char *getNume() { return nume; }
    int getDiscuri_platina() { return discuri_platina; }
    bool getInstrumentist() { return instrumentist; }
    char getGrad() { return grad; }
    // friends
    friend int operator+(int x, const Producator &obj);
    friend ostream &operator<<(ostream &out, const Producator &obj);
    friend istream &operator>>(istream &in, Producator &obj);
    friend ifstream &operator>>(ifstream &in, Producator &obj);
    friend int operator+(const Producator &objj, const Artist &obj);
    friend int operator+(const Artist &obj, const Producator &objj);
    // Overloads
    Producator operator&&(const Producator &obj);
    Producator &operator=(const Producator &obj);
    Producator &operator++();
    Producator operator++(int);
    int operator+(int x);
    Producator operator+(const Producator &obj);
    bool operator==(const Producator &obj);
    bool operator>(const Producator &obj);
    operator string();
    // methods
    string nivel();

    void afisare()
    {
        cout << nume << endl;
        cout << discuri_platina << endl;
        cout << instrumentist << endl;
        cout << grad << endl;
    }
};
class Artist
{
    char *nume;
    char *stil_muzical;
    int nr_hituri;
    int *top_hituri;

public:
    // Constructori
    Artist(const char *nume, const char *stil_muzical, int nr_hituri, int *top_hituri);
    Artist();
    Artist(const Artist &obj);
    ~Artist();
    // Setteri
    void setNume(char *nume) { this->nume = nume; }
    void setStil_muzical(char *stil_muzical) { this->stil_muzical = stil_muzical; }
    void setNr_hituri(int nr_hituri) { this->nr_hituri = nr_hituri; }

    // Getteri
    char *getNume() { return nume; }
    char *getStil_muzical() { return stil_muzical; }
    int getNr_hituri() { return nr_hituri; }
    int *getTop_hituri() { return top_hituri; }
    // friends
    friend int operator+(int x, const Producator &obj);
    friend ostream &operator<<(ostream &out, const Artist &obj);
    friend istream &operator>>(istream &in, Artist &obj);
    friend ifstream &operator>>(ifstream &in, Artist &obj);

    friend int operator+(const Producator &objj, const Artist &obj);
    friend int operator+(const Artist &obj, const Producator &objj);
    // overload
    Artist &operator=(const Artist &obj);
    Artist &operator++();
    Artist operator++(int);
    int operator+(int x);
    Artist operator-(int x);
    operator string();
    int operator[](int a);
    Artist operator+(const Artist &obj);
    bool operator>(const Artist &obj);
    bool operator==(const Artist &obj);
    // methods
    string nivel();
    void afisare()
    {
        cout << nume << endl;
        cout << stil_muzical << endl;
        cout << nr_hituri << endl;
        for (int i = 0; i < nr_hituri; i++)
            cout << top_hituri[i] << " ";
        cout << endl;
    }
};
class Sesiune
{
    const int nr_sesiune;
    static int contor_nr_sesiune;
    float ora_incepere;
    float durata;

public:
    // Constructori
    Sesiune();
    Sesiune(float ora_incepere, float durata);
    Sesiune(const Sesiune &obj);

    // setteri
    void setOra_incepere(float ora_incepere) { this->ora_incepere = ora_incepere; }
    void setDurata(float durata) { this->durata = durata; }
    // getteri
    const int getNr_sesiune() { return nr_sesiune; }
    static int getContor_nr_sesiune() { return contor_nr_sesiune; }
    float getOra_incepere() { return ora_incepere; }
    float getDurata() { return durata; }
    // friends
    friend ostream &operator<<(ostream &out, const Sesiune &obj);
    friend istream &operator>>(istream &in, Sesiune &obj);
    friend ifstream &operator>>(ifstream &in, Sesiune &obj);

    friend Sesiune operator+(int x, Sesiune &obj);
    friend Sesiune operator-(int x, Sesiune &obj);
    friend void changeTime(Sesiune &obj, char type, int x);
    // overload
    Sesiune &operator=(const Sesiune &obj);
    Sesiune &operator++();
    Sesiune &operator++(int);
    Sesiune &operator--();
    Sesiune &operator--(int);
    Sesiune &operator+(int x);
    Sesiune &operator-(int x);
    bool operator>(const Sesiune &obj);
    bool operator==(const Sesiune &obj);
    // methods
    Sesiune &extendDuration();
    Sesiune &extendDuration(int x);

    void afisare()
    {
        cout << ora_incepere << endl;
        cout << durata << endl;
    }
};
class Echipament
{
    char *denumire;
    double cost;
    char criteriu_grad;
    bool disponibilitate;

public:
    // Cosntructori
    Echipament();
    Echipament(const char *denumire, double cost, char criteriu_grad, bool disponibilitate);
    Echipament(const Echipament &obj);
    ~Echipament();
    // setteri
    void setDenumire(char *denumire) { this->denumire = denumire; }
    void setCost(double cost) { this->cost = cost; }
    void setCriteriu_grad(char criteriu_grad) { this->criteriu_grad = criteriu_grad; }
    void setDisponibilitate(bool disponibilitate) { this->disponibilitate = disponibilitate; }
    // getteri
    char *getDenumire() { return denumire; }
    double getCost() { return cost; }
    char getCriteriu_grad() { return criteriu_grad; }
    bool getDisponibilitate() { return disponibilitate; }
    // friends
    friend ostream &operator<<(ostream &out, const Echipament &obj);
    friend istream &operator>>(istream &in, Echipament &obj);
    friend ifstream &operator>>(ifstream &in, Echipament &obj);

    friend Echipament operator+(int x, const Echipament &obj);
    friend Echipament operator-(int x, const Echipament &obj);
    // overload
    Echipament &operator=(const Echipament &obj);
    Echipament &operator++();
    Echipament operator++(int);
    Echipament operator+(int x);
    Echipament operator-(int x);
    operator string();
    bool operator>(const Echipament &obj);
    bool operator==(const Echipament &obj);
    // metode
    void afisare()
    {
        cout << denumire << endl;
        cout << cost << endl;
        cout << criteriu_grad << endl;
        cout << disponibilitate << endl;
    }
};
Producator::Producator(const char *nume, int discuri_platina, bool instrumentist, char grad)
{
    this->nume = new char[strlen(nume) + 1];
    strcpy(this->nume, nume);
    this->discuri_platina = discuri_platina;
    this->instrumentist = instrumentist;
    this->grad = grad;
}
Producator::Producator()
{
    nume = new char[strlen("Unknown") + 1];
    strcpy(nume, "Unknown");
    discuri_platina = 0;
    instrumentist = 0;
    grad = 'Z';
}
Producator::Producator(const Producator &obj)
{
    nume = new char[strlen(obj.nume) + 1];
    strcpy(nume, obj.nume);
    discuri_platina = obj.discuri_platina;
    instrumentist = obj.instrumentist;
    grad = obj.grad;
}
Producator::~Producator()
{
    if (this->nume != NULL)
    {
        delete[] this->nume;
        this->nume = NULL;
    }
}
void Producator::setNume(char *nume)
{
    this->nume = nume;
}
void Producator::setDiscuri_platina(int discuri_platina)
{
    this->discuri_platina = discuri_platina;
}
void Producator::setInstrumentist(bool instrumentist)
{
    this->instrumentist = instrumentist;
}
void Producator::setGrad(char grad)
{
    this->grad = grad;
}
// Overload
ifstream &operator>>(ifstream &in, Producator &obj)
{
    char aux[100];
    in >> aux;
    if (obj.nume != NULL)
    {
        delete[] obj.nume;
        obj.nume = NULL;
    }
    obj.nume = new char[strlen(aux) + 1];
    strcpy(obj.nume, aux);
    in >> obj.discuri_platina;
    in >> obj.grad;
    char x;
    in >> x;
    x == 'y' ? obj.instrumentist = true : obj.instrumentist = false;
    return in;
}
Producator &Producator ::operator=(const Producator &obj)
{
    // self plm
    if (this != &obj)
    {
        if (this->nume != NULL)
        {
            delete[] this->nume;
            this->nume = NULL;
        }
        this->nume = new char[strlen(obj.nume) + 1];
        strcpy(this->nume, obj.nume);
        this->discuri_platina = obj.discuri_platina;
        this->instrumentist = obj.instrumentist;
        this->grad = obj.grad;
    }
    return *this;
}
Producator &Producator::operator++()
{
    discuri_platina++;
    if (grad < 'Z' && grad < 'A')
        grad--;
    return *this;
}
Producator Producator::operator++(int)
{
    Producator temp = *this;
    discuri_platina++;
    if (grad < 'Z' && grad < 'A')
        grad--;
    return temp;
}
int Producator::operator+(int x)
{
    Producator temp = *this;
    if (temp.nivel() == "BUN")
        return x + 1;
    if (temp.nivel() == "SLAB")
        return x - 1;
    if (temp.nivel() == "MEDIU")
        return x;
    return 0;
}
int operator+(int x, Producator &obj)
{
    if (obj.nivel() == "BUN")
        return x + 1;
    if (obj.nivel() == "SLAB")
        return x - 1;
    if (obj.nivel() == "MEDIU")
        return x;
    return 0;
}
Producator Producator::operator+(const Producator &obj)
{
    Producator aux;
    char *temp = new char[strlen(this->nume) + strlen(obj.nume) + 1];
    strcpy(temp, this->nume);
    strcat(temp, obj.nume);
    aux.nume = temp;
    aux.discuri_platina = this->discuri_platina + obj.discuri_platina;
    aux.instrumentist = false;
    if (instrumentist == true)
        aux.instrumentist = true;
    if (obj.instrumentist == true)
        aux.instrumentist = true;
    this->grad > obj.grad ? aux.grad = this->grad : aux.grad = obj.grad;
    return aux;
}
bool Producator::operator==(const Producator &obj)
{
    if (strcmp(nume, obj.nume) == 0 && this->discuri_platina == obj.discuri_platina && this->instrumentist == obj.instrumentist && this->grad == obj.grad)
        return true;
    else
        return false;
}
bool Producator::operator>(const Producator &obj)
{
    if (strcmp(nume, obj.nume) > 1 || discuri_platina > obj.discuri_platina || instrumentist > obj.instrumentist || grad < obj.grad)
        return true;
    else
        return false;
}
ostream &operator<<(ostream &out, const Producator &obj)
{
    out << "---------------------" << endl;
    out << "Informatii Producator:" << endl;
    out << "Nume: " << obj.nume << endl;
    out << "Nr. Discuri de platina: " << obj.discuri_platina << endl;
    out << "Gradul producatorului: " << obj.grad << endl;
    out << "Este instrumentist?: ";
    obj.instrumentist == true ? cout << "Da." : cout << "Nu.";
    out << endl;
    out << "---------------------" << endl;
    out << endl;
    return out;
}
istream &operator>>(istream &in, Producator &obj)
{
    cout << "Completeaza de la tastatura:" << endl;
    cout << "Nume: ";
    char aux[100];
    in >> aux;
    cout << endl;
    if (obj.nume != NULL)
    {
        delete[] obj.nume;
        obj.nume = NULL;
    }
    obj.nume = new char[strlen(aux) + 1];
    strcpy(obj.nume, aux);
    cout << "Nr. Discuri de platina: ";
    in >> obj.discuri_platina;
    cout << endl;
    cout << "Gradul producatorului(A,B,C,D,E,F): ";
    in >> obj.grad;
    cout << endl;
    cout << "Este instrumentist?(y/n): ";
    char x;
    in >> x;
    x == 'y' ? obj.instrumentist = true : obj.instrumentist = false;
    return in;
}
Producator::operator string()
{
    return nume;
}
// methods
string Producator::nivel()
{
    string verdict;
    int gradc = 0;
    switch (this->grad)
    {
    case 'A':
        gradc = 10;
        break;
    case 'B':
        gradc = 8;
        break;
    case 'C':
        gradc = 6;
        break;
    case 'D':
        gradc = 4;
        break;
    case 'E':
        gradc = 2;
        break;
    case 'F':
        gradc = 1;
        break;
    }
    int discuric = 0;
    if (this->discuri_platina > 0)
        discuric = 2;
    if (this->discuri_platina >= 5)
        discuric = 3;
    if (this->discuri_platina >= 10)
        discuric = 5;
    int instrc = 0;
    if (this->instrumentist == true)
        instrc = 5;
    int nota = gradc + discuric + instrc;
    if (nota <= 8)
        verdict = "SLAB";
    if (nota > 8 && nota < 15)
        verdict = "MEDIU";
    if (nota >= 15)
        verdict = "BUN";
    return verdict;
}

// Constructori Artist
Artist::Artist()
{
    nume = new char[strlen("Unknown") + 1];
    strcpy(nume, "Unknown");
    stil_muzical = new char[strlen("Unknown") + 1];
    strcpy(stil_muzical, "Unknown");
    nr_hituri = 0;
    top_hituri = NULL;
}
Artist::Artist(const char *nume, const char *stil_muzical, int nr_hituri, int *top_hituri)
{
    this->nume = new char[strlen(nume) + 1];
    strcpy(this->nume, nume);
    this->stil_muzical = new char[strlen(stil_muzical) + 1];
    strcpy(this->stil_muzical, stil_muzical);
    this->nr_hituri = nr_hituri;
    this->top_hituri = new int[nr_hituri];
    for (int i = 0; i <= nr_hituri; i++)
    {
        this->top_hituri[i] = top_hituri[i];
    }
}
Artist::Artist(const Artist &obj)
{
    nume = new char[strlen(obj.nume) + 1];
    strcpy(nume, obj.nume);
    stil_muzical = new char[strlen(obj.stil_muzical) + 1];
    strcpy(stil_muzical, obj.stil_muzical);
    nr_hituri = obj.nr_hituri;
    if (obj.top_hituri != NULL)
    {
        top_hituri = new int[obj.nr_hituri];
        for (int i = 0; i <= obj.nr_hituri; i++)
        {
            top_hituri[i] = obj.top_hituri[i];
        }
    }
    else
        top_hituri = NULL;
}
Artist::~Artist()
{
    if (this->stil_muzical != NULL)
    {
        delete[] this->stil_muzical;
        this->stil_muzical = NULL;
    }
    if (this->nume != NULL)
    {
        delete[] this->nume;
        this->nume = NULL;
    }
    if (this->top_hituri != NULL)
    {
        delete[] this->top_hituri;
        this->top_hituri = NULL;
    }
}
// Overload Artist
ostream &operator<<(ostream &out, const Artist &obj)
{
    out << "---------------------" << endl;
    out << "Informatii Artist:" << endl;
    out << endl;
    out << "Nume: " << obj.nume << endl;
    out << "Stil Muzical: " << obj.stil_muzical << endl;
    out << "Nr. de Hituri: " << obj.nr_hituri << endl;
    out << "Locurile ocupate in top 100: ";
    for (int i = 0; i < obj.nr_hituri; i++)
    {
        out << obj.top_hituri[i] << " ";
    }
    out << endl;
    out << "---------------------" << endl;

    return out;
}
istream &operator>>(istream &in, Artist &obj)
{
    cout << "Completeaza de la tastatura:" << endl;
    cout << "Nume: ";
    char aux[100];
    in >> aux;
    cout << endl;
    if (obj.nume != NULL)
    {
        delete[] obj.nume;
        obj.nume = NULL;
    }
    obj.nume = new char[strlen(aux) + 1];
    strcpy(obj.nume, aux);
    cout << "Stil Muzical: ";
    char aux2[100];
    in >> aux2;
    cout << endl;
    if (obj.stil_muzical != NULL)
    {
        delete[] obj.stil_muzical;
        obj.stil_muzical = NULL;
    }
    obj.stil_muzical = new char[strlen(aux2) + 1];
    strcpy(obj.stil_muzical, aux2);
    cout << endl;
    cout << "Numar de hituri: ";
    in >> obj.nr_hituri;
    cout << endl;
    cout << "Locul ocupat de hituri: ";
    if (obj.top_hituri != NULL)
    {
        delete[] obj.top_hituri;
        obj.top_hituri = NULL;
    }
    obj.top_hituri = new int[obj.nr_hituri];
    for (int i = 0; i < obj.nr_hituri; i++)
    {
        in >> obj.top_hituri[i];
    }
    return in;
}
ifstream &operator>>(ifstream &in, Artist &obj)
{
    char aux[100];
    in >> aux;
    if (obj.nume != NULL)
    {
        delete[] obj.nume;
        obj.nume = NULL;
    }
    obj.nume = new char[strlen(aux) + 1];
    strcpy(obj.nume, aux);
    char aux2[100];
    in >> aux2;
    if (obj.stil_muzical != NULL)
    {
        delete[] obj.stil_muzical;
        obj.stil_muzical = NULL;
    }
    obj.stil_muzical = new char[strlen(aux2) + 1];
    strcpy(obj.stil_muzical, aux2);
    in >> obj.nr_hituri;
    if (obj.top_hituri != NULL)
    {
        delete[] obj.top_hituri;
        obj.top_hituri = NULL;
    }
    obj.top_hituri = new int[obj.nr_hituri];
    for (int i = 0; i < obj.nr_hituri; i++)
    {
        in >> obj.top_hituri[i];
    }
    return in;
}
Artist &Artist::operator=(const Artist &obj)
{
    if (this != &obj)
    {
        if (this->nume != NULL)
        {
            delete[] this->nume;
            this->nume = NULL;
        }
        this->nume = new char[strlen(obj.nume) + 1];
        strcpy(this->nume, obj.nume);
        if (this->stil_muzical != NULL)
        {
            delete[] this->stil_muzical;
            this->stil_muzical = NULL;
        }
        this->stil_muzical = new char[strlen(obj.stil_muzical) + 1];
        strcpy(this->stil_muzical, obj.stil_muzical);
        nr_hituri = obj.nr_hituri;
        if (obj.top_hituri != NULL)
        {
            top_hituri = new int[obj.nr_hituri];
            for (int i = 0; i <= obj.nr_hituri; i++)
            {
                top_hituri[i] = obj.top_hituri[i];
            }
        }
        else
            top_hituri = NULL;
    }
    return *this;
}
int operator+(Producator &objj, Artist &obj)
{
    int nota;
    string verdictP = objj.nivel();
    string verdictA = obj.nivel();
    if (verdictA == "BUN")
    {
        if (verdictP == "BUN")
            return 10;
        if (verdictP == "MEDIU")
            return 8;
        if (verdictP == "SLAB")
            return 5;
    }
    if (verdictA == "MEDIU")
    {
        if (verdictP == "BUN")
            return 9;
        if (verdictP == "MEDIU")
            return 6;
        if (verdictP == "SLAB")
            return 3;
    }
    if (verdictA == "SLAB")
    {
        if (verdictP == "BUN")
            return 7;
        if (verdictP == "MEDIU")
            return 4;
        if (verdictP == "SLAB")
            return 1;
    }
    return 0;
}
int operator+(Artist &obj, Producator &objj)
{
    int nota;
    string verdictP = objj.nivel();
    string verdictA = obj.nivel();
    if (verdictA == "BUN")
    {
        if (verdictP == "BUN")
            return 10;
        if (verdictP == "MEDIU")
            return 8;
        if (verdictP == "SLAB")
            return 5;
    }
    if (verdictA == "MEDIU")
    {
        if (verdictP == "BUN")
            return 9;
        if (verdictP == "MEDIU")
            return 6;
        if (verdictP == "SLAB")
            return 3;
    }
    if (verdictA == "SLAB")
    {
        if (verdictP == "BUN")
            return 7;
        if (verdictP == "MEDIU")
            return 4;
        if (verdictP == "SLAB")
            return 1;
    }
    return 0;
}
Artist Artist::operator+(const Artist &obj)
{
    Artist aux;
    char *temp = new char[strlen(this->nume) + strlen(obj.nume) + 5];
    strcpy(temp, this->nume);
    strcat(temp, " si ");
    strcat(temp, obj.nume);
    aux.nume = temp;
    char *temp2 = new char[strlen(this->stil_muzical) + strlen(obj.stil_muzical) + 5];
    strcpy(temp2, this->stil_muzical);
    strcat(temp2, " si ");
    strcat(temp2, obj.stil_muzical);
    aux.stil_muzical = temp2;
    aux.nr_hituri = nr_hituri + obj.nr_hituri;
    delete[] aux.top_hituri;
    aux.top_hituri = new int[nr_hituri + obj.nr_hituri];
    for (int i = 0; i < nr_hituri; i++)
    {
        aux.top_hituri[i] = top_hituri[i];
    }
    int j = 0;
    for (int i = nr_hituri; i < nr_hituri + obj.nr_hituri; i++)
    {
        aux.top_hituri[i] = obj.top_hituri[j++];
    }

    return aux;
}
int Artist::operator+(int x)
{
    Artist temp = *this;
    if (temp.nivel() == "BUN")
        return x + 1;
    if (temp.nivel() == "SLAB")
        return x - 1;
    if (temp.nivel() == "MEDIU")
        return x;
        return 0;
}
int operator+(int x, Artist &obj)
{
    if (obj.nivel() == "BUN")
        return x + 1;
    if (obj.nivel() == "SLAB")
        return x - 1;
    if (obj.nivel() == "MEDIU")
        return x;
        return 0;
}
int Artist::operator[](int a)
{
    if (top_hituri == NULL)
        throw runtime_error("nu exista elemente");
    if (a > nr_hituri)
        throw runtime_error("indexul nu este valid");
    else
        return top_hituri[a];
}
/////methods artist
string Artist::nivel()
{
    string verdict;
    int nota = 0;
    if (nr_hituri > 0)
        nota += 3;
    if (nr_hituri > 10)
        nota += 5;
    int med = 0;
    for (int i = 0; i < nr_hituri; i++)
    {
        med += top_hituri[i];
    }
    if(nr_hituri>0)
    med = med / nr_hituri;
    if (med < 20)
        nota += 5;
    else
        nota += 2;
    if (nota == 0)
        verdict = "SLAB";
    if (nota > 0)
        verdict = "MEDIU";
    if (nota >= 5)
        verdict = "BUN";
    return verdict;
}
Sesiune::Sesiune() : nr_sesiune(contor_nr_sesiune++)
{
    ora_incepere = -1;
    durata = -1;
}
Sesiune::Sesiune(float ora_incepere, float durata) : nr_sesiune(contor_nr_sesiune++)
{

    this->ora_incepere = ora_incepere;
    this->durata = durata;
}
Sesiune::Sesiune(const Sesiune &obj) : nr_sesiune(contor_nr_sesiune++)
{
    this->ora_incepere = obj.ora_incepere;
    this->durata = obj.durata;
}
////overlaod sesiune
ostream &operator<<(ostream &out, const Sesiune &obj)
{
    out << "---------------------" << endl;
    out << "Informatii Sesiune: " << endl;
    out << endl;
    out << "Numarul sesiunii: " << obj.nr_sesiune << endl;

    int ore = int(obj.ora_incepere);
    int minute = int(obj.ora_incepere * 100 - ore * 100);
    out << "Ora inceperii sesiunii: " << ore << " si " << minute << " minute" << endl;

    out << "Durata sesiunii(minute): " << obj.durata << endl;
    out << "---------------------" << endl;
    return out;
}
istream &operator>>(istream &in, Sesiune &obj)
{
    cout << "Completeaza de la tastatura:" << endl;
    cout << "Ora Incepere(ex:12.30): ";
    in >> obj.ora_incepere;
    cout << endl;
    if (int(obj.ora_incepere) > 24 || int(obj.ora_incepere) < 0 || (obj.ora_incepere - int(obj.ora_incepere)) >= 0.60)
        throw runtime_error("format ora incorect");
    cout << "Durata: ";
    in >> obj.durata;
    cout << endl;
    return in;
}
ifstream &operator>>(ifstream &in, Sesiune &obj)
{
    in >> obj.ora_incepere;
    // if (int(obj.ora_incepere) > 24 || int(obj.ora_incepere) < 0 || (obj.ora_incepere - int(obj.ora_incepere)) >= 0.60)
    //     throw runtime_error("format ora incorect");
    in >> obj.durata;
    return in;
}
Sesiune operator+(int x, Sesiune &obj)
{
    obj.contor_nr_sesiune--;
    obj.durata += x;
    Sesiune rez(obj);
    return rez;
}
Sesiune operator-(int x, Sesiune &obj)
{
    obj.contor_nr_sesiune--;
    obj.durata = x - obj.durata;
    Sesiune rez = obj;
    return rez;
}
Sesiune &Sesiune::operator+(int x)
{
    contor_nr_sesiune--;
    durata += x;
    return *this;
}
Sesiune &Sesiune::operator-(int x)
{
    contor_nr_sesiune--;
    durata -= x;
    return *this;
}
Sesiune &Sesiune::operator=(const Sesiune &obj)
{
    if (this != &obj)
    {

        ora_incepere = obj.ora_incepere;
        durata = obj.durata;
    }
    return *this;
}
Sesiune &Sesiune::operator++()
{
    // pt ore
    if (ora_incepere == 24)
    {
        ora_incepere = 0;
    }
    else
        ora_incepere++;
    return *this;
}
Sesiune &Sesiune::operator++(int)
{
    // pt minute
    if (ora_incepere * 100 - int(ora_incepere) * 100 == 59)
    {
        ora_incepere = int(ora_incepere);
        ora_incepere++;
    }
    else
        ora_incepere += 0.01;
    return *this;
}
Sesiune &Sesiune::operator--()
{
    // pt ore
    if (ora_incepere == 0)
    {
        ora_incepere = 24;
    }
    else
        ora_incepere--;
    return *this;
}
Sesiune &Sesiune::operator--(int)
{
    // pt minute
    if (ora_incepere * 100 - int(ora_incepere) * 100 == 0)
    {
        ora_incepere -= 1;
        ora_incepere += 0.59;
    }
    else
        ora_incepere -= 0.01;
    return *this;
}

bool Sesiune::operator>(const Sesiune &obj)
{
    if (durata > obj.durata)
        return true;
    return false;
}
bool Sesiune::operator==(const Sesiune &obj)
{
    if (durata == obj.durata)
        return true;
    return false;
}
// methods
Sesiune &Sesiune::extendDuration(int x)
{
    *this + 100;
    return *this;
}
void changeTime(Sesiune &obj, char type, int x)
{
    if (x >= 0)
    {
        if (type == 'm')
        {
            while (x)
            {
                obj++;
                x--;
            }
        }
        if (type == 'h')
        {
            while (x)
            {
                ++obj;
                x--;
            }
        }
    }
    else
    {
        x = -1 * x;
        if (type == 'm')
        {
            while (x)
            {
                obj--;
                x--;
            }
        }
        if (type == 'h')
        {
            while (x)
            {
                --obj;
                x--;
            }
        }
    }
}
Echipament::Echipament()
{
    denumire = new char[strlen("Unknown") + 1];
    strcpy(denumire, "Unknown");
    cost = 0;
    criteriu_grad = 'z';
    disponibilitate = false;
}
Echipament::Echipament(const char *denumire, double cost, char criteriu_grad, bool disponibilitate)
{
    this->denumire = new char[strlen(denumire) + 1];
    strcpy(this->denumire, denumire);
    this->cost = cost;
    this->criteriu_grad = criteriu_grad;
    this->disponibilitate = disponibilitate;
}
Echipament::Echipament(const Echipament &obj)
{
    denumire = new char[strlen(obj.denumire) + 1];
    strcpy(denumire, obj.denumire);
    cost = obj.cost;
    criteriu_grad = obj.criteriu_grad;
    disponibilitate = obj.disponibilitate;
}
Echipament::~Echipament()
{
    if (this->denumire != NULL)
    {
        delete[] this->denumire;
        this->denumire = NULL;
    }
}
// Overload echipament
ostream &operator<<(ostream &out, const Echipament &obj)
{
    out << "---------------------" << endl;
    out << "Informatii Echipament:" << endl;
    out << endl;
    out << "Denumire: " << obj.denumire << endl;
    out << "Cost: " << obj.cost << endl;
    out << "Gradul necesar utilizarii: " << obj.criteriu_grad << endl;
    out << "Este echipamentul disponibil?: ";
    obj.disponibilitate == true ? cout << "Da." << endl : cout << "Nu." << endl;
    out << "---------------------" << endl;
    return out;
}
istream &operator>>(istream &in, Echipament &obj)
{
    cout << "Completeaza de la tastatura:" << endl;
    cout << "Denumire: ";
    char aux[100];
    in >> aux;
    cout << endl;
    if (obj.denumire != NULL)
    {
        delete[] obj.denumire;
        obj.denumire = NULL;
    }
    obj.denumire = new char[strlen(aux) + 1];
    strcpy(obj.denumire, aux);
    cout << "Cost: ";
    in >> obj.cost;
    cout << endl;
    cout << "Gradul necesar utilizarii echipamentului: ";
    in >> obj.criteriu_grad;
    cout << endl;
    cout << "Este disponibil?(y/n): ";
    char x;
    in >> x;
    x == 'y' ? obj.disponibilitate = true : obj.disponibilitate = false;
    return in;
}
ifstream &operator>>(ifstream &in, Echipament &obj)
{
    char aux[100];
    in >> aux;
    if (obj.denumire != NULL)
    {
        delete[] obj.denumire;
        obj.denumire = NULL;
    }
    obj.denumire = new char[strlen(aux) + 1];
    strcpy(obj.denumire, aux);
    in >> obj.cost;
    in >> obj.criteriu_grad;
    char x;
    in >> x;
    x == 'y' ? obj.disponibilitate = true : obj.disponibilitate = false;
    return in;
}
Echipament operator+(int x, const Echipament &obj)
{
    Echipament rez = obj;
    rez.cost += x;
    return rez;
}
Echipament operator-(int x, const Echipament &obj)
{
    Echipament rez = obj;
    rez.cost = x - rez.cost;
    return rez;
}
Echipament &Echipament::operator=(const Echipament &obj)
{
    if (this != &obj)
    {
        if (denumire != NULL)
        {
            delete[] denumire;
            denumire = NULL;
        }
        denumire = new char[strlen(obj.denumire) + 1];
        strcpy(denumire, obj.denumire);
        cost = obj.cost;
        criteriu_grad = obj.criteriu_grad;
        disponibilitate = obj.disponibilitate;
    }
    return *this;
}
Echipament &Echipament::operator++()
{
    if (criteriu_grad <= 'Z' && criteriu_grad > 'A')
        criteriu_grad--;
    return *this;
}
Echipament Echipament::operator++(int)
{
    Echipament rez = *this;
    if (criteriu_grad <= 'Z' && criteriu_grad > 'A')
        criteriu_grad--;
    return rez;
}
Echipament Echipament::operator+(int x)
{
    Echipament rez = *this;
    rez.cost += x;
    return rez;
}
Echipament Echipament::operator-(int x)
{
    Echipament rez = *this;
    rez.cost -= x;
    return rez;
}
Echipament::operator string()
{
    return denumire;
}
bool Echipament::operator>(const Echipament &obj)
{
    if (cost > obj.cost)
        return true;
    else
        return false;
}
bool Echipament::operator==(const Echipament &obj)
{
    if (cost == obj.cost)
        return true;
    else
        return false;
}
int Sesiune::contor_nr_sesiune = 1;
Producator Producatori[100];
int p = 0;
Artist Artisti[100];
int a = 0;
Sesiune Sesiuni[100];
int s = 0;
Echipament Echipamente[100];
int e = 0;

void bd()
{
    while (P >> Producatori[p++])
        ;
    while (A >> Artisti[a++])
        ;
    while (S >> Sesiuni[s++])
        ;
    while (E >> Echipamente[e++])
        ;
    p--;
    a--;
    s--;
    e--;
}
void meniu()
{
    int x = 45;
    // clrscr();
    while (x)
    {
        cout << "_______" << endl;
        cout << "|"
             << "MENIU"
             << "|" << endl;
        cout << "¯¯¯¯¯¯¯" << endl;
        cout << "1.creeaza un obiect" << endl;
        cout << "2.incarca baza de date din fisier" << endl;
        cout << "3.vezi toti Producatorii" << endl;
        cout << "4.vezi toti Artistii" << endl;
        cout << "5.vezi toate sesiunile" << endl;
        cout << "6.vezi toate echipamentele" << endl;
        cout << "FUNCTIONALITATI SPECIALE" << endl;
        cout << "7.schimba ora unei sesiuni" << endl;
        cout << "8.extinde durata unei sesiuni" << endl;
        cout << "9.afisesaza nivelul unui producator" << endl;
        cout << "10.afisesaza nivelul unui artist" << endl;
        cout << "11.formeaza o echipa de producatori si artisti" << endl;
        cout << "12.fa o configuratie" << endl;
        cout << "13.fa o configuratie aleatorie" << endl;
        cout << "14.sugereaza o configuratie optima" << endl;

        cout << "0.iesire" << endl;
        cin >> x;
        switch (x)
        {
        case 1:
        {
            int x1 = 45;

            // clrscr();
            while (x1)
            {
                cout << "_______" << endl;
                cout << "|"
                     << "Creare Obiect"
                     << "|" << endl;
                cout << "¯¯¯¯¯¯¯" << endl;
                cout << "Ce doresti sa creezi:" << endl;
                cout << "1.Producator" << endl;
                cout << "2.Artist" << endl;
                cout << "3.Sesiune" << endl;
                cout << "4.Echipament" << endl;
                cout << "0.exit" << endl;
                cin >> x1;
                while (x1 != 0)
                {
                    switch (x1)
                    {
                    case 1:
                    {
                        cin >> Producatori[p++];
                        cout << "Doresti sa afisezi datele introduse?(y/n)" << endl;
                        char input;
                        cin >> input;

                        if (input == 'y')
                            cout << Producatori[p - 1];
                        input = 'p';
                        cout << "Doresti sa modifici datele introduse?(y/n)" << endl;
                        cin >> input;
                        if (input == 'y')
                            cin >> Producatori[p - 1];
                        input = 'p';
                        cout << "Doresti sa afisezi datele introduse?(y/n)" << endl;
                        cin >> input;
                        if (input == 'y')
                            cout << Producatori[p - 1];
                        x1 = 0;
                    }
                    break;
                    case 2:
                    {
                        cin >> Artisti[a++];
                        cout << "Doresti sa afisezi datele introduse?(y/n)" << endl;
                        char input;
                        cin >> input;
                        if (input == 'y')
                            cout << Artisti[a - 1];
                        input = 'p';
                        cout << "Doresti sa modifici datele introduse?(y/n)" << endl;
                        cin >> input;
                        if (input == 'y')
                            cin >> Artisti[a - 1];
                        input = 'p';
                        cout << "Doresti sa afisezi datele introduse?(y/n)" << endl;
                        cin >> input;
                        if (input == 'y')
                            cout << Artisti[a - 1];
                        x1 = 0;
                    }
                    break;
                    case 3:
                    {
                        cin >> Sesiuni[s++];
                        cout << "Doresti sa afisezi datele introduse?(y/n)" << endl;
                        char input;
                        cin >> input;
                        if (input == 'y')
                            cout << Sesiuni[s - 1];
                        input = 'p';
                        cout << "Doresti sa modifici datele introduse?(y/n)" << endl;
                        cin >> input;
                        if (input == 'y')
                            cin >> Sesiuni[s - 1];
                        input = 'p';
                        cout << "Doresti sa afisezi datele introduse?(y/n)" << endl;
                        cin >> input;
                        if (input == 'y')
                            cout << Sesiuni[s - 1];
                        x1 = 0;
                    }
                    break;
                    case 4:
                    {
                        cin >> Echipamente[e++];
                        cout << "Doresti sa afisezi datele introduse?(y/n)" << endl;
                        char input;
                        cin >> input;
                        if (input == 'y')
                            cout << Echipamente[e - 1];
                        input = 'p';
                        cout << "Doresti sa modifici datele introduse?(y/n)" << endl;
                        cin >> input;
                        if (input == 'y')
                            cin >> Echipamente[e - 1];
                        input = 'p';
                        cout << "Doresti sa afisezi datele introduse?(y/n)" << endl;
                        cin >> input;
                        if (input == 'y')
                            cout << Echipamente[e - 1];
                        x1 = 0;
                    }
                    break;
                    case 0:
                    {
                        x1 = 0;
                    }
                    break;
                    }
                }
            }
        }
        break;
        case 2:
        {
            bd();
            cout << "Baza de date incarcata" << endl;
        }
        break;
        case 3:
        {
            if (p == 0)
                cout << "inca nu exista producatori" << endl;
            else
            {
                for (int i = 0; i < p; i++)
                {

                    cout << "producatorul " << i << endl;
                    cout << Producatori[i];
                }
                cout << "Vrei sa modifici un producator?(y/n)" << endl;
                char inp;
                cin >> inp;
                if (inp == 'y')
                {
                    int ip;
                    cout << "introdu numarul corespunzator modificarii: ";
                    cin >> ip;
                    cin >> Producatori[ip];
                }
                inp = 'p';
                cout << "Vrei sa stergi un producator?(y/n)" << endl;
                cin >> inp;
                if (inp == 'y')
                {
                    int ip;
                    cout << "introdu numarul corespunzator modificarii: ";
                    cin >> ip;
                    for (int i = ip; i <= p; i++)
                    {
                        Producatori[i] = Producatori[i + 1];
                    }
                    p--;
                }
            }
        }
        break;
        case 4:
        {
            if (a == 0)
                cout << "inca nu exista artisti" << endl;
            else
            {
                for (int i = 0; i < a; i++)
                {

                    cout << "Artistul " << i << endl;
                    cout << Artisti[i];
                }
                cout << "Vrei sa modifici un artist?(y/n)" << endl;
                char inp;
                cin >> inp;
                if (inp == 'y')
                {
                    int ip;
                    cout << "introdu numarul corespunzator modificarii: ";
                    cin >> ip;
                    cin >> Artisti[ip];
                }
                inp = 'p';
                cout << "Vrei sa stergi un artist?(y/n)" << endl;
                cin >> inp;
                if (inp == 'y')
                {
                    int ip;
                    cout << "introdu numarul corespunzator modificarii: ";
                    cin >> ip;
                    for (int i = ip; i <= a; i++)
                    {
                        Artisti[i] = Artisti[i + 1];
                    }
                    a--;
                }
            }
        }
        break;
        case 5:
        {
            if (s == 0)
                cout << "inca nu exista sesiuni" << endl;
            else
            {
                for (int i = 0; i < s; i++)
                {

                    cout << "Sesiunea " << i << endl;
                    cout << Sesiuni[i];
                }
                cout << "Vrei sa modifici o sesiune?(y/n)" << endl;
                char inp;
                cin >> inp;
                if (inp == 'y')
                {
                    int ip;
                    cout << "introdu numarul corespunzator modificarii: ";
                    cin >> ip;
                    cin >> Sesiuni[ip];
                }
                inp = 'p';
                cout << "Vrei sa stergi o sesiune?(y/n)" << endl;
                cin >> inp;
                if (inp == 'y')
                {
                    int ip;
                    cout << "introdu numarul corespunzator modificarii: ";
                    cin >> ip;
                    for (int i = ip; i <= s; i++)
                    {
                        Sesiuni[i] = Sesiuni[i + 1];
                    }
                }
                s--;
            }
        }
        break;
        case 6:
        {
            if (e == 0)
                cout << "inca nu exista echipamente" << endl;
            else
            {
                for (int i = 0; i < e; i++)
                {

                    cout << "Echipamnetul " << i << endl;
                    cout << Echipamente[i];
                }
                cout << "Vrei sa modifici un echipament?(y/n)" << endl;
                char inp;
                cin >> inp;
                if (inp == 'y')
                {
                    int ip;
                    cout << "introdu numarul corespunzator modificarii: ";
                    cin >> ip;
                    cin >> Echipamente[ip];
                }
                inp = 'p';
                cout << "Vrei sa stergi un echipament?(y/n)" << endl;
                cin >> inp;
                if (inp == 'y')
                {
                    int ip;
                    cout << "introdu numarul corespunzator modificarii: ";
                    cin >> ip;
                    for (int i = ip; i <= e; i++)
                    {
                        Echipamente[i] = Echipamente[i + 1];
                    }
                }
                e--;
            }
        }
        break;
        case 7:
        {
            int ip;
            cout << "introdu numarul corespunzator modificarii: ";
            cin >> ip;
            cout<<"obiectul selectat: "<<endl;
            cout<<Sesiuni[ip];
            char type;
            int amount;
            cout<<"introdu tipul (h-ore/m-minute) si valoarea cu care vrei sa schimbi, foloseste nr pozitive daca vrei sa aduni sau negative altfel"<<endl;
            cin>>type;
            cin>>amount;
            changeTime(Sesiuni[ip],type,amount);
            cout<<Sesiuni[ip];

        }
        break;
        case 8:
        {
            int ip;
            cout << "introdu numarul corespunzator modificarii: ";
            cin >> ip;
            cout<<"obiectul selectat: "<<endl;
            cout<<Sesiuni[ip];
            int amount;
            cout<<"introdu nr de minute cu care vrei sa extinzi durata"<<endl;
            cin>>amount;
            Sesiuni[ip].extendDuration(amount);
            cout<<Sesiuni[ip];

        }
        break;
        case 9:
        {
            int ip;
            cout << "introdu numarul corespunzator producatorului: ";
            cin >> ip;
            cout<<"obiectul selectat: "<<endl;
            cout<<Producatori[ip];
            cout<<"Nivelul actual al producatorului, aflat cu ajutorul algoritmilor specializati este: "<<endl;
            cout<<Producatori[ip].nivel()<<endl;

        }
        break;
        case 10:
        {
            int ip;
            cout << "introdu numarul corespunzator artistului: ";
            cin >> ip;
            cout<<"obiectul selectat: "<<endl;
            cout<<Artisti[ip];
            cout<<"Nivelul actual al artistului, aflat cu ajutorul algoritmilor specializati este: "<<endl;
            cout<<Artisti[ip].nivel()<<endl;
        }
        break;
        case 11:
        {
            int ip;
            cout <<"introdu numarul corespunzator de perechi: ";
            cin >> ip;
            int s;
            while(ip){
            int ind;
                cout<<"introdu indexul artistului"<<endl; 
                cin>>ind;
                s=s+Artisti[ind];
                cout<<"introdu indexul producatorului"<<endl; 
                cin>>ind;
                s=s+Producatori[ind];
                ip--;
            }
            int a = (s / 10) * 10;
            int b = a + 10;
            int rez;
            (s - a > b - s)? rez=b : rez=a;
            float n=(s*100)/rez;
            cout<<"Nota finala a combinatiei este: "<<n<<"/100"<<endl;

        }
        break;
        case 12:
        {
            Producator Producatorii[100];
            Artist Artistii[100];
            Echipament Echipamentee[100];
                        int ip1;
                        int ip2;
                        int ip3;
                        int ip4;
            cout <<"introdu numarul corespunzator de producatori: ";
            cin >> ip1;
            cout <<"introdu numarul corespunzator de artisti: ";
            cin >> ip2;
            cout <<"introdu numarul corespunzator de echipamente: ";
            cin >> ip4;
            cout <<"introdu sesiunea: ";
            cin >> ip3;
            int inde;
            cout<<"introdu indexul pentru fiecare producator"<<endl;
            for (int i = 0; i < ip1; i++)
            {
                cin>>inde;
                Producatorii[i]=Producatori[inde];
            }
            cout<<"introdu indexul pentru fiecare artist"<<endl;
            for (int i = 0; i < ip2; i++)
            {
                cin>>inde;
                Artistii[i]=Artisti[inde];
            }
            cout<<"introdu indexul pentru fiecare echipament"<<endl;
            for (int i = 0; i < ip3; i++)
            {
                cin>>inde;
                Echipamentee[i]=Echipamente[inde];
            }
            cout<<"configuratia are urmatoare formula: "<<endl;
            cout<<"Producatorii:"<<endl;
            for (int i = 0; i < ip1; i++)
            {
                cout<<Producatorii[i];
            }
            cout<<"Artistii:"<<endl;
            for (int i = 0; i < ip2; i++)
            {
                cout<<Artistii[i];
            }
            cout<<"Echipamentele:"<<endl;
            for (int i = 0; i < ip3; i++)
            {
                cout<<Echipamentee[i];
            }
            cout<<"Se vor desfasura in "<<endl;
            cout<<Sesiuni[ip3];
            
        }
        break;
        case 0:
            x = 0;
            break;
        }
    }
}

int main()
{
    // bd();

    meniu();
}
