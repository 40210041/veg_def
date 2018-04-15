//unit.h
#pragma once
#include <SFML/Graphics.hpp>

class Ship : public sf::Sprite
{
protected:
  sf::IntRect _sprite;
  //default constructor is hidden
  Ship();

public:
  //constructor that takes a sprite
  explicit Ship(sf::IntRect ir);
  //pure virtual deconstructor -- makes this an abstract class
  virtual ~Ship() = 0;
  //update, virtual so can be overrided, but not pure virtual
  virtual void Update(const float &dt);
};

//3.5
class Invader : public Ship
{
public:
  //3.5.1
  static bool direction;
  static float speed;
  Invader(sf::IntRect ir, sf::Vector2f pos);
  Invader();
  void Update(const float &dt) override;
};

//3.6 add player class
class Player : public Ship
{
public:
  Player();
  void Update(const float &dt) override;
};
