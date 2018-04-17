#include "unit.h"
#include "game.h"

using namespace sf;
using namespace std;

Unit::Unit() {};

Unit::Unit(IntRect ir) : Sprite()
{
  _sprite = ir;
  setTexture(spritesheet);
  setTextureRect(_sprite);
};

void Unit::Update(const float &dt) {}

// define the unit deconstructor
// although we est this to pure virtual, we still have to define it
Unit::~Unit() = default;

//ally base
AllyBase::AllyBase() : Unit() {}
int AllyBase::health = 20;
bool AllyBase::direction = 20;
float AllyBase::speed = 20;

AllyBase::AllyBase(sf::IntRect ir, sf::Vector2f pos) : Unit(ir)
{
  setOrigin(16, 16);
  setPosition(pos);
}

void AllyBase::Update(const float &dt)
{
  Unit::Update(dt);

}

//enemy base
EnemyBase::EnemyBase() : Unit() {}
int EnemyBase::health = 20;
int EnemyBase::new_health;
bool EnemyBase::direction = 20;
float EnemyBase::speed = 20;

EnemyBase::EnemyBase(sf::IntRect ir, sf::Vector2f pos) : Unit(ir)
{
  setOrigin(16, 16);
  setPosition(pos);
}

void EnemyBase::Update(const float &dt)
{
  Unit::Update(dt);
  if (AllyCarrot::collided == true){
    new_health = (health - 20);
    health = new_health;
	printf("I have no health now!!");
  }
}

//carrot class
AllyCarrot::AllyCarrot() : Unit() {}
bool AllyCarrot::collided = false;
bool AllyCarrot::direction = 20;
float AllyCarrot::speed = 100;

AllyCarrot::AllyCarrot(sf::IntRect ir, sf::Vector2f pos) : Unit(ir)
{
  setOrigin(16, 16);
  setPosition(pos);
}

void AllyCarrot::Update(const float &dt)
{
  Unit::Update(dt);

  move(dt * (direction ? 1.0f : -1.0f) * speed, 0);

  if ((direction && getPosition().x > gameWidth - 300) ||
    (!direction && getPosition().x < 16))
    {
      // change direction
      speed = 0;
      collided = true;
      if (collided == true){
       // printf("I have collided!\n");
      }
    }
}


//tomato class
AllyTomato::AllyTomato() : Unit() {}

bool AllyTomato::direction = 20;
float AllyTomato::speed = 80;

AllyTomato::AllyTomato(sf::IntRect ir, sf::Vector2f pos) : Unit(ir)
{
  setOrigin(16, 16);
  setPosition(pos);
}

void AllyTomato::Update(const float &dt)
{
  Unit::Update(dt);

  move(dt * (direction ? 1.0f : -1.0f) * speed, 0);

  if ((direction && getPosition().x > gameWidth - 300) ||
    (!direction && getPosition().x < 16))
    {
      // change direction
      speed = 0;
    }
}

//pear class
AllyPear::AllyPear() : Unit() {}

bool AllyPear::direction = 20;
float AllyPear::speed = 80;

AllyPear::AllyPear(sf::IntRect ir, sf::Vector2f pos) : Unit(ir)
{
  setOrigin(16, 16);
  setPosition(pos);
}

void AllyPear::Update(const float &dt)
{
  Unit::Update(dt);

  move(dt * (direction ? 1.0f : -1.0f) * speed, 0);

  if ((direction && getPosition().x > gameWidth - 300) ||
    (!direction && getPosition().x < 16))
    {
      // change direction
      speed = 0;
    }
}

//donut class
EnemyDonut::EnemyDonut() : Unit() {}

bool EnemyDonut::direction = 20;
float EnemyDonut::speed = 80;

EnemyDonut::EnemyDonut(sf::IntRect ir, sf::Vector2f pos) : Unit(ir)
{
  setOrigin(16, 16);
  setPosition(pos);
}

void EnemyDonut::Update(const float &dt)
{
  Unit::Update(dt);

  move(dt * (direction ? -1.0f : 1.0f) * speed, 0);

  if ((direction && getPosition().x < 150) ||
    (!direction && getPosition().x < 16))
    {
      // change direction
      speed = 0;
    }
}


//donut class
EnemyChocolate::EnemyChocolate() : Unit() {}

bool EnemyChocolate::direction = 20;
float EnemyChocolate::speed = 80;

EnemyChocolate::EnemyChocolate(sf::IntRect ir, sf::Vector2f pos) : Unit(ir)
{
  setOrigin(16, 16);
  setPosition(pos);
}

void EnemyChocolate::Update(const float &dt)
{
  Unit::Update(dt);

  move(dt * (direction ? -1.0f : 1.0f) * speed, 0);

  if ((direction && getPosition().x < 150) ||
    (!direction && getPosition().x < 16))
    {
      // change direction
      speed = 0;
    }
}


//donut class
EnemyHotdog::EnemyHotdog() : Unit() {}

bool EnemyHotdog::direction = 20;
float EnemyHotdog::speed = 80;

EnemyHotdog::EnemyHotdog(sf::IntRect ir, sf::Vector2f pos) : Unit(ir)
{
  setOrigin(16, 16);
  setPosition(pos);
}

void EnemyHotdog::Update(const float &dt)
{
  Unit::Update(dt);

  move(dt * (direction ? -1.0f : 1.0f) * speed, 0);

  if ((direction && getPosition().x < 150) ||
    (!direction && getPosition().x < 16))
    {
      // change direction
      speed = 0;
    }
}
