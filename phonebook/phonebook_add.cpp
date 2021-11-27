#include<stdio.h>
#include<ctype.h>
#include<time.h>
#include<string.h>
#include<windows.h>
#include<stdlib.h>
#include<conio.h>

void main_menu(); 
void phonebook_add();

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
	
phonebook_add();		
}

void phonebook_add()
{
	
	
	system("cls");
	FILE *fpointer;   
	fpointer = fopen("phonebook.txt","a");
	int condt,cikis,condt2;
	
	// --------------- //	
	
	fflush(stdin);	
	// ------------------- // Döngü


	
	do
	{	
		printf("Name:");
		fflush(stdin);		
		gets(contactsInfo.contact_name);  
		system("cls");
		contactsInfo.contact_name[0]=toupper(contactsInfo.contact_name[0]); 
		for (i=0;i<strlen(contactsInfo.contact_name); ++i)   
		{														 
			if(isalpha(contactsInfo.contact_name[i]))   
			{												 
				similarity = 1;
			}
			else
			{
				similarity = 0;
				break;
			}
		}
		if (!similarity)
		{	
			printf("Name contains number");
		}
	}while(!similarity);
	do
	{
		printf("Surname:");
		fflush(stdin);
		gets(contactsInfo.contact_surname);
		system("cls");
		contactsInfo.contact_surname[0]=toupper(contactsInfo.contact_surname[0]);
		for (i=0;i<strlen(contactsInfo.contact_surname); ++i)
		{
			if(isalpha(contactsInfo.contact_surname[i]))
				similarity = 1;
			else
			{
				similarity = 0;
				break;
			}
		}
		if (!similarity)
		{
			printf("Surname contains number");
			
		}
	}while(!similarity);
		printf("Tel No:");
		fflush(stdin);
		gets(contactsInfo.contact_no);
		system("cls");			
	
	fprintf(fpointer," %s %s %s \n\n", contactsInfo.contact_name, contactsInfo.contact_surname, contactsInfo.contact_no);
	fclose(fpointer);   
	// --------- // Kitap Kayit Sonu
	system("cls");
	
}


