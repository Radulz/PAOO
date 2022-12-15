#include <iostream>
#include <memory>
#include <string>

using namespace std;

// item 13
class Car
{
public:
    Car(shared_ptr<string> sound) : revingSound(sound) {} // the constructor takes ownership of the string

    void revEngine() // method which uses the string resource
    {
        cout << *revingSound << endl;
    }

private:
    shared_ptr<string> revingSound;
};

class Plane
{
public:
    Plane(auto_ptr<string> sound) : takeOffSound(sound) {}

    void takeOff()
    {
        cout << *takeOffSound << endl;
    }

private:
    auto_ptr<string> takeOffSound;
};

// item 14

template <typename T>
class Engine
{
public:
    Engine(T *ptr) : p(ptr), engineCount(new int(1)) {}

    Engine(const Engine &other) : p(other.p), engineCount(other.engineCount)
    {
        ++(*engineCount);
    }

    Engine &operator=(const Engine &other)
    {
        if (this != &other)
        {

            // decrement the counter of the engine
            if (--(*engineCount) == 0)
            {
                delete p;
                delete engineCount;
            }

            p = other.p;
            engineCount = other.engineCount;

            // increment the counter of the engine
            ++(*engineCount);
        }
        return *this;
    }

    ~Engine()
    {
        if (--(*engineCount) == 0)
        {
            delete p;
            delete engineCount;
        }
    }

#pragma region getters
    T *get()
    {
        return p;
    }

    int *getEngineCount()
    {
        return engineCount;
    }
#pragma endregion

private:
    T *p;
    int *engineCount;
};

int main(int, char **)
{
    // create a string resource that is shared by multiple cars
    shared_ptr<string> sharedEngineSound(new string("ratatata"));

    Car inLine6CylSupra(sharedEngineSound);
    Car inLine6CylGTR(sharedEngineSound);

    // rev the engines
    inLine6CylGTR.revEngine();
    inLine6CylSupra.revEngine();

    // the sound (string) is automatically freed, when these cars (objects) go out of use

    auto_ptr<string> boeingTakeOffSound(new string("*high pitch noise*"));

    Plane boeing(boeingTakeOffSound);

    // take off
    boeing.takeOff();

    // the string will be automatically freed

    Engine<string> engine(new string("Engine Sound"));

    // using the assignment operator
    Engine<string> engine2 = engine;

    // using the copy constructor
    Engine<string> engine3(engine);

    engine = engine3;

    cout << *(engine.get()) << endl;
    cout << *(engine.getEngineCount()) << endl;

    return 0;
}
