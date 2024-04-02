#include<stdio.h>

int id, pass, not_valid = 1,per;

void check_student(int id, int pass);
void student_sum();
void  grade( int per);
int main() {
    while (not_valid) {
        printf("Please enter your id: ");
        scanf("%d", &id);
        printf("Please enter your password: ");
        scanf("%d", &pass);
        check_student(id, pass);
    }
    printf("Access granted!\n");
    student_sum();
    grade(per);
    return 0;
}

void check_student(int id, int pass) {
    if (id % 10 == 5 && pass == id) {
        not_valid = 0;
    } else {
        printf("Invalid id or password. Try again.\n");
    }
}

void student_sum()
{
     printf("enter your grades in 6 subjects:\n");
     int sum = 0;
        
        for (int i = 0; i < 6; i++) {
                int g, not_greater = 0; 
                do {
                    printf("Subject %d: ", i + 1);
                    scanf("%d", &g);
                    if (g > 100) {
                        printf("Invalid grade grade must be between 0 and 100.\n");
                        not_greater = 1;
                    } else {
                        not_greater = 0; 
                    }
                } while (not_greater); 
                sum += g;
            }
         per = (sum / 6);
        printf("the total percentage = %d%%\n", per);
}

void grade(int per)
{
  if (per >= 85 && per <= 100)
            printf("Grade: EXCELLENT\n");
        else if (per >= 75 && per < 85)
            printf("Grade: VERY GOOD\n");
        else if (per >= 65 && per < 75)
            printf("Grade: GOOD\n");
        else if (per >= 50 && per < 65)
            printf("Grade: PASS\n");
        else
            printf("Grade: FAIL\n");
        
        printf("No matter the grade you get, what really matters is that you will try till your last breath.\n");
}
