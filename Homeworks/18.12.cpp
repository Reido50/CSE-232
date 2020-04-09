/*  Reid Harry
    4/9/2020
    I've made a map<string, int> that represents the number of times a word appears in a particular text.

    I need you to transform the data in this data structure to some related data structure. Do not copy this map, using const references.
*/

#include<map>
using std::map; using std::multimap;
#include<utility>
using std::pair;
#include<string>
using std::string;
#include<set>
using std::set;

// only_once: takes a map<string, int> and returns a set<string> of words that only appeared once in the text.
set<string> only_once(const map<string,int> & appearances){
    set<string> result;

    for(pair<string,int> word: appearances){
        if(word.second == 1){
            result.insert(word.first);
        }
    }

    return result;
}

// count_to_words: takes a map<string, int> and returns a multimap<int, string> of the counts to the words with that count.
multimap<int,string> count_to_words(const map<string,int> & appearances){
    multimap<int,string> result;

    for(pair<string,int> word: appearances){
        result.insert(pair<int,string>(word.second, word.first));
    }

    return result;
}

// count_to_set: takes a map<string, int> and returns a map<int, set<string>> of the counts to the set of words with that count.
map<int,set<string>> count_to_set(const map<string,int> & appearances){
    map<int,set<string>> result;

    for(pair<string,int> word: appearances){
        result[word.second].insert(word.first);
    }

    return result;
}