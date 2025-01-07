#include "persoana.h"

void Persoana::validareId(int idNou)
{
    if (idNou < 0)
        throw std::invalid_argument("ID-ul nu poate fi negativ");
}

void Persoana::setareId(int idNou)
{
    validareId(idNou);

    if (idFolosite.find(idNou) != idFolosite.end())
        throw std::invalid_argument("ID-ul este deja utilizat");

    if (id != 0)    // Dacă persoana avea deja un ID
        idFolosite.erase(id);

    id = idNou;
    idFolosite.insert(idNou);
}

Persoana::Persoana() : nume(""), prenume(""), id(0)
{
    idFolosite.insert(0);
}

Persoana::Persoana(const std::string& nume, const std::string& prenume, int id)
    : nume(nume), prenume(prenume), id(0)
{
    setareId(id);
}

Persoana::Persoana(const Persoana& other)
    : nume(other.nume), prenume(other.prenume), id(0)
{
    // Generăm un nou ID unic
    int idNou = other.id;

    while (idFolosite.find(idNou) != idFolosite.end())
        idNou++;

    setareId(idNou);
}

Persoana& Persoana::operator=(const Persoana& other)
{
    if (this != &other)
    {
        nume = other.nume;
        prenume = other.prenume;
        // Păstrăm ID-ul actual
    }
    return *this;
}

int Persoana::getId() const
{
    return id;
}

const std::string& Persoana::getNume() const
{
    return nume;
}

const std::string& Persoana::getPrenume() const
{
    return prenume;
}

std::ostream& operator<<(std::ostream& out, const Persoana& persoana)
{
    out << "ID: " << persoana.id << "\nNume: " << persoana.nume
        << "\nPrenume: " << persoana.prenume;
    return out;
}

std::istream& operator>>(std::istream& in, Persoana& persoana)
{
    std::cout << "Introduceti numele: ";
    std::getline(in >> std::ws, persoana.nume);

    std::cout << "Introduceti prenumele: ";
    std::getline(in >> std::ws, persoana.prenume);

    int idNou;
    std::cout << "Introduceti ID-ul: ";
    in >> idNou;
    persoana.setareId(idNou);

    return in;
}

Persoana::~Persoana()
{
    if (id != 0)
        idFolosite.erase(id);
}
