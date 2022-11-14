//
// Created by p2-erwich on 04/02/2022.
//

#include "GamePlay.h"
GamePlay::GamePlay(STATE state_id, sf::RenderWindow& game_window) :
  GameStateBase(state_id, game_window)
{
  ball = new Ball(game_window);
  paddle = new Paddle(game_window);

  for (int i = 0; i < GRID_WIDTH * GRID_HEIGHT; i++)
  {
    blocks[i] = new Block(game_window);
  }
  ui = new UI(game_window);

  for (int i = 0; i < MAX_GEMS; i++)
  {
    gems[i] = new Gem(game_window);
  }
  win = false;
}

GamePlay::~GamePlay()
{
  delete ball;
  delete paddle;

  for (int i = 0; i < GRID_WIDTH * GRID_HEIGHT; i++)
  {
    delete blocks[i];
  }
  delete ui;

  for (int i = 0; i < MAX_GEMS; i++)
  {
    delete gems[i];
  }
}

bool GamePlay::init()
{
  bool block, gem;
  for (int i = 0; i < GRID_HEIGHT; i++)
  {
    for (int j = 0; j < GRID_WIDTH; j++)
    {
      if (blocks[i * GRID_WIDTH + j]->init())
      {
        blocks[i * GRID_WIDTH + j]->setPosition(20 + 70 * j, 50 + 70 * i);
        block = true;
      }
      else
      {
        block = false;
      }
    }
  }

  for (int i = 0; i < MAX_GEMS; i++)
  {
    if (gems[i]->init())
    {
      gem = true;
    }
    else
    {
      gem = false;
    }
  }

  if (ball->init() && paddle->init() && block && ui->init() && gem)
  {
    return true;
  }
  return false;
}

void GamePlay::reset()
{
  for (int i = 0; i < GRID_WIDTH * GRID_HEIGHT; i++)
  {
    blocks[i]->setVisibility(true);
  }
  for (int i = 0; i < MAX_GEMS; i++)
  {
    gems[i]->resetPosition();
  }
  ball->resetPosition();
  ui->reset();
  paddle->reset();
}

bool GamePlay::getWin() { return win; }

int GamePlay::getUIScore() { return ui->getScore(); }

void GamePlay::blockCollision(Block &block, float dt)
{
  float normalX = 0, normalY = 0;
  float collision_time = ball->SweptAABB(*ball, block, normalX, normalY, dt);
  ball->getSprite().setPosition(ball->getSprite().getPosition().x + (ball->getVector().x * collision_time),
                                ball->getSprite().getPosition().y + (ball->getVector().y * collision_time));
  float remaining_time = 1.0f - collision_time;

  if (remaining_time != 0)
  {
    std::cout << remaining_time << std::endl;
    //ball->setVector(ball->getVector().x * remaining_time, ball->getVector().y);
    //ball->setVector(ball->getVector().x, ball->getVector().y * remaining_time);

    if (std::abs(normalX) > 0.0001f)ball->setVector(-ball->getVector().x, ball->getVector().y);
    if (std::abs(normalY) > 0.0001f) ball->setVector(ball->getVector().x, -ball->getVector().y);
    block.setVisibility(false);
    ui->addScore(block.getScore());
  }
}

STATE GamePlay::input(sf::Event event)
{
  paddle->input(event);
  return game_state_id;
}

STATE GamePlay::update(float dt)
{
  int count = 0;
  ball->update(dt);
  for (int i = 0; i < GRID_WIDTH * GRID_HEIGHT; i++)
  {
    if (blocks[i]->getVisibility())
    {
      blockCollision(*blocks[i], dt);
    }
    else
    {
      count++;
    }
  }
  if (count == GRID_WIDTH * GRID_HEIGHT)
  {
    win = true;
    return STATE::GAME_OVER;
  }

  ball->paddleCollision(*paddle);
  if (ball->bottomCollision())
  {
    ui->reduceLives();
  }
  paddle->update(dt);

  for (int i = 0; i < MAX_GEMS; i++)
  {
    if (gems[i]->getVisibility())
    {
      gems[i]->update(dt);
      if (gems[i]->collisions(*paddle))
      {
        ui->addScore(gems[i]->getScore());
      }
    }
  }

  return ui->update();
}

void GamePlay::render()
{
  ball->render();
  paddle->render();
  for (int i = 0; i < GRID_WIDTH * GRID_HEIGHT; i++)
  {
    blocks[i]->render();
  }
  ui->render();
  for (int i = 0; i < MAX_GEMS; i++)
  {
    gems[i]->render();
  }
}

