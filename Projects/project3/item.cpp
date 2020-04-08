#include "item.h"
#include<iostream>
using std::ostream; using std::endl;
#include<string>
using std::string;

Item::Item(const Item& i){
    name_ = i.name();
    quantity_ = i.quantity();
    price_ = i.price();
}

void Item::name(string s){
    name_ = s;
}

void Item::quantity(long q){
    quantity_ = q;
}

void Item::price(long p){
    price_ = p;
}

Item& Item::operator=(const Item& i){
    name_ = i.name();
    quantity_ = i.quantity();
    price_ = i.price();
    return *this;
}

ostream& operator<<(ostream& o, const Item& i){
    o << "Name: " << i.name_ << endl <<
         "Quantity: " << i.quantity_ << endl <<
         "Price: " << i.price_ << endl;

    return o;
}