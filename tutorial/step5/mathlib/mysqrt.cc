#include <cmath>

#include "mysqrt.h"

double mysqrt(double x) {
  assert(x >= 0.0);
  if (x == 0) {
    return 0;
  }
#if defined(HAVE_LOG) && defined(HAVE_EXP)
  double xi = exp(log(x) * 0.5);
#else
  double xi = x;
  while (myabs(xi - x / xi) > 1e-6) {
    xi = (x / xi + xi) * 0.5;
  }
#endif
  return xi;
}