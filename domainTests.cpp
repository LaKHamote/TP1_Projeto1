#include "domainTests.hpp"
#include "domain.hpp"


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

int UTCity::run() {
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
        email->setEmail(validValue);
        if (email->getEmail() != validValue)
            response = failure;
    }
    catch(invalid_argument error) {
        response = failure;
    }
    catch(out_of_range error) {
        response = failure;
    }
}

void UTEmail::failureScenario() {
    try {
        email->setEmail(invalidValue);
        response = failure;
    }
    catch(invalid_argument error) {
        if (email->getEmail() == invalidValue)
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
        code->setCode(VALID);
        if (code->getCode() != VALID)
            state = failure;
    }
    catch(invalid_argument error){
        state = failure;
    }
}

void UTCode::failureScenario(){
    try{
        code->setCode(INVALID);
        state = failure;
    }
    catch(invalid_argument error){
        if (code->getCode() == INVALID)
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
        country->setCountry(VALID);
        if (country->getCountry() != VALID)
            state = failure;
    }
    catch(invalid_argument error){
        state = failure;
    }
}

void UTCountry::failureScenario(){
    try{
        country->setCountry(INVALID);
        state = failure;
    }
    catch(invalid_argument error){
        if (country->getCountry() == INVALID)
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
        name->setName(validValue);
        if (name->getName() != validValue)
            response = failure;
    }
    catch(invalid_argument error) {
        response = failure;
    }
    catch(out_of_range error) {
        response = failure;
    }
}

void UTName::failureScenario() {
    try {
        name->setName(invalidValue);
        response = failure;
    }
    catch(invalid_argument error) {
        if (name->getName() == invalidValue)
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
