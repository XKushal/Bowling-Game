#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

int  a=0;
int  b=0;
int  c=0;
int frame = 10;//total number of frames
//calculates the score for each frame
void print_score(int myRoll1[][10],int myRoll2[][10],int bonusSpere,int strikeRoll1,int strikeRoll2);
//check if the second ball is spare
bool isSpere(int m,int n);
//check if the ball is strike
bool isStrike(int m);
//return valid second roll 
int validSecondnum(int m,int n);
//check if the second roll is invalid
bool isSecondValid(int m,int n);
//return first valid 
int validFirstnum(int m);
//checks if the first is valid 
bool isFirstValid(int m);
//move through the frames until reaches 10
int moveTheframes();

int main()
{
	moveTheframes();//fucntion call
	return 0;
}

//moves through each frame
int moveTheframes()
{
	int myRoll1[10][a];//first roll
	int myRoll2[10][b];//second roll
	int strikeRoll1,strikeRoll2,bonusSpere;
	int roll1Store,roll2Store;
	int i=0;
	while(i<frame)
	{
		while(i!=frame)
		{
			++i;
			cout<<"Enter the score for the first roll for frame "<<i<<" : ";//first roll
			cin>>myRoll1[i][a];
			roll1Store=myRoll1[i][a];
			if(isFirstValid(roll1Store)==true)//checks for validation
			roll1Store=myRoll1[i][a];
			else
			{
				myRoll1[i][a]=validFirstnum(roll1Store);
				roll1Store = 	myRoll1[i][a];
			}
			if(myRoll1[i][a]==10)//if strike case
			{
				cout<<"congratulations!!  you hit the strike!\n";
				cout<<"You get two chnaces to roll as bonus.";
				cout<<endl;
				if(i==frame)//last frame
				{
					cout<<"COME ON!! Extra two rolls as bonus\n";
					cout<<"Second last ROLL of the game: ";
					cin>>strikeRoll1;
					strikeRoll1=validFirstnum(strikeRoll1);//returns valid score if invalid
					if(isStrike(strikeRoll1)==true)//checks for strike
					cout<<"PERFECT SHOT!! STRIKE AGAIN.\n";
					else
					cout<<"NICE TRY. you could still hit the spere.\n";
					cout<<endl;
					cout<<"FINAL roll of the game: ";
					cin>>strikeRoll2;
					if(isStrike(strikeRoll1)==true)//checks for strike
					{
						strikeRoll2=validFirstnum(strikeRoll2);//returns valid score if invalid
						if(isStrike(strikeRoll2)==true)//checks for strike
						cout<<"STRIKE.\n";
					}
					else
					{
						strikeRoll2=validSecondnum(strikeRoll1,strikeRoll2);//returns valid if invalid
						if(isSpere(strikeRoll1,strikeRoll2)==true)//checks for spare
						cout<<"SPERE!!!.\n";
						else
						cout<<"GOOD GAME.\n";
					}
				}
				break;
			}
		cout<<"Enter the score for the second roll for frame "<<i<<" : ";//second roll
		cin>>myRoll2[i][b];
		roll2Store = myRoll2[i][a];
		if(isSecondValid(roll1Store,roll2Store)==true)//checks for validation
		roll2Store = myRoll2[i][a];
		else
		myRoll2[i][a]=validSecondnum(roll1Store,roll2Store);//returns valid if invalid
		if(isSpere(roll1Store,roll2Store)==true)//checks for spare 
		{
			cout<<"HURRY!!! You hit the spere.\n";
			cout<<"You get another chance to roll as bonus.\n";
		}
		else
		{
			cout<<"Well try.\n";
		}
		if(i==frame && (isSpere(roll1Store,roll2Store)==true))//checks for spare or second last frame
		{
			cout<<"ROll for the final time: ";
			cin>>bonusSpere;
			bonusSpere = validFirstnum(bonusSpere);//returns valid if invalid
			if(isStrike(bonusSpere)==true)//checks for strike
			cout<<"STRIKE!!! great play.\n";
			else
			cout<<"ALMOST THERE.\n";
		}
		
		cout<<endl;
		}
	cout<<endl;
	}
	//calls print_score fucntion to print calculated score
	print_score(myRoll1,myRoll2,bonusSpere,strikeRoll1,strikeRoll2);
}

