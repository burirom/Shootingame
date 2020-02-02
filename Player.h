#define GL_SILENCE_DEPRECATION
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <GLUT/glut.h>
#include <vector>
#include "Bullet.h"
using namespace std;
class Player{
private:
	float pR;
	float pG;
	float pB;
	float px1;     //ひだり
	float px2;		//右
	float py1;		//上
	float py2;		//下
	int life;
	float pr;
	int score;
	
public:
	Player(float x1,float x2,float y1,float y2,float R,float G,float B);   //セットオール
	~Player();
	void DrawPlayer(float r,float l);			//プレイヤードロー
	double P_getpx1();			//ゲットpx１
	double P_getpx2();			//ゲットpx2
	double P_getpy1();			//ゲットpy1
	double P_getpy2();			//ゲットpy2
	double P_getr();			//ゲットプレイヤーの半径
	double P_getrx(float r,float l);		//ゲット　Xの中心の座標
	double P_getry();						//ゲット　yの中心の座標
	double getP_life();				//ゲット　ライフ
	void P_die();			//ライフを０にする処理
	void couontscore();		//スコアカウンター
	int getscore();			//ゲット　スコア

};