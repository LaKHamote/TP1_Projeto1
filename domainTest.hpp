#ifndef domainTestHppIncluded
#define domainTestHppIncluded

#include "domain.hpp"
#include <string>

using namespace std;

template <class Domain>
class UTDomain {
    protected:
        Domain *domain;                            // Referência para unidade em teste.
        //virtual ~UTDomain() {};                  // nao sei se precisa
    private:
        virtual string VALID() const = 0;
        virtual string INVALID() const = 0;
        virtual void setUp() = 0;
        void successScenario();
        void failureScenario();
        void tearDown();
        bool response = SUCCESS;
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
    private:
        void setUp();
};
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

class UTDate:public UTDomain<Date> {
    protected:
        string VALID() const { return "15/Fev"; };
        string INVALID() const { return "40/Mar"; };
    private:
        void setUp();
};

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

class UTEmail:public UTDomain<Email> {
    protected:
        string VALID() const { return "torvalds@linux-foundation.org"; };
        string INVALID() const { return "This is an invalid email format.";};
    private:
        void setUp();
};
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

class UTCode:public UTDomain<Code> {
    protected:
        string VALID() const { return "79927398713"; };   
        string INVALID() const { return "79927398712"; };
    private:                           
        static const int LENGHT = 11;
        void setUp();                            
};
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

class UTCountry:public UTDomain<Country> {
    protected:
        string VALID() const { return "Turquia"; };
        string INVALID() const { return "Inglaterra"; };
    private:
        static const int LENGHT = 12;
        void setUp(); 
};
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

class UTName:public UTDomain<Name> {
    protected:
        string VALID() const { return "Linus Torvalds"; };
        string INVALID() const { return "riCharD StaLLmaN"; };
    private:
        void setUp();

};
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

class UTPassword:public UTDomain<Password> {
    protected:
        string VALID() const { return "aA&22"; };   
        string INVALID() const { return "manga"; };   
    private:
        static const int LENGHT = 5;
        void setUp();                      
};
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

class UTLanguage:public UTDomain<Language> {
    protected:
        string VALID() const { return "Ingles"; };   
        string INVALID() const { return "Klingon"; };                        
    private:
        void setUp();                      
};
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

class UTDescription:public UTDomain<Description> {
    protected:
        string VALID() const { return "This is a valid description."; };
        string INVALID() const { return "This    ISN'T    a valid description...   ^_^"; };
    private:
        void setUp();

};

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
class UTGrade:public UTDomain<Grade> {
    protected:
        string VALID() const { return "10"; };
        string INVALID() const { return "13"; };
    private:
        void setUp();

};
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

#endif
