#pragma once
//#include <GL/glut.h>
//#include <stdio.h>
#include <mciapi.h>
#include "MenuSelect.h"

extern MCI_OPEN_PARMS mop; //音楽再生用

#define MAXPOINTS 100      /* 記憶する点の数　　 */
#define ESCKEY 27
GLint point[MAXPOINTS][2]; /* 座標を記憶する配列 */
int pointnum = 0;          /* 記憶した座標の数　 */
int rubberband = 0;        /* ラバーバンドの消去 */

//グローバル変数参照
//extern float angle0;
//extern float angle1;
//extern float angle2;
extern int flagT;
extern int flagBack;
extern int flagSpace;

extern int NowSelect;    //現在の選択状態(初期は選択中)
extern int NowScene; //現在のシーン（初期はメニュー画面）

void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case ' ':
		switch (NowSelect){//現在選択中の状態によって処理を分岐
		case eMenu_Play://プレイ選択中なら
			flagSpace = 1;
			NowScene = eScene_Select;
			//SceneMgr_ChangeScene(eScene_Select);//シーンをゲーム画面に変更
			break;
		case eMenu_Config://設定選択中なら
			flagT = 1;
			NowScene = eScene_Config;//シーンを設定画面に変更
			//SceneMgr_ChangeScene(eScene_Config);//シーンを設定画面に変更
			break;
		case eMenu_Rank://ランキング選択中なら
			flagT = 2;
			NowScene = eScene_Rank;//シーンをランキング画面に変更
			//SceneMgr_ChangeScene(eScene_Rank);//シーンを設定画面に変更
			break;
		}
		//glutIdleFunc(Select_Now);
	case 'p': //backspaceが押されたら
		switch (NowScene){
		case eScene_Menu:
			break;
		case eScene_Select:
			flagBack = 1; //backする
			NowScene = eScene_Menu;
			break;
		case eScene_Config:
			flagBack = 1; //backする
			NowScene = eScene_Menu;
			break;
		case eScene_Rank:
			flagBack = 1; //backする
			NowScene = eScene_Menu;
			break;
		}
		break;
	case ESCKEY:exit(0);
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