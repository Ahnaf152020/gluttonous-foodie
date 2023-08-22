#include "iGraphics.h"

char button[5][20]={"images\\play.png","images\\Score.png","images\\help.png","images\\Credit.png","images\\exit.png"};
bool playh;
char life1[]="images\\life1.bmp";

bool optionsh;
bool helph;
bool credith;
bool exith;
bool backh;
bool scoreh;
bool onh;
bool offh;
bool level1h;
bool level2h;
bool level3h;



char cx='a';
int i=1,j=15;
int p=32;
int level=0;
int life=2;
int coun=0;
bool lock=false;

struct buttonCordinate{
	int x;
	int y;
}bCordinate[5];

int maze[3][27][17]=
{
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,1,
    1,0,1,1,1,0,1,1,1,1,1,0,1,1,1,0,1,
    1,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,
    1,0,1,0,1,1,1,1,0,1,1,1,1,0,1,0,1,
    1,0,1,0,1,0,0,0,0,0,0,0,1,0,1,0,1,
    1,0,1,0,1,0,1,1,1,1,1,0,1,0,1,0,1,
    1,0,1,0,1,0,0,0,0,0,1,0,1,0,1,0,1,
    1,0,1,0,1,0,1,1,1,1,1,0,1,0,1,0,1,
    1,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,
    1,0,1,0,1,0,1,1,1,1,1,0,1,0,1,0,1,
    1,0,1,0,1,0,1,0,0,0,0,0,1,0,1,0,1,
    1,0,1,0,1,0,1,1,1,1,1,0,1,0,1,0,1,
    1,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,
    1,0,1,0,1,0,1,0,1,1,1,0,1,0,1,0,1,
    1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,
    1,0,1,0,1,0,1,1,1,0,1,0,1,0,1,0,1,
    1,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,
    1,0,1,0,1,0,0,0,0,0,1,0,1,0,1,0,1,
    1,0,1,0,1,0,1,1,1,1,1,0,1,0,1,0,1,
    1,0,1,0,1,0,0,0,0,0,1,0,1,0,1,0,1,
    1,0,1,0,1,0,0,0,0,0,0,0,1,0,1,0,1,
    1,0,1,0,1,1,1,1,0,1,1,1,1,0,1,0,1,
    1,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,
    1,0,1,1,1,0,1,1,1,1,1,0,1,1,1,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,

	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,1,1,1,0,1,1,1,0,1,1,1,1,1,0,1,
	1,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,
	1,0,1,0,1,1,1,0,1,1,1,1,1,0,1,0,1,
	1,0,1,0,1,0,0,0,0,0,0,0,1,0,1,0,1,
	1,0,1,0,1,0,1,1,1,0,1,0,1,0,0,0,1,
	1,0,0,0,1,0,1,0,0,0,1,0,1,0,1,0,1,
	1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,
	1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,
	1,0,1,0,1,0,0,0,1,0,1,0,1,0,1,0,1,
	1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,
	1,0,1,0,1,0,1,0,0,0,1,0,0,0,1,0,1,
	1,0,1,0,0,0,1,0,1,0,1,0,1,0,1,0,1,
	1,0,1,0,1,0,1,0,0,0,1,0,1,0,1,0,1,
	1,0,1,0,1,0,1,1,1,0,1,0,1,0,1,0,1,
	1,0,1,0,1,0,0,0,1,0,1,0,1,0,1,0,1,
	1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,
	1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,
	1,0,1,0,1,0,1,0,0,0,1,0,1,0,1,0,1,
	1,0,0,0,1,0,1,1,1,1,1,0,1,0,0,0,1,
	1,0,1,0,1,0,0,0,0,0,0,0,1,0,1,0,1,
	1,0,1,0,1,1,0,1,1,1,1,1,1,0,1,0,1,
	1,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,
	1,0,1,1,1,1,1,0,1,1,1,1,0,1,1,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,

	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,1,1,1,1,1,1,0,1,1,1,1,1,1,0,1,
	1,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,
	1,0,1,0,1,0,1,1,0,1,1,0,1,0,1,0,1,
	1,0,1,0,1,0,1,0,0,0,1,0,1,0,1,0,1,
	1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,
	1,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,1,
	1,0,1,1,1,1,1,0,1,0,1,1,1,1,1,0,1,
	1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,
	1,0,1,1,1,1,1,0,1,0,0,1,1,1,1,0,1,
	1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,
	1,0,1,0,1,1,0,1,1,1,1,0,1,0,1,0,1,
	1,0,1,0,1,1,0,1,0,0,1,0,1,0,1,0,1,
	1,0,1,0,1,1,0,1,0,0,0,0,1,0,1,0,1,
	1,0,1,0,1,1,0,1,0,0,0,0,1,0,1,0,1,
	1,0,1,0,1,1,0,1,0,0,1,0,1,0,1,0,1,
	1,0,1,0,1,1,0,1,1,1,1,0,1,0,1,0,1,
	1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,
	1,0,1,1,1,1,1,0,1,0,1,1,1,1,1,0,1,
	1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,
	1,0,1,1,1,1,1,0,1,0,1,1,1,1,1,0,1,
	1,0,1,0,0,0,1,0,1,0,1,0,0,0,1,0,1,
	1,0,1,0,1,0,0,0,0,0,0,0,0,0,1,0,1,
	1,0,1,0,1,1,1,1,1,1,1,1,1,0,1,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,

};
int mazeR[3][27][17]=
{
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,1,
    1,0,1,1,1,0,1,1,1,1,1,0,1,1,1,0,1,
    1,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,
    1,0,1,0,1,1,1,1,0,1,1,1,1,0,1,0,1,
    1,0,1,0,1,0,0,0,0,0,0,0,1,0,1,0,1,
    1,0,1,0,1,0,1,1,1,1,1,0,1,0,1,0,1,
    1,0,1,0,1,0,0,0,0,0,1,0,1,0,1,0,1,
    1,0,1,0,1,0,1,1,1,1,1,0,1,0,1,0,1,
    1,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,
    1,0,1,0,1,0,1,1,1,1,1,0,1,0,1,0,1,
    1,0,1,0,1,0,1,0,0,0,0,0,1,0,1,0,1,
    1,0,1,0,1,0,1,1,1,1,1,0,1,0,1,0,1,
    1,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,
    1,0,1,0,1,0,1,0,1,1,1,0,1,0,1,0,1,
    1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,
    1,0,1,0,1,0,1,1,1,0,1,0,1,0,1,0,1,
    1,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,
    1,0,1,0,1,0,0,0,0,0,1,0,1,0,1,0,1,
    1,0,1,0,1,0,1,1,1,1,1,0,1,0,1,0,1,
    1,0,1,0,1,0,0,0,0,0,1,0,1,0,1,0,1,
    1,0,1,0,1,0,0,0,0,0,0,0,1,0,1,0,1,
    1,0,1,0,1,1,1,1,0,1,1,1,1,0,1,0,1,
    1,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,
    1,0,1,1,1,0,1,1,1,1,1,0,1,1,1,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,

	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,1,1,1,0,1,1,1,0,1,1,1,1,1,0,1,
	1,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,
	1,0,1,0,1,1,1,0,1,1,1,1,1,0,1,0,1,
	1,0,1,0,1,0,0,0,0,0,0,0,1,0,1,0,1,
	1,0,1,0,1,0,1,1,1,0,1,0,1,0,0,0,1,
	1,0,0,0,1,0,1,0,0,0,1,0,1,0,1,0,1,
	1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,
	1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,
	1,0,1,0,1,0,0,0,1,0,1,0,1,0,1,0,1,
	1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,
	1,0,1,0,1,0,1,0,0,0,1,0,0,0,1,0,1,
	1,0,1,0,0,0,1,0,1,0,1,0,1,0,1,0,1,
	1,0,1,0,1,0,1,0,0,0,1,0,1,0,1,0,1,
	1,0,1,0,1,0,1,1,1,0,1,0,1,0,1,0,1,
	1,0,1,0,1,0,0,0,1,0,1,0,1,0,1,0,1,
	1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,
	1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,
	1,0,1,0,1,0,1,0,0,0,1,0,1,0,1,0,1,
	1,0,0,0,1,0,1,1,1,1,1,0,1,0,0,0,1,
	1,0,1,0,1,0,0,0,0,0,0,0,1,0,1,0,1,
	1,0,1,0,1,1,0,1,1,1,1,1,1,0,1,0,1,
	1,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,
	1,0,1,1,1,1,1,0,1,1,1,1,0,1,1,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,

	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,1,1,1,1,1,1,0,1,1,1,1,1,1,0,1,
	1,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,
	1,0,1,0,1,0,1,1,0,1,1,0,1,0,1,0,1,
	1,0,1,0,1,0,1,0,0,0,1,0,1,0,1,0,1,
	1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,
	1,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,1,
	1,0,1,1,1,1,1,0,1,0,1,1,1,1,1,0,1,
	1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,
	1,0,1,1,1,1,1,0,1,0,0,1,1,1,1,0,1,
	1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,
	1,0,1,0,1,1,0,1,1,1,1,0,1,0,1,0,1,
	1,0,1,0,1,1,0,1,0,0,1,0,1,0,1,0,1,
	1,0,1,0,1,1,0,1,0,0,0,0,1,0,1,0,1,
	1,0,1,0,1,1,0,1,0,0,0,0,1,0,1,0,1,
	1,0,1,0,1,1,0,1,0,0,1,0,1,0,1,0,1,
	1,0,1,0,1,1,0,1,1,1,1,0,1,0,1,0,1,
	1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,
	1,0,1,1,1,1,1,0,1,0,1,1,1,1,1,0,1,
	1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,
	1,0,1,1,1,1,1,0,1,0,1,1,1,1,1,0,1,
	1,0,1,0,0,0,1,0,1,0,1,0,0,0,1,0,1,
	1,0,1,0,1,0,0,0,0,0,0,0,0,0,1,0,1,
	1,0,1,0,1,1,1,1,1,1,1,1,1,0,1,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,

};
struct point
{
	double x;
	double y;
	int inx;
	int iny;
	char deadEnd;
	bool lock2;
	bool lock3;
	bool lock4;
	bool lock5;
	point()
	{
		deadEnd='\0';
		lock2=true;
		lock3=true;
		lock4=true;
		lock5=true;
	}
	point(int dX, int dY)
	{
		inx=dX;
		iny=dY;
		x=p*inx+100;
		y=p*iny+120;
		lock2=true;
		lock3=true;
		lock4=true;
		lock5=true;
		deadEnd='\0';
	}
	void setPoint(int s, int t)
	{
		inx=s;
		iny=t;
		x=p*s+100;
		y=p*t+120;
	}
	void asgnAgain()
	{
		x=p*inx+100;
		y=p*iny+120;
	}
	void setPoint(double ax, double by)
	{
		x=ax;
		y=by;
	}
	bool checkEqual(point a) //check whether two point is equal or not
	{
		if(x==a.x&&y==a.y)
			return true;
		else 
			return false;
	}
};
void cDraw() // draws the maze
{
	int p=32;
	char xz[18]= {"images\\block6.bmp"};
	char mz[18]= {"images\\star.bmp"};
	for(int k=0; k<27; k++)
    {
        for(int l=0; l<17; l++)
        {
            if(maze[level][k][l]==1)
            {
                iShowBMP(p*k+100,p*l+120,xz);
            }
            else if(maze[level][k][l]==0)
            {
                iSetColor(224,0,0);
                iFilledCircle(p*k+p/2+100,p*l+p/2+120,4,10);

            }
        }
    }
}

