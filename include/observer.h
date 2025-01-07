#ifndef FESTIVAL_OBSERVER_H
#define FESTIVAL_OBSERVER_H

#include <iostream>
#include <vector>
#include <string>

class Spectator;
class Artist;

// Interfața Observer
class Observer
{
public:
    virtual void update(const std::string& mesaj) = 0;
    virtual ~Observer() = default;
};

// Clasa Subject (Observable)
class Subject
{
    std::vector<Observer*> observeri;
public:
    void notifica(const std::string& mesaj);
    void adaugaObserver(Observer* obs);
    void stergeObserver(Observer* obs);
};

// Observer pentru Spectator
class SpectatorObserver : public Observer
{
    Spectator* spectator;
public:
    explicit SpectatorObserver(Spectator* spectator);
    void update(const std::string& mesaj) override;
};

// Observer pentru Artist
class ArtistObserver : public Observer
{
    Artist* artist;
public:
    explicit ArtistObserver(Artist* artist);
    void update(const std::string& mesaj) override;
};


#endif // FESTIVAL_OBSERVER_H
