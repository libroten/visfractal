#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <cmath>
#include <cstddef>
#include <iostream>

#include "mandelbrot_set.h"

namespace {
constexpr std::size_t kWidth = 1920;
constexpr std::size_t kHeight = 1080;

constexpr char kWindowTitle[] = "Fractal";

constexpr char kOutputFile[] = "result.png";

const math::Point kPlotMin(-2, -1);
const math::Point kPlotMax(1, 1);

constexpr std::size_t kIterations = 100;
}  // namespace

int main() {
  MandelbrotSet set(kWidth, kHeight, kPlotMin, kPlotMax, kIterations);

  set.Generate();
  set.GetImage().saveToFile(kOutputFile);

  sf::Texture texture;
  texture.loadFromImage(
      set.GetImage(),
      sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(kWidth, kHeight)));

  sf::Sprite sprite(texture);

  sf::RenderWindow win(sf::VideoMode(kWidth, kHeight), kWindowTitle);

  while (win.isOpen()) {
    sf::Event evt;
    while (win.pollEvent(evt)) {
      if (evt.type == sf::Event::Closed) {
        win.close();
      }
    }

    win.draw(sprite);
    win.display();
  }

  return 0;
}