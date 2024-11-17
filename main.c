#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mock_data_feed.h"
#include "order_matching_engine.h"
#include "latency_profiler.h"
    

// Function declarations
void initialize_system();
void load_mock_data();
void execute_trades();
void shutdown_system();

// Main function
int main() {
    // Initialize the trading system
    printf("Initializing Low-Latency Trading System Simulator...\n");
    initialize_system();

    // Load mock data
    printf("Loading mock market data...\n");
    load_mock_data();

    // Execute trades
    printf("Executing trades on simulated data...\n");
    execute_trades();

    // Shutdown the system
    printf("Shutting down system.\n");
    shutdown_system();

    return 0;
}

// Function to initialize system resources
void initialize_system() {
    // Placeholder for initialization logic
    printf("System initialized.\n");
}

// Function to load mock data using mock_data_feed module
void load_mock_data() {
    int num_entries = 10; // Number of data points to simulate
    simulate_data_feed(num_entries);
}

// Function to execute trades using order-matching engine and profiler
void execute_trades() {
    // Initialize the order book
    OrderBook* book = initialize_order_book();

    // Add some sample orders
    add_order(book, create_order("AAPL", BUY, 150.00, 100));
    add_order(book, create_order("AAPL", SELL, 149.50, 50));
    add_order(book, create_order("AAPL", SELL, 150.00, 75));
    add_order(book, create_order("AAPL", BUY, 151.00, 60));

    // Initialize the profiler and start timing
    Profiler profiler;
    start_profiler(&profiler);

    // Match orders
    match_orders(book);

    // Stop the profiler and print latency
    long elapsed_time = stop_profiler(&profiler);
    print_latency("Order Matching", elapsed_time);

    // Clean up the order book
    free_order_book(book);
}

// Function to shut down and release system resources
void shutdown_system() {
    // Placeholder for clean-up logic
    printf("System resources released.\n");
}
