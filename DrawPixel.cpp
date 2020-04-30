#include <DxLib.h>
#include <stdio.h>

//画像を表示する
/*
int handle; //ハンドル用変数
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	#pragma region Initialize
	ChangeWindowMode(true);   //非全画面に設定
	SetGraphMode(640, 480, 32);   //画面サイズ指定（x, y, ColorDepth, Frame=60)
	SetOutApplicationLogValidFlag(false);   //Log.txtを生成しないように設定
	if (DxLib_Init() == 1) { return -1; }   //初期化失敗時にエラーとして出力
	#pragma endregion

	handle = LoadGraph("Sample.png");   //画像を読み込み

	while (ProcessMessage() == 0)   //多分main関数（一秒間に60回呼び出される）
	{
		ClearDrawScreen();   //裏画面を消す
		SetDrawScreen(DX_SCREEN_BACK);   //描画先を裏画面に設定

		DrawGraph(0, 100, handle, 0);   //読み込んだグラフィックの表示（x, y, 描画するグラフィックのハンドル, 透過を有効にするかどうか）

		ScreenFlip();  //裏画面を表画面にコピー
	}

	DxLib_End();  //DXライブラリの使用の終了宣言

	return 0;   //ソフトの終了
}*/

//図形を表示する
/*int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	#pragma region Initialize
	ChangeWindowMode(true);   //非全画面表示
	SetGraphMode(640, 480, 32);   //画面サイズ設定
	SetOutApplicationLogValidFlag(false);   //Log.txtを作らない
	if (DxLib_Init() == 1) return -1;   //初期化失敗したらエラーで終了
	#pragma endregion

	while (ProcessMessage() == 0)
	{
		ClearDrawScreen();   //裏画面消去
		SetDrawScreen(DX_SCREEN_BACK);   //描画先を裏画面に設定

		DrawCircle(100, 100, 30, GetColor(255, 0, 0), 0);   //x, y, 半径, 色, 内側を塗りつぶすかどうか(1で塗りつぶす)
		DrawCircle(300, 100, 30, GetColor(0, 255, 0), 1);
		DrawBox(50, 300, 100, 400, GetColor(0, 0, 255), 1);  //左上x, 左上y, 右下+1のx, 右下+1のy, 色, 塗りつぶすかどうか
		DrawLine(200, 300, 300, 400, GetColor(255, 255, 255), 1);   //起点x, 起点y, 終点x, 終点y, 色, 塗りつぶすかどうか

		ScreenFlip();   //裏画面を表画面にコピー
	}

	DxLib_End();

	return 0;
}*/

//文字を描画する
/*int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	#pragma region Initialize
	ChangeWindowMode(true);   //非全画面表示
	SetGraphMode(640, 480, 32);   //画面サイズ設定
	SetOutApplicationLogValidFlag(false);   //Log.txtを作らない
	if (DxLib_Init() == 1) return -1;   //初期化失敗したらエラーで終了
	#pragma endregion

	int hoge = 100;
	double piyo = 3.14;

	while (ProcessMessage() == 0)
	{
		ClearDrawScreen();   //画面除去
		SetDrawScreen(DX_SCREEN_BACK);   //裏画面に設定

		DrawFormatString(100, 100, GetColor(255, 255, 255), "aaa %d %f", hoge, piyo);

		ScreenFlip();
	}

	DxLib_End();

	return 0;
}*/

//何フレーム経過したのかを描画する
/*int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	#pragma region Initialize
	ChangeWindowMode(true);   //非全画面表示
	SetGraphMode(640, 480, 32);   //画面サイズ設定
	SetOutApplicationLogValidFlag(false);   //Log.txtを作らない
	if (DxLib_Init() == 1) return -1;   //初期化失敗したらエラーで終了
	#pragma endregion

	int count = 0;

	while (ProcessMessage() == 0)
	{
		ClearDrawScreen();
		SetDrawScreen(DX_SCREEN_BACK);

		count++;

		DrawFormatString(100, 100, GetColor(255, 255, 255), "frame %d", count);
		DrawFormatString(100, 120, GetColor(255, 255, 255), "set %d", count / 60);

		ScreenFlip();
	}

	DxLib_End();

	return 0;
}*/

