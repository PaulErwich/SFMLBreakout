//
// Created by p2-erwich on 04/02/2022.
//

#include "GameStateBase.h"
#include "../GameObjects/Ball.h"
#include "../GameObjects/Paddle.h"
#include "../GameObjects/Block.h"
#include "../Extras/UI.h"
#include "../GameObjects/Gem.h"

#ifndef BREAKOUTSFML_GAMEPLAY_H
#define BREAKOUTSFML_GAMEPLAY_H

class GamePlay : public GameStateBase
{
 public:
  GamePlay(STATE state_id, sf::RenderWindow& game_window);
  ~GamePlay();
  bool init();
  void reset();
  bool getWin();
  int getUIScore();
  void blockCollision(Block &block, float dt);
  STATE input(sf::Event event) override;
  STATE update(float dt) override;
  void render() override;

 private:
  static const int GRID_WIDTH = 15;
  static const int GRID_HEIGHT = 5;
  static const int MAX_GEMS = 3;
  Ball *ball;
  Paddle *paddle;
  Block *blocks[GRID_WIDTH * GRID_HEIGHT];
  UI *ui;
  Gem *gems[MAX_GEMS];
  bool win;
};

#endif // BREAKOUTSFML_GAMEPLAY_H
