#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <string.h>
#include <malloc.h>
#define SIZE 80
#define MAX 2147483647


// �� ����� � ����� 
int c_to_n(char c ){ 
	int n = 0;
	if ((c >= '0') && (c <= '9')){

		n = c - '0';
	}
	else if ((c >= 'A') && (c <= 'Z')){
		n = c - 'A' + 10;
	}
	else if ((c >= 'a') && (c <= 'z')){
		n =c - 'a' + 36;
	}
	else{
		printf("\n���������� ����: ������ �� ����������� � ������� :%d , %c",c, c );
		exit(0);
	}
	return(n);

}
// �� ������ � ����� 
int my_atoi(const char* str, int p) { 
	int max_t=MAX/p;
	//signed int n = 0;
	long long n = 0;
	int ost = MAX % p;
	for (int i = 0; str[i] != '\0'; i++){
	
		n = n * p + c_to_n(str[i]);
		if (n > MAX) {
			printf("����� �� �������� � ��������� ���������� �������� ��� int ");
			exit(0);
		}
	}
	return(n);
}
// ������� ������ ������ �� ����� 
void reverse(char *s){
	int i, j;
	char c;
	// strlen() ���������� ����� ������, �������������� ������� ��������
	for (i = 0, j = strlen(s) - 1; i < j; i++, j--){
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}
//�� ����� � ����� 
char n_to_c(int a){
	char c=0;
	if ((a >= 0) && (a <= 9)){
		c = a + '0';
	}
	else if (((a >= 10) && (a <= 35))){
		c = a + 55;
	}
	else if (((a >= 36) && (a <= 61))){
		c = a + 61;
	}
	return(c);
}
//�� �����  � ������
char* my_itoa(char* buf, int a, int p, int znak) {

	int i=0;
	//printf("%d", a);
	do {
		
		buf[i++] = n_to_c( a % p)  ;
		
		  
	} while ((a /= p) > 0);
	if (znak == -1) {
		buf[i++] = '-';
	}
	buf[i] = '\0';
	reverse(buf);// ������� ������ ������ �� ����� 
	
	printf("%s", buf);// �������� ������� 
	return(buf);

}
// ���������� ������������� ������� � ������ 
int max_sist( char * str , char p){
	char max_c=str[0];
	printf("\nmax_sist %s", str);
	for (int i = 1; i < p; i++){
		printf("\n%d\t%c\n", str[i], str[i]);
		if (str[i] > max_c){
			max_c = str[i];
		}
	}
	int  max_n = 0;
	max_n = c_to_n(max_c);
	//printf("\nMaxC=%c\n", max_c);
	//printf("\nMaxD=%d\n", max_n);
	return(max_n);
}
//����� ������� ���������� � ������� 
int check(char* str, int p) {
	for (int i = 0; str[i] != '\0'; i++) {
		int n = 0;
		n = c_to_n(str[i]);
		if (n > p) {
			return(0);
		}
	}
	return(1);
}
int main()
{
	setlocale(LC_ALL, "Rus");
	printf("������� ������� ���������\n");
	int sist;
	scanf_s("%d", &sist);
	printf("������� ������\n");
	char StrSim[SIZE];
	int i = 0;
	char c;
	int znak = 1;
	//������� getch ��������� ������ � ������� , �� �� ������� �� ����� , � ���������� �� i-��� ����� �
	while ((c = getch()) != '\r' ) {
	
    	putch(c);//��� ������� ���������� ����� ����� �� �����
		if ((c == '+')&&(i==0)) {
			znak = 1;
		}
		else if ((c=='-')&&(i == 0)){
			znak = -1;
		}
		else
		{
			if (c == 8) {
				if (i > 0) {
					i--;
					StrSim[i] = '\0';
				}
			}
			else {
				StrSim[i] = c;
				i++;
			}
		}
		
	}
	StrSim[i] = '\0';
	if (sist == 0){
		sist = max_sist( StrSim, i)+1;
		printf("\n�������\n%d\n", sist);
	}
	if ((sist > 62)||(sist<2)){
		printf("\n���������� ����: ������� ������� �� ����������� (2 <= p <= 62)");
		exit(0);
	}
	int ch = 1;
	ch= check(StrSim, sist);
	if (ch == 0) {
		printf("\n����� ��� �������� �������");
		exit(0);
	}
	printf("\n������ \n");
	printf("%s\n", StrSim);
	signed int chislo=0;
	chislo=my_atoi(StrSim, sist);
	printf("���������� \n%d", chislo*znak);
	printf("\n ����� ������ \n");
	char *NewStr;
	i++;// ��� '\0'
	if (znak == -1) {
		i++; // ��� '-'
	}
    NewStr = (char*)malloc(i * sizeof(char));
	my_itoa(NewStr, chislo,  sist, znak);
	free(NewStr);


}