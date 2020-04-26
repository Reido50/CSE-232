#pragma once

#include "utility.h"

#include<iostream>
using std::endl; using std::cout;
#include<string>
using std::string;
#include<vector>
using std::vector;
#include<utility>
using std::pair; using std::make_pair;
#include<ios>
using std::ostream; using std::streamsize;
#include<sstream>
using std::istringstream; using std::ostringstream;
#include<limits>
using std::numeric_limits;
#include<algorithm>
using std::find_if;
#include<exception>
using std::invalid_argument;
#include<numeric>
using std::gcd;

class Recipe{
    private:
        string name_;
        int serving_size_;
        string instructions_;

        /*  first: quantity of ingredient in an improper fraction <numerator, denominator>
            second: unit and name of ingredient <unit, name>*/
        typedef pair<pair<int,int>,pair<string,string>> ingredient;
        vector<ingredient> ingredients_;

    public:
        // Constructors
        Recipe(const string& n, int s): name_(n), serving_size_(s){};

        // Getters
        string name() const{
            return name_;
        }

        vector<ingredient> ingredients(){
            return ingredients_;
        }

        // Public Member Functions
        void AddIngredient(const string& s){
            ingredients_.push_back(StringToIngredient(s));
        }

        void SetInstructions(const string& s){
            string line, new_line;
            istringstream iss(s);
            while(getline(iss, line)){
                new_line = RemoveWhitespace(line);
                if(new_line.find_first_not_of(' ') != string::npos){
                    // Concat the line without trailing/leading spaces to instructions_
                    instructions_ += (RemoveWhitespace(line) + '\n');
                }
            }
        }

        string IngredientInOneServing(const string& name){
            string n = name;
            ingredient one_serving;
            vector<ingredient>::iterator itr;
            itr = find_if(ingredients_.begin(), ingredients_.end(), 
                    [n](ingredient i){
                        return n == i.second.second;
                    });
            if(itr != ingredients_.end()){
                one_serving = *itr;
                one_serving.first = SimplifyFraction(one_serving.first.first, serving_size_*(one_serving.first.second));
                return FormatNumber(one_serving.first.first, one_serving.first.second) + " " + one_serving.second.first + " " + one_serving.second.second;
            }else{
                throw invalid_argument("Ingredient not in recipe.");
            }
        }

        void ChangeServings(int s){
            pair<int,int> new_quantity;
            for(auto itr = ingredients_.begin(); itr != ingredients_.end(); ++itr){
                itr->first.first *= s;
                itr->first.second *= serving_size_;
                itr->first = SimplifyFraction(itr->first.first, itr->first.second);
            }
            serving_size_ = s;
        }

        // Rule of Three
        Recipe(const Recipe& r){
            name_ = r.name_;
            serving_size_ = r.serving_size_;
            instructions_ = r.instructions_;
            ingredients_ = r.ingredients_;
        }
        ~Recipe() = default;
        Recipe& operator=(const Recipe& r){
            name_ = r.name_;
            serving_size_ = r.serving_size_;
            instructions_ = r.instructions_;
            ingredients_ = r.ingredients_;
            return *this;
        }

        // Friends
        friend ostream& operator<<(ostream& out, const Recipe& r){
            out << "Recipe for: " << r.name_ << endl
                << "Serves " << r.serving_size_ << endl
                << "Ingredients:" << endl;

            // Prints contents of ingredients_ to out
            for(auto itr = r.ingredients_.begin(); itr != r.ingredients_.end(); ++itr){
                out << FormatNumber(itr->first.first, itr->first.second) << " " << itr->second.first << " " << itr->second.second << endl;
            }
            out << endl;

            out << "Instructions:" << endl << r.instructions_ << endl;

            return out;
        }
};