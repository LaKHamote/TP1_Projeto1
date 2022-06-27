#include "testes.hpp"
#include "dominios.hpp"


using namespace std;

void UTCity::setUp() {
    city = new City();
    response = success;
}

void UTCity::successScenario() {
    try {
        city->setCity(validValue);
        if (city->getCity() != validValue)
            response = failure;
    }
    catch(invalid_argument error) {
        response = failure;
    }
}

void UTCity::failureScenario() {
    try {
        city->setCity(invalidValue);
        response = failure;
    }
    catch(invalid_argument error) {
        if (city->getCity() == invalidValue)
            response = failure;
    }
}

void UTCity::tearDown() {
    delete city;
}

bool UTCity::run() {
    setUp();
    failureScenario();
    successScenario();
    tearDown();
    return response;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------


void UTDate::setUp() {
    date = new Date();
    response = success;
}

void UTDate::successScenario() {
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

void UTDate::failureScenario() {
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

void UTDate::tearDown() {
    delete date;
}

bool UTDate::run() {
    setUp();
    failureScenario();
    successScenario();
    tearDown();
    return response;
}

