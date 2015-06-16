#pragma region refarence
//glut 関数一覧
////void glutInit(int *argcp, char **argv)
//--GLUT および OpenGL 環境を初期化します.
//--引数には main の引数をそのまま渡します.
//--X Window で使われるオプション -display などはここで処理されます.
//--この関数によって引数の内容が変更されます.
//--プログラム自身で処理すべき引数があるときは, この後で処理します.
////int glutCreateWindow(char *name)
//--ウィンドウを開きます.
//--引数 name はそのウィンドウの名前の文字列で, タイトルバーなどに表示されます.
//--以降の OpenGL による図形の描画等は, 開いたウィンドウに対して行われます.
//--なお, 戻り値は開いたウィンドウの識別子です.
////void glutDisplayFunc(void (*func)(void))
//--引数 func は開いたウィンドウ内に描画する関数へのポインタです.
//--ウィンドウが開かれたり, 他のウィンドウによって隠されたウィンドウが再び現れたりして,
//--ウィンドウを再描画する必要があるときに, この関数が実行されます. したがって, この関数内で図形表示を行います.
////void glutMainLoop(void)
//--これは無限ループです.
//--この関数を呼び出すことで, プログラムはイベントの待ち受け状態になります.
////void glutInitDisplayMode(unsigned int mode)
//--ディスプレイの表示モードを設定します.
//--mode に GLUT_RGBA を指定した場合は, 色の指定を RGB (赤緑青, 光の三原色) で行えるようにします.
//--他にインデックスカラーモード (GLUT_INDEX) も指定できます. 後者はうまく使えば効率の良い表示が行えますが, それなりに面倒なので, ここではお任せで使える RGBA モードを使います.
////void glClearColor(GLclampf R, GLclampf G, GLclampf B, GLclampf A)
//--glClear(GL_COLOR_BUFFER_BIT) でウィンドウを塗りつぶす際の色を指定します.
//--R，G，B はそれぞれ赤, 緑, 青色の成分の強さを示す GLclampf 型 (float 型と等価) の値で, 0～1 の間の値を持ちます.
//--1 が最も明るく, この三つに (0, 0, 0) を指定すれば黒色, (1, 1, 1) を指定すれば白色になります.
//--上の例ではウィンドウは青色で塗りつぶされます. 最後の A はα値と呼ばれ,
//--OpenGL では不透明度として扱われます (0 で透明, 1 で不透明). ここではとりあえず 1 にしておいてください.
////void glClear(GLbitfield mask)
//--ウィンドウを塗りつぶします.
//--mask には塗りつぶすバッファを指定します.
//--OpenGL が管理する画面上のバッファ (メモリ) には, 色を格納するカラーバッファの他, 隠面消去処理に使うデプスバッファ,
//--凝ったことをするときに使うステンシルバッファ, カラーバッファの上に重ねて表示されるオーバーレイバッファなど,
//--いくつかのものがあり, これらが一つのウィンドウに重なって存在しています.
//--mask に GL_COLOR_BUFFER_BIT を指定したときは, カラーバッファだけが塗りつぶされます.
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

void resize(int w, int h)
{
	/* ウィンドウ全体をビューポートにする */
	glViewport(0, 0, w, h);

	/* 変換行列の初期化 */
	glLoadIdentity();

	/* スクリーン上の表示領域をビューポートの大きさに比例させる */
	glOrtho(-w / 200.0, w / 200.0, -h / 200.0, h / 200.0, -1.0, 1.0);
}
void Release(){
	mciSendCommand(mop.wDeviceID, MCI_CLOSE, 0, 0);
	//MessageBox(NULL, L"停止して終了します。", L"END", MB_OK);
	PostQuitMessage(0);
}

int main(int argc, char *argv[])
{
	////画面サイズを取得
	HWND	hWnd, hDeskWnd;
	hDeskWnd = GetDesktopWindow();
	GetWindowRect(hDeskWnd, &recDisplay);

	//glutInitWindowPosition(recDisplay.left, recDisplay.top); //表示箇所 //あとで修正sumiya
	//glutInitWindowSize(recDisplay.right, recDisplay.bottom); //ウィンドウズサイズ //修正sumiya

	int nMode = 0;
	DEVMODE devMode;
	//HWND hWnd;


	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutCreateWindow(Title);
	glutDisplayFunc(menudisplay); //menudisplay or field
	//glutDisplayFunc(SceneMgr_Update); //シーンマネージャー
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
	Init();
	//InitMusic(); //BGM再生
	glutMainLoop();
	Release();
	return 0;
}