#ifndef entityTestHppIncluded
#define entityTestHppIncluded

#include "entity.hpp"
#include "domainTest.hpp"
#include <string>

using namespace std;

template <class Entity>
class UTEntity:UTName, UTEmail, UTPassword, UTLanguage, UTDate, UTDescription, UTCity, UTCode, UTCountry {
    protected:
        Entity *entity;                            // Referência para unidade em teste.
        virtual ~UTEntity() {};
    private:
        virtual void setUp() = 0;
        void successScenario();
        void failureScenario();
        void tearDown();
        bool response = SUCCESS;
    public:
        const static int SUCCESS = 1;             // Definição de constante para reportar resultado de teste.
        const static int FAILURE = 0;             // Definição de constante para reportar resultado de teste.
        virtual int run();
};

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

class UTUser:public UTEntity<User> {
    private:
        void setUp();
};



#endif
