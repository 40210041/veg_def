#include "ship.h"
#include "game.h"

using namespace sf;
using namespace std;

Ship::Ship() {};

Ship::Ship(IntRect ir) : Sprite()
{
  _sprite = ir;
  setTexture(spritesheet);
  setTextureRect(_sprite);
};

void Ship::Update(const float &dt) {}

// define the ship deconstructor
// although we est this to pure virtual, we still have to define it
Ship::~Ship() = default;

Base::Base() : Ship() {}

bool Base::direction = 20;
float Base::speed = 20;

Base::Base(sf::IntRect ir, sf::Vector2f pos) : Ship(ir)
{
  setOrigin(16, 16);
  setPosition(pos);
}

void Base::Update(const float &dt)
{
  Ship::Update(dt);

  if ((direction && getPosition().x > gameWidth - 16) ||
    (!direction && getPosition().x < 16))
    {
      // change direction
      direction = !direction;
      for (int i = 0; i < ships.size(); i++)
      {
        // moves ships down 24 pixels
        ships[i]->move(0, 24);
      }
    }
}

//carrot class
AllyCarrot::AllyCarrot() : Ship() {}

bool AllyCarrot::direction = 20;
float AllyCarrot::speed = 80;

AllyCarrot::AllyCarrot(sf::IntRect ir, sf::Vector2f pos) : Ship(ir)
{
  setOrigin(16, 16);
  setPosition(pos);
}

void AllyCarrot::Update(const float &dt)
{
  Ship::Update(dt);

  move(dt * (direction ? 1.0f : -1.0f) * speed, 0);

  if ((direction && getPosition().x > gameWidth - 300) ||
    (!direction && getPosition().x < 16))
    {
      // change direction
      speed = 0;
    }
}


//tomato class
AllyTomato::AllyTomato() : Ship() {}

bool AllyTomato::direction = 20;
float AllyTomato::speed = 80;

AllyTomato::AllyTomato(sf::IntRect ir, sf::Vector2f pos) : Ship(ir)
{
  setOrigin(16, 16);
  setPosition(pos);
}

void AllyTomato::Update(const float &dt)
{
  Ship::Update(dt);

  move(dt * (direction ? 1.0f : -1.0f) * speed, 0);

  if ((direction && getPosition().x > gameWidth - 300) ||
    (!direction && getPosition().x < 16))
    {
      // change direction
      speed = 0;
    }
}

//pear class
AllyPear::AllyPear() : Ship() {}

bool AllyPear::direction = 20;
float AllyPear::speed = 80;

AllyPear::AllyPear(sf::IntRect ir, sf::Vector2f pos) : Ship(ir)
{
  setOrigin(16, 16);
  setPosition(pos);
}

void AllyPear::Update(const float &dt)
{
  Ship::Update(dt);

  move(dt * (direction ? 1.0f : -1.0f) * speed, 0);

  if ((direction && getPosition().x > gameWidth - 300) ||
    (!direction && getPosition().x < 16))
    {
      // change direction
      speed = 0;
    }
}

//donut class
EnemyDonut::EnemyDonut() : Ship() {}

bool EnemyDonut::direction = 20;
float EnemyDonut::speed = 80;

EnemyDonut::EnemyDonut(sf::IntRect ir, sf::Vector2f pos) : Ship(ir)
{
  setOrigin(16, 16);
  setPosition(pos);
}

void EnemyDonut::Update(const float &dt)
{
  Ship::Update(dt);

  move(dt * (direction ? -1.0f : 1.0f) * speed, 0);

  if ((direction && getPosition().x > gameWidth - 16) ||
    (!direction && getPosition().x < 16))
    {
      // change direction
      direction = !direction;
      for (int i = 0; i < ships.size(); i++)
      {
        // moves ships down 24 pixels
        ships[i]->move(0, 24);
      }
    }
}


//donut class
EnemyChocolate::EnemyChocolate() : Ship() {}

bool EnemyChocolate::direction = 20;
float EnemyChocolate::speed = 80;

EnemyChocolate::EnemyChocolate(sf::IntRect ir, sf::Vector2f pos) : Ship(ir)
{
  setOrigin(16, 16);
  setPosition(pos);
}

void EnemyChocolate::Update(const float &dt)
{
  Ship::Update(dt);

  move(dt * (direction ? -1.0f : 1.0f) * speed, 0);

  if ((direction && getPosition().x > gameWidth - 16) ||
    (!direction && getPosition().x < 16))
    {
      // change direction
      direction = !direction;
      for (int i = 0; i < ships.size(); i++)
      {
        // moves ships down 24 pixels
        ships[i]->move(0, 24);
      }
    }
}


//donut class
EnemyHotdog::EnemyHotdog() : Ship() {}

bool EnemyHotdog::direction = 20;
float EnemyHotdog::speed = 80;

EnemyHotdog::EnemyHotdog(sf::IntRect ir, sf::Vector2f pos) : Ship(ir)
{
  setOrigin(16, 16);
  setPosition(pos);
}

void EnemyHotdog::Update(const float &dt)
{
  Ship::Update(dt);

  move(dt * (direction ? -1.0f : 1.0f) * speed, 0);

  if ((direction && getPosition().x > gameWidth - 16) ||
    (!direction && getPosition().x < 16))
    {
      // change direction
      direction = !direction;
      for (int i = 0; i < ships.size(); i++)
      {
        // moves ships down 24 pixels
        ships[i]->move(0, 24);
      }
    }
}
