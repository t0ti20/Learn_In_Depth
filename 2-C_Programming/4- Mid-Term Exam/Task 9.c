#include <stdio.h>
void Reverse_Char(char Start[],char End[])
{
    while (Start<End) 
    {
          *Start^=*End;
          *End^=*Start;
          *Start++^=*End--;
    }
}
void Reverse_Words(char String[])
{
    char *Word_Start=String ;
    char *Temp=String;
    while (Temp[0]) 
    {
        Temp++;
        if (!Temp[0]) Reverse_Char(Word_Start,Temp-1);
        else if (Temp[0]==' ') 
        {
          Reverse_Char(Word_Start,Temp - 1);
          Word_Start = Temp + 1;
        }
    }
    Reverse_Char(String, Temp - 1);
}
int main ()
{
    char String[] = "mohamed gamal.";
    Reverse_Words(String);
    printf("%s",String);
    return 0;
}