#include <iostream>

#include "phanso.h"


PhanSo::PhanSo() {
    tuso = new int(0);
    mauso = new int(1);
}

PhanSo::PhanSo(int newTuso, int newMauso) {
    tuso = new int(newTuso);
    if (newMauso == 0) {
        std::cout << "Mau so phai khac 0. Gan mau so hien tai cho 1.\n";

        mauso = new int(1);
    } else {
        mauso = new int(newMauso);
    }
}

PhanSo::PhanSo(const PhanSo &other) {

    tuso = new int(*other.tuso);
    mauso = new int(*other.mauso);
}

PhanSo &PhanSo::operator=(const PhanSo &ps) {
    if (this == &ps) {
        return *this;
    }

    tuso = new int(*ps.tuso);
    mauso = new int(*ps.mauso);

    return *this;
}

PhanSo &PhanSo::operator+(const PhanSo &ps) {
    PhanSo *ketqua;

    int newTuso = (*tuso) * (*ps.mauso) + (*mauso) * (*ps.tuso);
    int newMauso = (*mauso) * (*ps.mauso);

    ketqua->tuso = new int(newTuso);
    ketqua->mauso = new int(newMauso);

    return *ketqua;
}

PhanSo &PhanSo::operator-(const PhanSo &ps) {
    PhanSo *ketqua;

    int newTuso = (*tuso) * (*ps.mauso) - (*mauso) * (*ps.tuso);
    int newMauso = (*mauso) * (*ps.mauso);

    ketqua->tuso = new int(newTuso);
    ketqua->mauso = new int(newMauso);

    return *ketqua;
}

PhanSo &PhanSo::operator*(const PhanSo &ps) {
    PhanSo *ketqua;

    int newTuso = (*tuso) * (*ps.tuso);
    int newMauso = (*mauso) * (*ps.mauso);

    ketqua->tuso = new int(newTuso);
    ketqua->mauso = new int(newMauso);

    return *ketqua;
}

PhanSo &PhanSo::operator/(const PhanSo &ps) {
    PhanSo *ketqua;

    int newTuso = (*tuso) * (*ps.mauso);
    int newMauso = (*mauso) * (*ps.tuso);

    ketqua->tuso = new int(newTuso);
    ketqua->mauso = new int(newMauso);

    return *ketqua;
}


PhanSo &PhanSo::operator+=(const PhanSo &ps) {
    int newTuso = (*tuso) * (*ps.mauso) + (*mauso) * (*ps.tuso);
    int newMauso = (*mauso) * (*ps.mauso);

    tuso = new int(newTuso);
    mauso = new int(newMauso);

    return *this;
}

PhanSo &PhanSo::operator-=(const PhanSo &ps) {
    int newTuso = (*tuso * *ps.mauso) - (*mauso * *ps.tuso);
    int newMauso = (*mauso) * (*ps.mauso);

    tuso = new int(newTuso);
    mauso = new int(newMauso);

    return *this;
}

PhanSo &PhanSo::operator*=(const PhanSo &ps) {
    int newTuso = (*tuso) * (*ps.tuso);
    int newMauso = (*mauso) * (*ps.mauso);

    tuso = new int(newTuso);
    mauso = new int(newMauso);

    return *this;
}

PhanSo &PhanSo::operator/=(const PhanSo &ps) {
    int newTuso = (*tuso) * (*ps.mauso);
    int newMauso = (*mauso) * (*ps.tuso);

    tuso = new int(newTuso);
    mauso = new int(newMauso);

    return *this;
}




int findGCD(int a, int b) {
    if (a == 0) {
        return b;
    }

    if (b == 0) {
        return a;
    }

    while (a != b) {
        if (a > b) {
            a -= b;
        } else {
            b -= a;
        }
    }

    return a;
}


std::ostream &operator<<(std::ostream &out, const PhanSo &ps) {
    int gcd = findGCD(*ps.tuso, *ps.mauso);

    if (*ps.tuso == 0) {
        out << 0;
    } else if (*ps.tuso % *ps.mauso == 0) {
        out << *ps.tuso / *ps.mauso;
    } else {
        out << (*ps.tuso / gcd) << "/" << (*ps.mauso / gcd);
    }

    return out;
}

std::istream &operator>>(std::istream &in, PhanSo &ps) {
    std::cout << "Nhap tu so: ";
    in >> *ps.tuso;

    std::cout << "Nhap mau so: ";
    in >> *ps.mauso;

    if (*ps.mauso == 0) {
        *ps.mauso = 1;
        std::cout << "Mau so phai khac 0. Gan mau so hien tai cho 1.\n";
    }

    return in;
}

PhanSo::~PhanSo() {
    delete tuso;
    tuso = nullptr;

    delete mauso;
    mauso = nullptr;
}
