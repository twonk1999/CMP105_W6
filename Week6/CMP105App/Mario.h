#pragma once
#include "Framework/GameObject.h"
#include "Framework/Animation.h"
#include "Framework/Input.h"
class Mario : public GameObject
{
public:
	sf::Vector2f gravity = sf::Vector2f(0, 0);
	sf::Vector2f velocity = sf::Vector2f(0, 0);
	sf::Vector2f jumpVector = sf::Vector2f(0, 0);
	sf::Vector2f pos = sf::Vector2f(0, 0);


	float scale = 0;
	float speed = 0;
	bool isJumping = false;

	Animation marioWalk;
protected:
	void update(float dt) override;
	void handleInput(float dt);
};

