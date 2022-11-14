//
// Created by p2-erwich on 04/02/2022.
//

#include "GameMenu.h"
GameMenu::GameMenu(STATE state_id, sf::RenderWindow& game_window) :
  GameStateBase(state_id, game_window)
{
  menu_option = false;
}

bool GameMenu::init()
{
  if (!font.loadFromFile("Data/Fonts/OpenSans-Bold.ttf"))
  {
    std::cout << "Font didn't load\n";
    return false;
  }

  Helper::SFMLText(text_title, "BREAKOUT", font, 72, cDefault,
                   (float)window.getSize().x / 2, (float)window.getSize().y / 8);

  Helper::SFMLText(text_play, "PLAY", font, 36, cSelected,
                   (float)window.getSize().x / 4, (float)window.getSize().y / 2);

  Helper::SFMLText(text_exit, "EXIT", font, 36, cDefault,
                   (float)window.getSize().x / 4 + (float)window.getSize().x /2, (float)window.getSize().y / 2);
  return true;
}


STATE GameMenu::input(sf::Event event)
{
  if (event.type == sf::Event::KeyPressed)
  {
    if (event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::Right)
    {
      menu_option = !menu_option;
    }

    if (event.key.code == sf::Keyboard::Enter)
    {
      if (menu_option)
      {
        return STATE::GAME_EXIT;
      }
      else if (!menu_option)
      {
        return STATE::GAME_PLAY;
      }
    }
  }

  return game_state_id;
}

STATE GameMenu::update(float dt)
{
  if (menu_option)
  {
    text_play.setFillColor(cDefault);
    text_exit.setFillColor(cSelected);
  }
  else
  {
    text_play.setFillColor(cSelected);
    text_exit.setFillColor(cDefault);
  }

  return game_state_id;
}

void GameMenu::render()
{
  window.draw(text_title);
  window.draw(text_play);
  window.draw(text_exit);
}
