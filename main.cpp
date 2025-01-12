#include <iostream>
#include <vector>

#include "dispozitiv.h"
#include "smartphone.h"
#include "pc.h"
#include "client.h"
#include "service.h"

int main()
{
    Service service("Service electronice");
    std::vector<Client*> clienti;
    std::vector<Dispozitiv*> dispozitive;

    int optiune;
    do
    {
        std::cout<<"\n\n=== MENIU PRINCIPAL ===";
        std::cout<<"\n1. Adauga client nou";
        std::cout<<"\n2. Adauga smartphone in service";
        std::cout<<"\n3. Adauga PC in service";
        std::cout<<"\n4. Afiseaza toti clientii";
        std::cout<<"\n5. Afiseaza dispozitive in service";
        std::cout<<"\n6. Diagnosticare dispozitiv";
        std::cout<<"\n7. Calculeaza cost reparatie";
        std::cout<<"\n0. Iesire";
        std::cout<<"\nAlegeti o optiune: ";
        std::cin>>optiune;

        switch(optiune)
        {
        case 1:
        {
            std::string nume, telefon;
            std::cout<<"Nume client: ";
            std::cin.ignore();
            std::getline(std::cin, nume);
            std::cout<<"Telefon: ";
            std::getline(std::cin, telefon);
            Client* client=new Client(nume, telefon);
            clienti.push_back(client);
            service.adaugaClient(client);
            std::cout<<"Client adaugat cu succes!\n";
            break;
        }
        case 2:
        {
            if(clienti.empty())
            {
                std::cout<<"Nu exista clienti! Va rugam sa adaugati mai intai un client.\n";
                break;
            }

            std::cout<<"\nClienti disponibili:";
            for(Client* client: clienti)
                std::cout<<"\n"<<client->getId()<<". "<<client->getNume();

            int idClient;
            std::cout<<"\nIntroduceti ID-ul clientului: ";
            std::cin>>idClient;

            Client* clientSelectat=nullptr;
            for(Client* client: clienti)
                if(client->getId()==idClient)
                {
                    clientSelectat=client;
                    break;
                }

            if(clientSelectat==nullptr)
            {
                std::cout<<"Client invalid!\n";
                break;
            }

            Smartphone* s=new Smartphone();
            std::cin>>*s;
            dispozitive.push_back(s);
            clientSelectat->adaugaDispozitiv(s);
            service.primesteDispozitiv(s, idClient);
            std::cout<<"Smartphone adaugat in service pentru clientul "<<clientSelectat->getNume()<<"!\n";
            break;
        }
        case 3:
        {
            if(clienti.empty())
            {
                std::cout<<"Nu exista clienti! Va rugam sa adaugati mai intai un client.\n";
                break;
            }

            std::cout<<"\nClienti disponibili:";
            for(Client* client: clienti)
                std::cout<<"\n"<<client->getId()<<". "<<client->getNume();

            int idClient;
            std::cout<<"\nIntroduceti ID-ul clientului: ";
            std::cin>>idClient;

            Client* clientSelectat=nullptr;
            for(Client* client: clienti)
                if(client->getId()==idClient)
                {
                    clientSelectat = client;
                    break;
                }

            if(clientSelectat==nullptr)
            {
                std::cout << "Client invalid!\n";
                break;
            }

            PC* pc=new PC();
            std::cin>>*pc;
            dispozitive.push_back(pc);
            clientSelectat->adaugaDispozitiv(pc);
            service.primesteDispozitiv(pc, idClient);
            std::cout<<"PC adaugat in service pentru clientul "<<clientSelectat->getNume()<<"!\n";
            break;
        }
        case 4:
        {
            for(Client* client: clienti)
                std::cout<<*client;
            break;
        }
        case 5:
        {
            std::cout<<service;
            break;
        }
        case 6:
        {
            std::cout<<service;
            if(dispozitive.empty())
            {
                std::cout<<"\nNu exista dispozitive in service!\n";
                break;
            }

            int idDispozitiv;
            std::cout<<"\nIntroduceti ID-ul dispozitivului pentru diagnosticare: ";
            std::cin>>idDispozitiv;

            for(Dispozitiv* dispozitiv: dispozitive)
                if(dispozitiv->getId()==idDispozitiv)
                {
                    dispozitiv->diagnosticare();
                    break;
                }
            break;
        }
        case 7:
        {
            std::cout<<service;
            if(dispozitive.empty())
            {
                std::cout<<"\nNu exista dispozitive in service!\n";
                break;
            }

            int idDispozitiv;
            std::cout<<"\nIntroduceti ID-ul dispozitivului pentru calculare cost: ";
            std::cin>>idDispozitiv;

            for(Dispozitiv* dispozitiv: dispozitive)
                if(dispozitiv->getId()==idDispozitiv)
                {
                    float cost=dispozitiv->calculeazaCostReparatie();
                    std::cout<<"Cost reparatie: "<<cost<<" RON\n";
                    break;
                }
            break;
        }
        }
    }
    while(optiune!=0);

    for(Client* client: clienti)
        delete client;

    for(Dispozitiv* dispozitiv: dispozitive)
        delete dispozitiv;

    return 0;
}
