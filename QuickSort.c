#include <stdio.h>
#include <stdlib.h>

void degis(int liste[], int boyut) {
    int temp = 0;
    if (boyut == 2) {
        for (int i = 0; i < boyut - 1; i++) {
            for (int j = 0; j < boyut - i - 1; j++) {
                if (liste[j] > liste[j + 1]) {
                    temp = liste[j];
                    liste[j] = liste[j + 1];
                    liste[j + 1] = temp;
                }
            }
        }
    }
}

void listegoster(int liste[], int boyut) {
    for (int i = 0; i < boyut; i++) {
        printf("%d ", liste[i]);
    }
    printf("\n");
}

void listebol(int liste[], int liste2[], int liste3[], int boyut, int *sayac1, int *sayac2) {
    int ort = 0;
    *sayac1 = 0;
    *sayac2 = 0;
    if (boyut > 2) {
        for (int i = 0; i < boyut; i++) {
            ort += liste[i];
        }
        ort /= boyut;

        for (int i = 0; i < boyut; i++) {
            if (liste[i] < ort) {
                liste2[*sayac1] = liste[i];
                (*sayac1)++;
            } else {
                liste3[*sayac2] = liste[i];
                (*sayac2)++;
            }
        }
    }
}

void birlestir(int liste1[], int boyut1, int liste2[], int boyut2, int birlesmis[]) {
    for (int i = 0; i < boyut1; i++) {
        birlesmis[i] = liste1[i];
    }

    for (int i = 0; i < boyut2; i++) {
        birlesmis[boyut1 + i] = liste2[i];
    }
}

int main() {
    int listem[] = {22, 27, 34, 13, 25, 44, 76, 45, 61};
    int boyut = sizeof(listem) / sizeof(listem[0]);
    int boyutsakla = 0,boyutsakla1 = 0,boyutsakla2 = 0,boyutsakla3 = 0,boyutsakla4 = 0;

    printf("**LIST**\n");
    listegoster(listem, boyut);

    int alt_liste1[boyut], alt_liste2[boyut], alt_liste3[boyut], alt_liste4[boyut],alt_liste5[boyut],alt_liste6[boyut],alt_liste7[boyut],alt_liste8[boyut],alt_liste9[boyut],alt_liste10[boyut];
    int sayac1, sayac2;

    listebol(listem, alt_liste1, alt_liste2, boyut, &sayac1, &sayac2);

    printf("Alt Liste 1: ");
    listegoster(alt_liste1, sayac1);
    printf("Alt Liste 2: ");
    listegoster(alt_liste2, sayac2);
    boyutsakla = sayac2;

    boyut = sayac1; 
    listebol(alt_liste1, alt_liste3, alt_liste4, boyut, &sayac1, &sayac2);

    printf("Alt Liste 1.1: ");
    listegoster(alt_liste3, sayac1);
    printf("Alt Liste 1.2: ");
    listegoster(alt_liste4, sayac2);
    boyutsakla1 = sayac2;
    int altsay3 = sayac1;


    boyut = boyutsakla1;
    listebol(alt_liste4, alt_liste7, alt_liste8, boyut, &sayac1, &sayac2);

    printf("Alt Liste 1.2.1: ");
    listegoster(alt_liste7, sayac1);
    printf("Alt Liste 1.2.2: ");
    listegoster(alt_liste8, sayac2);
    int altsay7 = sayac1, altsay8 = sayac2;

    boyut = boyutsakla;
    listebol(alt_liste2, alt_liste9, alt_liste10, boyut, &sayac1, &sayac2);

    printf("Alt Liste 2.1: ");
    listegoster(alt_liste9, sayac1);
    printf("Alt Liste 2.2: ");
    listegoster(alt_liste10, sayac2);
    int altsay9 = sayac1, altsay10 = sayac2;

    degis(alt_liste3,2);
    degis(alt_liste7,2);
    degis(alt_liste9,2);
    degis(alt_liste10,2);

    int listebirles[] = {};
    birlestir(alt_liste3,altsay3,alt_liste7,altsay7,listebirles);
    birlestir(listebirles,altsay3+altsay7,alt_liste8,altsay8,listebirles);
    birlestir(listebirles,altsay3+altsay7+altsay8,alt_liste9,altsay9,listebirles);
    birlestir(listebirles,altsay3+altsay7+altsay8+altsay9,alt_liste10,altsay10,listebirles);
    printf("**YENI LIST**\n");
    listegoster(listebirles, altsay10+altsay3+altsay7+altsay8+altsay9);

    return 0;
}
