//
// Created by MLG Erwich on 10/02/2022.
//

#include <SFML/Graphics.hpp>
#include <iostream>
#include "../GameStates/GameStateBase.h"
#include "Helper.h"

#ifndef BREAKOUTSFML_UI_H
#define BREAKOUTSFML_UI_H

class UI
{
 public:
  UI(sf::RenderWindow& game_window);
  ~UI();
  bool init();
  void reset();
  int getScore();
  void addScore(int points);
  void reduceLives();
  STATE update();
  void render();
 private:
  sf::RenderWindow& window;
  static const int MAX_LIFE_COUNT = 3;
  int current_lives;
  int score;
  sf::Font font;
  sf::Text text_score;
  sf::Texture texture;
  sf::Sprite lives[MAX_LIFE_COUNT];
};

#endif // BREAKOUTSFML_UI_H
