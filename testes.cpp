#include "testes.hpp"
#include "dominios.hpp"

#include <iostream>

using namespace std;

void TUCity::setUp() {
    city = new City();
    response = success;
}


void TUCity::successScenario() {
    try{
        city->setCity(validValue);
        if (city->getCity() != validValue)
            response = failure;
    }
    catch(invalid_argument error) {
        response = failure;
    }
}

void TUCity::failureScenario() {
    try{
        city->setCity(invalidValue);
        response = failure;
    }
    catch(invalid_argument error) {
        if (city->getCity() == invalidValue)
            response = failure;
    }
}

void TUCity::tearDown() {
    delete city;
}

bool TUCity::run() {
    setUp();
    failureScenario();
    successScenario();
    tearDown();
    return response;
}

void TUCity::simpleTest(string city) {
    this->city = new City();
    try{
        this->city->setCity(city);
        this->city->getCity();
        printf("Success\n"); 
    }
    catch (invalid_argument error) {
        cout << error.what() << endl;
        printf("Only the following citys are allowed:\n");
        City::showAllowedCitys();
    }
}


