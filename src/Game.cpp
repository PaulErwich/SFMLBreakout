
#include "Game.h"
#include <iostream>

Game::Game(sf::RenderWindow& game_window)
  : window(game_window)
{
  game_menu = new GameMenu(STATE::GAME_MENU, game_window);
  game_play = new GamePlay(STATE::GAME_PLAY, game_window);
  game_over = new GameOver(STATE::GAME_OVER, game_window);
  current_state = game_menu;
}

Game::~Game()
{
  delete game_menu;
  delete game_play;
  delete game_over;
  delete current_state;
}

bool Game::init()
{
  if (game_menu->init() && game_play->init() && game_over->init())
  {
    return true;
  }
  return false;
}

void Game::reset()
{
  game_play->reset();
}

void Game::switchState(STATE state_id)
{
  if (current_state->getStateID() == state_id)
  {

  }
  else
  {
    switch(state_id)
    {
      case STATE::GAME_EXIT:
        std::cout << "Exit" << std::endl;
        window.close();
        break;
      case STATE::GAME_MENU:
        std::cout << "Menu" << std::endl;
        current_state = game_menu;
        break;
      case STATE::GAME_PLAY:
        game_play->reset();
        std::cout << "Play" << std::endl;
        current_state = game_play;
        break;
      case STATE::GAME_OVER:
        if (game_play->getWin()) game_over->setGameOverText("YOU WIN");
        game_over->setScore(game_play->getUIScore());
        std::cout << "Over" << std::endl;
        current_state = game_over;
        break;
      default:
        std::cout << "default" << std::endl;
        break;
    }
  }
}

void Game::mouseClicked(sf::Event event)
{
  //get the click position
  sf::Vector2i click = sf::Mouse::getPosition(window);
}

void Game::input(sf::Event event)
{
  switchState(current_state->input(event));
}

void Game::update(float dt)
{
  switchState(current_state->update(dt));
}

void Game::render()
{
  current_state->render();
}



