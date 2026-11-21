#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    double jarak;
    double konsumsi;
    double hargaperliter;
    
    cout << "Jarak Tempuh: ";
    cin >> jarak;

    cout << "Konsumsi Bahan Bakar: ";
    cin >> konsumsi;

    cout << "Harga Bahan Bakar: ";
    cin >> hargaperliter;

    cout << endl;

    double totalbiaya = (jarak / konsumsi) * hargaperliter;

    cout << fixed << setprecision(2) << "Total Biaya Bahan Bakar: Rp " << totalbiaya << endl;

    return 0;
}
