#include "testes.hpp"
#include "dominios.hpp"

#include <iostream>

using namespace std;

void TUCity::setUp() {
    city = new City();
    response = success;
}

void TUCity::successScenario() {
    try {
        city->setCity(validValue);
        if (city->getCity() != validValue)
            response = failure;
    }
    catch(invalid_argument error) {
        response = failure;
    }
}

void TUCity::failureScenario() {
    try {
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
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------


void TUDate::setUp() {
    date = new Date();
    response = success;
}

void TUDate::successScenario() {
    try {
        date->setDate(validValue);
        if (date->getDate() != validValue)
            response = failure;
    }
    catch(invalid_argument error) {
        response = failure;
    }
    catch(out_of_range error) {
        response = failure;
    }
}

void TUDate::failureScenario() {
    try {
        date->setDate(invalidValue);
        response = failure;
    }
    catch(invalid_argument error) {
        if (date->getDate() == invalidValue)
            response = failure;
    }
    catch(out_of_range error) {
        if (date->getDate() == invalidValue)
            response = failure;
    }
}

void TUDate::tearDown() {
    delete date;
}

bool TUDate::run() {
    setUp();
    failureScenario();
    successScenario();
    tearDown();
    return response;
}

