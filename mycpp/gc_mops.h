// gc_mops.h - corresponds to mycpp/mops.py

#ifndef MYCPP_GC_MOPS_H
#define MYCPP_GC_MOPS_H

#include <stdint.h>

class BigStr;

namespace mops {

// BigInt library
// TODO: Make it arbitrary size.  Right now it's int64_t, which is distinct
// from int.

typedef int64_t BigInt;

BigStr* ToStr(BigInt b);
BigInt ToBigInt(BigStr* s, int base = 10);

inline int BigTruncate(BigInt b) {
  return static_cast<int>(b);
}

inline BigInt IntWiden(int b) {
  return static_cast<BigInt>(b);
}

inline BigInt Add(BigInt a, BigInt b) {
  return a + b;
}

inline BigInt Sub(BigInt a, BigInt b) {
  return a - b;
}

inline BigInt LShift(BigInt a, BigInt b) {
  return a << b;
}

}  // namespace mops

#endif  // MYCPP_GC_MOPS_H
