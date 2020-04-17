#include "table.h"

#include<iostream>
using std::cout; using std::endl; using std::ostream;
#include<vector>
using std::vector;
#include<algorithm>
using std::fill;
#include<random>
using std::uniform_int_distribution; using std::mt19937;
#include<exception>
using std::out_of_range;

// table will be width x height, default val is 0
Table::Table(long width, long height, long val){
    width_ = width;
    height_ = height;
    for(long i = 0; i < width; i++){
        t_.push_back(vector(height, val));
    }
}

// range from lo to hi, seed has default
void Table::fill_random(long lo, long hi, unsigned int seed){
    mt19937 generator(seed);
    uniform_int_distribution<long> distribution(lo,hi);

    for(long i = 0; i < width_; i++){
        for(long j = 0; j < height_; j++){
            t_[i][j] = distribution(generator);
        }
    }
}

bool Table::set_value(unsigned int row_num, unsigned int col_num, long val){
    if(row_num <= height_ && col_num <= width_){
        t_[col_num][row_num] = val;
        return true;
    }else{
        return false;
    }
}

long Table::get_value(unsigned int row_num, unsigned int col_num) const{
    if(row_num <= height_ && col_num <= width_){
        return t_[col_num][row_num];
    }else{
        throw out_of_range("Index out of Range");
    }
}

void Table::print_table(ostream& out){
    for(auto v:t_){
        for(auto i:v){
            out << i << ",";
        }
        out << endl;
    }
}

ostream& operator<<(ostream& out, Table t){
    t.print_table(out);
    return out;
}