#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <string.h>
#define SIZE 10

int c_to_n(char c )
{
	int n = 0;
	if ((c >= '0') && (c <= '9'))
	{

		n = c - '0';
	}
	else if ((c >= 'A') && (c <= 'Z'))
	{
		n = c - 'A' + 10;
	}
	else if ((c >= 'a') && (c <= 'z'))
	{
		n =c - 'a' + 36;
	}
	else
	{
		printf("ошибочка");
		exit(0);
	}
	return(n);

}

int my_atoi(const char* str, int p)//из строки в символ 
{
	
	int n = 0;
	for (int i = 0; str[i] != '\0'; i++)
	{

		n = n * p + c_to_n(str[i]);
	}
	return(n);
}
void reverse(char *s)
{
	int i, j;
	char c;

	for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}
char n_to_c(int a)
{
	char c;
	if ((a >= 0) && (a <= 9))
	{
		c = a + '0';
	}
	else if (((a >= 10) && (a <= 35)))
	{
		c = a + 55;
	}
	else if (((a >= 36) && (a <= 61)))
	{
		c = a + 61;
	}
	return(c);
}

char* my_itoa(char* buf, int a, int p)//из символа в строку
{
	int i=0;
	//printf("%d", a);
	do 
	{
		/*for (int i = 0; (a /= p) > 0; i++)
		{
			if ((a%10 >= '0') && (a % 10 <= '9'))
			{

				buf[i] = a % p + '0';
			}
			else if ((a % 10 >= 'A') && (a % 10 <= 'Z'))
			{
				buf[i] = a % p + 'A' - 10;
			}
			else if ((a % 10 >= 'a') && (a % 10 <= 'z'))
			{
				buf[i] = a % p + 'a' - 36;
			}
			
		}*/
		buf[i++] = n_to_c( a % p)  ;
		//printf("%d \t%d\t %c\n ",a, a % p, n_to_c(a % p));
		  
	} while ((a /= p) > 0);
	buf[i] = '\0';
	reverse(buf);// функция меняет строку на месте НЕ РАБОТАЕТ ВИДИМО НАДО НАПИСАТЬ 
	printf("%s", buf);// обратный порядок 
	return(buf);

}

int main()
{
	setlocale(LC_ALL, "Rus");
	printf("введиде систему счисления\n");
	int Sist;
	scanf_s("%d", &Sist);
	printf("введите строку\n");
	char StrSim[SIZE];
	int i = 0;
	char c;
	while ((c = getch()) != '\r' )//функция getch считывает символ с консоли , но не выводит на экран , а записывает на i-тое место в
	{
    	putch(c);//Эта функция производит вывод прямо на экран
		StrSim[i] = c;
		i++;
	}
	StrSim[i] = '\0';

	printf("\nстрока \n");
	printf("%s\n", StrSim);

	
	int chislo=0;
	chislo=my_atoi(StrSim, Sist);
	printf("получилось \n%d", chislo);
	printf("\nстрока \n");
	char NewStr[SIZE];
	my_itoa(NewStr, chislo,  Sist);
	


}