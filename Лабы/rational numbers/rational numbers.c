/* Рациональные числа. Разработать программу, меню которой позволяет выполнить
 * следующие функции:
 *
 * Ввод (числитель и знаменатель) двух рациональных чисел.
 * Вывод двух рациональных чисел (в форме: n/m).
 * Сложение чисел.
 * Вычитание чисел.
 * Умножение чисел.
 * Деление чисел.
 * Получение гармонического значения двух чисел.
 * Информация о версии и авторе программы.
 * Выход из программы.
 */

#include <stdio.h>

struct fractions {
    int nominator;
    int denominator;
};

//checking the correctness of data entered
int check_char(int* result) {
    char buff[10];
    
    return fgets(buff, sizeof buff, stdin) && sscanf(buff, "%d", result) == 1;
}


void fractions_input(struct fractions* current, char error[50]) {
    int current_nom;
    int current_denom;
    
    while(!check_char(&current_nom) || !check_char(&current_denom)){
        printf("%s\n", error);
    }
    current->nominator = current_nom;
    current->denominator = current_denom;
}


void fract_show (struct fractions fract) {
    printf("%d/%d\n", fract.nominator, fract.denominator);
}


struct fractions fractions_add(struct fractions first_fract, struct fractions second_fract) {
    struct fractions result;
    if (first_fract.denominator == second_fract.denominator) {
        result.nominator = first_fract.nominator + second_fract.nominator;
        result.denominator = first_fract.denominator;
    } else {
        result.nominator = first_fract.nominator * second_fract.denominator + second_fract.nominator * first_fract.denominator;
        result.denominator = first_fract.denominator * second_fract.denominator;
    }
    return result;
}


struct fractions fractions_subtract(struct fractions first_fract, struct fractions second_fract) {
   struct fractions result;
    if (first_fract.denominator == second_fract.denominator) {
        result.nominator = first_fract.nominator - second_fract.nominator;
        result.denominator = first_fract.denominator;
    } else {
        result.nominator = first_fract.nominator * second_fract.denominator - second_fract.nominator * first_fract.denominator;
        result.denominator = first_fract.denominator * second_fract.denominator;
    }
    return result; 
}


struct fractions fractions_multiply(struct fractions first_fract, struct fractions second_fract) {
    struct fractions result;
    result.nominator = first_fract.nominator * second_fract.nominator;
    result.denominator = first_fract.denominator * second_fract.denominator;
    return result;
}


struct fractions fractions_divid(struct fractions first_fract, struct fractions second_fract) {
    struct fractions result;
    result.nominator = first_fract.nominator * second_fract.denominator;
    result.denominator = first_fract.denominator * second_fract.nominator;
    return result;
}


struct fractions harmonic_get(struct fractions first_fract, struct fractions second_fract) {
    struct fractions result;
    result.nominator = first_fract.nominator * second_fract.nominator * 2;
    result.denominator = first_fract.denominator * second_fract.nominator + second_fract.denominator * first_fract.nominator;
    return result;
}


void show_info() {
    printf("Software version: 0.4 \nThe author: Klimenko Nikita \n");
}


int main() {
    struct fractions  first_fract;
    struct fractions second_fract;
    
    int choice;
    
    char error[50] = "Wrong values. Please enter the values again.";
    char input_first[70] = "Enter the numerator and denominator of the first fraction\n";
    char input_second[70] = "Enter the numerator and denominator of the second fraction\n";

    printf("%s", input_first);
    fractions_input(&first_fract, error);
    printf("%s", input_second);
    fractions_input(&second_fract, error);
    enum Choice {INPUT_FRACTIONS = 1, SHOW_FRACTIONS, ADD_FRACTIONS, SUBTRACT_FRACTIONS, MYLTIPLY_FRACTIONS, 
    DIV_FRACTIONS, GET_HARMONIC, SHOW_INFO_VERS, EXIT_MENU};
    printf("(1) Enter numbers\n(2) Finding numbers\n(3) Addition\n(4) Subtraction\n(5) Multiply\n(6) Division\n\
(7) Conclusion the harmonic values of numbers\n(8) Version and the author of the program\n(9) Exit\n");
    for (;;) {
        printf("Select the menu item\n");

        while(!check_char(&choice)) {
        printf("%s\n", error);
        }

        switch (choice) 
        {
            default:
                
                break;
            
            case INPUT_FRACTIONS:
                
                printf("%s", input_first);
                fractions_input(&first_fract, error);
                printf("%s", input_second);
                fractions_input(&second_fract, error);
                break;
            
            case SHOW_FRACTIONS:
            
                fract_show(first_fract);
                fract_show(second_fract);
                break;
            
            case ADD_FRACTIONS:
                fract_show(fractions_add(first_fract, second_fract));
                break;
            
            case SUBTRACT_FRACTIONS:
                fract_show(fractions_subtract(first_fract, second_fract));
                break;
            
            case MYLTIPLY_FRACTIONS:
                fract_show(fractions_multiply(first_fract, second_fract));
                break;
            
            case DIV_FRACTIONS:
                fract_show(fractions_divid(first_fract, second_fract));
                break;
        
            case GET_HARMONIC:
                fract_show(harmonic_get(first_fract, second_fract));
                break;
        
            case SHOW_INFO_VERS:
                show_info();
                break;
            
            case EXIT_MENU:
                return 0;
                break;
        }
    }
}

