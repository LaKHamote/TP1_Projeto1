#include "entityTest.hpp"
#include "domainTest.hpp"
#include "entity.hpp"
#include "domain.hpp"

using namespace std;

template <class Entity>
void UTEntity<Entity>::tearDown() {
    delete entity;
}

template <class Entity>
int UTEntity<Entity>::run() {
    setUp();
    successScenario();
    failureScenario();
    tearDown();
    return response;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

template <>
void UTEntity<User>::successScenario() {
    try {
        entity->setName(UTName::VALID());
        entity->setEmail(UTEmail::VALID());
        entity->setPassword(UTPassword::VALID());
        entity->setLanguage(UTLanguage::VALID());
        entity->setDate(UTDate::VALID());
        entity->setDescription(UTDescription::VALID());
        if (entity->getName() != UTName::VALID() ||
            entity->getEmail() != UTEmail::VALID() ||
            entity->getPassword() != UTPassword::VALID() ||
            entity->getLanguage() != UTLanguage::VALID() ||
            entity->getDate() != UTDate::VALID() ||
            entity->getDescription() != UTDescription::VALID()
        )
            response = FAILURE;
    }
    catch(invalid_argument& error) {
        response = FAILURE;
    }
}

template <> //falta arrumar
void UTEntity<User>::failureScenario() {
    try {
        entity->setName(UTName::INVALID());
        response = FAILURE;
    }
    catch(invalid_argument& error) {
        if (entity->getName() == UTName::INVALID())
            response = FAILURE;
    }
}


void UTUser::setUp() {
    entity = new User();
}