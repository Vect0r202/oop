#include <iostream>
#include <cstring>
using namespace std;

class Automobil
{
    char *marca= new char [30];
    char *model= new char [30];
    int an;
public:
    Automobil(char *marca, char *model, int an)
    {
        delete[] this->marca;
        this->marca = new char[strlen(marca)+1];
        strcpy(this->marca,marca);
        delete[] this->model;
        this->model = new char[strlen(model)+1];
        strcpy(this->model,model);
        this->an=an;
    }

    Automobil()
    {
        delete[] this->marca;
        this->marca = new char[8];
        strcpy(this->marca,"default");
        delete[] this->model;
        this->model = new char[8];
        strcpy(this->model,"default");
        this->an=2020;
    }

    Automobil(const Automobil&rhs)
    {
        delete[] marca;
        marca = new char[strlen(rhs.marca)+1];
        strcpy(marca,rhs.marca);
        delete[] model;
        model = new char[strlen(rhs.model)+1];
        strcpy(model,rhs.model);
        an=rhs.an;
    }

    void afisare()const
    {
        cout<<"Marca automobilului ales este: "<<marca<<endl;
        cout<<"Modelul automobilului ales este: "<<model<<endl;
        cout<<"Anul automobilului ales este: "<<an<<endl;
    }

    char *getMarca()const
    {
        return marca;
    }
    void setMarca(char *marca)
    {
        if(marca==NULL)
        {
            cout<<"Marca invalida. Introduceti alta marca! "<<endl;
            return ;
        }

        delete[] this->marca;
        this->marca = new char[strlen(marca)+1];
        strcpy(this->marca,marca);

    }

    char *getModel()const
    {
        return model;
    }
    void setModel(char *model)
    {
        if(model==NULL)
        {
            cout<<"Model invalid. Introduceti alt model! "<<endl;
            return ;
        }

        delete[] this->model;
        this->model = new char[strlen(model)+1];
        strcpy(this->model,model);

    }

    int getAn()const
    {
        return an;
    }

    void setAn(int an)
    {
        if(an<2019 || an>2024)
        {
            cout<<"An invalid. Introduceti alt an! "<<endl;
            return;
        }
        this->an=an;
    }

    friend ostream&operator<<(ostream& braila,const Automobil& a)
    {
        braila<<"Marca automobilului ales este: "<<a.marca<<endl;
        braila<<"Modelul automobilului ales este: "<<a.model<<endl;
        braila<<"Anul automobilului ales este: "<<a.an<<endl;
        return braila;
    }

    friend istream&operator>>(istream& galati, Automobil& a)
    {
        char modeltemp[30],marcatemp[30];
        cout<<"Introduceti modelul masinii: "<<endl;
        galati.getline(modeltemp,30);
        delete [] a.model;
        a.model = new char[strlen(modeltemp)+1];
        strcpy(a.model,modeltemp);
        cout<<"Introduceti marca masinii: "<<endl;
        galati.getline(marcatemp,30);
        delete [] a.marca;
        a.marca = new char[strlen(marcatemp)+1];
        strcpy(a.marca,marcatemp);
        cout<<"Introduceti anul masinii: "<<endl;
        galati>>a.an;
        return galati;
    }

    Automobil& operator=(const Automobil& rhs)
    {
        delete[] marca;
        marca=new char [strlen(rhs.marca)+1];
        strcpy(marca,rhs.marca);
        delete[] model;
        model=new char [strlen(rhs.model)+1];
        strcpy(model,rhs.model);
        an=rhs.an;
    }

    ~Automobil()
    {
        delete[] marca;
        delete[] model;
    }
};

class Reprezentata
{
    int nr_masini;
    int id_loc;
    Automobil **lista_masini=new Automobil*[100];
public:
    Reprezentata(int nr_masini, int id_loc, Automobil *lista_masini[])
    {
        this->nr_masini=nr_masini;
        this->id_loc=id_loc;
        for(int i=0; i<nr_masini; i++)
        {
            this->lista_masini[i]=lista_masini[i];
        }
    }

