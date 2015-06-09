extern float x0;
extern float x1;
extern float x2;
extern float x3;
extern float x4;
extern float x5;
extern int flagT;
//#include "keyBoard.h"

void menuidle(void)
{
	if (flagT == 0 && NowSelect == eMenu_Play){ //Playボタン選択中にspaceが押されていたら
		//ボタンが左へ移動
		x0 -= 3.0;
		x1 -= 3.0;
		x2 -= 3.0;
		if (x3 > (WIDTH / 2 - 300)){
			x3 -= 3.0;
			x4 -= 3.0;
			x5 -= 3.0;
		}
		else {
			NowSelect = eMenu_Easy;
			flagT = 3;
		}
	}
	switch (NowSelect){//現在の選択状態に従って処理を分岐
	case eMenu_Play://ゲーム選択中なら
		angle0 += 0.1f;
		angle1 = 0.0f;
		angle2 = 0.0f;
		Sleep(1);
		glutPostRedisplay();
		break;
	case eMenu_Config://設定選択中なら
		angle0 = 0.0f;
		angle1 += 0.1f;
		angle2 = 0.0f;
		Sleep(1);
		glutPostRedisplay();
		break;
	case eMenu_Rank://ランキング選択中なら
		angle0 = 0.0f;
		angle1 = 0.0f;
		angle2 += 0.1f;
		Sleep(1);
		glutPostRedisplay();
		break;
	case eMenu_Easy:
		angle0 += 0.1f;
		angle1 = 0.0f;
		angle2 = 0.0f;
		Sleep(1);
		glutPostRedisplay();
	case eMenu_Normal:
		angle0 = 0.0f;
		angle1 += 0.1f;
		angle2 = 0.0f;
		Sleep(1);
		glutPostRedisplay();
	case eMenu_Hard:
		angle0 = 0.0f;
		angle1 = 0.0f;
		angle2 += 0.1f;
		Sleep(1);
		glutPostRedisplay();

	}
	Sleep(1);
	glutPostRedisplay();
}