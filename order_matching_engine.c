#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define order types
typedef enum { BUY, SELL } OrderType;

// Define the structure for an order
typedef struct Order {
    char symbol[10];
    OrderType type;
    double price;
    int volume;
    struct Order* next;
} Order;

// Define the order book structure
typedef struct {
    Order* buy_orders;
    Order* sell_orders;
} OrderBook;

// Initialize an empty order book
OrderBook* initialize_order_book() {
    OrderBook* book = (OrderBook*)malloc(sizeof(OrderBook));
    book->buy_orders = NULL;
    book->sell_orders = NULL;
    return book;
}

// Function to create a new order
Order* create_order(const char* symbol, OrderType type, double price, int volume) {
    Order* new_order = (Order*)malloc(sizeof(Order));
    strncpy(new_order->symbol, symbol, sizeof(new_order->symbol) - 1);
    new_order->type = type;
    new_order->price = price;
    new_order->volume = volume;
    new_order->next = NULL;
    return new_order;
}

// Function to add an order to the order book
void add_order(OrderBook* book, Order* order) {
    Order** order_list = (order->type == BUY) ? &book->buy_orders : &book->sell_orders;

    // Insert at the end of the respective order list (FIFO for now)
    if (*order_list == NULL) {
        *order_list = order;
    } else {
        Order* temp = *order_list;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = order;
    }
    printf("Order added: %s %s at %.2f, volume %d\n", 
           order->type == BUY ? "BUY" : "SELL", order->symbol, order->price, order->volume);
}

// Function to match orders in the order book
void match_orders(OrderBook* book) {
    while (book->buy_orders && book->sell_orders) {
        Order* buy_order = book->buy_orders;
        Order* sell_order = book->sell_orders;

        // Check if prices match
        if (buy_order->price >= sell_order->price) {
            int volume_traded = (buy_order->volume < sell_order->volume) ? buy_order->volume : sell_order->volume;
            printf("Matched %d shares of %s at %.2f\n", volume_traded, buy_order->symbol, sell_order->price);

            // Adjust volumes
            buy_order->volume -= volume_traded;
            sell_order->volume -= volume_traded;

            // Remove fulfilled orders
            if (buy_order->volume == 0) {
                book->buy_orders = buy_order->next;
                free(buy_order);
            }
            if (sell_order->volume == 0) {
                book->sell_orders = sell_order->next;
                free(sell_order);
            }
        } else {
            // If prices don’t match, break out
            break;
        }
    }
}

// Clean up and free all orders in the order book
void free_order_book(OrderBook* book) {
    Order* temp;
    while (book->buy_orders) {
        temp = book->buy_orders;
        book->buy_orders = book->buy_orders->next;
        free(temp);
    }
    while (book->sell_orders) {
        temp = book->sell_orders;
        book->sell_orders = book->sell_orders->next;
        free(temp);
    }
    free(book);
}

