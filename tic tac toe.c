#include<stdio.h>
#include<conio.h>
char a[9]={'1','2','3','4','5','6','7','8','9'};
char player1[10],player2[10];
int m=0;
void check(char,char);


void check(char s, char p)
{
    if ((p==a[0]) || (p==a[1]) || (p==a[2]) || (p==a[3]) || (p==a[4]) || (p==a[5]) || (p==a[6]) || (p==a[7]) || (p==a[8]))
    {
        int i;
        for(i=0;i<9;i++)
        {
            if(a[i]==p)
            a[i]=s;
        }
    }
    else
    {
        printf("\n\t\tError:- plz enter the valid no.\t");
        printf("\n\t\tEnter the position:\t");
        fflush(stdin);
        scanf("%c",&p);
        check(s,p);
    }

}



void board()
{
    printf("\n\n\n\t\t\tTIC TAC TOE:");
    printf("\n\n\n\t\t\t|---|---|---|\n");
    printf("\t\t\t| %c | %c | %c |\n",a[0],a[1],a[2]);
    printf("\t\t\t|---|---|---|\n");
    printf("\t\t\t| %c | %c | %c |\n",a[3],a[4],a[5]);
    printf("\t\t\t|---|---|---|\n");
    printf("\t\t\t| %c | %c | %c |\n",a[6],a[7],a[8]);
    printf("\n\n\n\t\t%s symbol X\n",player1);
    printf("\t\t%s symbol O\n\n\n",player2);
    if(m==9)
        printf(" ");
    else
    {
        if (m%2==1)
            printf("\t\tIt is %s turn\n\n",player2);
        if (m%2==0)
            printf("\t\tIt is %s turn\n\n",player1);
    }
}


void input()
{
    char s,p;
    if(m%2==0)
        s='X';
    if(m%2==1)
        s='O';
    printf("\n\t\tEnter the position:\t");
   // fflush(stdin);
    //scanf("%c",&s);
    fflush(stdin);
    scanf("%c",&p);
    check(s,p);
    m++;
}

int game()
{
    input();
    system("cls");
    board();
    if ((a[0]=='O' && a[1]=='O' && a[2]=='O') ||(a[3]=='O' && a[4]=='O' && a[5]=='O') || (a[6]=='O' && a[7]=='O' && a[8]=='O'))
        return(2);
    if ((a[0]=='X' && a[1]=='X' && a[2]=='X') ||(a[3]=='X' && a[4]=='X' && a[5]=='X') || (a[6]=='X' && a[7]=='X' && a[8]=='X'))
        return(1);
    if ((a[0]=='O' && a[3]=='O' && a[6]=='O') ||(a[1]=='O' && a[4]=='O' && a[7]=='O') || (a[2]=='O' && a[5]=='O' && a[8]=='O'))
        return(2);
    if ((a[0]=='X' && a[3]=='X' && a[6]=='X') ||(a[1]=='X' && a[4]=='X' && a[7]=='X') || (a[2]=='X' && a[5]=='X' && a[8]=='X'))
        return(1);
    if ((a[0]=='X' && a[4]=='X' && a[8]=='X') ||(a[3]=='X' && a[4]=='X' && a[6]=='X'))
        return(1);
    if ((a[0]=='O' && a[4]=='O' && a[8]=='O') ||(a[3]=='O' && a[4]=='O' && a[6]=='O'))
        return(2);
    return(3);
}


void hello()
{
    int k;
    k=game();
    if(k==1)
        printf("\n\n\t\t\t %s WIN\n\n",player1);
    if(k==2)
        printf("\n\n\t\t\t %s WIN\n\n",player2);
    if(k==3)
        if(m<9)
            hello();
        else
            printf("\n\n\t\t\t It's a TIE\n\n");
}


void name()
{
    printf("\n\n\n\t\tEnter Player 1 name:  ");
    scanf("%s",&player1);
    system("cls");
    printf("\n\n\n\t\tEnter Player 2 name:  ");
    scanf("%s",&player2);
    system("cls");
}


void ttt()
{
    int i;
    name();
    board();
    hello();
    printf("press 1: play again\n");
    printf("press 2: quit game\n");
    scanf("%d",&i);
    if(i==1)
        ttt();
}


void main()
{
    ttt();

}
