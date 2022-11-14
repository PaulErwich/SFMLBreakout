//
// Created by p2-erwich on 04/02/2022.
//

#include "Paddle.h"
Paddle::Paddle(sf::RenderWindow& game_window) : GameObject(game_window)
{
}

Paddle::~Paddle()
{

}

bool Paddle::init()
{
  if (!texture.loadFromFile("Data/Images/paddleBlue.png"))
  {
    std::cout << "Paddle didn't load!" << std::endl;
    return false;
  }
  sprite.setTexture(texture);
  sprite.setPosition(window.getSize().x / 2 - sprite.getGlobalBounds().width / 2, window.getSize().y - 100);

  return true;
}

void Paddle::reset()
{
  sprite.setPosition(window.getSize().x / 2 - sprite.getGlobalBounds().width / 2, window.getSize().y - 100);
}

void Paddle::input(sf::Event event)
{
  if (event.type == sf::Event::KeyPressed)
  {
    if (event.key.code == sf::Keyboard::A)
    {
      vector->x = -1;
    }
    else if (event.key.code == sf::Keyboard::D)
    {
      vector->x = 1;
    }
  }

  if (event.type == sf::Event::KeyReleased)
  {
    if (event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::D)
    {
      vector->x = 0;
    }
  }
}

void Paddle::update(float dt)
{
  if (sprite.getPosition().x < 0)
  {
    sprite.setPosition(0, sprite.getPosition().y);
  }
  if (sprite.getPosition().x + sprite.getGlobalBounds().width > window.getSize().x)
  {
    sprite.setPosition(window.getSize().x - sprite.getGlobalBounds().width, sprite.getPosition().y);
  }
  sprite.move(vector->x * SPEED * dt, vector->y);
}

void Paddle::render()
{
  window.draw(sprite);
}
