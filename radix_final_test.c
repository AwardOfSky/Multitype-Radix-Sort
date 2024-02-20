#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <time.h>
#include "rsort.h"


#define max(a,b)                \
({ __typeof__ (a) _a = (a);     \
    __typeof__ (b) _b = (b);    \
    _a > _b ? _a : _b; })


#define min(a,b)                \
({ __typeof__ (a) _a = (a);     \
    __typeof__ (b) _b = (b);    \
    _a < _b ? _a : _b; })


#define PRINT_ARR(ARR, N, FORMAT, MEM) do { \
    size_t _i;                              \
    for(_i = 0; _i < N; ++_i) {             \
        printf(FORMAT" ", ARR[_i]MEM);      \
    }                                       \
    printf("\n");                           \
} while(0)


#define CHECK_SORT_ARR(ARR, N, ASC, MEM) do {                                                   \
    check = 1;                                                                                  \
    int i;                                                                                      \
    for (i = 0; i < N - 1; ++i) {                                                               \
        if ((ASC && (ARR[i + 1]MEM < ARR[i]MEM)) || (!ASC && (ARR[i + 1]MEM > ARR[i]MEM))) {    \
            check = 0;                                                                          \
            break;                                                                              \
        }                                                                                       \
    }                                                                                           \
} while(0)


/* 36 types (192 bytes) */
typedef struct node {
	float float_;
	double double_;
	char char_;
    short short_;
	int int_;
	long long_;
	int8_t int8_t_;
	int16_t int16_t_;
	int32_t int32_t_;
	int64_t int64_t_;
	int_fast8_t int_fast8_t_;
	int_fast16_t int_fast16_t_;
	int_fast32_t int_fast32_t_;
	int_fast64_t int_fast64_t_;
    int_least8_t int_least8_t_;
	int_least16_t int_least16_t_;
	int_least32_t int_least32_t_;
	int_least64_t int_least64_t_;
	intptr_t intptr_t_;
	intmax_t intmax_t_;
	uint8_t uint8_t_;
	uint16_t uint16_t_;
	uint32_t uint32_t_;
	uint64_t uint64_t_;
	uint_fast8_t uint_fast8_t_;
	uint_fast16_t uint_fast16_t_;
	uint_fast32_t uint_fast32_t_;
	uint_fast64_t uint_fast64_t_;
	uint_least8_t uint_least8_t_;
	uint_least16_t uint_least16_t_;
	uint_least32_t uint_least32_t_;
	uint_least64_t uint_least64_t_;
	uintptr_t uintptr_t_;
	uintmax_t uintmax_t_;
    size_t size_t_;
    wchar_t wchar_t_;
} node;


#define TEST_STRUCTS 0

/* test block */
#define TEST_CASE(ARR, ASC, ARR_T, MEM_T, MEM) do {         \
    start = clock();                                        \
    RADIX_SORT(ARR, size, ASC, ARR_T);                      \
    duration = (double)(clock() - start) / CLOCKS_PER_SEC;  \
    CHECK_SORT_ARR(ARR, size, ASC, MEM);                    \
    printf("%s check for "#ARR_T" type array: %s! Sorted %d elements in: %.3fs (%.1f ns/el)\n", ASC == 1 ? "Ascending" : "Descending", check == 1 ? "passed" : "ERROR", size, duration, (1000000000.0 / (double)size) * duration);\
    if (check) passed_tests++;                              \
    total_tests++;                                          \
} while(0)


#define TEST_CASE_S(ARR, ASC, ARR_T, MEM_T, MEM) do {       \
    start = clock();                                        \
    RADIX_SORT_STRUCT(ARR, size, ASC, ARR_T, MEM_T, MEM);   \
    duration = (double)(clock() - start) / CLOCKS_PER_SEC;  \
    CHECK_SORT_ARR(ARR, size, ASC, MEM);                    \
    printf("%s check for "#ARR_T" type array: %s! Sorted %d elements in: %.3fs (%.1f ns/el)\n", ASC == 1 ? "Ascending" : "Descending", check == 1 ? "passed" : "ERROR", size, duration, (1000000000.0 / (double)size) * duration);\
    if (check) passed_tests++;                              \
    total_tests++;                                          \
} while(0)

float rand_float();
double rand_double();

