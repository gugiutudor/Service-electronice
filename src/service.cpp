#include "Service.h"

Service::Service(const std::string& nume): nume(nume) {}

void Service::adaugaClient(Client* client)
{
    clienti.push_back(client);
}

void Service::primesteDispozitiv(Dispozitiv* dispozitiv, int idClient)
{
    for(Client* client: clienti)
        if(client->getId()==idClient)
            for(Dispozitiv* d: client->getDispozitive())
                if(d==dispozitiv)
                    dispozitiveActive.push_back(dispozitiv);
}

std::ostream& operator<<(std::ostream& out, const Service& s)
{
    out<<"\nService "<<s.nume;
    out<<"\nDispozitive in stadiu de reparare:";
    for(Dispozitiv* d: s.dispozitiveActive)
        out<<"\n"<<*d;
    return out;
}
