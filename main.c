C, file-handling, healthcare, blood-bank, CLI, offline-app, beginner, ATS-friendly, resume-project

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define FILENAME "habit_log.txt"

const char *habits[] = {
    "Reading",
    "Exercise",
    "Meditation",
    "Study",
    "Writing",
    "Wake up before 7AM"
};
const int total_habits = 6;

void log_today_habits() {
    FILE *fp = fopen(FILENAME, "a");
    if (!fp) {
        printf(" Error opening file for writing.\n");
        return;
    }

    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    int day = t->tm_wday;
    if (day == 0) day = 7; // make Sunday = 7

    fprintf(fp, "Day %d: ", day);

    printf("\nSelect completed habits for today (Day %d):\n", day);
    for (int i = 0; i < total_habits; i++) {
        char ch;
        printf("  Did you complete '%s'? (y/n): ", habits[i]);
        scanf(" %c", &ch);
        if (ch == 'y' || ch == 'Y') {
            fprintf(fp, "%s, ", habits[i]);
        }
    }

    fprintf(fp, "\n");
    fclose(fp);
    printf(" Habits logged successfully!\n");
}

void view_weekly_report() {
    FILE *fp = fopen(FILENAME, "r");
    if (!fp) {
        printf(" No log file found.\n");
        return;
    }

    char line[256];
    printf(" Weekly Habit Log:\n");
    while (fgets(line, sizeof(line), fp)) {
        printf("%s", line);
    }
    fclose(fp);
}

int main() {
    int choice;
    while (1) {
        printf(" Habit Tracker - Weekly Logger\n");
        printf("1. Log today's habits\n");
        printf("2. View weekly report\n");
        printf("0. Exit\n");
        printf("Enter your choice:\n ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: log_today_habits();
              break;
            case 2: view_weekly_report();
              break;
            case 0: printf(" Goodbye!\n");
              return 0;
            default: 
              printf(" Invalid choice. Try again.\n");
        }
    }
}
