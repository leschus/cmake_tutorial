#ifndef MYSQRT_H_
#define MYSQRT_H_

#include <cassert>

template <typename T>
T myabs(T x) {
  return x >= 0 ? x : -x;
}

double mysqrt(double x);

#endif // MYSQRT_H_