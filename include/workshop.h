// workshop.h
#ifndef FESTIVAL_WORKSHOP_H
#define FESTIVAL_WORKSHOP_H

#include "eveniment.h"

class Workshop : public Eveniment
{
private:
    std::string instructor;
    std::string nivelDificultate;  // "Începător", "Intermediar", "Avansat"

public:
    Workshop();
    Workshop(const std::string& nume, const std::string& data, const std::string& ora,
             unsigned int capacitateMaxima, float pretBilet,
             const std::string& instructor, const std::string& nivelDificultate);

    // Metode specifice (minim 2-3)
    void setInstructor(const std::string& numeInstructor);
    void setNivelDificultate(const std::string& nivel);
    const std::string& getInstructor() const;

    // Operatori de stream
    friend std::ostream& operator<<(std::ostream& out, const Workshop& workshop);
    friend std::istream& operator>>(std::istream& in, Workshop& workshop);

    ~Workshop() override = default;
};

#endif
