#include <stdio.h>

void pointcounter(int countedpoints, int totalpoints, int td2, int td1, int td, int fg, int sfty, int previous);

void main() {
    int totalpoints =2;
    while(totalpoints>1){
    	printf("Points: ");
    	scanf("%d", &totalpoints);

    	pointcounter(0, totalpoints, 0, 0, 0, 0, 0, 8);
    }
}

void pointcounter(int countedpoints, int totalpoints, int td2, int td1, int td, int fg, int sfty, int previous) {
    if (totalpoints - countedpoints == 0) {
        printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", td2, td1, td, fg, sfty);
    }
    if (previous >= 8 && totalpoints - countedpoints >= 8) {
        pointcounter(countedpoints + 8, totalpoints, td2 + 1, td1, td, fg, sfty,8);
    }
    if (previous >= 7 && totalpoints - countedpoints >= 7) {
        pointcounter(countedpoints + 7, totalpoints, td2, td1 + 1, td, fg, sfty,7);
    }
    if (previous >= 6 && totalpoints - countedpoints >= 6) {
        pointcounter(countedpoints + 6, totalpoints, td2, td1, td + 1, fg, sfty,6);
    }
    if (previous >= 3 && totalpoints - countedpoints >= 3) {
        pointcounter(countedpoints + 3, totalpoints, td2, td1, td, fg + 1, sfty,3);
    }
    if (previous >= 2 && totalpoints - countedpoints >= 2) {
        pointcounter(countedpoints + 2, totalpoints, td2, td1, td, fg, sfty + 1,2);
    }
}