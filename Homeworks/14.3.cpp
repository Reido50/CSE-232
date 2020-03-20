#include<fstream>
using std::ifstream;
#include<string>
using std::string;
#include<sstream>
using std::istringstream;
#include<utility>
using std::pair;
#include<map>
using std::map;
#include<iostream>
using std::cout; using std::endl;

int main(){
    ifstream stats("data.csv");
    
    string line;

    map<int, string> m;

    while(getline(stats, line)){
        istringstream iss;
        iss.str(line);

        pair<int, string> p;

        char c;
        while(iss.get(c)){
            if(c != ','){
                p.second += c;
            }else{
                break;
            }
        }

        iss >> p.first;

        m.insert(p);
    }

    int count = 5, place = 1;
    for(auto itr = m.crbegin(); itr != m.crend(); ++itr){
        if(count > 0){
            cout << place << ": " << itr->second << " with " << itr->first << " gold medals" << endl;
            count--;
            place++;
        }
    }
}