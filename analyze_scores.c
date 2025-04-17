#include <stdio.h>
#include <stdlib.h> 
#include "analysis_functions.h"
#define TEAM_SIZE 11

/***************************************************
 * disclaimer: not needed for main but im not sure
* int argc, char* argv[]
* brings in the user input and brings in other functions from other classes to be put for printing
* Parameters: void
* Returns:
* none: but it prints and gets functions as needed, also loop through the methods as needed
* Sources: none
************************************************/
int main(int argc, char* argv[]) {

    // Check arguments
    if (argc < 3) {
        puts("Run the program with a list of input file, followed by the output file\n\n./runScores file_name.txt ... results.txt\n\nwhere file_name.txt ... is a list of files to process\nand results.txt is the name of the output file to produce.");
        return -1;
    }
     int num_years = argc - 2;
     int wins[num_years][TEAM_SIZE];
     int scores[num_years][TEAM_SIZE];
        for (int i = 0; i < num_years; i++) {
        for (int j = 0; j < TEAM_SIZE; j++) {
            wins[i][j] = 0;
            scores[i][j] = 0;
        }
        
    }  
    for (int i = 0; i < argc - 2; i++) {
        load_data(wins, scores, argv[i + 1]);
        
    }
    for (int i = 0; i < argc - 2; i++) {
        printTeam(wins, scores, i);
    }
write_data(wins, scores, num_years, argv[argc-1]);
    return 0;
}