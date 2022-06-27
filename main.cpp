#include "testes.cpp"
#include "dominios.cpp"
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
        date->setDate("32/Fev");
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

    return 0;
}