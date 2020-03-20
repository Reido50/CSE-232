#include<map>
using std::map;
#include<string>
using std::string;
#include<algorithm>
using std::count_if;
#include<utility>
using std::pair;

bool atLeastOne(pair<string, int> p){
    return (p.second > 0);
}

int FriendsWithPets(const map<string, int> & friends){
    int o;

    o = count_if(friends.begin(), friends.end(), atLeastOne);

    return o;
}