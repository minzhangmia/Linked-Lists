/**
 * @fn	    void parse_command_line(const int argc, char *const *argv, CLOptions *opts) 
 * @brief	parse command line
 * @author	ZM
 * @date	2020/12/07
 * @returns	input correct parameter: original data and after filtering
 * 			input incorrect parameter: "Usage : ./assignment5 [-i inputfilename] [-n min ] [-x max ] [-h ]\n"
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "parse.h"
void parse_command_line(const int argc, char *const *argv, CLOptions *opts) // argc: number of demand | argv[]:pointers array (save demands) | opts: pointers of CLOption structure
{
    opts->infilename="data.txt"; //input value of filename in this path
   	opts->max_size=5;//10000;//input value of minimum size in this path
   	opts->min_size=2;//0;//input value of maxmum size in this path
	int i,j;  //i: the order of char string | j: the order of cahr string's character
	char inputfilename;
	for(i = 1;i < argc;i++)
	{
		if(argv[i][0]=='-')//check weather is '-' or not
		{
			switch(argv[i][1])//chech the first character behind of '-'
			{
				case 'h'://check weather is 'h' after '-'
					printf("Usage : ./assignment5 [-i inputfilename] [-n min ] [-x max ] [-h ]\n");
					break;
				case 'i'://check weather is 'i' after '-'
					opts->infilename=argv[++i]; // input filename
					break;
				case 'n'://check weather is 'n' after '-'
				    i++;
					j=0;
					while(argv[i][j]!='\0'&&isdigit(argv[i][j])) //check weather is the end of command line or not&&check weather argv(minimum) is digit or not
						j++;
					if(argv[i][j]!='\0')//if an incorrect parameter will print usage
					{
						printf("Usage : ./assignment5 [-i inputfilename] [-n min ] [-x max ] [-h ]\n"); 
						return;
					}
					opts->min_size=atoi(argv[i]);
					break;
				case 'x'://check weather is 'x' after '-'
					i++;
					j=0;
					while(argv[i][j]!='\0'&&isdigit(argv[i][j]))//check weather is the end of command line or not&&check weather argv(minimum) is digit or not
						j++;
					if(argv[i][j]!='\0')//if an incorrect parameter will print usage
					{
						printf("Usage : ./assignment5 [-i inputfilename] [-n min ] [-x max ] [-h ]\n");
						return;
					}
					opts->max_size=atoi(argv[i]);
					break;
				default:
					printf("Usage : ./assignment5 [-i inputfilename] [-n min ] [-x max ] [-h ]\n");
					return;
			}
		}
		else // if an incorrect parameter will print usage
		{
			printf("Usage : ./assignment5 [-i inputfilename] [-n min ] [-x max ] [-h ]\n");
			return;
		}
	}
}
