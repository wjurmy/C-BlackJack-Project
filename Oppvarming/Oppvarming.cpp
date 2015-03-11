#include <iostream>
#include <string>
#include <cstdlib>
#include <stdlib.h>
using namespace std;

int main() {
    // Oppgave 1a
    long long msg1
    {
        28539401679696455
    };
    char* ptr;
    ptr = (char*) &msg1;
    cout << "First msg:" << endl;
    cout << ptr << endl << endl;

    // Oppgave 1b
   int msg2[]{1918986818, 1998611822, 1684829551, 544483182, 1701538156, 1768453152, 8563};
    char *ptr2;
    ptr2 = (char*) &msg2;
    cout << "Secound msg:" << endl;
    cout << ptr2 << endl << endl;

    // Oppgave 1c
    int encrypted[]{1498105673, 1227249735, 1498829639, 1196119078, 1314530904, 1197024843, 5853000};

    // Først regner ut lengden av arrayen, hvor mange entries
    int Length_Of_Message = (int) sizeof (encrypted);

    // Define new decrypted msg array
    char *decrypted = (char*) malloc((Length_Of_Message + 1) * sizeof (char));

    // Define letters we will use
    char Letters[]{'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
        'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    // Define a char pointer to point to encrypted msg
    char *ptr3;
    ptr3 = (char*) &encrypted;

    // Use some dummie variables
    int j;
    char Letter;
    bool space;

    // Print encrypted msg
    cout << "Third msg comes here." << endl << endl;
    cout << "Encrypted msg: " << endl << ptr3 << endl << endl;

    // Vi prøver ulike offset for å se om noen av de gir et budskap som gir mening
    for (int offset = 20; offset < 21; offset++)//(int) sizeof (Letters) / sizeof (char); offset++) 
      {
        for (int i = 0; i < Length_Of_Message; i++) {
            space = false;

            // Find letter
            Letter = ptr3[i];

            // Check if our current byte represent a letter in our defined Letters array
            j = 0;
            while (Letter != Letters[j]) {
                j++;
                if (j >= ((int) sizeof (Letters) / sizeof (char))) {
                    // We assume a non-alphabetic sign = space
                    space = true;
                    break; // Break loop to avoid infininite loop
                }
            }

            if ((j + offset) >= ((int) sizeof (Letters) / sizeof (char))) {
                // Ensure we start at the beginning of letters array if offset takes us outside
                j -= ((int) sizeof (Letters) / sizeof (char));
            }

            if (space == false)
                decrypted[i] = Letters[j + offset];
            else
                decrypted[i] = ' ';
        }

        // Add an ending to the char array
        decrypted[Length_Of_Message] = '\0';

        // Print msg
        cout << "Decrypted msg: " << endl << decrypted << " " << endl << "We used offset: " << offset << endl << endl;
    }

    free(decrypted);
    cout << endl;
    cout << endl;
    cout << "Thank you for using Walids decryption machine." << endl;
}
