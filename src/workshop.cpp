// workshop.cpp
#include "workshop.h"

Workshop::Workshop()
    : Eveniment(), instructor(""), nivelDificultate("Incepator") {}

Workshop::Workshop(const std::string& nume, const std::string& data, const std::string& ora,
                   unsigned int capacitateMaxima, float pretBilet,
                   const std::string& instructor, const std::string& nivelDificultate)
    : Eveniment(nume, data, ora, capacitateMaxima, pretBilet),
      instructor(instructor),
      nivelDificultate(nivelDificultate)
{
    if (nivelDificultate != "Incepator" &&
            nivelDificultate != "Intermediar" &&
            nivelDificultate != "Avansat")
        throw std::invalid_argument("Nivel de dificultate invalid");
}

void Workshop::setInstructor(const std::string& numeInstructor)
{
    if (numeInstructor.empty())
        throw std::invalid_argument("Numele instructorului nu poate fi gol");

    instructor = numeInstructor;
}

void Workshop::setNivelDificultate(const std::string& nivel)
{
    if (nivel != "Incepator" && nivel != "Intermediar" && nivel != "Avansat")
        throw std::invalid_argument("Nivel de dificultate invalid");

    nivelDificultate = nivel;
}

const std::string& Workshop::getInstructor() const
{
    return instructor;
}

std::ostream& operator<<(std::ostream& out, const Workshop& workshop)
{
    out << static_cast<const Eveniment&>(workshop) << "\n"
        << "Instructor: " << workshop.instructor << "\n"
        << "Nivel de dificultate: " << workshop.nivelDificultate;

    return out;
}

std::istream& operator>>(std::istream& in, Workshop& workshop)
{
    in >> static_cast<Eveniment&>(workshop);

    std::cout << "Numele instructorului: ";
    std::getline(in >> std::ws, workshop.instructor);

    do
    {
        std::cout << "Nivel de dificultate (Incepator/Intermediar/Avansat): ";
        std::getline(in >> std::ws, workshop.nivelDificultate);
    }
    while (workshop.nivelDificultate != "Incepator" &&
            workshop.nivelDificultate != "Intermediar" &&
            workshop.nivelDificultate != "Avansat");

    return in;
}
