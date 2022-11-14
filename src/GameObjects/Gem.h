//
// Created by MLG Erwich on 10/02/2022.
//

#include "GameObject.h"

#ifndef BREAKOUTSFML_GEM_H
#define BREAKOUTSFML_GEM_H

class Gem : public GameObject
{
 public:
  Gem(sf::RenderWindow& game_window);
  ~Gem();
  bool init() override;

  bool getVisibility() const;
  void resetPosition();
  int getScore() const;
  bool collisions(GameObject& paddle);

  void update(float dt) override;
  void render() override;

 private:
  sf::Texture texture_colors[6];
  const int SPEED = 75;
  bool visible;
  int score;
  int spawn_timer;
  sf::Clock spawn_time;
};

#endif // BREAKOUTSFML_GEM_H
