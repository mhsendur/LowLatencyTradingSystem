#ifndef MOCK_DATA_FEED_H
#define MOCK_DATA_FEED_H

// Define the structure for mock market data
typedef struct {
    char symbol[10];
    double price;
    int volume;
} MarketData;

// Function declarations
MarketData generate_mock_data();
void simulate_data_feed(int num_entries);

#endif
