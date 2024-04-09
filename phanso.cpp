#include <iostream>

#include "phanso.h"


PhanSo::PhanSo() {
    *tuso = 0;
    *mauso = 1;
}

PhanSo::PhanSo(int *newTuso, int *newMauso) {
    tuso = newTuso;
    if (*newMauso == 0) {
        std::cout << "Mau so phai khac 0. Gan mau so hien tai cho 1.\n";
        mauso = new int(1);
    } else {
        mauso = newMauso;
    }
}

PhanSo& PhanSo::operator=(const PhanSo *ps) {
    if (this == ps) {
        std::cout << "Self-assignment detected. Exit!\n";
        return *this;
    }

    this->tuso = ps->tuso;
    this->mauso = ps->mauso;

    return *this;
}

PhanSo* PhanSo::operator+(const PhanSo *ps) {
    PhanSo *result = new PhanSo(new int(3), new int (4));

    int tu1 = *this->tuso;
    int tu2 = *ps->tuso;
    std::cout << tu1+tu2;



    return result;

}

int findGCD(const PhanSo *ps) {
    int tuso = *ps->tuso;
    int mauso = *ps->mauso;
    while (tuso != mauso) {
        if (tuso > mauso) {
            tuso -= mauso;
        } else {
            mauso -= tuso;
        }
    }

    return tuso;
}

std::ostream &operator<<(std::ostream &out, const PhanSo *ps) {
    int gcd = findGCD(ps);

    out << *ps->tuso / gcd << "/" << *ps->mauso / gcd;

    return out;
}

std::istream &operator>>(std::istream &in, PhanSo *ps) {
    std::cout << "Tu so: ";
    in >> *ps->tuso;
    std::cout << "Mau so: ";
    in >> *ps->mauso;

    return in;
}

PhanSo::~PhanSo() {
    delete tuso;
    delete mauso;
}
