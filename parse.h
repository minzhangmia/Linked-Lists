/**
 * \file parse.h
 * \brief Header file containing the definition for a structure to hold
 * 	command line arguments. It also contains the function prototype
 * 	for a function to parse the command line args and populate this
 * 	structure. Needed for Assignment 5 in 5613
 * \author R. Morrin
 * \version 2.0
 * \date 2020-11-24
 */
#ifndef PARSE_H_6UALVSS5
#define PARSE_H_6UALVSS5

/*! \struct 
 *  \brief Structure to hold command line options
 */
typedef struct {
    char *infilename;  	/*!< -i option. input data file */
    int max_size; 	/*!< -x option. Holds minimum size you want to filter */
    int min_size; 	/*!< -n option. Holds maximum size you want to filter */
}CLOptions;

/* Function to parse the command line and populate the above structure 	*/
void parse_command_line(const int argc, char * const *argv, CLOptions *opts);

#endif /* end of include guard: PARSE_H_6UALVSS5 */
