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
 * Method to assign the value to a Domain in a specific format
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
 * Method to access the value of a Domain
 * 
 * Return:
 * 
 * -string 
 */
inline string Domain::getValue() const {
    return value;
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

/**
 * Email Domain
 * 
 * It contains a valid email value.
 * 
 * Parameters:
 *      string - a string containing the email.
 * 
 * The format rules are:
 *      AAAA@BBBB.CCC
 *      Where AAAA can be alphanumeric characters and the symbols '.', '-', '_';
 *      AAAA must be followed by '@'.
 *      BBBB can be alphanumeric characters and the symbols '.', '-', '_';
 *      BBBB must end with a '.';
 *      CCCC can only have alphanumeric characters.
 *      
 * Exceptions:
 *      throws std::invalid_argument if the parameter doesn't follow any of the rules.
*/
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

/**
 * Name Domain
 * 
 * It contains a valid name value.
 * 
 * Parameters:
 *      string - a string containing the name.
 * 
 * The format rules are:
 *      30 chars. max;
 *      The parameter can't end with a whitespace;
 *      It also can't have multiple whitespaces;
 *      The characters can only be alphabetic;
 *      Each name must start with a capitalized letter;
 *      All the letters for each name/surname, apart from the first one, must not be capitalized;
 *      Names are separated by 1 (one) whitespace.
 * 
 * Exceptions:
 *      throws std::invalid_argument if the parameter doesn't follow any of the rules.
*/
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

/**
 * Description Domain
 * 
 * It contains a simple description.
 * 
 * Parameters:
 *      string - a string containing the description.
 * 
 * The format rules are:
 *      40 chars max;
 *      Only alfabetic characters and symbols;
 *      The allowed symbols are: ' ', '.', ',', ';', ':', '?', '!', '-';
 *      Sequential sumbols or spaces are not allowed.
 *      
 * Exceptions:
 *      throws std::invalid_argument if the parameter doesn't follow any of the rules.
*/
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
