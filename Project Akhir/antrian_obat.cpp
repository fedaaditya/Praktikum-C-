#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

const int MAKS_PASIEN = 50;
const int MAKS_OBAT = 10;
const int MENIT_PER_PASIEN = 5; 

enum JenisObat { TABLET = 1, SIRUP, KAPSUL, SALEP };
enum StatusPasien { BELUM_AMBIL_NOMOR, MENUNGGU, SELESAI };


union Dosis {
    int kaliPerHari;
    float mlPerDosis;
};


struct Obat {
    string nama;
    JenisObat jenis;
    int jumlah;   
    Dosis dosis;
};

struct Pasien {
    string nama;
    Obat obat[MAKS_OBAT];   
    int jumlahObat;
    int nomorAntrian;
    StatusPasien status;
};

// semua data
Pasien dataPasien[MAKS_PASIEN];     
int jumlahPasien = 0;

Pasien* antrian[MAKS_PASIEN];       
int jumlahAntrian = 0;              
int indeksPanggil = 0;              

// bantuan
string bacaTeks(const string& pesan) {
    string s;
    cout << pesan;
    getline(cin, s);
    return s;
}

int bacaAngka(const string& pesan, int minimal, int maksimal) {
    int nilai;
    bool valid = false;
    while (!valid) {
        string s = bacaTeks(pesan);
        nilai = atoi(s.c_str());
        if (nilai >= minimal && nilai <= maksimal) {
            valid = true;
        } else {
            cout << "  Input tidak valid! Masukkan angka " << minimal
                 << " - " << maksimal << ".\n";
        }
    }
    return nilai;
}

string namaJenis(JenisObat j) {
    switch (j) {
        case TABLET: return "Tablet";
        case SIRUP:  return "Sirup";
        case KAPSUL: return "Kapsul";
        case SALEP:  return "Salep";
    }
    return "-";
}


void tampilObat(const Obat* o, int no) {
    cout << "   " << no << ". " << o->nama << " (" << namaJenis(o->jenis)
         << ") x" << o->jumlah << " | ";
    if (o->jenis == SIRUP) {
        cout << o->dosis.mlPerDosis << " ml per dosis\n";
    } else {
        cout << o->dosis.kaliPerHari << " kali sehari\n";
    }
}

// input obat 1
void inputPasien() {
    if (jumlahPasien >= MAKS_PASIEN) {
        cout << "Data pasien penuh!\n";
        return;
    }

    Pasien* p = &dataPasien[jumlahPasien];
    p->nama = bacaTeks("Nama pasien           : ");
    p->jumlahObat = bacaAngka("Jumlah jenis obat     : ", 1, MAKS_OBAT);
    p->nomorAntrian = 0;
    p->status = BELUM_AMBIL_NOMOR;

    for (int i = 0; i < p->jumlahObat; i++) {
        cout << "--- Obat ke-" << i + 1 << " ---\n";
        Obat* o = &p->obat[i];
        o->nama = bacaTeks("  Nama obat           : ");
        cout << "  Jenis: 1.Tablet 2.Sirup 3.Kapsul 4.Salep\n";
        o->jenis = (JenisObat)bacaAngka("  Pilih jenis         : ", 1, 4);
        o->jumlah = bacaAngka("  Jumlah diambil      : ", 1, 100);

        if (o->jenis == SIRUP) {
            o->dosis.mlPerDosis = (float)atof(bacaTeks("  Dosis (ml)          : ").c_str());
        } else {
            o->dosis.kaliPerHari = bacaAngka("  Kali pakai per hari : ", 1, 10);
        }
    }

    jumlahPasien++;
    cout << "\nData pasien " << p->nama << " berhasil disimpan.\n";
}

