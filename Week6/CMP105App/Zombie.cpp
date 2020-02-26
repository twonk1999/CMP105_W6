#include "Zombie.h"
#include "Framework/Vector.h"
#include <iostream>
Zombie::Zombie()
{
	/*Physics related initialisations*/
	scale = 200;
	gravity = sf::Vector2f(0, 9.8) * scale;
	jumpVector = sf::Vector2f(0, -4.0f) * scale;
	isJumping = false;

	/*Animations*/
	walk.addFrame(sf::IntRect(0, 0, 55, 108));
	walk.addFrame(sf::IntRect(55, 0, 55, 108));
	walk.addFrame(sf::IntRect(110, 0, 55, 108));
	walk.addFrame(sf::IntRect(165, 0, 55, 108));
	walk.addFrame(sf::IntRect(220, 0, 55, 108));
	walk.addFrame(sf::IntRect(275, 0, 55, 108));
	walk.addFrame(sf::IntRect(330, 0, 55, 108));
	walk.addFrame(sf::IntRect(385, 0, 55, 108));
	walk.setFrameSpeed(1.f / 10.f);
}
void Zombie::update(float dt)
{
	pos = initialVelocity*dt+(0.5f*gravity*dt*dt);
	initialVelocity += gravity * dt;
	setPosition(getPosition() + pos);
	if (getPosition().y >= 500)
	{
		isJumping = false;
		setPosition(getPosition().x, 500);
		initialVelocity.y = -initialVelocity.y*0.90;
	}
	if (getPosition().y <= 0)
	{
		setPosition(getPosition().x, 0);
		initialVelocity.y = -initialVelocity.y*0.9;
	}
	walk.animate(dt);
	setTextureRect(walk.getCurrentFrame());
}
void Zombie::handleInput(float dt, Input* in)
{
	input = in;
	if (in->isKeyDown(sf::Keyboard::Space) && getPosition() == sf::Vector2f(getPosition().x, 500))
	{
		if (!isJumping)
		{
			initialVelocity = jumpVector;
			isJumping = true;
		}
	}
	if (in->isMouseLDown())
	{
		if (mouseIsClicked == false)
		{
			mouseClickPos = sf::Vector2f(in->getMouseX(), in->getMouseY());
			mouseIsClicked = true;
			setPosition(mouseClickPos);
		}
		else if (mouseIsClicked == true)
		{
			currentMousePos = sf::Vector2f(in->getMouseX(), in->getMouseY());
		}
	}
	if (!in->isMouseLDown() && mouseIsClicked)
	{
		mouseIsClicked = false;
		sf::Vector2f direction = Vector::normalise(currentMousePos - mouseClickPos);
		initialVelocity = Vector::magnitude(currentMousePos - mouseClickPos) * direction * (scale/20);
	}
}
