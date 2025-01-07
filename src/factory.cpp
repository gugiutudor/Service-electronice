#include "factory.h"

Concert* FestivalFactory::creeazaConcert(const std::string& nume,
        const std::string& data,
        const std::string& ora,
        unsigned int capacitateMaxima,
        float pretBilet,
        const std::string& genMuzical,
        bool inAerLiber)
{
    return new Concert(nume, data, ora, capacitateMaxima, pretBilet,
                       genMuzical, inAerLiber);
}

Workshop* FestivalFactory::creeazaWorkshop(const std::string& nume,
        const std::string& data, const std::string& ora,
        unsigned int capacitate, float pret,
        const std::string& instructor, const std::string& nivel
                                          )
{
    return new Workshop(nume, data, ora, capacitate, pret,
                        instructor, nivel);
}

Eveniment* FestivalFactory::creeazaEveniment(const std::string& nume,
        const std::string& data,
        const std::string& ora,
        unsigned int capacitateMaxima,
        float pretBilet)
{
    return new Eveniment(nume, data, ora, capacitateMaxima, pretBilet);
}

