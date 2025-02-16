#pragma once

#include<vector>
using std::vector;
#include<iostream>
using std::cout; using std::endl; using std::ostream;

class Table{
  private:
    vector<vector<long>> t_;    // 2D vector of long
    long width_;                // how wide is t_ (how many columns)
    long height_;               // how high is t_ (how many rows)
  public:
    // table will be width x height, default val is 0
    Table(long width, long height, long val=0);
    // range from lo to hi, seed has default
    void fill_random(long lo, long hi, unsigned int seed=0);
    bool set_value(unsigned int row_num, unsigned int col_num, long val);
    long get_value  (unsigned int row_num, unsigned int col_num) const;
    void print_table(ostream&);
    friend ostream& operator<<(ostream& out, Table t);
};
