#ifndef FESTIVAL_ARTIST_H
#define FESTIVAL_ARTIST_H

#include "persoana.h"
#include <vector>

class Artist : public Persoana
{
private:
    std::string gen_muzical;
    std::vector<std::string> instrumente;
    int experienta_ani;

public:
    // Constructori
    Artist();
    Artist(const std::string& nume, const std::string& prenume, int id,
           const std::string& gen_muzical, int experienta_ani);

    // Metode specifice (minim 2-3)
    void adaugaInstrument(const std::string& instrument);
    const std::string& getGenMuzical() const;
    int getExperienta() const;

    // Implementarea metodei virtuale pure
    std::string getTip() const override;

    // Operatori de stream
    friend std::ostream& operator<<(std::ostream& out, const Artist& artist);
    friend std::istream& operator>>(std::istream& in, Artist& artist);

    ~Artist() override = default;
};

#endif
