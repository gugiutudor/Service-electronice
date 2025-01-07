#include "observer.h"
#include "spectator.h"
#include "artist.h"

void Subject::adaugaObserver(Observer* obs)
{
    observeri.push_back(obs);
}

void Subject::stergeObserver(Observer* obs)
{
    for(size_t i = 0; i < observeri.size(); i++)
        if(obs == observeri[i])
        {
            observeri.erase(observeri.begin() + i);
            break;
        }
}

void Subject::notifica(const std::string& mesaj)
{
    for(size_t i = 0; i < observeri.size(); i++)
        observeri[i]->update(mesaj);
}

SpectatorObserver::SpectatorObserver(Spectator* spectator) : spectator(spectator) {}

void SpectatorObserver::update(const std::string& mesaj)
{
    std::cout << "Notificare pentru spectatorul " << spectator->getNume()
              << " " << spectator->getPrenume() << ": " << mesaj << "\n";
}

ArtistObserver::ArtistObserver(Artist* artist) : artist(artist) {}

void ArtistObserver::update(const std::string& mesaj)
{
    std::cout << "Notificare pentru artistul " << artist->getNume()
              << " " << artist->getPrenume() << ": " << mesaj << "\n";
}
