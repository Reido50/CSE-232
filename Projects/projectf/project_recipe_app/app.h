#pragma once

#include "recipe.h"

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
using std::find_if; using std::sort; using std::any_of;
#include<exception>
using std::invalid_argument;
#include<numeric>
using std::gcd;

class RecipeApp{
    private:
        typedef pair<pair<int,int>,pair<string,string>> ingredient;
        vector<ingredient> pantry_;
        vector<Recipe> recipes_;

    public:
        // Constructors
        RecipeApp() = default;
        
        // Public Member Functions
        void AddRecipe(const Recipe& r){
            recipes_.push_back(r);
            sort(recipes_.begin(), recipes_.end(), 
                    [](const Recipe& x, const Recipe& y){
                        return x.name() < y.name();
                    });
        }

        void AddIngredientToPantry(const string& s){
            pantry_.push_back(StringToIngredient(s));
            sort(pantry_.begin(), pantry_.end(),
                    [](ingredient& x, ingredient& y){
                        return x.second.second < y.second.second;
                    });
        }

        Recipe UseUpIngredient(const string& s){
            ingredient supply = StringToIngredient(s);
            Recipe result = recipes_[0];
            for(auto itr_r = recipes_.begin(); itr_r != recipes_.end(); ++itr_r){
                try{
                    ingredient demand_one_serving = StringToIngredient(itr_r->IngredientInOneServing(supply.second.second));
                    Recipe result = *itr_r;
                    result.ChangeServings((supply.first.first*demand_one_serving.first.second)/(supply.first.second*demand_one_serving.first.first));
                    return result;
                }catch(invalid_argument& e){
                    if(itr_r == (recipes_.end()-1)){
                        throw invalid_argument("No recipes found with given ingredient: " + s);
                    }
                }
            }
            return result;
        }

        // Friends
        friend ostream& operator<<(ostream& out, const RecipeApp& r){
            // Print Recipes
            out << "Recipes in the app (ordered by name):" << endl;
            for(auto itr = r.recipes_.begin(); itr != r.recipes_.end(); ++itr){
                out << *itr;
            }

            // Print Ingredients
            out << "Ingredients in pantry (ordered by name):" << endl;
            for(auto itr = r.pantry_.begin(); itr != r.pantry_.end(); ++itr){
                out << FormatNumber(itr->first.first, itr->first.second) << " " << itr->second.first << " " << itr->second.second << endl;
            }

            return out;
        }
};