//main.cpp
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

//load the games data
void Load()
{
	//
}

//update the window to show current status
void Update(RenderWindow &window)
{
  // reset clock, recalculate deltatime(dt)
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

  // quit via esc key
  if (Keyboard::isKeyPressed(Keyboard::Escape)) {
    window.close();
  }
}

//render the window
void Render(RenderWindow &window)
{

}

//start the game
int main()
{
  RenderWindow window(VideoMode(game_width, game_height), "VEGGIE DEFENDERS");
  Load();
  while(window.isOpen()){
    window.clear();
    Update(window);
    Render(window);
    window.display();
  }
  return 0;
}
