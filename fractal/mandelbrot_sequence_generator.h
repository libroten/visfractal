#ifndef FRACTAL_MANDELBROT_SEQUENCE_GENERATOR_H_
#define FRACTAL_MANDELBROT_SEQUENCE_GENERATOR_H_

#include "math/complex_number.h"

namespace fractal {

class MandelbrotSequenceGenerator {
 public:
  MandelbrotSequenceGenerator(math::ComplexNumber initial,
                              math::ComplexNumber c);

  math::ComplexNumber Next();

 private:
  math::ComplexNumber initial_;
  math::ComplexNumber constant_;

  math::ComplexNumber previous_;

  bool generation_started_ = false;
};

}  // namespace fractal

#endif  // FRACTAL_MANDELBROT_SEQUENCE_GENERATOR_H_