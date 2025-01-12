#ifndef SMARTPHONE_H_INCLUDED
#define SMARTPHONE_H_INCLUDED

#include "Dispozitiv.h"

class Smartphone: public Dispozitiv
{
private:
    int capacitateBaterie;
    int memorie;
    int cardStocare;
    float stocareOcupata;
    std::string tipProcesor;
    std::string sistemOperare;

public:
    Smartphone();

    Smartphone(const std::string& marca, const std::string& model, int pret, bool inGarantie,
               int capacitateBaterie, int memorie, int cardStocare, float stocareOcupata,
               const std::string& tipProcesor, const std::string& sistemOperare);

    Smartphone(const Smartphone& other);

    Smartphone& operator=(const Smartphone& other);

    friend std::istream& operator>>(std::istream& in, Smartphone& s);

    void diagnosticare() override;
    float calculeazaCostReparatie() override;
    void afiseazaDetaliiSpecifice() override;

    void verificaStareBaterie();
    void testeazaStocare();
};

#endif // SMARTPHONE_H_INCLUDED