// ambil nomor antrian 2
void ambilNomor() {

    int daftar[MAKS_PASIEN];
    int jumlahDaftar = 0;
    for (int i = 0; i < jumlahPasien; i++) {
        if (dataPasien[i].status == BELUM_AMBIL_NOMOR) {
            daftar[jumlahDaftar] = i;
            jumlahDaftar++;
        }
    }

    if (jumlahDaftar == 0) {
        cout << "Tidak ada pasien yang belum mengambil nomor.\n";
        return;
    }

    cout << "Pasien yang belum mengambil nomor:\n";
    for (int i = 0; i < jumlahDaftar; i++) {
        cout << "  " << i + 1 << ". " << dataPasien[daftar[i]].nama << "\n";
    }

    int pilih = bacaAngka("Siapa yang ambil nomor? (pilih nomor): ", 1, jumlahDaftar);
    Pasien* p = &dataPasien[daftar[pilih - 1]];

    antrian[jumlahAntrian] = p;
    jumlahAntrian++;
    p->nomorAntrian = jumlahAntrian;     // ekspresi: nomor = jumlah antrian terbaru
    p->status = MENUNGGU;

    int sisaDidepan = jumlahAntrian - 1 - indeksPanggil;
    int estimasi = sisaDidepan * MENIT_PER_PASIEN;

    cout << "\n=== " << p->nama << " mendapat NOMOR ANTRIAN " << p->nomorAntrian << " ===\n";
    cout << "Estimasi menunggu: " << estimasi << " menit\n";
}

// panggil antrian 3
void panggilBerikutnya() {
    if (indeksPanggil >= jumlahAntrian) {
        cout << "Tidak ada antrian yang menunggu.\n";
        return;
    }

    Pasien* p = antrian[indeksPanggil];
    cout << "\n============================================\n";
    cout << " PANGGILAN ANTRIAN NOMOR " << p->nomorAntrian << "\n";
    cout << " Atas nama: " << p->nama << "\n";
    cout << "============================================\n";
    cout << " Obat yang harus diambil:\n";

    int totalItem = 0;
    for (int i = 0; i < p->jumlahObat; i++) {
        tampilObat(&p->obat[i], i + 1);
        totalItem += p->obat[i].jumlah;   
    }
    cout << " Total item: " << totalItem << "\n";

    string jawab = bacaTeks("\nObat sudah diambil? (y/n): ");
    if (jawab == "y" || jawab == "Y") {
        p->status = SELESAI;
        indeksPanggil++;
        if (indeksPanggil < jumlahAntrian) {
            cout << "Selesai. Antrian berikutnya: nomor "
                 << antrian[indeksPanggil]->nomorAntrian << " ("
                 << antrian[indeksPanggil]->nama << ")\n";
        } else {
            cout << "Selesai. Semua antrian sudah dilayani.\n";
        }
    } else {
        cout << "Antrian nomor " << p->nomorAntrian << " masih ditahan.\n";
    }
}

// antrian disini 4
void lihatAntrian() {
    if (jumlahAntrian == 0) {
        cout << "Belum ada yang mengambil nomor antrian.\n";
        return;
    }

    cout << "\nNo | Nama               | Status\n";
    cout << "---+--------------------+-----------\n";
    int i = 0;
    while (i < jumlahAntrian) {
        Pasien* p = antrian[i];
        cout << p->nomorAntrian << "  | " << p->nama;
        for (size_t k = p->nama.length(); k < 19; k++) cout << ' ';
        cout << "| ";
        if (p->status == SELESAI) cout << "Selesai";
        else if (i == indeksPanggil) cout << "Dipanggil berikutnya";
        else cout << "Menunggu";
        cout << "\n";
        i++;
    }
    cout << "\nSisa antrian: " << jumlahAntrian - indeksPanggil << " pasien\n";
}

// main disini
int main() {
    int menu;
    do {
        cout << "\n========= ANTRIAN PENGAMBILAN OBAT =========\n";
        cout << "1. [Dokter]  Input obat pasien\n";
        cout << "2. [Pasien]  Ambil nomor antrian\n";
        cout << "3. [Petugas] Panggil antrian berikutnya\n";
        cout << "4. Lihat daftar antrian\n";
        cout << "0. Keluar\n";
        menu = bacaAngka("Pilih menu: ", 0, 4);
        cout << "\n";

        switch (menu) {
            case 1: inputPasien(); break;
            case 2: ambilNomor(); break;
            case 3: panggilBerikutnya(); break;
            case 4: lihatAntrian(); break;
            case 0: cout << "Terima kasih. Program selesai.\n"; break;
        }
    } while (menu != 0);

    return 0;
}