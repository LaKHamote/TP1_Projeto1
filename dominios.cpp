#include "dominios.hpp"

#include <iostream>
#include <string>
// #include <vector>

void City::validar(string city){
    for (const auto &item : AcceptableCitys) {
        if (item == city) { return; }
    }
    throw invalid_argument("Apenas as seguintes cidades são válidas:" + AcceptableCitys[19]);
};

void City::setCity(string city) {
    validar(city);
    this->city = city;
}


