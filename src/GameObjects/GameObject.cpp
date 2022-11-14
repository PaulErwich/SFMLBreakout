//
// Created by p2-erwich on 04/02/2022.
//

#include "GameObject.h"
GameObject::GameObject(sf::RenderWindow& game_window) : window(game_window)
{
  vector = new Vector2(0, 0);
}

GameObject::~GameObject()
{
  delete vector;
}

sf::Sprite GameObject::getSprite() { return sprite; }

Vector2 GameObject::getVector() {return *vector;}
void GameObject::setVector(float x, float y) { vector->x = x; vector->y = y;}


// https://www.gamedev.net/tutorials/programming/general-and-gameplay-programming/swept-aabb-collision-detection-and-response-r3084/
// Link to swept AABB code
float GameObject::SweptAABB(
  GameObject& obj_1, GameObject& obj_2, float& normal_x,
  float& normal_y, float dt)
{
  float xInvEntry, yInvEntry;
  float xInvExit, yInvExit;

  // find the distance between the objects on the near and far sides for both x and y
  if (obj_1.vector->x * dt * 100 > 0.0f)
  {
    xInvEntry =
      obj_2.sprite.getPosition().x - (obj_1.sprite.getPosition().x + obj_1.sprite.getGlobalBounds().width);
    xInvExit = (obj_2.sprite.getPosition().x + obj_2.sprite.getGlobalBounds().width) -
               obj_1.sprite.getPosition().x;
  }
  else
  {
    xInvEntry = (obj_2.sprite.getPosition().x + obj_2.sprite.getGlobalBounds().width) -
                obj_1.sprite.getPosition().x;
    xInvExit = obj_2.sprite.getPosition().x - (obj_1.sprite.getPosition().x + obj_1.sprite.getGlobalBounds().width);
  }

  if (obj_1.vector->y * dt * 100 > 0.0f)
  {
    yInvEntry = obj_2.sprite.getPosition().y - (obj_1.sprite.getPosition().y + obj_1.sprite.getGlobalBounds().height);
    yInvExit = (obj_2.sprite.getPosition().y + obj_2.sprite.getGlobalBounds().height) - obj_1.sprite.getPosition().y;
  }
  else
  {
    yInvEntry = (obj_2.sprite.getPosition().y + obj_2.sprite.getGlobalBounds().height) - obj_1.sprite.getPosition().y;
    yInvExit = obj_2.sprite.getPosition().y - (obj_1.sprite.getPosition().y + obj_1.sprite.getGlobalBounds().height);
  }

  float xEntry, yEntry;
  float xExit, yExit;

  if (obj_1.vector->x * dt * 100 == 0.0f)
  {
    xEntry = -std::numeric_limits<float>::infinity();
    xExit = std::numeric_limits<float>::infinity();
  }
  else
  {
    xEntry = xInvEntry / (obj_1.vector->x * 100 * dt);
    xExit = xInvExit / (obj_1.vector->x * 100 * dt);
  }

  if (obj_1.vector->y *dt * 100 == 0.0f)
  {
    yEntry = -std::numeric_limits<float>::infinity();
    yExit = std::numeric_limits<float>::infinity();
  }
  else
  {
    yEntry = yInvEntry / (obj_1.vector->y * dt * 100);
    yExit = yInvExit / (obj_1.vector->y * dt * 100);
  }

  // find the earliest/Latest times of collision float
  float entryTime = std::max(xEntry, yEntry);
  float exitTime = std::min(xExit, yExit);

  // if there was no collision
  //std::cout << entryTime << ", " << exitTime << ", " << xEntry << ", " << yEntry << std::endl;
  if (entryTime > exitTime || xEntry < 0.0f && yEntry < 0.0f || xEntry > 1.0f || yEntry > 1.0f)
  {
    normal_x = 0.0f;
    normal_y = 0.0f;
    return 1.0f;
  }
  else // if there was a collision
  {
    // calculate normal of collided surface
    if (xEntry > yEntry)
    {
      if (xInvEntry < 0.0f)
      {
        normal_x = 1.0f;
        normal_y = 0.0f;
      }
      else
      {
        normal_x = -1.0f;
        normal_y = 0.0f;
      }
    }
    else
    {
      if (yInvEntry < 0.0f)
      {
        normal_x = 0.0f;
        normal_y = 1.0f;
      }
      else
      {
        normal_x = 0.0f;
        normal_y = -1.0f;
      }
    }
  } // return the time of collision
  return entryTime;
}
