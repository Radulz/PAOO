#include <iostream>
#include <Windows.h>

using namespace std;

class Vehicul
{
private:
    string regPlate;
    string marca;
    int cmc;
    int putere;

public:
    Vehicul(string plate, string make, int cubicCapacity, int power) : regPlate(plate), marca(make), cmc(cubicCapacity), putere(power) {}

    Vehicul(const Vehicul &v)
    {
        this->regPlate = v.regPlate;
        this->marca = v.marca;
        this->putere = v.putere;
        this->cmc = v.cmc;
    }

    ~Vehicul() {}

    void toString()
    {
        cout << "Placuta inmatriculare: " << regPlate << ", Marca: " << marca << ", Cilindree: " << cmc << ", Putere(CP): " << putere;
    }

    Vehicul &operator=(const Vehicul &v)
    {
        if (this != &v) // item 11
        {
            this->regPlate = v.regPlate;
            this->marca = v.marca;
            this->putere = v.putere;
            this->cmc = v.cmc;
        }
        return *this; // item 10
    }

protected:
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
#pragma endregion
};

class Masina : public Vehicul
{
private:
    int nrUsi;
    int nrPasageri;

public:
    Masina(string plate, string make, int cubicCapacity, int power, int doors, int passengers) : Vehicul(plate, make, cubicCapacity, power), nrUsi(doors), nrPasageri(passengers) {}

    Masina(Masina &m) : Vehicul(m)
    {
        this->nrPasageri = m.nrPasageri;
        this->nrUsi = m.nrUsi;
    }

    ~Masina() {}

    void toString()
    {
        Vehicul::toString();
        cout << ", Nr. Usi: " << nrUsi << ", Nr. Locuri: " << nrPasageri << endl;
    }

    Masina &operator=(const Masina &m)
    {
        if (this != &m) // item 11
        {
            Vehicul::operator=(m);
            this->nrPasageri = m.nrPasageri;
            this->nrUsi = m.nrUsi;
        }
        return *this; // item 10
    }
#pragma region getters

    int getNrUsi()
    {
        return this->nrUsi;
    }
    int getNrPasageri()
    {
        return this->nrPasageri;
    }

#pragma endregion
};

class Camion : public Vehicul
{
private:
    bool remorca;

public:
    Camion(string plate, string make, int cubicCapacity, int power, bool trailer) : Vehicul(plate, make, cubicCapacity, power), remorca(trailer) {}

    Camion(Camion &c) : Vehicul(c)
    {
        this->remorca = c.remorca;
    }

    ~Camion() {}

    Camion &operator=(const Camion &c)
    {
        if (this != &c) // item 11
        {
            Vehicul::operator=(c);
            this->remorca = c.remorca;
        }
        return *this; // item 10
    }

    void toString()
    {
        Vehicul::toString();
        this->remorca ? cout << ", Remorca: Da" << endl : cout << ", Remorca: Nu" << endl;
    }
#pragma region getters
    bool getRemorca()
    {
        return this->remorca;
    }
#pragma endregion
};

int main(int, char **)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 7); // set the color to white

    Camion c1("AR11CPP", "Volvo", 13400, 500, false);
    Camion c2("AR22CSC", "Scania", 16400, 730, true);
    Camion c3(c2); // using the copy constructor

    c1.toString();
    c2.toString();
    cout << endl;

    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    cout << "Before using the assignment operator:" << endl;
    c3.toString();
    cout << endl;

    c3 = c1; // using the assignment operator, item 12
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
    cout << "After the use of assignment operator" << endl;
    c3.toString();
    cout << endl;

    Masina m1("TM18UPT", "BMW", 2000, 184, 4, 5);
    Masina m2(m1); // using the copy constructor
    Masina m3("AR19UPT", "Audi", 3000, 300, 5, 4);

    SetConsoleTextAttribute(hConsole, 7); //reset the color back to white
    m1.toString();
    m3.toString();
    cout << endl;

    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    cout << "Before using the assignment operator:" << endl;
    m2.toString();
    cout << endl;

    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
    m2 = m3; // using the assignment operator, item 12
    cout << "After the use of assignment operator" << endl;
    m2.toString();
    cout << endl;
    SetConsoleTextAttribute(hConsole, 7); //reset the color back to white
    return 0;
}