    Reprezentata()
    {
        this->nr_masini=nr_masini;
        this->id_loc=id_loc;
        for(int i=0; i<nr_masini; i++)
        {
            this->lista_masini[i]=NULL;
        }
    }

    Reprezentata(const Reprezentata&rhs)
    {
        nr_masini=rhs.nr_masini;
        id_loc=rhs.id_loc;
        *lista_masini=*rhs.lista_masini;
    }

    void afisare_r()const
    {
        cout<<"Locatia reprezentatei are id-ul: "<<id_loc<<endl;
        cout<<"Numarul de masini pe care le are in stoc reprezentanta este: "<<nr_masini<<endl;
        for(int i=0; i<nr_masini; i++)
        {
            lista_masini[i]->afisare();
        }
    }

    int getId_loc()const
    {
        return id_loc;
    }

    void setId_loc(int id_loc)
    {
        if(id_loc<100)
        {
            cout<<"Id de locatie invalid. Introduceti alt id! "<<endl;
            return;
        }
        this->id_loc=id_loc;
    }

    int getNr_masini()const
    {
        return nr_masini;
    }

    void setNr_masini(int nr_masini)
    {
        if(nr_masini<40 || nr_masini>100)
        {
            cout<<"An invalid. Introduceti alt an! "<<endl;
            return;
        }
        this->nr_masini=nr_masini;
    }

    friend istream &operator>>(istream& galati, Reprezentata& automobile){
        cout<<"Introduceti numarul de masini: "<<endl;
        galati>>automobile.nr_masini;
        cout<<"Introduceti id-ul reprezentatei: "<<endl;
        galati>>automobile.id_loc;
    }
    friend ostream &operator<<(ostream& braila, const Reprezentata& automobile)
    {
        braila<<"Numarul de automobile: "<<automobile.nr_masini<<endl<<"Id-ul locatiei este: "<<automobile.id_loc<<endl;
        for(int i=0; i<automobile.nr_masini; i++)
        {
            braila<<automobile.lista_masini[i];
        }
        return  braila;
    }

    void cautare_masina(char model_cautat[])
    {
        for(int i=0;i<nr_masini;i++)
        {
            if(strcmp(lista_masini[i]->getModel() ,model_cautat)==0)
                lista_masini[i]->afisare();
        }
    }

    ~Reprezentata(){
        for(int i=0;i<nr_masini;i++)
        {
            delete lista_masini[i];
        }
        delete[] lista_masini;

    }
};


int main()
{
    /*
    Automobil a1("mercedes","sklasse",2019);
    a1.afisare();
    cout<<a1;
    Automobil a2("bemveu", "septar", 2020);
    a2=a1;
    cout<<a2;
    */
    int nr_masini_1=3;
    char model_1[256];char marca_1[256];int an_1;
    Automobil ** lista_masini=new Automobil*[4];
    for(int i=0;i<nr_masini_1;i++)
    {
        cout<<"Introduceti marca masinii: "<<endl;
        fflush(stdin);
        cin.getline(marca_1,256);
        cout<<"Introduceti modelul masinii: "<<endl;
        cin.getline(model_1,256);
        cout<<"Introduceti anul masinii: "<<endl;
        cin>>an_1;
        lista_masini[i]=new Automobil(marca_1,model_1,an_1);
    }
    Reprezentata *reprezentanta_1=new Reprezentata(nr_masini_1,12,lista_masini);
    int tasta=0;char model_cautat[256];
    cout<<"Pentru a afisa catalogul de masini apasati tasta 1. Pentru a cauta o masina apasati tasta 2."<<endl;
    cin>>tasta;
    if(tasta==1)
        {
            reprezentanta_1->afisare_r();
        }
    else if(tasta==2){
        cout<<"Ce vreti sa cautati?"<<endl;
        fflush(stdin);
        cin.getline(model_cautat,256);
        reprezentanta_1->cautare_masina(model_cautat);
    }
    return 0;
}
