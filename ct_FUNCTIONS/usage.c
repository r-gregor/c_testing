/* ===============================================================
 *
 * 1-st
 *
 */

void usage(char *arg) {
	printf("Usage: %s [ n ] --> n - number of columns\n", arg);
	printf("                        optional (default = 3)\n\n");
	exit(1);
}

/* inside main */
/* int main(int argc, char **argv) { */

	if (argc > 2) {
		usage(argv[0]);
	}
/* ... */
/* } */
/* inside main */

/* ===============================================================
 *
 * 2-nd
 *
 */

void usage(char *arg);

/* inside main */
/* int main(int argc, char **argv) { */

	if (argc != 2) {
		usage(argv[0]);
	}
	
/* ... */
/* } */
/* inside main */


void usage(char *arg) {
	printf("\n\tUsage:\t%s <temperature>\n", arg);
	exit(1);
}


