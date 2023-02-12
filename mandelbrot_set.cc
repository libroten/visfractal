#include "mandelbrot_set.h"

#include <SFML/Graphics/Color.hpp>
#include <cmath>
#include <cstddef>
#include <iostream>

#include "fractal/mandelbrot_sequence_generator.h"
#include "graphics/pixel.h"
#include "math/complex_number.h"

MandelbrotSet::MandelbrotSet(std::size_t window_width,
                             std::size_t window_height,
                             math::Point plot_from,
                             math::Point plot_to,
                             size_t max_iterations)
    : win_width_(window_width),
      win_height_(window_height),
      plot_converter_(window_width, window_height, plot_from, plot_to),
      max_iterations_(max_iterations) {
  set_plot_.create(window_width, window_height, sf::Color::White);
}

void MandelbrotSet::Generate() {
  std::cout << "Evaluating mandelbrot set..." << std::endl;

  for (std::size_t y = 0; y < win_height_; y++) {
    for (std::size_t x = 0; x < win_width_; x++) {
      EvalPixel(graphics::Pixel(x, y));
    }
  }
}

void MandelbrotSet::EvalPixel(graphics::Pixel p) {
  int total_pixels = win_height_ * win_width_;
  int current_pixel_idx = win_width_ * p.y + p.x;

  std::cout << "Evaluated: " << (current_pixel_idx * 100 / total_pixels) << "%"
            << std::endl;

  const sf::Color kIncludedColor = sf::Color::White;
  const sf::Color kExcludedColor = sf::Color::Black;

  auto point = plot_converter_.GetPlotPoint(p);

  fractal::MandelbrotSequenceGenerator generator(
      math::ComplexNumber(0, 0), math::ComplexNumber(point.x, point.y));

  for (int i = 0; i < max_iterations_; i++) {
    auto sequence_member = generator.Next();

    auto modulus = sequence_member.modulus();
    if (!std::isfinite(modulus)) {
      set_plot_.setPixel(p.x, p.y, GetColorByIterations(i));

      return;
    }
  }

  set_plot_.setPixel(p.x, p.y, kIncludedColor);
}

const sf::Image& MandelbrotSet::GetImage() {
  return set_plot_;
}

sf::Color MandelbrotSet::GetColorByIterations(std::size_t iterations) {
  constexpr float kBoundMultiplier = 0.1;

  std::size_t lower_bound_iterations =
      static_cast<size_t>(max_iterations_ * kBoundMultiplier);

  if (iterations <= lower_bound_iterations) {
    return sf::Color::Black;
  }

  float iterations_range_length = max_iterations_ - lower_bound_iterations;
  int brightness = static_cast<int>(
      ((iterations - lower_bound_iterations) / iterations_range_length) * 255);

  if (brightness > 255) {
    brightness = 255;
  }

  return sf::Color(brightness, 0, 0);
}
