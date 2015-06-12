#pragma region refarence
//glut �֐��ꗗ
////void glutInit(int *argcp, char **argv)
//--GLUT ����� OpenGL �������������܂�.
//--�����ɂ� main �̈��������̂܂ܓn���܂�.
//--X Window �Ŏg����I�v�V���� -display �Ȃǂ͂����ŏ�������܂�.
//--���̊֐��ɂ���Ĉ����̓��e���ύX����܂�.
//--�v���O�������g�ŏ������ׂ�����������Ƃ���, ���̌�ŏ������܂�.
////void glutDisplayFunc(void (*func)(void))
//--���� func �͊J�����E�B���h�E���ɕ`�悷��֐��ւ̃|�C���^�ł�.
//--�E�B���h�E���J���ꂽ��, ���̃E�B���h�E�ɂ���ĉB���ꂽ�E�B���h�E���Ăь��ꂽ�肵��,
//--�E�B���h�E���ĕ`�悷��K�v������Ƃ���, ���̊֐������s����܂�. ����������, ���̊֐����Ő}�`�\�����s���܂�.
////glFlush(void)
//--glFlush() �͂܂����s����Ă��Ȃ� OpenGL �̖��߂�S�����s���܂�.
//--OpenGL �͊֐��Ăяo���ɂ���Đ�������� OpenGL �̖��߂����̓s�x���s����̂ł͂Ȃ�,
//--���������ߍ���ł����Ă܂Ƃ߂Ď��s���܂�.
//--���̂���, ������x���߂����܂�Ȃ��� �֐����Ăяo���Ă����s���J�n����Ȃ��ꍇ������܂�.
//--glFlush() �͂��������󋵂� �܂����s����Ă��Ȃ��c��̖��߂̎��s���J�n���܂�.
//--�Ђ�ς�� glFlush() ���Ăяo����, �������ĕ`�摬�x���ቺ���܂�.
//*/
//
#pragma endregion

#pragma comment(linker, "/SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")
#pragma comment(lib,"glew32.lib")
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <stdio.h>
#include "OBJ.h"
#include "menuDisplay.h"
#include "keyBoard.h"
#include "menuIdle.h"
#include "Init.h"
#include "field.h"
#include "FieldIdle.h"
#include <windows.h>

#define WIDTH 640
#define HEIGHT 480
//���s�ړ��p
float x0 = WIDTH / 2 - 300;
float x1 = WIDTH / 2 - 300;
float x2 = WIDTH / 2 - 300;
float x3 = WIDTH / 2 + 300;
float x4 = WIDTH / 2 + 300;
float x5 = WIDTH / 2 + 300;
int flagT = 3;

float angle0 = 0.0f;
float angle1 = 0.0f;
float angle2 = 0.0f;

#define Title "Catch Papet"
RECT recDisplay;

MODEL* model;

int absolute(int a){
	if (a < 0)return -a;
	else return a;
}

void resize(int w, int h)
{
	glViewport(0, 0, w, h);
	glLoadIdentity();
	glOrtho(-2.0, 2.0, -2.0, 2.0, -2.0, 2.0);
}

int main(int argc, char *argv[])
{
	int nMode = 0;
	DEVMODE devMode;
	HWND	hWnd, hDeskWnd;
	
	//��ʃT�C�Y�̎擾
	hDeskWnd = GetDesktopWindow();
	GetWindowRect(hDeskWnd, &recDisplay);
	//��ʃT�C�Y�̎擾�@�K�X�O���[�o���ϐ��ɂ��Ă�������
	int height_display = absolute(recDisplay.top - recDisplay.bottom);
	int weight_display = absolute(recDisplay.right - recDisplay.left);

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutCreateWindow(Title);

	/*
	// �t���X�N���[���\��
	hWnd = GetActiveWindow();
	while (EnumDisplaySettings(NULL, nMode++, &devMode)){
		if (devMode.dmPelsWidth != WIDTH || devMode.dmPelsHeight != HEIGHT)continue;
		if (devMode.dmBitsPerPel != 32)continue;
		if (ChangeDisplaySettings(&devMode, CDS_TEST) == DISP_CHANGE_SUCCESSFUL)break;
	}
	ChangeDisplaySettings(&devMode, CDS_FULLSCREEN);
	glutFullScreen();

	//�}�E�X�̔�\��
	glutSetCursor(GLUT_CURSOR_NONE);
	*/

	glutDisplayFunc(FieldDisplay); //menudisplay or FieldDisplay
	glutReshapeFunc(resize);
	//glutIdleFunc(field_idle); // menuidle or field_idle
	//if (flagT!=3)glutIdleFunc(translateidle);
	Init();
	glutMainLoop();
	return 0;
}