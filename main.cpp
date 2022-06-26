#include "testes.cpp"
#include "dominios.cpp"

#include <iostream>

using namespace std;

// CIC0197UNB

int main() {

    TUCity testCityA;
    switch(testCityA.run()) {
        case TUCity::success: cout << "Success - City" << endl;
                                break;
        case TUCity::failure: cout << "Failure - City" << endl;
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

    TUDate testDateA;
    switch(testDateA.run()) {
        case TUDate::success: cout << "Success - Date" << endl;
                                break;
        case TUDate::failure: cout << "Failure - Date" << endl;
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














    return 0;
};