#include "strings.h"
#include "gtest/gtest.h"

TEST(strings, string_abc_should_eq_to_string_abc){
    EXPECT_TRUE(IsSameString("abc","abc"));
}

TEST(strings, string_abc_should_not_eq_to_string_abcd){
    EXPECT_FALSE(IsSameString("abc","abcd"));
}

TEST(strings, cat_str_a_and_b_should_eq_to_ab){
    char dst[20] = {0};
    Cat2Str("a","b", dst, 20);
    EXPECT_TRUE(IsSameString("ab", dst));
}

