#include <phanso/phanso.h>
#include <gtest/gtest.h>

TEST(FractionTest, OutputTest) {
    Phanso f1 (3, 2);
    EXPECT_EQ(f1.getTuso(), 3);
    EXPECT_EQ(f1.getMauso(), 2);
}