#ifndef RSORT_H
#define RSORT_H

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define T_UNSIG_R__(T) T_UNSIG_R__##T
#define T_UNSIG_R__float 0
#define T_UNSIG_R__double 0
#define T_UNSIG_R__char 0
#define T_UNSIG_R__short 0
#define T_UNSIG_R__int 0
#define T_UNSIG_R__long 0
#define T_UNSIG_R__int8_t 0
#define T_UNSIG_R__int16_t 0
#define T_UNSIG_R__int32_t 0
#define T_UNSIG_R__int64_t 0
#define T_UNSIG_R__int_fast8_t 0
#define T_UNSIG_R__int_fast16_t 0
#define T_UNSIG_R__int_fast32_t 0
#define T_UNSIG_R__int_fast64_t 0
#define T_UNSIG_R__int_least8_t 0
#define T_UNSIG_R__int_least16_t 0
#define T_UNSIG_R__int_least32_t 0
#define T_UNSIG_R__int_least64_t 0
#define T_UNSIG_R__intptr_t 0
#define T_UNSIG_R__intmax_t 0
#define T_UNSIG_R__uint8_t 1
#define T_UNSIG_R__uint16_t 1
#define T_UNSIG_R__uint32_t 1
#define T_UNSIG_R__uint64_t 1
#define T_UNSIG_R__uint_fast8_t 1
#define T_UNSIG_R__uint_fast16_t 1
#define T_UNSIG_R__uint_fast32_t 1
#define T_UNSIG_R__uint_fast64_t 1
#define T_UNSIG_R__uint_least8_t 1
#define T_UNSIG_R__uint_least16_t 1
#define T_UNSIG_R__uint_least32_t 1
#define T_UNSIG_R__uint_least64_t 1
#define T_UNSIG_R__uintptr_t 1
#define T_UNSIG_R__uintmax_t 1
#define T_UNSIG_R__size_t 1
#define T_UNSIG_R__wchar_t 0

