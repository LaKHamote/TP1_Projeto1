#ifndef domainHppIncluded
#define domainHppIncluded

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

/**
 * Parent Class of all Domains
 * Author: 211038262
 */
class Domain {
    protected:
        string value;
        virtual ~Domain() {};
        virtual void validate(string) = 0;
    public:
        void setValue(string);
        string getValue() const;
};

/**
 * Method to assign the value to a Domain in a specific format
 * Author: 211038262
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
 * Author: 211038262
 *
 * Return:
 *
 * -string
 */
inline string Domain::getValue() const {
    return value;
}

/**
 * City Domain
 * Author: 211038262
 *
 * It contains a valid city value.
 *
 * Parameters:
 *      string - a string containing the city.
 *
 * The format rules are:
 *      - City is valid if among the following, without considering accentuation:
 *          Antalya, Bangkok, Delhi, Dubai, Hong Kong, Londres, Macau, Mumbai, Paris, Rio de Janeiro,
 *          São Paulo, Seul, Istambul, Kuala Lumpur, Nova Iorque, Osaka, Phuket, Shenzhen, Tóquio.
 *
 * Exceptions:
 *      throws std::invalid_argument if the parameter doesn't follow any of the rules.
*/
class City:public Domain {
    private:
        const static unordered_set<string> allowedCities;
        void validate(string);
};

/**
 * Date Domain
 * Author: 211038262
 *
 * It contains a valid date value.
 *
 * Parameters:
 *      string - a string containing the date.
 *
 * The format rules are:
 *      Format: DD/MTH
 *      DD are two digits from 01 to 31.
 *      MTH is an abbreviated month in (Jan, Fev, Mar, Abr, Mai, Jun, Jul, Ago, Set, Out, Nov, Dez).
 *
 * Exceptions:
 *      throws std::invalid_argument if the parameter doesn't follow any of the rules.
*/
class Date:public Domain {
    private:
        void validate(string);
};

/**
 * Email Domain
 * Author: 211026673
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

/**
 * Code Domain
 * Author: 190043474
 *
 * It contains a valid code value.
 *
 * Parameters:
 *      string - a string containing the code.
 *
 * The format rules are:
 *      DDDDDDDDDDX
 *      D is digit from 0 to 9.
 *      X is check digit calculated using luhn's algorithm.
 *
 * Exceptions:
 *      throws std::invalid_argument if the parameter doesn't follow any of the rules.
*/
class Code:public Domain {
    private:
        static const char MAXIMUM = '9';
        static const char MINIMUM = '0';
        static const int LENGTH = 11;
        bool luhn(string);
        void validate(string);
};

/**
 * Country Domain
 * Author: 190043474
 *
 * It contains a valid country value.
 *
 * Parameters:
 *      string - a string containing the country.
 *
 * The format rules are:
 *      - Country is valid if among the following, without considering accentuation:
 *          Estados Unidos, Brasil, China, Coreia do Sul, Emirados, França, Índia, Japão, Malásia, Reino Unido,
 *          Tailândia, Turquia
 *
 * Exceptions:
 *      throws std::invalid_argument if the parameter doesn't follow any of the rules.
*/
class Country:public Domain {
    private:
        const static unordered_set<string> allowedCountries;
        void validate(string);
};

/**
 * Name Domain
 * Author: 211026673
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

/**
 * Password Domain
 * Author: 190043474
 *
 * It contains a password code value.
 *
 * Parameters:
 *      string - a string containing the password.
 *
 * The format rules are:
 *      XXXXX Format
 *      Each X character is letter (form 'A' to 'Z' or from 'a' to 'z'), digit (from 0 to 9), or special character in (!#$%&).
 *      There is at least one letter (upper or lowercase), one digit, and one special character.
 *
 * Exceptions:
 *      throws std::invalid_argument if the parameter doesn't follow any of the rules.
*/
class Password:public Domain {
    private:
        static const int LENGTH = 5;
        void validate(string);
};


/**
 * Language Domain
 * Author: 211038262
 *
 * It contains a valid language value.
 *
 * Parameters:
 *      string - a string containing the language.
 *
 * The format rules are:
 *      - Language is valid if among the following, without considering accentuation:
 *          Inglês, Chinês, Mandarim, Hindi, Espanhol, Francês, Árabe, Bengali, Russo, Português, Indonésio
 *
 * Exceptions:
 *      throws std::invalid_argument if the parameter doesn't follow the rule.
*/
class Language:public Domain {
    private:
        const static unordered_set<string> allowedLanguages;
        void validate(string);
};

/**
 * Description Domain
 * Author: 211026673
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

/**
 * Grade Domain
 * Author: 211038262
 *
 * It contains a valid grade value.
 *
 * Parameters:
 *      string - a string containing the grade.
 *
 * The format rules are:
 *      A number from 0 to 10.
 *
 * Exceptions:
 *      throws std::invalid_argument if the parameter doesn't follow the rule.
*/
class Grade:public Domain {
    private:
        static const int MAXIMUM = 10;
        static const int MINIMUM = 0;
        void validate(string);
};

#endif
