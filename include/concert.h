#ifndef FESTIVAL_CONCERT_H
#define FESTIVAL_CONCERT_H

#include "eveniment.h"

class Concert : public Eveniment
{
private:
    std::string genMuzical;
    bool inAerLiber;

public:
    // Constructori
    Concert();
    Concert(const std::string& nume, const std::string& data, const std::string& ora,
            unsigned int capacitateMaxima, float pretBilet,
            const std::string& genMuzical, bool inAerLiber);

    // Metode specifice (minim 2-3)
    void setGenMuzical(const std::string& gen);
    void setInAerLiber(bool inAer);
    const std::string& getGenMuzical() const;

    // Operatori de stream
    friend std::ostream& operator<<(std::ostream& out, const Concert& concert);
    friend std::istream& operator>>(std::istream& in, Concert& concert);

    ~Concert() override = default;
};

#endif
