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
    string day_aux;
    string month;
    int day; // 10/Jan
    bool flag = false;
    for (auto const& value : date)
        if (value != '/' && not flag)
            day_aux += value;
        else
            if (flag)
                month += value;
            else 
                flag = true;
    day = stoi(day_aux);

    if (!(lowRangeDays <= day && day <= highRangeDays))
        throw out_of_range("Invalid Day");
    for (const auto &item : allowedMonths) 
        if (item == month) { return; }
    throw invalid_argument("Invalid Month");
};


//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

void Email::validate(string email) {
    const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    if (!regex_match(email, pattern)) {
        throw invalid_argument("Invalid e-mail format");
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

