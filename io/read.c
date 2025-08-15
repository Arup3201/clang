#include<stdio.h>
#include<string.h>

int main(int argc, char** argv) {
	if(argc < 2) {
		fprintf(stderr, "format: %s file.txt\n", argv[0]);
		return 1;
	}

	char filename[100];
	strcpy(filename, argv[1]);

	FILE* fp = fopen(filename, "r");
	if(fp == NULL) {
		fprintf(stderr, "[error] failed to read %s\n", filename);
		return 1;
	}

	char ch;
	while((ch=getc(fp)) != EOF) {
		fprintf(stdout, "%c", ch);
	}
	fprintf(stdout, "-- END\n");

	return 0;
}
