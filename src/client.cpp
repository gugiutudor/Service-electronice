#include "Client.h"

int Client::idUrmator = 0;

Client::Client(const std::string& nume, const std::string telefon): id(++idUrmator), nume(nume), telefon(telefon) {}

void Client::adaugaDispozitiv(Dispozitiv* d)
{
    dispozitive.push_back(d);
}

std::ostream& operator<<(std::ostream& out, const Client& c)
{
    out<<"\nClient "<<c.nume<<" (ID: "<<c.id<<")";
    out<<"\nDispozitive detinute:";
    for(Dispozitiv* d: c.dispozitive)
        out<<"\n"<<*d;
    return out;
}

int Client::getId() const
{
    return id;
}

std::string Client::getNume() const
{
    return nume;
}

const std::vector<Dispozitiv*>& Client::getDispozitive() const
{
    return dispozitive;
}
