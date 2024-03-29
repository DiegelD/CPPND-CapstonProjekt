#include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"
#include "obstacle.h"

int main() {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};
  
  Obstacle obstacle(kGridWidth, kGridHeight);
  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight, obstacle);
  Controller controller;
  Game game(kGridWidth, kGridHeight, obstacle);
  game.Run(controller, renderer, kMsPerFrame);
  std::cout << "Game has terminated successfully!\n";
  std::cout << "Score: " << game.GetScore() << "\n";
  std::cout << "Size: " << game.GetSize() << "\n";
  return 0;
}