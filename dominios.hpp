// 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
#ifndef DOMINIOS_H_INCLUDED
#define DOMINIOS_H_INCLUDED

using namespace std;

#include <string>
#include <stdexcept>


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

const string City::allowedCitys[19] = {"Antalya", "Bangkok", "Delhi", "Dubai", "Hong Kong", "Londres", "Macau", "Mumbai", "Paris", "Rio de Janeiro",
                                        "Sao Paulo", "Seul", "Istambul", "Kuala Lumpur", "Nova Iorque", "Osaka", "Phuket", "Shenzhen", "Toquio" };


#endif