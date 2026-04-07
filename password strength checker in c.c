#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char password[100];
    int i;
    int hasUpper = 0, hasLower = 0, hasDigit = 0, hasSpecial = 0;

    printf("Enter your password: ");
    scanf("%s", password);

    int length = strlen(password);

    // Check length
    if (length < 8) {
        printf("Weak Password: Must be at least 8 characters long.\n");
        return 0;
    }

    // Check each character
    for (i = 0; i < length; i++) {
        if (isupper(password[i]))
            hasUpper = 1;
        else if (islower(password[i]))
            hasLower = 1;
        else if (isdigit(password[i]))
            hasDigit = 1;
        else
            hasSpecial = 1;
    }

    // Evaluate strength
    if (hasUpper && hasLower && hasDigit && hasSpecial) {
        printf("Strong Password 💪\n");
    } else {
        printf("Weak Password ⚠️\n");

        if (!hasUpper)
            printf("- Add at least one uppercase letter\n");
        if (!hasLower)
            printf("- Add at least one lowercase letter\n");
        if (!hasDigit)
            printf("- Add at least one digit\n");
        if (!hasSpecial)
            printf("- Add at least one special character\n");
    }

    return 0;
}
