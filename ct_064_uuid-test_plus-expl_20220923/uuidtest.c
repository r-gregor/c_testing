/*
 * from: Generating Unique Identifiers in Your Programs (GUIDs/UUIDs)
 * https://www.youtube.com/watch?v=hGBHGficAiM&t=13s
 * (https://www.youtube.com/c/JacobSorber)
 *
 * AS TUTORIAL (explanation in comments at the bottom)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <uuid/uuid.h>     // NOT working on WINDOWS10 from cmd!

#define NUM_LINES 8
#define UUIDTEXTSIZE (sizeof(uuid_t)*2) + 5 // 4 hypens and '\0' character at the end of a string

/*
 * function to print raw uuid hex num pairs
 */
void printrawuuid(uuid_t id) {
	printf("RAW: ");
	for (int i=0; i < sizeof(uuid_t); i++) {
		printf("%x ", id[i] );
	}
	printf("\n");
}

int main() {

	uuid_t myuuid, myuuid2, namespace_uuid;

	// random based uuid-s -------------------------------------------------------
	uuid_generate(myuuid);

	for (int j=0; j < NUM_LINES; j++) {
		uuid_generate(myuuid);
		printf("(Line %02d) ", j+1);
		printrawuuid(myuuid);
	}

	printf("---\n");

	char uuidtext[UUIDTEXTSIZE];
	uuid_unparse(myuuid, uuidtext);

	for (int j=0; j < NUM_LINES; j++) {
		uuid_generate(myuuid);

		/* uuid_unparse - convert a UUID from binary representation to a string */
		uuid_unparse(myuuid, uuidtext);
		printf("(Line %02d) ", j+1);
		printf("UUID: %s\n", uuidtext);
	}

	// time based uuid-s ---------------------------------------------------------
	// check if uuid_generate_time makes different uuid-s when run sequentially
	// for two uuid-s
	printf("---\n");
	uuid_generate_time(myuuid);
	uuid_generate_time(myuuid2);

	printrawuuid(myuuid);
	printrawuuid(myuuid2);


	// name based uuid-s x---------------------------------------------------------
	//
	// $> uuidgen
	//    40f9cdee-9ad0-4a86-8f36-b5f4d42e5401
	// $> uuidgen --name="Jacob" -s --namespace="40f9cdee-9ad0-4a86-8f36-b5f4d42e5401"
	//    ba9922a0-4f69-541c-a5d7-12dd4b3dd930
	// $> uuidgen --name="Jacob" -s --namespace="40f9cdee-9ad0-4a86-8f36-b5f4d42e5401"
	//    ba9922a0-4f69-541c-a5d7-12dd4b3dd930
	//
	// OR
	//
	// $> uuidgen --name="Jacob" -s --namespace="$(uuidgen)"
	//    7b7232ea-81d8-5777-98d3-18dc9b7974cf
	// $> uuidgen --name="Jacob" -s --namespace="$(uuidgen)"
	//    0927f913-9351-5617-aace-c0f6e8ad47ce
	// $> uuidgen --name="Jacob" -s --namespace="$(uuidgen)"
	//    c04cd5c9-c756-5339-a10d-26e45d205447

	uuid_generate(myuuid);
	uuid_unparse(myuuid, uuidtext);
	printf("UUID: %s\n", uuidtext);

	// uuid_parse - convert an input UUID string into binary representation
	uuid_parse("40f9cdee-9ad0-4a86-8f36-b5f4d42e5401", namespace_uuid);
	uuid_generate_sha1(myuuid, namespace_uuid, "Jacob", strlen("Jacob"));
	uuid_unparse(myuuid, uuidtext);
	printf("SHA1 UUID: %s\n", uuidtext);
	
	// ALL COMMANDS RUN IN CONSOLE:
	// $> uuidgen --name="Jacob" -s --namespace="40f9cdee-9ad0-4a86-8f36-b5f4d42e5401"
	//    ba9922a0-4f69-541c-a5d7-12dd4b3dd930             // same!
	//
	// $> bin/uuidtest.exe
	//    ...
	//    SHA1 UUID: ba9922a0-4f69-541c-a5d7-12dd4b3dd930  // same!
	// ---
	// $> uuidgen --name="Jacob" -s --namespace="40f9cdee-9ad0-4a86-8f36-b5f4d42e5401"
	// ba9922a0-4f69-541c-a5d7-12dd4b3dd930 [**]
	// ======== ==== ==== ==== ============
	// 
	// $> echo "40f9cdee-9ad0-4a86-8f36-b5f4d42e5401"
	// 40f9cdee-9ad0-4a86-8f36-b5f4d42e5401
	// 
	// $> echo -e -n "\x40\xf9\xcd\xee\x9a\xd0\x4a\x86\x8f\x36\xb5\xf4\xd4\x2e\x54\x01Jacob" > test.txt
	//
	// $> sha1sum test.txt
	// ba9922a04f69241c65d712dd4b3dd93001cc059d4 *test.txt
	// ba9922a04f69541ca5d712dd4b3dd930 [**]
	// ============x===x===============xxxxxxxx
	// 
	// With hypens added:
	// ba9922a0-4f69-241c-65d7-12dd4b3dd930 01cc059d4 *test.txt
	// ba9922a0-4f69-541c-a5d7-12dd4b3dd930 [**]
	//               x    x                 xxxxxxxx
	// ==> uuid created from sha1 hash with change in version info (first x), and sme additional info (second x) and
	// ==> with last section chopped of (trailing x-es) to fit into uuid number length

    return 0;
}