//マウスの座標を取得・描画する
/*
int mouseX = 0, mouseY = 0;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	#pragma region Initialize
	ChangeWindowMode(true);   //非全画面表示
	SetGraphMode(640, 480, 32);   //画面サイズ設定
	SetOutApplicationLogValidFlag(false);   //Log.txtを作らない
	if (DxLib_Init() == 1) return -1;   //初期化失敗したらエラーで終了
	#pragma endregion

	while (ProcessMessage() == 0)
	{
		ClearDrawScreen();
		SetDrawScreen(DX_SCREEN_BACK);

		GetMousePoint(&mouseX, &mouseY);

		DrawFormatString(20, 50, GetColor(255, 255, 255), "MX: %3d MY: %3d", mouseX, mouseY);

		ScreenFlip();
	}

	DxLib_End();

	return 0;
}*/

//キーの状態を取得する
/*
char buf[256] = { 0 };
int keyState[256] = { 0 };

void KeyUpdate()
{
	GetHitKeyStateAll(buf);   //キーボードのすべてのキーの押下状態を取得する
	for (int i = 0; i < 256; i++)
	{
		if (buf[i] == 1) keyState[i]++;
		else keyState[i] = 0;
	}
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	#pragma region Initialize
	ChangeWindowMode(true);   //非全画面表示
	SetGraphMode(640, 480, 32);   //画面サイズ設定
	SetOutApplicationLogValidFlag(false);   //Log.txtを作らない
	if (DxLib_Init() == 1) return -1;   //初期化失敗したらエラーで終了
	#pragma endregion

	while (ProcessMessage() == 0)
	{
		ClearDrawScreen();
		SetDrawScreen(DX_SCREEN_BACK);

		KeyUpdate();

		if (keyState[KEY_INPUT_Z] > 0) DrawCircle(320, 240, 32, GetColor(255, 0, 0));
		if (keyState[KEY_INPUT_X] > 0) DrawCircle(320, 340, 32, GetColor(0, 255, 0));

		ScreenFlip();
	}

	DxLib_End();
	return 0;
}*/

//音を再生する
/*
char buf[256] = { 0 };
int keyState[256] = { 0 };

void keyUpdate()
{
	GetHitKeyStateAll(buf);
	
	for (int i = 0; i < 256; i++)
	{
		if (buf[i] == 1) keyState[i]++;
		else keyState[i] = 0;
	}
}

int handle;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	#pragma region Initialize
	ChangeWindowMode(true);   //非全画面表示
	SetGraphMode(640, 480, 32);   //画面サイズ設定
	SetOutApplicationLogValidFlag(false);   //Log.txtを作らない
	if (DxLib_Init() == 1) return -1;   //初期化失敗したらエラーで終了
	#pragma endregion

	handle = LoadSoundMem("Sample.mp3");   //事前にメモリに音を読み込む

	while (ProcessMessage() == 0)
	{
		ClearDrawScreen();
		SetDrawScreen(DX_SCREEN_BACK);

		keyUpdate();

		DrawFormatString(100, 100, GetColor(255, 255, 255), "Z Key %d", keyState[KEY_INPUT_Z]);

		if (keyState[KEY_INPUT_Z] == 1) PlaySoundMem(handle, DX_PLAYTYPE_BACKBIT);   //Zキーの押し始めに音楽を再生する
		else if (keyState[KEY_INPUT_Z] == 0) StopSoundMem(handle);   //Zキーを離したら音楽を停止する

		ScreenFlip();
	}

	DxLib_End();

	return 0;
}*/

//マウスのX座標で画像の透明度を更新する
/*
int handle, mouseX = 0, mouseY = 0;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstnace, LPSTR lpCmdLine, int nCmdShow)
{
	#pragma region Initialize
	ChangeWindowMode(true);   //非全画面表示
	SetGraphMode(640, 480, 32);   //画面サイズ設定
	SetOutApplicationLogValidFlag(false);   //Log.txtを作らない
	if (DxLib_Init() == 1) return -1;   //初期化失敗したらエラーで終了
	#pragma endregion

	handle = LoadGraph("Sample.png");

	while (ProcessMessage() == 0)
	{
		ClearDrawScreen();
		SetDrawScreen(DX_SCREEN_BACK);

		GetMousePoint(&mouseX, &mouseY);
		DrawFormatString(20, 20, GetColor(255, 255, 255), "mouseX:%d", mouseX);
		SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, mouseX);   //描画前にブレンド度合いを指定する（0～256）
		DrawGraph(100, 100, handle, 0);

		ScreenFlip();
	}
	DxLib_End();

	return 0;
}*/

