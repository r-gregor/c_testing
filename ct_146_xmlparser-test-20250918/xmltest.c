/*
 * filename: xmltest.c
 * 20250918 en
 * on cygwin compile with:
 *    gcc -Wall -o xmltest xmltest.c -I/usr/include/libxml2/ -lxml2
 * last: 20250918 en
 */
#include <stdio.h>
#include <string.h>
#include <libxml/parser.h>
#include <libxml/tree.h>

int main(int argc, char **argv) {

#if 0
	char *docname = "TestConfigInNamespace.xml";
	char *root_node = "MYTEST";
#else
	char *docname = "books.xml";
	char *root_node = "catalog";
#endif

	xmlDocPtr doc;
	xmlNodePtr cur;
	doc = xmlParseFile(docname);
	if (doc == NULL ) {
		fprintf(stderr,"Document not parsed successfully. \n");
		xmlFreeDoc(doc);
		return -1; 
	}
	cur = xmlDocGetRootElement(doc);
	if (cur == NULL) {
		fprintf(stderr,"empty document\n");
		xmlFreeDoc(doc);
		return -1;
	}
	if (xmlStrcmp(cur->name, (const xmlChar *) root_node)) {
		fprintf(stderr,"document of the wrong type, root node != %s \n", root_node);
		xmlFreeDoc(doc);
		return -1;
	}

	printf("Document '%s' sucessfully parsed ...\n", docname);

	return 0;
}

