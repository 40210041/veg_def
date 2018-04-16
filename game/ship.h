#pragma once
#include <SFML/Graphics.hpp>

class Ship : public sf::Sprite
{
protected:
  sf::IntRect _sprite;
  // default constructor is hidden
  Ship();
public:
  // constructor that takes a sprite
  explicit Ship(sf::IntRect ir);
  // pure virtual deconstructor -- makes this an abstract class
  virtual ~Ship() = 0;
  // update virtual so can be overrided, but not pure virtual
  virtual void Update(const float &dt);
};

class Base : public Ship
{
public:
  static int health;
  static bool direction;
  static float speed;
  Base(sf::IntRect ir, sf::Vector2f pos);
  Base();
  void Update(const float &dt) override;
};

class Ally : public Ship
{
public:
  static int health;
  static int damage;
  static bool direction;
  static float speed;
  Ally(sf::IntRect ir, sf::Vector2f pos);
  Ally();
  void Update(const float &dt) override;
};

class Enemy : public Ship
{
public:
  static int health;
  static int damage;
  static bool direction;
  static float speed;
  Enemy(sf::IntRect ir, sf::Vector2f pos);
  Enemy();
  void Update(const float &dt) override;
};
