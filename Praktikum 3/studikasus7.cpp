#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    float jarakTempuh;
    float konsumsiBBM;
    float hargaPerLiter;
    float totalBiaya;
    string efisiensi;

    cout << "======================= Data Perjalanan =======================" << endl;

    cout << "Jarak Tempuh (km) : ";
    cin >> jarakTempuh;

    cout << "Konsumsi Bahan Bakar (km/l) : ";
    cin >> konsumsiBBM;

    cout << "Harga Bahan Bakar per Liter : ";
    cin >> hargaPerLiter;

    if (konsumsiBBM > 15) {
        efisiensi = "Efisien";
    }
    else if (konsumsiBBM >= 10 && konsumsiBBM <= 15) {
        efisiensi = "Cukup Efisien";
    }
    else if (konsumsiBBM < 10) {
        efisiensi = "Boros";
    }

    totalBiaya = (jarakTempuh / konsumsiBBM) * hargaPerLiter;

    cout << "======================= Total Biaya =======================" << endl;
    cout << "Status Efisiensi      : " << efisiensi << endl;
    
    cout << fixed << setprecision(0); 
    cout << "Total Biaya BBM       : Rp " << totalBiaya << endl;
    
    return 0;
}