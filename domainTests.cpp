#include "domainTests.hpp"
#include "domain.hpp"


using namespace std;

template <class Domain>
void UTDomain<Domain>::successScenario() {
    try {
        domain->setValue(VALID());
        if (domain->getValue() != VALID())
            response = FAILURE;
    }
    catch(invalid_argument& error) {
        response = FAILURE;
    }
}

template <class Domain>
void UTDomain<Domain>::failureScenario() {
    try {
        domain->setValue(INVALID());
        response = FAILURE;
    }
    catch(invalid_argument& error) {
        if (domain->getValue() == INVALID())
            response = FAILURE;
    }
}

template <class Domain>
void UTDomain<Domain>::tearDown() {
    delete domain;
}

template <class Batata>
int UTDomain<Batata>::run() {
    setUp();
    successScenario();
    failureScenario();
    tearDown();
    return response;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

void UTCity::setUp() {
    domain = new City();
    response = SUCCESS;
}

void UTDate::setUp() {
    domain = new Date();
    response = SUCCESS;
}

void UTEmail::setUp() {
    domain = new Email();
    response = SUCCESS;
}

void UTCode::setUp(){
    domain = new Code();
    response = SUCCESS;
}

void UTCountry::setUp(){
    domain = new Country();
    response = SUCCESS;
}

void UTName::setUp() {
    domain = new Name();
    response = SUCCESS;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

void UTPassword::setUp(){
    password = new Password();
    state = sucess;
}

void UTPassword::tearDown(){
    delete password;
}

void UTPassword::sucessScenario(){
    try{
        password->setValue(VALID);
        if (password->getValue() != VALID)
            state = failure;
    }
    catch(invalid_argument& error){
        state = failure;
    }
}

void UTPassword::failureScenario(){
    try{
        password->setValue(INVALID);
        state = failure;
    }
    catch(invalid_argument& error){
        if (password->getValue() == INVALID)
            state = failure;
    }
}

int UTPassword::run(){
    setUp();
    sucessScenario();
    failureScenario();
    tearDown();
    return state;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

