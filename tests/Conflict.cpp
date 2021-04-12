#include <gtest/gtest.h>
#include <Conflict.hpp>

Conflict conflict = *new Conflict();

TEST(ConflictTest, status)
{
    EXPECT_EQ(conflict.status(), false);
    conflict.detection();
    EXPECT_EQ(conflict.status(), true);
    conflict.clear();
    EXPECT_EQ(conflict.status(), false);
}
