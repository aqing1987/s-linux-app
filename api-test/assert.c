// assert - abort the program if assertion is false
#include <stdio.h>

// to disable assert, put NDEBUG before include assert.h
//#define NDEBUG
#include <assert.h>


int main() {
	assert(1 == 1);
	assert(1 == 2);
	return 0;
}
