#include <sys/sysinfo.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

int main() {
	int ret = 0;
	struct sysinfo info;
	ret = sysinfo(&info);
	if (ret < 0) {
		printf("sysinfo: %s\n", strerror(errno));
		return -1;
	}

	printf("uptime: %ld\n", info.uptime);
	printf("freeram: %ld\n", info.freeram);
	printf("procs: %d\n", info.procs);
	return 0;
}
