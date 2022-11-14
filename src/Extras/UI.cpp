//
// Created by MLG Erwich on 10/02/2022.
//

#include "UI.h"
UI::UI(sf::RenderWindow& game_window) : window(game_window)
{
  current_lives = MAX_LIFE_COUNT;
  score = 0;
}

UI::~UI() = default;

bool UI::init()
{
  if (!font.loadFromFile("Data/Fonts/OpenSans-Bold.ttf"))
  {
    std::cout << "Font didn't load!" << std::endl;
    return false;
  }
  if (!texture.loadFromFile("Data/Images/life.png"))
  {
    std::cout << "Heart texture didn't load!" << std::endl;
    return false;
  }

  Helper::SFMLText(text_score, "SCORE: ", font, 18,
                   sf::Color::White, (float)window.getSize().x - 100, 10);

  for (int i = 0; i < MAX_LIFE_COUNT; i++)
  {
    lives[i].setTexture(texture);
    lives[i].setPosition(20 + 50 * i, 10);
    lives[i].scale(0.05, 0.05);
  }
  return true;
}

void UI::reset()
{
  score = 0;
  current_lives = MAX_LIFE_COUNT;
  text_score.setString("SCORE: " + std::to_string(score));
}

int UI::getScore() { return score; }
void UI::addScore(int points) {score += points;}

void UI::reduceLives() {current_lives--;}

STATE UI::update()
{
  text_score.setString("SCORE: " + std::to_string(score));
  if (current_lives == 0)
  {
    return STATE::GAME_OVER;
  }
  return STATE::GAME_PLAY;
}

void UI::render()
{
  window.draw(text_score);
  for (int i = 0; i < current_lives; i++)
  {
    window.draw(lives[i]);
  }
}
