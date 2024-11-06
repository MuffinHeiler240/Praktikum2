/** Initialisiere /loesche str mit c. */
void clear(char c, char str []) {

}


int dez2int(char str []) {
    int i = 0;
    int result = 0;
    // Traverse each character in the string
    while (str[i] != '\0') {
        // Check if the character is a digit
        if (str[i] < '0' || str[i] > '9') {
            return -1;  // Return -1 for invalid characters
        }

        // Convert character to integer and update result
        result = result * 10 + (str[i] - '0'); // -0 for ASCII conversion ('0' = 48) so that '0' = 0, '1' = 1, etc.
        i++;
    }
    return result;
}
int okt2int(char str []) {
    int i = 0;
    int result = 0;
    // Traverse each character in the string
    while (str[i] != '\0') {
        // Check if the character is a digit
        if (str[i] < '0' || str[i] > '7') {
            return -1;  // Return -1 for invalid characters
        }

        // Convert character to integer and update result
        result = result * 8 + (str[i] - '0'); // Base 8 conversion
        i++;
    }
    return result;
}

int hex2int (char str []) {
    int i = 0;
    int result = 0;
    // Traverse each character in the string
    while (str[i] != '\0') {
        // Check if the character is a digit
        if (!((str[i] >= '0' && str[i] <= '9')||(str[i] >= 'A' && str[i] <= 'F')||(str[i] >= 'a' && str[i] <= 'f')||((str[i] == 'x'||str[i] == 'X')&& i ==1))) {
            return -1;  // Return -1 for invalid characters
        }

        // Convert character to integer and update result
        if(str[i] >= '0' && str[i] <= '9') {
            result = result * 16 + (str[i] - '0'); // Base 16 conversion
        }if(str[i] >= 'A' && str[i] <= 'F') {
            result = result * 16 + (str[i] - '7'); // Base 16 conversion
        }if(str[i] >= 'a' && str[i] <= 'f') {
            result = result * 16 + (str[i] - 'W'); // Base 16 conversion
        }
        i++;
    }
    return result;
}

/** Bilde aus der Zeichenkette str eine positive
* Ganzzahl und gebe diese zurueck oder −1
* im Fehlerfall einer ungueltigen Zeichenkette.*/
int str2int (char str []) {
    // Check for empty string
    if (str[0] == '\0') {
        return -1;
    }

    if (str[0]=='0') {
        if (str[1]=='x'||str[1]=='X') {
            return hex2int(str);
        }
        else {
            return okt2int(str);
        }
    }
    return dez2int(str);
}


/** Schreibt die Binaerdarstellung der
* Ganzzahl i in die Zeichenkette str . */
void int2Binaer(int i, char str []) {
    int index = 0;
    int j;

    // Handle the special case where i is 0
    if (i == 0) {
        str[index++] = '0';
        str[index] = '\0';  // Null-terminate the string
        return;
    }

    // Create the binary representation in reverse order
    while (i > 0) {
        str[index++] = (i % 2) + '0';  // Get the last bit and convert to char
        i /= 2;  // Shift right by dividing by 2
    }

    str[index] = '\0';  // Null-terminate the string

    // Reverse the string to get the correct order
    for (j=0; j < index / 2; j++) {
        char temp = str[j];
        str[j] = str[index - 1 - j];
        str[index - 1 - j] = temp;
    }
}