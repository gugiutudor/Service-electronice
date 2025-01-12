#include "pc.h"

PC::PC(): Dispozitiv(), tipProcesor(""), frecventaProcesor(0),
    memorie(0), tipPlacaVideo(""), capacitatePlacaVideo(0) {}

PC::PC(const std::string& marca, const std::string& model, int pret, bool inGarantie,
       const std::string& tipProcesor, float frecventaProcesor, int memorie,
       const std::string& tipPlacaVideo, int capacitatePlacaVideo):
    Dispozitiv(marca, model, pret, inGarantie), tipProcesor(tipProcesor), frecventaProcesor(frecventaProcesor),
    memorie(memorie), tipPlacaVideo(tipPlacaVideo), capacitatePlacaVideo(capacitatePlacaVideo) {}

PC::PC(const PC& other):
    Dispozitiv(other), tipProcesor(other.tipProcesor), frecventaProcesor(other.frecventaProcesor), memorie(other.memorie),
    tipPlacaVideo(other.tipPlacaVideo), capacitatePlacaVideo(other.capacitatePlacaVideo) {}

PC& PC::operator=(const PC& other)
{
    if (this!=&other)
    {
        Dispozitiv::operator=(other);
        tipProcesor=other.tipProcesor;
        frecventaProcesor=other.frecventaProcesor;
        memorie=other.memorie;
        tipPlacaVideo=other.tipPlacaVideo;
        capacitatePlacaVideo=other.capacitatePlacaVideo;
    }
    return *this;
}

std::istream& operator>>(std::istream& in, PC& p)
{
    in>>static_cast<Dispozitiv&>(p);
    std::cout<<"Tip procesor: ";
    std::getline(in, p.tipProcesor);
    std::cout<<"Frecventa procesor (GHz): ";
    in>>p.frecventaProcesor;
    std::cout<<"Memorie RAM (GB): ";
    in>>p.memorie;
    in.ignore();
    std::cout<<"Tip placa video: ";
    std::getline(in, p.tipPlacaVideo);
    std::cout<<"Capacitate placa video (GB): ";
    in>>p.capacitatePlacaVideo;
    in.ignore();
    return in;
}

void PC::diagnosticare()
{
    verificaMemorie();
    verificaPlacaVideo();
}

float PC::calculeazaCostReparatie()
{
    float cost=0;
    if (memorie<16)
        cost+=400;
    if (capacitatePlacaVideo<8)
        cost+=2000;
    return cost;
}

void PC::afiseazaDetaliiSpecifice()
{
    std::cout<<"Detalii PC:\n";
    std::cout<<"Procesor: "<<tipProcesor<<" "<<frecventaProcesor<<"GHz\n";
    std::cout<<"Memorie RAM: "<<memorie<<"GB\n";
    std::cout<<"Placa video: "<<tipPlacaVideo<<" "<<capacitatePlacaVideo<<"GB\n";
}

void PC::verificaMemorie()
{
    std::cout<<"Test memorie RAM: "<<memorie<<"GB\n";
    if (memorie<16)
        std::cout<<"RAM insuficient - se recomanda upgrade la minim 16GB.\n";
    else
        std::cout<<"Memorie RAM suficienta pentru utilizare normala.\n";
}

void PC::verificaPlacaVideo()
{
    std::cout<<"Verificare placa video: "<<tipPlacaVideo<<" "<<capacitatePlacaVideo<<"GB\n";
    if (capacitatePlacaVideo<8)
        std::cout<<"Se recomanda upgrade la o placa video cu minim 8GB VRAM.\n";
    else
        std::cout<<"Placa video corespunde cerintelor actuale.\n";
}
