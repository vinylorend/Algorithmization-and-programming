#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double k, omega, A, phi_0, T, x_T;
    A = 1.0;

    cout << "Enter the k (how many times is x smaller than A?): \t";
    cin >> k;

    if (k <= 1) {
        cout << "ERROR: k <= 1" << endl;
        return 1;
    }
    
    cout << "Enter the omega frequency value (ω): \t";
    cin >> omega;

    if (omega <= 0) {
        cout << "ERROR: omega <= 0" << endl;
        return 1;

    phi_0 = asin(1.0 / k);

    T = (M_PI / 2 - phi_0) / omega;

    x_T = A * sin(omega * T + phi_0);

    cout << "The magnitude of the Phi(0) (phase shift): \t" << phi_0 << endl;
    cout << "The time point T at which the deviation achieves its maximum significance: \t" << T << endl;
    cout << "The value of the x(T) coordinate: \t" << x_T << endl;

    return 0;
}
