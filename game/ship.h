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

//base class
class AllyBase : public Ship
{
public:
  static int health;
  static bool direction;
  static float speed;
  AllyBase(sf::IntRect ir, sf::Vector2f pos);
  AllyBase();
  void Update(const float &dt) override;
};

class EnemyBase : public Ship
{
public:
  static int health;
  static bool direction;
  static float speed;
  EnemyBase(sf::IntRect ir, sf::Vector2f pos);
  EnemyBase();
  void Update(const float &dt) override;
};

//carrot class
class AllyCarrot : public Ship
{
public:
  static int health;
  static int damage;
  static bool direction;
  static float speed;
  bool carrotSent = 0;
  AllyCarrot(sf::IntRect ir, sf::Vector2f pos);
  AllyCarrot();
  void Update(const float &dt) override;
};

//tomato class
class AllyTomato : public Ship
{
public:
  static int health;
  static int damage;
  static bool direction;
  static float speed;
  AllyTomato(sf::IntRect ir, sf::Vector2f pos);
  AllyTomato();
  void Update(const float &dt) override;
};

//pear class
class AllyPear : public Ship
{
public:
  static int health;
  static int damage;
  static bool direction;
  static float speed;
  AllyPear(sf::IntRect ir, sf::Vector2f pos);
  AllyPear();
  void Update(const float &dt) override;
};

//donut class
class EnemyDonut : public Ship
{
public:
  static int health;
  static int damage;
  static bool direction;
  static float speed;
  EnemyDonut(sf::IntRect ir, sf::Vector2f pos);
  EnemyDonut();
  void Update(const float &dt) override;
};

//chocolate class
class EnemyChocolate : public Ship
{
public:
  static int health;
  static int damage;
  static bool direction;
  static float speed;
  EnemyChocolate(sf::IntRect ir, sf::Vector2f pos);
  EnemyChocolate();
  void Update(const float &dt) override;
};

//hotdog class
class EnemyHotdog : public Ship
{
public:
  static int health;
  static int damage;
  static bool direction;
  static float speed;
  EnemyHotdog(sf::IntRect ir, sf::Vector2f pos);
  EnemyHotdog();
  void Update(const float &dt) override;
};
