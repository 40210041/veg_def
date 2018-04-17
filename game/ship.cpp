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

//ally base
AllyBase::AllyBase() : Ship() {}
int AllyBase::health = 20;
bool AllyBase::direction = 20;
float AllyBase::speed = 20;

AllyBase::AllyBase(sf::IntRect ir, sf::Vector2f pos) : Ship(ir)
{
  setOrigin(16, 16);
  setPosition(pos);
}

void AllyBase::Update(const float &dt)
{
  Ship::Update(dt);

}

//enemy base
EnemyBase::EnemyBase() : Ship() {}
int EnemyBase::health = 20;
bool EnemyBase::direction = 20;
float EnemyBase::speed = 20;

EnemyBase::EnemyBase(sf::IntRect ir, sf::Vector2f pos) : Ship(ir)
{
  setOrigin(16, 16);
  setPosition(pos);
}

void EnemyBase::Update(const float &dt)
{
  Ship::Update(dt);
}

//carrot class
AllyCarrot::AllyCarrot() : Ship() {}

bool AllyCarrot::direction = 20;
float AllyCarrot::speed = 280;

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

  if ((direction && getPosition().x < 150) ||
    (!direction && getPosition().x < 16))
    {
      // change direction
      speed = 0;
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

  if ((direction && getPosition().x < 150) ||
    (!direction && getPosition().x < 16))
    {
      // change direction
      speed = 0;
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

  if ((direction && getPosition().x < 150) ||
    (!direction && getPosition().x < 16))
    {
      // change direction
      speed = 0;
    }
}
