#include "dominios.hpp"

#include <iostream>
#include <string>

void City::validar(string city) {
    for (const auto &item : allowedCitys) {
        if (item == city) { return; }
    }
    throw invalid_argument("Invalid City");
};

void City::setCity(string city) {
    validar(city);
    this->city = city;
}

void City::showAllowedCitys() {
    for(auto const& value : allowedCitys)
        cout << value << "; ";
    cout << endl;
}
