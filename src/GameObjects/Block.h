//
// Created by MLG Erwich on 09/02/2022.
//

#include "GameObject.h"

#ifndef BREAKOUTSFML_BLOCK_H
#define BREAKOUTSFML_BLOCK_H

class Block : public GameObject
{
 public:
  Block(sf::RenderWindow& game_window);
  ~Block();
  bool init() override;

  void setVisibility(bool visibility);
  bool getVisibility() const;
  void setPosition(float x, float y);
  int getScore() const;

  void update(float dt) override;
  void render() override;
 private:
  sf::Texture texture_colors[6];
  bool visible;
  int score;
};

#endif // BREAKOUTSFML_BLOCK_H
