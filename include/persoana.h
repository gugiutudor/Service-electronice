#ifndef FESTIVAL_PERSOANA_H
#define FESTIVAL_PERSOANA_H

#include <iostream>
#include <string>
#include <set>

class Persoana
{
protected:
    std::string nume;
    std::string prenume;
    int id;
    inline static std::set<int> idFolosite;  // pentru ID-uri unice
    virtual void validareId(int idNou);
    void setareId(int idNou);

public:
    // Constructori
    Persoana();
    Persoana(const std::string& nume, const std::string& prenume, int id);
    Persoana(const Persoana& other);

    // Operator de atribuire
    virtual Persoana& operator=(const Persoana& other);

    // Metodă virtuală pură - face clasa abstractă
    virtual std::string getTip() const = 0;

    // Getteri
    virtual int getId() const;
    const std::string& getNume() const;
    const std::string& getPrenume() const;

    // Operatori de citire/scriere
    friend std::ostream& operator<<(std::ostream& out, const Persoana& persoana);
    friend std::istream& operator>>(std::istream& in, Persoana& persoana);

    // Destructor virtual
    virtual ~Persoana();
};

#endif // FESTIVAL_PERSOANA_H
