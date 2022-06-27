#ifndef TESTES_H_INCLUDED
#define TESTES_H_INCLUDED

#include "dominios.hpp"

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
        const static string validValue;
        const static string invalidValue;
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

#endif