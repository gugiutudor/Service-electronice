#include "Smartphone.h"

Smartphone::Smartphone():
    Dispozitiv(), capacitateBaterie(0), memorie(0), cardStocare(0),
    stocareOcupata(0), tipProcesor(""), sistemOperare("") {}

Smartphone::Smartphone(const std::string& marca, const std::string& model, int pret, bool inGarantie,
                       int capacitateBaterie, int memorie, int cardStocare, float stocareOcupata,
                       const std::string& tipProcesor, const std::string& sistemOperare):
    Dispozitiv(marca, model, pret, inGarantie),
    capacitateBaterie(capacitateBaterie), memorie(memorie),
    cardStocare(cardStocare), stocareOcupata(stocareOcupata),
    tipProcesor(tipProcesor), sistemOperare(sistemOperare) {}

Smartphone::Smartphone(const Smartphone& other):
    Dispozitiv(other), capacitateBaterie(other.capacitateBaterie),
    memorie(other.memorie), cardStocare(other.cardStocare),
    stocareOcupata(other.stocareOcupata), tipProcesor(other.tipProcesor),
    sistemOperare(other.sistemOperare) {}

Smartphone& Smartphone::operator=(const Smartphone& other)
{
    if (this!=&other)
    {
        Dispozitiv::operator=(other);
        capacitateBaterie=other.capacitateBaterie;
        memorie=other.memorie;
        cardStocare=other.cardStocare;
        stocareOcupata=other.stocareOcupata;
        tipProcesor=other.tipProcesor;
        sistemOperare=other.sistemOperare;
    }
    return *this;
}

std::istream& operator>>(std::istream& in, Smartphone& s)
{
    in>>static_cast<Dispozitiv&>(s);
    std::cout<<"Tip procesor: ";
    std::getline(in, s.tipProcesor);
    std::cout<<"Capacitate baterie (mAh): ";
    in>>s.capacitateBaterie;
    std::cout<<"Memorie RAM (GB): ";
    in>>s.memorie;
    std::cout<<"Capacitate card stocare (GB): ";
    in>>s.cardStocare;
    std::cout<<"Stocare ocupata (GB): ";
    in>>s.stocareOcupata;
    in.ignore();
    std::cout<<"Sistem de operare: ";
    std::getline(in, s.sistemOperare);
    return in;
}

void Smartphone::diagnosticare()
{
    verificaStareBaterie();
    testeazaStocare();
}

float Smartphone::calculeazaCostReparatie()
{
    float cost=0;
    if (capacitateBaterie<2000)
        cost+=200;
    if (stocareOcupata/cardStocare>0.8)
        cost+=150;
    return cost;
}

void Smartphone::afiseazaDetaliiSpecifice()
{
    std::cout<<"Detalii smartphone:\n";
    std::cout<<"Capacitate baterie: "<<capacitateBaterie<<" mAh\n";
    std::cout<<"Sistem de operare: "<<sistemOperare<<"\n";
    std::cout<<"Procesor: "<<tipProcesor<<"\n";
    std::cout<<"Memorie RAM: "<<memorie<<" GB\n";
    std::cout<<"Capacitate card: "<<cardStocare<<" GB\n";
    std::cout<<"Memorie ocupata: "<<stocareOcupata<<" GB\n";
}

void Smartphone::verificaStareBaterie()
{
    std::cout<<"Stare baterie: "<<capacitateBaterie<<" mAh\n";
    if(capacitateBaterie<2000)
        std::cout<<"Baterie uzata - necesita inlocuire.\n";
    else
        std::cout<<"Bateria functioneaza in parametri normali.";
}

void Smartphone::testeazaStocare()
{
    float procentOcupat=(stocareOcupata/cardStocare)*100;
    std::cout<<"Spatiu ocupat pe card: "<<procentOcupat<<"%\n";
    if(procentOcupat>80)
        std::cout<<"Spatiu insuficient pe card - se recomanda upgrade.\n";
    else
        std::cout<<"Aveti spatiu suficient pe smartphone.";
}
