#ifndef domainHppIncluded
#define domainHppIncluded

#include <iostream>
#include <string>
#include <stdexcept>
#include <unordered_set>

using namespace std;

/**
 * Parent Class
 */
class Domain {
    protected:
        string value;
        virtual ~Domain() {};
        virtual void validate(string) {};
    public:
        void setValue(string);
        string getValue() const;
};

inline string Domain::getValue() const {
    return value;
}

inline void Domain::setValue(string value) {
    validate(value);
    this->value = value;
}

/**
 * Portrayal of city.
 * 
 * Format rules:
 * 
 * - City is valid if among the following: 
 *          Antalya, Bangkok, Delhi, Dubai, Hong Kong, Londres, Macau, Mumbai, Paris, Rio de Janeiro,
 *          São Paulo, Seul, Istambul, Kuala Lumpur, Nova Iorque, Osaka, Phuket, Shenzhen, Tóquio.
 */
class City:public Domain {
    private:
        const unordered_set<string> allowedCitys = { "Antalya", "Bangkok", "Delhi", "Dubai", "Hong Kong", "Londres", "Macau", "Mumbai", "Paris", "Rio de Janeiro",
                                                            "Sao Paulo", "Seul", "Istambul", "Kuala Lumpur", "Nova Iorque", "Osaka", "Phuket", "Shenzhen", "Toquio" };
        void validate(string);
};

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

class Date:public Domain {
    private:
        void validate(string);
};

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

class Email:public Domain {
    private:
        void validate(string);
};

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

class Code:public Domain {
    private:
        static const char MAXIMUM = '9';
        static const char MINIMUM = '0';
        static const int LENGHT = 11;
        bool luhn(string);
        void validate(string);
};

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

class Country:public Domain {
    private:
        static const int LENGHT = 12;
        const string valids[LENGHT] = {"Estados Unidos", "Brasil", "China", "Coreia do Sul", "Emirados", "França", "India", "Japao", "Malasia", "Reino Unido", "Tailandia", "Turquia"};
        void validate(string);
};

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

class Name:public Domain {
    private:
        void validate(string);
};

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

class Password:public Domain {
    private:
        static const int LENGHT = 5;
        void validate(string);
};

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------


#endif