//calculate the score for each frame
void print_score(int myRoll1[10][10],int myRoll2[10][10],int bonusSpere,int strikeRoll1,int strikeRoll2)
{
	int size = 11;
	int frame_score[size];//array to store the scores
	int i=0;
	frame_score[i]=0;
	int final_score;

	cout<<"HERE ARE THE SCORES FOR EACH FRAME: \n";
	for(int i=1; i<frame+1; ++i)//from frame 1 to 10
	{
		if(myRoll1[i][a] == 10)//strike condition
		{
			cout<<endl;
			frame_score[i]= myRoll1[i][a];//stores in 1
			if(i>frame-2)
			{
				if(i==frame-1)//second last frame
				{
					cout<<endl;
					frame_score[i]=frame_score[i]+frame_score[i-1]+myRoll1[i+1][a]+strikeRoll1;
					final_score=frame_score[i];
					cout<<endl<<endl;
				}	
				if(i==frame)//last frame
				{
					cout<<endl;
					frame_score[i]=frame_score[i]+frame_score[i-1]+strikeRoll1+strikeRoll2;
					final_score=frame_score[i];
					cout<<endl<<endl;
				}
			}
			else if(myRoll1[i+1][a] != 10)//other than strike case 
			{
				frame_score[i]=frame_score[i]+frame_score[i-1]+ myRoll1[i+1][a]+ myRoll2[i+1][b];
				final_score=frame_score[i];
				cout<<endl<<endl;
			}
			else
			{
				frame_score[i]=frame_score[i]+frame_score[i-1]+ myRoll1[i+1][a]+ myRoll1[i+2][a];
				final_score=frame_score[i];
				cout<<endl<<endl;
			}
		}
		else if((myRoll1[i][a] + myRoll2[i][b]) == 10)
		{
			frame_score[i]=frame_score[i-1]+ myRoll1[i][a]+myRoll2[i][b];
			if(i==frame)//last frame
			{
				frame_score[i]=frame_score[i]+bonusSpere;
				final_score=frame_score[i];
				cout<<endl<<endl;
			}
			else
			{
				frame_score[i]=frame_score[i]+myRoll1[i+1][a];
				final_score=frame_score[i];
				cout<<endl;
			}
		}
		else//general case 
		{
			frame_score[i]=frame_score[i-1]+myRoll1[i][a]+myRoll2[i][b];
			final_score=frame_score[i];
		}
		cout<<"|frame "<<i;
		cout<<"-> "<< "score: "<< left<<frame_score[i]<<"|";//scores for each frame
	}
	cout<<"total score : "<<final_score<<" |"<<endl;//total score
}

//check if the first is valid
bool isFirstValid(int m)
{
	if(m>10 || m<0 )
	return false;
	else
	return true;
}

//return valid score if the first is invalid
int validFirstnum(int m)
{
	while(isFirstValid(m) != true)
	{
		cout<<"Not Valid. Enter the valid score: ";
		cin>>m;
	}
	return m;
}

//check if the second is valid 
bool isSecondValid(int m,int n)
{
	if(n<0 || n > 10-m)
	return false;
	else
	return true;
}

//return valid if the second is invalid
int validSecondnum(int m,int n)
{
	while(isSecondValid(m,n) != true)
	{
		cout<<"valid: ";
		cin>>n;
	}
	return n;
}

//check if the ball hit the strike
bool isStrike(int m)
{
	if(m == 10)
		return true;
	else 
		return false;
}

//check if the ball hit the spare
bool isSpere(int m,int n)
{
	if((m+n)==10)
	return true;
	else
	return false;
}
