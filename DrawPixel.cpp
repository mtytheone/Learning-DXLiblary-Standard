#include <DxLib.h>
#include <stdio.h>

//�摜��\������
/*
int handle; //�n���h���p�ϐ�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	#pragma region Initialize
	ChangeWindowMode(true);   //��S��ʂɐݒ�
	SetGraphMode(640, 480, 32);   //��ʃT�C�Y�w��ix, y, ColorDepth, Frame=60)
	SetOutApplicationLogValidFlag(false);   //Log.txt�𐶐����Ȃ��悤�ɐݒ�
	if (DxLib_Init() == 1) { return -1; }   //���������s���ɃG���[�Ƃ��ďo��
	#pragma endregion

	handle = LoadGraph("Sample.png");   //�摜��ǂݍ���

	while (ProcessMessage() == 0)   //����main�֐��i��b�Ԃ�60��Ăяo�����j
	{
		ClearDrawScreen();   //����ʂ�����
		SetDrawScreen(DX_SCREEN_BACK);   //�`���𗠉�ʂɐݒ�

		DrawGraph(0, 100, handle, 0);   //�ǂݍ��񂾃O���t�B�b�N�̕\���ix, y, �`�悷��O���t�B�b�N�̃n���h��, ���߂�L���ɂ��邩�ǂ����j

		ScreenFlip();  //����ʂ�\��ʂɃR�s�[
	}

	DxLib_End();  //DX���C�u�����̎g�p�̏I���錾

	return 0;   //�\�t�g�̏I��
}*/

//�}�`��\������
/*int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	#pragma region Initialize
	ChangeWindowMode(true);   //��S��ʕ\��
	SetGraphMode(640, 480, 32);   //��ʃT�C�Y�ݒ�
	SetOutApplicationLogValidFlag(false);   //Log.txt�����Ȃ�
	if (DxLib_Init() == 1) return -1;   //���������s������G���[�ŏI��
	#pragma endregion

	while (ProcessMessage() == 0)
	{
		ClearDrawScreen();   //����ʏ���
		SetDrawScreen(DX_SCREEN_BACK);   //�`���𗠉�ʂɐݒ�

		DrawCircle(100, 100, 30, GetColor(255, 0, 0), 0);   //x, y, ���a, �F, ������h��Ԃ����ǂ���(1�œh��Ԃ�)
		DrawCircle(300, 100, 30, GetColor(0, 255, 0), 1);
		DrawBox(50, 300, 100, 400, GetColor(0, 0, 255), 1);  //����x, ����y, �E��+1��x, �E��+1��y, �F, �h��Ԃ����ǂ���
		DrawLine(200, 300, 300, 400, GetColor(255, 255, 255), 1);   //�N�_x, �N�_y, �I�_x, �I�_y, �F, �h��Ԃ����ǂ���

		ScreenFlip();   //����ʂ�\��ʂɃR�s�[
	}

	DxLib_End();

	return 0;
}*/

//������`�悷��
/*int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	#pragma region Initialize
	ChangeWindowMode(true);   //��S��ʕ\��
	SetGraphMode(640, 480, 32);   //��ʃT�C�Y�ݒ�
	SetOutApplicationLogValidFlag(false);   //Log.txt�����Ȃ�
	if (DxLib_Init() == 1) return -1;   //���������s������G���[�ŏI��
	#pragma endregion

	int hoge = 100;
	double piyo = 3.14;

	while (ProcessMessage() == 0)
	{
		ClearDrawScreen();   //��ʏ���
		SetDrawScreen(DX_SCREEN_BACK);   //����ʂɐݒ�

		DrawFormatString(100, 100, GetColor(255, 255, 255), "aaa %d %f", hoge, piyo);

		ScreenFlip();
	}

	DxLib_End();

	return 0;
}*/

