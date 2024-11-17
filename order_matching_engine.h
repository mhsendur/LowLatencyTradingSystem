#ifndef ORDER_MATCHING_ENGINE_H
#define ORDER_MATCHING_ENGINE_H

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

// Function declarations
OrderBook* initialize_order_book();
Order* create_order(const char* symbol, OrderType type, double price, int volume);
void add_order(OrderBook* book, Order* order);
void match_orders(OrderBook* book);
void free_order_book(OrderBook* book);

#endif
