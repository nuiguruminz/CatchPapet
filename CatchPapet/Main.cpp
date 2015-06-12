#pragma region refarence
//glut 関数一覧
////void glutInit(int *argcp, char **argv)
//--GLUT および OpenGL 環境を初期化します.
//--引数には main の引数をそのまま渡します.
//--X Window で使われるオプション -display などはここで処理されます.
//--この関数によって引数の内容が変更されます.
//--プログラム自身で処理すべき引数があるときは, この後で処理します.
////void glutDisplayFunc(void (*func)(void))
//--引数 func は開いたウィンドウ内に描画する関数へのポインタです.
//--ウィンドウが開かれたり, 他のウィンドウによって隠されたウィンドウが再び現れたりして,
//--ウィンドウを再描画する必要があるときに, この関数が実行されます. したがって, この関数内で図形表示を行います.
////glFlush(void)
//--glFlush() はまだ実行されていない OpenGL の命令を全部実行します.
//--OpenGL は関数呼び出しによって生成される OpenGL の命令をその都度実行するのではなく,
//--いくつか溜め込んでおいてまとめて実行します.
//--このため, ある程度命令が溜まらないと 関数を呼び出しても実行が開始されない場合があります.
//--glFlush() はそういう状況で まだ実行されていない残りの命令の実行を開始します.
//--ひんぱんに glFlush() を呼び出すと, かえって描画速度が低下します.
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
//平行移動用
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
	
	//画面サイズの取得
	hDeskWnd = GetDesktopWindow();
	GetWindowRect(hDeskWnd, &recDisplay);
	//画面サイズの取得　適宜グローバル変数にしてください
	int height_display = absolute(recDisplay.top - recDisplay.bottom);
	int weight_display = absolute(recDisplay.right - recDisplay.left);

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutCreateWindow(Title);

	/*
	// フルスクリーン表示
	hWnd = GetActiveWindow();
	while (EnumDisplaySettings(NULL, nMode++, &devMode)){
		if (devMode.dmPelsWidth != WIDTH || devMode.dmPelsHeight != HEIGHT)continue;
		if (devMode.dmBitsPerPel != 32)continue;
		if (ChangeDisplaySettings(&devMode, CDS_TEST) == DISP_CHANGE_SUCCESSFUL)break;
	}
	ChangeDisplaySettings(&devMode, CDS_FULLSCREEN);
	glutFullScreen();

	//マウスの非表示
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