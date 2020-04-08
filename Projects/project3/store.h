/*  Reid Harry
    4/7/2020

    4 Stores:
    Local Grocery
    East Lansing
    Apples,10,$4.76
    Sandwich,2,$1.99
    Olive Bread,3,$2.99
    Milk,7,$1.25
    Eggs,40,$0.78
    Candy,4,$0.51

    Electronics R Here
    Ann Arbor
    Bargain Phone,2,$200.00
    S Phone,4,$650.00
    Fruit Phone,2,$700.00

    Corner Store
    East Lansing
    Milk,30,$2.00
    Eggs,2,$0.50
    Candy,6,$1.00
    Soda,5,$1.56
    Bargain Phone,3,$185.00

    Sparty's
    East Lansing
    Candy,10,$0.85
    Soda,4,$1.50
    Sandwich,3,$2.99
    The first line of each store is the store's name, the next line is the store's location. The rest of the lines (before the blank 
    line) is the inventory.

    For each inventory line, there is the item's name, the quantity (the amount of that item the store has in stock), and the price. 
    For example, the "Corner Store" has two eggs for sale and each egg costs fifty cents.

    After reading in the store information, your program should output some summary information (to confirm it read in the data properly).

    Here's what should be outputed:

    Store Related Information (ordered by in-file order):
    There are 4 store(s).
    Local Grocery has 6 distinct items.
    Electronics R Here has 3 distinct items.
    Corner Store has 5 distinct items.
    Sparty's has 3 distinct items.
*/

#ifndef STORE
#define STORE

#include "item.h"
#include<string>
using std::string;
#include<vector>
using std::vector;

class Store{
private:
    string name_;
    string location_;
    vector<Item> items_;

public:
    // constructors
    Store(string n, string l): name_(n), location_(l) {};
    Store(const Store& s);

    // getters
    string name() const {return name_;}
    string location() const {return location_;}
    vector<Item> items() const {return items_;}
    long getItemsSize();

    // setters
    void name(string n);
    void location(string l);
    void addItem(string n, long q, long p);
    void addItem(const Item& i);

    // friends
    friend ostream& operator<<(ostream& o, const Store& s);
};

ostream& operator<<(ostream& o, const Store& s);

#endif