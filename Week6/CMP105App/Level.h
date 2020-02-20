#pragma once
#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include <string.h>
#include <iostream>
#include "Zombie.h"


class Level{
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();
	Zombie zombie;
	sf::Texture zombTexture;
	void handleInput(float dt);
	void update(float dt);
	void render();
	
private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();

	// Default variables for level class.
	sf::RenderWindow* window;
	Input* input;

	// More level variables
};