int main(int argc, char **argv) {
    /* uint32_t random_seed = 239741; */
    uint32_t random_seed = time(NULL);

    int passed_tests = 0;
    int total_tests = 0;
    srand(random_seed);
    int check = 0;
    clock_t start;
    double duration;
    int size = 10000000;
    if (argc >= 2) {
        size = atoi(argv[1]);
    }

    /* declare */
    printf("Allocating arrays...");

    node *node_arr1;
    node *node_arr2;
    if (TEST_STRUCTS) {
        node_arr1 = (node *)malloc(sizeof(*node_arr1) * size);
        node_arr2 = (node *)malloc(sizeof(*node_arr2) * size);
    }

    float *float_arr1 = (float *)malloc(sizeof(*float_arr1) * size);
    float *float_arr2 = (float *)malloc(sizeof(*float_arr2) * size);
    double *double_arr1 = (double *)malloc(sizeof(*double_arr1) * size);
    double *double_arr2 = (double *)malloc(sizeof(*double_arr2) * size);
    char *char_arr1 = (char *)malloc(sizeof(*char_arr1) * size);
    char *char_arr2 = (char *)malloc(sizeof(*char_arr2) * size);
    short *short_arr1 = (short *)malloc(sizeof(*short_arr1) * size);
    short *short_arr2 = (short *)malloc(sizeof(*short_arr2) * size);
    int *int_arr1 = (int *)malloc(sizeof(*int_arr1) * size);
    int *int_arr2 = (int *)malloc(sizeof(*int_arr2) * size);
    long *long_arr1 = (long *)malloc(sizeof(*long_arr1) * size);
    long *long_arr2 = (long *)malloc(sizeof(*long_arr2) * size);
    int8_t *int8_t_arr1 = (int8_t *)malloc(sizeof(*int8_t_arr1) * size);
    int8_t *int8_t_arr2 = (int8_t *)malloc(sizeof(*int8_t_arr2) * size);
    int16_t *int16_t_arr1 = (int16_t *)malloc(sizeof(*int16_t_arr1) * size);
    int16_t *int16_t_arr2 = (int16_t *)malloc(sizeof(*int16_t_arr2) * size);
    int32_t *int32_t_arr1 = (int32_t *)malloc(sizeof(*int32_t_arr1) * size);
    int32_t *int32_t_arr2 = (int32_t *)malloc(sizeof(*int32_t_arr2) * size);
    int64_t *int64_t_arr1 = (int64_t *)malloc(sizeof(*int64_t_arr1) * size);
    int64_t *int64_t_arr2 = (int64_t *)malloc(sizeof(*int64_t_arr2) * size);
    int_fast8_t *int_fast8_t_arr1 = (int_fast8_t *)malloc(sizeof(*int_fast8_t_arr1) * size);
    int_fast8_t *int_fast8_t_arr2 = (int_fast8_t *)malloc(sizeof(*int_fast8_t_arr2) * size);
    int_fast16_t *int_fast16_t_arr1 = (int_fast16_t *)malloc(sizeof(*int_fast16_t_arr1) * size);
    int_fast16_t *int_fast16_t_arr2 = (int_fast16_t *)malloc(sizeof(*int_fast16_t_arr2) * size);
    int_fast32_t *int_fast32_t_arr1 = (int_fast32_t *)malloc(sizeof(*int_fast32_t_arr1) * size);
    int_fast32_t *int_fast32_t_arr2 = (int_fast32_t *)malloc(sizeof(*int_fast32_t_arr2) * size);
    int_fast64_t *int_fast64_t_arr1 = (int_fast64_t *)malloc(sizeof(*int_fast64_t_arr1) * size);
    int_fast64_t *int_fast64_t_arr2 = (int_fast64_t *)malloc(sizeof(*int_fast64_t_arr2) * size);
    int_least8_t *int_least8_t_arr1 = (int_least8_t *)malloc(sizeof(*int_least8_t_arr1) * size);
    int_least8_t *int_least8_t_arr2 = (int_least8_t *)malloc(sizeof(*int_least8_t_arr2) * size);
    int_least16_t *int_least16_t_arr1 = (int_least16_t *)malloc(sizeof(*int_least16_t_arr1) * size);
    int_least16_t *int_least16_t_arr2 = (int_least16_t *)malloc(sizeof(*int_least16_t_arr2) * size);
    int_least32_t *int_least32_t_arr1 = (int_least32_t *)malloc(sizeof(*int_least32_t_arr1) * size);
    int_least32_t *int_least32_t_arr2 = (int_least32_t *)malloc(sizeof(*int_least32_t_arr2) * size);
    int_least64_t *int_least64_t_arr1 = (int_least64_t *)malloc(sizeof(*int_least64_t_arr1) * size);
    int_least64_t *int_least64_t_arr2 = (int_least64_t *)malloc(sizeof(*int_least64_t_arr2) * size);
    intptr_t *intptr_t_arr1 = (intptr_t *)malloc(sizeof(*intptr_t_arr1) * size);
    intptr_t *intptr_t_arr2 = (intptr_t *)malloc(sizeof(*intptr_t_arr2) * size);
    intmax_t *intmax_t_arr1 = (intmax_t *)malloc(sizeof(*intmax_t_arr1) * size);
    intmax_t *intmax_t_arr2 = (intmax_t *)malloc(sizeof(*intmax_t_arr2) * size);
    uint8_t *uint8_t_arr1 = (uint8_t *)malloc(sizeof(*uint8_t_arr1) * size);
    uint8_t *uint8_t_arr2 = (uint8_t *)malloc(sizeof(*uint8_t_arr2) * size);
    uint16_t *uint16_t_arr1 = (uint16_t *)malloc(sizeof(*uint16_t_arr1) * size);
    uint16_t *uint16_t_arr2 = (uint16_t *)malloc(sizeof(*uint16_t_arr2) * size);
    uint32_t *uint32_t_arr1 = (uint32_t *)malloc(sizeof(*uint32_t_arr1) * size);
    uint32_t *uint32_t_arr2 = (uint32_t *)malloc(sizeof(*uint32_t_arr2) * size);
    uint64_t *uint64_t_arr1 = (uint64_t *)malloc(sizeof(*uint64_t_arr1) * size);
    uint64_t *uint64_t_arr2 = (uint64_t *)malloc(sizeof(*uint64_t_arr2) * size);
    uint_fast8_t *uint_fast8_t_arr1 = (uint_fast8_t *)malloc(sizeof(*uint_fast8_t_arr1) * size);
    uint_fast8_t *uint_fast8_t_arr2 = (uint_fast8_t *)malloc(sizeof(*uint_fast8_t_arr2) * size);
    uint_fast16_t *uint_fast16_t_arr1 = (uint_fast16_t *)malloc(sizeof(*uint_fast16_t_arr1) * size);
    uint_fast16_t *uint_fast16_t_arr2 = (uint_fast16_t *)malloc(sizeof(*uint_fast16_t_arr2) * size);
    uint_fast32_t *uint_fast32_t_arr1 = (uint_fast32_t *)malloc(sizeof(*uint_fast32_t_arr1) * size);
    uint_fast32_t *uint_fast32_t_arr2 = (uint_fast32_t *)malloc(sizeof(*uint_fast32_t_arr2) * size);
    uint_fast64_t *uint_fast64_t_arr1 = (uint_fast64_t *)malloc(sizeof(*uint_fast64_t_arr1) * size);
    uint_fast64_t *uint_fast64_t_arr2 = (uint_fast64_t *)malloc(sizeof(*uint_fast64_t_arr2) * size);
    uint_least8_t *uint_least8_t_arr1 = (uint_least8_t *)malloc(sizeof(*uint_least8_t_arr1) * size);
    uint_least8_t *uint_least8_t_arr2 = (uint_least8_t *)malloc(sizeof(*uint_least8_t_arr2) * size);
    uint_least16_t *uint_least16_t_arr1 = (uint_least16_t *)malloc(sizeof(*uint_least16_t_arr1) * size);
    uint_least16_t *uint_least16_t_arr2 = (uint_least16_t *)malloc(sizeof(*uint_least16_t_arr2) * size);
    uint_least32_t *uint_least32_t_arr1 = (uint_least32_t *)malloc(sizeof(*uint_least32_t_arr1) * size);
    uint_least32_t *uint_least32_t_arr2 = (uint_least32_t *)malloc(sizeof(*uint_least32_t_arr2) * size);
    uint_least64_t *uint_least64_t_arr1 = (uint_least64_t *)malloc(sizeof(*uint_least64_t_arr1) * size);
    uint_least64_t *uint_least64_t_arr2 = (uint_least64_t *)malloc(sizeof(*uint_least64_t_arr2) * size);
    uintptr_t *uintptr_t_arr1 = (uintptr_t *)malloc(sizeof(*uintptr_t_arr1) * size);
    uintptr_t *uintptr_t_arr2 = (uintptr_t *)malloc(sizeof(*uintptr_t_arr2) * size);
    uintmax_t *uintmax_t_arr1 = (uintmax_t *)malloc(sizeof(*uintmax_t_arr1) * size);
    uintmax_t *uintmax_t_arr2 = (uintmax_t *)malloc(sizeof(*uintmax_t_arr2) * size);
    size_t *size_t_arr1 = (size_t *)malloc(sizeof(*size_t_arr1) * size);
    size_t *size_t_arr2 = (size_t *)malloc(sizeof(*size_t_arr2) * size);
    wchar_t *wchar_t_arr1 = (wchar_t *)malloc(sizeof(*wchar_t_arr1) * size);
    wchar_t *wchar_t_arr2 = (wchar_t *)malloc(sizeof(*wchar_t_arr2) * size);
    printf("Done!\n");

    printf("Initializing test cases...");
    int i;
    for (i = 0; i < size; ++i) {
        int_arr1[i] = (rand() % RAND_MAX) - (RAND_MAX >> 1);
        int_arr2[i] = (rand() % RAND_MAX) - (RAND_MAX >> 1);
        float_arr1[i] = rand_float() * int_arr1[i];
        float_arr2[i] = rand_float() * int_arr2[i];
        double_arr1[i] = rand_double() * int_arr1[i];
        double_arr2[i] = rand_double() * int_arr2[i];
        char_arr1[i] = (char)((rand() % RAND_MAX) - (RAND_MAX >> 1));
        char_arr2[i] = (char)((rand() % RAND_MAX) - (RAND_MAX >> 1));
        short_arr1[i] = (short)((rand() % RAND_MAX) - (RAND_MAX >> 1));
        short_arr2[i] = (short)((rand() % RAND_MAX) - (RAND_MAX >> 1));
        long_arr1[i] = (long)((rand() % RAND_MAX) - (RAND_MAX >> 1));
        long_arr2[i] = (long)((rand() % RAND_MAX) - (RAND_MAX >> 1));
        int8_t_arr1[i] = (int8_t)((rand() % RAND_MAX) - (RAND_MAX >> 1));
        int8_t_arr2[i] = (int8_t)((rand() % RAND_MAX) - (RAND_MAX >> 1));
        int16_t_arr1[i] = (int16_t)((rand() % RAND_MAX) - (RAND_MAX >> 1));
        int16_t_arr2[i] = (int16_t)((rand() % RAND_MAX) - (RAND_MAX >> 1));
        int32_t_arr1[i] = (int32_t)((rand() % RAND_MAX) - (RAND_MAX >> 1));
        int32_t_arr2[i] = (int32_t)((rand() % RAND_MAX) - (RAND_MAX >> 1));
        int64_t_arr1[i] = (int64_t)((rand() % RAND_MAX) - (RAND_MAX >> 1));
        int64_t_arr2[i] = (int64_t)((rand() % RAND_MAX) - (RAND_MAX >> 1));
        int_fast8_t_arr1[i] = (int_fast8_t)((rand() % RAND_MAX) - (RAND_MAX >> 1));
        int_fast8_t_arr2[i] = (int_fast8_t)((rand() % RAND_MAX) - (RAND_MAX >> 1));
        int_fast16_t_arr1[i] = (int_fast16_t)((rand() % RAND_MAX) - (RAND_MAX >> 1));
        int_fast16_t_arr2[i] = (int_fast16_t)((rand() % RAND_MAX) - (RAND_MAX >> 1));
        int_fast32_t_arr1[i] = (int_fast32_t)((rand() % RAND_MAX) - (RAND_MAX >> 1));
        int_fast32_t_arr2[i] = (int_fast32_t)((rand() % RAND_MAX) - (RAND_MAX >> 1));
        int_fast64_t_arr1[i] = (int_fast64_t)((rand() % RAND_MAX) - (RAND_MAX >> 1));
        int_fast64_t_arr2[i] = (int_fast64_t)((rand() % RAND_MAX) - (RAND_MAX >> 1));
        int_least8_t_arr1[i] = (int_least8_t)((rand() % RAND_MAX) - (RAND_MAX >> 1));
        int_least8_t_arr2[i] = (int_least8_t)((rand() % RAND_MAX) - (RAND_MAX >> 1));
        int_least16_t_arr1[i] = (int_least16_t)((rand() % RAND_MAX) - (RAND_MAX >> 1));
        int_least16_t_arr2[i] = (int_least16_t)((rand() % RAND_MAX) - (RAND_MAX >> 1));
        int_least32_t_arr1[i] = (int_least32_t)((rand() % RAND_MAX) - (RAND_MAX >> 1));
        int_least32_t_arr2[i] = (int_least32_t)((rand() % RAND_MAX) - (RAND_MAX >> 1));
        int_least64_t_arr1[i] = (int_least64_t)((rand() % RAND_MAX) - (RAND_MAX >> 1));
        int_least64_t_arr2[i] = (int_least64_t)((rand() % RAND_MAX) - (RAND_MAX >> 1));
        intptr_t_arr1[i] = (intptr_t)((rand() % RAND_MAX) - (RAND_MAX >> 1));
        intptr_t_arr2[i] = (intptr_t)((rand() % RAND_MAX) - (RAND_MAX >> 1));
        intmax_t_arr1[i] = (intmax_t)((rand() % RAND_MAX) - (RAND_MAX >> 1));
        intmax_t_arr2[i] = (intmax_t)((rand() % RAND_MAX) - (RAND_MAX >> 1));
        uint8_t_arr1[i] = (uint8_t)(rand() % RAND_MAX);
        uint8_t_arr2[i] = (uint8_t)(rand() % RAND_MAX);
        uint16_t_arr1[i] = (uint16_t)(rand() % RAND_MAX);
        uint16_t_arr2[i] = (uint16_t)(rand() % RAND_MAX);
        uint32_t_arr1[i] = (uint32_t)(rand() % RAND_MAX);
        uint32_t_arr2[i] = (uint32_t)(rand() % RAND_MAX);
        uint64_t_arr1[i] = (uint64_t)(rand() % RAND_MAX);
        uint64_t_arr2[i] = (uint64_t)(rand() % RAND_MAX);
        uint_fast8_t_arr1[i] = (uint_fast8_t)(rand() % RAND_MAX);
        uint_fast8_t_arr2[i] = (uint_fast8_t)(rand() % RAND_MAX);
        uint_fast16_t_arr1[i] = (uint_fast16_t)(rand() % RAND_MAX);
        uint_fast16_t_arr2[i] = (uint_fast16_t)(rand() % RAND_MAX);
        uint_fast32_t_arr1[i] = (uint_fast32_t)(rand() % RAND_MAX);
        uint_fast32_t_arr2[i] = (uint_fast32_t)(rand() % RAND_MAX);
        uint_fast64_t_arr1[i] = (uint_fast64_t)(rand() % RAND_MAX);
        uint_fast64_t_arr2[i] = (uint_fast64_t)(rand() % RAND_MAX);
        uint_least8_t_arr1[i] = (uint_least8_t)(rand() % RAND_MAX);
        uint_least8_t_arr2[i] = (uint_least8_t)(rand() % RAND_MAX);
        uint_least16_t_arr1[i] = (uint_least16_t)(rand() % RAND_MAX);
        uint_least16_t_arr2[i] = (uint_least16_t)(rand() % RAND_MAX);
        uint_least32_t_arr1[i] = (uint_least32_t)(rand() % RAND_MAX);
        uint_least32_t_arr2[i] = (uint_least32_t)(rand() % RAND_MAX);
        uint_least64_t_arr1[i] = (uint_least64_t)(rand() % RAND_MAX);
        uint_least64_t_arr2[i] = (uint_least64_t)(rand() % RAND_MAX);
        uintptr_t_arr1[i] = (uintptr_t)(rand() % RAND_MAX);
        uintptr_t_arr2[i] = (uintptr_t)(rand() % RAND_MAX);
        uintmax_t_arr1[i] = (uintmax_t)(rand() % RAND_MAX);
        uintmax_t_arr2[i] = (uintmax_t)(rand() % RAND_MAX);
        size_t_arr1[i] = (size_t)(rand() % RAND_MAX);
        size_t_arr2[i] = (size_t)(rand() % RAND_MAX);
        wchar_t_arr1[i] = (wchar_t)(rand() % RAND_MAX);
        wchar_t_arr2[i] = (wchar_t)(rand() % RAND_MAX);

        if (TEST_STRUCTS) {
            node_arr1[i].float_ = float_arr1[i];
            node_arr2[i].float_ = float_arr2[i];
            node_arr1[i].double_ = double_arr1[i];
            node_arr2[i].double_ = double_arr2[i];
            node_arr1[i].char_ = char_arr1[i];
            node_arr2[i].char_ = char_arr2[i];
            node_arr1[i].short_ = short_arr1[i];
            node_arr2[i].short_ = short_arr2[i];
            node_arr1[i].int_ = int_arr1[i];
            node_arr2[i].int_ = int_arr2[i];
            node_arr1[i].long_ = long_arr1[i];
            node_arr2[i].long_ = long_arr2[i];
            node_arr1[i].int8_t_ = int8_t_arr1[i];
            node_arr2[i].int8_t_ = int8_t_arr2[i];
            node_arr1[i].int16_t_ = int16_t_arr1[i];
            node_arr2[i].int16_t_ = int16_t_arr2[i];
            node_arr1[i].int32_t_ = int32_t_arr1[i];
            node_arr2[i].int32_t_ = int32_t_arr2[i];
            node_arr1[i].int64_t_ = int64_t_arr1[i];
            node_arr2[i].int64_t_ = int64_t_arr2[i];
            node_arr1[i].int_fast8_t_ = int_fast8_t_arr1[i];
            node_arr2[i].int_fast8_t_ = int_fast8_t_arr2[i];
            node_arr1[i].int_fast16_t_ = int_fast16_t_arr1[i];
            node_arr2[i].int_fast16_t_ = int_fast16_t_arr2[i];
            node_arr1[i].int_fast32_t_ = int_fast32_t_arr1[i];
            node_arr2[i].int_fast32_t_ = int_fast32_t_arr2[i];
            node_arr1[i].int_fast64_t_ = int_fast64_t_arr1[i];
            node_arr2[i].int_fast64_t_ = int_fast64_t_arr2[i];
            node_arr1[i].int_least8_t_ = int_least8_t_arr1[i];
            node_arr2[i].int_least8_t_ = int_least8_t_arr2[i];
            node_arr1[i].int_least16_t_ = int_least16_t_arr1[i];
            node_arr2[i].int_least16_t_ = int_least16_t_arr2[i];
            node_arr1[i].int_least32_t_ = int_least32_t_arr1[i];
            node_arr2[i].int_least32_t_ = int_least32_t_arr2[i];
            node_arr1[i].int_least64_t_ = int_least64_t_arr1[i];
            node_arr2[i].int_least64_t_ = int_least64_t_arr2[i];
            node_arr1[i].intptr_t_ = intptr_t_arr1[i];
            node_arr2[i].intptr_t_ = intptr_t_arr2[i];
            node_arr1[i].intmax_t_ = intmax_t_arr1[i];
            node_arr2[i].intmax_t_ = intmax_t_arr2[i];
            node_arr1[i].uint8_t_ = uint8_t_arr1[i];
            node_arr2[i].uint8_t_ = uint8_t_arr2[i];
            node_arr1[i].uint16_t_ = uint16_t_arr1[i];
            node_arr2[i].uint16_t_ = uint16_t_arr2[i];
            node_arr1[i].uint32_t_ = uint32_t_arr1[i];
            node_arr2[i].uint32_t_ = uint32_t_arr2[i];
            node_arr1[i].uint64_t_ = uint64_t_arr1[i];
            node_arr2[i].uint64_t_ = uint64_t_arr2[i];
            node_arr1[i].uint_fast8_t_ = uint_fast8_t_arr1[i];
            node_arr2[i].uint_fast8_t_ = uint_fast8_t_arr2[i];
            node_arr1[i].uint_fast16_t_ = uint_fast16_t_arr1[i];
            node_arr2[i].uint_fast16_t_ = uint_fast16_t_arr2[i];
            node_arr1[i].uint_fast32_t_ = uint_fast32_t_arr1[i];
            node_arr2[i].uint_fast32_t_ = uint_fast32_t_arr2[i];
            node_arr1[i].uint_fast64_t_ = uint_fast64_t_arr1[i];
            node_arr2[i].uint_fast64_t_ = uint_fast64_t_arr2[i];
            node_arr1[i].uint_least8_t_ = uint_least8_t_arr1[i];
            node_arr2[i].uint_least8_t_ = uint_least8_t_arr2[i];
            node_arr1[i].uint_least16_t_ = uint_least16_t_arr1[i];
            node_arr2[i].uint_least16_t_ = uint_least16_t_arr2[i];
            node_arr1[i].uint_least32_t_ = uint_least32_t_arr1[i];
            node_arr2[i].uint_least32_t_ = uint_least32_t_arr2[i];
            node_arr1[i].uint_least64_t_ = uint_least64_t_arr1[i];
            node_arr2[i].uint_least64_t_ = uint_least64_t_arr2[i];
            node_arr1[i].uintptr_t_ = uintptr_t_arr1[i];
            node_arr2[i].uintptr_t_ = uintptr_t_arr2[i];
            node_arr1[i].uintmax_t_ = uintmax_t_arr1[i];
            node_arr2[i].uintmax_t_ = uintmax_t_arr2[i];
            node_arr1[i].size_t_ = size_t_arr1[i];
            node_arr2[i].size_t_ = size_t_arr2[i];
            node_arr1[i].wchar_t_ = wchar_t_arr1[i];
            node_arr2[i].wchar_t_ = wchar_t_arr2[i];
        }
    }
    printf("Done!\n");
    
    printf("Starting tests...\n");
    TEST_CASE(float_arr1, 1, float, float, );
    TEST_CASE(float_arr2, 0, float, float, );
    TEST_CASE(double_arr1, 1, double, double, );
    TEST_CASE(double_arr2, 0, double, double, ); 
    TEST_CASE(char_arr1, 1, char, char, );
    TEST_CASE(char_arr2, 0, char, char, );
    TEST_CASE(short_arr1, 1, short, short, );
    TEST_CASE(short_arr2, 0, short, short, );
    TEST_CASE(int_arr1, 1, int, int, );
    TEST_CASE(int_arr2, 0, int, int, );
    TEST_CASE(long_arr1, 1, long, long, );
    TEST_CASE(long_arr2, 0, long, long, );
    TEST_CASE(int8_t_arr1, 1, int8_t, int8_t, );
    TEST_CASE(int8_t_arr2, 0, int8_t, int8_t, );
    TEST_CASE(int16_t_arr1, 1, int16_t, int16_t, );
    TEST_CASE(int16_t_arr2, 0, int16_t, int16_t, );
    TEST_CASE(int32_t_arr1, 1, int32_t, int32_t, );
    TEST_CASE(int32_t_arr2, 0, int32_t, int32_t, );
    TEST_CASE(int64_t_arr1, 1, int64_t, int64_t, );
    TEST_CASE(int64_t_arr2, 0, int64_t, int64_t, );
    TEST_CASE(int_fast8_t_arr1, 1, int_fast8_t, int_fast8_t, );
    TEST_CASE(int_fast8_t_arr2, 0, int_fast8_t, int_fast8_t, );
    TEST_CASE(int_fast16_t_arr1, 1, int_fast16_t, int_fast16_t, );
    TEST_CASE(int_fast16_t_arr2, 0, int_fast16_t, int_fast16_t, );
    TEST_CASE(int_fast32_t_arr1, 1, int_fast32_t, int_fast32_t, );
    TEST_CASE(int_fast32_t_arr2, 0, int_fast32_t, int_fast32_t, );
    TEST_CASE(int_fast64_t_arr1, 1, int_fast64_t, int_fast64_t, );
    TEST_CASE(int_fast64_t_arr2, 0, int_fast64_t, int_fast64_t, );
    TEST_CASE(int_least8_t_arr1, 1, int_least8_t, int_least8_t, );
    TEST_CASE(int_least8_t_arr2, 0, int_least8_t, int_least8_t, );
    TEST_CASE(int_least16_t_arr1, 1, int_least16_t, int_least16_t, );
    TEST_CASE(int_least16_t_arr2, 0, int_least16_t, int_least16_t, );
    TEST_CASE(int_least32_t_arr1, 1, int_least32_t, int_least32_t, );
    TEST_CASE(int_least32_t_arr2, 0, int_least32_t, int_least32_t, );
    TEST_CASE(int_least64_t_arr1, 1, int_least64_t, int_least64_t, );
    TEST_CASE(int_least64_t_arr2, 0, int_least64_t, int_least64_t, );
    TEST_CASE(intptr_t_arr1, 1, intptr_t, intptr_t, );
    TEST_CASE(intptr_t_arr2, 0, intptr_t, intptr_t, );
    TEST_CASE(intmax_t_arr1, 1, intmax_t, intmax_t, );
    TEST_CASE(intmax_t_arr2, 0, intmax_t, intmax_t, );
    TEST_CASE(uint8_t_arr1, 1, uint8_t, uint8_t, );
    TEST_CASE(uint8_t_arr2, 0, uint8_t, uint8_t, );
    TEST_CASE(uint16_t_arr1, 1, uint16_t, uint16_t, );
    TEST_CASE(uint16_t_arr2, 0, uint16_t, uint16_t, );
    TEST_CASE(uint32_t_arr1, 1, uint32_t, uint32_t, );
    TEST_CASE(uint32_t_arr2, 0, uint32_t, uint32_t, );
    TEST_CASE(uint64_t_arr1, 1, uint64_t, uint64_t, );
    TEST_CASE(uint64_t_arr2, 0, uint64_t, uint64_t, );
    TEST_CASE(uint_fast8_t_arr1, 1, uint_fast8_t, uint_fast8_t, );
    TEST_CASE(uint_fast8_t_arr2, 0, uint_fast8_t, uint_fast8_t, );
    TEST_CASE(uint_fast16_t_arr1, 1, uint_fast16_t, uint_fast16_t, );
    TEST_CASE(uint_fast16_t_arr2, 0, uint_fast16_t, uint_fast16_t, );
    TEST_CASE(uint_fast32_t_arr1, 1, uint_fast32_t, uint_fast32_t, );
    TEST_CASE(uint_fast32_t_arr2, 0, uint_fast32_t, uint_fast32_t, );
    TEST_CASE(uint_fast64_t_arr1, 1, uint_fast64_t, uint_fast64_t, );
    TEST_CASE(uint_fast64_t_arr2, 0, uint_fast64_t, uint_fast64_t, );
    TEST_CASE(uint_least8_t_arr1, 1, uint_least8_t, uint_least8_t, );
    TEST_CASE(uint_least8_t_arr2, 0, uint_least8_t, uint_least8_t, );
    TEST_CASE(uint_least16_t_arr1, 1, uint_least16_t, uint_least16_t, );
    TEST_CASE(uint_least16_t_arr2, 0, uint_least16_t, uint_least16_t, );
    TEST_CASE(uint_least32_t_arr1, 1, uint_least32_t, uint_least32_t, );
    TEST_CASE(uint_least32_t_arr2, 0, uint_least32_t, uint_least32_t, );
    TEST_CASE(uint_least64_t_arr1, 1, uint_least64_t, uint_least64_t, );
    TEST_CASE(uint_least64_t_arr2, 0, uint_least64_t, uint_least64_t, );
    TEST_CASE(uintptr_t_arr1, 1, uintptr_t, uintptr_t, );
    TEST_CASE(uintptr_t_arr2, 0, uintptr_t, uintptr_t, );
    TEST_CASE(uintmax_t_arr1, 1, uintmax_t, uintmax_t, );
    TEST_CASE(uintmax_t_arr2, 0, uintmax_t, uintmax_t, );
    TEST_CASE(size_t_arr1, 1, size_t, size_t, );
    TEST_CASE(size_t_arr2, 0, size_t, size_t, );
    TEST_CASE(wchar_t_arr1, 1, wchar_t, wchar_t, );
    TEST_CASE(wchar_t_arr2, 0, wchar_t, wchar_t, );

    if (TEST_STRUCTS) {
        TEST_CASE_S(node_arr1, 1, node, float, .float_);
        TEST_CASE_S(node_arr2, 0, node, float, .float_);
        TEST_CASE_S(node_arr1, 1, node, double, .double_);
        TEST_CASE_S(node_arr2, 0, node, double, .double_);
        TEST_CASE_S(node_arr1, 1, node, char, .char_);
        TEST_CASE_S(node_arr2, 0, node, char, .char_);
        TEST_CASE_S(node_arr1, 1, node, short, .short_);
        TEST_CASE_S(node_arr2, 0, node, short, .short_);
        TEST_CASE_S(node_arr1, 1, node, int, .int_);
        TEST_CASE_S(node_arr2, 0, node, int, .int_);
        TEST_CASE_S(node_arr1, 1, node, long, .long_);
        TEST_CASE_S(node_arr2, 0, node, long, .long_);
        TEST_CASE_S(node_arr1, 1, node, int8_t, .int8_t_);
        TEST_CASE_S(node_arr2, 0, node, int8_t, .int8_t_);
        TEST_CASE_S(node_arr1, 1, node, int16_t, .int16_t_);
        TEST_CASE_S(node_arr2, 0, node, int16_t, .int16_t_);
        TEST_CASE_S(node_arr1, 1, node, int32_t, .int32_t_);
        TEST_CASE_S(node_arr2, 0, node, int32_t, .int32_t_);
        TEST_CASE_S(node_arr1, 1, node, int64_t, .int64_t_);
        TEST_CASE_S(node_arr2, 0, node, int64_t, .int64_t_);
        TEST_CASE_S(node_arr1, 1, node, int_fast8_t, .int_fast8_t_);
        TEST_CASE_S(node_arr2, 0, node, int_fast8_t, .int_fast8_t_);
        TEST_CASE_S(node_arr1, 1, node, int_fast16_t, .int_fast16_t_);
        TEST_CASE_S(node_arr2, 0, node, int_fast16_t, .int_fast16_t_);
        TEST_CASE_S(node_arr1, 1, node, int_fast32_t, .int_fast32_t_);
        TEST_CASE_S(node_arr2, 0, node, int_fast32_t, .int_fast32_t_);
        TEST_CASE_S(node_arr1, 1, node, int_fast64_t, .int_fast64_t_);
        TEST_CASE_S(node_arr2, 0, node, int_fast64_t, .int_fast64_t_);
        TEST_CASE_S(node_arr1, 1, node, int_least8_t, .int_least8_t_);
        TEST_CASE_S(node_arr2, 0, node, int_least8_t, .int_least8_t_);
        TEST_CASE_S(node_arr1, 1, node, int_least16_t, .int_least16_t_);
        TEST_CASE_S(node_arr2, 0, node, int_least16_t, .int_least16_t_);
        TEST_CASE_S(node_arr1, 1, node, int_least32_t, .int_least32_t_);
        TEST_CASE_S(node_arr2, 0, node, int_least32_t, .int_least32_t_);
        TEST_CASE_S(node_arr1, 1, node, int_least64_t, .int_least64_t_);
        TEST_CASE_S(node_arr2, 0, node, int_least64_t, .int_least64_t_);
        TEST_CASE_S(node_arr1, 1, node, intptr_t, .intptr_t_);
        TEST_CASE_S(node_arr2, 0, node, intptr_t, .intptr_t_);
        TEST_CASE_S(node_arr1, 1, node, intmax_t, .intmax_t_);
        TEST_CASE_S(node_arr2, 0, node, intmax_t, .intmax_t_);
        TEST_CASE_S(node_arr1, 1, node, uint8_t, .uint8_t_);
        TEST_CASE_S(node_arr2, 0, node, uint8_t, .uint8_t_);
        TEST_CASE_S(node_arr1, 1, node, uint16_t, .uint16_t_);
        TEST_CASE_S(node_arr2, 0, node, uint16_t, .uint16_t_);
        TEST_CASE_S(node_arr1, 1, node, uint32_t, .uint32_t_);
        TEST_CASE_S(node_arr2, 0, node, uint32_t, .uint32_t_);
        TEST_CASE_S(node_arr1, 1, node, uint64_t, .uint64_t_);
        TEST_CASE_S(node_arr2, 0, node, uint64_t, .uint64_t_);
        TEST_CASE_S(node_arr1, 1, node, uint_fast8_t, .uint_fast8_t_);
        TEST_CASE_S(node_arr2, 0, node, uint_fast8_t, .uint_fast8_t_);
        TEST_CASE_S(node_arr1, 1, node, uint_fast16_t, .uint_fast16_t_);
        TEST_CASE_S(node_arr2, 0, node, uint_fast16_t, .uint_fast16_t_);
        TEST_CASE_S(node_arr1, 1, node, uint_fast32_t, .uint_fast32_t_);
        TEST_CASE_S(node_arr2, 0, node, uint_fast32_t, .uint_fast32_t_);
        TEST_CASE_S(node_arr1, 1, node, uint_fast64_t, .uint_fast64_t_);
        TEST_CASE_S(node_arr2, 0, node, uint_fast64_t, .uint_fast64_t_);
        TEST_CASE_S(node_arr1, 1, node, uint_least8_t, .uint_least8_t_);
        TEST_CASE_S(node_arr2, 0, node, uint_least8_t, .uint_least8_t_);
        TEST_CASE_S(node_arr1, 1, node, uint_least16_t, .uint_least16_t_);
        TEST_CASE_S(node_arr2, 0, node, uint_least16_t, .uint_least16_t_);
        TEST_CASE_S(node_arr1, 1, node, uint_least32_t, .uint_least32_t_);
        TEST_CASE_S(node_arr2, 0, node, uint_least32_t, .uint_least32_t_);
        TEST_CASE_S(node_arr1, 1, node, uint_least64_t, .uint_least64_t_);
        TEST_CASE_S(node_arr2, 0, node, uint_least64_t, .uint_least64_t_);
        TEST_CASE_S(node_arr1, 1, node, uintptr_t, .uintptr_t_);
        TEST_CASE_S(node_arr2, 0, node, uintptr_t, .uintptr_t_);
        TEST_CASE_S(node_arr1, 1, node, uintmax_t, .uintmax_t_);
        TEST_CASE_S(node_arr2, 0, node, uintmax_t, .uintmax_t_);
        TEST_CASE_S(node_arr1, 1, node, uintptr_t, .size_t_);
        TEST_CASE_S(node_arr2, 0, node, uintptr_t, .size_t_);
        TEST_CASE_S(node_arr1, 1, node, uintmax_t, .wchar_t_);
        TEST_CASE_S(node_arr2, 0, node, uintmax_t, .wchar_t_);
    }
    printf("Finished: %d / %d test cases passed.\n", passed_tests, total_tests);

    /* free */
    printf("Cleaning up...");
    if (TEST_STRUCTS) {
        free(node_arr1);
        free(node_arr2);
    }
    free(float_arr1);
    free(float_arr2);
    free(double_arr1);
    free(double_arr2);
    free(char_arr1);
    free(char_arr2);
    free(short_arr1);
    free(short_arr2);
    free(int_arr1);
    free(int_arr2);
    free(long_arr1);
    free(long_arr2);
    free(int8_t_arr1);
    free(int8_t_arr2);
    free(int16_t_arr1);
    free(int16_t_arr2);
    free(int32_t_arr1);
    free(int32_t_arr2);
    free(int64_t_arr1);
    free(int64_t_arr2);
    free(int_fast8_t_arr1);
    free(int_fast8_t_arr2);
    free(int_fast16_t_arr1);
    free(int_fast16_t_arr2);
    free(int_fast32_t_arr1);
    free(int_fast32_t_arr2);
    free(int_fast64_t_arr1);
    free(int_fast64_t_arr2);
    free(int_least8_t_arr1);
    free(int_least8_t_arr2);
    free(int_least16_t_arr1);
    free(int_least16_t_arr2);
    free(int_least32_t_arr1);
    free(int_least32_t_arr2);
    free(int_least64_t_arr1);
    free(int_least64_t_arr2);
    free(intptr_t_arr1);
    free(intptr_t_arr2);
    free(intmax_t_arr1);
    free(intmax_t_arr2);
    free(uint8_t_arr1);
    free(uint8_t_arr2);
    free(uint16_t_arr1);
    free(uint16_t_arr2);
    free(uint32_t_arr1);
    free(uint32_t_arr2);
    free(uint64_t_arr1);
    free(uint64_t_arr2);
    free(uint_fast8_t_arr1);
    free(uint_fast8_t_arr2);
    free(uint_fast16_t_arr1);
    free(uint_fast16_t_arr2);
    free(uint_fast32_t_arr1);
    free(uint_fast32_t_arr2);
    free(uint_fast64_t_arr1);
    free(uint_fast64_t_arr2);
    free(uint_least8_t_arr1);
    free(uint_least8_t_arr2);
    free(uint_least16_t_arr1);
    free(uint_least16_t_arr2);
    free(uint_least32_t_arr1);
    free(uint_least32_t_arr2);
    free(uint_least64_t_arr1);
    free(uint_least64_t_arr2);
    free(uintptr_t_arr1);
    free(uintptr_t_arr2);
    free(uintmax_t_arr1);
    free(uintmax_t_arr2);
    free(size_t_arr1);
    free(size_t_arr2);
    free(wchar_t_arr1);
    free(wchar_t_arr2);
    printf("Done!\nExiting!\n");

    return 0;
}


float rand_float() {
    return (float)rand() / (float)RAND_MAX;
}

double rand_double() {
    return (double)rand() / (double)RAND_MAX;
}
