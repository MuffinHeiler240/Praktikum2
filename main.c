/*
* main.c
*
* Created on: 21.10.2021
* Author: nwulff
*/
#include <stdio.h>
#include <stdlib.h>
#include "zahlen.h"
int main(int argc, char** argv) {
    /* Puffer fuer die Ausgabezeichenkette mit Platz fuer Nullterminator */
    char puffer[DIGITS+1];
    int zahl;
    /* Gibt es ueberhaupt ein Komandozeilen Argument? */
    if(argc<2) {
        printf ("%s Aufrufen mit einer Zahl zwischen 0 und %d\n",argv[0],  MAXZAHL);
        return EXIT_FAILURE;
    }
    printf ("Eingabezeichenkette: \"%s\" \n",argv[1]);

    /* Zeichenkette in eine int Zahl umrechnen */
    zahl = str2int(argv[1]) ;

    /* Ueberpruefung ob Zeichenkette gueltige Eingabe */
    if(zahl<0 || MAXZAHL<=zahl) {
        printf ("ungueltige Eingabe: %s \n",argv[1]);
        return EXIT_FAILURE;
    }
    /* Zahl in Binaerdarstellung in den Ausgabepuffer schreiben */
    int2Binaer(zahl, puffer );

    /* Zahl in unterschiedlichen Basen ausgeben */
    printf ("dezi: %d binaer:%s oktal:0%o hexa:0x%X \n",zahl,puffer,zahl,zahl);
    return EXIT_SUCCESS;
}
