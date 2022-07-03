#ifndef entityHppIncluded
#define entityHppIncluded

#include "domain.hpp"
#include <iostream>
#include <string>
#include <stdexcept>
#include <unordered_set>

using namespace std;

/**
 * Entity parent Class
 */
class Entity {
    protected:
    public:
};

class User {
    private:
        Name name;
        Email email;
        Password password;
        Language language;
        Date date;
        //Description description;
    public:
        Name getName() const { return name; };
        Email getEmail() const { return email; };
        Password getPassword() const { return password; };
        Language getLanguage() const { return language; };
        Date getDate() const { return date; };
        //Description getDescription() const { return description; };
        void setName(const Name& name) { this->name = name; };
        void setEmail(const Email& email) { this->email = email; };
        void setPassword(const Password& password) { this->password = password; };
        void setLanguage(const Language& language) { this->language = language; };
        void setDate(const Date& date) { this->date = date; };
        //void setDescription(const Description& description) { this->description = description; };
};







#endif