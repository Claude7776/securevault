#include <stdio.h>
#include <string.h>
void detect_attack(const char *input)
{
    if (strlen(input) < 6)
        printf("[!] Mot de passe faible détecté\n");
}
