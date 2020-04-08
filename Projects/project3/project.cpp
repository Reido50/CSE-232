/*  Reid Harry
    4/4/2020

    This program uses store.h/store.cpp and item.h/item.cpp
*/

#include "store.h"
#include "item.h"
#include<iostream>
using std::cin; using std::cout; using std::getline; using std::stoi; using std::endl; using std::fixed;
#include<iomanip>
using std::setprecision;
#include<string>
using std::string;
#include<vector>
using std::vector;
#include<sstream>
using std::istringstream; using std::ostringstream;
#include<utility>
using std::pair; using std::make_pair;
#include<map>
using std::map;
#include<algorithm>
using std::transform; using std::sort;

// Fills the reference to an Item with a name and quantity taken from input.
// This is used when getting the shopping list items
void getItemFromInput(Item& i){
    string item_name;
    long item_quantity;

    string line;
    getline(cin, line);

    istringstream iss(line);

    iss >> item_quantity;
    iss.get();
    getline(iss, item_name);

    i.name(item_name);
    i.quantity(item_quantity);
}

// Adds a new element to a reference vector of Stores with name, location, and items taken from input
// This is used when populating the vector of Stores called "stores" used throughout the program
void addStoreFromInput(vector<Store>& s_vec){
    string store_name, store_location;
    string item_name;
    long item_quantity;
    double item_price;
    getline(cin, store_name);
    getline(cin, store_location);
    Store new_store(store_name, store_location);

    string line;
    while(getline(cin, line)){
        if(line.length() == 0){
            break;
        }

        istringstream iss(line);

        getline(iss, item_name, ',');
        iss >> item_quantity;
        iss.get();
        iss.get();
        iss >> item_price;

        new_store.addItem(item_name, item_quantity, static_cast<long>(item_price*100));
    }

    s_vec.push_back(new_store);
}

// Returns an integer number of the number found at the start of a line.
// Must be at the beginning of the line with no letters before the int.
int getIntFromLine(){
    string line;
    getline(cin, line);
    return stoi(line);
}

// Populates "sellers" with indices that correspond to an appearance of the list_item
void populateSellers(const vector<Store> & stores, const Item & list_item, vector<pair<int,int>> & sellers){
    for(int j = 0; j < static_cast<int>(stores.size()); j++){
        for(int k = 0; k < static_cast<int>(stores[j].items().size()); k++){
            if(stores[j].items()[k].name() == list_item.name()){
                sellers.push_back(make_pair(j,k));
            }
        }
    }

    // Sorts the sellers by price
    // Lowest price at the beginning
    sort(sellers.begin(), sellers.end(), 
        [stores](pair<int,int> p1, pair<int,int> p2){
            return (stores[p1.first].items()[p1.second].price() < stores[p2.first].items()[p2.second].price());
        });
}

void attemptToBuy(const vector<Store> & stores, Item & list_item,const vector<pair<int,int>> & sellers, long & item_total_price, ostringstream & oss){
    for(pair<int,int> p: sellers){
        if(stores[p.first].items()[p.second].quantity() >= list_item.quantity()){
            item_total_price += stores[p.first].items()[p.second].price() * list_item.quantity();
            oss << "Order " << list_item.quantity() << " from " << stores[p.first].name() << " in " << stores[p.first].location() << endl;
            break;
        }else{
            item_total_price += stores[p.first].items()[p.second].price() * stores[p.first].items()[p.second].quantity();
            oss << "Order " << stores[p.first].items()[p.second].quantity() << " from " << stores[p.first].name() << " in " << stores[p.first].location() << endl;
            list_item.quantity(list_item.quantity() - stores[p.first].items()[p.second].quantity());
        }
    }
}

// Print Store Related Info
// Prints the first 3 lines of output and populates the "stores" vector with data from the input
void storeRelatedProcess(vector<Store> & stores){
    cout << "Store Related Information (ordered by in-file order):" << endl;

    // Get the number of stores from the first line of input
    // Line format: "X Stores:"
    int num_stores = getIntFromLine();
    cout << "There are " << num_stores << " store(s)." << endl;

    // Get store data from input and add each store into a vector
    for(int i = 0; i < num_stores; i++){
        addStoreFromInput(stores);
        cout << stores[i].name() << " has " << stores[i].getItemsSize() << " distinct items." << endl;
    }
    cout << endl;
}

// Print Item Related Info
// Determines how many items are in stock across all stores
void itemRelatedProcess(const vector<Store> & stores){
    cout << "Item Related Information (ordered alphabetically):" << endl;

    // The map "stock" holds the name of an item and the total stock of that item
    map<string,int> stock;
    // Populates "stock" by looping through each Store in "stores"
    for(Store s: stores){
        for(Item i: s.items()){
            stock[i.name()] += i.quantity();
        }
    }

    // Outputs how many distrinct items and the stock of each distinct item across all stores
    cout << "There are " << stock.size() << " distinct item(s) available for purchase." << endl;
    for(pair<string, int> p: stock){
        cout << "There are " << p.second << " " << p.first << "(s)." << endl;
    }
    cout << endl;
}

// Print Shopping Related Info
// This section of code finds which stores sell what items the user is looking for and the lowest price the user can get those items for
void shoppingRelatedProcess(const vector<Store> & stores){

    cout << "Shopping:" << endl;

    // Get the number of shopping list items from a line of input
    // Line format: "X items on my shopping list:"
    int num_list_items = getIntFromLine();

    // Get shopping list data from input and add each item into a vector
    Item list_item;
    // the grand total price of the purchases from all the stores
    long total_price = 0;
    // the total price of the current list_item being bought. This gets added to the grand total price of all the shopping items at the bottom of the loop.
    long item_total_price = 0;

    // Attempts to order items
    for(int i = 0; i < num_list_items; i++){
        item_total_price = 0;
        getItemFromInput(list_item);
        cout << "Trying to order " << list_item.quantity() << " " << list_item.name() << "(s)." << endl;

        // "sellers" vector is made up of the index of the store and the index of the item in that store that sells the list_item
        // Example: sellers[1].first = index of a store that sells a "list_item" in "stores"
        //          sellers[1].second = index the "list_item" in the item vector of the store of sellers[1].first
        vector<pair<int,int>> sellers;
        populateSellers(stores, list_item, sellers);
        cout << sellers.size() << " store(s) sell " << list_item.name() << "." << endl;    

        ostringstream oss;  // helps with output
        attemptToBuy(stores, list_item, sellers, item_total_price, oss);

        // Print statements for each list_item
        cout << "Total price: $" << fixed << setprecision(2) << static_cast<double>(item_total_price)/100.00 << endl;
        cout << oss.str() << endl;

        // Add total price of this list_item to the grand total price
        total_price += item_total_price;
    }

    // Print the grand total price
    cout << "Be sure to bring $" << static_cast<double>(total_price)/100.00 << " when you leave for the stores." << endl;
}

int main(){
    vector<Store> stores;

    //This task has been split into three main processes as shown below
    storeRelatedProcess(stores);
    itemRelatedProcess(stores);
    shoppingRelatedProcess(stores);
}