#include "domainTest.hpp"
#include "../Domains/domain.hpp"

using namespace std;

template <class DomainClass>
void UTDomain<DomainClass>::successScenario() {
    try {
        domain->setValue(VALID());
        if (domain->getValue() != VALID())
            response = FAILURE;
    }
    catch(invalid_argument& error) {
        cout << error.what() << endl;
        response = FAILURE;
    }
}

template <class DomainClass>
void UTDomain<DomainClass>::failureScenario() {
    try {
        domain->setValue(INVALID());
        response = FAILURE;
    }
    catch(invalid_argument& error) {
        if (domain->getValue() == INVALID())
            response = FAILURE;
    }
}

template <class DomainClass>
void UTDomain<DomainClass>::tearDown() {
    delete domain;
}

template <class DomainClass>
int UTDomain<DomainClass>::run() {
    setUp();
    successScenario();
    failureScenario();
    tearDown();
    return response;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

void UTCity::setUp() {
    domain = new City();
}
void UTDate::setUp() {
    domain = new Date();
}
void UTEmail::setUp() {
    domain = new Email();
}
void UTCode::setUp() {
    domain = new Code();
}
void UTCountry::setUp( ){
    domain = new Country();
}
void UTName::setUp() {
    domain = new Name();
}
void UTPassword::setUp() {
    domain = new Password();
}
void UTLanguage::setUp() {
    domain = new Language();
}
void UTDescription::setUp() {
    domain = new Description();
}
void UTGrade::setUp() {
    domain = new Grade();
}
