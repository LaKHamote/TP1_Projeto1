#include "main.hpp"
#include <regex>
#include <iostream>

using namespace std;

// CIC0197UNB

int main() {

    UTCity testCityA;
    switch (testCityA.run()) {
        case UTCity::SUCCESS: cout << "Success: City" << endl;
            break;
        case UTCity::FAILURE: cout << "Failure: City" << endl;
            break;
    }

    UTDate testDateA;
    switch (testDateA.run()) {
        case UTDate::SUCCESS: cout << "Success: Date" << endl;
            break;
        case UTDate::FAILURE: cout << "Failure: Date" << endl;
            break;
    }

    UTEmail testEmailA;
    switch (testEmailA.run()) {
        case UTEmail::SUCCESS: cout << "Success: Email" << endl;
            break;
        case UTEmail::FAILURE: cout << "Failure: Email" << endl;
            break;
    }

    UTCode testCodeA;
    switch (testCodeA.run()) {
        case UTCode::SUCCESS: cout << "Success: Code" << endl;
            break;
        case UTCode::FAILURE: cout << "Failure: Code" << endl;
            break;
    }

    UTCountry testCountryA;
    switch (testCountryA.run()) {
        case UTCountry::SUCCESS: cout << "Success: Country" << endl;
            break;
        case UTCountry::FAILURE: cout << "Failure: Country" << endl;
            break;
    }

    UTName testNameA;
    switch (testNameA.run()) {
        case UTName::SUCCESS: cout << "Success: Name" << endl;
            break;
        case UTName::FAILURE: cout << "Failure: Name" << endl;
            break;
    }

    UTPassword testPasswordA;
    switch (testPasswordA.run()) {
        case UTPassword::SUCCESS: cout << "Success: Password" << endl;
            break;
        case UTPassword::FAILURE: cout << "Failure: Password" << endl;
            break;
    }

    UTLanguage testLanguageA;
    switch (testLanguageA.run()) {
        case UTLanguage::SUCCESS: cout << "Success: Language" << endl;
            break;
        case UTLanguage::FAILURE: cout << "Failure: Language" << endl;
            break;
    }

    UTUser testUserA;
    switch (testUserA.run()) {
        case UTUser::SUCCESS: cout << "Success: User" << endl;
            break;
        case UTUser::FAILURE: cout << "Failure: User" << endl;
            break;
    }

    return 0;
}
