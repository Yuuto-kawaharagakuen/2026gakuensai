#pragma once
//ゲームクリア
class GameClear:public IGameObject
{
public:
	GameClear();
	~GameClear();

	void Update();
	void Render(RenderContext& rc);

	// メンバ変数
	SpriteRender spriteRender;
	float elapsedTime = 0.0f;
	int score = 0;

	void SetElapsedTime(float t) { elapsedTime = t; }
	void SetScore(int s) { score = s; }
};

