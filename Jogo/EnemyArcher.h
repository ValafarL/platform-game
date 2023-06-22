#pragma once
#include "Characters.h"
class EnemyArcher : public Characters
{
private:
	bool arrowShot;
	int arrowV;
	int timeShot;

public:
	EnemyArcher();
	~EnemyArcher();
	void attack();
	void travelArrow();
	void arrowCollide();
	void update();
	void render();
};

