## Lab 1

### 1. Write a program to find the average expenditure of a company for each month of each year, each year and average over the range of years specified. Use arrays to construct a table, display the table of expenditure and find the sum and average.

```c++ 

#include <stdio.h>
// #include <conio.h>

int main(){

    int no_of_year=0,iy;
    printf("\nEnter the number of year: ");
    scanf("%d",&no_of_year);

    float sum[no_of_year],average[no_of_year];
    int table [no_of_year][12],initial_year;
    printf("\nEnter initial year : ");
    scanf("%d",&initial_year);
    iy=initial_year;
    sum[0]=0;
    printf("\nEnter the expenditure of different months\n");
    printf("----------------------------------------------------\n");
    for(int i=0;i<no_of_year;i++){
        for(int j=0;j<12;j++){
            printf("For year %d month %d : ",initial_year,j+1);
            scanf("%d",&table[i][j]);
            sum[i]+=table[i][j];
        }
        printf("\n");
        initial_year++;
    }

    // Storing Average:
    for(int i=0;i<no_of_year;i++){
        average[i]=(sum[i])/12;
    }
     initial_year=iy;
    printf("\nExpenditure table\n");
    printf("-----------------------------------------------------------\n");
    printf("\nYear\tJan\tfeb\tMar\tApril\tMay\tJune\tJul\tAug\tSep\tOct\tNov\tDec\n");
     for(int i=0;i<no_of_year;i++){
        printf("%d\t",initial_year);
        for(int j=0;j<12;j++){

            printf("%d\t",table[i][j]);
        }
        printf("\n");
         initial_year++;
    }

    float temp_sum;
    float temp_average;
    // calculating total sum
    for(int i=0;i<no_of_year;i++){
            temp_sum+=sum[i];
            temp_average+=average[i];
    }
    printf("\nTotal sum and average details:\n");
    printf("-----------------------------------------------------------\n");
    printf("Sum: %.3f",temp_sum);
    printf("\nAverage: %.3f",(temp_average/no_of_year));
    return 0;
}

```

### 2. Write a program to find the position of the character 'C' in the sentence "idea without execution is worthless" using pointer and string.
```c++


#include <stdio.h>
// #include <conio.h>
#include<string.h>

int main(){
    char c[]="idea without execution is worthless";
    int position;

    for(int i=0;i<strlen(c);i++){
        if(*(c+i)=='c' || *(c+i)=='C')
            position=i+1;
    }
    printf("The position of c in given string is:%d",position);

    return 0;
}

```

### 3. Store and retrieve the name of the students and obtained marks in c programming in 1st semester using structure.
```c++

#include <stdio.h>
// #include <conio.h>

struct student{
    char name[30];
    float marks;
};

int main(){
    int nstudent;

    printf("Enter the number of students:");
    scanf("%d",&nstudent);

    struct student s[nstudent];
    printf("\nPlease enter the details for students:\n");
    printf("-----------------------------------\n");

    int start=1;
    for(int i=0;i<nstudent;i++){
        printf("Name %d: ",start);
        scanf("%s",&s[i].name);
        printf("Marks %d: ",start);
        scanf("%f",&s[i].marks);
        printf("\n");
        start++;
    }


    //Displaying the data:
    printf("\nDetails of students:\n");
    printf("-----------------------------------\n");

       for(int i=0;i<nstudent;i++){
        printf("Name: %s",s[i].name);
        printf("\n");
        printf("Marks: %.3f",s[i].marks);
        printf("\n\n");
    }

    return 0;
}

```

### 4. Write a program to read name, rollno, address, and phone number of each student in your class using structure. Store the information in file so that you can recover the information later. While recovering the information from the file sort the information alphabetically according to the name
```c++
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
```