#define GET_EL_NOUB_R__(ARR, MEM, MEM_T) GET_EL_NOUB_R__##MEM_T(ARR, MEM, MEM_T)
#define GET_EL_NOUB_R__float(ARR, MEM, MEM_T) int32_t el; memcpy(&el, &ARR[i]MEM, sizeof(float));
#define GET_EL_NOUB_R__double(ARR, MEM, MEM_T) int64_t el; memcpy(&el, &ARR[i]MEM, sizeof(double));
#define GET_EL_NOUB_R__char(ARR, MEM, MEM_T) MEM_T el = ARR[i]MEM;
#define GET_EL_NOUB_R__short(ARR, MEM, MEM_T) MEM_T el = ARR[i]MEM;
#define GET_EL_NOUB_R__int(ARR, MEM, MEM_T) MEM_T el = ARR[i]MEM;
#define GET_EL_NOUB_R__long(ARR, MEM, MEM_T) MEM_T el = ARR[i]MEM;
#define GET_EL_NOUB_R__int8_t(ARR, MEM, MEM_T) MEM_T el = ARR[i]MEM;
#define GET_EL_NOUB_R__int16_t(ARR, MEM, MEM_T) MEM_T el = ARR[i]MEM;
#define GET_EL_NOUB_R__int32_t(ARR, MEM, MEM_T) MEM_T el = ARR[i]MEM;
#define GET_EL_NOUB_R__int64_t(ARR, MEM, MEM_T) MEM_T el = ARR[i]MEM;
#define GET_EL_NOUB_R__int_fast8_t(ARR, MEM, MEM_T) MEM_T el = ARR[i]MEM;
#define GET_EL_NOUB_R__int_fast16_t(ARR, MEM, MEM_T) MEM_T el = ARR[i]MEM;
#define GET_EL_NOUB_R__int_fast32_t(ARR, MEM, MEM_T) MEM_T el = ARR[i]MEM;
#define GET_EL_NOUB_R__int_fast64_t(ARR, MEM, MEM_T) MEM_T el = ARR[i]MEM;
#define GET_EL_NOUB_R__int_least8_t(ARR, MEM, MEM_T) MEM_T el = ARR[i]MEM;
#define GET_EL_NOUB_R__int_least16_t(ARR, MEM, MEM_T) MEM_T el = ARR[i]MEM;
#define GET_EL_NOUB_R__int_least32_t(ARR, MEM, MEM_T) MEM_T el = ARR[i]MEM;
#define GET_EL_NOUB_R__int_least64_t(ARR, MEM, MEM_T) MEM_T el = ARR[i]MEM;
#define GET_EL_NOUB_R__intptr_t(ARR, MEM, MEM_T) MEM_T el = ARR[i]MEM;
#define GET_EL_NOUB_R__intmax_t(ARR, MEM, MEM_T) MEM_T el = ARR[i]MEM;
#define GET_EL_NOUB_R__uint8_t(ARR, MEM, MEM_T) MEM_T el = ARR[i]MEM;
#define GET_EL_NOUB_R__uint16_t(ARR, MEM, MEM_T) MEM_T el = ARR[i]MEM;
#define GET_EL_NOUB_R__uint32_t(ARR, MEM, MEM_T) MEM_T el = ARR[i]MEM;
#define GET_EL_NOUB_R__uint64_t(ARR, MEM, MEM_T) MEM_T el = ARR[i]MEM;
#define GET_EL_NOUB_R__uint_fast8_t(ARR, MEM, MEM_T) MEM_T el = ARR[i]MEM;
#define GET_EL_NOUB_R__uint_fast16_t(ARR, MEM, MEM_T) MEM_T el = ARR[i]MEM;
#define GET_EL_NOUB_R__uint_fast32_t(ARR, MEM, MEM_T) MEM_T el = ARR[i]MEM;
#define GET_EL_NOUB_R__uint_fast64_t(ARR, MEM, MEM_T) MEM_T el = ARR[i]MEM;
#define GET_EL_NOUB_R__uint_least8_t(ARR, MEM, MEM_T) MEM_T el = ARR[i]MEM;
#define GET_EL_NOUB_R__uint_least16_t(ARR, MEM, MEM_T) MEM_T el = ARR[i]MEM;
#define GET_EL_NOUB_R__uint_least32_t(ARR, MEM, MEM_T) MEM_T el = ARR[i]MEM;
#define GET_EL_NOUB_R__uint_least64_t(ARR, MEM, MEM_T) MEM_T el = ARR[i]MEM;
#define GET_EL_NOUB_R__uintptr_t(ARR, MEM, MEM_T) MEM_T el = ARR[i]MEM;
#define GET_EL_NOUB_R__uintmax_t(ARR, MEM, MEM_T) MEM_T el = ARR[i]MEM;
#define GET_EL_NOUB_R__size_t(ARR, MEM, MEM_T) MEM_T el = ARR[i]MEM;
#define GET_EL_NOUB_R__wchar_t(ARR, MEM, MEM_T) MEM_T el = ARR[i]MEM;


#define IS_FLOATING_R__(MEM_T) (!strcmp("float",#MEM_T) || !strcmp("double", #MEM_T))
#define LAST_BYTE_R__(MEM_T) ((sizeof(MEM_T) << 3) - 8)
#define SWAP_ARRS_R__(ARR, ARR_T) do {  \
    ARR_T *temp = h;                    \
    h = ARR;                            \
    ARR = temp;                         \
} while(0);

#define PTR_ASS_B_R__(START, S_, END, I_INC) do {   \
    for (i = START; i S_ END; s+=bucket[I_INC])     \
        pointers[i] = s;                            \
} while(0) 


/* aliases */
#define RADIX_SORT_STRUCT(ARR, N, ASC, ARR_T, MEM_T, MEM) RADIX_SORT_CORE(ARR, N, ASC, ARR_T, MEM_T, .MEM)
#define RADIX_SORT(ARR, N, ASC, ARR_T) RADIX_SORT_CORE(ARR, N, ASC, ARR_T, ARR_T, )


