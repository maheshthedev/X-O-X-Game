#include<iostream>
#include<cstdlib>
#include<conio.h>
#include<string>
using namespace std;
char m[3][3]={'1','2','3','4','5','6','7','8','9'};
string Player1,Player2;
void p()
{
cout<<"\n\tWELCOME TO X-O-X GAME ";
cout<<"\n\tEnter the Name of Player 1:";
cin>>Player1;
cout<<"\n\tEnter the Name of Player 2:";
cin>>Player2;
}
void draw()
{
    int i=0,j=0;
    cout<<"\n\n";
    cout<<"        "<<"-------------";
    cout<<"\n";

    for(i=0;i<3;i++)
    {
         cout<<"        | ";
        for(int j=0;j<3;j++)
        {
           cout<<m[i][j]<<" | ";
        }
        cout<<endl;
        cout<<"        "<<"-------------";
        cout<<endl;
    }
}
void player(char ch1,char ch2)
{
    draw();
    char op;
    int flag=0;
   cout<<"\n\tDear \""<<ch1<<"\"\n  Plz,Enter the Unoccupied Position :";
   cin>>op;
   for(int i=0;i<3;i++)
   {
       for(int j=0;j<3;j++)
       {
           if(op==m[i][j])
           {
               m[i][j]=ch1;
                flag=1;
           }

       }
   }
   if(flag==0)
   {
       cout<<"\n\n\t That Place was Already Occupied...! ( if \'Ok\' then click ENTER):";
        getch();
        player(ch1, ch2);
   }
}
int check(char ch1,char ch2)
{
    for(int i=0;i<3;i++)
    {
      if((m[i][0]==m[i][1])&&(m[i][1]==m[i][2]))
      {
        if(m[i][0]==ch1)
        {
            draw();
            cout<<"\n\n\t Congratulations to \" "<<Player1<<"\"";
            exit(0);
        }
        else
        {
            draw();
            cout<<"\n\n\t  Congratulations to \" "<<Player2<<"\"";
            exit(0);
        }
       }
      else if((m[0][i]==m[1][i])&&(m[1][i]==m[2][i]))
      {
        if(m[0][i]==ch1)
        {
            draw();
            cout<<"\n\n\t  Congratulations to \" "<<Player1<<"\"";
            exit(0);
        }
        else
        {
            draw();
            cout<<"\n\n\t  Congratulations to \" "<<Player2<<"\"";
            exit(0);
        }
       }
    }
    if((m[0][0]==m[1][1])&&(m[1][1]==m[2][2]))
    {
      if(m[0][0]==ch1)
        {
            draw();
            cout<<"\n\n\t  Congratulations to \" "<<Player1<<"\"";
            exit(0);
        }
        else
        {
            draw();
            cout<<"\n\n\t  Congratulations to \" "<<Player2<<"\"";
            exit(0);
        }
    }
    else if((m[0][2]==m[1][1])&&(m[1][1]==m[2][0]))
    {
      if(m[0][2]==ch1)
        {
            draw();
            cout<<"\n\n\t  Congratulations to \""<<Player1<<"\"";
            exit(0);
        }
        else
        {
            draw();
            cout<<"\n\n\t  Congratulations to \""<<Player2<<"\"";
            exit(0);
        }
    }
    else
    {
        int flag=1;
        for (size_t i = 0; i < 3; i++)
        {
            for (size_t j = 0; j < 3; j++)
            {
                if(m[i][j]=='X'||m[i][j]=='O')
                continue;
                flag = 0;
            }
        }
        if(flag==1) {
            cout<<"Oops! Draw. Well, Played "<<Player1<<","<<Player2;
            exit(0);
        }        
    }
    return 1;
}
int main()
{
    p();
    char ch1,ch2;
    system("CLS");
    cout<<"\n\tEnter Your Option ,Dear "<<Player1<<"(X/O):";
    cin>>ch1;
    if(ch1=='O') ch2 = 'X';
    if(ch1=='X') ch2 = 'O';
    cout<<"\n\tYour Option ,Dear "<<Player2<<" is "<<ch2;
    if((ch1=='O'||ch1=='X'||ch2=='O'||ch2=='X')&&(ch1!=ch2))
    {
        cout<<"\n\n\t Let's Start Game \" ALL THE BEST TO YOU GUYS \"";
        cout<<"\n\t( if \'Ok\' then click ENTER) :";
         getch();
        system("CLS");
        for(int i=0;i<10;i++)
        {
            if(check(ch1,ch2)!=0)
            {
                system("CLS");
                cout<<"\n\t Player 1 \""<<ch1<<"\" Player 2 \""<<ch2<<"\"";
                player(ch1, ch2);
                check(ch1, ch2);
                player(ch2,ch1);
                check(ch1, ch2);
            }
            else
            {
               cout<<"\n\t Game is Draw";
                cout<<" Game Over";
            }
        }
    }
    else
    {
        system("CLS");
        cout<<"\n\n\t \"PLEASE CHOOSE VALID OPTION\"";
        main();
    }
}
