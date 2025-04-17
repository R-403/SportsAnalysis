runScores: analyze_scores.o analysis_functions.o
	gcc -g -Wall analyze_scores.o analysis_functions.o -lm -o runScores 

analyze_scores.o: analysis_functions.h analyze_scores.c
	gcc -g -Wall -c analyze_scores.c

analysis_functions.o: analysis_functions.h analysis_functions.c
	gcc -g -Wall -c analysis_functions.c

clean:
	rm -f analyze_scores.o analysis_functions.o runScores

all: runScores
