#ifndef _CRTC_H
#define _CRTC_H

#include <stdio.h>

void crtc(int n) {
	while(n != 0) {
		printf("-");
		n--;
	}
	printf("\n");
}

#endif

