#include "store.h"
#include "item.h"
#include<iostream>
using std::ostream; using std::endl;
#include<string>
using std::string;
#include<algorithm>
using std::find_if;

Store::Store(const Store& s){
    name_ = s.name();
    location_ = s.location();
    items_ = s.items();
}

long Store::getItemsSize(){
    return static_cast<long>(items_.size());
}

void Store::name(string n){
    name_ = n;
}

void Store::location(string l){
    location_ = l;
}

void Store::addItem(string n, long q, long p){
    Item i(n, q, p);
    items_.push_back(i);
}

void Store::addItem(const Item& i){
    items_.push_back(i);
}

ostream& operator<<(ostream& o, const Store& s){
    o << "Name: " << s.name_ << endl <<
         "Location: " << s.location_ << endl <<
         "Items: " << endl;

    for(Item i : s.items_){
        o << i << endl;
    }

    return o;
}