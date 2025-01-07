#ifndef FESTIVAL_GESTIONARE_BILETE_H
#define FESTIVAL_GESTIONARE_BILETE_H

#include <vector>
#include <string>
#include <stdexcept>

template<typename T>
class GestionareBilete
{
private:
    std::vector<T> bilete;
    std::string tipEveniment;
    unsigned int capacitateMaxima;
    float pretStandard;

public:
    GestionareBilete();
    GestionareBilete(const std::string& tipEveniment, unsigned int capacitateMaxima, float pretStandard);

    void adaugaBilet(const T& bilet);
    void stergeBilet(const std::string& nume);  // modificat pentru a căuta după nume
    int numarBileteDisponibile() const;
    bool verificaDisponibilitate(const std::string& nume) const;  // modificat pentru a căuta după nume
    float calculeazaVenituri() const;
    std::vector<T> getBileteVandute() const;

    void setPretStandard(float pretNou);
    float getPretStandard() const;
    const std::string& getTipEveniment() const;

    bool operator<(const GestionareBilete<T>& other) const;
};

#endif // FESTIVAL_GESTIONARE_BILETE_H
