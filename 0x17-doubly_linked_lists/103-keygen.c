#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
unsigned int index, result;
size_t length, sum;
char *characters = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";
char key[7] = "      ";

if (argc != 2)
{
printf("Correct usage: ./keygen5 username\n");
return (1);
}

length = strlen(argv[1]);
key[0] = characters[(length ^ 59) & 63];

for (index = 0, sum = 0; index < length; index++)
sum += argv[1][index];
key[1] = characters[(sum ^ 79) & 63];

for (index = 0, result = 1; index < length; index++)
result *= argv[1][index];
key[2] = characters[(result ^ 85) & 63];

for (result = argv[1][0], index = 0; index < length; index++)
{
if ((char)result <= argv[1][index])
result = argv[1][index];
}

srand(result ^ 14);
key[3] = characters[rand() & 63];

for (result = 0, index = 0; index < length; index++)
result += argv[1][index] * argv[1][index];
key[4] = characters[(result ^ 239) & 63];

for (result = 0, index = 0; (char)index < argv[1][0]; index++)
result = rand();
key[5] = characters[(result ^ 229) & 63];

printf("%s\n", key);
return (0);
}
