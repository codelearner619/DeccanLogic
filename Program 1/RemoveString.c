#include<stdio.h>
#include<conio.h>
#include<string.h>
int main()
{
   char str[1000], word[100];
   int i, j, k, x, y, lS, lW, temp, chk=0, Inc, gap;
   
   printf("Enter the String: ");
   gets(str);
 //  scanf("%s", str);
  
   printf("Enter a Word: ");
   gets(word);
  //  scanf("%s", word);
/*  
   for (int k = 0; str[k] != '\0'; k++)  
   {
      return k;
     }
   
   
   lS = k;
   
   for (int x = 0; str[x] != '\0'; x++)  
   {
      return x;
     }
     
   lW = x;
 */  
   lS = strlen(str);
   lW = strlen(word);
   
   
   for(i=0; i<lS; i++)
   {
      temp = i;
      Inc = 0;
      for (j=0; j<lW; j++)
      {
         if (str[i] == word[j])
         {
            if (temp > 0 && (temp + lW)<lS)
            {
               if (str[temp - 1] == ' ' && str[temp + lW] == ' ')
                  Inc = 1;
            }
            else if (temp == 0 && (temp + lW) < lS)
            {
               if (str[temp + lW] == ' ')
                  Inc = 1;
            }
            else if (temp > 0 && (temp + lW) == lS)
            {
               if(str[temp - 1] == ' ')
                  Inc = 1;
            }
            if (Inc == 1)
               i++;
            else
               break;
         }
      }
      chk = i - temp;
      if (chk == lW)
      {
         i = temp;
         for (j=i; j<(lS-lW); j++)
            str[j] = str[j + lW];
         lS = lS - lW;
         i = temp;
         str[j]='\0';
      }
   }
   lS = strlen(str);
   i = 0;
   while (str[i] != '\0')
   {
      gap = 0;
      if (str[i] == ' ' && str[i+1] == ' ')
      {
         for(j=i; j<(lS-1); j++)
         {
            str[j] = str[j+1];
            gap = 1;
         }
      }
      if (i == 0 && str[i] == ' ')
      {
         for(j=i; j<(lS - 1); j++)
         {
            str[j] = str[j+1];
            gap = 1;
         }
      }
      if(gap == 0)
         i++;
      else
      {
         str[j] = '\0';
         lS--;
      }
   }
   printf("\nNew String = %s", str);
   getch();
   return 0;
}