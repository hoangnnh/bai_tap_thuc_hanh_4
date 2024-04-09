#ifndef PHANSO_PHANSO_H
#define PHANSO_PHANSO_H

#include <iostream>

class PhanSo {
    friend std::ostream& operator<<(std::ostream&, const PhanSo*);
    friend std::istream& operator>>(std::istream&, PhanSo*);

    friend int findGCD(const PhanSo*);

private:
    int *tuso;
    int *mauso;
public:
    PhanSo();
    PhanSo(int*, int*);

    PhanSo& operator=(const PhanSo*);
    PhanSo* operator+(const PhanSo*);

    ~PhanSo();

};


#endif //PHANSO_PHANSO_H
