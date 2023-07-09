#include <stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

#define CANDIDATE_COUNT
#define CANDIDATE1 "ALPHA"
#define CANDIDATE2 "BRAVO"
#define CANDIDATE3 "CHARLIE"
#define CANDIDATE4 "DELTA"

int votesCount1 = 0, votesCount2 = 0, votesCount3 = 0, votesCount4 = 0, spoiledtvotes = 0;
FILE *p;
void castVote()
{
	system("cls");
    int choice;
    int n;
    char cnic[14];
    printf("Enter your CNIC:");
    scanf("%s",cnic);
    if(Find(cnic)==0)
    {
    p=fopen("CNIC.txt","a");
    fprintf(p,cnic);
    fprintf(p,"\n");
    fclose(p);
    }
    printf("\n #### Please choose your Candidate ####");
    printf("\n 1. %s", CANDIDATE1);
    printf("\n 2. %s", CANDIDATE2);
    printf("\n 3. %s", CANDIDATE3);
    printf("\n 4. %s", CANDIDATE4);
    printf("\n 5. %s", "None of These");
    printf("\n Input your choice (1 - 4) : ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        votesCount1++;
        break;
    case 2:
        votesCount2++;
        break;
    case 3:
        votesCount3++;
        break;
    case 4:
        votesCount4++;
        break;  
    case 5:
        spoiledtvotes++;
        break;
    default:
        printf("\n Error: Wrong Choice !! Please retry");
        getchar();
    }
    system("cls");
    printf("\n Your vote is appreciated. !!");
}
int Find(char *CNIC)
{
	int back;
	char temp[14];
	FILE *p=fopen("CNIC.txt","r");
	while(fscanf(p," %s",temp)!=EOF)
	{
		if(strcmp(temp,CNIC)==0)
		{
				printf(" [ %s ] Your Vote is Already Casted \n press 0 to proceed to back menu.",temp);
				scanf("%d",&back);
				fclose(p);
				if (back==0)
				{
					main();
				}
				return 0;	
		}
	}
	printf("***[%s] Welcome*** ",CNIC);
	fclose(p);
}
void votesCount()
{
	system("cls");
    printf("\n ##### Voting Statics ####");
    printf("\n %s - %d ", CANDIDATE1, votesCount1);
    printf("\n %s - %d ", CANDIDATE2, votesCount2);
    printf("\n %s - %d ", CANDIDATE3, votesCount3);
    printf("\n %s - %d ", CANDIDATE4, votesCount4);
    printf("\n %s - %d ", "Spoiled Votes", spoiledtvotes);
}
void outcome()
{
	system("cls");
	float total;
	total=(float)votesCount1+votesCount2+votesCount3+votesCount4+spoiledtvotes;
	total=(total/51)*100;
	printf("Vote Casted With resoect to population is %.1f",total);
}
void getLeadingCandidate()
{
	system("cls");
    printf("\n  #### Leading Candiate ####");
    if (votesCount1 > votesCount2 && votesCount1 > votesCount3 && votesCount1 > votesCount4)
        printf("[%s]", CANDIDATE1);
    else if (votesCount2 > votesCount3 && votesCount2 > votesCount4 && votesCount2 > votesCount1)
        printf("[%s]", CANDIDATE2);
    else if (votesCount3 > votesCount4 && votesCount3 > votesCount2 && votesCount3 > votesCount1)
        printf("[%s]", CANDIDATE3);
    else if (votesCount4 > votesCount1 && votesCount4 > votesCount2 && votesCount4 > votesCount3)
        printf("[%s]", CANDIDATE4);
    else
        printf("----- Warning !!! No-win situation-----");
}

int main()
{
    int i;
    int choice;
    printf("Enter Your Choice\n1.Online\n2.Offline\n3.About");
    scanf("%d",&choice);
    switch(choice)
    {
    	case 1:
    	{
    		system("cls");
    		do                                                              
			   { 		                                                        
			       printf("\n\n ###### Welcome to Voting System 2022 #####");  
			       printf("\n 1. Cast the Vote");                            
			       printf("\n 2. Find Vote Count");
				   printf("\n 3. Find Vote percentage with respect to population");                            
			       printf("\n 4. Find leading Candidate");                     
			       printf("\n 0. Exit");                                       
			       printf("\n Please enter your choice : ");                 
			       scanf("%d", &choice);                                       
			       switch (choice)                                             
			       {                                                           
			       case 1:                                                     
			           castVote();                                             
			           break;                                                  
			       case 2:                                                     
			           votesCount();                                           
			           break;
				   case 3:
				       outcome();
					   break;	                                                     
			       case 4:                                                     
			           getLeadingCandidate();                                  
			           break;
				   case 0 :
				       exit(0);                                                  
			       default:                                                    
			           printf("\n Error: Invalid Choice");                     
			       }                                                           
			   } while (choice != 0);                                          
			                                                                   
			   // hold the screen                                              
			   getchar();                                                     		
		}
		break;
		case 2:
		{ int choicee;
			system("cls");
			printf("There are 3 regions available.\n Select 1 for Karachi.\n Select 2 for Lahore \n Select 3 for Peshawar.");	
			scanf("%d",&choicee);
			switch(choicee)
			{
				case 1:
				printf("Voting will begin at 7am in Saddar, Karachi till 9pm.\nMake sure you bring your CNIC.");
				break;
				
				case 2:
				printf("Voting will begin at 7am in Shahwala Road,Lahore till 9pm.\nMake sure you bring your CNIC.");
				break;
				
				case 3:
				printf("Voting will begin at 7am in Maskan,Peshawar till 9pm.\nMake sure you bring your CNIC.");
				break;
			}
		}
		
		case 3:
			{
				printf("This voting system has been designed to minmize the complexity for the citizens with a fairly lower academic background while conducting a safe and accurate voting system. It can be either used for a relatively smaller structure or even on a bigger scale such as provinicial, federal or business votings .The simple menu enables users to experience voting \nwhile simulataneously allowing them to save time in a safe manner. You have been provided the choice of either voting online or choose a region to vote offline.You can vote, check for the winning candidate and even find total vote count.");
			}
	}
    return 0;
}