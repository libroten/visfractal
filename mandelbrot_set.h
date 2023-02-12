#include "fractal/mandelbrot_sequence_generator.h"
#include "graphics/display_plot.h"
#include "graphics/pixel.h"
#include "math/point.h"

#include <SFML/Graphics.hpp>
#include <cstddef>

class MandelbrotSet {
 public:
  MandelbrotSet(std::size_t window_width,
                std::size_t window_height,
                math::Point plot_from,
                math::Point plot_to,
                size_t max_iterations);

  void Generate();
  const sf::Image& GetImage();

 private:
  void EvalPixel(graphics::Pixel p);
  sf::Color GetColorByIterations(std::size_t iterations);

  sf::Image set_plot_;

  std::size_t win_width_;
  std::size_t win_height_;

  std::size_t max_iterations_;

  graphics::DisplayPlot plot_converter_;
};
