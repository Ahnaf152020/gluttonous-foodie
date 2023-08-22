#include<iostream>
#include<string.h>
using namespace std;

struct highScore
{
	int scor;
	char name[20];
	int ran;
	highScore()
	{
		ran=0;
	}
	highScore(int Scor, char Name[])
	{
		scor=Scor;
		strcpy(name,Name);
	}
	void setAll(highScore x)
	{
	    ran=x.ran;
		strcpy_s(name,x.name);
		scor=x.scor;
	}
};
highScore Player[6];
void sortScore(highScore *r, int n) // sort the highScore
{
    highScore *q=r;
    for(int k=0;k<n-1;k++)
    {
        for(int l=0;l<n-1-k;l++)
        {
            if(r->scor<(r+1)->scor)
            {
                highScore temp=*r;
                *(r)=*(r+1);
                *(r+1)=temp;
            }
            else if(r->scor==(r+1)->scor)
            {
                if(r->name>(r+1)->name)
                {
                    highScore temp=*r;
					*(r)=*(r+1);
					*(r+1)=temp;
                }
            }
            r++;
        }
        r=q;
    }
    for(int j=0;j<n;j++)
    {
		q->ran=j+1;
        q++;
    }
}
void readScore()
{
	FILE *fp=fopen("HighScore.bin","rb");
	highScore pla;
	for(int k=0;k<5;k++)
	{
		fread(&pla,sizeof(highScore),1,fp);
		Player[k].setAll(pla);
	}
	fclose(fp);
}
void writeScore()
{
	FILE *fp=fopen("HighScore.bin","wb");
	for(int k=0;k<5;k++)
		fwrite(Player+k,sizeof(highScore),1,fp);
	fclose(fp);
}
