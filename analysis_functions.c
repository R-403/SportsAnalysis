#include <stdio.h>
#include <stdlib.h> 
#include "analysis_functions.h"
#define TEAM_SIZE 11

/***************************************************
* void printTeam(int wins[][TEAM_SIZE], int scores[][TEAM_SIZE], int year)
* is where the overall profit is being calculated based on user input
* Parameters: int wins[][TEAM_SIZE], int scores[][TEAM_SIZE], int year
* Returns:
* it returns nothing but it prints the top team or if the teams were tied
* Sources: none
************************************************/

void printTeam(int wins[][TEAM_SIZE], int scores[][TEAM_SIZE], int year) {
    int team = 1; // initialize the variables
// make the for loops here and write whats needed and see that the wins are there.
// make print statements
    for (int j = 1; j < TEAM_SIZE; j++) {
        if (wins[year][j] > wins[year][team]) {
            team = j;
        }
    }

    for (int j = 1; j < TEAM_SIZE; j++) {
        if (wins[year][j] == wins[year][team] && j != team) {

            if (scores[year][j] > scores[year][team]) {    
                team = j;
                printf("The top team of %d was Team %d.\n", wins[year][0], team);
                return;
            }
            if (scores[year][j] < scores[year][team]) {    
                team = j;
                printf("The top team of %d was Team %d.\n", wins[year][0], team);
                return;
            }
            if (scores[year][j] == scores[year][team]) {
                printf("The top team of %d was tied between Team %d and Team %d.\n", wins[year][0], team, j);
                return;
            }   
            return;
        }
    }
    printf("The top team of %d was Team %d.\n", wins[year][0], team);
}

/***************************************************
* void load_data(int wins[][TEAM_SIZE], int scores[][TEAM_SIZE], char* filename)
* is where the overall profit is being calculated based on user input
* Parameters: int wins[][TEAM_SIZE], int scores[][TEAM_SIZE], char* filename
* Returns:
* it returns nothing but it loads the data and keeps a count of the wins and based on the points, who wins and adds that to a counter 
* Sources: none
************************************************/

void load_data(int wins[][TEAM_SIZE], int scores[][TEAM_SIZE], char* filename){
    //make the variables, initialize and put to zero
    FILE* file = fopen(filename, "r"); // take the file needed 
    int team = 0;
    int score = 0;
    int team2 = 0;
    int score2 = 0;
    int year = 0;

    int year_index = 0;
    //loop through the years.
    while (wins[year_index][0] != 0) {
        year_index++;
    }

    fscanf(file, "%*s %d", &year);
    wins[year_index][0] = year;
    scores[year_index][0] = year;
// make the loop here and keep the scores to make the win counter
    while ((fscanf(file, "%d %d %d %d", &team, &team2, &score, &score2)) == 4) {
        scores[year_index][team] += score;
        scores[year_index][team2] += score2;
        if (score > score2) {
            wins[year_index][team]++;
        }
        if (score < score2) {
            wins[year_index][team2]++;
        }
        if (score == score2) {
            wins[year_index][team2]++;
            wins[year_index][team]++;
        }

    }
}
/***************************************************
* void write_data(int wins[][TEAM_SIZE], int scores[][TEAM_SIZE], int yearsc, char* filename)
* is where the overall profit is being calculated based on user input
* Parameters: int wins[][TEAM_SIZE], int scores[][TEAM_SIZE], int yearsc, char* filename
* Returns:
* it returns nothing but parses through the file and prints each of the numbers, it takes a copy of it and ovverites whats needed, see the wins, see the rule
* Sources: none
************************************************/
void write_data(int wins[][TEAM_SIZE], int scores[][TEAM_SIZE], int yearsc, char* filename) {
    FILE* file = fopen(filename, "w"); //open the file to write it. "w"
// make the loop so the data can be printed and take the wins and write the file with new info.
    fprintf(file, "Team");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < yearsc; j++) {
            fprintf(file, " %d", wins[j][0]);
        }
    }
    fprintf(file, "\n");

    for (int j = 1; j < TEAM_SIZE; j++) {
        fprintf(file, "%4d", j);
        
        for (int i = 0; i < yearsc; i++) {
            fprintf(file, " %4d", wins[i][j]);
        }
        for (int i = 0; i < yearsc; i++) {
            fprintf(file, " %4d", scores[i][j]);
        }

        fprintf(file, "\n");
    }
    fclose(file);
}

