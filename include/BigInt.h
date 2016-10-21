#ifndef BIGINT_H_
#define BIGINT_H_

#include "gtest/gtest_prod.h"

#include <string>
#include <vector>

class BigInt {
private:
  /**
   * Always in form:
   * *this <  0: ________ ... 0xffffffff
   * *this >= 0: ________ ... 0x00000000
   *             ^            ^
   *             |　　　　　 　 +---- Most Significant
   *             +---- Least Significant
   */
  std::vector<int> m_ints;

  FRIEND_TEST(BigIntTest, MethodBarDoesAbc);

public:
  BigInt(const BigInt &) = default;
  BigInt(int n);

  BigInt &operator+=(const BigInt &rhs);
  BigInt operator+(const BigInt &rhs) const;
  BigInt operator++(int);
  BigInt &operator++();
  BigInt operator-() const;
  BigInt &operator-=(const BigInt &rhs);
  BigInt operator-(const BigInt &rhs) const;
  BigInt &operator--();
  BigInt operator--(int);
  BigInt &operator*=(const BigInt &rhs);

  bool operator==(const BigInt &rhs) const;
  bool operator!=(const BigInt &rhs) const;
  bool operator>(const BigInt &rhs) const;
  bool operator<(const BigInt &rhs) const;

  std::string toBitString() const;
};

#endif /* BIGINT_H_ */
