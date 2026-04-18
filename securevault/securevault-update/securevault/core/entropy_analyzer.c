#include <math.h>
#include <string.h>

double calculate_entropy(const char *str)
{
    int freq[256] = {0};
    int len = strlen(str);

    for (int i = 0; i < len; i++)
        freq[(unsigned char)str[i]]++;

    double entropy = 0.0;

    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            double p = (double)freq[i] / len;
            entropy -= p * log2(p);
        }
    }

    return entropy;
}
