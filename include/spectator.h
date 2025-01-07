#ifndef FESTIVAL_SPECTATOR_H
#define FESTIVAL_SPECTATOR_H

#include "persoana.h"

class Spectator : public Persoana
{
private:
    std::string tipBilet;  // VIP, Standard, etc.
    float buget;
    int varsta;

public:
    // Constructori
    Spectator();
    Spectator(const std::string& nume, const std::string& prenume, int id,
              const std::string& tipBilet, float buget, int varsta);

    // Metode specifice (minim 2-3)
    void setTipBilet(const std::string& tipNou);
    void adaugaBuget(float suma);
    void scadeBuget(float suma);

    // Implementarea metodei virtuale pure
    std::string getTip() const override;

    // Operatori de stream
    friend std::ostream& operator<<(std::ostream& out, const Spectator& spectator);
    friend std::istream& operator>>(std::istream& in, Spectator& spectator);

    ~Spectator() override = default;
};

#endif
