/*FLIGHT OF THE MESSENGER Game by Sarah Duncan. Started on the 28/12/2019. Written in C*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/* Functions*/
int Consent(char user_name[20]);
int Kelpie(void);
int Bridge(void);
int Toll(void);

int main(void)
{
	
	char user_name[20];
	/*Arrays for the message*/
	char size [3][10] =
	{
		"small",
		"tall",
		"giant"
	};
	char colour[6] [10] =
	{
		"red",
		"brown",
		"white",
		"gold",
		"silver",
		"black",
	};
	
	char animal[4][10] =
	{
		"wolf",
		"horse",
		"bear",
		"boar"
	};
	
	
	/*Coded message is randomised using the following functions*/
	srand(time(0));
	char code [3] [10]; 
	int num = rand()%2;
	for(int i=0; i<10; i++)
	{
	code[0][i]= size[num][i];
	}
	num= rand()%5;
	for(int i=0; i<10; i++)
	{
	code[1][i]= colour[num][i];
	}
	num= rand()%3;
	for(int i=0; i<10; i++)
	{
	code[2][i]= animal[num][i];
	}
	 
	/*Introduction*/
	printf("Welcome to FLIGHT OF THE MESSENGER\n (Press ENTER to Continue)");
	getchar();
	printf("You are a peasant, but you are a fast peasant.\nIn fact, you are the fastest peasant in all of Sunland.\nThat is why you are the King's Messenger\n");
	getchar();
	printf("HEY, HEY, YOU!\n");
	getchar();
	printf("You wake up with a start on your pile of hay. King's Messenger did not mean a King's wage.\n");
	getchar();
	printf("Hey get up!\n");
	printf("You open your eyes to see the ugly mug of the Sir John The Sufficent. He was a knight of the realm. Not a particularly prized knight, but a knight all the same.\n");
	getchar();
	printf("Come on, get up you're needed, er... What's your name again?\n");
	fgets(user_name,20,stdin);
	if (user_name[0] == '\n')
	{
		printf("Very funny, I'll ask you one more time. WHAT. IS. YOUR. NAME?\n");
		fgets(user_name,20, stdin);
		if(user_name[0] == '\n')
		{
			printf("... \n John looks upset. You better say something.\n");
			fgets(user_name, 20, stdin);
			if(user_name[0] == '\n')
			{
				printf("John seems very annoyed, very annoyed, why is he holding his fist back like...\n John punches you hard. The last thing you ever see is his ugly mug. You fail at life. You die. \n \n GAME OVER");
				return 0;
			}
		}
	}
	strtok(user_name,"\n");
	printf("Right then, hurry up %s! You are needed.", user_name);
	getchar();
	printf("After rubbing the sleep out of your eyes and putting on your only other set of clothes, the slightly cleaner set.");
	getchar();
	printf("You pick your way through the muddy roads of your village and follow Sir John up the steps of the castle\n");
	getchar();
	
	
	
	/*Castle Scene*/
	
	printf("The castle is the largest building for miles and full of long confusing corridors, but your destination is easier found. The Great Hall is visible from the front door of the palace and you can hear raised voices. You and Sir Tom enter and bow, the room descends into silence\n");
	getchar();
	printf("You look up to see a war counsel. The king and his general's seem stressed, sweat rolls down the side of their face.\n");
	printf(" Ah, Sir Tom you have returned with our most trustworthy messenger err...\n");
	getchar();
	printf("...");
	getchar();
	printf("%s, sire", user_name);
	getchar();
	printf("Yes, yes %s, now could you please bring the General Tomson the following coded message, exactly\n", user_name);
	printf( "Do you accept? (yes or no)");
	int reply= Consent(user_name);
	if(reply == 0)
	{
		return 0;
	}
	printf("Brillant! Here is the message I want you to give the General: \nthe %s %s %s.\n" , code[0],code[1],code[2]);
	getchar(); 
	printf("Right go to the border and give the message exactly.");
	getchar();
	printf("You head off on the road towards the border, running");
	getchar();
	
	/*Choosing the way to go*/
	int choice =9;
	int success;
	printf(" You have three paths to choose from \n [1] Along the South river where it is said that terrifying beasts swim. \n [2] Across the West river where you will have to choose your crossing point carefully lest you be swept up in the currents. \n [3] Or worst of all, over the bridge and pay *shudder* the TOLL.\n");
	scanf("%d", &choice);
	while( choice<1 || choice> 3)
	{
		printf("PLEASE CHOOSE 1 , 2 or 3");
		printf(" You have three paths to choose from \n [1] Along the South river where it is said that terrifying beasts swim. \n [2] Across the West river where you will have to choose your crossing point carefully lest you be swept up in the currents. \n [3] Or worst of all, over the bridge and pay *shudder* the TOLL.");
		scanf("%d", &choice);
	}
	switch (choice)
	{
	case 1:
		success=Kelpie();
		break;
	case 2:
		success=Bridge();
		break;
	case 3:
		success=Toll();
	}
	
	if(success==0)
	{
		return 0;
	}
	/*Ending Sequence*/
	char message [3] [10];
	printf("After that whole fiasco, you see the generals camp ahead. You arrive in and find the general.");
printf("Hello there, do you have a message for me? Here let me write it down.");
getchar();
printf("What size?");
	fgets(message[0],10, stdin);
	strtok(message[0],"\n");
	printf( "What colour?");
	fgets(message[1],10, stdin);
	strtok(message[1], "\n");
	printf("What animal?");
	fgets(message[2],10,stdin);
	strtok(message[2], "\n");
	if(strcmp(message[0],code[0])==0 && strcmp(message[1],code[1])==0&& strcmp(message[2], code[2])==0)
	{
		printf("You leave content that you have delivered your message. You go back to your village and rest. You wake up to laughter, groans and dysentry. But that is the life of a peasant, it sucks but it beats being invaded.\n CONGRATULATIONS  YOU HAVE BEATEN FLIGHT OF THE MESSENGER.");
	}
	else
	{
		printf(" You leave content that you have delivered your message. You go back to your village and rest. That night you hear shouts and screams. You peak out of your doorway. Your village has been overun. You delivered the wrong message. You have FAILED! \n GAME OVER");
	}
	return 0;	
}

