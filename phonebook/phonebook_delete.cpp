#include<stdio.h>
#include<ctype.h>
#include<time.h>
#include<string.h>
#include<windows.h>
#include<stdlib.h>
#include<conio.h>

void main_menu(); 
void phonebook_delete();

int i=0, similarity=0, found=0;      
char karar=0;	

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
	
phonebook_delete();		
}
void phonebook_delete()
{
	
	char numberWillBeDeleted[20],found;
	system("cls");
	FILE *fpointer,*fpointer2;     
	fpointer=fopen("phonebook.txt","r");  
	printf("Silinecek Kitabin Id'sini Giriniz: ");
	scanf("%s",&numberWillBeDeleted);
	fpointer2=fopen("phonebookTemporary.txt","w+");  
	if(fpointer==NULL)
	{
		
		printf("Boyle Bir Kitap Bulunmamaktadir!");
		
		printf("Ana Menuye Yonlendiriliyorsunuz");		
		main_menu();
	}
	else
	{
		while(fscanf(fpointer," %s %s %s \n",contactsInfo.contact_name,contactsInfo.contact_surname,contactsInfo.contact_no)!=EOF)
		{
			
				for(int x = 0 ; x <20 ; x++){
					
					if(numberWillBeDeleted[x] != contactsInfo.contact_no[x])	{
					
					fprintf(fpointer2," %s %s %s \n",contactsInfo.contact_name,contactsInfo.contact_surname,contactsInfo.contact_no);
					break;
					}
					
					else{
					
					found=1;
					break;
					}
					
				}	
		}
		if(!found)
		{	
			printf("Number didnt find");
		}
		else
		{
			
			printf("Completed");
		}
		fclose(fpointer);  
		fclose(fpointer2);
		remove("phonebook.txt"); 
		rename("phonebookTemporary.txt","phonebook.txt");  
	}

}
