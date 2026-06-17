/**
 * function that returns the positin of the delimiter in a string
 */
unsigned int getPositionOfDelim(char *line, char delim) {
	unsigned int pos;
	unsigned int j = 0;
	while (!line[j] == '\0') {
		if (line[j] == delim) {
			pos = j;
			break;
		} else {
			j++;
		}
	}
	return pos;
}

/*
 * get the position (offset) of delimiter ';'
 * ACTUAL use:
 * return int to check if delimiter found --> NOT found --> -1
 * you can choose an action if count == 0 / strlen(line) (1st or last char in line)
 */
int get_delim_position(char *line, char delim, uint32_t line_len) {
	uint32_t count = 0;
	for (int i = 0; i < line_len; i++) {
		if (line[i] == delim) {
			return count;
		} else {
			count++;
		}
	}

	/* delimiter NOT found */
	if (count >= line_len) {
		return -1;
	}
	return -1;
}

