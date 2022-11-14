//
// Created by p2-erwich on 04/02/2022.
//

#include "Ball.h"

Ball::Ball(sf::RenderWindow& game_window) :
  GameObject(game_window)
{
}

Ball::~Ball()
{
}

bool Ball::init()
{
  if (!texture.loadFromFile("Data/Images/ballBlue.png"))
  {
    std::cout << "Ball didn't load";
    return false;
  }
  sprite.setTexture(texture);
  sprite.setPosition(window.getSize().x / 2 - sprite.getGlobalBounds().width / 2, window.getSize().y - 300);
  sprite.scale(1.5, 1.5);
  setVector(1, 2);
  std::cout << vector->x << ", " << vector->y << std::endl;

  return true;
}

void Ball::resetPosition()
{
  sprite.setPosition(window.getSize().x / 2 - sprite.getGlobalBounds().width / 2,
                     window.getSize().y - 300);
  vector->x = -vector->x;
  spawn_timer.restart();

}

void Ball::wallCollision()
{
  if ((sprite.getPosition().x < 0 && vector->x < 0) ||
      (sprite.getPosition().x + sprite.getGlobalBounds().width > window.getSize().x && vector->x > 0))
  {
    vector->x = -vector->x;
    std::cout << "bounce? - left/right" << std::endl;
  }

  if (sprite.getPosition().y < 0 && vector->y < 0)
  {
    vector->y = -vector->y;
    std::cout << "bounce? - top" << std::endl;
  }
}

bool Ball::bottomCollision()
{
  if (sprite.getPosition().y > window.getSize().y && vector->y > 0)
  {
    resetPosition();
    return true;
  }
  return false;
}

void Ball::paddleCollision(GameObject& paddle)
{
  if (sprite.getPosition().y + sprite.getGlobalBounds().height > paddle.getSprite().getPosition().y &&
      sprite.getPosition().y < paddle.getSprite().getPosition().y + paddle.getSprite().getGlobalBounds().height &&
      sprite.getPosition().x < paddle.getSprite().getPosition().x + paddle.getSprite().getGlobalBounds().width &&
      sprite.getPosition().x + sprite.getGlobalBounds().width > paddle.getSprite().getPosition().x &&
      vector->y > 0)
  {
    vector->y = -vector->y;
  }
}

void Ball::blockCollision(Block& block, sf::Clock& timer)
{
  if (sprite.getPosition().y + sprite.getGlobalBounds().height > block.getSprite().getPosition().y &&
      sprite.getPosition().y < block.getSprite().getPosition().y + block.getSprite().getGlobalBounds().height &&
      sprite.getPosition().x < block.getSprite().getPosition().x + block.getSprite().getGlobalBounds().width &&
      sprite.getPosition().x + sprite.getGlobalBounds().width > block.getSprite().getPosition().x &&
      timer.getElapsedTime().asMilliseconds() >= 17)
  {
    block.setVisibility(false);
    if (sprite.getPosition().x < block.getSprite().getPosition().x + block.getSprite().getGlobalBounds().width ||
        sprite.getPosition().x + sprite.getGlobalBounds().width > block.getSprite().getPosition().x)
    {
      vector->x = -vector->x;
    }
    if (sprite.getPosition().y < block.getSprite().getPosition().x + block.getSprite().getGlobalBounds().height ||
        sprite.getPosition().y + sprite.getGlobalBounds().height > block.getSprite().getPosition().y)
    {
      vector->y = -vector->y;
    }
    timer.restart();
  }
}

void Ball::update(float dt)
{
  if (spawn_timer.getElapsedTime().asSeconds() > 1)
  {
    sprite.move(vector->x * dt * BALL_SPEED, vector->y * dt * BALL_SPEED);
  }
  wallCollision();
}

void Ball::render()
{
  window.draw(sprite);
}

