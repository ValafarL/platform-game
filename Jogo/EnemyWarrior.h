#pragma once
#include "Characters.h"
#include "Animation.h"
class EnemyWarrior: public Characters, public Animation
{
private:

public:
	EnemyWarrior();
	~EnemyWarrior();
	void attack();
};

