#include "dispozitiv.h"

int Dispozitiv::idUrmator = 0;

Dispozitiv::Dispozitiv():
    id(++idUrmator), marca(""), model(""), pret(0), inGarantie(false) {}

Dispozitiv::Dispozitiv(const std::string& marca, const std::string& model, int pret, bool inGarantie):
    id(++idUrmator), marca(marca), model(model), pret(pret), inGarantie(inGarantie) {}

Dispozitiv::Dispozitiv(const Dispozitiv& other):
    id(other.id), marca(other.marca), model(other.model), pret(other.pret), inGarantie(other.inGarantie) {}

Dispozitiv& Dispozitiv::operator=(const Dispozitiv& other)
{
    if (this!=&other)
    {
        id=other.id;
        marca=other.marca;
        model=other.model;
        pret=other.pret;
        inGarantie=other.inGarantie;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& out, const Dispozitiv& d)
{
    out<<"\nID: "<<d.id
       <<"\nMarca: "<<d.marca
       <<"\nModel: "<<d.model
       <<"\nPret: "<<d.pret<<" RON"
       <<"\nGarantie: "<<(d.inGarantie?"Da":"Nu")<<"\n";
    return out;
}

std::istream& operator>>(std::istream& in, Dispozitiv& d)
{
    std::cout<<"Marca: ";
    in.ignore();
    std::getline(in, d.marca);
    std::cout<<"Model: ";
    std::getline(in, d.model);
    std::cout<<"Pret: ";
    in>>d.pret;
    std::cout<<"In garantie (Introduceti 1 pentru 'da'/Introduceti 0 pentru 'nu'): ";
    in>>d.inGarantie;
    in.ignore();
    return in;
}

Dispozitiv& Dispozitiv::operator+(float valoare)
{
    this->pret+=valoare;
    return *this;
}

Dispozitiv& operator*(Dispozitiv& d, int procent)
{
    d.pret=d.pret+(d.pret*procent/100.0f);
    return d;
}

int Dispozitiv::getId() const
{
    return id;
}

std::string Dispozitiv::getMarca() const
{
    return marca;
}

std::string Dispozitiv::getModel() const
{
    return model;
}

float Dispozitiv::getPret() const
{
    return pret;
}

bool Dispozitiv::getInGarantie() const
{
    return inGarantie;
}

void Dispozitiv::setPret(float pretNou)
{
    pret=pretNou;
}

void Dispozitiv::setGarantie(bool garantieNoua)
{
    inGarantie=garantieNoua;
}

Dispozitiv::~Dispozitiv() {}
