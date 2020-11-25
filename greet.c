#include <stdio.h>
#include <string.h>

// gcc greet.c -o greet -fno-stack-protector -z execstack -no-pie


void greet(){
        char name[100]="";
        printf("Name locate at: %p\n", name);
	fflush(stdout);
        scanf("%s", name);
        printf("Hello, %s\n", name);
}

void main(){
        printf("Who are you?\n");
        greet();
        printf("Bye :D");
}

