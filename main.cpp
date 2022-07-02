#include "main.hpp"

#include <regex>
#include <iostream>

using namespace std;

// CIC0197UNB

int main() {

    UTCity testCityA;
    switch (testCityA.run()) {
        case UTCity::SUCCESS: cout << "Success - Cities" << endl;
            break;
        case UTCity::FAILURE: cout << "Failure - Cities" << endl;
            break;
    }
    //-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
    printf("--------------------------\n");

    UTDate testDateA;
    switch (testDateA.run()) {
        case UTDate::SUCCESS: cout << "Success - Date" << endl;
            break;
        case UTDate::FAILURE: cout << "Failure - Date" << endl;
            break;
    }
    //-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
    printf("--------------------------\n");

    UTEmail testEmailA;
    switch (testEmailA.run()) {
        case UTEmail::SUCCESS: cout << "Success - Email" << endl;
            break;
        case UTEmail::FAILURE: cout << "Failure - Email" << endl;
            break;
    }
    //-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
    printf("--------------------------\n");
    
    UTCode testCodeA;
    switch (testCodeA.run()) {
        case UTCode::SUCCESS: cout << "Success - Code" << endl;
            break;
        case UTCode::FAILURE: cout << "Failure - Code" << endl;
            break;
    }
    //-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
    printf("--------------------------\n");
    
    UTCountry testCountryA;
    switch (testCountryA.run()) {
        case UTCountry::SUCCESS: cout << "Success - Country" << endl;
            break;
        case UTCountry::FAILURE: cout << "Failure - Country" << endl;
            break;
    }
    //-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
    printf("--------------------------\n");

    UTName testNameA;
    switch (testNameA.run()) {
        case UTName::SUCCESS: cout << "Success - Name" << endl;
            break;
        case UTName::FAILURE: cout << "Failure - Name" << endl;
            break;
    }

    //-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
    printf("--------------------------\n");
    
    UTPassword testPasswordA;
    switch (testPasswordA.run()) {
        case UTPassword::sucess: cout << "Success - Password" << endl;
            break;
        case UTPassword::failure: cout << "Failure - Password" << endl;
            break;
    }
    
    //-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
    printf("--------------------------\n");
    
    return 0;
}
