#ifndef FESTIVAL_EXCEPTII_H
#define FESTIVAL_EXCEPTII_H

#include <exception>
#include <string>

class ExceptieFestival : public std::exception
{
protected:
    std::string mesaj;
public:
    explicit ExceptieFestival(const std::string& mesaj);
    const char* what() const noexcept override;
};

class ExceptieBilet : public ExceptieFestival
{
public:
    explicit ExceptieBilet(const std::string& mesaj);
};

class CapacitateDepasitaException : public ExceptieBilet
{
public:
    explicit CapacitateDepasitaException(const std::string& mesaj);
};

class BiletInvalidException : public ExceptieBilet
{
public:
    explicit BiletInvalidException(const std::string& mesaj);
};

class RestrictieVarstaException : public ExceptieBilet
{
public:
    explicit RestrictieVarstaException(const std::string& mesaj);
};


#endif // FESTIVAL_EXCEPTII_H
