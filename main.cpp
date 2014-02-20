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
    Animal *inicio;
    Animal *sig;

    Lista ()
    {
        this->inicio=NULL;
        this->sig=NULL;
    }

    void agregarAnimal(Animal* animal)
    {
        if (inicio==NULL)
        {
            inicio=animal;
        }else{

        Animal *temp;
        for(temp = inicio; temp->sig!=NULL; temp = temp->sig);
            temp->sig = animal;
        }
    }

    void guardarAnimales(char* path)
    {
       if(inicio == NULL)
            return;

        ofstream out(path);
        Animal* temp;

        for(temp = inicio; temp != NULL; temp = temp->sig)
        {
            out<<temp->getTipo()<<" ";
            out<<temp->getNombre()<<endl;
        }
        out.close();
    }

    void leerAnimales(char* path)
    {
        ifstream in(path);

        string str;
        string typ;
        while (in>>typ && in>>str)
        {
            cout<<typ<<" "<<str<<endl;
        }

        in.close();
    }

    void ordenar ()
    {

    }

    void borrarAnimal(string nombre)
    {
        if (inicio == NULL)
            return;

        Animal* temp;
        if (inicio->nombre==nombre)
        {
            temp=inicio->sig;
            delete inicio;
            inicio=temp;
            return;
        }

        for (temp=inicio; temp->sig!=NULL; temp=temp->sig)
        {
            Animal* temp2;
            if (temp->sig->nombre==nombre)
            {
                temp2=temp->sig->sig;

                delete temp->sig;
                temp->sig=temp2;
                return ;
            }
        }
    }
};

int main()
{
    Lista l;
    l.agregarAnimal(new Gato("ny"));
    l.agregarAnimal(new Gato("Nye"));
    l.agregarAnimal(new Perro("Woof"));
    l.agregarAnimal(new Lora("Poly"));

    l.guardarAnimales("animales.txt");
    l.leerAnimales("animales.txt");
    return 0;
}
