#include "spectator.h"
#include <stdexcept>

Spectator::Spectator()
    : Persoana(), tipBilet("Standard"), buget(0.0), varsta(0) {}

Spectator::Spectator(const std::string& nume, const std::string& prenume, int id,
                     const std::string& tipBilet, float buget, int varsta)
    : Persoana(nume, prenume, id),
      tipBilet(tipBilet),
      buget(buget),
      varsta(varsta)
{
    if (buget < 0)
        throw std::invalid_argument("Bugetul nu poate fi negativ");
}

void Spectator::setTipBilet(const std::string& tipNou)
{
    if (tipNou != "Standard" && tipNou != "VIP" && tipNou != "Student")
        throw std::invalid_argument("Tip bilet invalid");

    tipBilet = tipNou;
}

void Spectator::adaugaBuget(float suma)
{
    if (suma < 0)
        throw std::invalid_argument("Suma adaugata nu poate fi negativa");

    buget += suma;
}

void Spectator::scadeBuget(float suma)
{
    if (suma < 0)
        throw std::invalid_argument("Suma scazuta nu poate fi negativa");

    if (suma > buget)
        throw std::runtime_error("Fonduri insuficiente");

    buget -= suma;
}

std::string Spectator::getTip() const
{
    return "Spectator";
}

std::ostream& operator<<(std::ostream& out, const Spectator& spectator)
{
    out << static_cast<const Persoana&>(spectator) << "\n"
        << "Tip bilet: " << spectator.tipBilet << "\n"
        << "Buget ramas: " << spectator.buget << " lei\n"
        << "Varsta: " << spectator.varsta << " ani\n";
    return out;
}

std::istream& operator>>(std::istream& in, Spectator& spectator)
{
    in >> static_cast<Persoana&>(spectator);

    std::cout << "Tip bilet (Standard/VIP/Student): ";
    std::getline(in >> std::ws, spectator.tipBilet);

    std::cout << "Buget disponibil: ";
    in >> spectator.buget;

    std::cout << "Varsta: ";
    in >> spectator.varsta;

    return in;
}
