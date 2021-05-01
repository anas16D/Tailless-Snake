#include <iostream>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<windows.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


bool GameOver = false;
int width = 50, height = 30;
int PosX = width/2, PosY = height/2;
char input1, input2;
enum Direction {STOP, UP, RIGHT, DOWN, LEFT};
Direction dir;
unsigned int score = 0;
int FoodX = rand()%(width-1)+1, FoodY = rand()%(height-1)+1;



void Build();
void Input();
void Result();
void Move();




int main(int argc, char** argv)
{
	srand(time(NULL));
	
	Build();
	
	while(!GameOver)
	{
		Result();
		Input();
		Move();
	}	
	
	
	return 0;
}

void Build()
{

	int i, j;
	for(i = 0; i<=height; i++)
	{
		for(j =0; j<=width; j++)
		{
			if(i == 0  )
	  		    std::cout<<"_";
   			else if(j == 0 )
			   std::cout<<"|";
			else if( j == width)  
	  		   std::cout<<"|" ;   
   			else if(i == height )
			   std::cout<<"_"; 
			else if(i == PosY && j == PosX)
				 std::cout<<static_cast<char>(153); 
			else if(i == FoodY && j == FoodX)
				 std::cout<<static_cast<char>(220);  
   			else
			   std::cout<<" ";		
			   
		}
		std::cout<<std::endl;
	}
	
	
	
}


void Input()
{
	input1 = getch();
	input2= getch();
	

	
	int first = static_cast<int>(input1);
	int second = static_cast<int>(input2);
	

	
	if(first == -32)
	{
		switch(second)
			{
				case 72:
					dir = UP;
					break;
				case 77:
					dir = RIGHT;
					break;
				case 80:
					dir = DOWN;
					break;
				case 75:
					dir = LEFT;
					break;
				default:
					Input();
					break;
			}
		
			
	}
	else
	{
		Input();
	}
	
}

void Move()
{
	int i, j;
	
		
		HANDLE hStdout;
		COORD destCoord;
		hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
		destCoord.X = PosX;
		destCoord.Y = PosY;
		SetConsoleCursorPosition(hStdout,destCoord);
		
		std::cout<<" \b";
		
		int PrevX = PosX;
		int PrevY = PosY;
		
		switch(dir)
		{
			case UP:
				PosY--;				// left-top corner is (0,0) and value of y increases downward
				break;
			case RIGHT:
				PosX++;
				break;
			case DOWN:
				PosY++;
				break;
			case LEFT:
				PosX--;
				break;
			//case UP:
				//PosX++;
				//break;
		}
		
		
		destCoord.X = PosX;
		destCoord.Y = PosY;
		SetConsoleCursorPosition(hStdout,destCoord);
		std::cout<<static_cast<char>(153);
		
	
	
}



void Result()
{
	HANDLE hStdout;
	COORD destCoord;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	destCoord.X = width/2;
	destCoord.Y = height+2;
	SetConsoleCursorPosition(hStdout,destCoord);
	
	
	if(PosX<=0 || PosX>=width || PosY<=0 || PosY>=height)
	{
		GameOver = true;
		std::cout<<"GameOver :(( \n Score = "<<score;
	}
 		
	else if(PosX == FoodX && PosY == FoodY)
	{
		score += 10;
		
		std::cout<<"\n Score: "<<score; 
		
		FoodX = rand()%(width-1)+1;
	 	FoodY = rand()%(height-1)+1;
	 	
		destCoord.X = FoodX;
		destCoord.Y = FoodY;
		SetConsoleCursorPosition(hStdout,destCoord);
		
		std::cout<<static_cast<char>(220);  
		
	}
	else
	{
		std::cout<<"\n Score: "<<score;
	}

	
	
}






