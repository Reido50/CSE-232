#include <iostream>
using std::cout; using std::cin; using std::endl; using std::fixed;
#include<iomanip>
using std::setprecision;

int main() {
    cout << fixed << setprecision(2);
    
    const double AU_to_km = 149598000;  // units = km/AU
    const double AU_to_mi = 92955800;   // units = mi/AU
    const double initial_distance = 37.33 * AU_to_km;   // units = km
    const double initial_velocity = 14.33;  // units = km/s
    int days;
    
    // Prompt user for int (days after 12/30/2016)
    cout << "Enter an amount of day after 12/30/2016: ";
    cin >> days;
    
    // Convert days into AU
    double final_distance = days * 24 * 3600 * initial_velocity * (1/AU_to_km);
    
    cout << "The distance from the sun of the New Horizons spacecraft is "
         << (final_distance * AU_to_km) << " kilometers or "
         << (final_distance * AU_to_mi) << " miles!";
    
    return 0;
}