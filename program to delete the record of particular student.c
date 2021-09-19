#include<stdio.h>
#include<conio.h>
int main()
{
    FILE *fp1, *fp2;
    typedef struct student
    {
        int roll_no;
        char name[20];
        int marks;
    }STUDENT;

    STUDENT stud;
    int found = 0, rno;
    system("cls");
    fp1 = fopen("student_details5.txt","r");
    if(fp1 == NULL)
    {
        printf("\n File opening error");
        return 0;
    }
    fp2 = fopen("student_details_temp.txt","w");
    if(fp2 == NULL)
    {
        printf("\n File opening error");
        return 0;
    }
    printf("\n Enter the roll number of the student whose record to be deleted");
    scanf("%d",&rno);
    while(1)
    {
        fscanf(fp1,"%d",&stud.roll_no);
        if(stud.roll_no == -1)
            break;
        if(stud.roll_no == rno)
        {
            found = 1;
            fscanf(fp1,"%s %d",stud.name,&stud.marks);
        }
        else
        {
            fscanf(fp1,"%s %d",stud.name, &stud.marks);
            fprintf(fp2,"%d %s %d",stud.roll_no, stud.name, stud.marks);
        }
    }
    fprintf(fp2," %d",-1);
    fclose(fp1);
    fclose(fp2);
    if(found == 0)
    {
        printf("\n The record with roll number %d was not found in the file",rno);
    }
    else
    {
        fp1 = fopen("student_details5.txt","w");
        if(fp1 == NULL)
        {
            printf("\n File opening error");
            return 0;
        }
        fp2 = fopen("student_details_temp.txt","r");
        if(fp2 == NULL)
        {
            printf("\n File opening error");
            return 0;
        }

        while(1)
        {
            fscanf(fp2,"%d",&stud.roll_no);
            if(stud.roll_no == -1)
            break;
            fscanf(fp2, "%s %d",stud.name, &stud.marks);
            fprintf(fp1,"%d %s %d",stud.roll_no,stud.name, stud.marks);
        }
    }
    fprintf(fp1,"%d",-1);
    fclose(fp1);
    fclose(fp2);
    printf("\n Record Deleted");
    return 0;
    getch();
}
