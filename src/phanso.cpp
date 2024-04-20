#include <iostream>

#include "phanso.h"

int findgcd(int, int);

Phanso::Phanso() {
    tuso = new int(0);
    mauso = new int(1);
}

Phanso::Phanso(int newTuso, int newMauso) {
    tuso = new int(newTuso);
    if (newMauso == 0) {
        std::cout << "Mau so phai khac 0. Gan mau so hien tai cho 1.\n";

        mauso = new int(1);
    } else {
        mauso = new int(newMauso);
    }
}

Phanso::Phanso(const Phanso &other) {

    tuso = new int(*other.tuso);
    mauso = new int(*other.mauso);
}

Phanso &Phanso::operator=(const Phanso &ps) {
    if (this == &ps) {
        return *this;
    }

    tuso = new int(*ps.tuso);
    mauso = new int(*ps.mauso);

    return *this;
}

Phanso &Phanso::operator+(const Phanso &ps) {
    Phanso *ketqua;

    int newTuso = (*tuso) * (*ps.mauso) + (*mauso) * (*ps.tuso);
    int newMauso = (*mauso) * (*ps.mauso);

    ketqua->tuso = new int(newTuso);
    ketqua->mauso = new int(newMauso);

    return *ketqua;
}

Phanso &Phanso::operator-(const Phanso &ps) {
    Phanso *ketqua;

    int newTuso = (*tuso) * (*ps.mauso) - (*mauso) * (*ps.tuso);
    int newMauso = (*mauso) * (*ps.mauso);

    ketqua->tuso = new int(newTuso);
    ketqua->mauso = new int(newMauso);

    return *ketqua;
}

Phanso &Phanso::operator*(const Phanso &ps) {
    Phanso *ketqua;

    int newTuso = (*tuso) * (*ps.tuso);
    int newMauso = (*mauso) * (*ps.mauso);

    ketqua->tuso = new int(newTuso);
    ketqua->mauso = new int(newMauso);

    return *ketqua;
}

Phanso &Phanso::operator/(const Phanso &ps) {
    Phanso *ketqua;

    int newTuso = (*tuso) * (*ps.mauso);
    int newMauso = (*mauso) * (*ps.tuso);

    ketqua->tuso = new int(newTuso);
    ketqua->mauso = new int(newMauso);

    return *ketqua;
}


Phanso &Phanso::operator+=(const Phanso &ps) {
    int newTuso = (*tuso) * (*ps.mauso) + (*mauso) * (*ps.tuso);
    int newMauso = (*mauso) * (*ps.mauso);

    tuso = new int(newTuso);
    mauso = new int(newMauso);

    return *this;
}

Phanso &Phanso::operator-=(const Phanso &ps) {
    int newTuso = (*tuso * *ps.mauso) - (*mauso * *ps.tuso);
    int newMauso = (*mauso) * (*ps.mauso);

    tuso = new int(newTuso);
    mauso = new int(newMauso);

    return *this;
}

Phanso &Phanso::operator*=(const Phanso &ps) {
    int newTuso = (*tuso) * (*ps.tuso);
    int newMauso = (*mauso) * (*ps.mauso);

    tuso = new int(newTuso);
    mauso = new int(newMauso);

    return *this;
}

Phanso &Phanso::operator/=(const Phanso &ps) {
    int newTuso = (*tuso) * (*ps.mauso);
    int newMauso = (*mauso) * (*ps.tuso);

    tuso = new int(newTuso);
    mauso = new int(newMauso);

    return *this;
}


bool Phanso::operator==(const Phanso &ps) {
    Phanso dolech; // The difference between 2 fractions
    dolech = *this - ps;

    if (*dolech.tuso == 0) {
        return true;
    }

    return false;
}

bool Phanso::operator<(const Phanso &ps) {
    Phanso dolech;

    dolech = *this - ps;

    if ((*dolech.tuso < 0 && *dolech.mauso > 0) ||
        (*dolech.tuso > 0 && *dolech.mauso < 0)) {

        return true;
    }

    return false;
}

bool Phanso::operator<=(const Phanso &ps) {

    if (*this < ps || *this == ps) {
        return true;
    }

    return false;
}

bool Phanso::operator>(const Phanso &ps) {
    Phanso dolech;

    dolech = *this - ps;

    if ((*dolech.tuso > 0 && *dolech.mauso > 0) ||
        (*dolech.tuso < 0 && *dolech.mauso < 0)) {

        return true;
    }

    return false;
}

bool Phanso::operator>=(const Phanso &ps) {
    if (*this > ps || *this == ps) {
        return true;
    }

    return false;
}


bool Phanso::operator!=(const Phanso &ps) {
    if (!(*this == ps)) {
        return true;
    }

    return false;
}


Phanso& Phanso::operator++() {
    *this += Phanso(1,1);

    return *this;
}

Phanso Phanso::operator++(int x) {
    Phanso ketqua = *this;

    *this += Phanso(1,1);

    return ketqua;
}

Phanso& Phanso::operator--() {
    *this -= Phanso(1,1);

    return *this;
}

Phanso Phanso::operator--(int x) {
    Phanso ketqua = *this;

    *this -= Phanso(1,1);

    return ketqua;
}

int findgcd(int a, int b) {
    if (a == 0) {
        return b;
    }

    if (b == 0) {
        return a;
    }

    if (a < 0) {
        a = std::abs(a);
    }

    if (b < 0) {
        b = std::abs(b);
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


std::ostream &operator<<(std::ostream &out, const Phanso &ps) {
    int gcd = findgcd(*ps.tuso, *ps.mauso);

    if (*ps.tuso == 0) {
        out << 0;
    } else if (*ps.tuso % *ps.mauso == 0) {
        out << *ps.tuso / *ps.mauso;
    } else {
        out << (*ps.tuso / gcd) << "/" << (*ps.mauso / gcd);
    }

    return out;
}

std::istream &operator>>(std::istream &in, Phanso &ps) {
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

Phanso::~Phanso() {
    delete tuso;
    tuso = nullptr;

    delete mauso;
    mauso = nullptr;
}
