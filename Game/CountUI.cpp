#include "stdafx.h"
#include "CountUI.h"
#include "Player.h"
#include "Game.h"
#include"Result1.h"
CountUI::CountUI()
{
	fontRender.SetColor(g_vec4Black);
	position = { -930.0f, 450.0f, 0.0f };
}

CountUI::~CountUI()
{

}

void CountUI::Update()
{
	// 毎フレーム経過時間を加算
	elapsedTime += g_gameTime->GetFrameDeltaTime();

	wchar_t text[256];
	swprintf_s(text, 256, L"手に入れたクリスタルの数:%d個", UInum);
	fontRender.SetText(text);
	fontRender.SetPosition(position);
	player = FindGO<Player>("player");
	int seconds = (int)elapsedTime % 60;
	if (seconds != 0) {
		Score = player->crystalCount * 50 / seconds*5;
	}
	else {
		Score = 0; // または意図したフォールバック値
	}
}

void CountUI::Render(RenderContext& rc)
{
	fontRender.Draw(rc);
}