#include "domainTests.hpp"
#include "domain.hpp"


using namespace std;

void UTCity::setUp() {
    city = new City();
    response = success;
}

void UTCity::successScenario() {
    try {
        city->setValue(validValue);
        if (city->getValue() != validValue)
            response = failure;
    }
    catch(invalid_argument& error) {
        response = failure;
    }
}

void UTCity::failureScenario() {
    try {
        city->setValue(invalidValue);
        response = failure;
    }
    catch(invalid_argument& error) {
        if (city->getValue() == invalidValue)
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
        date->setValue(validValue);
        if (date->getValue() != validValue)
            response = failure;
    }
    catch(invalid_argument& error) {
        response = failure;
    }
    catch(out_of_range& error) {
        response = failure;
    }
}

void UTDate::failureScenario() {
    try {
        date->setValue(invalidValue);
        response = failure;
    }
    catch(invalid_argument& error) {
        if (date->getValue() == invalidValue)
            response = failure;
    }
    catch(out_of_range& error) {
        if (date->getValue() == invalidValue)
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
        email->setValue(validValue);
        if (email->getValue() != validValue)
            response = failure;
    }
    catch(invalid_argument& error) {
        response = failure;
    }
    catch(out_of_range& error) {
        response = failure;
    }
}

void UTEmail::failureScenario() {
    try {
        email->setValue(invalidValue);
        response = failure;
    }
    catch(invalid_argument& error) {
        if (email->getValue() == invalidValue)
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
        name->setValue(validValue);
        if (name->getValue() != validValue)
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
        name->setValue(invalidValue);
        response = failure;
    }
    catch(invalid_argument& error) {
        if (name->getValue() == invalidValue)
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
