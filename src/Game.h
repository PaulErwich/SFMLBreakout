
#ifndef BREAKOUT_GAME_H
#define BREAKOUT_GAME_H

#include <SFML/Graphics.hpp>
#include "Vector2.h"
#include "GameStates/GameStateHeader.h"


class Game
{
 public:
  Game(sf::RenderWindow& window);
  ~Game();
  bool init();
  void reset();
  void switchState(STATE state_id);
  void mouseClicked(sf::Event event);
  void input(sf::Event event);
  void update(float dt);
  void render();

 private:
  sf::RenderWindow& window;
  GameStateBase *current_state;
  GameMenu *game_menu;
  GamePlay *game_play;
  GameOver * game_over;

};

#endif // BREAKOUT_GAME_H
