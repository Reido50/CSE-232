#ifndef ITEM
#define ITEM

#include<iostream>
using std::ostream;
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
    Item(const Item& i);

    // getters
    string name() const {return name_;}
    long quantity() const {return quantity_;}
    long price() const {return price_;}

    // setters
    void name(string s);
    void quantity(long q);
    void price(long p);

    // overloaded operator= method
    Item& operator=(const Item& i);

    // friends
    friend ostream& operator<<(ostream& o, const Item& i);
};

ostream& operator<<(ostream& o, const Item& i);

#endif