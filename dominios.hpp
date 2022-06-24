// 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
#ifndef DOMINIOS_H_INCLUDED
#define DOMINIOS_H_INCLUDED

using namespace std;

#include <string>
#include <stdexcept>


class City {
    private:
        const static string AcceptableCitys[19]; 
        string city;
        void validar(string);
    public:
        void setCity(string);
        string getCity() const;
};

inline string City::getCity() const {
    return city;
}

const string City::AcceptableCitys[19]  = {"Antalya", "Bangkok", "Delhi", "Dubai", "Hong Kong", "Londres", "Macau", "Mumbai", "Paris", "Rio de Janeiro",
                                            "São Paulo", "Seul", "Istambul", "Kuala Lumpur", "Nova Iorque", "Osaka", "Phuket", "Shenzhen", "Tóquio" };


#endif