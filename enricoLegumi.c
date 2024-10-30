#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool chk_rettangolo(int a, int b, int c);

int main() {
    int a, b, c;
    printf("Inserisci il valore di a: ");
    scanf("%d", &a);
    printf("\n");
    printf("Inserisci il valore di b: ");
    scanf("%d", &b);
    printf("\n");
    printf("Inserisci il valore di c: ");
    scanf("%d", &c);
    printf("\n");
    if((a>0) && (b>0) && (c>0)) {
        if((a<(b+c)) && (b<(a+c)) && (c<(a+b))) {
            if((a>((b>c)?b-c:c-b)) && (b>((a>c)?a-c:c-a)) && (c>((a>b)?a-b:b-a))) {
                printf("Condizione verificate, controllo del tipo di triangolo\n");
                if(chk_rettangolo(a,b,c)) {
                    printf("Il triangolo è rettangolo\n");
                    return 0;
                }
                if((a!=b) && (a!=c) && (b!=c)) {
                    printf("Il triangolo è scaleno\n");
                    return 0;
                }
                if((a==b) && (a==c)) {
                    printf("Il triangolo è equilatero\n");
                    return 0;
                }
                if((a==b) || (b==c) || (a==c)) {
                    printf("Il triangolo è isoscele\n");
                    return 0;
                }
            }
            else {
                printf("Almeno un lato inserito è minore della differenza degli altri due, uscita dal programma\n");
            }
        }
        else {
            printf("Almeno un lato inserito è maggiore della somma degli altri due, uscita dal programma\n");    
        }
    }
    else {
        printf("Almeno un lato inserito è negativo, uscita dal programma\n");
    }
}

bool chk_rettangolo(int a, int b, int c) {
    if((a>b) && (a>c)) {
        if(a==sqrt((b*b)+(c*c))) {
            return true;
        }
    }
    else {
        if((b>a) && (b>c)) {
            if(b==sqrt((a*a)+(c*c))) {
                return true;
            }
        }
        else {
            if((c>a) && (c>b)) {
                if(c==sqrt((a*a)+(b*b))) {
                    return true;
                }
            }
        }
    }
    return false;
}