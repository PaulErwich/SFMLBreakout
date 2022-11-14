//
// Created by MLG Erwich on 10/02/2022.
//

#include "Gem.h"
Gem::Gem(sf::RenderWindow& game_window) : GameObject(game_window)
{
  score = 25;
  visible = true;
  spawn_timer = random(5, 15);
}

Gem::~Gem() = default;

bool Gem::init()
{
  if (!texture_colors[0].loadFromFile("Data/Images/element_blue_polygon_glossy.png")) return false;
  if (!texture_colors[1].loadFromFile("Data/Images/element_green_polygon_glossy.png")) return false;
  if (!texture_colors[2].loadFromFile("Data/Images/element_grey_polygon_glossy.png")) return false;
  if (!texture_colors[3].loadFromFile("Data/Images/element_purple_polygon_glossy.png")) return false;
  if (!texture_colors[4].loadFromFile("Data/Images/element_red_polygon_glossy.png")) return false;
  if (!texture_colors[5].loadFromFile("Data/Images/element_yellow_polygon_glossy.png")) return false;

  texture = texture_colors[random(0, 5)];
  sprite.setTexture(texture);
  int x = random(0, (int)window.getSize().x - (int)sprite.getGlobalBounds().width);
  sprite.setPosition((float)x, -100);
  vector->y = 2;
  return true;
}

bool Gem::getVisibility() const { return visible; }

void Gem::resetPosition()
{
  int x = random(50, (int)window.getSize().x - (int)sprite.getGlobalBounds().width);
  sprite.setPosition((float)x, -100);
  spawn_timer = random(5, 15);
  spawn_time.restart();
  visible = true;
}

int Gem::getScore() const { return score; }

bool Gem::collisions(GameObject& paddle)
{
  if (sprite.getPosition().y + sprite.getGlobalBounds().height > paddle.getSprite().getPosition().y &&
      sprite.getPosition().y < paddle.getSprite().getPosition().y + paddle.getSprite().getGlobalBounds().height &&
      sprite.getPosition().x < paddle.getSprite().getPosition().x + paddle.getSprite().getGlobalBounds().width &&
      sprite.getPosition().x + sprite.getGlobalBounds().width > paddle.getSprite().getPosition().x)
  {
    visible = false;
    resetPosition();
    return true;
  }

  if (sprite.getPosition().y > window.getSize().y)
  {
    resetPosition();
  }
  return false;
}

void Gem::update(float dt)
{
  if (spawn_time.getElapsedTime().asSeconds() > spawn_timer && visible)
  {
    sprite.move(vector->x, vector->y * dt * SPEED);
  }
}

void Gem::render()
{
  if (visible)
  {
    window.draw(sprite);
  }
}
