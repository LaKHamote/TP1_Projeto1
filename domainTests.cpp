#include "domainTests.hpp"
#include "domain.hpp"


using namespace std;

City *domain;

int UTCity::setUp() {
    domain = new City();
    response = SUCCESS;
    return 8;
}

void UTDomain::successScenario() {
    try {
        domain->setValue(VALID());
        if (domain->getValue() != VALID())
            response = FAILURE;
    }
    catch(invalid_argument& error) {
        response = FAILURE;
    }
}

void UTDomain::failureScenario() {
    try {
        domain->setValue(INVALID());
        response = FAILURE;
    }
    catch(invalid_argument& error) {
        if (domain->getValue() == INVALID())
            response = FAILURE;
    }
}

void UTDomain::tearDown() {
    delete domain;
}

int UTDomain::run() {
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
        date->setValue(VALID);
        if (date->getValue() != VALID)
            response = failure;
    }
    catch(invalid_argument& error) {
        response = failure;
    }
}

void UTDate::failureScenario() {
    try {
        date->setValue(INVALID);
        response = failure;
    }
    catch(invalid_argument& error) {
        if (date->getValue() == INVALID)
            response = failure;
    }
}

void UTDate::tearDown() {
    delete date;
}

int UTDate::run() {
    setUp();
    failureScenario();
    successScenario();
    tearDown();
    return response;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

void UTEmail::setUp() {
    email = new Email();
    response = success;
}

void UTEmail::successScenario() {
    try {
        email->setValue(VALID);
        if (email->getValue() != VALID)
            response = failure;
    }
    catch(invalid_argument& error) {
        response = failure;
    }
}

void UTEmail::failureScenario() {
    try {
        email->setValue(INVALID);
        response = failure;
    }
    catch(invalid_argument& error) {
        if (email->getValue() == INVALID)
            response = failure;
    }
}

void UTEmail::tearDown() {
    delete email;
}

int UTEmail::run() {
    setUp();
    failureScenario();
    successScenario();
    tearDown();
    return response;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

void UTCode::setUp(){
    code = new Code();
    state = sucess;
}

void UTCode::tearDown(){
    delete code;
}

void UTCode::sucessScenario(){
    try{
        code->setValue(VALID);
        if (code->getValue() != VALID)
            state = failure;
    }
    catch(invalid_argument& error){
        state = failure;
    }
}

void UTCode::failureScenario(){
    try{
        code->setValue(INVALID);
        state = failure;
    }
    catch(invalid_argument& error){
        if (code->getValue() == INVALID)
            state = failure;
    }
}

int UTCode::run(){
    setUp();
    sucessScenario();
    failureScenario();
    tearDown();
    return state;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

void UTCountry::setUp(){
    country = new Country();
    state = sucess;
}

void UTCountry::tearDown(){
    delete country;
}

void UTCountry::sucessScenario(){
    try{
        country->setValue(VALID);
        if (country->getValue() != VALID)
            state = failure;
    }
    catch(invalid_argument& error){
        state = failure;
    }
}

void UTCountry::failureScenario(){
    try{
        country->setValue(INVALID);
        state = failure;
    }
    catch(invalid_argument& error){
        if (country->getValue() == INVALID)
            state = failure;
    }
}

int UTCountry::run(){
    setUp();
    sucessScenario();
    failureScenario();
    tearDown();
    return state;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

void UTName::setUp() {
    name = new Name();
    response = success;
}

void UTName::successScenario() {
    try {
        name->setValue(VALID);
        if (name->getValue() != VALID)
            response = failure;
    }
    catch(invalid_argument& error) {
        response = failure;
    }
    catch(out_of_range& error) {
        response = failure;
    }
}

void UTName::failureScenario() {
    try {
        name->setValue(INVALID);
        response = failure;
    }
    catch(invalid_argument& error) {
        if (name->getValue() == INVALID)
            response = failure;
    }
}

void UTName::tearDown() {
    delete name;
}

int UTName::run() {
    setUp();
    failureScenario();
    successScenario();
    tearDown();
    return response;
}
