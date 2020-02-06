#include<iostream>
using std::cout; using std::cin; using std::endl; using std::fixed;
#include<iomanip>
using std::setprecision;
#include<cmath>
using std::pow; using std::abs;

double fn(double x){
    return -6.0*pow(x,2.0) + 5.0*x + 3.0;
}

double integral(double x){
    return -2*pow(x,3.0) + (5.0/2.0)*pow(x,2.0) + 3.0*x;
}

double trapezoid(double a, double b, long n){
    double area = 0;
    double current_x = 0;
    double previous_x = a;
    double increment = (b-a)/static_cast<double>(n);

    for(int i = 1; i <= n; i++){
        current_x = a + i*increment;

        area += ((current_x - previous_x) * (fn(previous_x) + fn(current_x))) / 2.0;

        previous_x = current_x;
    }

    return area;
}

int main(){
    double a, b, t;
    long n;
    double dif, calculated_area, approx_area;

    cout << "Lower Range:" << endl;
    cin >> a;
    cout << "Upper Range:" << endl;
    cin >> b;
    cout << "Tolerance:" << endl;
    cin >> t;
    cout << "Initial trapezoid count:" << endl;
    cin >> n;

    calculated_area = (integral(b) - integral(a));

    for(n; true; n *= 2){
        approx_area = trapezoid(a,b,n);
        dif = abs((calculated_area - approx_area));

        if(dif > t){
            cout << fixed << setprecision(4) << "Intermediate Result:" << approx_area << 
                 ", traps:" << setprecision(0) << n << ", diff:" << setprecision(4) << dif << endl;
        }else{
            cout << setprecision(0) << "Trap count:" << n << ", estimate:" << setprecision(4) << approx_area << 
                 ", exact:" << calculated_area << ", tolerance:" << t << endl;
            break;
        }
    }
}