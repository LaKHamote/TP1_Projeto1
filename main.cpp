#include "testes.cpp"
#include "dominios.cpp"
// #include "testes.hpp"
// #include "dominios.hpp"

#include <iostream>

using namespace std;

// CIC0197UNB

int main() {
    TUCity testA;
    testA.simpleTest("BSB");
    testA.simpleTest("Londres");
    switch(testA.run()) {
        case TUCity::success: cout << "Success - City" << endl;
                                break;
        case TUCity::failure: cout << "Failure - City" << endl;
                                break;
    }

    return 0;
};