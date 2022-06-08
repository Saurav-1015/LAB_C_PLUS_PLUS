/*
Write a program to read name, rollno, address, and
phone number of each student in your class using structure.
Store the information in file so that you can recover the information later.
While recovering the information from the file sort the information alphabetically according to the name
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    char name[50];
    int roll_no;
    char address[50];
};

int main()
{
    int no_of_student=0;
    int start=1;
    
    FILE *ptr;

    printf("\nEnter the number of student: ");
    scanf("%d",&no_of_student);
    
    struct student s[no_of_student];

    printf("\n\nPlease enter the data of student(s)\n");
    printf("------------------------------------------\n");

    for (int i=0;i<no_of_student;i++){
        
        printf("\nStudent NO: %d",start);

        printf("\nName: ");
        fflush(stdin);
        scanf("%s",s[i].name);

        printf("Roll NO: ");
        fflush(stdin);
        scanf("%d",&s[i].roll_no);

        printf("Address: ");
        fflush(stdin);
        scanf("%s",s[i].address);

        start++;
        
    }

    ptr=fopen("lab4_file.txt","wb+");

    if(ptr==NULL)
    {
        printf("No file found!!");
        exit(1);
    }

    // Writing in file lab4_file.txt
    fwrite(&s,sizeof(struct student),no_of_student,ptr);
    rewind(ptr);


    struct student s_read[no_of_student];
    struct student temp;
    fread(&s_read,sizeof(struct student),no_of_student,ptr);

    for( int i=0; i<no_of_student;i++){
        for (int j = i+1; j < no_of_student; j++)
        {
            if(strcmp(s_read[i].name,s_read[j].name)>0)
            {
                temp=s_read[i];
                s_read[i]=s_read[j];
                s_read[j]=temp;

            }

        }
        
    }

    //Displaying table in ascending order corresponding to name of each structure
    printf("\n\nDisplaying the data from file:\n");
    printf("------------------------------------------\n");
    for(int i=0;i<no_of_student;i++){

        printf("\nName: %s\nRoll NO: %d\nAddress: %s\n",s_read[i].name,s_read[i].roll_no,s_read[i].address);
        printf("\n");
    }
    


    return 0;
}