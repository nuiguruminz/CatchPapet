#include <mciapi.h>

extern MCI_OPEN_PARMS mop; //音楽再生用

extern float x0;
extern float x1;
extern float x2;
extern float x3;
extern float x4;
extern float x5;
extern int flagT;
extern RECT recDisplay;
#define WCENTER recDisplay.right/2.0

void menuidle(void)
{
	if (flagT == 0 && NowSelect == eMenu_Play){ //Playボタン選択中にspaceが押されていたら
		//ボタンが左へ移動
		x0 -= 5.0;
		x1 -= 5.0;
		x2 -= 5.0;
		if (x3 >= WCENTER){
			x3 -= 5.0;
			x4 -= 5.0;
			x5 -= 5.0;
		}
		else {
			NowSelect = eMenu_Easy;
			flagT = 0;
		}
	}
	else if (flagT == 1 && NowSelect == eMenu_Config){ //Configボタン選択中にspaceが押されていたら

	}
	else if (flagT == 1 && NowSelect == eMenu_Rank){ //Rankボタン選択中にspaceが押されていたら

	}
	else if (flagT == 4){

	}
	//オープン
	//mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD)&mop);
	switch (NowSelect){//現在の選択状態に従って処理を分岐
	case eMenu_Play://ゲーム選択中なら
		//mciSendCommand(mop.wDeviceID, MCI_PLAY, 0, 0); //音楽再生 //流しっぱなし //音楽終わるとなぜか立体の動きも鈍くなる //音楽長くする？
		angle0 += 0.1f;
		angle1 = 0.0f;
		angle2 = 0.0f;
		Sleep(1);
		glutPostRedisplay();
		break;
	case eMenu_Config://設定選択中なら
		//mciSendCommand(mop.wDeviceID, MCI_PLAY, 0, 0);
		angle0 = 0.0f;
		angle1 += 0.1f;
		angle2 = 0.0f;
		Sleep(1);
		glutPostRedisplay();
		break;
	case eMenu_Rank://ランキング選択中なら
		//mciSendCommand(mop.wDeviceID, MCI_PLAY, 0, 0);
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