#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double initial_price, discount_percent;
    int payment_count, credit_type;

    cout << "Enter the initial price: ";
    cin >> initial_price;
    if (initial_price <= 0) {
        cout << "Error: Initial price must be positive." << endl;
        return 1;
    }

    cout << "Enter the discount percentage: ";
    cin >> discount_percent;
    if (discount_percent < 0 || discount_percent > 100) {
        cout << "Error: Discount percentage must be between 0 and 100." << endl;
        return 1;
    }

    cout << "Enter the number of payments: ";
    cin >> payment_count;
    if (payment_count <= 0) {
        cout << "Error: Number of payments must be positive." << endl;
        return 1;
    }

    cout << "Select the credit type (1 - Platinum, 2 - Business): ";
    cin >> credit_type;
    if (credit_type != 1 && credit_type != 2) {
        cout << "Error: Invalid credit type." << endl;
        return 1;
    }

    double price_after_discount = initial_price * (1 - discount_percent / 100);

    double final_price;
    if (credit_type == 1) {
        final_price = price_after_discount * pow(1 + 0.05, payment_count);
    } else {
        final_price = price_after_discount * pow(1 + 0.02, payment_count);
    }

    cout << "Initial price: $" << initial_price << endl;
    cout << "Price after discount: $" << price_after_discount << endl;
    cout << "Final price with credit: $" << final_price << endl;

    return 0;
}
