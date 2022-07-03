#ifndef entityTestHppIncluded
#define entityTestHppIncluded

#include "entity.hpp"
#include "domainTest.hpp"
#include <string>

using namespace std;

template <class Entity>
class UTEntity:UTName, UTEmail, UTPassword, UTLanguage, UTDate, UTCity, UTCode, UTCountry {
    protected:
        Entity *entity;                            // Referência para unidade em teste.
        bool response = SUCCESS;
        virtual string VALID() = 0;
        virtual string INVALID() = 0;
        virtual void setUp() = 0;
        void successScenario();
        void failureScenario();
        void tearDown();
        virtual ~UTEntity() {};
    public:
        const static int SUCCESS = 1;             // Definição de constante para reportar resultado de teste.
        const static int FAILURE = 0;             // Definição de constante para reportar resultado de teste.
        virtual int run();
};

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

class UTUser:public UTEntity<User> {
    private:
        string VALID() { return "Londres"; };
        string INVALID() { return "Wakanda"; };
        void setUp();
};



#endif
