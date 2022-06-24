#ifndef TESTES_H_INCLUDED
#define TESTES_H_INCLUDED

#include "dominios.hpp"

#include <string>


using namespace std;

class TUCity {
    private:
        // const static string VALID;
        // const static string INVALID;
        City *city;
        void setUp();
    public:
        string testar(string);   
        bool run();
        
};

#endif