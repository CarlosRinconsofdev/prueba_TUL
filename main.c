#include <stdio.h>

#define MAX 100000

char string [MAX] = {0}; //string a manipular
__uint32_t n = 0; // Longitud del string
__uint32_t k = 0; // Intentos
//__uint16_t pm = 0; // Parejas a modificar

struct parejasM {
    __uint16_t PM;
    char posicionesM [50000];
}; 

struct parejasM p;
char str[MAX];

struct parejasM parejas_modificar(char str[]){
    struct parejasM p;
    __uint32_t j = n / 2;
    for(__uint32_t i = 0; i < j; i++){
        if (str[i] != str[n-i-1]){
            p.PM++;
            p.posicionesM[p.PM-1] = i;
        }
    }
    return p;
}

char* highestValuePalindrome (char str[], struct parejasM pm){
    char* s;
    if (k <= pm.PM){
        s = "-1";
    }
    else if(k == pm.PM){
        for(__uint16_t i = 0; i <= pm.PM; i++){
            if (str[pm.posicionesM[i]] > str[pm.posicionesM[n-i-1]]){
                str[pm.posicionesM[n-i-1]] = str[pm.posicionesM[i]];
            }
            else {
                str[pm.posicionesM[i]] = str[pm.posicionesM[n-i-1]];
            }
            
        }
        s = &str;
    }
    return s;
}

int main() {
    // printf() displays the string inside quotation
    printf("Ingrese el valor de k y n separados por espacio\n");
    scanf("%i %i", &n, &k);
    printf("Ingrese s\n");
    scanf("%s", &string);
    //fgets(string, MAX, stdin);
    printf("Usted acaba de ingresar:\n");
    printf("n = %i k = %i\n", n, k);
    printf("s = '%s'\n", string);
    //printf("s = '%c'\n", string[9]);
    p = parejas_modificar(string);
    printf("Parejas a modificar = %d\n", p.PM);
    char* s = highestValuePalindrome(string, p);
    strcpy(string, s);
    printf("Programa finalizado con: %s\n", string);
    return 0;
}
