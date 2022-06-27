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
        void validate(string);
    public:
        static void showAllowedCitys();
        void setCity(string);
        string getCity() const;
};

inline string City::getCity() const {
    return city;
}

inline void City::setCity(string city) {
    validate(city);
    this->city = city;
}

inline void City::showAllowedCitys() {
    for (auto const& value : allowedCitys)
        cout << value << "; "; 
    cout << endl;
}

const string City::allowedCitys[19] = {"Antalya", "Bangkok", "Delhi", "Dubai", "Hong Kong", "Londres", "Macau", "Mumbai", "Paris", "Rio de Janeiro",
                                        "Sao Paulo", "Seul", "Istambul", "Kuala Lumpur", "Nova Iorque", "Osaka", "Phuket", "Shenzhen", "Toquio" };
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

class Date {
    private:
        string date;
        void validate(string);
    public:
        void setDate(string);
        string getDate() const;
};

inline string Date::getDate() const {
    return date;
}

inline void Date::setDate(string date) {
    validate(date);
    this->date = date;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

class Email {
    private:
        string email;
        void validate(string);
    public:
        void setEmail(string);
        string getEmail() const {
            return email;
        }
};

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

#endif