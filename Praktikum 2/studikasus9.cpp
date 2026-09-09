#include <iostream>
#include <iomanip>

using namespace std;

int main ()
{
    cout << left << setw(10) << "Meter"
         << setw(15) << "Sentimeter"
         << setw(15) << "Milimeter"
         << setw(15) << "Kilometer" <<endl;

    for (int i = 1; i <= 10; i++) {
        double cm = i * 100;
        double mm = i * 1000;
        double km = i / 1000.0;

    cout << right << setw(5) << i 
         << setw(12) << cm 
         << setw(15) << mm 
         << setw(15) << km <<endl;
    }
    return 0;

}