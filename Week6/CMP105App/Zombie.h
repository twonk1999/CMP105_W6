#pragma once
#include "Framework/GameObject.h"
#include "Framework/Animation.h"
class Zombie : public GameObject
{
public:
	Zombie();
	float scale = 0;
	float speed = 62.5;
	sf::Vector2f gravity = sf::Vector2f(0,0);
	sf::Vector2f velocity = sf::Vector2f(0, 0);
	sf::Vector2f pos;
	void update(float dt) override;
	void handleInput(float dt) override;
protected:
	Animation walk;
};

