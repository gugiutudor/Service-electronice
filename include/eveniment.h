#ifndef FESTIVAL_EVENIMENT_H
#define FESTIVAL_EVENIMENT_H

#include <string>
#include <iostream>

class Eveniment
{
protected:
    std::string nume;
    std::string data;
    std::string ora;
    unsigned int capacitateMaxima;
    float pretBilet;

    static void validareData(const std::string& data);
    static void validareOra(const std::string& ora);

public:
    // Constructori
    Eveniment();
    Eveniment(const std::string& nume, const std::string& data,
              const std::string& ora, unsigned int capacitateMaxima, float pretBilet);

    // Getteri
    const std::string& getNume() const;
    unsigned int getCapacitateMaxima() const;
    float getPretBilet() const;

    // Operatori
    friend std::ostream& operator<<(std::ostream& out, const Eveniment& eveniment);
    friend std::istream& operator>>(std::istream& in, Eveniment& eveniment);

    // Destructor virtual pentru polimorfism
    virtual ~Eveniment() = default;
};

#endif // FESTIVAL_EVENIMENT_H
