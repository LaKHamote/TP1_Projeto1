#include "main.hpp"

#include <regex>
#include <iostream>

using namespace std;

// CIC0197UNB

int main() {

    UTCity testCityA;
    switch (testCityA.run()) {
        case UTCity::success: cout << "Success - City" << endl;
                                break;
        case UTCity::failure: cout << "Failure - City" << endl;
                                break;
    }
    //-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
    printf("--------------------------\n");

    UTDate testDateA;
    switch (testDateA.run()) {
        case UTDate::success: cout << "Success - Date" << endl;
                                break;
        case UTDate::failure: cout << "Failure - Date" << endl;
                                break;
    }
    //-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
    printf("--------------------------\n");

    UTEmail testEmailA;
    switch (testDateA.run()) {
        case UTDate::success: cout << "Success - Email" << endl;
            break;
        case UTDate::failure: cout << "Failure - Email" << endl;
            break;
    }
    //-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
    printf("--------------------------\n");
    
    UTCode testCodeA;
    switch (testCodeA.run()) {
        case UTCode::sucess: cout << "Success - Code" << endl;
            break;
        case UTCode::failure: cout << "Failure - Code" << endl;
            break;
    }
    //-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
    printf("--------------------------\n");
    
    UTCountry testCountryA;
    switch (testCountryA.run()) {
        case UTCountry::sucess: cout << "Success - Country" << endl;
            break;
        case UTCountry::failure: cout << "Failure - Country" << endl;
            break;
    }
    //-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
    printf("--------------------------\n");

    UTName testNameA;
    switch (testNameA.run()) {
        case UTDate::success: cout << "Success - Name" << endl;
            break;
        case UTDate::failure: cout << "Failure - Name" << endl;
            break;
    }

    //-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

    return 0;
}
