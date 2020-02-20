#include "Zombie.h"
#include "Framework/Input.h"
#include "Framework/Vector.h"
Zombie::Zombie()
{

	scale = 200;
	gravity = sf::Vector2f(0, 9.8) * scale;
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
	pos = velocity*dt + (0.5f*gravity*dt*dt);
	velocity += gravity * dt;
	setPosition(getPosition() + pos);
	if (getPosition().y >= 500)
	{
		setPosition(getPosition().x, 500);
		velocity = sf::Vector2f(0, 0);
	}
	walk.animate(dt);
	setTextureRect(walk.getCurrentFrame());
}
