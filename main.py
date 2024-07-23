from os import getenv
from string import ascii_lowercase
from sys import argv, stderr


ALPHABET = getenv("CAESAR_ALPHABET", default=ascii_lowercase)

if len(argv) != 3 or argv[1] not in ["encode", "decode"]:
    print(f"usage: {argv[0]} <decode/encode> <key>\nset CAESAR_ALPHABET if you want to use your own alphabet", file=stderr)
    exit(1)

key = sum(map(ord, argv[2])) % len(ALPHABET)
print(''.join(map(lambda x: ALPHABET[(ALPHABET.find(x) + key) % len(ALPHABET)], input())))
