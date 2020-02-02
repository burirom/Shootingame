#define GL_SILENCE_DEPRECATION
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <GLUT/glut.h>
#include <cmath>
#include <string>
#include <sstream>
#include "Enemy.h"
#include "Player.h"
#include "Bullet.h"
using namespace std;
float xright = 0;
float xleft = 0;
float Ex = 0.0;
float event = 0;
int stage=1;		//ステージ
int E_diecount = 0;	//死亡カウント

vector<Bullet> Pb;				//プレイヤーバレット
vector<Bullet> Eb; 				//エネミーバレット
Player p(-0.05,0.05,-0.4,-0.5,1,0,0);
Enemy e[40];


void DrawString(string str,double x0, double y0)      //画面表示
{
    // 画面上にテキスト描画
    glRasterPos2f(x0, y0);
    double size = (double)str.size();
    for(double i = 0; i < size; ++i){
        char ic = str[i];
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, ic);
    }
}

void P_collision(){
	float xx =0;
	float yy = 0;
	float Er = 0;
	float Br = 0;
	float D =0;
	if(Pb.size()!=0){
		for(int i=0; i<40; i++){         //エネミー
			for(int j=0;j<Pb.size();j++){		//バレット
			xx = pow(Pb[j].B_getBx() - e[i].E_getrx(),2);
			yy = pow(Pb[j].B_getBy() - e[i].E_getry(),2);
			Er = e[i].E_getr();			//エネミーの半径
			Br = Pb[j].B_getr();		//バレットの半径
    		D = sqrt(xx + yy);
    		if(Er + Br >D){
    			if(e[i].getE_life()!=0){
    			Pb.erase(Pb.begin()+j);
    			e[i].E_die();
    			E_diecount++;
    			p.couontscore();
    			}
    		}
    		}

		}

	}
}
void E_collision(){
	float xx =0;
	float yy = 0;
	float Br = 0;
	float Pr = 0;
	float D =0;
	if(Eb.size()>0){
		for(int j=0;j<Eb.size();j++){
			D = 0;
			xx = pow(Eb[j].B_getBx()-p.P_getrx(xright,xleft),2);
			yy = pow(Eb[j].B_getBy()-p.P_getry(),2);
			Br = Eb[j].B_getr();		//バレットの半径
			Pr = p.P_getr();            //プレイヤーの半径
			D = sqrt(xx + yy);
			if(Pr + Br>D){

				if(p.getP_life()!=0){
    			Eb.erase(Eb.begin()+j);
    			p.P_die();
			}
		}
	}
	}
}



void display(void){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3d(0,0,0);
	glBegin(GL_LINE_LOOP);
	glVertex2d(0,1);
	glVertex2d(0,-1);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex2d(1,0);
	glVertex2d(-1,0);
	glEnd();
	//ステージごとに色を変える処理
	float E_R = 0;
	float E_B = 0;
	float E_G = 0;
	if(stage==1){
		E_R = 0;
		E_B = 1;
		E_G = 0;
	}else if(stage==2){
		E_R = 0;
		E_B = 1;
		E_G = 1;
	}else if(stage==3){
		E_R = 1;
		E_B = 1;
		E_G = 0;
	}else{
		glColor3d(1.0, 1.0, 1.0);
		DrawString("Clear", 0.0, 0.0);
	}
	//ステージごとに色を変える処理 終了

	for(int y=0; y<40; y+=10){				//エネミーのドローの処理
		for(int x=0; x<10; x++){
			if(e[x + y].getE_life()!=0){			//エネミーのライフ判定
				float spacex = 0.2;
				float spacey = 0.02;
				e[x + y].setall(-0.95+spacex * x,-0.85+spacex * x,0.80-spacey * y,0.9-spacey * y,E_R,E_B,E_G);  //セット
				e[x + y].DrawEnemy(Ex);
			}
		}
	}						
	if(E_diecount == 40){				//全部の敵を倒した時の処理
		stage++;						//次のステージに行く処理
		E_diecount = 0;					//E_diecountをリセット
		for(int i = 0;i<40;i++){
		e[i].E_setlife();			//モンスターのHPをセット
		}								
	}
	
	if(p.getP_life()!=0){			//プレイヤーのライフ判定
	p.DrawPlayer(xright,xleft);		//プレイヤーの呼び出
	if(Pb.size()!=0){				//プレイヤーのバレットの呼び出し
    	for(int i=0;i<Pb.size();i++){
    		Pb[i].P_DrawBullet();
    	}
    }
	}


	if(Eb.size()!=0){				//エネミーのバレットの呼び出し
    	for(int i=0;i<Eb.size();i++){
    		Eb[i].E_DrawBullet();
    	}
    }
    int a = p.getscore();
    //スコア表示
     glColor3d(1.0, 1.0, 1.0);
     stringstream ss;
     ss << p.getscore();
     string score = ss.str();
     stringstream ss1;
     ss1 << p.getP_life();
     string P_hp = ss1.str();
     DrawString("Score:", 0.3, 0.95);		
     DrawString(score,0.5,0.95);		
     DrawString("Hp",0.7,0.95);
     DrawString(P_hp,0.8,0.95);
     //スコア表示 終了



    P_collision();
    E_collision();


	glFlush();
}





