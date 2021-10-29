#include <gtest/gtest.h>
#include "cal/add/add.h"

TEST(Cal, Add1) {
    EXPECT_EQ(5, add(2, 3));
}

TEST(Cal, Add2) {
    EXPECT_EQ(6, add(2, 3));
}