//
// Created by p2-erwich on 04/02/2022.
//

#include "GameObject.h"

#ifndef BREAKOUTSFML_PADDLE_H
#define BREAKOUTSFML_PADDLE_H

class Paddle : public GameObject
{
 public:
  Paddle(sf::RenderWindow& game_window);
  ~Paddle();
  bool init() override;
  void reset();
  void input(sf::Event event);
  void update(float dt) override;
  void render() override;
 private:
  const float SPEED = 400;
};

#endif // BREAKOUTSFML_PADDLE_H