bool checkPoint()// checks whether the maze is empty of pallets
{
	for(int k=0;k<27;k++)
		for(int l=0;l<17;l++)
			if(maze[level][k][l]==0)
				return false;
	return true;
}
point bird(1,15);
point lp=bird;
point pig1(25,15);
point pig2(25,1);
point pig3(11,7);
void asgn() // resets the values of mazes
{
	for(int f=0;f<5;f++)
		for(int g=0;g<27;g++)
			for(int h=0;h<17;h++)
				maze[f][g][h]=mazeR[f][g][h];
}
void runBird() // control the movement of bird and counts eaten pallets
{
	lp=bird;
	maze[level][i][j]=2;
    if(cx=='l'&&maze[level][i-1][j]!=1&&!lock)
    {
		if(maze[level][i-1][j]!=2)
			coun++;
        i--;
    }
    else if(cx=='r'&&maze[level][i+1][j]!=1&&!lock)
    {
		if(maze[level][i+1][j]!=2)
			coun++;
        i++;
    }
    else if(cx=='u'&&maze[level][i][j+1]!=1&&!lock)
    {
		if(maze[level][i][j+1]!=2)
			coun++;
        j++;
    }
    else if(cx=='d'&&maze[level][i][j-1]!=1&&!lock)
    {
		if(maze[level][i][j-1]!=2)
			coun++;
        --j;
    }
    else
        bird=lp;
	if(maze[level][i][j]!=0)
		maze[level][i][j]=2;

	bird.setPoint(i,j);
	if(bird.checkEqual(pig1)||bird.checkEqual(pig2)||bird.checkEqual(pig3))
		lock=true;
}
point chaseBird(point pig) // controls the movements of enemys
{
	int s=pig.inx;
	int t=pig.iny;
	bool up=maze[level][s][t+1]!=1?true:false;
	bool down=maze[level][s][t-1]!=1?true:false;
	bool lef=maze[level][s-1][t]!=1?true:false;
	bool righ=maze[level][s+1][t]!=1?true:false;
	if(pig.deadEnd!='\0')
	{
		if(pig.deadEnd=='r')
		{
			if(!up&&!down)
				s++;
			else
			{
				pig.deadEnd='\0';
				goto next;
			}
			goto en;
		}
		else if(pig.deadEnd=='l')
		{
			if(!up&&!down)
				s--;
			else
			{
				pig.deadEnd='\0';
				goto next;
			}
			goto en;
		}
		else if(pig.deadEnd=='d')
		{
			if(!lef&&!righ)
				t--;
			else
			{
				pig.deadEnd='\0';
				goto again;
			}
			goto en;
		}
		else if(pig.deadEnd=='u')
		{
			if(!lef&&!righ)
				t++;
			else
			{
				pig.deadEnd='\0';
				goto again;
			}
			goto en;
		}
	}
	else if(!up&&!down&!lef)
		pig.deadEnd='r';
	else if(!up&&!down&!righ)
		pig.deadEnd='l';
	else if(!up&&!righ&!lef)
		pig.deadEnd='d';
	else if(!down&&!righ&!lef)
		pig.deadEnd='u';
	else if(s!=i&&pig.lock2)
	{
		again:
		if(s<i)
		{
			if(righ)
			{
				s++;
				pig.lock4=true;
				pig.lock5=true;
			}
			else
				goto next;
		}
		else if(s>i)
		{
			if(lef)
			{
				s--;
				pig.lock4=true;
				pig.lock5=true;
			}
			else
				goto next;
		}
	}
	else if(t!=j)
	{
		next:
		if(t<j&&up&&pig.lock4)
		{
			t++;
			pig.lock2=true;
			pig.lock3=true;
		}
		else if(t>j&&down&&pig.lock4)
		{
			t--;
			pig.lock2=true;
			pig.lock3=true;

		}
		else if(!pig.lock4)
		{
			if(down&&pig.lock5)
				t--;
			else if(up)
			{
				t++;
				pig.lock5=false;
			}
		}
		else if(t==j)
		{
			pig.lock4=false;
		}
		else if(!up||!down)
		{
			pig.lock2=false;
			if(lef&&pig.lock3)
			{
				s--;
				pig.lock4=true;
				pig.lock5=true;
			}
			else if(righ)
			{
				s++;
				pig.lock3=false;
				pig.lock4=true;
				pig.lock5=true;
			}
		}
	}
	en:
	pig.setPoint(s,t);
	if(pig.checkEqual(bird))
	{
		lock=true;
		iResumeTimer(2);
	}
	return pig;
}
point chase(point pig, int m ,int n) // chases random points in maze
{
	int s=pig.inx;
	int t=pig.iny;
	bool up=maze[level][s][t+1]!=1?true:false;
	bool down=maze[level][s][t-1]!=1?true:false;
	bool lef=maze[level][s-1][t]!=1?true:false;
	bool righ=maze[level][s+1][t]!=1?true:false;
	if(pig.deadEnd!='\0')
	{
		if(pig.deadEnd=='r')
		{
			if(!up&&!down)
				s++;
			else
			{
				pig.deadEnd='\0';
				goto next;
			}
			goto en;
		}
		else if(pig.deadEnd=='l')
		{
			if(!up&&!down)
				s--;
			else
			{
				pig.deadEnd='\0';
				goto next;
			}
			goto en;
		}
		else if(pig.deadEnd=='d')
		{
			if(!lef&&!righ)
				t--;
			else
			{
				pig.deadEnd='\0';
				goto again;
			}
			goto en;
		}
		else if(pig.deadEnd=='u')
		{
			if(!lef&&!righ)
				t++;
			else
			{
				pig.deadEnd='\0';
				goto again;
			}
			goto en;
		}
	}
	else if(!up&&!down&!lef)
		pig.deadEnd='r';
	else if(!up&&!down&!righ)
		pig.deadEnd='l';
	else if(!up&&!righ&!lef)
		pig.deadEnd='d';
	else if(!down&&!righ&!lef)
		pig.deadEnd='u';
	else if(s!=m&&pig.lock2)
	{
		again:
		if(s<m)
		{
			if(righ)
			{
				s++;
				pig.lock4=true;
				pig.lock5=true;
			}
			else
				goto next;
		}
		else if(s>m)
		{
			if(lef)
			{
				s--;
				pig.lock4=true;
				pig.lock5=true;
			}
			else
				goto next;
		}
	}
	else if(t!=n)
	{
		next:
		if(t<n&&up&&pig.lock4)
		{
			t++;
			pig.lock2=true;
			pig.lock3=true;
		}
		else if(t>n&&down&&pig.lock4)
		{
			t--;
			pig.lock2=true;
			pig.lock3=true;

		}
		else if(!pig.lock4)
		{
			if(down&&pig.lock5)
				t--;
			else if(up)
			{
				t++;
				pig.lock5=false;
			}
		}
		else if(t==n)
		{
			pig.lock4=false;
		}
		else if(!up||!down)
		{
			pig.lock2=false;
			if(lef&&pig.lock3)
			{
				s--;
				pig.lock4=true;
				pig.lock5=true;
			}
			else if(righ)
			{
				s++;
				pig.lock3=false;
				pig.lock4=true;
				pig.lock5=true;
			}
		}
	}
	en:
	pig.setPoint(s,t);
	return pig;
}
point ranGen() // generates random number in maze
{
	int mx=rand()%25+1;
	int nx=rand()%16+1;
	bool mazeChek=maze[level][mx][nx]!=1?true:false;
	if(!mazeChek)
		ranGen();
	else
	{
		point x(mx,nx);
		return x;
	}
}