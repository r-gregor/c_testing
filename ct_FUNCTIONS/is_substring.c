/* from: https://github.com/portfoliocourses/c-example-code/blob/main/substr_substring.c
 *       Check If A String Is A Substring Of Another String | C Programming Example
 *       https://www.youtube.com/watch?v=tx37dJZTfMM
 */
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool is_substring(char *substr, char *string);



// returns true if 'substr' is a substring of strign, and false otherwise
bool is_substring(char *substr, char *string) {

	// get the length of both strings
	int slen = strlen(string);
	int clen = strlen(substr);

	// we can stop checking for 'substr' in string at the position it will no longer
	// possibly fit into the string
	int end = slen - clen + 1;

	// check each position in string for 'substr'
	for (int i = 0; i < end; i++) {
		// assume the 'substr' string is found at this position
		bool substr_found = true;
		
		// check each index of the 'substr' string to see if it matches with the 
		// corresponding character in string at index i onwards
		for (int j = 0; j < clen; j++) {
			// if we find a non-matching character, we know that 'substr' is not 
			// found here and we can stop checking now
			if (substr[j] != string[i + j]) {
				substr_found = false;
				break;
			}
		}
		
		// if we found no non-matching characters, we found that 'substr' IS a 
		// substring of string (at position i) and we can stop checking
		if (substr_found) return true;
	}

	// if at no position in string did we find 'substr' it is NOT a substring
	return false;
}

