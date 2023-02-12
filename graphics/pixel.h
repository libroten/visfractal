#ifndef GRAPHICS_PIXEL_H_
#define GRAPHICS_PIXEL_H_

#include <cstddef>

namespace graphics {

struct Pixel {
  std::size_t x, y;

  Pixel() = default;
  Pixel(std::size_t x_val, std::size_t y_val) : x(x_val), y(y_val) {}
};

}  // namespace graphics

#endif  // GRAPHICS_PIXEL_H_