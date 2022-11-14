//
// Created by p2-erwich on 04/02/2022.
//

#include "GameObject.h"
#include "../Vector2.h"
#include "Block.h"

#ifndef BREAKOUTSFML_BALL_H
#define BREAKOUTSFML_BALL_H

class Ball : public GameObject
{
 public:
  Ball(sf::RenderWindow& game_window);
  ~Ball();
  void resetPosition();
  void wallCollision();
  bool bottomCollision();
  void paddleCollision(GameObject& paddle);
  void blockCollision(Block& block, sf::Clock& timer);

  bool init() override;
  void update(float dt) override;
  void render() override;
 private:
  const float BALL_SPEED = 100.0f;
  sf::Clock spawn_timer;
};

#endif // BREAKOUTSFML_BALL_H
