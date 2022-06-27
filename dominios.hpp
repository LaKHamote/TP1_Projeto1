#ifndef DOMINIOS_H_INCLUDED
#define DOMINIOS_H_INCLUDED

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class City {
    private:
        const static string allowedCitys[19];
        string city;
        void validar(string);
    public:
        static void showAllowedCitys();
        void setCity(string);
        string getCity() const;
};

inline string City::getCity() const {
    return city;
}

inline void City::showAllowedCitys() {
    for(auto const& value : allowedCitys)
        cout << value << "; ";
    cout << endl;
}


const string City::allowedCitys[19] = {"Antalya", "Bangkok", "Delhi", "Dubai", "Hong Kong", "Londres", "Macau", "Mumbai", "Paris", "Rio de Janeiro",
                                        "Sao Paulo", "Seul", "Istambul", "Kuala Lumpur", "Nova Iorque", "Osaka", "Phuket", "Shenzhen", "Toquio" };
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

class Date {
    private:
        const static string allowedMonths[12];
        const static int lowRangeDays = 1;
        const static int highRangeDays = 31;
        string date;
        int day;
        string month;
        void validar(string);
    public:
        void setDate(string);
        string getDate() const;
};

inline string Date::getDate() const {
    return date;
}

const string Date::allowedMonths[12] = {"Jan", "Fev", "Mar", "Abr", "Mai", "Jun", "Jul", "Ago", "Set", "Out", "Nov", "Dez"};

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

class Email {
    private:
        string email = "";
        void validate(string);
    public:
        bool setEmail(string);
        string getEmail() const {
            return email;
        }
};

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

#endif