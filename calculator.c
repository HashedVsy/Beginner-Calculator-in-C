#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#ifdef _WIN32
#include <windows.h>
#endif


typedef struct {
    char *enter_first;
    char *enter_operator;
    char *enter_second;
    char *invalid_input;
    char *div_zero;
    char *invalid_operator;
    char *result_msg;
    char *continue_msg;
    char *goodbye;
} Messages;

int main() {
    #ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8); // Output UTF-8
    SetConsoleCP(CP_UTF8);       // Input UTF-8
    #endif

    bool running = true;
    char lang[3];

    // Language selection
    printf("Choose your language:\n");
    printf("en = English\nus = American English\nde = German\ncn = Chinese\ntr = Turkish\nfr = French\n");
    printf("Enter code: ");
    scanf("%2s", lang); while(getchar() != '\n'); // clear input buffer

    // Define messages for each language
    Messages msgs;

    if (strcmp(lang, "de") == 0) {
        msgs = (Messages){"Geben Sie die erste Zahl ein: ",
                          "Geben Sie den Operator ein (+, -, *, /): ",
                          "Geben Sie die zweite Zahl ein: ",
                          "Ungültige Eingabe!\n",
                          "Die zweite Zahl darf nicht 0 sein!\n",
                          "Geben Sie einen gültigen Operator ein!\n",
                          "Das Ergebnis ist %.2f\n",
                          "Möchten Sie eine weitere Berechnung durchführen? (y/n): ",
                          "Auf Wiedersehen!\n"};
    } else if (strcmp(lang, "cn") == 0) {
        msgs = (Messages){"输入第一个数字: ",
                          "输入运算符 (+, -, *, /): ",
                          "输入第二个数字: ",
                          "无效输入!\n",
                          "第二个数字不能为0!\n",
                          "请输入有效运算符!\n",
                          "结果是 %.2f\n",
                          "是否继续计算? (y/n): ",
                          "再见!\n"};
    } else if (strcmp(lang, "tr") == 0) {
        msgs = (Messages){"İlk sayıyı girin: ",
                          "Operatörü girin (+, -, *, /): ",
                          "İkinci sayıyı girin: ",
                          "Geçersiz giriş!\n",
                          "İkinci sayı 0 olamaz!\n",
                          "Geçerli bir operatör girin!\n",
                          "Sonuç: %.2f\n",
                          "Başka bir hesaplama yapmak ister misiniz? (y/n): ",
                          "Hoşçakal!\n"};
    } else if (strcmp(lang, "fr") == 0) {
        msgs = (Messages){"Entrez le premier nombre: ",
                          "Entrez l'opérateur (+, -, *, /): ",
                          "Entrez le deuxième nombre: ",
                          "Entrée invalide!\n",
                          "Le deuxième nombre ne peut pas être 0!\n",
                          "Entrez un opérateur valide!\n",
                          "Le résultat est %.2f\n",
                          "Voulez-vous faire un autre calcul? (y/n): ",
                          "Au revoir!\n"};
    } else { // default English
        msgs = (Messages){"Enter first number: ",
                          "Enter operator (+, -, *, /): ",
                          "Enter second number: ",
                          "Invalid input!\n",
                          "Second number cannot be 0!\n",
                          "Enter a valid operator!\n",
                          "The result is %.2f\n",
                          "Do you want to perform another calculation? (y/n): ",
                          "Goodbye!\n"};
    }

    while (running) {
        float num1, num2, result;
        char op;

        // Get first number
        printf("%s", msgs.enter_first);
        if (scanf("%f", &num1) != 1) { printf("%s", msgs.invalid_input); while(getchar()!='\n'); continue; }

        // Get operator
        printf("%s", msgs.enter_operator);
        scanf(" %c", &op); while(getchar()!='\n');

        // Get second number
        printf("%s", msgs.enter_second);
        if (scanf("%f", &num2) != 1) { printf("%s", msgs.invalid_input); while(getchar()!='\n'); continue; }

        // Calculate
        switch(op) {
            case '+': result = num1 + num2; break;
            case '-': result = num1 - num2; break;
            case '*': result = num1 * num2; break;
            case '/':
                if (num2 != 0) result = num1 / num2;
                else { printf("%s", msgs.div_zero); continue; }
                break;
            default: printf("%s", msgs.invalid_operator); continue;
        }

        // Print result
        printf(msgs.result_msg, result);

        // Ask to continue
        char cont;
        printf("%s", msgs.continue_msg);
        scanf(" %c", &cont); while(getchar()!='\n');
        if (cont != 'y' && cont != 'Y') running = false;
    }

    printf("%s", msgs.goodbye);
    return 0;
}