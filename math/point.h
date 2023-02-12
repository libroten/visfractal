#ifndef MATH_POINT_H_
#define MATH_POINT_H_

namespace math {

struct Point {
  long double x, y;

  Point() = default;
  Point(double x_val, double y_val) : x(x_val), y(y_val) {}
};

}  // namespace math

#endif  // MATH_POINT_H_