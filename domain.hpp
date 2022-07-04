#ifndef domainHppIncluded
#define domainHppIncluded

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

/**
 * Parent Class of all Domains
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

/**
 * Function to access the value of a Domain
 * 
 * Return:
 * 
 * -string 
 */
inline string Domain::getValue() const {
    return value;
}

/**
 * Function to assign the value to a Domain in a specific format
 * 
 * Params:
 * 
 * -string 
 */
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
        const static unordered_set<string> allowedCities;
        void validate(string);
};

/**
 * Portrayal of date.
 * 
 * Format rules:
 * 
 * - Date is valid if in the following format:
 * 
 * -> DD/MES
 * Ex: 08/Mar    
 */
class Date:public Domain {
    private:
        void validate(string);
};

class Email:public Domain {
    private:
        void validate(string);
};

class Code:public Domain {
    private:
        static const char MAXIMUM = '9';
        static const char MINIMUM = '0';
        static const int LENGTH = 11;
        bool luhn(string);
        void validate(string);
};

class Country:public Domain {
    private:
        const static unordered_set<string> allowedCountries;
        void validate(string);
};

class Name:public Domain {
    private:
        void validate(string);
};

class Password:public Domain {
    private:
        static const int LENGTH = 5;
        void validate(string);
};

class Language:public Domain {
    private:
        const static unordered_set<string> allowedLanguages;
        void validate(string);
};

class Description:public Domain {
    private:
        const static unordered_set<char> allowedSymbols;
        void validate(string);
};

class Grade:public Domain {
    private:
        static const int MAXIMUM = 10;
        static const int MINIMUM = 0;
        void validate(string);
};

#endif
