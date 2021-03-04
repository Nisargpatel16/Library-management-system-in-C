
#include <windows.h>
#include<stdio.h>                  
#include<conio.h>                   //contains delay(),getch(),gotoxy(),etc.
#include <stdlib.h>
#include<string.h>                  //contains strcmp(),strcpy(),strlen(),etc
#include<time.h>

                              //Defines gotoxy() for ANSI C compilers.                          
void gotoxy(short x, short y) 	 
{
COORD pos = {x, y};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

                            	//function declaration  
char catagories[][15]={"ICP","EVD","EC","CDE","ME","COM"};								                           
void lib_menu(void);
int  checkid(int);
void stu_menu();
void Password(void);		
void issuebook();
void border();
void dialogbox();
void time_1(void);
void student();
void librarian();
void time1();
int Login_check_stu(char id[],char pass[]);
int Login_check_lib(char id[],char pass[]);
void addbooks(void);
void viewbooks_stu(void);
void viewbooks_lib(void);
void searchbook_stu(void);
void searchbook_lib(void);
void issuebooks(void);
int  get_info();

	FILE *fp,*fz;
 	char *fid, *fpass, *token;
 	char findbook;
int s;
struct books
{
    int id;
    char stname[20];
    char name[20];
    char Author[20];
    int quantity;
    float Price;
    int count;
    char pub[20];
    char *cat;

};
struct books a;

                                    //  MAIN() FUNCTION
int main()
 {
    int check=0,x=0,b=1;
    char id[20], pass[20],ch;
  	border();
	int c=1,d;
	gotoxy(20,5);
	time1();
	gotoxy(70,5);
	time_1();
	system("color 70");
	gotoxy(20,8);
    while(b<10)
	{
		printf("* "); 
        Sleep(90); 
		b++;   	
	}
	printf(" LIBRARY MANAGMENT SYSTEM");
	while(c<10) 
	{
		printf("* "); 
        Sleep(5);
		c++;    	
	}
	gotoxy(20,11);
	printf("Please choose one of the below option to login!!!");
	gotoxy(20,14);
	printf(" 1. Student  ");
	Sleep(5);
	gotoxy(20,17);
	printf(" 2. Librarian");
	Sleep(5);
	gotoxy(20,20);
	printf(" 3. Close Application");
	gotoxy(20,23);
	printf("Enter your choice:");
	scanf("%d",&d);
	
	switch(d)
	{
		case 1: student();
		        break;
		   
		case 2: librarian();
		        break;  
				
		case 3: gotoxy(20,25); 
		        printf("loading!!!!!");
		        dialogbox();
		        
		        getch();
		        Sleep(10);
		        exit(0);
		        break;	      
	} 
}
                                    // border() function		
void border()
{
  	int i=1,j=178,k=1,l=1,m=1,n=3,b=1;
	printf("\n\n\t\t");
	while(k<=84)
	{
		printf("%c",j);
		k++;
	}
    while(i<=26)
    {
        printf("\n\t\t%c",j);
        i++;   
    }
    while(m<=26)
    {
        printf(" %c",j);
        gotoxy(98,n);
        m++;
        n++;
    }
    gotoxy(0,28);
    printf("\t\t");
    while(l<=84)
	{
		printf("%c",j);
		l++;
	}
}

			                    // Student function	
void student()	
{
	int check=0,x=0,b=1;
    char id[20], pass[20],ch;
    system("cls");
    border();
    gotoxy(22,10);
    printf("Enter student username and password:");
    gotoxy(22,12);
    printf("------------------------------------\n");
    gotoxy(22,13);
    printf("Enter your User ID:\n");
    gotoxy(22,14);
    printf("-------------------------------------");
    gotoxy(42,13);
    scanf("%s", id);
    gotoxy(22,17);
    printf("------------------------------------\n");
    gotoxy(22,18);
    printf("Enter your Password:\n");
    gotoxy(22,19);
    printf("------------------------------------"); 
    gotoxy(43,18);
     while(ch!=13)
     {
 	    ch=getch();
 	     if(ch!=13&&ch!=8)
 		{
			putch('*');
			pass[x]=ch;
			x++;
		}
     }
     pass[x]='\0';
     check = Login_check_stu(id, pass);
     if (check==1)
     { 
       gotoxy(25,22);
	   while(b<15)
       {
		  printf("* "); 
          Sleep(90); 
	      b++;   	
       }
       gotoxy(25,23);
       printf("Login successful...  Press any key to continue");
  	   getch();
  	   system("cls");
   	   stu_menu();
   	   getch();
     }                   
     else
     {
  	   gotoxy(25,22);
  	   while(b<15)
       {
		  printf("* "); 
          Sleep(90); 
	      b++;   	
       }	
	   gotoxy(25,23);
   	   printf("Login failed. Try again...");
   	   getch();
   	   system("cls");
   	   student();
	 }
}



int Login_check_stu(char id[], char pass[])
{
	int check=0;
 	const char str[40], s[3] = " ";
	fp = fopen("student.txt","r");
 	if(fp==NULL) 
 	{ 
   		printf("File error..."); 
		exit(0); 
 	}
	while(fgets(str,40,fp)!=NULL)
 	{
   		fid = strtok(str,s);  
   		fpass = strtok(NULL,s);
   		fpass[strlen(fpass)-1]='\0';
  		if((strcmp(id,fid) == 0) && (strcmp(pass,fpass) == 0 ))
    	{
 	    	check=1;  
    	}
	}
 	return check;
}


void stu_menu()
{  
    border();
	int c=1,b=1,l;
	char ch;
	gotoxy(20,5);
	printf("WELCOME!!!");
	gotoxy(20,6);
	printf("****STUDENT****");
	gotoxy(20,8);
    while(b<15)
	{
		printf("* "); 
        Sleep(90); 
		b++;   	
	}
	printf(" MAIN MENU ");
    while(c<15) 
	{
		printf("* "); 
        Sleep(5);
		c++;    	
	} 
    gotoxy(20,11);
	printf(" 1. View Booklist   ");
	Sleep(5);
	gotoxy(20,14);
	printf(" 2. Search book");
	Sleep(5);
	gotoxy(20,17);
	printf(" 3. close application");
	Sleep(5);
	gotoxy(20,20);
	printf("Enter your choice:");
	scanf("%d",&l);
	switch(l)
	{
		case 1: viewbooks_stu();
		        break;
		        
	    case 2: searchbook_stu();
	             break;
	    
	    case 3: exit(0);
	}
	
}		
                              // librarian functio
void librarian()
{
	int check=0,x=0,b=1;
    char id[20], pass[20],ch;
    system("cls");
    border();
    gotoxy(22,10);
    printf("Enter your librarian username and password:");
    gotoxy(22,12);
    printf("------------------------------------\n");    
	gotoxy(22,13);
    printf("Enter your User ID:\n");
	gotoxy(22,14);
    printf("-------------------------------------");
    gotoxy(42,13);
    scanf("%s", id);
    gotoxy(22,17);
    printf("------------------------------------\n");
    gotoxy(22,18);
    printf("Enter your Password:\n");
    gotoxy(22,19);
	printf("------------------------------------"); 
	gotoxy(43,18);
    while(ch!=13)
    {
       ch=getch();
       if(ch!=13&&ch!=8)
 	   {
			putch('*');
			pass[x]=ch;
			x++;
		}
 	}
    pass[x]='\0';
    check = Login_check_lib(id, pass);
    if (check==1)
    { 
  	    gotoxy(25,22);
  	    while(b<15)
    	{
		  printf("* "); 
          Sleep(90); 
	      b++;   	
    	}
        gotoxy(25,23);
  	    printf("Login successful...  Press any key to continue");
  	    getch();
  	    system("cls");
   	    lib_menu();
   	    getch();
    }                  
    else
    {
      gotoxy(25,22);
      while(b<15)
      {
		  printf("* "); 
          Sleep(90); 
	      b++;   	
      }	
      gotoxy(25,23);
      printf("Login failed. Try again...");
      getch();
      system("cls");
      librarian();
	}
    return 0;	
}


int Login_check_lib(char id[], char pass[])
{
	FILE *fp;
 	//char *fid, *fpass, *token;
 	int check=0;
 	const char str[40], s[2] =" ";
 	fp = fopen("librarian.txt","r");
 	if(fp==NULL) 
 	{ 
   		printf("File error...");
	    exit(0); 
 	}
	while(fgets(str, 40, fp)!=NULL)
 	{
 		fid = strtok(str,s);  
   		fpass = strtok(NULL,s);
   		fpass[strlen(fpass)-1]='\0';
   		if((strcmp(id,fid) == 0) && (strcmp(pass,fpass) == 0 ))
    	{
 		    check=1;  
    	}
	}
 	return check;
}

void lib_menu(void)

{   
    border();
	int c=1,b=1,l;
	gotoxy(20,3);
	printf("WELCOME!!!");
	gotoxy(20,5);
	printf("****LIBRARIAN****");
	gotoxy(20,7);
    while(b<15)
	{
		printf("* "); 
        Sleep(90); 
		b++;   	
	}
	printf(" MAIN MENU ");
    while(c<15) 
	{
		printf("* "); 
        Sleep(5);
		c++;    	
	} 
    gotoxy(20,10);
	printf(" 1. Add Books   ");
	Sleep(5);
	gotoxy(20,12);
	printf(" 2. Delete books");
	Sleep(5);
	gotoxy(20,14);
	printf(" 3. Search Books");
	Sleep(5);
	gotoxy(20,16);
	printf(" 4. Issue Books");
	Sleep(5);
	gotoxy(20,18);
	printf(" 5. Book list");
	Sleep(5);
	gotoxy(20,20);
	printf(" 6. Edit Book's Record");
	Sleep(5);
	gotoxy(20,22);
	printf(" 7. Exit Application");
	gotoxy(20,24);
	printf("Enter your choice:");
	scanf("%d",&l);
	switch(l)
	{
		case 1: addbooks();
		        break;
		case 3: searchbook_lib();
				break;
		case 4: issuebook();
				break;
		case 5: viewbooks_lib();
				break;
		case 7: dialogbox();
				break;
	}
}


void viewbooks_stu(void)  //show the list of book persists in library
{
	int i=0,j;
	char m,ch;
	system("cls");
	gotoxy(1,1);
	printf("____________________________________AVILAIBLE BOOKS_______________________________");
	gotoxy(2,2);
	printf(" CATEGORY   BOOK ID    BOOK NAME     AUTHOR    QUANTITY   PRICE  Publisher name ");
	j=4;
	fp=fopen("savefile.txt","r");
	//while(fscanf(fp,"%d %s %s %f %d %s",&a.id,a.name,a.Author,&a.Price,&a.quantity,a.pub)==1)
	while((ch=getc(fp))!=EOF)
	//while(ch!="  ")
	{
		fscanf(fp,"%s %d %s %s %f %d %s",a.cat,&a.id,a.name,a.Author,&a.Price,&a.quantity,a.pub);
		gotoxy(3,j);
		printf("%s",a.cat);
		gotoxy(16,j);
		printf("%d",a.id);
		gotoxy(22,j);
		printf("%s",a.name);
		gotoxy(36,j);
		printf("%s",a.Author);
		gotoxy(54,j);
		printf("%d",a.quantity);
		gotoxy(57,j);
		printf("%.2f",a.Price);
		gotoxy(69,j);
		printf("%s",a.pub);
		printf("\n\n");
		j++;
		i=i+a.quantity;

	}
	gotoxy(3,25);
	printf("Total Books =%d",i);
	fclose(fp);
	
	gotoxy(3,27);
	printf("go to main menu please enter(y/n)");
	if(getch()=='y')
    	{
        	system("cls");
        	stu_menu();
    	}	
     else
     {
        system("cls");
        exit(0);
     }
}


void viewbooks_lib(void)  //show the list of book persists in library
{
	int i=0,j;
	char ch;
	system("cls");
	gotoxy(1,1);
	printf("____________________________________AVILAIBLE BOOKS_______________________________");
	gotoxy(2,2);
	printf(" CATEGORY   BOOK ID    BOOK NAME     AUTHOR    QUANTITY   PRICE  Publisher name ");
	j=4;
	fp=fopen("savefile.txt","r");
	//fprintf(fp,"hii");
	//while(fscanf(fp,"%d %s %s %f %d %s",&a.id,a.name,a.Author,&a.Price,&a.quantity,a.pub)==1)
	while((ch=getc(fp))!=EOF)
	//while(ch!="  ")
	{	//printf("hii");
		fscanf(fp,"%s %d %s %s %f %d %s",a.cat,&a.id,a.name,a.Author,&a.Price,&a.quantity,a.pub);
		gotoxy(3,j);
		printf("%s",a.cat);
		gotoxy(16,j);
		printf("%d",a.id);
		gotoxy(22,j);
		printf("%s",a.name);
		gotoxy(36,j);
		printf("%s",a.Author);
		gotoxy(50,j);
		printf("%d",a.quantity);
		gotoxy(57,j);
		printf("%.2f",a.Price);
		gotoxy(69,j);
		printf("%s",a.pub);
		printf("\n\n");
		j++;
		i=i+a.quantity;

	}
	gotoxy(3,25);
	printf("Total Books =%d",i);
	fclose(fp);
	
	gotoxy(3,27);
	printf("go to main menu please enter(y/n)");
	if(getch()=='y')
    	{
        	system("cls");
        	lib_menu();
    	}	
     else
     {
        system("cls");
        exit(0);
     }
}




void addbooks(void)    //funtion that add books
{
    system("cls");
    border();
    int i;
    gotoxy(20,5);
    printf("\t\t**************SELECT CATEGOIES*****************");
    gotoxy(20,8);
    printf(" 1.> ICP");
    gotoxy(20,10);
    printf("2.> EVD");
    gotoxy(20,12);
    printf("3.> EC");
    gotoxy(20,14);
    printf("4.> CDE");
    gotoxy(20,16);
    printf("5.> ME");
    gotoxy(20,18);
    printf("6.> COM");
    gotoxy(20,20);
    printf("7.> Back to main menu");
    gotoxy(20,23);
    printf("Enter your choice:");
    scanf("%d",&s);
    if(s==7)
    lib_menu();
    system("cls");
    border();
    fp=fopen("savefile.txt","a+");
    if(get_info()==1)
    {
    	a.cat=catagories[s-1];
    	//fprintf("\n");
    	fseek(fp,0,SEEK_END);
    	fprintf(fp,"\n%s %d %s %s %.2f %d %s",a.cat,a.id,a.name,a.Author,a.Price,a.quantity,a.pub);
    	fclose(fp);
    	gotoxy(21,23);
    	printf("The record is sucessfully saved");
    	gotoxy(21,24);
    	printf("Save any more?(Y / N):");
    	if(getch()=='n')
    	{
        	system("cls");
        	lib_menu();
    	}	
     else
     {
        system("cls");
        addbooks();
     }
	}
}    


int get_info()
{
    int t,i;
    gotoxy(20,6);
    printf("Enter the Information Below");
    gotoxy(20,8);
    printf("Category:");
    gotoxy(30,8);
    printf("%s",catagories[s-1]);
    gotoxy(21,10);
    printf("Book ID:\t");
    gotoxy(33,10);
    scanf("%d",&t);
/*  if(checkid(i) == 0)
    {
    	system("cls");
    	border();
        gotoxy(21,12);
        printf("\aThe book id already exists\a");
        getch();
        system("cls");
        lib_menu();
        return 0;
    }*/
    a.id=t;
    gotoxy(21,13);
    printf("Book Name:");
	gotoxy(33,13);
    scanf("%s",a.name);
    gotoxy(21,15);
    printf("Author:");
	gotoxy(33,15);
    scanf("%s",a.Author);
    gotoxy(21,17);
    printf("Quantity:");
	gotoxy(33,17);
    scanf("%d",&a.quantity);
    gotoxy(21,19);
    printf("Price:");
	gotoxy(33,19);
    scanf("%f",&a.Price);
    gotoxy(21,21);
    printf("Publisher name:");
	gotoxy(38,21);
    scanf("%s",&a.pub);
    return 1;
}

void time1()
{
	SYSTEMTIME stime;
	GetSystemTime(&stime);
	printf("%d /%d /%d",stime.wDay,stime.wMonth,stime.wYear);

}

void searchbook_stu(void)
{
    system("cls");
    char ch1;
    int d,ci=0;
    border();
    gotoxy(20,8);
    printf("*****************************Search Books*********************************");
    gotoxy(20,10);
    printf(" 1. Search By ID");
    gotoxy(20,14);
    printf("2. Search By Name");
    gotoxy(20,16);
    printf("Enter Your Choice");
   // scanf("%d",&ci);
    //printf("%d",c);
   // getch();
    fp=fopen("savefile.txt","r"); 
    rewind(fp);   
    switch(getch())
    {
      case '1':
    	{
        	system("cls");
        	border();
        	gotoxy(20,8);
        	printf("****Search Books By Id****");
       		gotoxy(20,10);
        	printf("Enter the book id:");
        	scanf("%d",&d);
        	gotoxy(20,12);
        	printf("Searching........");
        	while((ch1=getc(fp))!=EOF)
        	{
        		fscanf(fp,"%d %s %s %f %d %s",&a.id,a.name,a.Author,&a.Price,&a.quantity,&a.pub);     
        		if(a.id==d)
        		{
            		sleep(2);
         		    gotoxy(20,13);
         	        printf("The Book is available");
            		gotoxy(20,15);
            		printf(" ID:%d",a.id);gotoxy(47,9);
            		gotoxy(20,16);
            		printf(" Name:%s",a.name);gotoxy(47,10);
            		gotoxy(20,17);
            		printf(" Author:%s ",a.Author);gotoxy(47,11);
            		gotoxy(20,18);
        
		    		printf(" Qantity:%d ",a.quantity);gotoxy(47,12); gotoxy(47,11);
            		gotoxy(20,19);
            		printf(" Price:Rs.%.2f",a.Price);gotoxy(47,13);
            		gotoxy(20,20);
            		printf(" Publisher name:%s",a.pub);gotoxy(47,14);
            		gotoxy(20,21);
            		//findbook='t';
            		ci++;
        		}
 			}
       		if(ci!=0)  //checks whether conditiion enters inside loop or not
      	  	{
        		gotoxy(20,13);
        		printf("\aNo Record Found");
       		}
        	gotoxy(20,23);
       		printf("Try another search?(Y/N)");
        	if(getch()=='y')
        	{
        		system("cls");
        		searchbook_stu();
        	}else
        	{
        		system("cls");
        		stu_menu();
        	
			}break;
    	}
    case '2':
   	{
        char s[15];
        system("cls");
        border();
        gotoxy(20,8);
        printf("****Search Books By Name****");
        gotoxy(20,10);
        printf("Enter Book Name:");
        scanf("%s",s);
        int d=0;
        while((ch1=getc(fp))!=EOF)
        {
        	fscanf(fp,"%d %s %s %f %d  ",&a.id,a.name,a.Author,&a.Price,&a.quantity);             
            if(strcmp(a.name,(s))==0) 
        	{	
            	gotoxy(20,12);
            	printf("The Book is available");
            	gotoxy(20,14);
            	printf(" ID:%d",a.id);gotoxy(47,9);
            	gotoxy(20,15);
            	printf(" Name:%s",a.name);gotoxy(47,10);
            	gotoxy(20,16);
            	printf(" Author:%s",a.Author);gotoxy(47,11);
            	gotoxy(20,17);
            	printf(" Qantity:%d",a.quantity);gotoxy(47,12);
            	gotoxy(20,18);
            	printf(" Price:Rs.%.2f",a.Price);gotoxy(47,13);
            	gotoxy(20,19);
            	printf(" Publisher name:%s",a.pub);gotoxy(47,14);
            	gotoxy(20,20);
            	d++;
        	}
 		}
        if(d==0)
        {
        	gotoxy(20,12);printf("\aNo Record Found");
        }
        gotoxy(20,23);
        printf("Try another search?(Y/N)");
        	if(getch()=='y')
        	{
        		system("cls");
        		searchbook_stu();
        	}else
        	{
        		system("cls");
        		stu_menu();
        	
			}break;
    }
    default :
    getch();
    searchbook_stu();
  }
  fclose(fp);
}
void searchbook_lib(void)
{
    system("cls");
    char ch1;
    int d,ci=0;
    border();
    gotoxy(20,8);
    printf("*****************************Search Books*********************************");
    gotoxy(20,10);
    printf(" 1. Search By ID");
    gotoxy(20,14);
    printf("2. Search By Name");
    gotoxy(20,16);
    printf("Enter Your Choice");
   // scanf("%d",&ci);
    //printf("%d",c);
   // getch();
    fp=fopen("savefile.txt","r"); 
    rewind(fp);   
    switch(getch())
    {
      case '1':
    	{
        	system("cls");
        	border();
        	gotoxy(20,8);
        	printf("****Search Books By Id****");
       		gotoxy(20,10);
        	printf("Enter the book id:");
        	scanf("%d",&d);
        	gotoxy(20,12);
        	printf("Searching........");
        	while((ch1=getc(fp))!=EOF)
        	{
        		fscanf(fp,"%d %s %s %f %d  ",&a.id,a.name,a.Author,&a.Price,&a.quantity);     
        		if(a.id==d)
        		{
            		sleep(2);
         		    gotoxy(20,13);
         	        printf("The Book is available");
            		gotoxy(20,15);
            		printf(" ID:%d",a.id);gotoxy(47,9);
            		gotoxy(20,16);
            		printf(" Name:%s",a.name);gotoxy(47,10);
            		gotoxy(20,17);
            		printf(" Author:%s ",a.Author);gotoxy(47,11);
            		gotoxy(20,18);
        
		    		printf(" Qantity:%d ",a.quantity);gotoxy(47,12); gotoxy(47,11);
            		gotoxy(20,19);
            		printf(" Price:Rs.%.2f",a.Price);gotoxy(47,13);
            		gotoxy(20,20);
            		printf(" Publisher name:%s",a.pub);gotoxy(47,14);
            		gotoxy(20,21);
            		//findbook='t';
            		ci++;
        		}
 			}
       		if(ci!=0)  //checks whether conditiion enters inside loop or not
      	  	{
        		gotoxy(20,13);
        		printf("\aNo Record Found");
       		}
        	gotoxy(20,23);
       		printf("Try another search?(Y/N)");
        	if(getch()=='y')
        	{
        		system("cls");
        		searchbook_lib();
        	}else
        	{
        		system("cls");
        		lib_menu();
        	
			}break;
    	}
    case '2':
   	{
        char s[15];
        system("cls");
        border();
        gotoxy(20,8);
        printf("****Search Books By Name****");
        gotoxy(20,10);
        printf("Enter Book Name:");
        scanf("%s",s);
        int d=0;
        while((ch1=getc(fp))!=EOF)
        {
        	fscanf(fp,"%d %s %s %f %d  ",&a.id,a.name,a.Author,&a.Price,&a.quantity);             
            if(strcmp(a.name,(s))==0) 
        	{	
            	gotoxy(20,12);
            	printf("The Book is available");
            	gotoxy(20,14);
            	printf(" ID:%d",a.id);gotoxy(47,9);
            	gotoxy(20,15);
            	printf(" Name:%s",a.name);gotoxy(47,10);
            	gotoxy(20,16);
            	printf(" Author:%s",a.Author);gotoxy(47,11);
            	gotoxy(20,17);
            	printf(" Qantity:%d",a.quantity);gotoxy(47,12);
            	gotoxy(20,18);
            	printf(" Price:Rs.%.2f",a.Price);gotoxy(47,13);
            	gotoxy(20,19);
            	printf(" Publisher name:%s",a.pub);gotoxy(47,14);
            	gotoxy(20,20);
            	d++;
        	}
 		}
        if(d==0)
        {
        	gotoxy(20,12);printf("\aNo Record Found");
        }
        gotoxy(20,23);
        printf("Try another search?(Y/N)");
        	if(getch()=='y')
        	{
        		system("cls");
        		searchbook_lib();
        	}else
        	{
        		system("cls");
        		lib_menu();
        	
			}break;
    }
    default :
    getch();
    searchbook_lib();
  }
  fclose(fp);
}


void time_1(void)
{
	time_t t;
	time(&t);
	printf("%s",ctime(&t));
	
//	getch();
}

void dialogbox()
{
	MessageBox(0,"confirm exit\n library management  - ICP","Nisarg Patel",4);
	return 0;
}
void issuebook()
{
	system("cls");
	border();
	int i;
	gotoxy(10,3);
	printf("1>Issue a book");
	gotoxy(10,5);
	printf("2>View issued book");
	gotoxy(10,7);
	printf("Enter your choice - ");
	switch(getch())
	{
		case '1':
		{
			int x=0;
			char next='y';
			while(next=='y')
			{
				system("cls");
				gotoxy(10,4);
				printf("Enter a book id - ");
				scanf("%d",&i);
				fp=fopen("savefile.txt","r");
				fz=fopen("issuefile.txt","a+");
			//	checkid(i);
			//	fprintf(fz,"%d %s %s %f %d %s",a.id,a.name,a.Author,a.Price,a.quantity,a.pub);
				if(checkid(i)==0)
				{
					gotoxy(10,6);
					printf("The book record is available");
					gotoxy(10,8);
					printf("There are %d unissued books in the library",a.quantity);
					gotoxy(10,10);
					printf("The name of the book is %s",a.name);
					printf("\nEnter student name ");
					scanf("%s",a.stname);
					fseek(fz,sizeof(a),SEEK_END);
					fprintf(fz,"\n%s %d %s %.2f",a.stname,a.id,a.name,a.Price);
					fclose(fz);
				}	
				gotoxy(10,15);
				printf("Want to issue any other book : Y/N");
				fflush(stdin);
				next=getche();	
				fclose(fp);
			}
			break;
		}
		case '2':
		{
			system("cls");
			char ch;
			int i=5;
			printf("#######  Issued book list  ########");
			gotoxy(4,4);
			printf("STUDENT NAME   ID    BOOK NAME   PRICE");
			fz=fopen("issuefile.txt","r");
			while((ch=getc(fz))!=EOF)
			{	
				fscanf(fz,"%s %d %s %f",a.stname,&a.id,a.name,&a.Price);
				gotoxy(4,i);
				printf("%s",a.stname);
				gotoxy(10,i);
				printf("%d",a.id);
				gotoxy(14,i);
				printf("%s",a.name);
				gotoxy(18,i);
				printf("%f",a.Price);
				i++;
			}
			fclose(fz);
			
		}
	}
}



int checkid(int i)  //check whether the book is exist in library or not
{
	char ch3;
	rewind(fp);
	while((ch3=getc(fp))!=EOF)
	{
		fscanf(fp,"%d %s %s %f %d %s",&a.id,a.name,a.Author,&a.Price,&a.quantity,a.pub);
			//fprintf(fz,"%d %s %s %f %d %s",a.id,a.name,a.Author,a.Price,a.quantity,a.pub);
		//printf("%d ",a.id);
		if(a.id==i)
		{	
		//	fprintf(fz,"hiii");
			return 0;  //returns 0 if book exits
		}
	}
	return 1;
}
