#include "domainTests.hpp"
#include "domain.hpp"

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
    City *city;
    city = new City();
    try {
        city->setCity("Londres");
        city->getCity();
        printf("Perfection\n"); 
    }
    catch (invalid_argument error) {
        cout << error.what() << endl;
        printf("Only the following citys are allowed:\n");
        City::showAllowedCitys();
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
    Date *date;
    date = new Date();
    try {
        date->setDate("10/Fev");
        date->getDate();
        printf("Perfection\n");
    }
    catch (invalid_argument error) {
        cout << error.what() << endl;
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
    Email *email;
    email = new Email();
    try {
        email->setEmail("rms@gnu.org");
        email->getEmail();
        printf("Perfection\n");
    }
    catch (invalid_argument error) {
        cout << error.what() << endl;
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
    Code *code;
    code = new Code();
    try {
        string test = {"79927398713"};
        code->setCode(test);
        code->getCode();
        printf("Perfection\n");
    }
    catch (invalid_argument error) {
        cout << error.what() << endl;
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
    Country *country;
    country = new Country();
    try {
        string test = {"Brasil"};
        country->setCountry(test);
        country->getCountry();
        printf("Perfection\n");
    }
    catch (invalid_argument error) {
        cout << error.what() << endl;
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
    Name *name;
    name = new Name();
    try {
        name->setName("rms@gnu.org");
        name->getName();
        printf("Perfection\n");
    }
    catch (invalid_argument error) {
        cout << error.what() << endl;
    }

    //-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
    printf("--------------------------\n");

    return 0;
}
