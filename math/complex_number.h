#ifndef MATH_COMPLEX_NUMBER_H_
#define MATH_COMPLEX_NUMBER_H_

namespace math {

struct ComplexNumber {
  ComplexNumber();
  ComplexNumber(long double re, long double im);

  long double modulus();

  long double re;
  long double im;
};

ComplexNumber operator+(const ComplexNumber& a, const ComplexNumber& b);
ComplexNumber operator-(const ComplexNumber& a, const ComplexNumber& b);
ComplexNumber operator*(const ComplexNumber& a, const ComplexNumber& b);

ComplexNumber operator*(const ComplexNumber& a, double scalar);

}  // namespace math

#endif  // MATH_COMPLEX_NUMBER_H_