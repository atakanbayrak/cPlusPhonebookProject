#include<stdio.h>
#include<ctype.h>
#include<time.h>
#include<string.h>
#include<windows.h>
#include<stdlib.h>
#include<conio.h>

void main_menu();
void phonebook_printout(); 

int i=0, similarity=0, found=0;      
char condt=0;					 


struct contacts             
{						     
	char contact_name[100];
	char contact_surname[100];
	char contact_no[30];
}contactsInfo;


int main() 
{	
	system("color a");
	main_menu(); 
}

void main_menu(void){	
	
phonebook_printout();		
}

void phonebook_printout()
{
	int found=0;
	char ad[20];
	FILE *fpointer;   
	system("cls");  
	fpointer=fopen("phonebook.txt","rb");    
	fflush(stdin);	 					 
	scanf("%s",ad);
	ad[0]=toupper(ad[0]);   
		
	
	while(fscanf(fpointer,"%s %s %s \n\n",contactsInfo.contact_name, contactsInfo.contact_surname, contactsInfo.contact_no)!=EOF)
	{
		if(strcmp(ad,contactsInfo.contact_no)==0)   
		{												  
			found=1;	
			printf("%s",contactsInfo.contact_no);								  
			break;
		}
	}
		
		if(!found) printf("There is no number like this.");
		fclose(fpointer);  		
}

