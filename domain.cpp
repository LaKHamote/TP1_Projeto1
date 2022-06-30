#include "domain.hpp"

#include <iostream>
#include <string>
#include <regex>

void City::validate(string city) {
    for (const auto &item : allowedCitys) {
        if (item == city) { return; }
    }
    throw invalid_argument("Invalid City");
};

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------


void Date::validate(string date) {
    const regex pattern("(0[1-9]|[12][0-9]|3[01])/(Jan|Fev|Mar|Abr|Mai|Jun|Jul|Ago|Set|Out|Nov|Dez)");
    if (!regex_match(date, pattern))
        throw invalid_argument("Invalid Date Format");
};


//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

void Email::validate(string email) {
    const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    if (!regex_match(email, pattern)) {
        throw invalid_argument("Invalid e-mail Format");
    }
}

void Email::setEmail(string email) {
    validate(email);
    this->email = email;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

bool Code::luhn(string code){
    int i, sum = 0, codeInt[LENGHT];
    bool valid = false;

    for (i = 0;i < LENGHT;i++)
        codeInt[i] = (int) code[i] - 48; // tabela ASCII

    for (i = LENGHT - 2;i >= 0;i -= 2){
        codeInt[i] *= 2;
        if (codeInt[i] > 9)
            codeInt[i] -= 9;
    }
    for (i = 0;i < LENGHT;i++)
        sum += codeInt[i];

    if (sum % 10 == 0)
        valid = true;

    return valid;
}

void Code::validate(string code){
    int i;

    if (code.size() > LENGHT)
        throw invalid_argument("Invalid code Format");
    for (i = 0;i < LENGHT;i++)
        if (!(code[i] >= MINIMUM && code[i] <= MAXIMUM))
            throw invalid_argument("Invalid code Format");
    if (!(luhn(code)))
        throw invalid_argument("Invalid code Format");
    return;
}

void Code::setCode(string code){
    validate(code);
    this->code = code;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

void Country::validate(string country){
    int i;
    bool validCountry = false;

    for (i = 0;i < LENGHT;i++)
        if (valids[i] == country)
            validCountry = true;

    if (!(validCountry))
        throw invalid_argument("Invalid country Format");
}

void Country::setCountry(string country){
    validate(country);
    this->country = country;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

