//
// Created by p2-erwich on 04/02/2022.
//

#include "GameStateBase.h"
#include "../Extras/Helper.h"

#ifndef BREAKOUTSFML_GAMEMENU_H
#define BREAKOUTSFML_GAMEMENU_H

class GameMenu : public GameStateBase
{
 public:
  GameMenu(STATE state_id, sf::RenderWindow& game_window);
  ~GameMenu() = default;
  bool init();
  STATE input(sf::Event event) override;
  STATE update(float dt) override;
  void render() override;

 private:
  const sf::Color cDefault = sf::Color::White;
  const sf::Color cSelected = sf::Color::Red;
  sf::Font font;
  sf::Text text_title;
  sf::Text text_play;
  sf::Text text_exit;
  bool menu_option;
};

#endif // BREAKOUTSFML_GAMEMENU_H
