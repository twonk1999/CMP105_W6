#pragma once
#include "Framework/GameObject.h"
#include "Framework/Animation.h"
#include "Framework/Input.h"
class Zombie : public GameObject
{
public:
	Zombie();
	sf::Vector2f gravity = sf::Vector2f(0, 0);
	sf::Vector2f initialVelocity = sf::Vector2f(0, 0);
	sf::Vector2f pos;
	sf::Vector2f jumpVector = sf::Vector2f(0, 0);

	Input* input;

	float scale = 0;
	float speed = 62.5;
	bool isJumping = false;
	void update(float dt) override;
	void handleInput(float dt, Input* in);
protected:
	Animation walk;
};

