#ifndef SERVICE_H_INCLUDED
#define SERVICE_H_INCLUDED

#include <vector>
#include "Client.h"
#include "Dispozitiv.h"

class Service
{
private:
    std::string nume;
    std::vector<Client*> clienti;
    std::vector<Dispozitiv*> dispozitiveActive;

public:
    Service(const std::string& nume);

    void adaugaClient(Client* client);
    void primesteDispozitiv(Dispozitiv* dispozitiv, int idClient);

    friend std::ostream& operator<<(std::ostream& out, const Service& s);
};

#endif // SERVICE_H_INCLUDED
