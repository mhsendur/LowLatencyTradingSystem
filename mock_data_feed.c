#include "mock_data_feed.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random mock market data record
MarketData generate_mock_data() {
    MarketData data;
    const char* symbols[] = {"AAPL", "GOOG", "AMZN", "MSFT", "TSLA"};
    int num_symbols = sizeof(symbols) / sizeof(symbols[0]);

    snprintf(data.symbol, sizeof(data.symbol), "%s", symbols[rand() % num_symbols]);
    data.price = 100.0 + (rand() % 5000) / 10.0;
    data.volume = 10 + rand() % 1000;

    return data;
}

// Function to simulate the data feed for a set number of entries
void simulate_data_feed(int num_entries) {
    for (int i = 0; i < num_entries; i++) {
        MarketData data = generate_mock_data();
        printf("Symbol: %s, Price: %.2f, Volume: %d\n", data.symbol, data.price, data.volume);
        struct timespec ts = {0, 100000000};
        nanosleep(&ts, NULL);
    }
}
