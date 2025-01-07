#include "eveniment.h"
#include <regex>
#include <stdexcept>

void Eveniment::validareData(const std::string& data)
{
    std::regex pattern("^\\d{4}-(0[1-9]|1[0-2])-(0[1-9]|[12]\\d|3[01])$");

    if (!std::regex_match(data, pattern))
        throw std::invalid_argument("Format data invalid. Folositi formatul YYYY-MM-DD");
}

void Eveniment::validareOra(const std::string& ora)
{
    std::regex pattern("^([01]\\d|2[0-3]):([0-5]\\d)$");

    if (!std::regex_match(ora, pattern))
        throw std::invalid_argument("Format ora invalid. Folositi formatul HH:MM");
}

Eveniment::Eveniment()
    : nume(""), data("2024-01-01"), ora("00:00"),
      capacitateMaxima(0), pretBilet(0.0) {}

Eveniment::Eveniment(const std::string& nume, const std::string& data,
                     const std::string& ora, unsigned int capacitateMaxima, float pretBilet)
    : nume(nume), data(data), ora(ora),
      capacitateMaxima(capacitateMaxima), pretBilet(pretBilet)
{
    validareData(data);
    validareOra(ora);
    if (pretBilet < 0)
        throw std::invalid_argument("Pretul biletului nu poate fi negativ");
}

const std::string& Eveniment::getNume() const
{
    return nume;
}

unsigned int Eveniment::getCapacitateMaxima() const
{
    return capacitateMaxima;
}

float Eveniment::getPretBilet() const
{
    return pretBilet;
}

std::ostream& operator<<(std::ostream& out, const Eveniment& eveniment)
{
    out << "Eveniment: " << eveniment.nume << "\n"
        << "Data: " << eveniment.data << "\n"
        << "Ora: " << eveniment.ora << "\n"
        << "Capacitate maxima: " << eveniment.capacitateMaxima << " persoane\n"
        << "Pret bilet: " << eveniment.pretBilet << " lei";

    return out;
}

std::istream& operator>>(std::istream& in, Eveniment& eveniment)
{
    std::cout << "Introduceti numele evenimentului: ";
    std::getline(in >> std::ws, eveniment.nume);

    do
    {
        std::cout << "Introduceti data (YYYY-MM-DD): ";
        std::getline(in >> std::ws, eveniment.data);
        try
        {
            eveniment.validareData(eveniment.data);
            break;
        }
        catch (const std::invalid_argument& e)
        {
            std::cout << e.what() << "\n";
        }
    }
    while (true);

    do
    {
        std::cout << "Introduceti ora (HH:MM): ";
        std::getline(in >> std::ws, eveniment.ora);
        try
        {
            eveniment.validareOra(eveniment.ora);
            break;
        }
        catch (const std::invalid_argument& e)
        {
            std::cout << e.what() << "\n";
        }
    }
    while (true);

    std::cout << "Introduceti capacitatea maxima: ";
    in >> eveniment.capacitateMaxima;

    do
    {
        std::cout << "Introduceti pretul biletului: ";
        in >> eveniment.pretBilet;
        if (eveniment.pretBilet >= 0) break;
        std::cout << "Pretul nu poate fi negativ!\n";
    }
    while (true);

    return in;
}
