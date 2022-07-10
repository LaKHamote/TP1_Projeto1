#ifndef domainTestHppIncluded
#define domainTestHppIncluded

#include "domain.hpp"
#include <string>

using namespace std;

/**
 * Parent class of all tests for domains
 * 
 * Template Params:
 * -Any declared Domain 
 * 
 * Author: 211038262
 */
template <class Domain>
class UTDomain {
    protected:
        Domain *domain;
        //virtual ~UTDomain() {};
    private:
        virtual string VALID() const = 0;
        virtual string INVALID() const = 0;
        virtual void setUp() = 0;
        void successScenario();
        void failureScenario();
        void tearDown();
        bool response = SUCCESS;
    public:
        const static int SUCCESS = 1;
        const static int FAILURE = 0;
        virtual int run();
};

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

class UTCity:public UTDomain<City> {
    private:
        string VALID() const { return "Londres"; };
        string INVALID() const { return "Wakanda"; };
        void setUp();
};
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

class UTDate:public UTDomain<Date> {
    private:
        string VALID() const { return "15/Fev"; };
        string INVALID() const { return "40/Mar"; };
        void setUp();
};

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

class UTEmail:public UTDomain<Email> {
    private:
        string VALID() const { return "torvalds@linux-foundation.org"; };
        string INVALID() const { return "This is an invalid email format.";};
        void setUp();
};
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

class UTCode:public UTDomain<Code> {
    private:                           
        string VALID() const { return "79927398713"; };   
        string INVALID() const { return "79927398712"; };
        static const int LENGHT = 11;
        void setUp();                            
};
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

class UTCountry:public UTDomain<Country> {
    private:
        string VALID() const { return "Turquia"; };
        string INVALID() const { return "Inglaterra"; };
        static const int LENGHT = 12;
        void setUp(); 
};
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

class UTName:public UTDomain<Name> {
    private:
        string VALID() const { return "Linus Torvalds"; };
        string INVALID() const { return "riCharD StaLLmaN"; };
        void setUp();

};
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

class UTPassword:public UTDomain<Password> {
    private:
        string VALID() const { return "aA&22"; };   
        string INVALID() const { return "manga"; };   
        static const int LENGHT = 5;
        void setUp();                      
};
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

class UTLanguage:public UTDomain<Language> {
    private:
        string VALID() const { return "Ingles"; };   
        string INVALID() const { return "Klingon"; };                        
        void setUp();                      
};
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

class UTDescription:public UTDomain<Description> {
    private:
        string VALID() const { return "This is a valid description."; };
        string INVALID() const { return "This    ISN'T    a valid description...   ^_^"; };
        void setUp();

};

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
class UTGrade:public UTDomain<Grade> {
    private:
        string VALID() const { return "10"; };
        string INVALID() const { return "13"; };
        void setUp();

};
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

#endif
