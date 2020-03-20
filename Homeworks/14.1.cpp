/*  Reid Harry
    3/19/2020
    For this homework write a function called havel_hakimi_digraph that takes in a vector<pair<int, int>> 
    and then returns whether or not the graph is graphical.
*/

#include<vector>
using std::vector;
#include<algorithm>
using std::sort;
#include<utility>
using std::pair;

bool compare(pair<int,int> a, pair<int,int> b){
    if(a.first != b.first){
        return(a.first > b.first);
    }else{
        return(a.second > b.second);
    }
}

bool check_havel(vector<pair<int,int>> graph){
    for(int i = 0; i < static_cast<int>(graph.size()); i++){
        if(graph[i].first != 0 || graph[i].second != 0){
            return false;
        }
    }
    return true;
}

bool havel_hakimi_digraph(vector<pair<int,int>> graph){
    int count = 0;

    while(!(check_havel(graph))){
        count++;

        if(graph.empty()){
            return true;
        }

        sort(graph.begin(), graph.end(), compare);

        int out_degree = graph[0].first;
        graph[0].first = 0;

        for(int i = 1; i < out_degree + 1; i++){
            if(static_cast<int>(graph.size()) <= out_degree){
                return false;
            }else{
                if(graph[i].second != 0){
                    graph[i].second--;
                }else{
                    out_degree++;
                }
            }
        }

        if(count >= 100){
            return false;
        }
    }
    
    return true;
}