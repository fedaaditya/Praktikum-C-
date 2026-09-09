#include <iostream>
#include <iomanip>
#include <string>
 using namespace std;

int main () {
    int p = 10;
    int l = 5;
    int t = 3;

int volume = p * l * t;
int luaspermukaan = 2 * ((p * l)+ (p * t)+ (l * t));

cout << "Volume: " << volume << endl;
cout << "Luas Permukaan: " << luaspermukaan << endl;

return 0;
}