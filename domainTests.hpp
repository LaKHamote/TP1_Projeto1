#ifndef testHppIncluded
#define testHppIncluded

#include "domain.hpp"

#include <string>

using namespace std;

class UTCity {
    private:
        const static string validValue;
        const static string invalidValue;
        City *city;
        bool response;
        void setUp();
        void successScenario();
        void failureScenario();
        void tearDown();
    public:
        const static int success = 1;
        const static int failure = 0;
        int run();
};

const string UTCity::validValue = "Londres";
const string UTCity::invalidValue = "Wakanda";
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------


class UTDate {
    private:
        const static string validValue;
        const static string invalidValue;
        Date *date;
        bool response;
        void setUp();
        void successScenario();
        void failureScenario();
        void tearDown();
    public:
        const static int success = 1;
        const static int failure = 0;
        int run();
};

const string UTDate::validValue = "15/Fev";
const string UTDate::invalidValue = "40/Mar";

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

class UTEmail {
    private:
        const string validValue   = "torvalds@linux-foundation.org";
        const string invalidValue = "This is an invalid email format.";
        Email *email;
        bool response;
        void setUp();
        void successScenario();
        void failureScenario();
        void tearDown();
    public:
        const static int success = 1;
        const static int failure = 0;
        int run();
};

// const string UTEmail::validValue = "torvalds@linux-foundation.org";
// const string UTEmail::invalidValue = "This is an invalid email format.";

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

class UTCode {
    private:
        static const int LENGHT = 11;
        const string VALID = {"79927398713"};   
        const string INVALID = {"79927398712"};   
        Code *code;                         
        int state;                             
        void setUp();                           
        void tearDown();                        
        void sucessScenario();            
        void failureScenario();              

    public:
        const static int sucess  =  0;          
        const static int failure = -1;          
        int run();                              
};

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

class UTCountry {
    private:
        static const int LENGHT = 12;
        const string VALID = {"Turquia"};   // Definição de constante para evitar número mágico.
        const string INVALID = {"Inglaterra"};   // Definição de constante para evitar número mágico.
        Country *country;                         // Referência para unidade em teste.
        int state;                             // Estado do teste.
        void setUp();                           // Método para criar unidade em teste.
        void tearDown();                        // Método para destruir unidade em teste.
        void sucessScenario();            // Cenário de teste.
        void failureScenario();              // Cenário de teste.

    public:
        const static int sucess  =  0;          // Definição de constante para reportar resultado de teste.
        const static int failure = -1;          // Definição de constante para reportar resultado de teste.
        int run();                              // Método para executar teste.
};

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

#endif
