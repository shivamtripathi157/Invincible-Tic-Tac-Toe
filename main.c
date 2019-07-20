/*TIC TAC TOE GAME
*Author:SHIVAM TRIPATHI
*22 Jan 2017
*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
char matrix[3][3];
int score_player=0,score_comp=0;

void init_matrix();
void get_player_move();
void get_computer_move();
void display_matrix();
void check();
void display_rule();
void display_matrix_coord();
void display_score();
void game_round_manager();
void display_move();
void main()
{
    printf("\n\n\n\n\n%46s","*** WELCOME ***");
    printf("\n\n%45s","TO THE GAME OF");
    printf("\n\n%44s","TIC-TAC-TOE");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t-Press Enter to play.....");
    getch();
    display_rule();
    init_matrix();
    game_round_manager();
    getch();

}
void game_round_manager()
{
        display_move();
        get_player_move();
        check();
        get_computer_move();
        check();
        game_round_manager();
}
void init_matrix()
{
    int i,j;
    for (i=0;i<3 ;i++ )
        for (j=0;j<3;j++)
            matrix[i][j]=' ';
}
void display_matrix_coord()
{
    char i;
    printf("Coordinates are:\n");
    for (i='1';i<='3' ;i++ )
    {
        printf(" %c%c | %c%c | %c%c ",i,'1',i,'2',i,'3');
        if (i!='3')
            {
                printf("\n----|----|----\n");
            }
    }

}
void display_rule()
{
        char i;
    system("cls");
    printf("\nRules are:\n");
    printf("\n1.You play against Computer\n");
    printf("\n2.You mark 'X' Computer marks 'O'\n");
    printf("\n3.Enter the cordinates(X,Y) of cell to mark cell with 'X'\n\n");
    for (i='1';i<='3' ;i++ )
    {
        printf(" %c%c | %c%c | %c%c ",i,'1',i,'2',i,'3');
        if (i!='3')
            {
                printf("\n    |    |    ");
                printf("\n----|----|----\n");
            }
    }
    printf("\n\n4.One who fills three adjacent column or row or diagonal cells first with 'X' or 'O' respectively wins the set");
    printf("\n\n5.One who wins two sets first or who has greater score after 5th round wins the match");
    printf("\n\n\nPress Enter to continue>>>\n");
    getch();
    system("cls");
}
void display_move()
{
    system("cls");
        display_matrix_coord();
        display_matrix();
}
void get_player_move()
{
    int x,y,n;
    char str[3];
    printf("\nEnter the coordinates(X,Y) of  cell to mark cell with 'X':\n");
    str[0]=getche();
    if(str[0]=='\r')
        str[0]=getche();
    str[1]=getche();
    n=atoi(str);
    x=n/10;
    y=n%10;
    x--;
    y--;
    if (matrix[x][y]!=' ')
    {
        printf("\a\nInvalid move!,Try again");
        get_player_move();
    }
    else
    {
        matrix[x][y]='X';
    }
}
void get_computer_move()
{
    int i,j,count=0;

    /*check if any row has two O*/
    for (i=0;i<3 ;i++ )
    {
        count=0;
        for(j=0;j<3;j++)
            if(matrix[i][j]=='O')
                count++;
        if(count==2)
            for(j=0;j<3;j++)
                if (matrix[i][j]==' ')
                   {
                    matrix[i][j]='O';
                    return;
                   }

    }
     /*check if any column has two O*/
    for (i=0;i<3 ;i++ )
    {
        count=0;
        for(j=0;j<3;j++)
            if(matrix[j][i]=='O')
                count++;
        if(count==2)
            for(j=0;j<3;j++)
                if (matrix[j][i]==' ')
                   {
                       matrix[j][i]='O';
                       return;
                   }

    }
    /*check main diagonal for two O*/
    count=0;
    for(i=0;i<3;i++)
        {
            if(matrix[i][i]=='O')
                count++;
        }
    if(count==2)
        for(i=0;i<3;i++)
                if (matrix[i][i]==' ')
                    {
                            matrix[i][i]='O';
                            return;
                    }

    /*check other diagonal for two O*/
    count=0;
     for(i=0,j=2;i<3;i++,j--)
                if (matrix[i][j]=='O')
                    count++;
     if(count==2)
            for(i=0,j=2;i<3;i++,j--)
                if (matrix[i][j]==' ')
                    {
                        matrix[i][j]='O';
                        return;
                    }

    /*check if any row has two X*/
    for (i=0;i<3 ;i++ )
    {
        count=0;
        for(j=0;j<3;j++)
            if(matrix[i][j]=='X')
                count++;
        if(count==2)
            for(j=0;j<3;j++)
                if (matrix[i][j]==' ')
                   {
                    matrix[i][j]='O';
                    return;
                   }

    }
     /*check if any column has two X*/
    for (i=0;i<3 ;i++ )
    {
        count=0;
        for(j=0;j<3;j++)
            if(matrix[j][i]=='X')
                count++;
        if(count==2)
            for(j=0;j<3;j++)
                if (matrix[j][i]==' ')
                   {
                       matrix[j][i]='O';
                       return;
                   }

    }
    /*check main diagonal for two X*/
    count=0;
    for(i=0;i<3;i++)
        {
            if(matrix[i][i]=='X')
                count++;
        }
    if(count==2)
        for(i=0;i<3;i++)
                if (matrix[i][i]==' ')
                    {
                            matrix[i][i]='O';
                            return;
                    }

    /*check other diagonal for two X*/
    count=0;
     for(i=0,j=2;i<3;i++,j--)
                if (matrix[i][j]=='X')
                    count++;
     if(count==2)
            for(i=0,j=2;i<3;i++,j--)
                if (matrix[i][j]==' ')
                    {
                        matrix[i][j]='O';
                        return;
                    }

    /*check any band diagonal for two X*/
    if(matrix[0][1]=='X'&&matrix[1][0]=='X'&&matrix[0][0]==' ')
        {
            matrix[0][0]='O';
            return;
        }
    else if(matrix[0][1]=='X'&&matrix[1][2]=='X'&&matrix[0][2]==' ')
        {
            matrix[0][2]='O';
            return;
        }
    else if(matrix[1][0]=='X'&&matrix[2][1]=='X'&&matrix[2][0]==' ')
        {
            matrix[2][0]='O';
            return;
        }
    else if(matrix[1][2]=='X'&&matrix[2][1]=='X'&&matrix[2][2]==' ')
        {
            matrix[2][2]='O';
            return;
        }
      /*occupy central position i.e:2,2 before user*/

    if (matrix[1][1]==' ')
    {
        matrix[1][1]='O';
        return;
    }

    /*check if any row has one O*/
    for (i=0;i<3 ;i++ )
    {
        count=0;
        for(j=0;j<3;j++)
            if(matrix[i][j]=='O')
                count++;
            else if(matrix[i][j]=='X')
                count--;
        if(count==1)
            for(j=0;j<3;j=j+2)
                if (matrix[i][j]==' ')
                   {
                    matrix[i][j]='O';/*printf("1");*/
                    return;
                   }

    }
     /*check if any column has one O*/
    for (i=0;i<3 ;i++ )
    {
        count=0;
        for(j=0;j<3;j++)
            if(matrix[j][i]=='O')
                count++;
            else if(matrix[j][i]=='X')
                count--;
        if(count==1)
            for(j=0;j<3;j=j+2)
                if (matrix[j][i]==' ')
                   {
                       matrix[j][i]='O';
                       return;
                   }

    }
    /*check main diagonal for one O*/
    count=0;
    for(i=0;i<3;i++)
        {
            if(matrix[i][i]=='O')
                count++;
            if(matrix[i][i]=='X')
                count--;
        }
    if(count==1)
        for(i=0;i<3;i++)
                if (matrix[i][i]==' ')
                    {
                            matrix[i][i]='O';
                            return;
                    }

    /*check other diagonal for one O and no X*/
    count=0;
     for(i=0,j=2;i<3;i++,j--)
    {
        if (matrix[i][j]=='O')
            count++;
        if(matrix[i][j]=='X')
            count--;
    }
     if(count==1)
            for(i=0,j=2;i<3;i++,j--)
                if (matrix[i][j]==' ')
                    {
                        matrix[i][j]='O';printf("4");
                        return;
                    }

    /*find a row with no X*/
      for (i=0;i<3 ;i++ )
      {
        for (j=0;j<3 ;j++ )
                if (matrix[i][j]=='X')
                    break;
            if (j==3)
                for(j=0;j<3;j=j+2)
                    if(matrix[i][j]==' ')
                        {
                            matrix[i][j]='O';
                            return;
                        }
      }
      /*find a column with no X*/
      for (i=0;i<3 ;i++ )
      {
        for (j=0;j<3 ;j++ )
                if (matrix[j][i]=='X')
                    break;
            if (j==3)
                for(j=0;j<3;j=j+2)
                    if(matrix[j][i]==' ')
                        {
                            matrix[j][i]='O';
                            return;
                        }
      }
      /*to fill any blank cell if no condition applied*/
    for (i=0;i<3 ;i++ )
    {
        for (j=0;j<3 ;j++ )
                if (matrix[i][j]==' ')
                    break;
            if (matrix[i][j]==' ')
                break;
    }
        matrix[i][j]='O';
        return;

}
void display_matrix()
{
    int t;
    printf("\n\n\n");
    for (t=0;t<3 ;t++ )
    {
        printf(" %c | %c | %c ",matrix[t][0],matrix[t][1],matrix[t][2]);
        if (t!=2)
            printf("\n---|---|---\n");
    }
    printf("\n");
}
void check()
{
    int i,j,count;
    char winner;
    for (i=0;i<3 ;i++ )
        if (matrix[i][0]==matrix[i][1]&&matrix[i][0]==matrix[i][2])
            winner= matrix[i][0];
    for (i=0;i<3 ;i++ )
        if (matrix[0][i]==matrix[1][i]&&matrix[0][i]==matrix[2][i])
            winner= matrix[0][i];
    if (matrix[0][0]==matrix[1][1]&&matrix[0][0]==matrix[2][2])
        winner= matrix[0][0];
    if(matrix[0][2]==matrix[1][1]&&matrix[1][1]==matrix[2][0])
        winner= matrix[0][2];
      if (winner=='X')
    {
        display_move();
        printf("\a\n\n\tYou Win this round!!!");
        getch();
        score_player++;
        display_score();
    }
    else if(winner=='O')
    {
        display_move();
        printf("\a\n\n\tComputer Wins this round!!!");
        getch();
        score_comp++;
        display_score();
    }
    /*to check if there is only one cell left*/
    count=0;
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            if(matrix[i][j]==' ')
                count++;
     if(count<=1)
    {
        display_move();
        printf("\a\nIt's a Draw!!");
        getch();
        display_score();
    }
}
void display_score()
{
    static int round=1;
    system("cls");
    printf("\t *** SCOREBOARD ***");
    printf("\n\n\t     YOU | COMPUTER");
    printf("\n    ROUND %d:  %d  |  %d",round,score_player,score_comp);
    if(score_player==2)
    {
        printf("\n\n\n\n\n\n\n\a*Congrats You Win this match!!!");
        getch();
        exit(EXIT_SUCCESS);
    }
    else if(score_comp==2)
    {
        printf("\n\n\n\n\n\n\n\aOops Computer Wins this Match!!!");
        getch();
        exit(EXIT_SUCCESS);
    }
    else if(round==5)
    {
        if(score_comp>score_player)
            printf("\n\n\n\n\n\n\n\aCongrats You Win this match!!!");
        else if(score_comp==score_player)
            printf("\n\n\n\n\n\n\aCongrats You are as good as this Computer.\n\n\n\t\tIt's a Tie!");
        else
            printf("\n\n\n\n\n\n\n\aOops Computer Wins this Match!!!");
        getch();
        exit(EXIT_SUCCESS);
    }
    printf("\n\n\n\t\t\t-Press enter to play next round>>>");
    round++;
    getch();
    system("cls");
    init_matrix();
    game_round_manager();/*to play next round*/
}