//���t���[���o�߂����̂���`�悷��
/*int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	#pragma region Initialize
	ChangeWindowMode(true);   //��S��ʕ\��
	SetGraphMode(640, 480, 32);   //��ʃT�C�Y�ݒ�
	SetOutApplicationLogValidFlag(false);   //Log.txt�����Ȃ�
	if (DxLib_Init() == 1) return -1;   //���������s������G���[�ŏI��
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

//�}�E�X�̍��W���擾�E�`�悷��
/*
int mouseX = 0, mouseY = 0;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	#pragma region Initialize
	ChangeWindowMode(true);   //��S��ʕ\��
	SetGraphMode(640, 480, 32);   //��ʃT�C�Y�ݒ�
	SetOutApplicationLogValidFlag(false);   //Log.txt�����Ȃ�
	if (DxLib_Init() == 1) return -1;   //���������s������G���[�ŏI��
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

//�L�[�̏�Ԃ��擾����
/*
char buf[256] = { 0 };
int keyState[256] = { 0 };

void KeyUpdate()
{
	GetHitKeyStateAll(buf);   //�L�[�{�[�h�̂��ׂẴL�[�̉�����Ԃ��擾����
	for (int i = 0; i < 256; i++)
	{
		if (buf[i] == 1) keyState[i]++;
		else keyState[i] = 0;
	}
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	#pragma region Initialize
	ChangeWindowMode(true);   //��S��ʕ\��
	SetGraphMode(640, 480, 32);   //��ʃT�C�Y�ݒ�
	SetOutApplicationLogValidFlag(false);   //Log.txt�����Ȃ�
	if (DxLib_Init() == 1) return -1;   //���������s������G���[�ŏI��
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

//�����Đ�����
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
	ChangeWindowMode(true);   //��S��ʕ\��
	SetGraphMode(640, 480, 32);   //��ʃT�C�Y�ݒ�
	SetOutApplicationLogValidFlag(false);   //Log.txt�����Ȃ�
	if (DxLib_Init() == 1) return -1;   //���������s������G���[�ŏI��
	#pragma endregion

	handle = LoadSoundMem("Sample.mp3");   //���O�Ƀ������ɉ���ǂݍ���

	while (ProcessMessage() == 0)
	{
		ClearDrawScreen();
		SetDrawScreen(DX_SCREEN_BACK);

		keyUpdate();

		DrawFormatString(100, 100, GetColor(255, 255, 255), "Z Key %d", keyState[KEY_INPUT_Z]);

		if (keyState[KEY_INPUT_Z] == 1) PlaySoundMem(handle, DX_PLAYTYPE_BACKBIT);   //Z�L�[�̉����n�߂ɉ��y���Đ�����
		else if (keyState[KEY_INPUT_Z] == 0) StopSoundMem(handle);   //Z�L�[�𗣂����特�y���~����

		ScreenFlip();
	}

	DxLib_End();

	return 0;
}*/

//�}�E�X��X���W�ŉ摜�̓����x���X�V����
/*
int handle, mouseX = 0, mouseY = 0;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstnace, LPSTR lpCmdLine, int nCmdShow)
{
	#pragma region Initialize
	ChangeWindowMode(true);   //��S��ʕ\��
	SetGraphMode(640, 480, 32);   //��ʃT�C�Y�ݒ�
	SetOutApplicationLogValidFlag(false);   //Log.txt�����Ȃ�
	if (DxLib_Init() == 1) return -1;   //���������s������G���[�ŏI��
	#pragma endregion

	handle = LoadGraph("Sample.png");

	while (ProcessMessage() == 0)
	{
		ClearDrawScreen();
		SetDrawScreen(DX_SCREEN_BACK);

		GetMousePoint(&mouseX, &mouseY);
		DrawFormatString(20, 20, GetColor(255, 255, 255), "mouseX:%d", mouseX);
		SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, mouseX);   //�`��O�Ƀu�����h�x�������w�肷��i0�`256�j
		DrawGraph(100, 100, handle, 0);

		ScreenFlip();
	}
	DxLib_End();

	return 0;
}*/

//�摜���g�k��]������ ���̂P
/*
int mouseX = 0, mouseY = 0;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstnace, LPSTR lpCmdLine, int nCmdShow)
{
	#pragma region Initialize
	ChangeWindowMode(true);   //��S��ʕ\��
	SetGraphMode(640, 480, 32);   //��ʃT�C�Y�ݒ�
	SetOutApplicationLogValidFlag(false);   //Log.txt�����Ȃ�
	if (DxLib_Init() == 1) return -1;   //���������s������G���[�ŏI��
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

//�摜���g�k��]������ ���̂Q
/*
int mouseX = 0, mouseY = 0;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstnace, LPSTR lpCmdLine, int nCmdShow)
{
	#pragma region Initialize
	ChangeWindowMode(true);   //��S��ʕ\��
	SetGraphMode(640, 480, 32);   //��ʃT�C�Y�ݒ�
	SetOutApplicationLogValidFlag(false);   //Log.txt�����Ȃ�
	if (DxLib_Init() == 1) return -1;   //���������s������G���[�ŏI��
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

//���K�i�㉺���E�L�[�őΉ����������ɉ摜�𓮂����j
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