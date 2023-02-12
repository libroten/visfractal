#include "graphics/display_plot.h"
#include "math/point.h"

#include <cassert>

namespace graphics {

DisplayPlot::DisplayPlot(std::size_t win_width,
                         std::size_t win_height,
                         math::Point min,
                         math::Point max)
    : min_(min),
      max_(max),
      window_width_(win_width),
      window_height_(win_height) {
  assert(min.x < max.x);
  assert(min.y < max.y);

  CorrectPlotRatio();
}

math::Point DisplayPlot::GetPlotPoint(Pixel p) {
  math::Point point;

  long double x_length = max_.x - min_.x;
  long double y_length = max_.y - min_.y;

  long double x_per_pixel = x_length / window_width_;
  long double y_per_pixel = y_length / window_height_;

  point.x = min_.x + p.x * x_per_pixel;
  point.y = max_.y - p.y * y_per_pixel;

  return point;
}

void DisplayPlot::CorrectPlotRatio() {
  long double plot_width = max_.x - min_.x;
  long double plot_height = max_.y - min_.y;

  long double win_ratio = window_width_ * 1.0 / window_height_;
  long double plot_ratio = plot_width / plot_height;

  long double multiplier = win_ratio / plot_ratio;

  min_.x *= multiplier;
  max_.x *= multiplier;
}

}  // namespace graphics