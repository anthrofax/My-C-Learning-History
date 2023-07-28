#include <stdio.h>

int i, u, T, npm[13];

int main()
{
    printf("Masukan NPM Anda \n");
    u = 1;
    T = 0;
    for (i = 0; i <= 12; i++)
    {
        printf("NPM digit ke-%i = ", u);
        scanf("%i", &npm[i]);
        T = T + npm[i] - 1;
        u++;
    }
    printf("ab=%i", T);
}