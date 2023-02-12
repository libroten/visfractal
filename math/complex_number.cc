#include "math/complex_number.h"

#include <cmath>

namespace math {

ComplexNumber::ComplexNumber() = default;
ComplexNumber::ComplexNumber(long double re_part, long double im_part)
    : re(re_part), im(im_part) {}

ComplexNumber operator+(const ComplexNumber& a, const ComplexNumber& b) {
  return ComplexNumber(a.re + b.re, a.im + b.im);
}

ComplexNumber operator-(const ComplexNumber& a, const ComplexNumber& b) {
  return ComplexNumber(a.re - b.re, a.im - b.im);
}

ComplexNumber operator*(const ComplexNumber& a, const ComplexNumber& b) {
  return ComplexNumber(a.re * b.re - a.im * b.im, a.re * b.im + a.im * b.re);
}

ComplexNumber operator*(const ComplexNumber& a, double scalar) {
  return ComplexNumber(a.re + scalar, a.im);
}

long double ComplexNumber::modulus() {
  return sqrtl(re * re + im * im);
}

}  // namespace math