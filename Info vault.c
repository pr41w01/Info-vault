#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

struct person
{
    char name[35];
    char address[50];
    char department[35];
    char email[30];
    unsigned long long int mble_no;
    int year, month, day, hour, minute, second;
};
void password();
void addrecord();
void deleterecord();
void searchrecord();
void listview();
void modifyrecord();
void recent();
void exportToTxt();
void factoryReset();
void got();
void menu();

void printHeader(const char *title)
{
    system("cls");
    printf("\t\t\t\t\t\t  |-----------------------------------------|\n");
    printf("\t\t\t\t\t\t  |*************** INFO VAULT **************|\n");
    printf("\t\t\t\t\t\t  |-----------------------------------------|\n");
    printf("\n%s\n\n", title);
}

void printMenu()
{
    printf("\n\n\n\t\t\t\t\t\t_____________________________________________________\n");
    printf("\t\t\t\t\t\t|1. Add New        |  2. Delete  |  3. Search       |\n");
    printf("\t\t\t\t\t\t|------------------|-------------|------------------|\n");
    printf("\t\t\t\t\t\t|4. List Details   |  5. Modify  |  6. Export data  |\n");
    printf("\t\t\t\t\t\t|------------------|-------------|------------------|\n");
    printf("\t\t\t\t\t\t|7. Department Stat|  8. Recents |  9. Logout       |\n");
    printf("\t\t\t\t\t\t|__________________|_____________|__________________|\n");
    printf("\n\t\t\t\t\t\tEnter your choice: ");
}

void printFooter()
{
    printf("\n\n\t\t\t\t\t\tPress any key to continue...");
	getch();
    system("cls");
    password();
}

void animateLoading()
{
    printf("Loading");
    for (int i = 0; i < 3; i++)
    {
        Sleep(500);
        printf(".");
        fflush(stdout);
    }
    printf("\n");
}



int main()
{
    system("color 0f");
    password();

    return 0;
}

