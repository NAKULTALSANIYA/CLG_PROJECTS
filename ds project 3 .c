#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for Order
struct Order {
    int orderId;
    char customerName[50];
    char product[50];
    float price;
    struct Order* next;
};

// Create a queue to store orders
struct Order* front = NULL;
struct Order* rear = NULL;

// Function to create a new order
struct Order* createOrder(int orderId, char* customerName, char* product, float price) {
    struct Order* newOrder = (struct Order*)malloc(sizeof(struct Order));
    newOrder->orderId = orderId;
    strcpy(newOrder->customerName, customerName);
    strcpy(newOrder->product, product);
    newOrder->price = price;
    newOrder->next = NULL;
    return newOrder;
}

// Function to add an order to the queue (FIFO)
void addOrder() {
    int orderId;
    char customerName[50], product[50];
    float price;

    printf("Enter Order ID: ");
    scanf("%d", &orderId);
    getchar();  // To consume newline character
    printf("Enter Customer Name: ");
    fgets(customerName, sizeof(customerName), stdin);
    customerName[strcspn(customerName, "\n")] = '\0';  // Remove newline character
    printf("Enter Product Name: ");
    fgets(product, sizeof(product), stdin);
    product[strcspn(product, "\n")] = '\0';  // Remove newline character
    printf("Enter Price: ");
    scanf("%f", &price);

    struct Order* newOrder = createOrder(orderId, customerName, product, price);

    if (rear == NULL) {
        front = rear = newOrder;
    } else {
        rear->next = newOrder;
        rear = newOrder;
    }
    printf("Order Added Successfully!\n");
}

// Function to process (serve) an order (FIFO)
void processOrder() {
    if (front == NULL) {
        printf("No pending orders.\n");
    } else {
        struct Order* temp = front;
        printf("Processing Order ID: %d\n", temp->orderId);
        printf("Customer Name: %s\n", temp->customerName);
        printf("Product: %s\n", temp->product);
        printf("Price: %.2f\n", temp->price);

        front = front->next; // Remove the front order
        free(temp);
    }
}

// Function to display all pending orders
void displayOrders() {
    if (front == NULL) {
        printf("No pending orders.\n");
    } else {
        struct Order* temp = front;
        while (temp != NULL) {
            printf("Order ID: %d, Customer: %s, Product: %s, Price: %.2f\n",
                   temp->orderId, temp->customerName, temp->product, temp->price);
            temp = temp->next;
        }
    }
}

// Main function to drive the program
int main() {
    int choice;

    while (1) {
        printf("1. Add Order\n");
        printf("2. Process Order\n");
        printf("3. Display Orders\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addOrder();
                break;
            case 2:
                processOrder();
                break;
            case 3:
                displayOrders();
                break;
            case 4:
                printf("Exiting system...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
