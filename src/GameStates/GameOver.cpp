//
// Created by p2-erwich on 04/02/2022.
//

#include "GameOver.h"
GameOver::GameOver(STATE state_id, sf::RenderWindow& game_window) :
  GameStateBase(state_id, game_window)
{

}

bool GameOver::init()
{
  if (!font.loadFromFile("Data/Fonts/OpenSans-Bold.ttf"))
  {
    std::cout << "Font didn't load!" << std::endl;
    return false;
  }

  Helper::SFMLText(text_game_over, "GAME OVER", font, 72, cDefault,
                   window.getSize().x / 2, window.getSize().y / 8);
  Helper::SFMLText(text_score, "FINAL SCORE: ", font, 36, cDefault,
                   window.getSize().x / 2, window.getSize().y / 2);
  Helper::SFMLText(text_menu, "PRESS ENTER TO RETURN TO MENU", font, 36, cDefault,
                   window.getSize().x / 2, window.getSize().y / 4 + window.getSize().y / 2);

  return true;
}

void GameOver::setScore(int score)
{
  text_score.setString("FINAL SCORE: " + std::to_string(score));
}

void GameOver::setGameOverText(const std::string& string) {text_game_over.setString(string);}

STATE GameOver::input(sf::Event event)
{
  if (event.key.code == sf::Keyboard::Enter)
  {
    return STATE::GAME_MENU;
  }
  return game_state_id;
}

STATE GameOver::update(float dt)
{
  return game_state_id;
}

void GameOver::render()
{
  window.draw(text_game_over);
  window.draw(text_score);
  window.draw(text_menu);
}

