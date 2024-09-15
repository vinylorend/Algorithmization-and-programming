- - -
>  ___The task has not been done yet___
- - -

```C++
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    // Словари для хранения информации о скидках и способах оплаты
    const int num_clients = 4;
    const int num_products = 3;
    int discounts[num_clients][num_products] = {{40, 30, 20}, {30, 20, 10}, {20, 10, 0}, {0, -10, 0}};

    // Ввод данных пользователем
    int client_type, product_type;
    cout << "Enter the client type (1-excellent, 2-good, 3-average, 4-poor): ";
    cin >> client_type;
    cout << "Enter the product type (A=1, B=2, C=3): ";
    cin >> product_type;

    // Проверка корректности введенных данных
    if (client_type < 1 || client_type > num_clients || product_type < 1 || product_type > num_products) {
        cout << "ERROR: Invalid client or product type." << endl;
        return 1;
    }

    // Расчет скидки
    int discount = discounts[client_type - 1][product_type - 1];

    // Выбор способа оплаты и расчет итоговой стоимости
    int payment_method;
    double final_price;
    cout << "Select the payment method (1-cash, 2-check, 3-credit): ";
    cin >> payment_method;

    switch (payment_method) {
        case 1: // Наличные
            final_price = 100 - discount;
            break;
        case 2: // Чек
            int num_payments, interest_rate;
            cout << "Enter the number of payments: ";
            cin >> num_payments;
            if (num_payments <= 0) {
                cout << "Error: Number of payments must be positive." << endl;
                return 1;
            }
            cout << "Enter the interest rate: ";
            cin >> interest_rate;
            if (interest_rate < 0) {
                cout << "Error: Interest rate must be non-negative." << endl;
                return 1;
            }
            final_price = (100 - discount) * pow(1 + interest_rate / 100.0, num_payments);
            break;
        case 3: // Кредит
            int credit_type, num_payments;
            cout << "Enter the credit type (1-platinum, 2-business): ";
            cin >> credit_type;
            cout << "Enter the number of payments: ";
            cin >> num_payments;
            if (num_payments <= 0) {
                cout << "Error: Number of payments must be positive." << endl;
                return 1;
            }
            final_price = (100 - discount) * pow(1 + (credit_type == 1 ? 0.05 : 0.02), num_payments);
            break;
        default:
            cout << "ERROR: Invalid payment method." << endl;
            return 1;
    }

    // Вывод результата
    cout << "Final price: " << final_price << "%" << endl;

    return 0;
}
```
