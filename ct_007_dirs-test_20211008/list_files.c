#include <dirent.h>
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

const int MAX_CHARS = 256;
int MAX_CHARS1;

int main(void) {
	DIR *dir;
	struct dirent *entry;
	dir = opendir(".");

	if (dir == NULL) {
		printf("Failed to open directory.\n");
		return 1;
	}

	/* count files */
	int files_num = 0;
	while ((entry = readdir(dir)) != NULL) {
		if(entry->d_type != DT_DIR) {
			files_num++;
			int s_len = strlen(entry->d_name);  
			if (s_len >= MAX_CHARS1) {
				MAX_CHARS1 = s_len;
			}
		}
	}

	printf("Number of files: %d\n", files_num);
	printf("The longest file has [%d] chars!\n", MAX_CHARS1);
	
	// display files ...
	rewinddir(dir);
	while ((entry = readdir(dir)) != NULL) {
		if(entry->d_type != DT_DIR) {
			printf("%s\n", entry->d_name);
		}
	}
	
	printf("\n---------------------------------------\n");
	// put filnames in array
	rewinddir(dir);
	char farray[files_num][MAX_CHARS1 + 1];
	int j = 0;
	while ((entry = readdir(dir)) != NULL) {
		if(entry->d_type != DT_DIR) {
			strcpy(farray[j], entry->d_name);
			j++;
		} 
	}
	closedir(dir);

	
	int arr_len = sizeof(farray) / sizeof(farray[0]);
	printf("The num of elements in farray: %d\n", arr_len);

	for (int k = 0; k < arr_len; k++) {
		printf("farray[%d] = %s\n", k, farray[k]);
	}
	
	
	
	



	return 0;
}

