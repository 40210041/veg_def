#include <SFML/Graphics.hpp>
#include <iostream>
#include "ship.h"
#include "game.h"

using namespace sf;
using namespace std;

sf::Texture spritesheet;
sf::Sprite invader;
std::vector<Ship *> ships;

void Load()
{
  // check if spreitesheet exists
  if (!spritesheet.loadFromFile("res/img/invaders_sheet.png"))
  {
    cerr << "Failed to load spritesheet!" << std::endl;
  }

  auto rectTowerFriendly = IntRect(50, 1900, 200, 300);
  // set the position of the unit
  Vector2f positionTowerFriendly = {50, (gameHeight - 400)};
  auto towerFriendly = new Base(rectTowerFriendly, positionTowerFriendly);
  ships.push_back(towerFriendly);

  auto rectTowerEnemy = IntRect(380, 1900, 200, 300);
  // set the position of the unit
  Vector2f positionTowerEnemy = {(gameWidth - 200), (gameHeight - 400)};
  auto towerEnemy = new Base(rectTowerEnemy, positionTowerEnemy);
  ships.push_back(towerEnemy);
}

void CreateCarrot()
{
  auto rectNewUnit1 = IntRect(50, 50, 200, 200);
  // set the position of the unit
  Vector2f positionNewUnit1 = {70, (gameHeight - 270)};
  auto newUnit1 = new AllyCarrot(rectNewUnit1, positionNewUnit1);
  ships.push_back(newUnit1);
}
void CreateTomato()
{
  auto rectNewUnit1 = IntRect(50, 370, 200, 200);
  // set the position of the unit
  Vector2f positionNewUnit1 = {70, (gameHeight - 270)};
  auto newUnit1 = new AllyTomato(rectNewUnit1, positionNewUnit1);
  ships.push_back(newUnit1);
}
void CreatePear()
{
  auto rectNewUnit1 = IntRect(50, 690, 200, 200);
  // set the position of the unit
  Vector2f positionNewUnit1 = {70, (gameHeight - 270)};
  auto newUnit1 = new AllyPear(rectNewUnit1, positionNewUnit1);
  ships.push_back(newUnit1);
}

void CreateDonut()
{
  auto rectNewUnit1 = IntRect(50, 980, 200, 200);
  // set the position of the unit
  Vector2f positionNewUnit1 = {(gameWidth - 100), (gameHeight - 270)};
  auto newUnit1 = new EnemyDonut(rectNewUnit1, positionNewUnit1);
  ships.push_back(newUnit1);
}
void CreateChocolate()
{
  auto rectNewUnit1 = IntRect(50, 1310, 200, 200);
  // set the position of the unit
  Vector2f positionNewUnit1 = {(gameWidth - 100), (gameHeight - 270)};
  auto newUnit1 = new EnemyChocolate(rectNewUnit1, positionNewUnit1);
  ships.push_back(newUnit1);
}
void CreateHotdog()
{
  auto rectNewUnit1 = IntRect(50, 1630, 200, 200);
  // set the position of the unit
  Vector2f positionNewUnit1 = {(gameWidth - 100), (gameHeight - 270)};
  auto newUnit1 = new EnemyHotdog(rectNewUnit1, positionNewUnit1);
  ships.push_back(newUnit1);
}

void Update(RenderWindow &window)
{
  // reset clock, recalculate deltatime
  static Clock clock;
  float dt = clock.restart().asSeconds();
  // check and consume events
  Event event;
  while (window.pollEvent(event))
  {
    if (event.type == Event::Closed)
    {
      window.close();
      return;
    }
  }

  for (auto &s : ships)
  {
    s->Update(dt);
  }

  // number keys
  if (Keyboard::isKeyPressed(Keyboard::Num1)) {
    CreateCarrot();
  }
  if (Keyboard::isKeyPressed(Keyboard::Num2)) {
    CreateTomato();
  }
  if (Keyboard::isKeyPressed(Keyboard::Num3)) {
    CreatePear();
  }
  // number keys
  if (Keyboard::isKeyPressed(Keyboard::Num8)) {
    CreateDonut();
  }
  if (Keyboard::isKeyPressed(Keyboard::Num9)) {
    CreateChocolate();
  }
  if (Keyboard::isKeyPressed(Keyboard::Num0)) {
    CreateHotdog();
  }

  // calculate ally collision
  const float ally_x = invader.getPosition().x;
  const float ally_y = invader.getPosition().y;

  if (ally_x > (gameWidth - 400))
  {
    window.close();
  }

  // quit via ESC key
  if (Keyboard::isKeyPressed(Keyboard::Escape)) {
    window.close();
  }
}

void Render(RenderWindow &window)
{
  window.draw(invader);

  for (const auto s : ships)
  {
    window.draw(*s);
  }
}

int main()
{
  RenderWindow window(VideoMode(gameWidth, gameHeight), "SPACE INVADERS");
  Load();
  while(window.isOpen()){
    window.clear();
    Update(window);
    Render(window);
    window.display();
  }
  return 0;
}
