#ifndef PC_H_INCLUDED
#define PC_H_INCLUDED

#include "Dispozitiv.h"

class PC: public Dispozitiv
{
private:
    std::string tipProcesor;
    float frecventaProcesor;
    int memorie;
    std::string tipPlacaVideo;
    int capacitatePlacaVideo;

public:
    PC();

    PC(const std::string& marca, const std::string& model, int pret, bool inGarantie,
       const std::string& tipProcesor, float frecventaProcesor, int memorie,
       const std::string& tipPlacaVideo, int capacitatePlacaVideo);

    PC(const PC& other);

    PC& operator=(const PC& other);

    friend std::istream& operator>>(std::istream& in, PC& p);

    void diagnosticare() override;
    float calculeazaCostReparatie() override;
    void afiseazaDetaliiSpecifice() override;

    void verificaMemorie();
    void verificaPlacaVideo();
};

#endif // PC_H_INCLUDED
