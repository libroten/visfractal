#include "fractal/mandelbrot_sequence_generator.h"
#include "math/complex_number.h"

namespace fractal {

MandelbrotSequenceGenerator::MandelbrotSequenceGenerator(
    math::ComplexNumber initial,
    math::ComplexNumber c)
    : initial_(initial), constant_(c) {}

math::ComplexNumber MandelbrotSequenceGenerator::Next() {
  if (!generation_started_) {
    previous_ = initial_;
    generation_started_ = true;
    return initial_;
  }

  math::ComplexNumber next = previous_ * previous_ + constant_;
  previous_ = next;

  return next;
}

}  // namespace fractal
