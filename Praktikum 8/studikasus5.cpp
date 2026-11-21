
#include <iostream>
#include <string>
using namespace std;

struct Produk {
    string nama;
    long long harga;
    int terjual;
};

int main() {
    int n;

    cout << "Input:" << endl;
    cout << "Masukkan jumlah produk: ";
    cin >> n;


    if (n <= 0) {
        cout << "Jumlah produk harus lebih dari 0!" << endl;
        return 0;
    }

    Produk* p = new Produk[n];

    cout << "Masukkan data produk (nama produk, harga satuan, jumlah terjual):" << endl;

    cin.ignore();

    for (int i = 0; i < n; i++) {
        string teksInput;

        cout << "Produk " << i + 1 << ": ";
        getline(cin, teksInput);


        size_t kutipAwal = teksInput.find('"');
        size_t kutipAkhir = teksInput.find('"', kutipAwal + 1);

        p[i].nama = teksInput.substr(
            kutipAwal + 1,
            kutipAkhir - kutipAwal - 1
        );


        size_t posisiRp = teksInput.find("Rp ");
        size_t posisiKoma = teksInput.find(',', posisiRp);

        string stringHarga = teksInput.substr(
            posisiRp + 3,
            posisiKoma - (posisiRp + 3)
        );


        string hargaBersih = "";

        for (char karakter : stringHarga) {
            if (karakter != '.') {
                hargaBersih += karakter;
            }
        }

        p[i].harga = stoll(hargaBersih);


        size_t posisiTerjual = teksInput.find("Terjual: ");

        string stringTerjual = teksInput.substr(posisiTerjual + 9);

        p[i].terjual = stoi(stringTerjual);
    }


    long long totalPendapatan = 0;
    long long maxPendapatan = 0;

    for (int i = 0; i < n; i++) {
        long long pendapatan = p[i].harga * p[i].terjual;

        totalPendapatan += pendapatan;

        if (pendapatan > maxPendapatan) {
            maxPendapatan = pendapatan;
        }
    }

    cout << "\nOutput:" << endl << endl;

    cout << "Total pendapatan: Rp " << totalPendapatan << endl;

    cout << "Rata-rata pendapatan per produk: Rp "
         << totalPendapatan / n << endl;

    cout << "Produk dengan pendapatan tertinggi:" << endl;


    for (int i = 0; i < n; i++) {
        long long pendapatan = p[i].harga * p[i].terjual;

        if (pendapatan == maxPendapatan) {
            cout << "- \"" << p[i].nama
                 << "\" (Rp " << pendapatan << ")" << endl;
        }
    }

    delete[] p;

    return 0;
}
