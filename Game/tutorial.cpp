#include "stdafx.h"
#include "tutorial.h"
#include "Player.h"
#include "GameCamera.h"
#include "BackGround.h"
#include "sound/SoundEngine.h"
#include"Title.h"
#include"Goal.h"
#include"Game.h"
tutorial::tutorial()
{
	//プレイヤーのオブジェクトを作る
	player = NewGO<Player>(0, "player");

	//ゲームカメラのオブジェクトを作る
	gameCamera = NewGO<GameCamera>(0, "gamecamera");

	//背景のオブジェクトを作る
	backGround = NewGO<BackGround>(0);
	//ゲーム中のBGMを読み込む
	g_soundEngine->ResistWaveFileBank(1, "Assets/sound/gamebgm.wav");
	//ゲーム中のBGMを再生する
	gameBGM = NewGO<SoundSource>(0);
	gameBGM->Init(1);
	gameBGM->Play(true);
	//ゴールを生成
	goal = NewGO<Goal>(0, "goal");
	goal->position = { 2700.0f, 300.0f, 300.0f };
}
tutorial::~tutorial()
{
	//プレイヤーを削除する。
	DeleteGO(player);
	//ゲームカメラを削除する。
	DeleteGO(gameCamera);
	//ゲーム中のBGMを削除する。
	DeleteGO(gameBGM);
	//背景を削除する。
	DeleteGO(backGround);
	//ゴールを消す
	DeleteGO(goal);
}

void tutorial::Update() {
	if (goal->getGoal == true)
	{
		NewGO<Game>(0);
		DeleteGO(this);
	}
	//Bキーを押されたらスタート画面に戻る
	if (g_pad[0]->IsTrigger(enButtonLB1)) {
		NewGO<Title>(0, "title");
		DeleteGO(this);
	}
}