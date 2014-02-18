#include <iostream>
#include <fstream>

using namespace std;

class Animal
{
public:
    string nombre;
    Animal* sig;

    Animal()
    {
    }

    Animal(string nombre)
    {
        this->nombre=nombre;
        sig=NULL;
    }

    virtual void rugir()=0;

    virtual bool esFelino()
    {
        return false;
    }
    void setNombre(string nombre)
    {
        this->nombre=nombre;
    }

    string getNombre()
    {
            return nombre;
    }

    string getTipo()
    {
        return "Animal";
    }
};

class Gato : public Animal
{
public:
    Gato (string nombr)
    {
        nombre=nombr;
    }

    void rugir()
    {
        cout<<"miau"<<endl;
    }

    bool esFelino()
    {
        return true;
    }

    string getTipo()
    {
        return "Gato";
    }
};

class Perro : public Animal
{
public:
    Perro (string nombr)
    {
        nombre=nombr;
    }

    void rugir ()
    {
        cout<<"guau"<<endl;
    }

    bool esFelino()
    {
        return false;
    }

    string getTipo()
    {
        return "Perro";
    }
};

class Lora : public Animal
{
public:
    Lora (string nombr)
    {
        nombre=nombr;
    }

    void rugir ()
    {
        cout<<"Hola"<<endl;
    }

    bool esFelino()
    {
        return false;
    }

    string getTipo()
    {
        return "Lora";
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
