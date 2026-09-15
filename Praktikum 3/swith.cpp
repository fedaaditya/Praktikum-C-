#include <iostream>
using namespace std;

int main() {
    int pakaian;

    cout << "Masukan Pakaian: ";
    cin >> pakaian;

    switch (pakaian)
    {
    case 1:
        cout << "Pakaian Baju Kemeja" << endl;
        break;
    case 2:
        cout << "Pakaian Baju T-Shirt" << endl;
        break;
    case 3:
        cout << "Pakaian Celana Jeans" << endl;
        break;
    case 4:
        cout << "Pakaian Rok" << endl;
        break;
    case 5:
        cout << "Pakaian Blouse" << endl;
        break;
    default:
        cout << "Kode yang dimasukkan salah" << endl;
        break;
    }
    return 0;
}
