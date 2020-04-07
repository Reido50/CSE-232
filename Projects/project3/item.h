#ifndef ITEM
#define ITEM

#include "store.h"
#include<string>
using std::string;

class Item{
private:
    string name_ = "";
    long quantity_ = 0;
    long price_ = 0;
    
public:
    // constructors
    Item() = default;
    Item(string n, long q, long p): name_(n), quantity_(q), price_(p) {};
    Item(const Item& i): name_()

    // getters
    string name() const {return name_;}
    long quantity() const {return quantity_;}
    long price() const {return price_;}

};


#endif