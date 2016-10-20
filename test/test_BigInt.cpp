#include "gtest/gtest.h"
#include <iostream>

#include "BigInt.h"

using namespace std;

// IndependentMethod is a test case - here, we have 2 tests for this 1 test case
TEST(IndependentMethod, ResetsToZero) {
  BigInt x = 1;
  BigInt y = 2;
  BigInt z = 3;
  EXPECT_EQ(x + y, z);
}

TEST(IndependentMethod, ResetsToZero2) {
  BigInt x = 1;
  BigInt y = 2;
  BigInt z = 3;
  EXPECT_EQ(x + y, z);
}

// The fixture for testing class Project1. From google test primer.
class BigIntTest : public ::testing::Test {
protected:
  // You can remove any or all of the following functions if its body
  // is empty.

  BigIntTest() {
    // You can do set-up work for each test here.
  }

  virtual ~BigIntTest() {
    // You can do clean-up work that doesn't throw exceptions here.
  }

  // If the constructor and destructor are not enough for setting up
  // and cleaning up each test, you can define the following methods:
  virtual void SetUp() {
    // Code here will be called immediately after the constructor (right
    // before each test).
  }

  virtual void TearDown() {
    // Code here will be called immediately after each test (right
    // before the destructor).
  }

  // Objects declared here can be used by all tests in the test case for
  // Project1.
  BigInt p = 0;
};

// Test case must be called the class above
// Also note: use TEST_F instead of TEST to access the test fixture (from google
// test primer)
TEST_F(BigIntTest, MethodBarDoesAbc) {
  BigInt a = 1;
  BigInt b = 2;
  BigInt c = 3;
  BigInt d = a + b;
  cout << (d == c) << endl;
  cout << "a: " << a.toBitString() << endl;
  cout << "b: " << b.toBitString() << endl;
  cout << "c: " << c.toBitString() << endl;
  cout << "d: " << d.toBitString() << endl;
  BigInt e = c - d;
  cout << "e: " << e.m_ints.size() << endl;
  cout << "c - d: " << e.toBitString() << endl;
  e += 10;
  cout << "e: " << e.toBitString() << endl;
}

// }  // namespace - could surround Project1Test in a namespace
