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
#pragma comment(lib,"winmm.lib") //���y�Đ��p
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
#include "SceneMgr.h"
#include "Menu.h"
//<<<<<<< HEAD
#include <mmsystem.h> //���y�Đ��p
#include "InitMusic.h"
//#include <GL/glut.h>
//#define WIDTH 640
//#define HEIGHT 480
//HWND	hWnd, hDeskWnd = GetDesktopWindow();
RECT recDisplay;

MCI_OPEN_PARMS mop0; //���y�Đ��p
MCI_OPEN_PARMS mop; //���y�Đ��p
//=======
//>>>>>>> 24f2c582fd8eb5cb861cdfb6b47224ba73cc6af7

#define WIDTH 640
#define HEIGHT 480
#define CENTER 0 //��ŏC��
//���s�ړ��p
#define TONARI 500
float x0 = CENTER;
float x1 = CENTER;
float x2 = CENTER;
float x3 = CENTER + TONARI;
float x4 = CENTER + TONARI;
float x5 = CENTER + TONARI;
int flagT = 3;
int flagBack = 0;
int flagSpace = 0;

float angle0 = 0.0f;
float angle1 = 0.0f;
float angle2 = 0.0f;

#define Title "Catch Papet"

MODEL* model;

int NowSelect = eMenu_Play;   //���݂̑I�����(�����͑I��)
int NowScene = eScene_Menu; //���݂̃V�[���i�����̓��j���[���

int absolute(int a){
	if (a < 0)return -a;
	else return a;
}

void resize(int w, int h)
{
	glViewport(0, 0, w, h);
	glLoadIdentity();
    glOrtho(-w / 200.0, w / 200.0, -h / 200.0, h / 200.0, -1.0, 1.0);
}

void Release(){
	mciSendCommand(mop.wDeviceID, MCI_CLOSE, 0, 0);
	//MessageBox(NULL, L"��~���ďI�����܂��B", L"END", MB_OK);
	PostQuitMessage(0);
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

	
	glutDisplayFunc(menudisplay); //menudisplay or field
	//glutDisplayFunc(SceneMgr_Update); //�V�[���}�l�[�W���[
	glutReshapeFunc(resize);
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
	

	glutDisplayFunc(menudisplay); //menudisplay or FieldDisplay
	glutReshapeFunc(resize);
	glutIdleFunc(menuidle); // menuidle or field_idle
	//if (flagT!=3)glutIdleFunc(translateidle);
	Init();
	//InitMusic(); //BGM�Đ�
	glutMainLoop();
	Release();
	return 0;
}