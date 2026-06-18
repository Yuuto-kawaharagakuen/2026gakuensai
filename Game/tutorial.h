#pragma once
#include"sound/SoundSource.h"

class Player;
class GameCamera;
class BackGround;
class Goal;

class tutorial :public IGameObject
{
public:
	tutorial();
	~tutorial();
	void Update();
	Player* player;
	GameCamera* gameCamera;
	BackGround* backGround;
	Goal* goal;
	SoundSource* gameBGM;

};
