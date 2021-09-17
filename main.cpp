#include <iostream>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<windows.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


bool GameOver = false;
int width = 50, height = 30;
int PosX = width/2, PosY = height/2;
char input1, input2;					// arrow keys returns two ascii values
enum Direction {STOP, UP, RIGHT, DOWN, LEFT};
Direction dir;
unsigned int score = 0;
int FoodX = rand()%(width-1)+1, FoodY = rand()%(height-1)+1;



void Build();					// to build the walls and initial placement
void Input();					// to take input from user
void Result();					// update score after each move
void Move();					// to move the snake according to input




int main(int argc, char** argv)
{
	srand(time(NULL));
	
	Build();
	Input();	
	
	
	return 0;
}

void Build()
{

	int i, j;
	for(i = 0; i<=height; i++)				// building the initial setup
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
				 std::cout<<static_cast<char>(153); 		// placing head of snake
			else if(i == FoodY && j == FoodX)
				 std::cout<<static_cast<char>(220);  		// placing food
   			else
			   std::cout<<" ";		
			   
		}
		std::cout<<std::endl;
	}
	
	
	
}


void Input()
{
	input1 = getch();			// arrow keys return two values 
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
			
			while(first == -32 && !GameOver)
			{
			
				
				
				if(_kbhit())		// check if key is pressed
				{
 			        Input();
 			        break;
				}
				
				Move();
				Result();
				
				Sleep(200);					// sleep for 0.2 seconds or 200 miliseconds
				
			}
		
			
	}
	else
	{
		fflush(stdin);
		Input();
	}
	
}

void Move()							// moving the snake according to input
{
	int i, j;
	
	/* below code puts the cursor at PosX, PosY */
		
		HANDLE hStdout;
		COORD destCoord;
		hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
		destCoord.X = PosX;
		destCoord.Y = PosY;
		SetConsoleCursorPosition(hStdout,destCoord);
		
		std::cout<<" \b";				// a space to remove the previous snake and a backspace to put cursor back at PosX, PosY
		
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
		
		}
		
		
		destCoord.X = PosX;
		destCoord.Y = PosY;
		SetConsoleCursorPosition(hStdout,destCoord);
		std::cout<<static_cast<char>(153);
		
	
	
}



void Result()
{
	/* below code puts the cursor at the place to prit/update score*/
	
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
		SetConsoleCursorPosition(hStdout,destCoord);		// putting cursor at randm place to place new food
		
		std::cout<<static_cast<char>(220);  
		
	}
	else
	{
		std::cout<<"\n Score: "<<score;
	}

	
	
}






