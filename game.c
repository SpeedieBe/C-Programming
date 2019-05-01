#include <stdio.h>
#include <stdlib.h>

/* Global Variable*/
int choice,achoice,howmany,max,elapsed,maxDigits,runningScore,score,guess;
score=0;
runningScore=0;

/*Ask user what kind of ArithmeticGame*/
int askWhatArithmeticGame()
{
    int achoice;

    printf("Pick a type of Arithmetic Game.\n");
    printf("1.Addition\n");
    printf("2.Multiplication\n");
    printf("Your choice:");

    scanf("%d", &achoice);

    return achoice;
}

/*Arithmetic addition game*/
int addGame()
{
    /*Variable declaration*/
    int i,answer,rand1,rand2,max,howmany,end,start,elapsed;

    /* Redefine i as 0 in case user has done another game*/
    i=0;

    /*Start time function*/
    srand (time(NULL));

    /*Ask user for max number*/
    max=askMax();

    /*Ask user for how many questions*/
    howmany=howMany();

    /*Do while loop while i (The correct number of guess) <1*/
    do
    {
    /* Question calculation*/
    rand1= rand() % max+1;

    rand2= rand() % max+1;

    /*Start time*/
    start=time(NULL);

    /*Show user questions*/
    printf("%d + %d\n", rand1,rand2);

    /*Take answer*/
    scanf("%d", &answer);

        /*If answer is correct tell user and end loop*/
        if (answer=(rand1+rand2))
        {
        answer=rand1+rand2;
        printf("Correct!\n");
        i++;
        }

        /*If answer is incorrect tell user and loop*/
        else if (answer=!(rand1+rand2))
        {
        printf("Incorrect!\n");
        i++;
        }

    /*End time*/
    end=time(NULL);

    /*Time calculation*/
    elapsed=end-start;

    /*Get number of points*/
    numPoints(score);

    /*Add score to runningscore total*/
    runningScore=(score+runningScore);
    }
    while(i<=howmany);


}

/*Guessing game*/
int guessGame()
{
    /*Variable declartion*/
    int i,answer,rand1,rand2,max,howmany,end,start,elapsed;

    /* Redefine i as 0 in case user has done another game*/
    i=0;

    /*Start randomization*/
    srand(time(NULL));

    /*Ask user for max number*/
    printf("Choose a max number\n");
    scanf("%d",&max);

    /*Define random answer*/
    answer= rand() % max + 1;

    /*Start timer*/
    start=time(NULL);
    do
    {
        /*Ask for and take user's guess*/
        printf("Enter a guess!\n");
        scanf("%d", &guess);

        /*If answer is correct tell user and end loop*/
        if(answer==guess)
        {
            printf("Correct!\n");
            i++;
        }


        /*If answer is incorrect tell user and loop*/
        else if(answer<=guess)
        {
            printf("Too high, guess again!\n");
        }


        /*If answer is incorrect tell user and loop*/
        else if(answer>=guess)
        {
            printf("Too low, guess again!\n");
        }
    }
    while(i<1);

    /*End time*/
    end=time(NULL);

    /*Time calculation*/
    elapsed=end-start;

    /*Get number of points*/
    numPoints(score);

    /*Add score to runningscore total*/
    runningScore=(score+runningScore);



}

/*Ask user the maximum number for the game*/
int askMax()
{
    int max;

    printf("What is the maximum number you would like?\n");

    scanf("%d", &max);

    return max;
}

/*Ask user how many*/
int howMany()
{
    int howmany;
    printf("How many problems do you want?\n");

    scanf("%d", &howmany);

    return howmany;
}

/*Main menu*/
int mainMenu()
{
    int choice;
    /* Introduction and instructions */
    printf("\nHello, welcome to the game!\n");
    printf("Please make a selection from the following\n");

    /*Choices*/
    printf("1.Play Arithmetic Game\n");
    printf("2.Play Guessing Game\n");
    printf("3.Print Score\n");
    printf("4.Quit\n");
    printf("Enter your choice:");
    scanf("%d", &choice);
    return choice;
}

/*Count digits of entered max number for a return*/
int numDigits()
{
    if ( max < 10 )
        return 1;
    else if ( max < 100)
        return 2;
    else if (max <1000)
        return 3;
}

