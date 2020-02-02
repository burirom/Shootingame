#define GL_SILENCE_DEPRECATION
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <GLUT/glut.h>
#include "Player.h"
// #include "Bullet.h"
using namespace std;
Player::Player(float x1,float x2,float y1,float y2,float R,float G,float B){
	pR = R;
	pG = G;
	pB = B;
	px1 = x1;
	px2 = x2;
	py1 = y1;
	py2 = y2;
	pr = (px2 - px1)/2;          //プレイヤーの半径
	life = 3;					//プレイヤーライフ
	score = 0;					//スコア
}
Player::~Player(){

}
void Player::DrawPlayer(float r,float l){	//プレイヤー
	
	glColor3d(pR,pG,pB);
	glBegin(GL_QUADS);		
	glVertex2d(px1+ r + l, py1);
	glVertex2d(px2+ r + l, py1);
	glVertex2d(px2+ r + l, py2);
	glVertex2d(px1+ r + l, py2);
	glEnd();
}
double Player::P_getpx1(){		//ゲット　px1
	return px1;
}
double Player::P_getpx2(){		//ゲット　px2
	return px2;
}
double Player::P_getpy1(){		//ゲット　py1
	return py1;
}
double Player::P_getpy2(){		//ゲット　py2
	return py2;
}
double Player::P_getr(){		//ゲット　pr
	return pr;					//プレイヤーの半径
}
double Player::P_getrx(float r,float l){     //プレイヤーの中心の座標xをゲット
	float ans = 0;
	ans = (px2 + r + l + px1 + r + l)/2;
	return ans;
}
double Player::P_getry(){			//プレイヤーの中心の座標xをゲット
	return (py2+py1)/2;
}
double Player::getP_life(){			//プレイヤーのライフをゲット
	return life;
}
void Player::P_die(){				//ライフを減らす処理
	life--;
}
void Player::couontscore(){			//エネミーを倒すたびにスコアを＋10する処理
	score+=10;
}
int Player::getscore(){				//スコアをゲットする
	return score;
}
