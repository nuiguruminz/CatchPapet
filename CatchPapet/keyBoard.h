//#include <GL/glut.h>
#include <stdio.h>

#define MAXPOINTS 100      /* 記憶する点の数　　 */
GLint point[MAXPOINTS][2]; /* 座標を記憶する配列 */
int pointnum = 0;          /* 記憶した座標の数　 */
int rubberband = 0;        /* ラバーバンドの消去 */

//グローバル変数参照
extern float angle0;
extern float angle1;
extern float angle2;
extern int flagT;

typedef enum{
	eMenu_Play,        //プレイ
	eMenu_Config,    //設定
	eMenu_Rank,		//ランキング
	eMenu_Easy,
	eMenu_Normal,
	eMenu_Hard,

	eMenu_Num = 3,        //本項目の数
} eMenu;
/*static */ int NowSelect = eMenu_Play;    //現在の選択状態(初期は選択中)

void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case ' ':
		switch (NowSelect){//現在選択中の状態によって処理を分岐
		case eMenu_Play://ゲーム選択中なら
			flagT = 0;
			// SceneMgr_ChangeScene(eScene_Game);//シーンをゲーム画面に変更
			break;
		case eMenu_Config://設定選択中なら
			flagT = 1;
			//SceneMgr_ChangeScene(eScene_Config);//シーンを設定画面に変更
			break;
		case eMenu_Rank://ランキング選択中なら
			flagT = 2;
			//SceneMgr_ChangeScene(eScene_Config);//シーンを設定画面に変更
			break;
		}
		//glutIdleFunc(Select_Now);
		break;
	default:
		break;
	}
}
void specialkeydown(int key, int x, int y){
	switch (key){
	case GLUT_KEY_UP:
		NowSelect = (NowSelect + (eMenu_Num - 1)) % eMenu_Num;//選択状態を一つ上げる
		//Select_Now();
		break;
	case GLUT_KEY_DOWN:
		NowSelect = (NowSelect + 1) % eMenu_Num;//選択状態を一つ下げる
		//Select_Now();
		break;
	}
}