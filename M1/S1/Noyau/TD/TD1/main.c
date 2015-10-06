#include <stdio.h>
#include <setjmp.h>
#include <unistd.h>

jmp_buf buff, bufg;

void f() {
	int n = 0;
	
	while (1) {
		printf("Execute f: %d\n", n++);
		sleep(1);
		if (setjmp(buff) == 0) {
			longjmp(bufg, 1);
		}
	}
}

void g() {
	int m = 1000;
	
	while (1) {
		printf("Execute g: %d\n", m++);
		sleep(1);
		if (setjmp(bufg) == 0) {
			longjmp(buff, 1);
		}
	}
}

void main() {
	if (setjmp(bufg) == 0) {
		f();
	}
	else {
		g();
	}
}
