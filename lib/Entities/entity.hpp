#ifndef entityHppIncluded
#define entityHppIncluded

#include "../Domains/domain.hpp"
#include <iostream>
#include <string>
#include <stdexcept>
#include <unordered_set>

using namespace std;

/**
 * Portrayal of User that is composed of 6 classes:
 * 
 * -Name
 * 
 * -Email
 * 
 * -Password
 * 
 * -Language
 * 
 * -Date
 * 
 * -Description
 * 
 * Author: 211038262
 */
class User {
    private:
        Name name;
        Email email;
        Password password;
        Language language;
        Date date;
        Description description;
    public:
        Name getName() const { return name; };
        Email getEmail() const { return email; };
        Password getPassword() const { return password; };
        Language getLanguage() const { return language; };
        Date getDate() const { return date; };
        Description getDescription() const { return description; };
        void setName(const Name& name) { this->name = name; };
        void setEmail(const Email& email) { this->email = email; };
        void setPassword(const Password& password) { this->password = password; };
        void setLanguage(const Language& language) { this->language = language; };
        void setDate(const Date& date) { this->date = date; };
        void setDescription(const Description& description) { this->description = description; };
};

/**
 * Portrayal of an Accommodation that is composed of 6 classes:
 * 
 * -Code
 * 
 * -City
 * 
 * -Country
 * 
 * -Grade
 * 
 * -Description
 * 
 * Author: 211038262
 */
class Accommodation {
    private:
        Code code;
        City city;
        Country country;
        Grade grade;
        Description description;
        Email email;                    
    public:
        Code getCode() const { return code; };
        City getCity() const { return city; };
        Country getCountry() const { return country; };
        Grade getGrade() const { return grade; };
        Description getDescription() const { return description; };
        Email getEmail() const {return email; };
        void setCode(const Code& code) { this->code = code; };
        void setCity(const City& city) { this->city = city; };
        void setCountry(const Country& country) { this->country = country; };
        void setGrade(const Grade& grade) { this->grade = grade; };
        void setDescription(const Description& description) { this->description = description; };
        void setEmail(const Email& email) {this->email = email; };
};

/**
 * Portrayal of an Accommodation that is composed of 6 classes:
 * 
 * -Code
 * 
 * -City
 * 
 * -Country
 * 
 * -Grade
 * 
 * -Description
 * 
 * Author: 211026673
 */
class Rating {
    private:
        Code code;
        Grade grade;
        Description description;
        Email email;
        Code accommodation_code;
    public:
        Code getCode() const { return code; };
        Grade getGrade() const { return grade; };
        Description getDescription() const { return description; };
        Email getEmail() const {return email; };
        Code getAccommodationCode() const {return accommodation_code; };
        void setCode(const Code& code) { this->code = code; };
        void setGrade(const Grade& grade) { this->grade = grade; };
        void setDescription(const Description& description) { this->description = description; };
        void setEmail(const Email& email) {this->email = email; };
        void setAccommodationCode(const Code& accommodation_code) {this->accommodation_code = accommodation_code; };
};

#endif