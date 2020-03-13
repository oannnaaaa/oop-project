#include <iostream>

using namespace std;


class nod
{
private:
    char info;
    nod* next;
    friend class Coada_de_caractere;
}

class Coada_de_caractere
{
private:
    nod*;
    nod**;


public:
    //constructor de initializare a cozii cu NULL
    Coada();

    //destructor care dezaloca toate elementele cozii
     ~Coada();
    // metoda de agaugare a unui element in stiva (push)

    //met de stergere a unui elemet (pop)

    //met de a testa daca coada e goala
    bool isEmpty() const;

    //met de fisare a cozii concomitent cu golirea ei prin supraincarcarea operatorului <<

    //supraincarcarea operatorului >> realizata orin oush-uri succesive

    //met de concatenare a doua cozi , prin supraincarcarea operatorului +

    //met supraincarere -- ,care sa elimine concomintent elemente din ambele cozi , adaugand in a 3a coada caracterul care are codul ascii mai mare



}

    Coada()::Coada()
    {
        nod* = nod** = nullptr; //Coada vida
        count = 0; // niciun element
    }

int main()
{

    cout << "Hello world!" << endl;
    return 0;
}
