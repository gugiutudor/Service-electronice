#ifndef DISPOZITIV_H_INCLUDED
#define DISPOZITIV_H_INCLUDED

#include <iostream>

class Dispozitiv
{
protected:
    int id;
    std::string marca;
    std::string model;
    float pret;
    bool inGarantie;
    static int idUrmator;

public:
    Dispozitiv();

    Dispozitiv(const std::string& marca, const std::string& model, int pret, bool inGarantie);

    Dispozitiv(const Dispozitiv& other);

    Dispozitiv& operator=(const Dispozitiv& other);

    friend std::ostream& operator<<(std::ostream& out, const Dispozitiv& d);

    friend std::istream& operator>>(std::istream& in, Dispozitiv& d);

    Dispozitiv& operator+(float valoare);

    friend Dispozitiv& operator*(Dispozitiv& d, int procent);

    int getId() const;
    std::string getMarca() const;
    std::string getModel() const;
    float getPret() const;
    bool getInGarantie() const;

    void setPret(float pretNou);
    void setGarantie(bool garantieNoua);

    virtual void diagnosticare()=0;
    virtual float calculeazaCostReparatie()=0;
    virtual void afiseazaDetaliiSpecifice()=0;

    virtual ~Dispozitiv();
};

#endif // DISPOZITIV_H_INCLUDED
