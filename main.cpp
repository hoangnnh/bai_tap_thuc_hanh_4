#include <iostream>

#include "phanso.h"

using namespace std;


int main() {
    PhanSo f1 = PhanSo();
    cin >> f1;
    cout << "f1: " << f1 << "\n";

//    PhanSo f3;
//    f3 = f1;
//    cout << f3 << "\n";

    PhanSo f4 = PhanSo(1,2);
    cout << "f4: "<<f4 << "\n";

    PhanSo f5;
    f5 = f1 + f4;
    cout << "f5: "<<f5 << "\n";

    PhanSo f6;
    f6 = f1 - f4;
    cout << "f6: "<<f6 << "\n";

    PhanSo f7;
    f7 = f1 * f4;
    cout << "f7: " << f7 << "\n";

    PhanSo f8;
    f8 = f1 / f4;
    cout << "f8: " << f8 << "\n";

    f8 += f1;
    cout << "f8: " << f8 << "\n";

    f8 -= f1;
    cout << "f8: " << f8 << "\n";

    f8 *= f1;
    cout << "f8: " << f8 << "\n";

    f8 /= f1;
    cout << "f8: " << f8 << "\n";



    return 0;

}
