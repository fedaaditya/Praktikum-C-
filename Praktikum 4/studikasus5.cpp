#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    int ulangi;

    do {
        double total_makanan = 0;
        double total_transportasi = 0;
        double total_hiburan = 0;
        double total_lainnya = 0;
        double total_semua = 0;

        double max_pengeluaran = 0;
        string max_kategori = "";


        for (int i = 1; i <= 7; i++) {
            string kategori;
            double jumlah;

            cout << "Masukkan kategori pengeluaran hari ke-" << i << " (Makanan/Transportasi/Hiburan/Lain-lain): ";
            cin >> kategori;
            
            cout << "Masukkan jumlah pengeluaran: Rp ";
            cin >> jumlah;


            if (kategori == "Makanan") {
                total_makanan += jumlah;
            } else if (kategori == "Transportasi") {
                total_transportasi += jumlah;
            } else if (kategori == "Hiburan") {
                total_hiburan += jumlah;
            } else {

                total_lainnya += jumlah;
            }


            if (jumlah > max_pengeluaran) {
                max_pengeluaran = jumlah;
                max_kategori = kategori;
            }
        }


        total_semua = total_makanan + total_transportasi + total_hiburan + total_lainnya;


        cout << fixed << setprecision(2);
        cout << "Total Pengeluaran Makanan: Rp " << total_makanan << endl;
        cout << "Total Pengeluaran Transportasi: Rp " << total_transportasi << endl;
        cout << "Total Pengeluaran Hiburan: Rp " << total_hiburan << endl;
        cout << "Total Pengeluaran Lainnya: Rp " << total_lainnya << endl;
        cout << "Total Pengeluaran Selama Seminggu: Rp " << total_semua << endl;
        cout << "Pengeluaran Terbesar: Rp " << max_pengeluaran << " pada kategori " << max_kategori << endl;


        cout << "Ingin mencatat pengeluaran untuk minggu lain? (1 untuk ya, selain itu untuk tidak): ";
        cin >> ulangi;

    } while (ulangi == 1);

    return 0;
}