void password()
{
    char username[20];
    char password[20];
    int passIndex = 0;

    printHeader("\t\t\t\t\t\t\t   WELCOME TO INFO VAULT");
    printf("\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    printf("\n\n\n\t\t\t\t\t\tLogin Here\n\n\t\t\t\t\t\tEnter Username: ");
    scanf("%s", username);

    printf("\n\t\t\t\t\t\tEnter password: ");

    char ch;
    while ((ch = getch()) != '\r')
    {
        if (ch == 8)
        {
            if (passIndex > 0)
            {
                passIndex--;
                printf("\b \b");
            }
        }
        else
        {
            password[passIndex++] = ch;
            printf("*");
        }
    }

    password[passIndex] = '\0';

    if (strcmp(username, "appleorange") == 0 && strcmp(password, "5304") == 0)
    {
        printf("\n\n\n\t\t\t\t\t\tLogin successful. ");
        animateLoading();
        menu();
    }
    else
    {
        printHeader("\n\t\t\t\t\t\tLOGIN FAILED:(");
        printf("\t\t\t\t\t\tIncorrect username or password.\n");
        printFooter();
        exit(0);
    }
}

void menu()
{
    printHeader("\t\t\t\t\t\t\t\t    MAIN MENU");
    printMenu();

    switch (getch())
    {
   	case'0':
        factoryReset();
    	break;
    case '1':
        addrecord();
        break;
    case '2':
        deleterecord();
        break;
    case '3':
        searchrecord();
        break;
    case '4':
        listview();
        break;
    case '5':
        modifyrecord();
        break;
    case '6':
        exportToTxt();
        break;
    case '7':
        printAddressStatistics();
        break;
    case '8':
    	recent();
    	break;
    case '9':
        password();
        break;
	default:
        printHeader("\t\t\t\t\t\t INVALID CHOICE");
        printf("\t\t\t\t\t\t Enter a valid option (1-9)\n");
        printFooter();
        menu();
    }
}

// Implement other functions (addrecord, deleterecord, searchrecord, listview, modifyrecord) similarly.
void addrecord()
{
        system("cls");
        printf("\t\t\t\t\t\t  |-----------------------------------------|\n");
    printf("\t\t\t\t\t\t  |*************** INFO VAULT **************|\n");
    printf("\t\t\t\t\t\t  |-----------------------------------------|\n");
        FILE *f;
        struct person p;
        f=fopen("project","ab");
        printf("\n\t\t\t\t\t\t Enter name: ");
        scanf(" %[^\n]",&p.name);
         for (int i = 0; p.name[i] != '\0'; i++) {
        if (!(isalpha(p.name[i]) || isspace(p.name[i]))) {
			printf("\t\t\tInvalid input! Please enter only characters for the name.\n");
            sleep(2);
			fclose(f);
		//	return;
            menu();
        }
        
    }
        printf("\n\t\t\t\t\t\t Enter complete name of Department(Upper Case): ");
        scanf(" %[^\n]",&p.department);
        printf("\n\t\t\t\t\t\t Enter the address: ");
        scanf(" %[^\n]",&p.address);
        printf("\n\t\t\t\t\t\t Enter official email: ");
        scanf("%s",&p.email);
        
        printf("\n\t\t\t\t\t\t Enter phone no:");
        scanf("%llu",&p.mble_no);

        
       time_t currentTime;
       time(&currentTime);
       struct tm *localTime = localtime(&currentTime);
       
    p.year = localTime->tm_year + 1900; 
    p.month = localTime->tm_mon + 1;     
    p.day = localTime->tm_mday;
    p.hour = localTime->tm_hour;
    p.minute = localTime->tm_min;
    p.second = localTime->tm_sec;
    printf("\n\t\t\t\t\t\t Your data was saved at: %04d-%02d-%02d %02d:%02d:%02d\n",p.year, p.month, p.day, p.hour, p.minute, p.second);


    
    
        fwrite(&p,sizeof(p),1,f);
         

      fflush(stdin);
        printf("\n\t\t\t\t\t\t record saved");

fclose(f);

    printf("\n\n\t\t\t\t\t\t Enter any key");

	 getch();
    system("cls");
    menu();
}

void deleterecord()
{
	system("cls");
	printf("\t\t\t\t\t\t  |-----------------------------------------|\n");
    printf("\t\t\t\t\t\t  |*************** INFO VAULT **************|\n");
    printf("\t\t\t\t\t\t  |-----------------------------------------|\n");
    struct person p;
    FILE *f, *ft;
    int flag = 0;
    char name[100];

    f = fopen("project", "rb");
    if (f == NULL)
    {
        printf("\n\t\t\t\t\t\t CONTACT'S DATA NOT ADDED YET.");
        sleep(2);
        menu();
    }
    else
    {
        ft = fopen("temp", "wb");
        if (ft == NULL)
        {
            printf("\n\t\t\t\t\t\t file opening error");
            fclose(f);
            getch();
            menu();
        }
        else
        {
            printf("\n\t\t\t\t\t\t Enter person's name to delete: ");
            got(name);

           fflush(stdin);
            while (fread(&p, sizeof(p), 1, f) == 1)
            {
                if (strcmp(p.name, name) != 0)
                    fwrite(&p, sizeof(p), 1, ft);
                else
                    flag = 1;
            }
            fclose(f);
            fclose(ft);

            if (flag == 0)
            {
                printf("\n\n\t\t\t\t\t\tNO CONTACT'S RECORD FOUND FOR DELETION.");
            }
            else
            {
                printf("\n\t\t\t\t\t\t  RECORD DELETED SUCCESSFULLY.");
                remove("project");
                rename("temp", "project");
            }
        }
    }

    printf("\n\t\t\t\t\t\t Press any key to continue...");
    getch();
    system("cls");
    menu();
}


  void searchrecord(){
	system("cls");
	printf("\t\t\t\t\t\t  |-----------------------------------------|\n");
    printf("\t\t\t\t\t\t  |*************** INFO VAULT **************|\n");
    printf("\t\t\t\t\t\t  |-----------------------------------------|\n");
	
	 struct person p;
     FILE *f;
     char name[100];

     f=fopen("project","rb");
     if(f==NULL)
              {
        printf("\n\t\t\t\t\t\t  Something went wrong!\a\a\a\a");
        sleep(2);
        menu();

          }
printf("\n\t\t\t\t\t\t Enter name of person to search:");
got(name);
//scanf("%s",&name);
while(fread(&p,sizeof(p),1,f)==1)
{
    if(strcmp(p.name,name)==0)
    {
        printf("\n\t\t\tDetail Information About %s",name);
        printf("\n\t\t\tName:%s\n\t\t\tAddress:%s\n\t\t\tDepartment:%s\n\t\t\tMobile no:%llu\n\t\t\tE-mail:%s",p.name,p.address,p.department,p.mble_no,p.email);
        printf("\n\t\t\tData saved time: %04d-%02d-%02d %02d:%02d:%02d\n",p.year, p.month, p.day, p.hour, p.minute, p.second);
    }
    else {
	printf("\n\t\t\tData not found");
	}
        
}

 fclose(f);
  printf("\n\t\t\t\t\t\t  Enter any key");

	 getch();
    system("cls");
menu();
	
}

void listview() {
	system("cls");
	printf("\t\t\t\t\t\t  |-----------------------------------------|\n");
    printf("\t\t\t\t\t\t  |*************** INFO VAULT **************|\n");
    printf("\t\t\t\t\t\t  |-----------------------------------------|\n");
    
    struct person p;
    FILE *f;
    f = fopen("project", "rb");

    if (f == NULL) {
        printf("\n\t\t\t\t\t\t File opening error in listing.");
       getch();
        menu();
    }

    while (fread(&p, sizeof(p), 1, f) == 1) {
        printf("\n\n\n YOUR RECORD:\n");
        printf("Name=%s\nAddress=%s\nDepartment=%s\nE-mail=%s\nMobile no=%llu\n", p.name, p.address, p.department, p.email, p.mble_no);
        printf("Data saved time: %04d-%02d-%02d %02d:%02d:%02d\n", p.year, p.month, p.day, p.hour, p.minute, p.second);
        printf("===================================================================================================================");
    }

    fclose(f);

    printf("\n\t\t\t\t\t\tPress any key to continue...");
    getch();
    menu();
}

void modifyrecord()
{
	system("cls");
	printf("\t\t\t\t\t\t  |-----------------------------------------|\n");
    printf("\t\t\t\t\t\t  |*************** INFO VAULT **************|\n");
    printf("\t\t\t\t\t\t  |-----------------------------------------|\n");
    FILE *f;
    int flag = 0;
    struct person p, s;
    char name[50];

    f = fopen("project", "rb+");
    if (f == NULL)
    {
        printf("\t\t\t\t CONTACT'S DATA NOT ADDED YET.");
        sleep(2);
        menu();
    }
    else
    {
        
        printf("\n\t\t\t\t\t\t Enter CONTACT'S NAME TO MODIFY:");
        scanf(" %[^\n]", &name);

        while (fread(&p, sizeof(p), 1, f) == 1)
        {
            if (strcmp(name, p.name) == 0)
            {
                printf("\n\t\t\t\t\t\t Enter new name: ");
                scanf(" %[^\n\t\t\t\t\t\t]", &s.name);
                printf("\t\t\t\t\t\t Enter complete Department name(Upper case): ");
                scanf(" %[^\n]", &s.department);
                printf("\t\t\t\t\t\t Enter new address: ");
                scanf(" %[^\n]", &s.address);
                printf("\t\t\t\t\t\t Enter new official email: ");
                scanf("%s", &s.email);
                printf("\t\t\t\t\t\t Enter new phone no.: ");
                scanf("%llu", &s.mble_no);

                // Preserve the original time
                s.year = p.year;
                s.month = p.month;
                s.day = p.day;
                s.hour = p.hour;
                s.minute = p.minute;
                s.second = p.second;
                fseek(f, -sizeof(p), SEEK_CUR);
                fwrite(&s, sizeof(s), 1, f);
                flag = 1;
                break;
            }
        }
        fflush(stdin);

        if (flag == 1)
        {
            printf("\n\t\t\t\t\t\t Your record is modified.");
        }
        else
        {
            printf("\n\t\t\t\t\t\t Data not found.");
        }

        fclose(f);
    }

    printf("\n\t\t\t\t\t\t Press any key to continue...");
    getch();
    system("cls");
    menu();
}

void printAddressStatistics()
{
    FILE *f;
    struct person p;
    char department[50];

    f = fopen("project", "rb");

    if (f == NULL)
    {
        printf("\t\t\t\t\t\t  DATAs NOT ADDED YET.");
        sleep(2);
        menu();
    }

    system("cls");
	printf("\t\t\t\t\t\t  |-----------------------------------------|\n");
    printf("\t\t\t\t\t\t  |*************** INFO VAULT **************|\n");
    printf("\t\t\t\t\t\t  |-----------------------------------------|\n");
    
    printf("\n\t\t\t\t\t\tEnter Department name to view statistics(Use Upper case): ");
    scanf(" %[^\n]", department);

    int count = 0;

    while (fread(&p, sizeof(p), 1, f) == 1)
    {
        if (strcmp(department, p.department) == 0)
        {
            count++;
        }
    }

    fclose(f);

    printf("\n\t\t\t\t\t\t Department Statistics for %s:", department);
    printf("\n\t\t\t\t\t\t Number of Records: %d\n", count);

    // Display a basic bar chart using ASCII characters
    printf("\n\t\t\t\t\t\t Department Distribution:\n");

    for (int i = 0; i < count; i++)
    {
        printf("||  ");
    }
    printf("\n");

    printf("\n\t\t\t\t\t\t Press any key to continue...");
    getch();
    system("cls");
    menu();
}

void recent(){
	system("cls");
	printf("\t\t\t\t\t\t  |-----------------------------------------|\n");
    printf("\t\t\t\t\t\t  |*************** INFO VAULT **************|\n");
    printf("\t\t\t\t\t\t  |-----------------------------------------|\n");
	
	 struct person p;
    FILE *f;
    f = fopen("project", "rb");

    if (f == NULL) {
        printf("\n\t\t\t\t\t\t No recent datas found");
        sleep();
        menu();
    }

    time_t currentTime;
    time(&currentTime);

    while (fread(&p, sizeof(p), 1, f) == 1) {
        // Calculate the difference in seconds between the current time and the saved time
        time_t recordTime = mktime(&(struct tm){p.second, p.minute, p.hour, p.day, p.month - 1, p.year - 1900});
        double differenceInSeconds = difftime(currentTime, recordTime);

        // Display records from the last 10 days (864000 seconds)
        if (differenceInSeconds <= 864000) {
            printf("\n\n\n YOUR RECORD:\n");
            printf("Name=%s\nAddress=%s\nDepartment=%s\nE-mail=%s\nMobile no=%llu\n", p.name, p.address, p.department, p.email, p.mble_no);
            printf("Data saved time: %04d-%02d-%02d %02d:%02d:%02d\n", p.year, p.month, p.day, p.hour, p.minute, p.second);
            printf("===================================================================================================================");
        }
    }

    fclose(f);

    printf("\n\t\t\t\t\t\t Press any key to continue...");
    getch();
    system("cls");
    menu();
}
void exportToTxt() {
    struct person p;
    FILE *f, *txtFile;
    f = fopen("project", "rb");

    if (f == NULL) {
        printf("\n\t\t\t\t\t\t File opening error for export.");
        exit(1);
    }

    txtFile = fopen("exported_data.txt", "w");

    if (txtFile == NULL) {
        printf("\n\t\t\t\t\t\t Error creating text file.");
        fclose(f);
        exit(1);
    }

    fprintf(txtFile, "Name   |   Address   |   Department   |   Email   |   Mobile No   |   Date   |   Time\n");
    fprintf(txtFile,"________________________________________________________________________________________");

    while (fread(&p, sizeof(p), 1, f) == 1) {
        fprintf(txtFile, "\n%s | %s | %s | %s | %llu | %d/%d/%d | %d:%d:%d\n", p.name, p.address, p.department,
                p.email, p.mble_no, p.year, p.month, p.day, p.hour, p.minute, p.second);
                 fprintf(txtFile,"________________________________________________________________________________________");
                
    }

    fclose(f);
    fclose(txtFile);

    printf("\n\t\t\t\t\t\t Data exported to exported_data.txt successfully.");

    // Press any key to continue...
    printf("\n\t\t\t\t\t\t Press any key to continue...");
    getch();
    system("cls");
    menu();
}

void factoryReset() {
    char d[50];
    system("cls");
    printf("\n\t\t\t\t\t\t Enter your pet name: ");
    scanf("%s", &d);

    if (strcmp(d, "babu") == 0) {
        if (remove("project") == 0) {
            printf("\n\t\t\t\t\t\t Factory reset successful. All data has been deleted.");
        } else {
            printf("\n\t\t\t\t\t\t Error during factory reset. Unable to delete data file.");
        }

        // Press any key to continue...
        printf("\n\t\t\t\t\t\t Press any key to continue...");
        getch();
        system("cls");
        menu();
    } else {
        printf("\n\t\t\t\t\t\t You are not authorized");
        getch();
        menu();
    }
}

void got(char *name)
{

   int i=0,j;
    char c,ch;
    do
    {
        c=getch();
                if(c!=8&&c!=13)
                {
                    *(name+i)=c;
                        putch(c);
                        i++;
                }
                if(c==8)
                {
                    if(i>0)
                    {
                        i--;
                    }
                   // printf("h");
                    system("cls");
                    for(j=0;j<i;j++)
                    {
                        ch=*(name+j);
                        putch(ch);

                    }

                }
    }while(c!=13);
      *(name+i)='\0';
}
