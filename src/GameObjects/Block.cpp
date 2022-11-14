//
// Created by MLG Erwich on 09/02/2022.
//

#include "Block.h"
Block::Block(sf::RenderWindow& game_window) : GameObject(game_window)
{
  score = 10;
  visible = true;
}

Block::~Block() = default;

bool Block::init()
{
  if (!texture_colors[0].loadFromFile("Data/Images/element_blue_square.png")) return false;
  if (!texture_colors[1].loadFromFile("Data/Images/element_green_square.png")) return false;
  if (!texture_colors[2].loadFromFile("Data/Images/element_grey_square.png")) return false;
  if (!texture_colors[3].loadFromFile("Data/Images/element_purple_square.png")) return false;
  if (!texture_colors[4].loadFromFile("Data/Images/element_red_square.png")) return false;
  if (!texture_colors[5].loadFromFile("Data/Images/element_yellow_square.png")) return false;

  texture = texture_colors[random(0, 5)];
  sprite.setTexture(texture);
  sprite.scale(2, 2);


  return true;
}

void Block::setVisibility(bool visibility) { visible = visibility; }
bool Block::getVisibility() const { return visible; }

void Block::setPosition(float x, float y) { sprite.setPosition(x, y); }

int Block::getScore() const { return score; }

void Block::update(float dt)
{

}

void Block::render()
{
  if (visible)
  {
    window.draw(sprite);
  }
}
