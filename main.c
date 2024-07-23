#include <stdlib.h>
#include <stdio.h>
#include <stdnoreturn.h>
#include <string.h>


#define DEFAULT_ALPHABET "abcdefghijklmnopqrstuvwxyz"


noreturn void usage(char *name)
{
    fprintf(stderr, "usage: %s <decode/encode> <key>\nset CAESAR_ALPHABET if you want to use your own alphabet\n", name);
    exit(1);
}

int main(int argc, char **argv)
{
    if (argc != 3) usage(argv[0]);

    char *alphabet = getenv("CAESAR_ALPHABET");
    if (alphabet == NULL) alphabet = DEFAULT_ALPHABET;

    int key = 0;
    for (char *cp = argv[2]; *cp != '\0'; ++cp) key += *cp;
    key %= strlen(alphabet);
    if (!strcmp(argv[1], "decode"))
        key = -key;
    else if (strcmp(argv[1], "encode"))
        usage(argv[0]);

    char *source;
    scanf("%ms", &source);
    if (source == NULL)
    {
        perror("scanf: ");
        exit(1);
    }

    for (char *cp = source; *cp != '\0'; ++cp)
        putchar(*cp + key);
    putchar('\n');
}
