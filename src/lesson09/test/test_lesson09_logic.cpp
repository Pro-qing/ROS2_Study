#include <gtest/gtest.h>

#include "lesson09_logic.hpp"

TEST(Lesson09Logic, FormatsNormalCount)
{
  // TODO: keep the expected value aligned with the documented contract.
  EXPECT_EQ(format_count(7), "count = 7");
}

TEST(Lesson09Logic, CoversZero)
{
  EXPECT_EQ(format_count(0), "count = 0");
}

TEST(Lesson09Logic, CoversLargeValue)
{
  EXPECT_EQ(format_count(999), "count = 999");
}
