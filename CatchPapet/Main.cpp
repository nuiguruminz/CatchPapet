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
#pragma comment(lib,"winmm.lib") //音楽再生用
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
#include <mmsystem.h> //音楽再生用
#include "InitMusic.h"
//#include <GL/glut.h>
//#define WIDTH 640
//#define HEIGHT 480
//HWND	hWnd, hDeskWnd = GetDesktopWindow();
RECT recDisplay;

MCI_OPEN_PARMS mop0; //音楽再生用
MCI_OPEN_PARMS mop; //音楽再生用
//=======
//>>>>>>> 24f2c582fd8eb5cb861cdfb6b47224ba73cc6af7

#define WIDTH 640
#define HEIGHT 480
#define CENTER 0 //後で修正
//平行移動用
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

int NowSelect = eMenu_Play;   //現在の選択状態(初期は選択中)
int NowScene = eScene_Menu; //現在のシーン（初期はメニュー画面

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
	//MessageBox(NULL, L"停止して終了します。", L"END", MB_OK);
	PostQuitMessage(0);
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

	
	glutDisplayFunc(menudisplay); //menudisplay or field
	//glutDisplayFunc(SceneMgr_Update); //シーンマネージャー
	glutReshapeFunc(resize);
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
	

	glutDisplayFunc(menudisplay); //menudisplay or FieldDisplay
	glutReshapeFunc(resize);
	glutIdleFunc(menuidle); // menuidle or field_idle
	//if (flagT!=3)glutIdleFunc(translateidle);
	Init();
	//InitMusic(); //BGM再生
	glutMainLoop();
	Release();
	return 0;
}