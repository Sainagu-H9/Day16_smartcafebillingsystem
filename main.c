#include <stdio.h>

int main() {
    int c, ino, qty, items;
    float price, bill, tb = 0, income = 0;
    int total_qty = 0;
    int count[5] = {0};

    printf("========== Cafe Order Management System ==========\n\n");
    printf("Item No.\tItem Name\tPrice\n");
    printf("1.\t\tCoffee\t\t50\n");
    printf("2.\t\tTea\t\t30\n");
    printf("3.\t\tSandwich\t80\n");
    printf("4.\t\tBurger\t\t120\n");
    printf("5.\t\tPastry\t\t60\n\n");

    printf("Enter total customers: ");
    scanf("%d", &c);

    if (c > 10) {
        printf("---- Max capacity is 10 customers ----\n");
        return 0;
    }

    for (int i = 1; i <= c; i++) {
        tb = 0;
        printf("\n--- Customer %d ---\n", i);
        printf("Enter number of items: ");
        scanf("%d", &items);

        int j = 1;
        while (j <= items) {
            printf("Enter item number: ");
            scanf("%d", &ino);

            if (ino < 1 || ino > 5) {
                printf("--- Invalid item number ---\n");
                return 0;
            }

            printf("Enter quantity: ");
            scanf("%d", &qty);

            if (ino == 1)
                price = 50;
            else if (ino == 2)
                price = 30;
            else if (ino == 3)
                price = 80;
            else if (ino == 4)
                price = 120;
            else
                price = 60;

            bill = price * qty;
            tb += bill;
            total_qty += qty;
            count[ino - 1] += qty;

            j++;
        }

        printf("Total Bill for Customer %d: %.0f\n", i, tb);
        income += tb;
    }

    int max = 0, min = 0;
    for (int i = 1; i < 5; i++) {
        if (count[i] > count[max])
            max = i;
        if (count[i] < count[min])
            min = i;
    }

    char *item_name[] = {"Coffee", "Tea", "Sandwich", "Burger", "Pastry"};

    printf("\n========== Cafe Summary ==========\n");
    printf("Total Revenue: %.0f\n", income);
    printf("Total Items Sold: %d\n", total_qty);
    printf("Most Ordered Item: %s\n", item_name[max]);
    printf("Least Ordered Item: %s\n", item_name[min]);
    printf("==================================\n");

    return 0;
}
