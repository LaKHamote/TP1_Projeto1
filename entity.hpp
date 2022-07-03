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

/**
 * Portrayal of User
 */
class User {
    private:
        Name name;
        Email email;
        Password password;
        Language language;
        Date date;
        //Description description;
    public:
        string getName() const { return name.getValue(); };
        string getEmail() const { return email.getValue(); };
        string getPassword() const { return password.getValue(); };
        string getLanguage() const { return language.getValue(); };
        string getDate() const { return date.getValue(); };
        //string getDescription() const { return description.getValue(); };
        void setName(string name) { this->name.setValue(name); };
        void setEmail(string  email) { this->email.setValue(email); };
        void setPassword(string  password) { this->password.setValue(password); };
        void setLanguage(string  language) { this->language.setValue(language); };
        void setDate(string  date) { this->date.setValue(date); };
        //void setDescription(string  description) { this->description.setValue(description; };
};







#endif