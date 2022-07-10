#include "entityTest.hpp"
#include "domainTest.hpp"
#include "entity.hpp"
#include "domain.hpp"

using namespace std;

template <class Entity>
void UTEntity<Entity>::setUp() {
    entity = new Entity();
}

template <class Entity>
void UTEntity<Entity>::tearDown() {
    delete entity;
}

template <class Entity>
int UTEntity<Entity>::run() {
    setUp();
    successScenario();
    tearDown();
    return response;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

const string UTUser::VALID_NAME = "Linus Torvalds";
const string UTUser::VALID_EMAIL = "torvalds@linux-foundation.org";
const string UTUser::VALID_PASSWORD = "aA&22";
const string UTUser::VALID_LANGUAGE = "Ingles";
const string UTUser::VALID_DATE = "15/Fev";
const string UTUser::VALID_DESCRIPTION = "This is a valid description.";

void UTUser::successScenario() {
    Name name;
    name.setValue(VALID_NAME);
    entity->setName(name);
    Email email;
    email.setValue(VALID_EMAIL);
    entity->setEmail(email);
    Password password;
    password.setValue(VALID_PASSWORD);
    entity->setPassword(password);
    Language language;
    language.setValue(VALID_LANGUAGE);
    entity->setLanguage(language);
    Date date;
    date.setValue(VALID_DATE);
    entity->setDate(date);
    Description description;
    description.setValue(VALID_DESCRIPTION);
    entity->setDescription(description);
    if (entity->getName().getValue() != VALID_NAME ||
        entity->getEmail().getValue() != VALID_EMAIL ||
        entity->getPassword().getValue() != VALID_PASSWORD ||
        entity->getLanguage().getValue() != VALID_LANGUAGE ||
        entity->getDate().getValue() != VALID_DATE ||
        entity->getDescription().getValue() != VALID_DESCRIPTION
    )
        response = FAILURE;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

const string UTAccommodation::VALID_CODE = "79927398713";
const string UTAccommodation::VALID_CITY = "Londres";
const string UTAccommodation::VALID_COUNTRY = "Turquia";
const string UTAccommodation::VALID_GRADE = "10";
const string UTAccommodation::VALID_DESCRIPTION = "This is a valid description.";

void UTAccommodation::successScenario() {
    Code code;
    code.setValue(VALID_CODE);
    entity->setCode(code);
    City city;
    city.setValue(VALID_CITY);
    entity->setCity(city);
    Country country;
    country.setValue(VALID_COUNTRY);
    entity->setCountry(country);
    Grade grade;
    grade.setValue(VALID_GRADE);
    entity->setGrade(grade);
    Description description;
    description.setValue(VALID_DESCRIPTION);
    entity->setDescription(description);
    if (entity->getCode().getValue() != VALID_CODE ||
        entity->getCity().getValue() != VALID_CITY ||
        entity->getCountry().getValue() != VALID_COUNTRY ||
        entity->getGrade().getValue() != VALID_GRADE ||
        entity->getDescription().getValue() != VALID_DESCRIPTION
    )
        response = FAILURE;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

const string UTRating::VALID_CODE = "79927398713";
const string UTRating::VALID_GRADE = "10";
const string UTRating::VALID_DESCRIPTION = "This is a valid description.";

void UTRating::successScenario() {
    Code code;
    code.setValue(VALID_CODE);
    entity->setCode(code);
    Grade grade;
    grade.setValue(VALID_GRADE);
    entity->setGrade(grade);
    Description description;
    description.setValue(VALID_DESCRIPTION);
    entity->setDescription(description);
    if (entity->getCode().getValue() != VALID_CODE ||
        entity->getGrade().getValue() != VALID_GRADE ||
        entity->getDescription().getValue() != VALID_DESCRIPTION
    )
        response = FAILURE;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
