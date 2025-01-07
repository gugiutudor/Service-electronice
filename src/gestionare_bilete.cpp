#include "gestionare_bilete.h"
#include "concert.h"
#include "workshop.h"

template<typename T>
GestionareBilete<T>::GestionareBilete()
    : tipEveniment(""), capacitateMaxima(0), pretStandard(0.0) {}

template<typename T>
GestionareBilete<T>::GestionareBilete(const std::string& tipEveniment,
                                      unsigned int capacitateMaxima, float pretStandard)
    : tipEveniment(tipEveniment), capacitateMaxima(capacitateMaxima), pretStandard(pretStandard)
{
    if (pretStandard < 0)
    {
        throw std::invalid_argument("Pretul nu poate fi negativ");
    }
}

template<typename T>
void GestionareBilete<T>::adaugaBilet(const T& bilet)
{
    if (bilete.size() >= capacitateMaxima)
    {
        throw std::runtime_error("S-a atins capacitatea maxima de bilete");
    }
    bilete.push_back(bilet);
}

template<typename T>
void GestionareBilete<T>::stergeBilet(const std::string& nume)
{
    for (auto it = bilete.begin(); it != bilete.end(); ++it)
    {
        if (it->getNume() == nume)
        {
            bilete.erase(it);
            return;
        }
    }
    throw std::runtime_error("Biletul nu a fost gasit");
}

template<typename T>
int GestionareBilete<T>::numarBileteDisponibile() const
{
    return capacitateMaxima - bilete.size();
}

template<typename T>
bool GestionareBilete<T>::verificaDisponibilitate(const std::string& nume) const
{
    for (const auto& bilet : bilete)
    {
        if (bilet.getNume() == nume)
        {
            return true;
        }
    }
    return false;
}

template<typename T>
float GestionareBilete<T>::calculeazaVenituri() const
{
    float total = 0;
    for (const auto& bilet : bilete)
    {
        total += bilet.getPretBilet();
    }
    return total;
}

template<typename T>
std::vector<T> GestionareBilete<T>::getBileteVandute() const
{
    return bilete;
}

template<typename T>
void GestionareBilete<T>::setPretStandard(float pretNou)
{
    if (pretNou < 0)
    {
        throw std::invalid_argument("Pretul nu poate fi negativ");
    }
    pretStandard = pretNou;
}

template<typename T>
float GestionareBilete<T>::getPretStandard() const
{
    return pretStandard;
}

template<typename T>
const std::string& GestionareBilete<T>::getTipEveniment() const
{
    return tipEveniment;
}

template<typename T>
bool GestionareBilete<T>::operator<(const GestionareBilete<T>& other) const
{
    return this->calculeazaVenituri() < other.calculeazaVenituri();
}

// Instanțieri explicite ale clasei template pentru tipurile specifice
template class GestionareBilete<Concert>;
template class GestionareBilete<Workshop>;
