#pragma region refarence
//glut �֐��ꗗ
////void glutInit(int *argcp, char **argv)
//--GLUT ����� OpenGL �������������܂�.
//--�����ɂ� main �̈��������̂܂ܓn���܂�.
//--X Window �Ŏg����I�v�V���� -display �Ȃǂ͂����ŏ�������܂�.
//--���̊֐��ɂ���Ĉ����̓��e���ύX����܂�.
//--�v���O�������g�ŏ������ׂ�����������Ƃ���, ���̌�ŏ������܂�.
////int glutCreateWindow(char *name)
//--�E�B���h�E���J���܂�.
//--���� name �͂��̃E�B���h�E�̖��O�̕������, �^�C�g���o�[�Ȃǂɕ\������܂�.
//--�ȍ~�� OpenGL �ɂ��}�`�̕`�擙��, �J�����E�B���h�E�ɑ΂��čs���܂�.
//--�Ȃ�, �߂�l�͊J�����E�B���h�E�̎��ʎq�ł�.
////void glutDisplayFunc(void (*func)(void))
//--���� func �͊J�����E�B���h�E���ɕ`�悷��֐��ւ̃|�C���^�ł�.
//--�E�B���h�E���J���ꂽ��, ���̃E�B���h�E�ɂ���ĉB���ꂽ�E�B���h�E���Ăь��ꂽ�肵��,
//--�E�B���h�E���ĕ`�悷��K�v������Ƃ���, ���̊֐������s����܂�. ����������, ���̊֐����Ő}�`�\�����s���܂�.
////void glutMainLoop(void)
//--����͖������[�v�ł�.
//--���̊֐����Ăяo�����Ƃ�, �v���O�����̓C�x���g�̑҂��󂯏�ԂɂȂ�܂�.
////void glutInitDisplayMode(unsigned int mode)
//--�f�B�X�v���C�̕\�����[�h��ݒ肵�܂�.
//--mode �� GLUT_RGBA ���w�肵���ꍇ��, �F�̎w��� RGB (�ԗΐ�, ���̎O���F) �ōs����悤�ɂ��܂�.
//--���ɃC���f�b�N�X�J���[���[�h (GLUT_INDEX) ���w��ł��܂�. ��҂͂��܂��g���Ό����̗ǂ��\�����s���܂���, ����Ȃ�ɖʓ|�Ȃ̂�, �����ł͂��C���Ŏg���� RGBA ���[�h���g���܂�.
////void glClearColor(GLclampf R, GLclampf G, GLclampf B, GLclampf A)
//--glClear(GL_COLOR_BUFFER_BIT) �ŃE�B���h�E��h��Ԃ��ۂ̐F���w�肵�܂�.
//--R�CG�CB �͂��ꂼ���, ��, �F�̐����̋��������� GLclampf �^ (float �^�Ɠ���) �̒l��, 0�`1 �̊Ԃ̒l�������܂�.
//--1 ���ł����邭, ���̎O�� (0, 0, 0) ���w�肷��΍��F, (1, 1, 1) ���w�肷��Δ��F�ɂȂ�܂�.
//--��̗�ł̓E�B���h�E�͐F�œh��Ԃ���܂�. �Ō�� A �̓��l�ƌĂ΂�,
//--OpenGL �ł͕s�����x�Ƃ��Ĉ����܂� (0 �œ���, 1 �ŕs����). �����ł͂Ƃ肠���� 1 �ɂ��Ă����Ă�������.
////void glClear(GLbitfield mask)
//--�E�B���h�E��h��Ԃ��܂�.
//--mask �ɂ͓h��Ԃ��o�b�t�@���w�肵�܂�.
//--OpenGL ���Ǘ������ʏ�̃o�b�t�@ (������) �ɂ�, �F���i�[����J���[�o�b�t�@�̑�, �B�ʏ��������Ɏg���f�v�X�o�b�t�@,
//--�Â������Ƃ�����Ƃ��Ɏg���X�e���V���o�b�t�@, �J���[�o�b�t�@�̏�ɏd�˂ĕ\�������I�[�o�[���C�o�b�t�@�Ȃ�,
//--�������̂��̂�����, ����炪��̃E�B���h�E�ɏd�Ȃ��đ��݂��Ă��܂�.
//--mask �� GL_COLOR_BUFFER_BIT ���w�肵���Ƃ���, �J���[�o�b�t�@�������h��Ԃ���܂�.
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


void resize(int w, int h)
{
	/* �E�B���h�E�S�̂��r���[�|�[�g�ɂ��� */
	glViewport(0, 0, w, h);

	/* �ϊ��s��̏����� */
	glLoadIdentity();

	/* �X�N���[����̕\���̈���r���[�|�[�g�̑傫���ɔ�Ⴓ���� */
	glOrtho(-w / 200.0, w / 200.0, -h / 200.0, h / 200.0, -1.0, 1.0);
}

int main(int argc, char *argv[])
{
	////��ʃT�C�Y���擾
	//HWND	hWnd, hDeskWnd;
	//hDeskWnd = GetDesktopWindow();
	//GetWindowRect(hDeskWnd, &recDisplay);

	//glutInitWindowPosition(recDisplay.left, recDisplay.top); //�\���ӏ� //���ƂŏC��sumiya
	//glutInitWindowSize(recDisplay.right, recDisplay.bottom); //�E�B���h�E�Y�T�C�Y //�C��sumiya

	int nMode = 0;
	DEVMODE devMode;
	HWND hWnd;


	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutCreateWindow(Title);
	glutDisplayFunc(menudisplay); //menudisplay or field
	glutReshapeFunc(resize);
	hWnd = GetActiveWindow();
	while (EnumDisplaySettings(NULL, nMode++, &devMode)){
		if (devMode.dmPelsWidth != WIDTH || devMode.dmPelsHeight != HEIGHT)continue;
		if (devMode.dmBitsPerPel != 32)continue;
		if (ChangeDisplaySettings(&devMode, CDS_TEST) == DISP_CHANGE_SUCCESSFUL)break;
	}
	ChangeDisplaySettings(&devMode, CDS_FULLSCREEN);
	glutFullScreen();
	glutIdleFunc(menuidle);
	//if (flagT!=3)glutIdleFunc(translateidle);
	Init();
	glutMainLoop();
	return 0;
}