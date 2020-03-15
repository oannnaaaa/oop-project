#include <iostream>
#include <bits/stdc++.h>
#include <cstddef>


using namespace std;

class Coada_de_caractere;

class Nod
{

    char info;
    Nod* next;


    public:
    Nod(); //constructor implicit
    Nod(char info, Nod* next=0); //constructor parametrizat

    char getInfo()
        {return info;}


    Nod* getNext()
        {return next;}


    void setInfo(char info)
        {this->info = info;}

    void setNext(Nod* next)
        {this->next = next;}


    ~Nod() //destructor
    {
        info = '\0';
        next = NULL;
        //cout<<"Destructorul a fost apelat.";
    }

    friend class Coada_de_caractere;
};

Nod::Nod()
{
    next=0;
}

 Nod::Nod(char info, Nod* next){
    this->info=info;
    this->next=next;
    }

class Coada_de_caractere
{

   Nod *prim;
   Nod *ultim;

public:

    //functie de citire
    void citire(Coada_de_caractere &);
    void afisare(Coada_de_caractere &);

    //constructor de initializare a cozii cu NULL
    Coada_de_caractere();

    //destructor care dezaloca toate elementele cozii
     ~Coada_de_caractere();

    // metoda de agaugare a unui element in stiva (push)
    void push(Nod x);

    //met de stergere a unui elemet (pop)
    void pop();

    //met de a testa daca coada e goala
    bool isEmpty();

    //met pentru a obtine primul element din coada
    Nod* getFirst();

    //met de fisare a cozii concomitent cu golirea ei prin supraincarcarea operatorului <<
    friend ostream& operator<<(ostream& afiseaza, Coada_de_caractere&);

    //supraincarcarea operatorului >> realizata orin oush-uri succesive
    friend istream& operator>>(istream& scrie, Coada_de_caractere&);

    //met de concatenare a doua cozi , prin supraincarcarea operatorului +
    //friend Coada_de_caractere operator+(Coada_de_caractere &, Coada_de_caractere &);
    //nu am reusit sa o fac sa mearga :(

    //met supraincarere -- ,care sa elimine concomintent elemente din ambele cozi , adaugand in a 3a coada caracterul care are codul ascii mai mare
    //friend Coada_de_caractere operator-(Coada_de_caractere &, Coada_de_caractere &);
    //nu am reusit sa o fac sa mearga :(
};

Coada_de_caractere::Coada_de_caractere()
    {
        prim=NULL;
        ultim=NULL;
    }

Coada_de_caractere::~Coada_de_caractere()
{
    Nod *p = prim;
    Nod *q;

    //eliberam memoria rezervata elementelor listei
    while (p!=0)
    {
        q = p;
        p = p->getNext();
        delete q;
    }

    prim = ultim = NULL;
}

bool Coada_de_caractere::isEmpty()
{
    return prim == NULL;
}

Nod* Coada_de_caractere::getFirst()
{
    return prim;
}

void Coada_de_caractere::push(Nod x)
{
    Nod *p = new Nod(x.info,0);

    if (isEmpty())
        prim  = ultim = p;
    else
    {
        ultim->next = p;
        ultim = p;
    }

}

void Coada_de_caractere::pop()
{
    if (isEmpty())
        return ;
    else
    {
        prim = prim ->next;
    }
}


ostream& operator<< (ostream& afiseaza, Coada_de_caractere& coada)
{
    Nod* p = new Nod;
    p = coada.getFirst();

    afiseaza << "(sfarsit coada) ";
    while (p != NULL)
        {
            afiseaza << p->getInfo();

            if (p->getNext() == NULL)
                afiseaza<<". ";
            else
                afiseaza<<"-";

                p = p->getNext();
        }

     afiseaza <<" (inceput coada)\n";

    p = coada.getFirst();
    Nod *q;

    //golim coada
    while (p!=NULL)
    {
        q = p;
        p = p->getNext();
        delete q;
    }

        return afiseaza;
}


