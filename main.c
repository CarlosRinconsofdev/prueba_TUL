#include <stdio.h>
#include <string.h>

#define MAX 100000

char string [MAX]; //string a manipular
__uint32_t n = 0; // Longitud del string
__uint32_t k = 0; // Intentos
struct parejasM p;
char s[MAX] = {'8'};

struct parejasM {
    __uint16_t PM;
    __uint16_t posicionesM [50000];
}; 



struct parejasM parejas_modificar(char str[]){
    struct parejasM p;
    p.PM = 0;
    __uint32_t j = n / 2;
    for(__uint32_t i = 0; i < j; i++){
        if (str[i] != str[n-i-1]){
            p.PM++;
            p.posicionesM[p.PM-1] = i;
        }
    }
    return p;
}

char* highestValuePalindrome (char str[MAX], struct parejasM pm){

    if (k < pm.PM){
        strcpy(s, "-1");
    }
    else if(k == pm.PM){
        for(__uint16_t i = 0; i <= pm.PM; i++){
            if (str[pm.posicionesM[i]] > str[n - pm.posicionesM[i] - 1]){
                str[n - pm.posicionesM[i] - 1] = str[pm.posicionesM[i]];
            }
            else {
                str[pm.posicionesM[i]] = str[(n - pm.posicionesM[i] - 1)];
            }
            
        }
        strcpy(s, str);
    }
    else {
        // No me alcanzo el tiempo para implementar esta funcion.
    }
    return s;
}

int main() {

    printf("Ingrese el valor de n y k separados por espacio\n");
    scanf("%i %i", &n, &k);
    printf("Ingrese s\n");
    scanf("%s", &string);
    printf("Usted acaba de ingresar:\n");
    printf("n = %i k = %i\n", n, k);
    printf("s = '%s'\n", string);
    p = parejas_modificar(string);
    printf("Parejas a modificar = %d\n", p.PM);
    highestValuePalindrome(string, p);
    //printf("La primera pareja a cambiar esta en la posicion: %d\n", (p.posicionesM[0]));
    printf("Programa finalizado con: %s\n", s);

    return 0;

}