void resize(int w, int h){
	glViewport(0, 0, w, h);
	glLoadIdentity();
	glOrtho(-w/600, w/600, -h/600, h/600, -1.0, 1.0);
}
void keyboard(unsigned char key, int x, int y){
	switch(key){
	case 'q':
	case 'Q':
	case '\033':
		exit(0);
	break;
	case ' ':

	Pb.push_back(Bullet());
    Pb[Pb.size()-1].B_setallx(p.P_getpx1()+xright+xleft,p.P_getpx2()+xright+xleft);
	break;
	default:
		break;
	}
}
void specialkeydown(int key, int x, int y){
	switch(key){
	case GLUT_KEY_RIGHT:
	xright += 0.05;
	break;
	case GLUT_KEY_LEFT:
	xleft -= 0.05;
	break;
	}
}
void Init(void){
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glFlush();
}


void timer(int value) {
 
    if(Pb.size()!=0){						//プレイヤーバレットが　1.0についた時バレットを消す処理				
    	for(int i=0;i<Pb.size();i++){
    		Pb[i].B_Py();					//バレットのy座標をプラスしていく
    		if(Pb[i].B_getry()>1.0){		//y座標0.8になったら消失する
    			Pb.erase(Pb.begin());
    		}

    	}
    }
    

    if(Eb.size()!=0){						//エネミーバレットが　-1.0についた時バレットを消す処理				
    	for(int i=0;i<Eb.size();i++){
    		Eb[i].B_My();					//バレットのy座標をプラスしていく
    		if(Eb[i].B_getry()<-1.0){		//y座標0.8になったら消失する
    			Eb.erase(Eb.begin()+i);
    		}

    	}
    }
    glutPostRedisplay();
    //タイマー実行
    glutTimerFunc(1, timer, 0);
}

void Etimer(int value) {
	int c = 0;
	if(stage==1){		//ステージ1のとき
		c = 4;			//8体から弾が出る
	}else if(stage==2){		//ステージ2のとき
		c = 8;				//8体から弾が出る
	}else if(stage==3){					//ステージ3のとき
		c = 12;				//12体から弾が出る
	}


	if(event>3){			//エネミーの移動処理
		event=0;
	}
	if(event==0||event==3){
		Ex -= 0.05;
	}else{
		Ex += 0.05;
	}
	event++;


	int count = 0;
	srand(time(NULL));
	while(count < c){				//モンスター四体の抽選
		int a=0;
		a = rand()%40;
		if(e[a].getE_life() > 0){
		Eb.push_back(Bullet());
	    Eb[Eb.size()-1].B_setallx(e[a].E_getx1()+Ex,e[a].E_getx2()+Ex);
	    Eb[Eb.size()-1].B_setally(e[a].E_gety2(),e[a].E_gety1());
	    }
	    count++;
	}


    glutPostRedisplay();
    //タイマー実行
    glutTimerFunc(2000, Etimer, 0);
}

int main(int argc, char* argv[]){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(800,800);
	glutCreateWindow("MyGame");
	glutDisplayFunc(display);
	glutTimerFunc(1, timer, 0);
	glutTimerFunc(2000, Etimer, 0);
	glutReshapeFunc(resize);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(specialkeydown);
	Init();
	glutMainLoop();
	return 0;
}