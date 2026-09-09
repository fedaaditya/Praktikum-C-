#include <iostream>
using namespace std;

int main ()
{

    int a = 100.0;
    int b = 0.05;
    int c = 0.10;
    int d = (a * (1 + b)) - (a * b);
    
    cout << "Harga akhir adalah: " << d << endl;
    return 0;

}