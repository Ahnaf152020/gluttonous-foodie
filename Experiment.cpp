#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<string>
#include<math.h>
#include "custom h.h"
using namespace std;

#define screenWidth 1200
#define screenHeight 800

int image1;
int pigI1;
int pigI2;
int pigI3;
int gameState=-1;


/*
function iDraw() is called again and again by the system.

*/

// create a enemy packet, index position, deadEnd
point bCordinate[3];
point ranX(0,0)
void ranChase()
{
	if(pig1.checkEqual(ranX)||ranX.inx==0)
		ranX=ranGen();
	else
		pig1=chase(pig1,ranX.inx,ranX.iny);
}
void multiEnemy()
{
	pig1=chaseBird(pig1);
	pig2=chaseBird(pig2);
	pig3=chaseBird(pig3);
}
void iDraw()
{
    //place your drawing codes here
    iClear();
	cx='a';
	//cxx='a';
    cDraw();
    iShowImage(pig1.x,pig1.y,p,p,pigI1);
    iShowImage(pig2.x,pig2.y,p,p,pigI2);
    iShowImage(pig3.x,pig3.y,p,p,pigI3);
}

void iPassiveMouse(int mx, int my)
{
    ;
}
void iMouseMove(int mx, int my)
{

}
void iMouse(int button, int state, int mx, int my)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
		
    }
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {

    }
}

/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
    if (key == 'q')
    {
        exit(0);
    }
    if(key== 'u')
    {
        cout<<bird.x<<' '<<bird.y<<endl;
		cout<<"i: "<<i<<" j: "<<j<<endl;
    }
	if(key=='n')
	{
		if(checkPoint())
		{
			level++;
			iPauseTimer(0);
		}
	}
	if(key=='t')
	{
		iPauseTimer(0);
	}
	if(key=='T')
	{
		iResumeTimer(0);
	}
    //place your codes for other keys here
}

/*
function iSpecialKeyboard() is called whenver user hits special keys like-
function keys, home, end, pg up, pg down, arraows etc. you have to use
appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{

    //place your codes for other keys here
    if (key == GLUT_KEY_END)
    {
        exit(0);
    }
    if (key == GLUT_KEY_UP)
    {
        cx='u';
    }
    if (key == GLUT_KEY_DOWN)
    {
        cx='d';
    }
    if (key == GLUT_KEY_LEFT)
    {
        cx='l';
    }
    if (key == GLUT_KEY_RIGHT)
    {
        cx='r';
    }
}

int main()
{
    //place your own initialization codes here.
    
	iSetTimer(240,ranChase);
	iPauseTimer(0);

    iInitialize(screenWidth, screenHeight, "Demo");
    pigI1=iLoadImage("images\\pig1.png");
    pigI2=iLoadImage("images\\pig2.png");
    pigI3=iLoadImage("images\\pig3.png");
	
    iStart(); // it will start drawing
    return 0;
}