/* Calculate number of points earned*/
int numPoints()
{
    maxDigits=numDigits(max);

    if ((elapsed/(2*maxDigits)<1))
    {
       score=10;
    }

    else if(((1*maxDigits)<=1) || (elapsed/(2*maxDigits)<2))
    {
       score=9;
    }

    else if(((2*maxDigits)<=2) || (elapsed/(2*maxDigits)<3))
    {
       score=8;
    }

    else if(((2*maxDigits)<=3) || (elapsed/(2*maxDigits)<4))
    {
       score=7;
    }

    else if(((2*maxDigits)<=4) || (elapsed/(2*maxDigits)<5))
    {
       score=6;
    }

    else if(((2*maxDigits)<=5) || (elapsed/(2*maxDigits)<6))
    {
       score=5;
    }

    else if(((2*maxDigits)<=6) || (elapsed/(2*maxDigits)<7))
    {
       score=4;
    }

    else if(((2*maxDigits)<=7) || (elapsed/(2*maxDigits)<8))
    {
       score=3;
    }

    else if(((2*maxDigits)<=8) || (elapsed/(2*maxDigits)<9))
    {
       score=2;
    }

    else if(((2*maxDigits)<=9) || (elapsed/(2*maxDigits)<10))
    {
       score=1;
    }

    else if(((2*maxDigits)>=10))
    {
       score=0;
    }
    return score;
}

/* Multiplication game*/
int multiGame()
{
    /*Variable declaration*/
    int i,answer,rand1,rand2,max,howmany,end,start,elapsed;

    /* Redefine i as 0 in case user has done another game*/
    i=0;

    /*Start time function*/
    srand (time(NULL));

    /*Ask user for max number*/
    max=askMax();

    /*Ask user for how many questions*/
    howmany=howMany();

    /*Do while loop while i (The correct number of guess) <1*/
    do
    {
    rand1= rand() % max+1;

    rand2= rand() % max+1;

    /*Start time*/
    start=time(NULL);

    /*Show user questions*/
    printf("%d * %d\n", rand1,rand2);

    /*Take answer*/
    scanf("%d", &answer);
        /*If answer is correct tell user and end loop*/
        if (answer=(rand1*rand2))
        {
        answer=rand1*rand2;
        printf("Correct!\n");
        i++;
        }

        /*If answer is incorrect tell user and loop*/
        else if (answer=!(rand1*rand2))
        {
        printf("Incorrect!\n");
        i++;
        }

    /*End time*/
    end=time(NULL);

    /*Time calculation*/
    elapsed=end-start;

    /*Get number of points*/
    numPoints(score);

    /*Add score to runningscore total*/
    runningScore=(score+runningScore);
    }
    while(i<=howmany);
}

int main()
{
    /* call mainMenu for a choice */
    choice=mainMenu();

    /*If statement for option 1 */
    if (choice==1)
    {
        /* Call for askWhatArithmeticGame function*/
        achoice=askWhatArithmeticGame();

        /* If addition is chosen*/
        if (achoice==1)
        {
            /* Start addGame with how many questions the user wants*/
            addGame(howmany);

            /*Back to main menu*/
            main();
        }

        /* If multiplication is chosen*/
        else if (achoice==2)
        {
            /*Start multiGame with how many questions the user wants*/
            multiGame(howmany);

            /*Back to main menu*/
            main();
        }

        /* If none of the correct options are chosen*/
        else if (achoice<1 || achoice>2)
        {
            /* Tell user he is stupid and an unloved*/
            printf("Incorrect!\n");

            main();
        }
    }

    /*If statement for option 2 */
    else if (choice==2)
    {
        /*Call for guessing game*/
        guessGame();

        /*Back to main menu*/
        main();
    }

    /*If statement for option 3 */
    else if (choice==3)
    {
        /*Tell user score*/
        printf("\nYour score is %d\n", runningScore);

        /*Back to main menu*/
        main();
    }

    /*If statement for option 4 */
    else if (choice==4)
    {
        /*Quit Message*/
        printf("Game Over! \nThanks for playing I guess....\n");

    }

    /*If statement for if user can not follow instructions */
    else if (choice<1 || choice>4)
    {
        /* Tell user he is stupid and an unloved*/
        printf("Incorrect\n");

        /*Back to main menu*/
        main();
    }
    return 0;
}
