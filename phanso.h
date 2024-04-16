#ifndef PHANSO_PHANSO_H
#define PHANSO_PHANSO_H

#include <iostream>

class PhanSo {
    friend std::ostream& operator<<(std::ostream&, const PhanSo&);
    friend std::istream& operator>>(std::istream&, PhanSo&);

private:
    int *tuso;
    int *mauso;

public:

    PhanSo();
    explicit PhanSo(int, int);

    PhanSo(const PhanSo&);

    PhanSo& operator=(const PhanSo&);

    PhanSo& operator+(const PhanSo&);
    PhanSo& operator-(const PhanSo&);
    PhanSo& operator*(const PhanSo&);
    PhanSo& operator/(const PhanSo&);

    PhanSo& operator+=(const PhanSo&);
    PhanSo& operator-=(const PhanSo&);
    PhanSo& operator*=(const PhanSo&);
    PhanSo& operator/=(const PhanSo&);


    ~PhanSo();

};


#endif //PHANSO_PHANSO_H
