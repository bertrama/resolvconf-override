// gcc -Wall -g -shared -fPIC -ldl -o libtest.so test.c

#include <resolv.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <assert.h>

#define __USE_GNU
#include <dlfcn.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* For debugging */
#if 0
static void
print_ns (void)
{
	int i;
	for(i=0;i<_res.nscount;i++) {
		char buf[INET_ADDRSTRLEN];

		inet_ntop(AF_INET, &_res.nsaddr_list[i].sin_addr, buf, sizeof(buf));
		fprintf(stderr, "dnssrvr: %s\n", buf);
	}
}
#endif

struct hostent *gethostbyname(const char *name)
{
	struct hostent * (*f)() = dlsym (RTLD_NEXT, "gethostbyname");
	struct hostent *ret =  f("localhost");

	return ret;
}

int getaddrinfo(const char *node, const char *service,
		const struct addrinfo *hints,
		struct addrinfo **res)
{
	int (*f)() = dlsym (RTLD_NEXT, "getaddrinfo");
	return f("localhost", service, hints, res);
}
