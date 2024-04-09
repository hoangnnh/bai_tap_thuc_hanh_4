#include <iostream>

#include "phanso.h"

using namespace std;

int main() {
    PhanSo *f1 = new PhanSo(new int(3), new int(2));
    cout << "Phan so f1: ";
    cout << f1 << '\n';
    PhanSo *f2 = new PhanSo(new int(0), new int(1));
    cout << "Phan so f2:\n";
    cin >> f2;
    cout << f2 << '\n';

    return 0;

}
