//
// Created by p2-erwich on 04/02/2022.
//

#include "GameStateBase.h"
#include "../Extras/Helper.h"

#ifndef BREAKOUTSFML_GAMEOVER_H
#define BREAKOUTSFML_GAMEOVER_H

class GameOver : public GameStateBase
{
 public:
  GameOver(STATE state_id, sf::RenderWindow &game_window);
  ~GameOver() = default;
  bool init();

  void setScore(int score);
  void setGameOverText(const std::string& string);

  STATE input(sf::Event event) override;
  STATE update(float dt) override;
  void render() override;

 private:
  const sf::Color cDefault = sf::Color::White;
  sf::Font font;
  sf::Text text_game_over;
  sf::Text text_score;
  sf::Text text_menu;
};

#endif // BREAKOUTSFML_GAMEOVER_H
