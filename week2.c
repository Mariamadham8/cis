#include <stdio.h>

int main() {
    int n,not_valid=1;
    while(not_valid){
    printf("please enter your id: ");
    scanf("%d", &n);
    
    if (n % 10 == 5) {
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
        int per = (sum / 6);
        printf("the total percentage = %d%%\n", per);

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
        not_valid=0;
    }
    else {
        printf("Invalid ID\n");
        not_valid=1;
    }
    }
    



    return 0;
}
