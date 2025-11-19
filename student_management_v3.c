#include "functions.h"

int main(){

    // asking for data

    printf("Enter the number of students you want to add data for\n");
    int num;
    scanf("%d",&num);

    // create the required structure 

    struct student_data data[num];

    // storing data

    printf("Enter student data for all students in the specified manner\n");
    printf("Name, Roll Number and Marks\n");
    for(int i = 0; i < num; i++)
        scanf("%s %d %f",data[i].name,&data[i].roll_number,&data[i].marks);

    // checking duplicates

    int duplicate[256] = {0};
    for(int i = 0; i < num; i++){
        for(int j = i+ 1; j < num;j++){
            if(data[i].roll_number == data[j].roll_number) 
                duplicate[j] = 1;
        }
    }

    // sorting the data on basis of roll number

    for(int i = 0; i < num; i++){
        for(int j = 0; j < num - i - 1 ; j++){
            if(data[j].roll_number > data[j + 1].roll_number){
                struct student_data temp;
                temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }

        }
    }

    // making file and storing data without duplicates in file

    FILE *p;
    p = fopen("Data.txt","w");
    if(p == NULL) printf("Error occured during file opening");
    else{
        fprintf(p,"%-15s %-10s %-5s\n", "Name", "Roll_No", "Marks");
        int i = 0;
        while(i != num){
            if(duplicate[i] == 0)
                fprintf(p,"%-15s %-10d %-5.2f\n", data[i].name, data[i].roll_number, data[i].marks);
            i++;
        }
    }
    fclose(p);

    // making file permanent

    p = fopen("Data.txt","a+");
    

    // implemention features

    while(1){ 

    // implementing menu

    menu();

    // implementing choice

    int choice;
    scanf("%d",&choice);
    switch(choice){
        case 1:
        view_data(p);
        break;

        case 2:
        find_student(p);
        break;

        case 3:
        num = delete_student(p,num);     
        p = fopen("Data.txt","a+");      
        break;

        case 4:
        num = add_student(p,num);        
        p = fopen("Data.txt","a+");      
        break;

        case 5:
        update_data(p,num);              
        p = fopen("Data.txt","a+");      
        break;

        case 6:
        printf("Exiting Program...\n");
        return 0;
        
        default:
        printf("Wrong number entered");
        break;
        }
    }
    return 0;
}
