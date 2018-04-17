#include <SFML/Graphics.hpp>
#include <iostream>
#include "ship.h"
#include "game.h"

using namespace sf;
using namespace std;

sf::Texture spritesheet;
sf::Sprite invader;
std::vector<Ship *> ships;

//create "boolean" ints, 0 = available, 1 = used
int carrotSent = 0;
int tomatoSent = 0;
int pearSent = 0;
int donutSent = 0;
int chocolateSent = 0;
int hotdogSent = 0;

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
  auto towerFriendly = new AllyBase(rectTowerFriendly, positionTowerFriendly);
  ships.push_back(towerFriendly);

  auto rectTowerEnemy = IntRect(380, 1900, 200, 300);
  // set the position of the unit
  Vector2f positionTowerEnemy = {(gameWidth - 200), (gameHeight - 400)};
  auto towerEnemy = new EnemyBase(rectTowerEnemy, positionTowerEnemy);
  ships.push_back(towerEnemy);
}


void CreateCarrot()
{
  carrotSent = 1;
  auto rectNewUnit1 = IntRect(50, 50, 200, 200);
  // set the position of the unit
  Vector2f positionNewUnit1 = {70, (gameHeight - 270)};
  auto newUnit1 = new AllyCarrot(rectNewUnit1, positionNewUnit1);
  ships.push_back(newUnit1);
}
void CreateTomato()
{
  tomatoSent = 1;
  auto rectNewUnit1 = IntRect(50, 370, 200, 200);
  // set the position of the unit
  Vector2f positionNewUnit1 = {70, (gameHeight - 270)};
  auto newUnit1 = new AllyTomato(rectNewUnit1, positionNewUnit1);
  ships.push_back(newUnit1);
}
void CreatePear()
{
  pearSent = 1;
  auto rectNewUnit1 = IntRect(50, 690, 200, 200);
  // set the position of the unit
  Vector2f positionNewUnit1 = {70, (gameHeight - 270)};
  auto newUnit1 = new AllyPear(rectNewUnit1, positionNewUnit1);
  ships.push_back(newUnit1);
}

void CreateDonut()
{
  donutSent = 1;
  auto rectNewUnit1 = IntRect(50, 980, 200, 200);
  // set the position of the unit
  Vector2f positionNewUnit1 = {(gameWidth - 200), (gameHeight - 270)};
  auto newUnit1 = new EnemyDonut(rectNewUnit1, positionNewUnit1);
  ships.push_back(newUnit1);
}
void CreateChocolate()
{
  chocolateSent = 1;
  auto rectNewUnit1 = IntRect(50, 1310, 200, 200);
  // set the position of the unit
  Vector2f positionNewUnit1 = {(gameWidth - 200), (gameHeight - 270)};
  auto newUnit1 = new EnemyChocolate(rectNewUnit1, positionNewUnit1);
  ships.push_back(newUnit1);
}
void CreateHotdog()
{
  hotdogSent = 1;
  auto rectNewUnit1 = IntRect(50, 1630, 200, 200);
  // set the position of the unit
  Vector2f positionNewUnit1 = {(gameWidth - 200), (gameHeight - 270)};
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

  // number keys for allies
  if (Keyboard::isKeyPressed(Keyboard::Num1)) {
    if (carrotSent == 1){
      printf("Carrot has alrady been sent out!");
    }
    else if (carrotSent == 0){
        CreateCarrot();
    }
    }

  if (Keyboard::isKeyPressed(Keyboard::Num2)) {
    if (tomatoSent == 1){
      printf("Tomato has alrady been sent out!");
    }
    else if (tomatoSent == 0){
        CreateTomato();
    }
  }
  if (Keyboard::isKeyPressed(Keyboard::Num3)) {
    if (pearSent == 1){
      printf("Pear has alrady been sent out!");
    }
    else if (pearSent == 0){
        CreatePear();
    }
  }
  // number keys for enemies
  if (Keyboard::isKeyPressed(Keyboard::Num8)) {
    if (donutSent == 1){
      printf("Donut has alrady been sent out!");
    }
    else if (donutSent == 0){
        CreateDonut();
    }
  }
  if (Keyboard::isKeyPressed(Keyboard::Num9)) {
    if (chocolateSent == 1){
      printf("Chocolate has alrady been sent out!");
    }
    else if (chocolateSent == 0){
        CreateChocolate();
    }
  }
  if (Keyboard::isKeyPressed(Keyboard::Num0)) {
    if (hotdogSent == 1){
      printf("Hotdog has alrady been sent out!");
    }
    else if (hotdogSent == 0){
        CreateHotdog();
    }
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
