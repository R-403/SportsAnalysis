//bridge between the two sales functions and analyze files
//packages here
/***************************************************
* analysis_functions.h
* is where the bridge is made to bridge btween analysis_functions.c and analyze_scores.c
* Returns:
* none cause its just calling the functions together and methods
* Sources: none
************************************************/
//bridge between the two sales functions and analyze files
//packages here
#ifndef ANALYSIS_FUNCTIONS_H
#define ANALYSIS_FUNCTIONS_H
#include <stdio.h>
#include <stdlib.h> 
#define TEAM_SIZE 11

//functions here
    void printTeam(int wins[][TEAM_SIZE], int scores[][TEAM_SIZE], int year);

    void load_data(int wins[][TEAM_SIZE], int scores[][TEAM_SIZE], char* filename);

    void write_data(int wins[][TEAM_SIZE], int scores[][TEAM_SIZE], int yearsc, char* filename);


#endif