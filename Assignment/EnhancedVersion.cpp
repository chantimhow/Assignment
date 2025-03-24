#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    double a, b, c, d, e, f, g, x;
    double integration_value, error_threshold;
    // to ask user for input
    do {
        cout << "input lower limit: ";
        cin >> a;
        cout << "input upper limit: ";
        cin >> b;
        if (a > b) {
            cout << "lower limit cannot be higher than upper limit!" << endl;
        }
    } while (a > b);
    do {
        cout << "enter error threshold:";
        cin >> error_threshold;
        if (error_threshold <= 0) {
            cout << "error threshold has to be greater than 0!" << endl;
        }
    } while (error_threshold <= 0);
    cout << "enter coefficients" << endl;
    cout << "x^4:";
    cin >> c;
    cout << "x^3:";
    cin >> d;
    cout << "x^2:";
    cin >> e;
    cout << "x^1:";
    cin >> f;
    cout << "constant(g):";
    cin >> g;

    //to calculate exact intergration value
    integration_value = ((c * (pow(b, 5)) / 5) + (d * (pow(b, 4)) / 4) + (e * (pow(b, 3)) / 3) + (f * (pow(b, 2)) / 2) +
        (g * b)) - ((c * (pow(a, 5)) / 5) + (d * (pow(a, 4)) / 4) + (e * (pow(a, 3)) / 3) + (f * (pow(a, 2)) / 2) +
            (g * a));
    int n = 2, trap_interval, simp_interval;
    double trapezoidal_value = 0, height, absolute_error, simpson_value = 0, trap_error, simp_error;

    
    //calculate trapezoidal rule   
        do {
            height = (b - a) / n;
            trapezoidal_value = (c * pow(a, 4) + d * pow(a, 3) + e * pow(a, 2) + f * a + g); // f(a)
            trapezoidal_value += (c * pow(b, 4) + d * pow(b, 3) + e * pow(b, 2) + f * b + g);
             
            for (int i = 1; i < n; i++)
            {
                x = a + i * height;
                trapezoidal_value += 2 * (c * pow(x, 4) + d * pow(x, 3) + e * pow(x, 2) + f * x + g);
            }
            trapezoidal_value *= (height / 2);
            absolute_error = fabs(integration_value - trapezoidal_value);

            if (absolute_error > error_threshold)
            {
                n += 1;
            }

        } while (absolute_error > error_threshold);
        trap_interval = n;
        n = 2;
        trap_error = absolute_error;
    //calculate simpson's rule
        do {
            height = (b - a) / n;
            simpson_value = (c * pow(a, 4) + d * pow(a, 3) + e * pow(a, 2) + f * a + g); 
            simpson_value += (c * pow(b, 4) + d * pow(b, 3) + e * pow(b, 2) + f * b + g);

            for (int i = 1; i < n; i++)
            {
                x = a + i * height;
                if (i % 2 == 0) {
                    simpson_value += 2 * (c * pow(x, 4) + d * pow(x, 3) + e * pow(x, 2) + f * x + g);
                }
                else if (i % 2 != 0) {
                    simpson_value += 4 * (c * pow(x, 4) + d * pow(x, 3) + e * pow(x, 2) + f * x + g);
                }
            }
            simpson_value *= (height / 3);
            absolute_error = fabs(integration_value - simpson_value);

            if (absolute_error > error_threshold)
            {
                n += 2;
            }

        } while (absolute_error > error_threshold);
        simp_interval = n;
            simp_error = absolute_error;
 
    cout << endl;
 //output of calculated value
    cout << "Quartic Polynomial: " << '(' << c << "x^4" << ')' << '+' << '(' << d << "x^3" << ')' << '+' << '(' << e << "x^2" << ')' << '+' << '(' << f << "x^1" << ')' << '+' << '(' << g << ')' << endl;
    cout << "Exact value of intergral: " << fixed << setprecision(4) << integration_value << endl;

    for (int i = 1; i < 90; i++) { //to print a line
        cout << '-';
    }
    cout << endl;

    int width = 20;
    //line 1
    cout << setw(width) << left << "Integration Method";
    cout << setw(width) << left << "No of Subintervals";
    cout << setw(width -5 ) << left << "Result";
    cout << setw(width-2) << left << "Absolute Error";
    cout << setw(width-5) << left << "Percentage Error" << endl;
    //line 2
    cout << setw(width) << left << "Trapeziodal Rule";
    cout << setw(width) << left << trap_interval;
    cout << setw(width - 5) << left << trapezoidal_value;
    cout << setw(width - 2) << left << trap_error;
        cout << setw(width - 5) << left << (trap_error / integration_value) * 100 << showpoint << endl;
    //line 3
    cout << setw(width) << left << "Simpson Rule";
    cout << setw(width) << left << simp_interval;
    cout << setw(width - 5) << left << simpson_value;
    cout << setw(width - 2) << left << simp_error;
    cout << setw(width - 5) << left << (simp_error / integration_value) * 100 << showpoint << endl;

    for (int i = 1; i < 90; i++) {
        cout << '-';
    }
    cout << endl;
// to check which rule uses less interval and determine which is more efficient.
    if (trap_interval > simp_interval) {
        cout << "Simpson Rule is more efficient, requiring fewer subintervals to achieve the specified error threshold.";
    }
    else if (trap_interval < simp_interval) {
        cout << "Trapezoidal Rule is more efficient, requiring fewer subintervals to achieve the specified error threshold.";
    }
    cout << endl;
    system("pause");
    return 0;
}
