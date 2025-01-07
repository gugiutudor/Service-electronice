#include "artist.h"
#include <algorithm>

Artist::Artist() : Persoana(), gen_muzical(""), experienta_ani(0) {}

Artist::Artist(const std::string& nume, const std::string& prenume, int id,
               const std::string& gen_muzical, int experienta_ani)
    : Persoana(nume, prenume, id),
      gen_muzical(gen_muzical),
      experienta_ani(experienta_ani)
{
    if (experienta_ani < 0)
        throw std::invalid_argument("Experienta nu poate fi negativa");
}

void Artist::adaugaInstrument(const std::string& instrument)
{
    if (std::find(instrumente.begin(), instrumente.end(), instrument) == instrumente.end())
        instrumente.push_back(instrument);
}

const std::string& Artist::getGenMuzical() const
{
    return gen_muzical;
}

int Artist::getExperienta() const
{
    return experienta_ani;
}

std::string Artist::getTip() const
{
    return "Artist";
}

std::ostream& operator<<(std::ostream& out, const Artist& artist)
{
    out << static_cast<const Persoana&>(artist) << "\n"
        << "Gen muzical: " << artist.gen_muzical << "\n"
        << "Experienta: " << artist.experienta_ani << " ani\n"
        << "Instrumente: ";

    for (const auto& instrument : artist.instrumente)
        out << instrument << ", ";

    return out;
}

std::istream& operator>>(std::istream& in, Artist& artist)
{
    in >> static_cast<Persoana&>(artist);

    std::cout << "Gen muzical: ";
    std::getline(in >> std::ws, artist.gen_muzical);

    std::cout << "Ani de experienta: ";
    in >> artist.experienta_ani;

    std::cout << "Numar de instrumente: ";
    int n;
    in >> n;
    artist.instrumente.clear();

    for (int i = 0; i < n; ++i)
    {
        std::string instrument;
        std::cout << "Instrument " << (i+1) << ": ";
        std::getline(in >> std::ws, instrument);
        artist.adaugaInstrument(instrument);
    }

    return in;
}
