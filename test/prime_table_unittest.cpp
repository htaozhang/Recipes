#include "../algo/prime_table.h"
#include <gtest/gtest.h>


TEST(PrimeTable, Online) {
    // 100001, 100003, 100007, 100009
    algo::PrimeTable *table = new algo::OnlinePrimeTable();
    EXPECT_TRUE(table != NULL);
    EXPECT_FALSE(table->IsPrime(-1));
    EXPECT_FALSE(table->IsPrime(0));
    EXPECT_TRUE(table->IsPrime(2));
    EXPECT_TRUE(table->IsPrime(3));
    EXPECT_FALSE(table->IsPrime(4));
    EXPECT_EQ(59, table->NextPrime(57));
    EXPECT_EQ(100003, table->NextPrime(100001));
}

TEST(PrimeTable, Offline) {
    algo::PrimeTable *table = new algo::OfflinePrimeTable(1000000);
    EXPECT_TRUE(table != NULL);
    EXPECT_FALSE(table->IsPrime(-1));
    EXPECT_FALSE(table->IsPrime(0));
    EXPECT_TRUE(table->IsPrime(2));
    EXPECT_TRUE(table->IsPrime(3));
    EXPECT_FALSE(table->IsPrime(4));
    EXPECT_EQ(59, table->NextPrime(57));
    EXPECT_EQ(100003, table->NextPrime(100001));
    EXPECT_EQ(-1, table->NextPrime(1000000));
}
