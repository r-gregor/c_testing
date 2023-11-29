#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <curl/curl.h>

const int PROG_BAR_LENGTH = 30;

typedef struct {
	long total_bytes;
	
} statusinfo;


/* update_bar function */
void update_bar(int percent_done) {
	int num_chars = percent_done * PROG_BAR_LENGTH / 100;
	printf("\r[");
	for (int i=0; i < num_chars; i++) {
		printf("#");
	}
	
	for (int i=0; i < (PROG_BAR_LENGTH - num_chars); i++) {
		printf(" ");
	}

	printf("] %d%% Done", percent_done);
	fflush(stdout);
}


size_t got_data(char *buffer, size_t itemsize, size_t numitems, void *stinfo) {
	statusinfo* status = stinfo;
	size_t bytes = itemsize * numitems;
	status->total_bytes += bytes;

	return bytes;
}


bool download_url(char *url, statusinfo *sinfo) {
	CURL *curl = curl_easy_init();

	if(!curl) return false;

	// set options
	curl_easy_setopt(curl, CURLOPT_URL, url);
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, got_data);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, sinfo);
	curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1);

	// do the download
	CURLcode result = curl_easy_perform(curl);

	curl_easy_cleanup(curl);
	return (result == CURLE_OK);
}


/** main */
int main() {

	char *urls[] = {
		"http://ipv4.download.thinkbroadband.com/100MB.zip",
		"http://ipv4.download.thinkbroadband.com/20MB.zip",
		"http://ipv4.download.thinkbroadband.com/50MB.zip",
		"http://ipv4.download.thinkbroadband.com/1GB.zip",
		"http://ipv4.download.thinkbroadband.com/200MB.zip",
		"http://ipv4.download.thinkbroadband.com/512MB.zip"
		"http://ipv4.download.thinkbroadband.com/1GB.zip",
		"http://ipv4.download.thinkbroadband.com/1GB.zip"
	};
	const int num_urls = (sizeof(urls) / sizeof(urls[0]));

	statusinfo sinfo;
	sinfo.total_bytes = 0;

	update_bar(0);
	for (int i=0; i < num_urls; i++) {
		download_url(urls[i], &sinfo);
		update_bar((i+1)*100 / num_urls);
	}
	printf("\n");

	return 0;
}
