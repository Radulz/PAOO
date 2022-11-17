#include <iostream>

using namespace std;

class Tren
{
private:
    string id;
    string marca;
    int cmc; // cubic capacity
    int nrVagoane;
    int putere; // in horsepower

public:
    Tren(string ID, string make, int cubicCapacity, int carriages, int power) : id(ID), marca(make), cmc(cubicCapacity), nrVagoane(carriages), putere(power) {} // constructor
    // copy constructor
    Tren(const Tren &t)
    {
        this->id = t.id;
        this->marca = t.marca;
        this->cmc = t.cmc;
        this->nrVagoane = t.nrVagoane;
        this->putere = t.putere;
    }
    ~Tren() {} // destructor
    void toString()
    {
        cout << "ID: " << id << ", Marca: " << marca << ", Cilindree: " << cmc << ", Vagoane: " << nrVagoane << ", Putere(CP): " << putere << endl;
    }
    Tren &operator=(const Tren &t)
    {
        if (this != &t)
        {
            this->id = t.id;
            this->marca = t.marca;
            this->cmc = t.cmc;
            this->nrVagoane = t.nrVagoane;
            this->putere = t.putere;
        }
        return *this;
    }
#pragma region getters
    string getId()
    {
        return this->id;
    }
    string getMarca()
    {
        return this->marca;
    }
    int getCmc()
    {
        return this->cmc;
    }
    int getNrVagoane()
    {
        return this->nrVagoane;
    }
    int getPutere()
    {
        return this->putere;
    }
#pragma endregion
};

class Masina
{
private:
    string regPlate;
    string marca;
    int cmc;
    int putere;
    int nrUsi;
    int nrPasageri;

public:
    Masina(string plate, string make, int cubicCapacity, int power, int doors, int passengers) : regPlate(plate), marca(make), cmc(cubicCapacity), putere(power), nrUsi(doors), nrPasageri(passengers) {}
    Masina(const Masina &m)
    {
        this->regPlate = m.regPlate;
        this->marca = m.marca;
        this->putere = m.putere;
        this->cmc = m.cmc;
        this->nrPasageri = m.nrPasageri;
        this->nrUsi = m.nrUsi;
    }
    ~Masina() {}
    void toString()
    {
        cout << "Placuta inmatriculare: " << regPlate << ", Marca: " << marca << ", Cilindree: " << cmc << ", Nr. Usi: " << nrUsi << ", Nr. Locuri: " << nrPasageri << ", Putere(CP): " << putere << endl;
    }
    Masina &operator=(const Masina &m)
    {
        if (this != &m)
        {
            this->regPlate = m.regPlate;
            this->marca = m.marca;
            this->putere = m.putere;
            this->cmc = m.cmc;
            this->nrPasageri = m.nrPasageri;
            this->nrUsi = m.nrUsi;
        }
        return *this;
    }
#pragma region getters
    string getRegPlate()
    {
        return this->regPlate;
    }
    string getMarca()
    {
        return this->marca;
    }
    int getCmc()
    {
        return this->cmc;
    }
    int getNrUsi()
    {
        return this->nrUsi;
    }
    int getNrPasageri()
    {
        return this->nrPasageri;
    }
    int getPutere()
    {
        return this->putere;
    }
#pragma endregion
};

class Camion
{
private:
    string regPlate;
    string marca;
    int cmc;
    int putere;
    bool remorca;

public:
    Camion(string plate, string make, int cubicCapacity, int power, bool trailer) : regPlate(plate), marca(make), cmc(cubicCapacity), putere(power), remorca(trailer) {}
    Camion(Camion &c)
    {
        this->regPlate = c.regPlate;
        this->marca = c.marca;
        this->cmc = c.cmc;
        this->putere = c.putere;
        this->remorca = c.remorca;
    }
    ~Camion() {}
    Camion &operator=(const Camion &c)
    {
        if (this != &c)
        {
            this->regPlate = c.regPlate;
            this->marca = c.marca;
            this->putere = c.putere;
            this->cmc = c.cmc;
            this->remorca = c.remorca;
        }
        return *this;
    }
    void toString()
    {
        cout << "Placuta inmatriculare: " << regPlate << ", Marca: " << marca << ", Cilindree: " << cmc << ", Putere(CP): " << putere;
        this->remorca ? cout << ", Remorca: Da" << endl : cout << ", Remorca: Nu" << endl;
    }
#pragma region getters
    string getRegPlate()
    {
        return this->regPlate;
    }
    string getMarca()
    {
        return this->marca;
    }
    int getCmc()
    {
        return this->cmc;
    }
    int getPutere()
    {
        return this->putere;
    }
    bool getRemorca()
    {
        return this->remorca;
    }
#pragma endregion
};
// for item 5
class Bicicleta
{
};

// for item 6
class Uncopyable
{
protected:           // allow construction
    Uncopyable() {}  // and destruction of
    ~Uncopyable() {} // derived objects...
private:
    Uncopyable(const Uncopyable &); // ...but prevent copying
    Uncopyable &operator=(const Uncopyable &);
};

class Avion : private Uncopyable
{
private:
    string Id;
    string Model;

public:
    Avion(string id, string model) : Id(id), Model(model) {}
    void toString()
    {
        cout << "Avion " << Model << " cu id-ul: " << Id << "\n";
    }
};

int main(int, char **)
{
    // item 4
    Tren t1("1611.1", "Malaxa", 200000, 5, 4500);
    Tren t2(t1);
    t1.toString();
    t2.toString();
    cout << endl;

    Masina m1("TM18UPT", "BMW", 2000, 184, 4, 5);
    Masina m2(m1);
    Masina m3("AR19UPT", "Audi", 3000, 300, 4, 5);
    m1.toString();
    m2.toString();
    m3.toString();
    cout << endl;
    m2 = m3;
    m2.toString();
    cout << endl;

    Camion c1("AR11CCC", "Volvo", 13400, 500, false);
    Camion c2("AR22LLL", "Scania", 16400, 730, true);
    Camion c3(c2);

    c1.toString();
    c2.toString();
    c3.toString();
    cout << endl;

    c3 = c1;
    c3.toString();

    // item 5
    Bicicleta b1;    // clasa Bicicleta nu are un constructor explicit definit, asadar c++ apeleaza constructoru standard
    b1.~Bicicleta(); // destructorul a fost creat automat de catre compilator

    // item 6
    Avion a1("id1", "Boeing");
    a1.toString();
    // Avion a2(a1);  // eroare, copy constructorul clasei avion este private
    // Avion a3 = a1; // eroare, operatorul de atribuire al clasei avion este private
    return 0;
}
