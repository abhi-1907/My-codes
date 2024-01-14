#include<iostream>
#include<conio.h>
#include<time.h>
#include<cstdlib>
#include<algorithm>
#define size 10

using namespace std;
//class declaration
class enemies;
class bullet;
//function declaration
void reinitialise();
void sort();
int randomnumber();
void gunmovement(char );
//global integer declaration
static int guny=size-1,gunx=size/2;
static int next_bu=0,num=0;

struct ranklist
{
    int score;
    string name;
    int rank;
};

class enemies
{
    public:
    int enemyx;
    int enemyy;
    enemies()
    {
        enemyx=5;
        enemyy=2;
    }
    //generates enemy in the random position
    void enemy()
    {
        int k=randomnumber();
        enemyx=k;
        enemyy=2;
    }
    //changes the y coordinate of the enemy
    void enemynext()
    {
        enemyy++;
    }
    friend void destroy(enemies& ,bullet& );
};

class bullet
{
    public:
    int bulletx;
    int bullety;
    bullet()
    {
        bulletx=gunx;
        bullety=guny-1;
    }
    //changes the y coordinate of bullet
    void change()
    {
        bullety--;
    }
    //initialises bullet again
    void nextbullet()
    {
        bulletx=gunx;
        bullety=guny-1;
    }
    friend void destroy(enemies& ,bullet& );
};

//array of objects declaration
static bullet ob_bullet[9];
static enemies ob_enemy[2];
static ranklist ranks[10];

//destroys objects and initialises them
void destroy(enemies& ob1,bullet& ob2)
{
    ob2.bulletx=gunx;
    ob2.bullety=guny-1;
    ob1.enemy();
}


int main()
{
    char choice;
    int x,y,t=0;

 do
 { 
    while((ob_enemy[0].enemyy<=10)&&(ob_enemy[1].enemyy<=10))
    {
    for(y=1;y<=size;y++)
    {
        for(x=1;x<=size;x++)
        {
            if((x==ob_enemy[0].enemyx&&y==ob_enemy[0].enemyy)||(x==ob_enemy[1].enemyx&&y==ob_enemy[1].enemyy))
            {
                cout<<"* ";
            }
            else if(x==1||y==1||x==size||y==size)
            cout<<"# ";
            else if(x==gunx&&y==guny)
            {
                cout<<"^ ";
            }
            else if((x==ob_bullet[0].bulletx&&y==ob_bullet[0].bullety)||(x==ob_bullet[1].bulletx&&y==ob_bullet[1].bullety)||(x==ob_bullet[2].bulletx&&y==ob_bullet[2].bullety)||(x==ob_bullet[3].bulletx&&y==ob_bullet[3].bullety)||(x==ob_bullet[4].bulletx&&y==ob_bullet[4].bullety)||(x==ob_bullet[5].bulletx&&y==ob_bullet[5].bullety)||(x==ob_bullet[6].bulletx&&y==ob_bullet[6].bullety)||(x==ob_bullet[7].bulletx&&y==ob_bullet[7].bullety)||(x==ob_bullet[8].bulletx&&y==ob_bullet[8].bullety))
            {
                cout<<". ";
            }
            else
            cout<<"  ";
        }
        cout<<"\n";
    }
    cout<<"current score : "<<ranks[num].score;
    next_bu++;
    if(t<9)
    t++;
    else
    t=8;
    //for destruction
    for(int i=0;i<9;i++)
    {
        if((ob_enemy[0].enemyx==ob_bullet[i].bulletx)&&(ob_enemy[0].enemyy>=ob_bullet[i].bullety))
        {
        destroy(ob_enemy[0],ob_bullet[i]);
        ranks[num].score++;
        }
         if((ob_enemy[1].enemyx==ob_bullet[i].bulletx)&&(ob_enemy[1].enemyy>=ob_bullet[i].bullety))
         {
        destroy(ob_enemy[1],ob_bullet[i]);
        ranks[num].score++;
         }
        
    }
    //inputting charecter from user
    char input;
    input=getch();
    gunmovement(input);
    //for new bullet
     if(next_bu<8)
     {
    for(int j=8;j>=next_bu;j--)
    ob_bullet[j].nextbullet();
     }
    //for next position of existing bullet
    for(int i=0;i<t;i++)
    {
    if(ob_bullet[i].bullety>=2)
    {
        ob_bullet[i].change();
    }
    else if(ob_bullet[i].bullety<2)
    {
        ob_bullet[i].nextbullet();
    }
    }

    //for next position of enemies
    for(int i=0;i<2;i++)
    {
    ob_enemy[i].enemynext();
    }
    system("cls");
    }
    cout<<"\nGAME OVER!!!";
    cout<<"\n\nEnter your name: ";
    cin>>ranks[num].name;
    ranks[num].rank=num+1;
    sort();
    cout<<"\n\nYour score is : "<<ranks[num].score;
    cout<<"\n\nRanklist\n--------------------------------------\n";
    cout<<"\tRank\tName\tScore";
    cout<<"\n--------------------------------------------";
    for(int i=0;i<=num;i++)
    {
        cout<<endl<<"\t"<<ranks[i].rank<<"\t"<<ranks[i].name<<"\t"<<ranks[i].score<<endl;
    }
    num++;
    //Re initialising the bullets enemies and gun
    reinitialise();
    cout<<"\n\nDo you want to play again((y/n): ";
    cin>>choice;
}while(choice=='y');

    return 0;
}

//for gun movement
void gunmovement(char input)
{
    
    if((input=='a')&&(gunx>2))
    {
        gunx--;
    }
    else if((input=='d')&&(gunx<9))
    {
        gunx++;
    }
    else if((input=='s')&&(guny<9))
    {
        guny++;
    }
    else if((input=='w')&&(guny>2))
    {
        guny--;
    }
}
//for random number generation
int randomnumber()
{
 int ul=10,ll=2,no;
 srand(time(0));
 no=rand()%(ul-ll)+2;
 return no;
}

void sort()
{
    ranklist temp;
    for(int i=0;i<num;i++)
    {
        for(int j=0;j<num;j++)
        {
            if(ranks[j+1].score>=ranks[j].score)
            {
                swap(ranks[j+1],ranks[j]);

            }
        }
    }
}

void reinitialise()
{
    guny=size-1;
    gunx=size/2;
    for(int i=0;i<9;i++)
    {
        ob_bullet[i].bulletx=gunx;
        ob_bullet[i].bullety=guny-1;
    }
    ob_enemy[0].enemyx=5;
    ob_enemy[0].enemyy=2;
    ob_enemy[1].enemyx=5;
    ob_enemy[1].enemyy=2;

}