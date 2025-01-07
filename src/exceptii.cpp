#include "exceptii.h"

ExceptieFestival::ExceptieFestival(const std::string& mesaj) : mesaj(mesaj) {}

const char* ExceptieFestival::what() const noexcept
{
    return mesaj.c_str();
}

ExceptieBilet::ExceptieBilet(const std::string& mesaj)
    : ExceptieFestival("Eroare bilet: " + mesaj) {}

CapacitateDepasitaException::CapacitateDepasitaException(const std::string& mesaj)
    : ExceptieBilet("Capacitate depasita: " + mesaj) {}

BiletInvalidException::BiletInvalidException(const std::string& mesaj)
    : ExceptieBilet("Bilet invalid: " + mesaj) {}

RestrictieVarstaException::RestrictieVarstaException(const std::string& mesaj)
    : ExceptieBilet("Restrictie de varsta: " + mesaj) {}
