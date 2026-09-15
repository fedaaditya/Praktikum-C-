#include <iostream>
using namespace std;

int main() {
    int nomor;

    cout << "Masukan Nomor: ";
    cin >> nomor;

    string hasil = (nomor % 2 == 0)? "Genap" : "Ganjil";
    cout << "Angka tersebut adalah: " << hasil << endl;
    return 0;
}