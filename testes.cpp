#include "testes.hpp"

using namespace std;

void TUCity::setUp(){
    city = new City();
}

string TUCity::testar(string city){
    this->city = new City();
    try{
        this->city->setCity(city);
    }
    catch (invalid_argument &error){
        printf("error");
    }
    
    
    return this->city->getCity();
}