/*Asks the user whether they would like to go on the quest*/
int Consent(char user_name[20])
{
	int reply=2;
	char answer  [4];
	char yes [4] = "yes";
	char no [4] = "no";
		fgets( answer, 4 , stdin);
	strtok(answer,"\n");
	if(strcmp(answer, yes)== 0)
	{
		reply = 1;
		return reply;
	}
	else if (strcmp(answer,no) == 0)
	{
		printf("WHAT!!!\n You suddenly realise that your life is bound to your king because democracy is a couple of centuries away. ");
		getchar();
		printf("The king composes himself and asks again. Will you bring this message?(yes)");
		fgets(answer,4,stdin);
		if(strcmp(answer,yes)!=0)
		{
			printf("Well you've done it now, Sir John The Sufficient is pulling out his sword, through sheer stupidity or just from a love of free-will, you have stuck to your guns (which coincidently also won't be invented for another few centuries.). The king nods his head to John and with that %s is no more\n GAME OVER", user_name);
			reply = 0;
			return reply;
		}
		else
		{
			reply=1;
			return reply;
		}
	}
	else
	{
		printf("Speak up I can't hear you! (type yes or no)");
		Consent(user_name);
	}
	
}

/*Option 1 Sequence of events. Uses branching conditional tasks*/
int Kelpie(void)
{
	int success;
	int reply=2;
	char answer  [4];
	char yes [4] = "yes";
	char no [4] = "no";
	strtok(answer,"\n");
	printf("You travel along the south river your legs feel tired\n");
	getchar();
	printf("Your legs ache, but you must keep going...");
	getchar();
	printf("At last, relief, up ahead you see a strange horse standing by the waters edge.");
	getchar();
	printf("It has a longer than usual back, its hooves are backwards, there's a red stain around its mouth");
	getchar();
	printf("That horse could make your journey so much easier, plus free horse, but still you remember the old songs; the ones about the river...");
	getchar();
	printf("Do you approach? (yes or no)");
	fgets( answer, 4 , stdin);
	strtok(answer, "\n");
	if(strcmp(answer,no)==0)
	{
		printf("You continue on your way. Briefly you and the horse make eye contact you break it first.\n");
		reply=1;
		return reply;
	}
	else
	{	
		char answer_2 [4];
		printf("You approach the horse it stays perfectly still\n");
		printf("Do you touch the horse?(yes or no)");
		getchar();
		fgets(answer_2, 4, stdin);
		strtok(answer_2,"\n");
		
		if(strcmp(answer_2,no)==0)
		{
			printf("You go to pat the horse but then you remember the old tales. You back up and start to run away. The horse begins to follow");
			getchar();
			printf("But then it stops, soon it will have easier prey");
			getchar();
			printf("You escape");
			reply=1;
			return reply;
		}
		else
		{
			printf("You pat the horse, but when you go to lift your hand it sticks firmly.");
			getchar();
			printf("Suddenly you remember, the songs of this river, the Tale of the Kelpie. You frantically try to pull away to no avail. The horse leaps forward into the river. Bringing you with it. The message never reaches its intended destination. \n GAME OVER");
			reply = 0;
			return reply;
		}
		
			
	}
	
	
}


