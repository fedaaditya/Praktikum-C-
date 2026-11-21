#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
   double hargabarang;
   double diskon;

   cout << "Harga Barang: ";
   cin >> hargabarang;
   cout << "Diskon: ";
   cin >> diskon;
   cout << endl;

   double hargasetelahdiskon = hargabarang - ( hargabarang * diskon / 100);

   cout << "Harga Awal: " << hargabarang << endl;
   cout << diskon << "%" << endl;
   cout << fixed << setprecision(2) << "Harga Setelah Diskon: Rp" << hargasetelahdiskon << endl;
   
   return 0;
}
