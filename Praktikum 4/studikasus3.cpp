#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int ulangi;

    do {
        double penggunaan, total_sebelum_diskon, diskon, total_setelah_diskon;
        int tarif;

        cout << "Masukkan penggunaan listrik (kWh): ";
        cin >> penggunaan;

        if (penggunaan <= 100) {
            tarif = 1500;
        } else if (penggunaan <= 300) {
            tarif = 2000;
        } else {
            tarif = 3000;
        }

        total_sebelum_diskon = penggunaan * tarif;

        if (total_sebelum_diskon > 1000000) {
            diskon = total_sebelum_diskon * 0.10;
        } else {
            diskon = 0;
        }

        total_setelah_diskon = total_sebelum_diskon - diskon;


        cout << fixed << setprecision(2);
        cout << "Total Penggunaan Listrik: " << penggunaan << " kWh" << endl;
        cout << "Total Tagihan Sebelum Diskon: Rp " << total_sebelum_diskon << endl;
        cout << "Diskon: Rp " << diskon << endl;
        cout << "Total Tagihan Setelah Diskon: Rp " << total_setelah_diskon << endl;

        cout << "Ingin menghitung tagihan untuk penggunaan lain? (1 untuk ya, selain itu untuk tidak): ";
        cin >> ulangi;

    } while (ulangi == 1);

    return 0;
}