#include <stdio.h>
#include <string.h>

// structure creation

struct student_data {
    char name[256];
    int roll_number;
    float marks;
};

// fuction creation

void view_data(FILE *p);
void find_student(FILE *p);
int delete_student(FILE *p,int num);
int add_student(FILE *p,int num);
void update_data(FILE *p,int num);
void menu();

// displaying all data

void view_data(FILE *p){
        rewind(p);
        char ch[256];
        int troll;
        float tmarks;

        fgets(ch, sizeof(ch), p);

        printf("%-15s %-10s %-10s\n", "Name", "Roll_No", "Marks");
        printf("------------------------------------------\n");

    while(fscanf(p,"%s %d %f",ch,&troll,&tmarks) == 3)
        printf("%-15s %-10d %-5.2f\n",ch,troll,tmarks);
}

// searching student on the bases of roll number

void find_student(FILE *p){

    printf("Enter the student's roll number you want to search\t");
    int s;
    scanf("%d",&s);

    char ch[256];
    int troll;
    float tmarks;
    fgets(ch, sizeof(ch), p);

    printf("%-15s %-10s %-10s\n", "Name", "Roll_No", "Marks");
    printf("------------------------------------------\n");

    while(fscanf(p,"%s %d %f",ch,&troll,&tmarks) == 3){
        if(troll == s) printf("%-15s %-10d %-5.2f\n",ch,troll,tmarks);
    }

}

// deteting student data 

int delete_student(FILE *p, int num){

    rewind(p);

    printf("Enter the roll number you want to remove\n");
    int del;
    scanf("%d",&del);

    FILE *r;
    r = fopen("Temp.txt","w");
    fprintf(r,"%-15s %-10s %-5s\n", "Name", "Roll_No", "Marks");

    char ch[356];
    int troll,i = 0;
    float tmarks;
    fgets(ch, sizeof(ch), p);

    int removed = 0;

    while(fscanf(p, "%s %d %f", ch, &troll, &tmarks) == 3) {
        if(troll != del){
            fprintf(r,"%-15s %-10d %-5.2f\n",ch,troll,tmarks);
        } else {
            removed = 1;
        }
    }

    fclose(r);

    remove("Data.txt");
    rename("Temp.txt","Data.txt");

    if(removed) return num - 1;
    else return num;
}

// adding new student data

int add_student(FILE *p, int num){
    
    printf("Enter data of student to be added\n");
    struct student_data temp;
    scanf("%s %d %f",temp.name,&temp.roll_number,&temp.marks);

    rewind(p);
    char ch[256];
    int troll,count = 0;
    float tmarks;
    while(fscanf(p,"%s %d %f",ch,&troll,&tmarks) == 3){
        if(temp.roll_number == troll) count = 1;
    }

    if(count == 1){
        printf("Duplicate Roll Number detected");
        return num;
    }
    else {
        fprintf(p,"%-15s %-10d %-5.2f\n",temp.name, temp.roll_number, temp.marks);
    }

    rewind(p);
    FILE *r;
    r = fopen("Temp.txt","w");

    struct student_data tem[num + 1];
    
    fgets(ch, sizeof(ch), p);
    int i = 0;
    while(fscanf(p,"%s %d %f",tem[i].name,&tem[i].roll_number,&tem[i].marks) == 3){
        i++;
    }

    int cnt = i;

    strcpy(tem[cnt].name,temp.name);
    tem[cnt].roll_number = temp.roll_number;
    tem[cnt].marks = temp.marks;

    for(int i = 0; i < cnt + 1; i++){
        for(int j = 0; j < (cnt + 1) - i - 1; j++){
            if(tem[j].roll_number > tem[j+ 1].roll_number){
               struct student_data x = tem[j];
               tem[j] = tem[j + 1];
               tem[j + 1] = x;
            }
        }
    }

    fprintf(r,"%-15s %-10s %-5s\n","Name","Roll Number","Marks");
    i = 0;
    while(i < cnt + 1){
        fprintf(r,"%-15s %-10d %-5.2f\n",tem[i].name,tem[i].roll_number,tem[i].marks);
        i++;
    }
    printf("New Data succesfully added");

    fclose(r);
    remove("Data.txt");
    rename("Temp.txt","Data.txt");

    return num + 1;
}

// updating previous student data

void update_data(FILE *p, int num){

    printf("Enter Roll Number of student you want to update data of\n");
    struct student_data temp;
    scanf("%d",&temp.roll_number);
    int te = temp.roll_number;

    char ch[256];
    int troll,count = 0;
    float tmarks;
    while(fscanf(p,"%s %d %f",ch,&troll,&tmarks) == 3){
        if(temp.roll_number == troll) count = 1;
    }

    if(count == 0) printf("No individul with given Roll Number detected\n");
    else{

    printf("Enter new Name and Marks of student\n");
    scanf("%s %f",temp.name,&temp.marks);

    rewind(p);
    FILE *r;
    r = fopen("Temp.txt","w");

    fgets(ch, sizeof(ch), p);
    fprintf(r,"%-15s %-10s %-5s\n","Name","Roll Number","Marks");
        while(fscanf(p,"%s %d %f",ch,&troll,&tmarks) == 3){
            if(troll != te) 
            fprintf(r,"%-15s %-10d %-5.2f\n",ch,troll,tmarks);
            else 
            fprintf(r,"%-15s %-10d %-5.2f\n",temp.name,temp.roll_number,temp.marks);
        }
    printf("Data Updated succesfully");
    fclose(r);
    remove("Data.txt");
    rename("Temp.txt","Data.txt");
    }
}

// creating menu 

void menu(){
    printf("\n===== STUDENT RECORD MANAGEMENT SYSTEM =====\n");
    printf("1. Display All Students\n");
    printf("2. Search Student by Roll Number\n");
    printf("3. Delete Student\n");
    printf("4. Add New Student\n");
    printf("5. Update Student\n");
    printf("6. Exit\n");
    printf("============================================\n");
    printf("Enter your choice:  ");
}
