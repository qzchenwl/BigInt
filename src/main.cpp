#include "BigInt.h"
#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  BigInt x = (pow(2, 31) - 1);
  BigInt y = 10;
  BigInt z = -1 * pow(2, 15);

  cout << "x: " << x.toBitString() << endl;
  cout << "y: " << y.toBitString() << endl;
  cout << "z: " << z.toBitString() << endl;

  z += y;
  cout << "z: " << z.toBitString() << endl;

  z += z;
  cout << "z: " << z.toBitString() << endl;

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
  cout << "c - d: " << e.toBitString() << endl;

  cout << hex << "a: " << a << endl;
  cout << dec << "a: " << a << endl;
  cout << oct << "a: " << a << endl;

  cout << "z: " << z << endl;
  cout << "z: " << z.toBitString() << endl;

  return 0;
}
