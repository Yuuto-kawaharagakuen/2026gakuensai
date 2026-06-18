#include "stdafx.h"
#include "GameClear.h"
#include "Result1.h"
#include "Title.h"

GameClear::GameClear() {
	// GameClearではゲームクリアの画像のみを表示
	spriteRender.Init("Assets/sprite/gameclear1.dds", 1920.0f, 1080.0f);
}

GameClear::~GameClear() 
{
}

void GameClear::Update() {
	// Aボタンが押されたら Result1 に移動し、経過時間とスコアを渡す
	if (g_pad[0]->IsTrigger(enButtonA)) {
		Result1* r1 = NewGO<Result1>(0, "result1");
		r1->SetElapsedTime(elapsedTime);
		r1->SetScore(score);
		DeleteGO(this);
	}

	// Bボタンでタイトルへ戻る（保険）
	if (g_pad[0]->IsTrigger(enButtonLB1)) {
		NewGO<Title>(0, "title");
		DeleteGO(this);
	}
}

void GameClear::Render(RenderContext& rc) {
	spriteRender.Draw(rc);
}
