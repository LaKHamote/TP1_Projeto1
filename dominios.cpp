#include "dominios.hpp"

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

bool Email::setEmail(string email) {
    try {
        validate(email);
    }
    catch (const invalid_argument& error) {
        cout << error.what() << '\n';
        return false;
    }
    this->email = email;
    return true;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

