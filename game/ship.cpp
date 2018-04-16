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

  //move(dt * (direction ? 1.0f : -1.0f) * speed, 0);

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

Ally::Ally() : Ship() {}

bool Ally::direction = 20;
float Ally::speed = 20;

Ally::Ally(sf::IntRect ir, sf::Vector2f pos) : Ship(ir)
{
  setOrigin(16, 16);
  setPosition(pos);
}

void Ally::Update(const float &dt)
{
  Ship::Update(dt);

  move(dt * (direction ? 1.0f : -1.0f) * speed, 0);

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

Enemy::Enemy() : Ship() {}

bool Enemy::direction = 20;
float Enemy::speed = 20;

Enemy::Enemy(sf::IntRect ir, sf::Vector2f pos) : Ship(ir)
{
  setOrigin(16, 16);
  setPosition(pos);
}

void Enemy::Update(const float &dt)
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
