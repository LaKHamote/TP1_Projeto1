#ifndef domainTestHppIncluded
#define domainTestHppIncluded

#include "domain.hpp"
#include <string>

using namespace std;

/**
 * Parent template class of all tests for domains
 * 
 * Template Params:
 * -Any declared Domain 
 * 
 * Author: 211038262
 */
template <typename DomainClass>
class UTDomain {
    protected:
        DomainClass *domain;
        virtual ~UTDomain() {};
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
        /**
         * Method to call all the test cases and inform SUCCESS or FAILURE with a test coverage of one valid and invalid value each
         * 
         * Return: int 
         */
        virtual int run();
};

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

/**
 * Unity Test for Domain City
 * Author: 211038262
 */
class UTCity:public UTDomain<City> {
    private:
        string VALID() const { return "Londres"; };
        string INVALID() const { return "Wakanda"; };
        void setUp();
};
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

/**
 * Unity Test for Domain Date
 * Author: 211038262
 */
class UTDate:public UTDomain<Date> {
    private:
        string VALID() const { return "15/Fev"; };
        string INVALID() const { return "40/Mar"; };
        void setUp();
};

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

/**
 * Unity Test for Domain Email
 * Author:
 */
class UTEmail:public UTDomain<Email> {
    private:
        string VALID() const { return "torvalds@linux-foundation.org"; };
        string INVALID() const { return "This is an invalid email format.";};
        void setUp();
};

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

/**
 * Unity Test for Domain Code
 * Author: 190043474
 */
class UTCode:public UTDomain<Code> {
    private:                           
        string VALID() const { return "79927398713"; };   
        string INVALID() const { return "79927398712"; };
        static const int LENGHT = 11;
        void setUp();                            
};

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

/**
 * Unity Test for Domain Country
 * Author: 190043474
 */
class UTCountry:public UTDomain<Country> {
    private:
        string VALID() const { return "Turquia"; };
        string INVALID() const { return "Inglaterra"; };
        static const int LENGHT = 12;
        void setUp(); 
};

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

/**
 * Unity Test for Domain Name
 * Author:
 */
class UTName:public UTDomain<Name> {
    private:
        string VALID() const { return "Linus Torvalds"; };
        string INVALID() const { return "riCharD StaLLmaN"; };
        void setUp();

};

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

/**
 * Unity Test for Domain Password
 * Author: 190043474
 */
class UTPassword:public UTDomain<Password> {
    private:
        string VALID() const { return "aA&22"; };   
        string INVALID() const { return "manga"; };   
        static const int LENGHT = 5;
        void setUp();                      
};

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

/**
 * Unity Test for Domain Language
 * Author: 211038262
 */
class UTLanguage:public UTDomain<Language> {
    private:
        string VALID() const { return "Ingles"; };   
        string INVALID() const { return "Klingon"; };                        
        void setUp();                      
};

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

/**
 * Unity Test for Domain Description
 * Author:
 */
class UTDescription:public UTDomain<Description> {
    private:
        string VALID() const { return "This is a valid description."; };
        string INVALID() const { return "This    ISN'T    a valid description...   ^_^"; };
        void setUp();

};

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

/**
 * Unity Test for Domain Grade
 * Author: 211038262
 */
class UTGrade:public UTDomain<Grade> {
    private:
        string VALID() const { return "10"; };
        string INVALID() const { return "13"; };
        void setUp();

};

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

#endif
