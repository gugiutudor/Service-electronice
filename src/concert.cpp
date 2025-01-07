#include "concert.h"

Concert::Concert()
    : Eveniment(), genMuzical(""), inAerLiber(false) {}

Concert::Concert(const std::string& nume, const std::string& data, const std::string& ora,
                 unsigned int capacitateMaxima, float pretBilet,
                 const std::string& genMuzical, bool inAerLiber)
    : Eveniment(nume, data, ora, capacitateMaxima, pretBilet),
      genMuzical(genMuzical), inAerLiber(inAerLiber) {}

void Concert::setGenMuzical(const std::string& gen)
{
    if(gen.empty())
        throw std::invalid_argument("Genul muzical nu poate fi gol");

    genMuzical = gen;
}

void Concert::setInAerLiber(bool inAer)
{
    inAerLiber = inAer;
}

const std::string& Concert::getGenMuzical() const
{
    return genMuzical;
}

std::ostream& operator<<(std::ostream& out, const Concert& concert)
{
    out << static_cast<const Eveniment&>(concert) << "\n"
        << "Gen muzical: " << concert.genMuzical << "\n"
        << "Locatie: " << (concert.inAerLiber ? "In aer liber" : "In interior");

    return out;
}

std::istream& operator>>(std::istream& in, Concert& concert)
{
    in >> static_cast<Eveniment&>(concert);

    std::cout << "Gen muzical: ";
    std::getline(in >> std::ws, concert.genMuzical);

    std::cout << "Concert in aer liber (1-Da/0-Nu): ";
    in >> concert.inAerLiber;

    return in;
}
