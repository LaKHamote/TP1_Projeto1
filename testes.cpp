#include "testes.hpp"
#include "dominios.hpp"

using namespace std;

void TUCity::setUp(){
    city = new City();
}

void TUCity::testar(string city) {
    this->city = new City();
    try{
        this->city->setCity(city);
        this->city->getCity();
    }
    catch (invalid_argument error) {
        cout << error.what() << endl;
        cout << "Only the following citys are allowed:\n";
        City::showAllowedCitys();
    }
}


