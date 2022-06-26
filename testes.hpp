#ifndef TESTES_H_INCLUDED
#define TESTES_H_INCLUDED

#include "dominios.hpp"

#include <string>

using namespace std;

class TUCity {
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
        bool run();
};

const string TUCity::validValue = "Londres";
const string TUCity::invalidValue = "Wakanda";
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------


class TUDate {
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
        bool run();
};

const string TUDate::validValue = "15/Fev";
const string TUDate::invalidValue = "40/Mar";




#endif