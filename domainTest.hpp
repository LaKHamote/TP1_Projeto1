#ifndef domainTestHppIncluded
#define domainTestHppIncluded

#include "domain.hpp"
#include <string>

using namespace std;

template <class Domain>
class UTDomain {
    protected:
        Domain *domain;                            // Referência para unidade em teste.
        bool response = SUCCESS;
        virtual string VALID() const = 0;
        virtual string INVALID() const = 0;
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
    protected:
        string VALID() const { return "Londres"; };
        string INVALID() const { return "Wakanda"; };
        void setUp();
};
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

class UTDate:public UTDomain<Date> {
    protected:
        string VALID() const { return "15/Fev"; };
        string INVALID() const { return "40/Mar"; };
        void setUp();
};
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

class UTEmail:public UTDomain<Email> {
    protected:
        string VALID() const { return "torvalds@linux-foundation.org"; };
        string INVALID() const { return "This is an invalid email format.";};
        void setUp();
};
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

class UTCode:public UTDomain<Code> {
    protected:
        static const int LENGHT = 11;
        string VALID() const { return "79927398713"; };   
        string INVALID() const { return "79927398712"; };                           
        void setUp();                            
};
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

class UTCountry:public UTDomain<Country> {
    protected:
        static const int LENGHT = 12;
        string VALID() const { return "Turquia"; };
        string INVALID() const { return "Inglaterra"; };
        void setUp(); 
};
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

class UTName:public UTDomain<Name> {
    protected:
        string VALID() const { return "Linus Torvalds"; };
        string INVALID() const { return "riCharD StaLLmaN"; };
        void setUp();
    public:

};
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

class UTPassword:public UTDomain<Password> {
    protected:
        static const int LENGHT = 5;
        string VALID() const { return "aA&22"; };   
        string INVALID() const { return "manga"; };                        
        void setUp();                      
};
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

class UTLanguage:public UTDomain<Language> {
    protected:
        string VALID() const { return "Ingles"; };   
        string INVALID() const { return "Klingon"; };                        
        void setUp();                      
};
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

#endif
