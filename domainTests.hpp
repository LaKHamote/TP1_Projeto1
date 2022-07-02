#ifndef testHppIncluded
#define testHppIncluded

#include "domain.hpp"
#include <string>

using namespace std;

template <class Domain>
class UTDomain {
    protected:
        Domain *domain;                            // Referência para unidade em teste.
        bool response = SUCCESS;
        virtual string VALID() = 0;
        virtual string INVALID() = 0;
        virtual void setUp() = 0;
        void successScenario();
        void failureScenario();
        void tearDown();
        virtual ~UTDomain() {};
    public:
        const static int SUCCESS = 1;             // Definição de constante para reportar resultado de teste.
        const static int FAILURE = 0;             // Definição de constante para reportar resultado de teste.
        virtual int run();                        // Método para executar teste.
};

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

class UTCity:public UTDomain<City> {
    private:
        string VALID() { return "Londres"; };
        string INVALID() { return "Wakanda"; };
        void setUp();
};
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

class UTDate:public UTDomain<Date> {
    private:
        string VALID() { return "15/Fev"; };
        string INVALID() { return "40/Mar"; };
        void setUp();
};
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

class UTEmail:public UTDomain<Email> {
    private:
        string VALID() { return "torvalds@linux-foundation.org"; };
        string INVALID() { return "This is an invalid email format.";};
        void setUp();
};
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

class UTCode:public UTDomain<Code> {
    private:
        static const int LENGHT = 11;
        string VALID() { return "79927398713"; };   
        string INVALID() { return "79927398712"; };                           
        void setUp();                            
};
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

class UTCountry:public UTDomain<Country> {
    private:
        static const int LENGHT = 12;
        string VALID() { return "Turquia"; };
        string INVALID() { return "Inglaterra"; };
        void setUp(); 
};
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

class UTName:public UTDomain<Name> {
    private:
        string VALID() { return "Linus Torvalds"; };
        string INVALID() { return "riCharD StaLLmaN"; };
        void setUp();
};
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

class UTPassword:public UTDomain<Password> {
    private:
        static const int LENGHT = 5;
        string VALID() { return "aA&22"; };   
        string INVALID() { return "manga"; };                        
        void setUp();                      
};
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

class UTLanguage:public UTDomain<Language> {
    private:
        string VALID() { return "Ingles"; };   
        string INVALID() { return "Klingon"; };                        
        void setUp();                      
};
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

#endif
