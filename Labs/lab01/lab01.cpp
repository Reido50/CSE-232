#include <iostream>
using std::cout; using std::cin; using std::endl; using std::fixed;
#include<iomanip>
using std::setprecision;

int main() {
    cout << fixed << setprecision(2);
    
    const double AU_to_km = 149598000;  // units = km/AU
    const double AU_to_mi = 92955800;   // units = mi/AU
    const double initial_distance = 37.33;   // units = AU
    const double initial_velocity_km = 14.33;  // units = km/s
    const double initial_velocity_mi = 8.90;    // units = mi/s
    const double speed_of_light = 299792458;    // units = m/s
    int days;
    double roundtrip_hours;
    double final_distance_km;
    double final_distance_mi;
    
    // Prompt user for int (days after 12/30/2016)
    cin >> days;
    
    // Convert days into AU
    final_distance_km = days * 24 * 3600 * initial_velocity_km * (1/AU_to_km) + initial_distance; // units = AU
    final_distance_mi = days * 24 * 3600 * initial_velocity_mi * (1/AU_to_mi) + initial_distance; // units = AU

    // Output distance in km and mi
    cout << (final_distance_km * AU_to_km) << endl << (final_distance_mi * AU_to_mi) << endl;

    // Convert final_distance (AU) to roundtrip_hours (hr)
    roundtrip_hours = final_distance_km * 2 * AU_to_km * 1000 * (1/speed_of_light) * (1/3600.0);

    // Output roundtrip time in hours
    cout << roundtrip_hours << endl;
    
    return 0;
}