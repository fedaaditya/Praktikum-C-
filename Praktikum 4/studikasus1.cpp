#include <iostream>
#include <iomanip> 

using namespace std;

int main() {
    string ulang;
    
    do {
        int jumlah_barang;
        cout << "Masukkan jumlah barang: ";
        cin >> jumlah_barang;
        
        double total_harga = 0;
        for (int i = 1; i <= jumlah_barang; ++i) {
            double harga;
            cout << "Masukkan harga barang ke-" << i << ": Rp ";
            cin >> harga;
            total_harga += harga;
        }
        
        double diskon = 0;
        if (total_harga > 500000) {
            diskon = total_harga * 0.10;
        } else if (total_harga >= 250000) {
            diskon = total_harga * 0.05;
        } else {
            diskon = 0;
        }
        
        double total_setelah_diskon = total_harga - diskon;
        
        cout << fixed << setprecision(2);
        cout << "Total Harga: Rp " << total_harga << "\n";
        cout << "Diskon: Rp " << diskon << "\n";
        cout << "Total Setelah Diskon: Rp " << total_setelah_diskon << "\n";
        
        cout << "Ingin menambahkan belanjaan lagi? (1 untuk ya, selain itu untuk tidak): ";
        cin >> ulang;
        
    } while (ulang == "1");

    return 0;
}