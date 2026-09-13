#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

int main() {
   double suhu1;
   double suhu2;
   double suhu3;
   double suhu4;
   double suhu5;

   cout << "Suhu Hari 1: ";
   cin >> suhu1;
   cout << "Suhu Hari 2: ";
   cin >> suhu2;
   cout << "Suhu Hari 3: ";
   cin >> suhu3;
   cout << "Suhu Hari 4: ";
   cin >> suhu4;
   cout << "Suhu Hari 5: ";
   cin >> suhu5;

   cout << endl;

   double ratasuhu = (suhu1 + suhu2 + suhu3 + suhu4 + suhu5) / 5;
   cout << fixed << setprecision(1) << "Rata-rata Suhu: " << ratasuhu << endl;
   
   return 0;
}
