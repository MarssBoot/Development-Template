#include <gtest/gtest.h>
#include "add.h"

TEST(Additi, CanAddTwoPositiveNumbers) {
  Money a(10, 10), b(10, 10)
    ASSERT_EQ(a+b, 20.20)<<"1 is not equal 0";

}

TEST(Addition, CanAddTwoNumbersDifferentSign) {
  EXPECT_EQ(add(-5, 5), 0);
}

TEST(Addition, CanAddTwoNegativeNumbers) {
  EXPECT_EQ(add(-5, -5), -10);
}
