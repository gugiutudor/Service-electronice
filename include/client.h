#ifndef CLIENT_H_INCLUDED
#define CLIENT_H_INCLUDED

#include <vector>
#include "Dispozitiv.h"

class Client
{
private:
    int id;
    std::string nume;
    std::string telefon;
    std::vector<Dispozitiv*> dispozitive;
    static int idUrmator;

public:
    Client(const std::string& nume, const std::string telefon);

    void adaugaDispozitiv(Dispozitiv* d);

    friend std::ostream& operator<<(std::ostream& out, const Client& c);

    int getId() const;
    std::string getNume() const;
    const std::vector<Dispozitiv*>& getDispozitive() const;
};

#endif // CLIENT_H_INCLUDED
