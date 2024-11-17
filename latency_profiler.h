#ifndef LATENCY_PROFILER_H
#define LATENCY_PROFILER_H

#include <time.h>

// Structure to hold timing data
typedef struct {
    struct timespec start_time;
    struct timespec end_time;
} Profiler;

// Function declarations
void start_profiler(Profiler* profiler);
long stop_profiler(Profiler* profiler);
void print_latency(const char* operation, long elapsed_time);

#endif
