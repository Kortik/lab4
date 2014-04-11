all: keygen textgen coder
keygen: 
	gcc Keygen.c -o keygen
textgen: 
	gcc Textgen.c -o textgen
coder:
	gcc Coder.c -o coder
