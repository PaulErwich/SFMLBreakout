//
// Created by p2-erwich on 04/02/2022.
//

#include <SFML/Graphics.hpp>
#include <iostream>

#ifndef BREAKOUTSFML_GAMESTATEBASE_H
#define BREAKOUTSFML_GAMESTATEBASE_H

enum class STATE {GAME_UNKNOWN = -1, GAME_EXIT, GAME_MENU, GAME_PLAY, GAME_OVER};

class GameStateBase
{
 public:
  GameStateBase(STATE state_id, sf::RenderWindow &game_window);
  ~GameStateBase();
  STATE getStateID();
  virtual STATE input(sf::Event event);
  virtual STATE update(float dt);
  virtual void render();

 protected:
  STATE game_state_id;
  sf::RenderWindow &window;
};

#endif // BREAKOUTSFML_GAMESTATEBASE_H
