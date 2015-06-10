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
//--R，G，B はそれぞれ赤, 緑, 青色の成分の強さを示す GLclampf 型 (float 型と等価) の値で, 0〜1 の間の値を持ちます.
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


void resize(int w, int h)
{
	/* ウィンドウ全体をビューポートにする */
	glViewport(0, 0, w, h);

	/* 変換行列の初期化 */
	glLoadIdentity();

	/* スクリーン上の表示領域をビューポートの大きさに比例させる */
	glOrtho(-w / 200.0, w / 200.0, -h / 200.0, h / 200.0, -1.0, 1.0);
}

int main(int argc, char *argv[])
{
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