#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    double panjang;
    double lebar;
    double tinggi;
    double hargaperliter;

    cout << "Panjang ruangan: ";
    cin >> panjang;
    cout << "Lebar ruangan: ";
    cin >> lebar;
    cout << "Tinggi ruangan: ";
    cin >> tinggi;
    cout << "Harga cat per liter: ";
    cin >> hargaperliter;

    cout << endl;

    double luasdinding = 2 * (panjang * tinggi + lebar * tinggi);
    double litercat = luasdinding / 10;
    double totalbiaya = litercat * hargaperliter;

    cout << fixed << setprecision(2) << "Luas dinding : " << luasdinding << " m^2" << endl;
    cout << "Jumlah liter cat yang dibutuhkan: " << litercat << " liter" << endl;
    cout << "Total biaya cat: Rp " << totalbiaya << endl;

    return 0;
}
