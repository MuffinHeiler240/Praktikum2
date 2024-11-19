#include "zahlen.h"

void clear(char c, char str []) {
    int i = 0;
    for (; i < DIGITS; i++) {
       str[i] = c;
   }

    str[DIGITS] = '\0';
}

/* Konvertierung der dezimalen Eingabe in einen ganzzahligen Wert (Integer) */
int dez2int(char str []) {
    int i = 0;
    int result = 0;
    while (str[i] != '\0') {
        if (str[i] < '0' || str[i] > '9') {
            return -1;
        }
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return result;
}

/* Konvertierung der oktalen Eingabe in einen ganzzahligen Wert (Integer) */
int okt2int(char str []) {
    int i = 0;
    int result = 0;
    while (str[i] != '\0') {
        if (str[i] < '0' || str[i] > '7') {
            return -1;
        }
        result = result * 8 + (str[i] - '0');
        i++;
    }
    return result;
}

/* Konvertierung der hexadezimalen Eingabe in einen ganzzahligen Wert (Integer) */
int hex2int (char str []) {
    int i = 0;
    int result = 0;
    while (str[i] != '\0') {
        if (!((str[i] >= '0' && str[i] <= '9')||(str[i] >= 'A' && str[i] <= 'F')||(str[i] >= 'a' && str[i] <= 'f')||((str[i] == 'x'||str[i] == 'X')&& i ==1))) {
            return -1;
        }

        if(str[i] >= '0' && str[i] <= '9') {
            result = result * 16 + (str[i] - '0');
        }if(str[i] >= 'A' && str[i] <= 'F') {
            result = result * 16 + (str[i] - '7');
        }if(str[i] >= 'a' && str[i] <= 'f') {
            result = result * 16 + (str[i] - 'W');
        }
        i++;
    }
    return result;
}

/* Konvertierung der Zeichenkette in einen Integer */
int str2int (char str []) {

    /* Überprüfen, ob die Zeichenkette nicht leer ist */
    if (str[0] == '\0') {
        return -1;
    }
    /* Bestimmen des Zahlensystems und Aufruf einer spezifischen Funktion */
    if (str[0]=='0') {
        if (str[1]=='x'||str[1]=='X') {
            return hex2int(str);
        }
        return okt2int(str);

    }
    return dez2int(str);
}

/* Umwandlung eines Integers in eine binäre Zeichenkette */
void int2Binaer(int i, char str []) {
    int j;

    clear('0',str);

    /* Der Fall, in dem die Dezimalzahl gleich 0 ist */
    if (i == 0) {
        return;
    }

    /* Divisionsalgorithmus mit der invertierten Speicherung */
    for (j = DIGITS-1; j >= 0; j--) {
        if(i > 0) {
            str[j] = (i % 2) + '0';
            i /= 2;
        } else {
            return;
        }
    }
}