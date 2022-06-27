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
        date->setDate("30/Fev");
        date->getDate();
        printf("Perfection\n");
    }
    catch (invalid_argument error) {
        cout << error.what() << endl;
    }
    catch (out_of_range error) {
        cout << error.what() << endl;
    }
    //-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
    printf("--------------------------\n");


    const regex pattern("(0[1-9]|[12][0-9]|3[01])/(Jan|Fev|Mar|Abr|Mai|Jun|Jul|Ago|Set|Out|Nov|Dez)");
    cout << regex_match("30/Fev", pattern) << endl;















    return 0;
};