#ifndef domainHppIncluded
#define domainHppIncluded

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

/**
 * Portrayal of city.
 * 
 * Format rules:
 * 
 * - City is valid if among the following: 
 *          Antalya, Bangkok, Delhi, Dubai, Hong Kong, Londres, Macau, Mumbai, Paris, Rio de Janeiro,
 *          São Paulo, Seul, Istambul, Kuala Lumpur, Nova Iorque, Osaka, Phuket, Shenzhen, Tóquio.
 */
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

class Code {
    private:
        static const char MAXIMUM = '9';
        static const char MINIMUM = '0';
        static const int LENGHT = 11;
        string code;
        void validate(string);
        bool luhn(string);
    public:
        void setCode(string);
        inline string getCode() const;
};

inline string Code::getCode() const{
    return code;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

class Country {
    private:
        static const int LENGHT = 12;
        const string valids[LENGHT] = {"Estados Unidos", "Brasil", "China", "Coreia do Sul", "Emirados", "França", "India", "Japao", "Malasia", "Reino Unido", "Tailandia", "Turquia"};
        string country;
        void validate(string);
    public:
        void setCountry(string);
        string getCountry() const;
};

inline string Country::getCountry() const{
    return country;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

class Name {
    private:
        string name = "";
        void validate(string);
    public:
        void setName(string);
        string getName() {
            return name;
        }
};

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------


#endif