//画像を拡縮回転させる その１
/*
int mouseX = 0, mouseY = 0;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstnace, LPSTR lpCmdLine, int nCmdShow)
{
	#pragma region Initialize
	ChangeWindowMode(true);   //非全画面表示
	SetGraphMode(640, 480, 32);   //画面サイズ設定
	SetOutApplicationLogValidFlag(false);   //Log.txtを作らない
	if (DxLib_Init() == 1) return -1;   //初期化失敗したらエラーで終了
	#pragma endregion

	int handle = LoadGraph("Sample.png");

	while (ProcessMessage() == 0)
	{
		ClearDrawScreen();
		SetDrawScreen(DX_SCREEN_BACK);

		GetMousePoint(&mouseX, &mouseY);

		double exrate = mouseX / 100.0;
		double angle = mouseY / 100.0;

		DrawFormatString(20, 20, GetColor(255, 255, 255), "mouseX:%d", mouseX);
		DrawFormatString(20, 40, GetColor(255, 255, 255), "mouseY:%d", mouseY);
		DrawFormatString(20, 60, GetColor(255, 255, 255), "exrate:%f", exrate);
		DrawFormatString(20, 80, GetColor(255, 255, 255), "angle:%f", angle);

		DrawRotaGraph(320, 240, exrate, angle, handle, 0);

		ScreenFlip();
	}

	DxLib_End();

	return 0;
}*/

//画像を拡縮回転させる その２
/*
int mouseX = 0, mouseY = 0;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstnace, LPSTR lpCmdLine, int nCmdShow)
{
	#pragma region Initialize
	ChangeWindowMode(true);   //非全画面表示
	SetGraphMode(640, 480, 32);   //画面サイズ設定
	SetOutApplicationLogValidFlag(false);   //Log.txtを作らない
	if (DxLib_Init() == 1) return -1;   //初期化失敗したらエラーで終了
	#pragma endregion

	int handle = LoadGraph("Sample.png");

	while (ProcessMessage() == 0)
	{
		ClearDrawScreen();
		SetDrawScreen(DX_SCREEN_BACK);

		GetMousePoint(&mouseX, &mouseY);

		double exrateX = mouseX / 100.0, exrateY = mouseY / 100.0;

		DrawFormatString(20, 20, GetColor(255, 255, 255), "mouseX:%d", mouseX);
		DrawFormatString(20, 40, GetColor(255, 255, 255), "mouseY:%d", mouseY);
		DrawFormatString(20, 60, GetColor(255, 255, 255), "exratex:%f", exrateX);
		DrawFormatString(20, 80, GetColor(255, 255, 255), "exratey:%f", exrateY);

		DrawRotaGraph3(320, 240, 20, 20, exrateX, exrateY, 0.0, handle, 0);
		DrawCircle(320, 240, 6, GetColor(255, 0, 0));

		ScreenFlip();
	}
	DxLib_End();

	return 0;
}*/

//練習（上下左右キーで対応した方向に画像を動かす）
/*
char buf[256] = { 0 };
int keyState[256] = { 0 };

int x = 0, y = 0;

void KeyUpdate()
{
	GetHitKeyStateAll(buf);
	for (int i = 0; i < 256; i++)
	{
		if (buf[i] == 1) keyState[i]++;
		else keyState[i] = 0;
	}
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstnace, LPSTR lpCmdLine, int nCmdShow)
{
	#pragma region Initialize
	ChangeWindowMode(true);
	SetGraphMode(640, 480, 32);
	SetOutApplicationLogValidFlag(false);
	if (DxLib_Init() == 1)return -1;
	#pragma endregion

	int handle = LoadGraph("Sample.png");

	while (ProcessMessage() == 0)
	{
		ClearDrawScreen();
		SetDrawScreen(DX_SCREEN_BACK);

		KeyUpdate();

		if (keyState[KEY_INPUT_UP] >= 1) y++;
		if (keyState[KEY_INPUT_DOWN] >= 1) y--;
		if (keyState[KEY_INPUT_RIGHT] >= 1) x--;
		if (keyState[KEY_INPUT_LEFT] >= 1) x++;

		DrawGraph(x, y, handle, 1);

		ScreenFlip();
	}

	DxLib_End();

	return 0;
}*/