/*Option2 Is a riddle using conditional branching*/
int Bridge(void)
{
	int success;
	printf("You head to the West river. You stand at the bank looking at the swirling currents below.");
	getchar();
	printf("What to do? What to do? You look around for some form of hope.");
	getchar();
	printf("You walk down the river until you come across a bridge. At last some hope!");
	printf("You begin to cross.You wonder why everybody uses the toll bridge when there's a free bridge only a mile upstream.");
	getchar();
	printf("WHO DARES CROSS MY BRIDGE WITHOUT SPEAKING TO ME!!!");
	getchar();
	printf("Oh yeah you remember now");
	getchar();
	printf("The Troll");
	getchar();
	printf(" He moved in under the bridge a couple of months ago. And every time someone tried to cross the river he tried to get them to answer his riddle");
	getchar();
	printf("It was the Dark Ages for crying out loud almost nobody did education!");
	getchar();
	printf("RIGHT PEASANT  YOU KNOW THE DEAL!!! ANSWER MY RIDDLE OR PREPARE TO BE DINNER!!");
	getchar();
	printf("You groan internally");
	getchar();
	int result=0;
	printf("A MERCHANT CAN PLACE 8 LARGE BOXES OR 10 SMALL BOXES INTO A CRATE FOR SHIPPING. IN 1 SHIPMENT, HE SENT A TOTAL OF 96 BOXES. IF THERE ARE MORE LARGE BOXES THAN SMALL BOXES, HOW MANY CRATES DID HE SHIP?(answer with a number) ");
	scanf("%d", &result);
	if (result!=11)
	{
		printf("The troll gives you a long stare.");
		getchar();
		printf("WRONG!!!\n");
		printf("He lunges forward and grabs you. The last thing you ever smell is stinky stinky breath. GAME OVER.");
		success=0;
	}
	else
	{
		printf("The troll nods approvingly.\n");
		getchar();
		printf("YOU MAY PASS");
		getchar();
		printf("You run across, only slowing when you were well away from the troll.");
		success=1;
	}
	return success;
}

/*Option 3 Maths Problem uses randomised numbers*/
int Toll(void)
{
	int success;
	srand(time(0));
	int main_fee  = rand()%100;
	int king_fee = rand()% 20;
	int red_sock_fee = rand()% 60;
	
	char comment_1[100];
	if( main_fee >= 50)
	{
		strcpy(comment_1,"(Well that was more than last time)");
	}
	else if (main_fee <= 10)
	{
		strcpy(comment_1, "(For once a bargain)");
	}
	else
	{
		strcpy(comment_1,"(Well fair I suppose)");
	}
	
	int total	= main_fee + king_fee + red_sock_fee;
	int user_total;
	printf(" This was demeaning you were a King's Messenger on business\n");
	getchar();
	printf("You stand at the gate of the toll bridge while the guard toted up your toll");
	getchar();
	printf("It was ridiculous everyday there seemed to be a different fee, and little extra payments always seemed to find their way in. ");
	getchar();
	printf(" Right lets see, hmm standard fee is %d. %s", main_fee , comment_1);
	getchar();
	printf("And since you are on king's business there's an additional fee of %d", king_fee);
	getchar();
	printf("Oh almost forgot pull up your trousers cuff.");
	getchar();
	printf("Hmm, yes, your socks are red, that's an additional... let's say %d\n", red_sock_fee);
	printf("Now add up your toll there for us\n");
	printf("You groan and remember that the guards were on commission to catch anyone underpaying or any bribery you better get this right(Answer in  number)");
	scanf("%d", &user_total);
	if(user_total< total)
	{
		printf("Haha very funny! Trying to cheat us? Well we will see if a day in the slammer losens your tongue");
		getchar();
		printf("You spend the day in the dungeon, your message unsent. GAME OVER");
		success=0;
	}
	else if(user_total> total)
	{
		printf("Trying to bribe us with a few extra coins? Well that won't do His Majesty told us we could have all the coin on the briber if we eliminated the problem. The last thing you feel is a sharp thud on your head. GAME OVER.");
		success=0;
	}
	else
	{
		printf("The guard frowns as you pay the correct toll. You continue on your way.\n");
		success=1;
	}
		
	return success;
}
