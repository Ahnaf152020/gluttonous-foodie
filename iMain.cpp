#include "scoreCustom.h"
#include<stdlib.h>
#include<math.h>
#include "custom h.h"
#define screenWidth 1400
#define screenHeight 800
int image1;
int image2;
int gameState=-1;

int pigI1;
int pigI2;
int pigI3;

int high,details,homemenu,credit,help2,scr,over;
int imag[5];

bool nation=true;
char score[12];
char str[20];
int len;

point ran1(0,0);
point ran2(0,0);
point ran3(0,0);
point bullets(bird.inx,bird.iny);

void checkWin() //resets values if player is caught by enemy
{
    if(lock&&gameState!=5&&life==0)
    {
        iPauseTimer(0);
        asgn();
        Player[5].scor=coun;
        coun=0;
        i=1;
        j=15;
        level=0;
        pig1.setPoint(25,15);
        pig2.setPoint(25,1);
        pig3.setPoint(11,7);
        bird.setPoint(1,15);
        nation=false;
        gameState=5;
    }
	else if(lock&&life!=0)
	{
		life--;
		lock=false;
		i=1;
        j=15;
        pig1.setPoint(25,15);
        pig2.setPoint(25,1);
        pig3.setPoint(11,7);
        bird.setPoint(1,15);
		cx='a';
		iPauseTimer(0);
	}
}
char* stringConverter(int con)
{
	char *ch = new char[3000];
	itoa(con, ch, 10);
	return ch;
}
void showScore()
{
	iSetColor(255, 255, 255);
	iText(200, 300, stringConverter(Player[4].ran), GLUT_BITMAP_TIMES_ROMAN_24);
	iText(635, 300, Player[4].name, GLUT_BITMAP_TIMES_ROMAN_24);
	iText(1155, 300, stringConverter(Player[4].scor), GLUT_BITMAP_TIMES_ROMAN_24);

	
	iText(200, 350, stringConverter(Player[3].ran), GLUT_BITMAP_TIMES_ROMAN_24);
	iText(635, 350, Player[3].name, GLUT_BITMAP_TIMES_ROMAN_24);
	iText(1155, 350, stringConverter(Player[3].scor), GLUT_BITMAP_TIMES_ROMAN_24);

	
	iText(200, 400, stringConverter(Player[2].ran), GLUT_BITMAP_TIMES_ROMAN_24);
	iText(635, 400, Player[2].name, GLUT_BITMAP_TIMES_ROMAN_24);
	iText(1155, 400, stringConverter(Player[2].scor), GLUT_BITMAP_TIMES_ROMAN_24);

	
	iText(200, 450, stringConverter(Player[1].ran), GLUT_BITMAP_TIMES_ROMAN_24);
	iText(635, 450, Player[1].name, GLUT_BITMAP_TIMES_ROMAN_24);
	iText(1155, 450, stringConverter(Player[1].scor), GLUT_BITMAP_TIMES_ROMAN_24);

	
	iText(200, 500, stringConverter(Player[0].ran), GLUT_BITMAP_TIMES_ROMAN_24);
	iText(635, 500, Player[0].name, GLUT_BITMAP_TIMES_ROMAN_24);
	iText(1155, 500, stringConverter(Player[0].scor), GLUT_BITMAP_TIMES_ROMAN_24);
}
point ranChase(point pig,point *ranX) // chases random point
{
    if(pig.checkEqual(*ranX)||ranX->inx==0)
        *ranX=ranGen();
    else
        pig=chase(pig,ranX->inx,ranX->iny);
    return pig;
}
void multiEnemy()	// runs multiple enemy
{
    if(abs(pig1.inx-bird.inx)<5||abs(pig1.iny-bird.iny)<3)
        pig1=chaseBird(pig1);
    else
        pig1=ranChase(pig1,&ran1);
    if(abs(pig2.inx-bird.inx)<5||abs(pig2.iny-bird.iny)<3)
        pig2=chaseBird(pig2);
    else
        pig2=ranChase(pig2,&ran2);
    if(abs(pig3.inx-bird.inx)<5||abs(pig3.iny-bird.iny)<3)
        pig3=chaseBird(pig3);
    else
        pig3=ranChase(pig3,&ran3);
}
void intoch(int num)	//converts int to char
{
    int k=0;
    while(num/10)
    {
        score[k++]=num%10+48;
        num/=10;
    }
    score[k++]=num+48;
    strrev(score);
    score[k]='\0';
}
void iDraw()
{
    //place your drawing codes here
    iClear();

    if (gameState == -1)
    {
        //HomePage(Menu)

		iShowImage(0,0,1400,800,homemenu);

        if (playh)
        {
            
            iShowImage(435,575,380,133, high);
        }

        if (scoreh)
        {
            
            iShowImage(435,375, 380, 133, high);

        }
		if (helph)
        {
            
            iShowImage(435,375, 380, 133, high);

        }
        if (credith)
        {
            iShowImage(435,275, 380, 133, high);
        }

        if (exith)
        {
            iShowImage(435, 175, 380, 133, high);
        }
        for (int k = 0; k < 5; k++)
        {
            iShowImage(bCordinate[k].x, bCordinate[k].y, 250, 80, imag[k]);
        }
		lock=false;
		cx='a';
    }
    else if (gameState ==0)
    {
        cDraw();
        intoch(coun);
		iShowImage(1000,150,256,481,details);

        iShowImage(bird.x,bird.y,p,p,image1);

        iShowImage(pig1.x,pig1.y,p,p,pigI1);
        iShowImage(pig2.x,pig2.y,p,p,pigI2);
        iShowImage(pig3.x,pig3.y,p,p,pigI3);
		
		iShowImage(1000,150,256,481,details);
		iSetColor(127, 255, 0);
		iText ( 1130, 419,stringConverter(level+1),GLUT_BITMAP_TIMES_ROMAN_24);
		iText ( 1140, 375,score,GLUT_BITMAP_TIMES_ROMAN_24);
		iText(1235, 325, stringConverter(Player[0].scor), GLUT_BITMAP_TIMES_ROMAN_24);		
		int fijd=1050;
		for(int k=life;k>=0;k--)
		{
			iShowBMP2(fijd, 237,life1,0);
			fijd+=50;
		}
    }
    else if (gameState ==1)
    {
		iShowImage(0,0,1400,800,scr);
		showScore();
    }
    else if (gameState == 2)
    {
        iShowImage(0, 0, 1400, 800, help2);
    }
    else if (gameState ==3)
    {
        iShowImage(0, 0, 1400, 800, credit);
    }
    else if (gameState ==4)
    {
		writeScore();
        exit(0);
    }
    else if(gameState==5)
    {
		iShowImage(0,0,1400,800,over);
        iSetColor(0, 0, 0);
        iText(300,130 , str,GLUT_BITMAP_TIMES_ROMAN_24);
    }
}
void iPassiveMouse(int mx, int my)
{
    if (gameState == -1)
    {
        if (mx >= 500 && mx <= 749 && my >= 600 && my <= 683)
        {
            playh = true;
        }
        else
        {
            playh = false;
        }
        if (mx >= 500 && mx <= 749 && my >= 502 && my <= 583)
        {
            scoreh = true;
        }
        else
        {
            scoreh = false;
        }

        if (mx >= 500 && mx <=749 && my >= 401 && my <= 481)
        {
            helph = true;
        }
        else
        {
            helph = false;
        }
        if (mx >= 500 && mx <=749 && my >=298  && my <= 383)
        {
            credith = true;
        }
        else
        {
            credith = false;
        }
        if (mx >= 500 && mx <=749 && my >= 175 && my <= 271)
        {
            exith = true;
        }
        else
        {
            exith = false;
        }
    }
    if (gameState == 1)
    {
        if (mx>=750 && mx<=503 && my>=569 && my<=450)
        {
            onh=true;
        }
        else
        {
            onh=false;
        }
        if (mx>=500 && mx<=497 && my>=381 && my<=272)
        {
            offh=false;
        }
        else
        {
            offh=false;
        }
        if (mx>=495 && mx<=480 && my>=181 && my<=62)
        {
            backh=true;
        }
        else
        {
            backh=false;
        }
    }
}
/*
function iMouseMove() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{

    //place your codes here


}

/*
function iMouse() is called when the user presses/releases the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        //place your codes here


        for(int k=0; k<5; k++)
        {
            if(mx>=bCordinate[k].x && mx<=bCordinate[k].x+200 && my>=bCordinate[k].y && my<=bCordinate[k].y+50)
            {
                gameState=k;
            }
        }
    }
    if (gameState == -1)
    {
        if (mx >= 500 && mx <= 749 && my >= 600 && my <= 683)
        {
            playh = true;
        }
        else
        {
            playh = false;
        }
        if (mx >= 500 && mx <= 749 && my >= 550 && my <= 593)
        {
            scoreh = true;
        }
        else
        {
            scoreh = false;
        }

        if (mx >= 520 && mx <=749 && my >= 402 && my <= 481)
        {
            helph = true;
        }
        else
        {
            helph = false;
        }
        if (mx >= 520 && mx <=749 && my >=250  && my <= 380)
        {
            credith = true;
        }

        else
        {
            credith = false;
        }
        if (mx >= 500 && mx <=749 && my >= 190 && my <= 271)
        {
            exith = true;
        }
        else
        {
            exith = false;
        }
    }
    if (gameState == 1)
    {
        if (mx >= 1470 && mx <= 1770 && my >= 105 && my <= 205)
        {
            gameState = -1;
        }
    }
    if (gameState == 4)
    {
        if (mx >= 1470 && mx <= 1770 && my >= 105 && my <= 205)
        {
            exith = true;//exith
        }
        else
        {
            exith = false;
        }
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
        writeScore();
        exit(0);
    }
    if(key=='t'&&nation)
    {
        iPauseTimer(0);
        iPauseTimer(1);
    }
    if(key=='p'&&nation)
    {
        gameState=0;
    }
    if(key=='o'&&nation)
    {
        gameState=1;
    }
    if(key=='e'&&nation)
    {
        gameState=2;
    }
    if(gameState==5)
    {
        if(key == '\r')
        {
            str[len]='\0';
            strcpy_s(Player[5].name, str);
            sortScore(Player,6);
            for(int e = 0; e < len; e++)
                str[e] = 0;
            len = 0;
            nation=true;
            gameState=-1;
        }
        else
        {
            if(key>='a'&&key<='z')
                str[len++] = key;
            else if(key>='A'&&key<='Z')
                str[len++] = key;
        }
    }
    if(key=='n')
    {
        if(checkPoint()) // increases level when every pallet is taken
        {
            level++;
            iPauseTimer(0);
            iPauseTimer(1);
            pig1.setPoint(25,15);
            pig2.setPoint(25,1);
            pig3.setPoint(11,7);
            bird.setPoint(1,15);
        }
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
        iResumeTimer(0);
        iResumeTimer(1);
    }
    if (key == GLUT_KEY_DOWN)
    {
        cx='d';
        iResumeTimer(0);
        iResumeTimer(1);
    }
    if (key == GLUT_KEY_LEFT)
    {
        cx='l';
        iResumeTimer(0);
        iResumeTimer(1);
    }
    if (key == GLUT_KEY_RIGHT)
    {
        cx='r';
        iResumeTimer(0);
        iResumeTimer(1);
    }
    if (key == GLUT_KEY_F1)
    {
        gameState=-1;
    }
}

int main()
{
    readScore();
    //place your own initialization codes here.
    int sum=100;
    for (int k = 5; k >= 0; k--)
    {
        bCordinate[k].x = 500;
        bCordinate[k].y = sum;
        sum += 100;
    }
    iSetTimer(240,multiEnemy);
    iPauseTimer(0);
    iSetTimer(250,runBird);
    iSetTimer(3000,checkWin);
    iPauseTimer(2);
    iInitialize(screenWidth, screenHeight, "Gluttonous Foodie");
	
	for(int k=0;k<5;k++)
		imag[k]=iLoadImage(button[k]);

    image1=iLoadImage("images\\bird.png");

	homemenu=iLoadImage("images\\home.png");
	details=iLoadImage("images\\file.png");
	high = iLoadImage("images\\B1.png");
	help2=iLoadImage("images\\help2.png");
	credit=iLoadImage("images\\project.png");
	scr=iLoadImage("images\\scr.png");
	over=iLoadImage("images\\over.png");

    pigI1=iLoadImage("images\\pig1.png");
    pigI2=iLoadImage("images\\pig2.png");
    pigI3=iLoadImage("images\\pig3.png");
    iStart(); // it will start drawing
    return 0;
}
