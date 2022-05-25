#include <iostream>
#include <conio.h>
#include <windows.h>
#include<cstdlib>
#include<time.h>
using namespace std;


void drawBoundary(int,int,int*,int*,int*);
void changeUserLocationOnButtonClick(int ,int *,char,int,int*);
int i,j,k;
bool gameOver;
const int width = 20;
const int height = 20;
int x1, y1, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;
enum eDirecton { STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirecton dir;
void Setup()
{
    gameOver = false;
    dir = STOP;
    x1 = width / 2;
    y1= height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
}
void Draw()
{
    system("cls"); //system("clear");
    for ( i = 0; i < width+2; i++)
        cout << "#";
    cout << endl;

    for ( i = 0; i < height; i++)
    {
        for ( j = 0; j < width; j++)
        {
            if (j == 0)
                cout << "#";
            if (i == y1 && j == x1)
                cout << "O";
            else if (i == fruitY && j == fruitX)
                cout << "F";
            else
            {
                bool print = false;
                for (int k = 0; k < nTail; k++)
                {
                    if (tailX[k] == j && tailY[k] == i)
                    {
                        cout << "o";
                        print = true;
                    }
                }
                if (!print)
                    cout << " ";
            }


            if (j == width - 1)
                cout << "#";
        }
        cout << endl;
    }

    for ( i = 0; i < width+2; i++)
        cout << "#";
    cout << endl;
    cout << "Score:" << score << endl;
}
void Input()
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'x':
            gameOver = true;
            break;
        }
    }
}
void Logic()
{
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x1;
    tailY[0] = y1;
    for (int i = 1; i < nTail; i++)
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
    switch (dir)
    {
    case LEFT:
        x1--;
        break;
    case RIGHT:
        x1++;
        break;
    case UP:
        y1--;
        break;
    case DOWN:
        y1++;
        break;
    default:
        break;
    }
    if (x1 >= width) x1 = 0; else if (x1 < 0) x1 = width - 1;
    if (y1 >= height) y1 = 0; else if (y1 < 0) y1 = height - 1;

    for ( i = 0; i < nTail; i++)
        if (tailX[i] == x1 && tailY[i] == y1)
            gameOver = true;

    if (x1 == fruitX && y1 == fruitY)
    {
        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
        nTail++;
    }
}

void drawBoundary(int x,int y,int *posX,int *posY,int *gameOver){


	for(i=-1;i<=10;i++){
		for(j=-1;j<=50;j++){
			if(i==-1 || i==10 || j==-1 || j==50){
				cout<<"#";
			}
			else{
				if(i==y && j==x){
					cout<<"P";
					for(k=0;k<4;k++){
						if(posX[k]==x && posY[k]==y){
							posX[k]=-1;
							posY[k]=-1;
							(*gameOver)++;
						}
					}
				}
				else{
					if(posX[0]==j && posY[0]==i){
						cout<<"a";
					}
					else if(posX[1]==j && posY[1]==i){
						cout<<"b";
					}
					else if(posX[2]==j && posY[2]==i){
						cout<<"c";
					}
					else if(posX[3]==j && posY[3]==i){
						cout<<"d";
					}
					else
						cout<<" ";
				}
			}
		}
		cout<<"\n";
	}
}

void changeUserLocationOnButtonClick(int *x,int *y,char keyPressed,int *noOfMoves,int *gameQuit){
	switch(keyPressed){
		case 'w':
		    			if(*y!=0){
				(*noOfMoves)++;
				(*y)--;
			}
			break;
		case 'a':
			if(*x!=0){
				(*noOfMoves)++;
				(*x)--;
			}
			break;
		case 'd':
			if(*x!=49){
				(*noOfMoves)++;
				(*x)++;
			}
			break;
		case 's':
			if(*y!=9){
				(*noOfMoves)++;
				(*y)++;
			}
			break;
		case 'q':
			*gameQuit=1;
			break;
	}
}
void func(){int x=0,y=0;
	char ch;
	int positionX[4]={0};
	int positionY[4]={0};
	int randomNum,i=0;
	int gamever=0,noOfMoves=0,gameQuit=0;

	srand(time(0));


	while(i<4){
		randomNum=rand()%50;
		positionX[i]=randomNum;
		i++;
	}

	i=0;
	while(i<4){
		randomNum=rand()%10;
		positionY[i]=randomNum;
		i++;
	}

	drawBoundary(x,y,positionX,positionY,&gamever);

	while(1){
		if(_kbhit()){
			ch=getch();
			system("cls");
			changeUserLocationOnButtonClick(&x,&y,ch,&noOfMoves,&gameQuit);
			if(gameQuit==0){
				drawBoundary(x,y,positionX,positionY,&gamever);
				if(gamever==4){
					system("cls");
					cout<<"\n[][][][] Well Done [][][][]\n";
					cout<<"\nYou Collected All The Jwels!\n";
					cout<<"\nIt Took You "<<noOfMoves<<" Moves!\n";
					cout<<"\n[][][][] Game Over [][][][]\n";
					break;
				}
			}
			else{
				system("cls");
				cout<<"\nOh No! You Quit!!\n";
				cout<<"\nYou Collected "<<gamever<<" Jwels!\n";
				cout<<"\nAfter "<<noOfMoves<<" Moves You Quit!\n";
				cout<<"\n[][][][] Game Over [][][][]\n";
				break;
			}
		}
	}
}

int main()
{   char ans;

    do{gameOver=true;
            system("cls");
    cout<<"\n\t\t--------------------------------";
    cout<<"\n\t\t|         PROJECT              |";
    cout<<"\n\t\t--------------------------------";
    cout<<"\n\t\tAvailable Games : ";
    cout<<"\n\t\t1:SNAKE GAME ";
    cout<<"\n\t\t2:JEWEL GAME ";
    cout<<"\n\t\t3:HELP";
    cout<<"\n\t\tUSER,Which game you want to play ? (1/2) : ";
int ch;
cin>>ch;
if(ch==1){
    Setup();
    while (!gameOver)
    {
        Draw();
        Input();
        Logic();
        Sleep(10);
    }}
    if(ch==2)
    {system("cls");
       func();
    }
    if(ch==3)
    {system("cls");
        cout<<"\n\t\t-------------------------------------";
        cout<<"\n\t\t          HELP MENU ";
        cout<<"\n\t\t-------------------------------------";
        cout<<"\n\t\tThe controls for snake game are as follows:\n\n\t\t w key to move up ,a key to move left and vice versa and it applies to jewel game too.\n\n\t\tIn jewel game you have to move p using the mentioned keys and collect jewels and in snake game you have \n\n\t\tto move 0 to f i.e Fruit to increase the size of the snake and your points as well :)";
    }

    cout<<"\n\n\n\n\t\tUSER,Do you want to see the menu again('y' for yes & 'n' for no)";
    cin>>ans;
    }while(ans=='y'||ans=='Y');
    return 0;
}
