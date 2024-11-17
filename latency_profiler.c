#include <stdio.h>
#include <time.h>

// Structure to hold timing data
typedef struct {
    struct timespec start_time;
    struct timespec end_time;
} Profiler;

// Start the timer
void start_profiler(Profiler* profiler) {
    clock_gettime(CLOCK_MONOTONIC, &profiler->start_time);
}

// Stop the timer and calculate elapsed time in nanoseconds
long stop_profiler(Profiler* profiler) {
    clock_gettime(CLOCK_MONOTONIC, &profiler->end_time);
    long elapsed_time = (profiler->end_time.tv_sec - profiler->start_time.tv_sec) * 1000000000L +
                        (profiler->end_time.tv_nsec - profiler->start_time.tv_nsec);
    return elapsed_time;
}

// Print the elapsed time in microseconds
void print_latency(const char* operation, long elapsed_time) {
    printf("%s latency: %ld microseconds\n", operation, elapsed_time / 1000);
}
