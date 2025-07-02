

#include "Poloshirt.h"
#include <sstream>
#include <iomanip>

// default constructor .

PoloShirt::PoloShirt() : Shirt(), monogram("") {}

// paremterized constructor.

PoloShirt::PoloShirt(const std::string &size, const std::string &color, const std::string &monogram)
    : Shirt(size, color), monogram(monogram) {}

// accessors and mutators
std::string PoloShirt::getMonogram() const
{

    return monogram;
}

void PoloShirt::setMonogram(const std::string &m)
{
    monogram = m;
}

std::string PoloShirt::toString() const{

    std::ostringstream oss;
    oss << Shirt::toString() << " Monogram: " << monogram;
    return oss.str();

}



// Override retailPrice
double PoloShirt::retailPrice() const  {
    double basePrice = Shirt::retailPrice();
    double monogramCost = 5.0;
    for (char c : monogram) {
        if (c != ' ')
            monogramCost += 0.5;
    }
    return basePrice + monogramCost;
}