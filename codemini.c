#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

int main() {

    srand(time(0));

    // declaring array that is data set
    const char* morseTable[] = {
        ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
        "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
        "..-", "...-", ".--", "-..-", "-.--", "--.."
    };

    char input[10];
    int score = 0;
    int rounds = 3;

    system("cls");

    // show intro
    printf("========================================\n");
    printf("   INITIALIZING NEURAL MORSE LINK...    \n");
    printf("========================================\n");
    Sleep(800);
    printf("Searching for satellites...\n");
    Sleep(500);
    printf("CONNECTION ESTABLISHED.\n\n");
    Sleep(1000);

    for (int i = 0; i < rounds; i++) {

        int tarid = rand() % 26;
        char tarlet = 'A' + tarid;

        printf("ROUND %d/%d\n", i + 1, rounds);
        printf("Transmission for letter: %c\n", tarlet);

        printf("SIGNAL INCOMING...\n");

        // to play the morse sound i.e., beep 
        for (int j = 0; morseTable[tarid][j] != '\0'; j++) {
            if (morseTable[tarid][j] == '.') {
                Beep(800, 200);
            } else {
                Beep(800, 550);
            }
            Sleep(100);
        }

        printf("Your intercept (code): ");

        time_t start = time(NULL);
        scanf("%s", input);
        time_t end = time(NULL);

        double duration = difftime(end, start);

        // to help track the time taken for the answer entered by user
        if (duration > 10.0) {
            printf("TIMEOUT! Satellites lost the signal. (%.fs)\n", duration);
        } 
        else if (strcmp(input, morseTable[tarid]) == 0) {
            printf("ACCESS GRANTED. Decryption successful!\n");
            score++;
        } 
        else {
            printf("ACCESS DENIED. The correct code was %s\n", morseTable[tarid]);
        }

        printf("----------------------------------------\n\n");
        Sleep(1000);
    }

    system("cls");

    // prints the result of the input taken by user
    printf("=== MISSION REPORT ===\n");
    printf("Final Score: %d/%d\n", score, rounds);

    if (score == rounds)
        printf("RANK: ELITE GHOST AGENT\n");
    else if (score >= rounds/2.0)
        printf("RANK: FIELD ANALYST\n");
    else
        printf("RANK: REJECTED - BACK TO ACADEMY\n");

    printf("\nPress any key to exit...");
    getch();

    return 0;
}