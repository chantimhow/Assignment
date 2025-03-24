#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    double a, b, c, d, e, f, g, x;
    double integration_value, error_threshold;
    // to ask user for input    
    cout << "input lower limit: ";
    cin >> a;
    cout << "input upper limit: ";
    cin >> b;
    cout << "enter error threshold:";
    cin >> error_threshold;
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
    integration_value = (c / 5) * (pow(b, 5) - pow(a, 5)) + (d / 4) * (pow(b, 4) - pow(a, 4)) + (e / 3) * (pow(b, 3) - pow(a, 3)) + (f / 2) * (pow(b, 2) - pow(a, 2)) + (g * (b - a));
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

    n = 2;

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

    cout << "Exact value of the integral:  " << integration_value << endl;
    cout << "Trapezoidal Rule: " << trapezoidal_value << endl;
    cout << "Simpson Rule: " << simpson_value << endl;

    system("pause");
    return 0;
}
    