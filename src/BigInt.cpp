#include "BigInt.h"
#include <cassert>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int add(int x, int y, int *carry) {
  int z = x + y + *carry;

  int bitx = ((unsigned int)x & (1 << 31)) >> 31;
  int bity = ((unsigned int)y & (1 << 31)) >> 31;
  int bitz = ((unsigned int)z & (1 << 31)) >> 31;

  if (bitx == 1 && bity == 1) {
    *carry = 1;
  } else if ((bitx ^ bity) == 1 && bitz == 0) {
    *carry = 1;
  } else {
    *carry = 0;
  }

  return z;
}

BigInt::BigInt(int n) {
  m_ints.push_back(n);
  if (n > 0) {
    m_ints.push_back(0);
  } else if (n < 0) {
    m_ints.push_back(-1);
  }
}

/**
 *
 * Most basic operator for BigInt
 */
BigInt &BigInt::operator+=(const BigInt &rhs) {
  assert(m_ints.size() > 0 && rhs.m_ints.size() > 0);
  assert(m_ints.back() == -1 || m_ints.back() == 0);
  assert(rhs.m_ints.back() == -1 || rhs.m_ints.back() == 0);

  auto &l_ints = m_ints;
  const auto &r_ints = (this == &rhs) ? BigInt(rhs).m_ints : rhs.m_ints;

  while (l_ints.size() < r_ints.size()) {
    l_ints.push_back(l_ints.back());
  }

  vector<int>::size_type i = 0;
  int carry = 0;

  while (i < r_ints.size()) {
    l_ints[i] = add(l_ints[i], r_ints[i], &carry);
    ++i;
  }

  while (i < l_ints.size()) {
    l_ints[i] = add(l_ints[i], r_ints[0], &carry);
    ++i;
  }

  int sign = l_ints.back() >= 0 ? 0 : -1;
  while (l_ints.size() > 0 && l_ints.back() == sign) {
    l_ints.pop_back();
  }
  l_ints.push_back(sign);

  return *this;
}

BigInt BigInt::operator+(const BigInt &rhs) const {
  BigInt result = *this;
  result += rhs;
  return result;
}

BigInt BigInt::operator++(int) {
  BigInt tmp = *this;
  *this += 1;
  return tmp;
}

BigInt &BigInt::operator++() {
  *this += 1;
  return *this;
}

BigInt BigInt::operator-() const {
  BigInt result = *this;
  for (vector<int>::size_type i = 0; i < result.m_ints.size(); ++i) {
    result.m_ints[i] = ~result.m_ints[i];
  }
  result += 1;
  return result;
}

BigInt &BigInt::operator-=(const BigInt &rhs) {
  auto toAdd = -rhs;
  *this += toAdd;
  return *this;
}

BigInt BigInt::operator-(const BigInt &rhs) const {
  BigInt result = *this;
  result -= rhs;
  return result;
}

BigInt &BigInt::operator--() {
  *this -= 1;
  return *this;
}

BigInt BigInt::operator--(int) {
  BigInt tmp = *this;
  *this -= 1;
  return tmp;
}

bool BigInt::operator==(const BigInt &rhs) const {
  auto result = *this - rhs;
  return result.m_ints.size() == 1 && result.m_ints[0] == 0;
}

bool BigInt::operator!=(const BigInt &rhs) const { return !(*this == rhs); }

bool BigInt::operator>(const BigInt &rhs) const {
  auto result = *this - rhs;
  return result.m_ints.size() > 1 && result.m_ints.back() == 0;
}

bool BigInt::operator<(const BigInt &rhs) const {
  auto result = *this - rhs;
  return result.m_ints.back() == -1;
}

BigInt &BigInt::operator*=(const BigInt &rhs) {
  auto count = rhs;
  if (count == 0) {
    *this = 0;
    return *this;
  }

  if (count < 0) {
    count = -count;
    *this = -*this;
  }

  while (count != 0) {
    count--;
    *this += *this;
  }
  return *this;
}

string BigInt::toBitString() const {
  vector<char> bits;
  for (vector<int>::size_type i = 0; i < m_ints.size(); ++i) {
    unsigned int val = m_ints[i];
    for (int shift = 0; shift < 32; ++shift) {
      bits.push_back((((val & (1 << shift)) >> shift)) == 0 ? '0' : '1');
    }
    bits.push_back('|');
  }
  return string(bits.begin(), bits.end());
}

bool is_big_endian() {
  union {
    uint32_t i;
    char c[4];
  } bint = {0x01020304};

  return bint.c[0] == 1;
}
ostream &operator<<(ostream &os, const BigInt &bigint) {
  os << "[";
  ios::fmtflags f(os.flags());
  os << hex;
  for (auto i = bigint.m_ints.size() - 1; i > 0; --i) {
    os << bigint.m_ints[i] << ",";
  }
  os << bigint.m_ints[0];
  os.flags(f);
  os << "]";
  return os;
}
