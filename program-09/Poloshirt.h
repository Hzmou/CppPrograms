
    /*
    * This is a header file to declar the PoloShirt class.

    */

    #pragma once
    #include "Shirt.h"
    #include <iostream>
    #include <string>

    class PoloShirt : public Shirt
    {
    private:
        std::string monogram; // monogram for the polo shirt.

    public:
        PoloShirt();                                                                  // default constructor
        PoloShirt(const std::string &size, const std::string &color, const std::string& monogram = ""); // parameterized constructor

        // accessors and mutators
        std::string getMonogram() const;
        void setMonogram(const std::string &m);

        // override toString
        std::string toString() const;

        // override retailPrice
        double retailPrice() const ;
    };