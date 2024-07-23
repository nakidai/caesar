Caesar cipher
--
Usage is pretty simple: first argument is encode/decode (which affects the sign
of the key (direction of moves)), second argument is the string which is hashed
by summation characters and taking remainder of division by length of the
alphabet. You can set your own alphabet by setting CAESAR\_ALPHABET environment
variable. Pass text you want to encrypt/decrypt in stdin and result will be
shown in stdout.

Example
--
```
$ echo "helloworld" | python main.py encrypt 123abc
jgnnqyqtnf
```
