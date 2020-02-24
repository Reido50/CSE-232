/*  Reid Harry
    2/24/2020
    I want you to write a similar function in C++. The function (named "zip") should take two const references 
    to vector<string> and return a vector<string> where each element in the returned vector is the concatentation 
    of the elements in the original two vectors (see test cases for examples).
*/

#include<vector>
using std::vector;
#include<string>
using std::string;

vector<string> zip(const vector<string>& v1, const vector<string>& v2){
    vector<string> zipped;
    string v1_value, v2_value;

    for(int i=0; true; i++){
        if(i >= v1.size() && i >= v2.size()){
            break;
        }else if(i >= v1.size()){
            v1_value = "";
            v2_value = v2[i];
        }else if(i >= v2.size()){
            v1_value = v1[i];
            v2_value = "";
        }else{
            v1_value = v1[i];
            v2_value = v2[i];
        }

        zipped.push_back(v1_value + v2_value);
    }

    return zipped;
}