/* main macro */
#define RADIX_SORT_CORE(ARR, N, ASC, ARR_T, MEM_T, MEM) do {            \
    ARR_T *h = (ARR_T *)malloc(N * sizeof(*h));                         \
    ARR_T *pointers[256];                                               \
    ARR_T *s;                                                           \
    int32_t swap = 0;                                                   \
    int32_t mbit;                                                       \
    for (mbit = 0; mbit < sizeof(MEM_T) << 3; mbit += 8) {              \
        if (mbit > 0) {                                                 \
            SWAP_ARRS_R__(ARR, ARR_T);                                  \
        }                                                               \
        int64_t bucket[256] = {0};                                      \
        int64_t i;                                                      \
        for (i = 0; i < N; ++i) {                                       \
            GET_EL_NOUB_R__(ARR, MEM, MEM_T);                           \
            ++bucket[(el >> mbit) & 0xFF];                              \
        }                                                               \
        s = h;                                                          \
        int32_t next = 0;                                               \
        for (i = 0; i < 256; ++i) {                                     \
            if(bucket[i] == N) {                                        \
                SWAP_ARRS_R__(ARR, ARR_T);                              \
                next = 1;                                               \
                break;                                                  \
            }                                                           \
        }                                                               \
        if (next) {                                                     \
            continue;                                                   \
        }                                                               \
        swap = 1 - swap;
        if (IS_FLOATING_R__(MEM_T)) {                                   \
            if (mbit == LAST_BYTE_R__(MEM_T)) {                         \
                if (ASC) {                                              \
                    PTR_ASS_B_R__(255, >=, 128, --i);                   \
                    PTR_ASS_B_R__(0, <, 128, i++);                      \
                } else {                                                \
                    PTR_ASS_B_R__(127, >=, 0, i--);                     \
                    s += bucket[128];                                   \
                    PTR_ASS_B_R__(128, <, 255, ++i);                    \
                }                                                       \
            } else {                                                    \
                if (ASC) {                                              \
                    PTR_ASS_B_R__(0, <, 256, i++);                      \
                } else {                                                \
                    PTR_ASS_B_R__(255, >=, 0, i--);                     \
                }                                                       \
            }                                                           \
            if(mbit != LAST_BYTE_R__(MEM_T)) {                          \
                for (i = 0; i < N; ++i) {                               \
                    GET_EL_NOUB_R__(ARR, MEM, MEM_T);                   \
                    *pointers[(el >> mbit) & 0xFF]++ = ARR[i];          \
                }                                                       \
            } else {                                                    \
                for (i = 0; i < N; ++i) {                               \
                    GET_EL_NOUB_R__(ARR, MEM, MEM_T);                   \
                    int32_t r = (el >> LAST_BYTE_R__(MEM_T)) & 0xFF;    \
                    if (r < 128) {                                      \
                        *pointers[r]++ = ARR[i];                        \
                    } else {                                            \
                        *--pointers[r] = ARR[i];                        \
                    }                                                   \
                }                                                       \
            }                                                           \
        } else if (!T_UNSIG_R__(MEM_T)) {                               \
            if(mbit == LAST_BYTE_R__(MEM_T)) {                          \
                if (ASC) {                                              \
                    PTR_ASS_B_R__(128, <=, 255, i++);                   \
                    PTR_ASS_B_R__(0, <, 128, i++);                      \
                } else {                                                \
                    PTR_ASS_B_R__(127, >=, 0, i--);                     \
                    PTR_ASS_B_R__(255, >=, 128, i--);                   \
                }                                                       \
            } else {                                                    \
                if (ASC) {                                              \
                    PTR_ASS_B_R__(0, <=, 255, i++);                     \
                } else {                                                \
                    PTR_ASS_B_R__(255, >=, 0, i--);                     \
                }                                                       \
            }                                                           \
            for (i = 0; i < N; ++i) {                                   \
                GET_EL_NOUB_R__(ARR, MEM, MEM_T);                       \
                *pointers[(el >> mbit) & 0xFF]++ = ARR[i];              \
            }                                                           \
        } else {                                                        \
            if (ASC) {                                                  \
                PTR_ASS_B_R__(0, <=, 255, i++);                         \
            } else {                                                    \
                PTR_ASS_B_R__(255, >=, 0, i--);                         \
            }                                                           \
            for (i = 0; i < N; ++i) {                                   \
                GET_EL_NOUB_R__(ARR, MEM, MEM_T);                       \
                *pointers[(el >> mbit) & 0xFF]++ = ARR[i];              \
            }                                                           \
        }                                                               \
    }                                                                   \
    if (swap) {                                                         \
        SWAP_ARRS_R__(ARR, ARR_T);                                      \
    } else {                                                            \
        memcpy(ARR, h, sizeof(ARR_T) * N);                              \
    }                                                                   \
    free(h);                                                            \
} while(0)


#endif