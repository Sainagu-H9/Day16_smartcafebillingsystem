#include <stdio.h>

int main() {
    int n, item_no, q, no_items;
    float p, bill, t_b = 0, total_income = 0;
    int total_items_sold = 0;
    int item_count[5] = {0};

    printf("========== Cafe Order Management System ==========\n\n");
    printf("Item No.\tItem Name\tPrice\n");
    printf("1.\t\tCoffee\t\t50\n");
    printf("2.\t\tTea\t\t30\n");
    printf("3.\t\tSandwich\t80\n");
    printf("4.\t\tBurger\t\t120\n");
    printf("5.\t\tPastry\t\t60\n\n");

    printf("Enter total number of customers: ");
    scanf("%d", &n);

    if (n > 10) {
        printf("---- Max capacity is only 10 members. Please try again. ----\n");
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        t_b = 0;
        printf("\n--- Customer %d ---\n", i);

        printf("Enter number of items: ");
        scanf("%d", &no_items);

        printf("Enter item number:\n");
        scanf(" %d", &item_no);
        if (item_no>5 || item_no<1)
        {
            printf("---invalid input---");
            return 0 ;
        }
        else
        {
        printf("Enter Quantity ::");
        scanf("%d", &q);
        
            switch (item_no) {
                case 1: p = 50; break;
                case 2: p = 30; break;
                case 3: p = 80; break;
                case 4: p = 120; break;
                case 5: p = 60; break;
                default:
                    printf("Invalid item number! Skipping...\n");
                    continue;
            }

            bill = p * q;
            t_b += bill;
            total_items_sold += q;
            item_count[item_no - 1] += q;
        }

        printf("Total Bill for Customer %d: %.0f\n", i, t_b);
        total_income += t_b;
    }

    // Find most and least ordered items
    int max_idx = 0, min_idx = 0;
    for (int i = 1; i < 5; i++) {
        if (item_count[i] > item_count[max_idx])
            max_idx = i;
        if (item_count[i] < item_count[min_idx])
            min_idx = i;
    }

    char *items[] = {"Coffee", "Tea", "Sandwich", "Burger", "Pastry"};

    printf("\n========== Cafe Summary ==========\n");
    printf("Total Revenue: %.0f\n", total_income);
    printf("Total Items Sold: %d\n", total_items_sold);
    printf("Most Ordered Item: %s\n", items[max_idx]);
    printf("Least Ordered Item: %s\n", items[min_idx]);
    printf("==================================\n");

    return 0;
}
