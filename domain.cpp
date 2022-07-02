#include "domain.hpp"

#include <iostream>
#include <string>
#include <regex>
#include <sstream>

void City::validate(string value) {
    if (allowedCitys.find(value) == allowedCitys.end())
        throw invalid_argument("Invalid City");
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------


void Date::validate(string date) {
    const regex pattern("(0[1-9]|[12][0-9]|3[01])/(Jan|Fev|Mar|Abr|Mai|Jun|Jul|Ago|Set|Out|Nov|Dez)");
    if (!regex_match(date, pattern))
        throw invalid_argument("Invalid Date Format");
}


//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

void Email::validate(string email) {
    const regex pattern("(\\w+)(\\.|-|_)?(\\w*)@(\\w+)(\\.|-|_)?(\\w*)(\\.(\\w+))+");
    if (!regex_match(email, pattern)) {
        throw invalid_argument("Invalid e-mail Format");
    }
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

    if (code.size() != LENGHT)
        throw invalid_argument("Invalid code Format");
    for (i = 0;i < LENGHT;i++)
        if (!(code[i] >= MINIMUM && code[i] <= MAXIMUM))
            throw invalid_argument("Invalid code Format");
    if (!(luhn(code)))
        throw invalid_argument("Invalid code Format");
    return;
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

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------

void Name::validate(string name) {
    if (name.length() > 30) {
        throw invalid_argument("Name has too many characters!");
    }
    if (name[name.length() - 1] == ' ') {
        throw invalid_argument("Name can't end with a whitespace.");
    }
    const regex pattern1("[ ]{2,}");
    if (regex_search(name, pattern1)) {
        throw invalid_argument("Name can't have multiple whitespaces!");
    }
    string aux;
    stringstream ss(name);
    while (ss >> aux) {
        if (aux[0] < 'A' || aux[0] > 'Z') {
            throw invalid_argument("Invalid name format!");
        }
        for (string::iterator it = aux.begin() + 1; it < aux.end(); it++) {
            if (*it < 'a' || *it > 'z') {
                throw invalid_argument("Invalid name format!");
            }
        }
    }
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

void Password::validate(string password){
    bool hasDigit = false, hasLowercase = false, hasUppercase = false, hasSpecial = false, invalidChar = false;
    int i;

    if (password.size() != LENGHT)
        throw invalid_argument("Invalid password Format!");

    for (i = 0;i < LENGHT;i++){
        if (password[i] >= '0' && password[i] <= '9')
            hasDigit = true;
        else if (password[i] >= 'a' && password[i] <= 'z')
            hasLowercase = true;
        else if (password[i] >= 'A' && password[i] <= 'Z')
            hasUppercase = true;
        else if (password[i] == '!' || password[i] == '#' || password[i] == '$' || password[i] == '%' || password[i] == '&')
            hasSpecial = true;
        else
            invalidChar = true;
    }

    if (!(!invalidChar && ((hasLowercase || hasUppercase) && hasDigit && hasSpecial)))
        throw invalid_argument("Invalid password Format!");
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
