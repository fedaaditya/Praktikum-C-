#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
#include <sstream>
#include <cctype>
using namespace std;

struct Proyek {
    string nama;
    long long anggaran;
    int pekerja;
};


string formatRupiah(long long n) {
    string s = to_string(n);
    string hasil;
    int hitung = 0;
    for (int i = (int)s.size() - 1; i >= 0; i--) {
        hasil = s[i] + hasil;
        if (++hitung % 3 == 0 && i > 0) hasil = "." + hasil;
    }
    return "Rp " + hasil;
}


long long bacaAngka(const string &prompt) {
    long long x;
    while (true) {
        cout << prompt;
        if (cin >> x && x >= 0) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return x;
        }
        cout << "Input tidak valid! Masukkan angka tidak negatif.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}


void tambahProyek(Proyek *&data, int &n, const Proyek &baru) {
    Proyek *temp = new Proyek[n + 1];
    for (int i = 0; i < n; i++) temp[i] = data[i];
    temp[n] = baru;
    delete[] data;
    data = temp;
    n++;
}

bool hapusProyek(Proyek *&data, int &n, int indeks) {
    if (n == 0) {
        cout << "Tidak ada proyek yang bisa dihapus (array kosong).\n";
        return false;
    }
    if (indeks < 0 || indeks >= n) {
        cout << "Indeks proyek tidak valid!\n";
        return false;
    }
    if (n == 1) {
        delete[] data;
        data = nullptr;
        n = 0;
        return true;
    }
    Proyek *temp = new Proyek[n - 1];
    for (int i = 0, j = 0; i < n; i++) {
        if (i != indeks) temp[j++] = data[i];
    }
    delete[] data;
    data = temp;
    n--;
    return true;
}

void tampilkanDaftar(const Proyek *data, int n) {
    if (n == 0) {
        cout << "  (Tidak ada proyek)\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        cout << "  Proyek " << i + 1 << ": \"" << data[i].nama
             << "\", Anggaran: " << formatRupiah(data[i].anggaran)
             << ", Pekerja: " << data[i].pekerja << "\n";
    }
}

void tampilkanStatistik(const Proyek *data, int n) {
    if (n == 0) {
        cout << "\nTidak ada data proyek untuk dihitung.\n";
        return;
    }
    long long total = 0;
    long long totalPekerja = 0;
    int maks = 0;
    for (int i = 0; i < n; i++) {
        total += data[i].anggaran;
        totalPekerja += data[i].pekerja;
        if (data[i].anggaran > data[maks].anggaran) maks = i;
    }
    double rata = (double)totalPekerja / n;

    ostringstream oss;
    oss << fixed << setprecision(2) << rata;
    string rataStr = oss.str();
    size_t pos = rataStr.find('.');
    if (pos != string::npos) rataStr[pos] = ',';

    cout << "\nTotal anggaran seluruh proyek: " << formatRupiah(total) << "\n";
    cout << "Rata-rata jumlah pekerja per proyek: " << rataStr << "\n";
    cout << "Proyek dengan anggaran terbesar: \"" << data[maks].nama
         << "\" (" << formatRupiah(data[maks].anggaran) << ")\n";
}


bool ambilAngka(const string &s, const string &kunci, long long &hasil) {
    string low = s;
    for (size_t i = 0; i < low.size(); i++) low[i] = (char)tolower((unsigned char)low[i]);
    size_t pos = low.find(kunci);
    if (pos == string::npos) return false;
    pos += kunci.size();
    size_t akhir = s.find(',', pos);
    string bagian = (akhir == string::npos) ? s.substr(pos) : s.substr(pos, akhir - pos);
    if (bagian.find('-') != string::npos) return false;  // negatif
    string digit;
    for (size_t i = 0; i < bagian.size(); i++)
        if (isdigit((unsigned char)bagian[i])) digit += bagian[i];
    if (digit.empty() || digit.size() > 18) return false;
    hasil = stoll(digit);
    return true;
}


bool parseProyek(const string &baris, Proyek &p) {
    size_t a = baris.find('"');
    size_t b = (a == string::npos) ? string::npos : baris.find('"', a + 1);
    if (a == string::npos || b == string::npos || b == a + 1) return false;
    p.nama = baris.substr(a + 1, b - a - 1);
    string sisa = baris.substr(b + 1);
    long long ang, pek;
    if (!ambilAngka(sisa, "anggaran:", ang) || !ambilAngka(sisa, "pekerja:", pek)) return false;
    if (pek > 2000000000LL) return false;
    p.anggaran = ang;
    p.pekerja = (int)pek;
    return true;
}

Proyek inputProyek(const string &label) {
    Proyek p;
    string baris;
    while (true) {
        cout << label << " ";
        getline(cin, baris);
        if (parseProyek(baris, p)) return p;
        cout << "Format tidak valid! Contoh: \"Gedung A\", Anggaran: Rp 1.000.000.000, Pekerja: 50\n"
             << "(anggaran/pekerja tidak boleh negatif)\n";
        if (!cin) { cin.clear(); }
    }
}

int main() {
    Proyek *data = nullptr;
    int n = 0;

    int jumlah = (int)bacaAngka("Masukkan jumlah proyek: ");
    if (jumlah == 0) cout << "Tidak ada proyek yang dimasukkan (array kosong).\n";

    cout << "Masukkan data proyek:\n";
    for (int i = 0; i < jumlah; i++) {
        Proyek p = inputProyek("Proyek " + to_string(i + 1) + ":");
        tambahProyek(data, n, p);
    }

    
    cout << "\n=== Tambah proyek baru ===\n";
    Proyek baru = inputProyek("Data proyek baru:");
    tambahProyek(data, n, baru);

    cout << "\nDaftar proyek setelah penambahan:\n";
    tampilkanDaftar(data, n);

   
    cout << "\n=== Hapus proyek ===\n";
    if (n == 0) {
        cout << "Tidak ada proyek yang bisa dihapus.\n";
    } else {
        int indeks;
        do {
            indeks = (int)bacaAngka("Indeks proyek yang dihapus (0 - " + to_string(n - 1) + "): ");
        } while (!hapusProyek(data, n, indeks));
    }

    cout << "\nDaftar proyek setelah penghapusan:\n";
    tampilkanDaftar(data, n);

    tampilkanStatistik(data, n);

    delete[] data;  // bebaskan memori
    return 0;
}