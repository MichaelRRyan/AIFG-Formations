#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <vector>
#include "Boid.h"
#include "Pvector.h"
#include "Flock.h"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include <string>
using namespace std;

class Game
{
public:
	Game();
	~Game();
	/// <summary>
	/// main method for game
	/// </summary>
	void run();

private:

	void processEvents();
	void processKeys(sf::Event t_event);
	void processMouse(sf::Event t_event);
	void update(sf::Time t_deltaTime);
	void render();

	sf::RenderWindow m_window; // main SFML window
	//Gets the resolution, size, and bits per pixel for the screen of the PC that is running this program.
	sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
	sf::Font m_font;
	int window_height;
	int window_width;
	sf::Text m_actionMessage; // text used for message on screen

	bool m_exitGame; // control exiting game

	float boidsSize = 3;
	float enemySize = 10;
	int leader = 0;

	bool close = false;

	//Create flock, vector of shapes, and initialize boids
	Flock flock;
	vector<sf::CircleShape> shapes;

	const string m_ACTION_NAMES[4];

	enum class Action {
		Flock = 0,
		Swarm = 1,
		CircleFormation = 2,
		VFormation = 3
	} m_action;

};

#endif // !GAME_HPP

