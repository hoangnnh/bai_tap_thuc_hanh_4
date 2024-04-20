#ifndef PHANSO_PHANSO_H
#define PHANSO_PHANSO_H

#include <iostream>

class Phanso {
    friend std::ostream& operator<<(std::ostream&, const Phanso&);
    friend std::istream& operator>>(std::istream&, Phanso&);

private:
    int *tuso;
    int *mauso;

public:

    Phanso();
    explicit Phanso(int, int);

    Phanso(const Phanso&);

    int getTuso();

    int getMauso();

    Phanso& operator=(const Phanso&);

    Phanso& operator+(const Phanso&);
    Phanso& operator-(const Phanso&);
    Phanso& operator*(const Phanso&);
    Phanso& operator/(const Phanso&);

    Phanso& operator+=(const Phanso&);
    Phanso& operator-=(const Phanso&);
    Phanso& operator*=(const Phanso&);
    Phanso& operator/=(const Phanso&);

    bool operator==(const Phanso&);
    bool operator<(const Phanso&);
    bool operator>(const Phanso&);
    bool operator<=(const Phanso&);
    bool operator>=(const Phanso&);
    bool operator!=(const Phanso&);

    Phanso operator++(int);
    Phanso &operator++();
    Phanso operator--(int);
    Phanso &operator--();



    ~Phanso();

};


#endif //PHANSO_PHANSO_H
