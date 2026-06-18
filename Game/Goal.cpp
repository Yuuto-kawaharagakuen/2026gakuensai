#include "stdafx.h"
#include "Goal.h"
#include"Player.h"
Goal::Goal() {
	modelRender.Init("Assets/modelData/unityChan.tkm");
	player = FindGO<Player>("player");
}
Goal::~Goal() {

}

void Goal::Update() {
	//回転処理
	Rotation();
	//絵描きさんの更新処理
	modelRender.Update();
	modelRender.SetPosition(position);
	//プレイヤーから☆に向かうベクトルを計算。
	Vector3 diff = player->position - position;

	if (diff.Length() <= 120.0f) {
		// すでにゴールしていなければ一度だけ処理する
		if (!getGoal) {
			//効果音の再生
			SoundSource* se = NewGO<SoundSource>(0);
			se->Init(2);
			se->SetVolume(3.5f);
			se->Play(false);
			getGoal = true;
		}
		// Goal オブジェクト自身はここで削除しない。
		// Game 側でフラグを受け取って遷移処理を行うため、
		// 先に破棄してしまうとフラグを読み取れなくなる。
	}
}

void Goal::Rotation()
{
	rotation.AddRotationDegY(1.0f);

	modelRender.SetRotation(rotation);
}

void Goal::Render(RenderContext& rc) {
	modelRender.Draw(rc);
}
