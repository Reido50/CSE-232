/*  Reid Harry
    2/13/2020
    
*/

#include<iostream>
using std::cin; using std::cout; using std::endl;
#include<string>
using std::string;
#include<math.h>
using std::pow;
#include<algorithm>
using std::sort;

long loc_to_dec(string loc){
    long num = 0;

    for(auto chr: loc){
        num += pow(2,(int)chr - 97);
    }

    return num;
}

string abbreviate(string loc){
    int currentAscii;

    sort(loc.begin(), loc.end());

    for(auto i = loc.length()-1; i > 0;){
        currentAscii = (int)loc[i];
        if(loc[i-1] == loc[i] && loc[i] != 'z'){
            loc.insert(i+1, 1, (char)(++currentAscii));
            loc.erase(i-1, 2);
        }else{
            i--;
        }
    }

    return loc;
}

string dec_to_loc(long dec){
    string loc;

    for(int i = 122; i >= 97 || dec != 0; i--){
        if(dec - pow(2, i-97) >= 0){
            dec-=pow(2, i-97);
            loc.insert(0,1,(char)i);
        }
    }

    return loc;
}

long add_loc(string loc1, string loc2){
    string new_loc;
    new_loc = loc1 + loc2;
    sort(new_loc.begin(), new_loc.end());
    new_loc = abbreviate(new_loc);
    return loc_to_dec(new_loc);
}