#include <stdio.h>
#include "matrix_operations.h"
#include "basic_operations.h"
#include "history.h"

void run_calculator() {
    HistoryNode *history = NULL;
    load_history_from_csv(&history);

    int choice;
    while (1) {
        printf("\nWhich action do you want to take?\n");
        printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n");
        printf("5. Square Root\n6. Power\n7. Matrix Addition\n8. Matrix Multiplication\n");
        printf("9. Determinant\n10. Show History\n11. Exit\n");
        printf("Your Choice: ");
        scanf("%d", &choice);

        if (choice == 11) {
            save_history_to_csv(history);
            clear_history(&history);
            printf("Exiting the program...\n");
            break;
        }

        switch (choice) {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
                handle_basic_operations(choice, &history);
                break;
            case 7:
            case 8:
            case 9:
                handle_matrix_operations(choice, &history);
                break;
            case 10:
                display_history(history);
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}