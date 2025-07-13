#include <stdio.h>

int getFirstDay(int year) {
    int day;
    day = (year * 365 + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400 + 1) % 7;
    return day;
}

int isLeapYear(int year) {
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

void printMonth(int year, int month, int *startDay) {
    char *months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    int daysInMonth[] = {
        31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
    };

    if (isLeapYear(year)) {
        daysInMonth[1] = 29; // February
    }

    printf("\n\n  ------------%s %d------------\n", months[month], year);
    printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

    for (int i = 0; i < *startDay; i++) {
        printf("     ");
    }

    for (int day = 1; day <= daysInMonth[month]; day++) {
        printf("%5d", day);
        if (++(*startDay) > 6) {
            printf("\n");
            *startDay = 0;
        }
    }

    if (*startDay != 0)
        printf("\n");
}

int main() {
    int year, startDay;

    printf("Enter year: ");
    scanf("%d", &year);

    startDay = getFirstDay(year);

    for (int month = 0; month < 12; month++) {
        printMonth(year, month, &startDay);
    }

    return 0;
}