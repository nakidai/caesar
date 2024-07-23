CC ?= cc
RM ?= rm


ccaesar: main.c
	${CC} -std=c11 -o ccaesar $<

clean:
	${RM} ccaesar

.PHONY: clean
