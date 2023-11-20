//Written with <3 by tala!

/*
/*
 * Filename: honeygain_conversion.c
 * Author: Talha Nizamani
 * Copyright: © 2023 Talha Nizamani
 * License: Apache License, Version 2.0
 *
 * Created: November 20, 2023
 * Purpose: Conversion tool for Honeygain points calculation.
*/

 

#ifdef _WIN32
#include <stdio.h>
#include <stdlib.h>
#endif

#ifdef linux
#include <stdio.h>
#include <stdlib.h>
#endif

// Constants
#define RATE 0.3
#define MEGABYTE_TO_GIGABYTE 1000
#define CONVERSION_FACTOR 3.3386
#define VERBOSE_OPTION "-v"

//Displaying Options/Choices for conversion
void menu();

//compatible cli options, makes it work in Windows and Linux
void clearscreen();
void pause();

//Conversions
float honey(float megabytes, float rate);
float dollar(float points);

//Methods for conversion
void megabyte();
void gigabyte();
void _points();

//Global Variables
int debug = 0;
float var = 0;
float points = 0;
int OS = 0;


int main(int argc, char *argv[]) {
    if (argc > 1 && strcmp(argv[1], VERBOSE_OPTION) == 0) { //Makes it so it accepts Parameters! :)
        debug = 1;
        printf("Verbose mode enabled!\n");
    }
        #ifdef _WIN32
        if(debug) {
        	printf("YOUR OS IS WINDOWS!\n");
        	pause();
			}
        OS = 0;
        #endif
        #ifdef linux
        if(debug) {        
        	printf("YOUR OS IS UNIX!\n");
        	pause();
			}
        OS = 1;
        #endif
		
		int choice = 0;

        while(1) {
		clearscreen();
        menu();
        scanf("%d", &choice);
		switch(choice)
		
		{
		case 1:
			clearscreen();
			megabyte();
            break;
        case 2:
        	clearscreen();
            gigabyte();
            break;
        case 3:
        	var = 0;
			points = 0;
            clearscreen();
            _points();
            break;
        case 4:
            if(OS == 0) //Windows
            	system("ipconfig | grep \"IPv4 Address\"");
        	if(OS == 1) //Unix T-T ik its unnecessary but idc.
            	system("ifconfig | grep \"IPv4 Address\"");
            break;
        default:
        	choice = 0;
			scanf("%d", &choice);
            printf("\n Invalid choice !!!");
    }
    printf("\n\n");
    pause();
    points = 0;
}

}
void megabyte() {
    float var = 0;

    printf("Enter Amount in Megabytes: ");

    while (1) {
        if (scanf("%f", &var) == 1) {
            points = honey(var, RATE);
            printf("\nYour points are %.2f", points);
            printf("\nEstimated in Dollars: $%.2f\n", dollar(points));
            break;
        } else {
            printf("Invalid input. Please enter a valid number.\n");
            scanf("%*s");
            printf("Enter Amount in Megabytes: ");
        }
    }
}

void gigabyte() {
    points = 0;
    float var = 0;

    printf("note: This will provide inaccurate estimate, please use points for accurate conversion!\n");
    
    while (1) {
        printf("\nEnter Amount in Gigabytes: ");
        if (scanf("%f", &var) == 1) {
            points = honey(var * MEGABYTE_TO_GIGABYTE, RATE);
            printf("\nYour points are %.2f", points);
            printf("\nEstimated in Dollars: $%.2f\n", dollar(points));
            break;
        } else {
            printf("Invalid input. Please enter a valid number.\n");
            scanf("%*s");
        }
    }
}


void _points() {
	float res = 0;
	
    while (1) {
        printf("Enter Amount in Points: ");
        if (scanf("%f", &var) == 1) {
            res = var * CONVERSION_FACTOR;
            printf("You've provided %.2f Megabytes to honeygain.\n", res);
            printf("Estimated in Dollars: $%.2f\n", dollar(var));
            break;
        } else {
            // Invalid input, clear the input buffer
            printf("Invalid input. Please enter a valid number.\n");
            scanf("%*s"); 
        }
    }
}

float honey(float megabytes, float rate) {
        return megabytes * rate;
}

float dollar(float points) {
        return points / MEGABYTE_TO_GIGABYTE;
}

void clearscreen() {
	if(OS == 0) { //For Windows
		system("cls");
	}
	if(OS == 1) { //For UNIX
		system("clear");
	}
}

void pause() {
	if(OS == 0) { //For Windows
		system("pause");
	}
	if(OS == 1) { //For UNIX
		system("sleep 1");
	}
}


void menu() {
        printf("===================\n");
        printf("1. Use Megabytes");
        printf("\n2. Use Gigabytes");
        printf("\n3. Use Points - \n");
        printf("===================\n\n");
        printf("Choice: ");

}

/*
 * End of honeygain_conversion.c
 */

