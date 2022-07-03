#include "domain.hpp"
#include <iostream>
#include <string>
#include <regex>
#include <sstream>


const unordered_set<string> City::allowedCities = { "Antalya", "Bangkok", "Delhi", "Dubai", "Hong Kong", "Londres", "Macau", "Mumbai", "Paris", "Rio de Janeiro",
                                            "Sao Paulo", "Seul", "Istambul", "Kuala Lumpur", "Nova Iorque", "Osaka", "Phuket", "Shenzhen", "Toquio" };
void City::validate(string city) {
    if (allowedCities.find(city) == allowedCities.end())
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

bool Code::luhn(string code) {
    int i, sum = 0, codeInt[LENGTH];
    bool valid = false;

    for (i = 0;i < LENGTH;i++)
        codeInt[i] = (int) code[i] - 48; // tabela ASCII

    for (i = LENGTH - 2;i >= 0;i -= 2){
        codeInt[i] *= 2;
        if (codeInt[i] > 9)
            codeInt[i] -= 9;
    }
    for (i = 0;i < LENGTH;i++)
        sum += codeInt[i];

    if (sum % 10 == 0)
        valid = true;

    return valid;
}

void Code::validate(string code) {
    int i;

    if (code.size() != LENGTH)
        throw invalid_argument("Invalid code Format");
    for (i = 0;i < LENGTH;i++)
        if (!(code[i] >= MINIMUM && code[i] <= MAXIMUM))
            throw invalid_argument("Invalid code Format");
    if (!(luhn(code)))
        throw invalid_argument("Invalid code Format");
    return;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------


const unordered_set<string> Country::allowedCountries = {"Estados Unidos", "Brasil", "China", "Coreia do Sul", "Emirados", "França",
                                                        "India", "Japao", "Malasia", "Reino Unido", "Tailandia", "Turquia"};
void Country::validate(string country) {
    if (allowedCountries.find(country) == allowedCountries.end())
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

void Password::validate(string password) {
    bool hasDigit = false, hasLowercase = false, hasUppercase = false, hasSpecial = false, invalidChar = false;
    int i;

    if (password.size() != LENGTH)
        throw invalid_argument("Invalid password Format!");

    for (i = 0;i < LENGTH;i++){
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


const unordered_set<string> Language::allowedLanguages = { "Ingles", "Chines", "Mandarim", "Hindi", "Espanhol",
                                                        "Frances", "Arabe", "Bengali", "Russo", "Portugues", "Indonesio"};
void Language::validate(string language) {
    if (allowedLanguages.find(language) == allowedLanguages.end())
        throw invalid_argument("Invalid Language");
}