#ifndef FESTIVAL_FACTORY_H
#define FESTIVAL_FACTORY_H

#include "eveniment.h"
#include "concert.h"
#include "workshop.h"

class FestivalFactory
{
public:
    static Concert* creeazaConcert(const std::string& nume,
                                   const std::string& data,
                                   const std::string& ora,
                                   unsigned int capacitateMaxima,
                                   float pretBilet,
                                   const std::string& genMuzical,
                                   bool inAerLiber);

    static Workshop* creeazaWorkshop(const std::string& nume,
                                     const std::string& data,
                                     const std::string& ora,
                                     unsigned int capacitate,
                                     float pret,
                                     const std::string& instructor,
                                     const std::string& nivel);

    static Eveniment* creeazaEveniment(const std::string& nume,
                                       const std::string& data,
                                       const std::string& ora,
                                       unsigned int capacitateMaxima,
                                       float pretBilet);
};

#endif
