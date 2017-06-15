/*  McUsr put this together, and into public domain, 
	without any guarrantees about anything,
	but the statement that it works for me.
*/

#if 1 == 1
#define TESTING
#endif

#include <sys/param.h>
#include <sys/sysctl.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct osver {
	int minor;
	int sub;
} ;
typedef struct osver osxver ;
void macosx_ver(char *darwinversion, osxver *osxversion ) ;
char *osversionString(void) ;

#ifdef TESTING
int main( int argc, char *argv[] )
{
	osxver foundver;
	char *osverstr= NULL ;
	osverstr=osversionString() ;
	macosx_ver(osverstr, &foundver ) ;
	printf("Mac os x version = 10.%d.%d\n",foundver.minor,foundver.sub );
	free(osverstr);
	return 0;
}
#endif
char *osversionString(void) {
	int mib[2];
	size_t len;
	char *kernelVersion=NULL;
	mib[0] = CTL_KERN;
	mib[1] = KERN_OSRELEASE;

	if (sysctl(mib, 2, NULL, &len, NULL, 0) < 0 ) {
		fprintf(stderr,"%s: Error during sysctl probe call!\n",__PRETTY_FUNCTION__ );
		fflush(stdout);
		exit(4) ;
	}

	kernelVersion = malloc(len );
	if (kernelVersion == NULL ) {
		fprintf(stderr,"%s: Error during malloc!\n",__PRETTY_FUNCTION__ );
		fflush(stdout);
		exit(4) ;
	}
	if (sysctl(mib, 2, kernelVersion, &len, NULL, 0) < 0 ) {
		fprintf(stderr,"%s: Error during sysctl get verstring call!\n",__PRETTY_FUNCTION__ );
		fflush(stdout);
		exit(4) ;
	}

	return kernelVersion ;
}

void macosx_ver(char *darwinversion, osxver *osxversion ) {
/*
	From the book Mac Os X and IOS Internals:
	In version 10.1.1, Darwin (the core OS) was renumbered from v1.4.1 to 5.1,
	and since then has followed the OS X numbers consistently by being four
	numbers ahead of the minor version, and aligning its own minor with the
	sub-version.
*/
	char firstelm[2]= {0,0},secElm[2]={0,0};

	if (strlen(darwinversion) < 5 ) {
		fprintf(stderr,"%s: %s Can't possibly be a version string. Exiting\n",__PRETTY_FUNCTION__,darwinversion);
		fflush(stdout);
		exit(2);
	}
	char *s=darwinversion,*t=firstelm,*curdot=strchr(darwinversion,'.' );

	while ( s != curdot )
		*t++ = *s++;
	t=secElm ;
	curdot=strchr(++s,'.' );
	while ( s != curdot )
		*t++ = *s++;
	int maj=0, min=0;
	maj= (int)strtol(firstelm, (char **)NULL, 10);
	if ( maj == 0 && errno == EINVAL ) {
		fprintf(stderr,"%s Error during conversion of version string\n",__PRETTY_FUNCTION__);
		fflush(stdout);
		exit(4);
	}

	min=(int)strtol(secElm, (char **)NULL, 10);

	if ( min  == 0 && errno == EINVAL ) {
		fprintf(stderr,"%s: Error during conversion of version string\n",__PRETTY_FUNCTION__);
		fflush(stdout);
		exit(4);
	}
	osxversion->minor=maj-4;
	osxversion->sub=min;
}