istream& operator>>(istream& scrie, Coada_de_caractere& coada)
{
     Nod temp;
     char val;

     while (val != '0')
     {
     scrie >> val;

     if (val == '0') // introducerea valorii 0 inseamna ca am terminat de citit coada
            return scrie;

     temp.setInfo(val);
     coada.push(temp);
     }

    return scrie;
}

/*
Coada_de_caractere operator+(Coada_de_caractere &coada1, Coada_de_caractere &coada2)
{

    Coada_de_caractere *coada = new Coada_de_caractere;
    Nod *temp1 = coada1->getFirst();
    Nod *temp2 = coada2->getFirst();


    while (temp1!= NULL)
    {
        coada.push(*temp1);
        temp1 = temp1->getNext();
    }


    while(temp2 != NULL)
    {
        coada.push(*temp2);
        temp2 = temp2->getNext();
    }

    return *coada;

}
*/
/*
Coada_de_caractere operator-(Coada_de_caractere &coada1, Coada_de_caractere &coada2)
{

    Coada_de_caractere *coada = new Coada_de_caractere;
    Nod *temp1 = coada1->getFirst();
    Nod *temp2 = coada2->getFirst();


    while (temp1!= NULL && temp2 != NULL)
    {
        if (temp1.getInfo()  >= temp2.getInfo())
        coada->push(*temp1);
        else
        coada->push(*temp2);

        temp1 = temp1->getNext();
        temp2 = temp2->getNext();
    }

    return *coada;

}
*/

void Coada_de_caractere::afisare(Coada_de_caractere &coada)
{
    Nod* p = new Nod;
    p = coada.getFirst();

    cout << "(sfarsit coada) ";
    while (p != NULL)
        {
            cout << p->getInfo();

            if (p->getNext() == NULL)
                cout<<". ";
            else
                cout<<"-";

                p = p->getNext();
        }

     cout <<" (inceput coada)\n";
}

void Coada_de_caractere::citire(Coada_de_caractere &coada1)
{
    cout<<"Introduceti valorile care vor fi in coada. (valoarea 0 semnifica sfarsitul listei)\n";
    cin>>coada1;
    cout<<"Coada arata in felul urmator:\n";
    coada1.afisare(coada1);
}

int main()
{
    Coada_de_caractere coada1;

    coada1.citire(coada1);

    char ch;

         do
         {

        cout<<"\n---Meniu---\n";
        cout<<"Optiunea 0: opriti programul.\n";
        cout<<"Optiunea 1: adaugati o valoare din coada.\n";
        cout<<"Optiunea 2: stergeti o valoare din coada.\n";
        cout<<"Optiunea 3: verificati daca coada este goala.\n";
        cout<<"Optiunea 4: afisati coada.\n";
        cout<<"Optiunea 5: fisarea cozii (concomitent cu golirea).\n\n";

                cin>>ch;
                switch (ch)
                {

                         case '1':
                             { cout<<"Introduceti caracterul pe care vreti sa-l adugati. (de tip char) \n";
                               char val;
                               cin >> val;
                               coada1.push(Nod(val));
                               cout<<"*Caracterul "<<val<<" a fost adaugat in coada.\n";
                             }
                                           break;
                          case '2':
                              {
                                if (coada1.isEmpty()!= true)
                                  {Nod* val = coada1.getFirst();
                                cout<<"*Caracterul "<<val->getInfo()<<" a fost sters din coada.\n";
                                coada1.pop();}
                               }
                                           break;
                         case '3':
                             { if(coada1.isEmpty())
                                cout<<"*Coada este goala.\n";
                               else
                                cout<<"*Coada nu este goala.\n";
                             }
                                           break;
                         case '4':
                             {
                                 cout<<'\n'; coada1.afisare(coada1); cout<<'\n';
                             }
                                           break;
                         case '5':
                             {
                               cout<<coada1;
                               cout<<"Coada a fost fisata si golita.\n";
                             }
                                           break;
                }
         }
         while (ch!='0');


    return 0;
}
