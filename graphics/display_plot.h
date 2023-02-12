#ifndef GRAPHICS_DISPLAY_PLOT_H_
#define GRAPHICS_DISPLAY_PLOT_H_

#include <cstddef>

#include "graphics/pixel.h"
#include "math/point.h"

namespace graphics {

// Transforms pixel coordinates to plot coordinates.
class DisplayPlot {
 public:
  DisplayPlot(std::size_t win_width,
              std::size_t win_height,
              math::Point min,
              math::Point max);

  math::Point GetPlotPoint(Pixel p);

 private:
  void CorrectPlotRatio();

  std::size_t window_width_;
  std::size_t window_height_;

  math::Point min_;
  math::Point max_;
};

}  // namespace graphics

#endif  // GRAPHICS_DISPLAY_PLOT_H_
