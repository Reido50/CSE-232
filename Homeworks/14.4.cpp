#include<set>
using std::set;
#include<string>
using std::string;
#include<algorithm>
using std::set_intersection; using std::inserter;

set<string> FriendsInCommon(const set<string> & s1, const set<string> & s2){
    set<string> inter;
    set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(inter, inter.begin()));
    return inter;
}