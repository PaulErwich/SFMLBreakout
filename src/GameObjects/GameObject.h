//
// Created by p2-erwich on 04/02/2022.
//

#include <SFML/Graphics.hpp>
#include <iostream>
#include "../Vector2.h"

#define random(min, max) rand() % (max + 1 - min) + min // The function I've used to generate random numbers

#ifndef BREAKOUTSFML_GAMEOBJECT_H
#define BREAKOUTSFML_GAMEOBJECT_H

class GameObject
{
 public:
  GameObject(sf::RenderWindow &game_window);
  ~GameObject();
  sf::Sprite getSprite();
  Vector2 getVector();
  void setVector(float x, float y);
  float SweptAABB(GameObject& obj_1, GameObject& obj_2, float& normal_x, float& normal_y, float dt);
  virtual bool init() = 0;
  virtual void update(float dt) = 0;
  virtual void render() = 0;

 protected:
  sf::RenderWindow &window;
  sf::Texture texture;
  sf::Sprite sprite;
  Vector2 *vector;
};

#endif // BREAKOUTSFML_GAMEOBJECT_H
