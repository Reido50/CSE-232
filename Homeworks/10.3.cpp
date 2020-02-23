#include<string>
using std::string;

char safe_at(int i, string s){
    if(s.length()-1 < i){
        return ' ';
    }else{
        return s[i];
    }
}

char safe_at(string s, int i){
    if(s.length()-1 < i){
        return ' ';
    }else{
        return s[i];
    }
}