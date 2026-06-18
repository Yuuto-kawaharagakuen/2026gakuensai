#pragma once
class Player;
class Goal:public IGameObject
{
public:
	Goal();
	~Goal();
	//更新処理
	void Update();
	//描画処理
	void Render(RenderContext& rc);
	//回転処理
	void Rotation();

	ModelRender modelRender;
	Vector3 position;
	Quaternion rotation;
	FontRender fontRender;
	Player* player;
	bool getGoal = false;

};

