#include <stdio.h>

void display_all_grades(int arr[][7], char grades[][20]);
void display_grade( int arr[][6]);
void check_student(int id, int pass);
void student_sum(int counter);
void grade(int per, int counter);

int id, pass, not_valid = 1,per,stu,counter=0;
char grades[20][20];
int arr[20][7];
int ids[20];
int main()
{
    printf("inter n of student");
    scanf("%d",&stu);
    for(int i=1;i<=stu;i++){
          printf("student number:%d\n",i);
    while (not_valid) {
        printf("Please enter your id: ");
        scanf("%d", &id);
         ids[i]=id;
        counter++;
        printf("Please enter your password: ");
        scanf("%d", &pass);
        check_student(id, pass);
        
    }
  
    printf("Access granted for student %d!\n", id);
        student_sum(counter);
        grade(per,counter);
       not_valid=1;
    }

     printf("choose option:(1/all)-(2/specific)\n");
        int n;
        scanf("%d",&n);
        if(n==1){
            display_all_grades( arr, grades );
        }
        else if(n==2)
        {
            display_grade( arr);
        }
}


//modified check_student() :)
void check_student(int id, int pass) {
    int flag=1;
    
    for(int i=counter-1;i>=1;i--)
    {
        if(i==0) //cause the first id will be always flag=0 this handle it
        {
            break;
        }
        else if(arr[id][7] !=arr[i][7])
        {
            continue;
        }
        else
        {
        flag=0;
        break;
        }
   
    }
    if (id % 10 == 5 && pass == id &&flag) {
        not_valid = 0;
    } else {
        printf("Invalid id or password. Try again.\n");
    }
}

void student_sum(int counter)
{
     printf("enter your grades in 6 subjects:\n");
     int sum = 0;
        
        for (int i = 1; i <=6; i++) {
                int g, not_greater = 0; 
                do {
                    printf("Subject %d: ", i );
                    scanf("%d", &g);
                    if (g > 100) {
                        printf("Invalid grade grade must be between 0 and 100.\n");
                        not_greater = 1;
                    } else {
                        arr[counter][i]=g;
                        not_greater = 0; 
                    }
                } while (not_greater); 
                sum += g;
               
            }
         per = (sum / 6);
          arr[counter][7]=per;
       
}

void grade(int per, int counter) {
    if (per >= 85 && per <= 100)
        strcpy(grades[counter], "excellent");
    else if (per >= 75 && per < 85)
        strcpy(grades[counter], "v.good");
    else if (per >= 65 && per < 75)
        strcpy(grades[counter], "good");
    else if (per >= 50 && per < 65)
        strcpy(grades[counter], "pass");
    else
        strcpy(grades[counter], "fail");
}

 display_all_grades(int arr[][7],char grades[][20] )
 {
    for(int i=1;i<=stu;i++)
    {
       
        printf("student: %d (his id: %d)",i,ids[i]);  //id مش راضي بيتطبع صح 
        for(int j=1;j<=7;j++)
        {
            
            printf(" %d",arr[i][j]);
             if(j==7){
                printf("%%");
            }
           
        }
        printf(" grade: %s",grades[i]);
        printf("\n");
    }
 }

void display_grade(int arr[][6]) {
    int idx, id_flag = 0, id;
    printf("Enter ID you want to search: ");
    scanf("%d", &id);
    printf("Enter index you want to search: ");
    scanf("%d", &idx);

    for (int i = 1; i <= stu; i++) {
        if (id == ids[i]) {
            id_flag = 1;
            if (idx >= 1 && idx <= 6) { // Check if the index is valid
                printf("The desired grade of student ID:%d for subject %d is: %d\n", id, idx, arr[i][idx+1]);
            } else {
                printf("Invalid index!\n");
            }
            break;
        }
    }
    if (!id_flag) {
        printf("ID not found!\n");
    }
}
