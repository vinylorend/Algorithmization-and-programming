#include <iostream>
#include <cmath>
#include <limits> //for infinity

using namespace std;

int main() {
    double H, V, alpha, g = 9.8, T, x_T, y_T;

    cout << "Enter the height of the cliff 'H' (in meters): \t";
    cin >> H;

    cout << "Enter the speed velocity 'V' (in m/s): \t";
    cin >> V;

    cout << "Enter the angle 'alpha' (in degrees): \t";
    cin >> alpha;

    
    alpha = alpha * M_PI / 180.0; // Converting the angle to radians

    if (sin(alpha) == 0) {
        cout << "ERROR: angle < 0 or angle > 180" << endl;
        return 1;
    }

    if (V == 0) {
        cout << "ERROR: V == 0 << endl" << endl;
        return 1;
    }

    double under_sqrt = 1 + (2 * g * H) / (V * V * sin(alpha) * sin(alpha));

    if (under_sqrt < 0) {
        cout << "ERROR: value under sqrt < 0" << endl;
        return 1;
    }

    T = (V * sin(alpha) / g) * (1 + sqrt(under_sqrt));

    x_T = V * T * cos(alpha);
    y_T = H + V * T * sin(alpha) - 0.5 * g * T * T;

    if (y_T < 0) {
        y_T = 0;
    }

    cout << "The flight time of the stone 'T': " << T << " sec" << endl;
    cout << "Horizontal position of the stone 'x(T)': " << x_T << " meters" << endl;
    cout << "The vertical position of the stone 'y(T)': " << y_T << " meters" << endl;

    return 0;
}
