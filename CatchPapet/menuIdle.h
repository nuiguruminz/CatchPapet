#include <mciapi.h>

extern MCI_OPEN_PARMS mop; //音楽再生用

//#define WIDTH 640
//#define HEIGHT 240
#define CENTER 0
#define MOVE 5.0
//extern int flagBack;
//extern float x0;
//extern float x1;
//extern float x2;
//extern float x3;
//extern float x4;
//extern float x5;
//extern int flagT;
//extern RECT recDisplay;
//extern int NowScene;

void menuidle(void)
{

	if (flagSpace == 1 && NowSelect == eMenu_Play){
		//ボタンが左へ移動
		x0 -= MOVE;
		x1 -= MOVE;
		x2 -= MOVE;
		if (x3 >= CENTER){
			x3 -= MOVE;
			x4 -= MOVE;
			x5 -= MOVE;
		}
		else {
			flagSpace = 0; //space押されてない状態に戻す
			//NowSelect = eMenu_Easy;
			NowScene = eScene_Select;
			//flagT = 3;
		}
	}
	else if (flagBack) //バックボタンが押されたら
	{
		//ボタンが右へ移動
		x3 += MOVE;
		x4 += MOVE;
		x5 += MOVE;
		if (x0 <= CENTER){
			x0 += MOVE;
			x1 += MOVE;
			x2 += MOVE;
		}
		else {
			flagBack = 0;
		}
	
	}

	//else if (flagT == 1 && NowSelect == eMenu_Config){ //Configボタン選択中にspaceが押されていたら

	//}
	//else if (flagT == 1 && NowSelect == eMenu_Rank){ //Rankボタン選択中にspaceが押されていたら

	//}
	//else if (flagT == 4){

	//}
	////オープン
	////mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD)&mop);
	switch (NowSelect){//現在の選択状態に従って処理を分岐
	case eMenu_Play://ゲーム選択中なら
		//mciSendCommand(mop.wDeviceID, MCI_PLAY, 0, 0); //音楽再生 //流しっぱなし //音楽終わるとなぜか立体の動きも鈍くなる //音楽長くする？
		angle0 += 0.3f;
		angle1 = 0.0f;
		angle2 = 0.0f;
		Sleep(1);
		glutPostRedisplay();
		break;
	case eMenu_Config://設定選択中なら
		//mciSendCommand(mop.wDeviceID, MCI_PLAY, 0, 0);
		angle0 = 0.0f;
		angle1 += 0.3f;
		angle2 = 0.0f;
		Sleep(1);
		glutPostRedisplay();
		break;
	case eMenu_Rank://ランキング選択中なら
		//mciSendCommand(mop.wDeviceID, MCI_PLAY, 0, 0);
		angle0 = 0.0f;
		angle1 = 0.0f;
		angle2 += 0.3f;
		Sleep(1);
		glutPostRedisplay();
		break;
		/*
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
		*/
	}
	Sleep(1);
	glutPostRedisplay();
}