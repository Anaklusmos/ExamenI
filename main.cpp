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
    Gato (string nombre)
    {
        this->nombre=nombre;
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
    Perro (string nombre)
    {
        this->nombre=nombre;
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
    Lora (string nombre)
    {
        this->nombre=nombre;
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

class Lista
{
public:
    Animal*inicio;
    Animal*sig;

    Lista ()
    {
        this->inicio=NULL;
        this->sig=NULL;
    }

    void agregarAnimal(Animal*animal)
    {
        if (inicio==NULL)
        {
            inicio=animal;
            return ;
        }

        Animal*temp;
        for (temp=inicio; temp->sig!=NULL; temp=temp->sig);
                        temp->sig=animal;
    }

    void guardarAnimales (char* path)
    {
        Animal*temp;

        ofstream out (path);
        for (temp=inicio; temp->sig!=NULL; temp=temp->sig)
        {
            out<<temp->sig->getTipo()<<" "<<temp->sig->getNombre()<<endl;
        }
        out.close();
    }

    void leerAnimales(char* path)
    {
        ifstream in(path);

        string str;
        while (in>>str)
        {
            cout<<str<<endl;
        }

        in.close();
    }

    void ordenar ()
    {

    }

    void borrarAnimal(string nombre)
    {

    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
