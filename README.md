# Multitype-Radix-Sort
A high-performance C alternative to sort large arrays with support for most standard C types and all types defined in stdint.h

## Background

Currently, comparison-based sorting is still king across many libraries and programming languages.
However, it is proven that any comparison-based sorting algorithm requires at least nlog(n) comparisons to 
sort a given array.<br>
Bucket-based algorithms such as radix sort, on the other hand, do not require comparisons at all and are instead based on the idea that we can sort an array by iteratively assigning buckets to each element (according to a subset of itself) and reorder the whole array based on this division.
With this paradigm, it is possible to break the nlog(n) time barrier for sorting.<br>


Many people make the case against radix sort, arguing that comparison-based algorithms such as quicksorts (or variants thereof) are both "fast enough", easy to implement, and works for all types.<br>
Ease of implementation is subjective so I will not dwell too much into it ... but programmer aside, doesn't it get a little annoying to have to always write your own comparison functions for each type for something like qsort() in C?<br>
The argument that comparison sorts always work for all types is, in fact, the strongest point against radix sort. <br>
While it is true that the way bucket assigning works for radix sort is dependent on the representation of the data, it is also true that, in essence, there are only three different bit representations to tackle: floating point, unsigned and signed. <br>
Besides, C has these dangerous things called macros that can either make you shoot yourself in the foot or make some real magic happen. <br>
Regarding speed, saying that quicksort is "fast enough" as an argument is ... well ... cute.<br>


## Description

This repo provides a radix sort implementation that accommodates all standard (one-worded) C types and all types defined in stdint.h, sorting all these types in linear time.
Radix sort is a **stable** sorting method, meaning every two numbers with the same value appear in the same order in the sorted output as they appear in the input.


The algorithm itself is a **LSD** (least significant digit) radix sort variant with **base 256** and some minor optimizations on top, thus sorting one byte of data (over the entire array) at a time.<br>
The function is a macro written in ANSI C (C89).


## Features

 - Support for 36 types, including every standard **one-worded C type** as well as all types from **stdint.h** (see list below).
 - Support for **structure sorting** (as long as the member to sort corresponds to one of the supported types).
 - Parameterized ascending and descending sorting.
 - Backwards compatible (written in **ANSI C**, compiled with the -std=c89 flag).
 - Speed is significantly better than C's inlined qsort(). Expected speedups can easily reach about one order of magnitude. For instance, sorting an array with 10M elements is about 10x faster `int` types, slighly more for smaller types (`chars` are more than 70x faster) and less for larger types (`doubles` are the slowest at about 4x faster). This was tested in my local desktop computer (Intel® Core™ i7-6700 8MB cache with 16GB(2x8) RAM @2666Mhz).
 - No pointer dereferencing for floating-point conversions (so no UB) and no -Wall warnings for the macro expansion of the expected parameterizations.
 - No macro namespace cluttering -  intricate names and `_R__` suffix at the end of each of the helper macros 

### Supported types:

#### Floating point types:
 - float
 - double

#### Signed types:
 - char
 - short
 - int
 - long
 - int8_t 
 - int16_t
 - int32_t
 - int64_t
 - int_fast8_t
 - int_fast16_t
 - int_fast32_t
 - int_fast64_t
 - int_least8_t
 - int_least16_t
 - int_least32_t
 - int_least64_t
 - intptr_t
 - intmax_t
 - wchar_t

#### Unsigned Types:
 - uint8_t
 - uint16_t
 - uint32_t
 - uint64_t
 - uint_fast8_t
 - uint_fast16_t
 - uint_fast32_t
 - uint_fast64_t
 - uint_least8_t
 - uint_least16_t
 - uint_least32_t
 - uint_least64_t
 - uintptr_t
 - uintmax_t
 - size_t


## How to use

There are two aliases for normal array sorting and for sorting arrays of structures.
The macro that these two aliases call is the same and so is the code, but this mechanism eases up the parameterization for the case of sorting standard arrays.
Just include `#include "rsort.h"` in your program (can be inserted in any order).

For standard arrays:<br>
```c
RADIX_SORT(ARR, N, ASC, ARR_T);
```

For arrays of structures:<br>
```c
RADIX_SORT_STRUCT(ARR, N, ASC, ARR_T, MEM_T, MEM);
```

Where:

 - `ARR` - Name of the array.
 - `N` - Number of elements of the array.
 - `ASC` - `1` to sort in ascending order, `0` for descending.
 - `ARR_T` - Type of the array. For standard arrays this is one of the supported types, for structs, it is the type of the structure.
 - `MEM_T` - Type of the structure member to sort from (one of the standard types).
 - `MEM` - Name of the member in the array to sort from. (the actual name, no strings and no point; ex: `age`, for the field within struct `typedef strcut node { int age; int a; } node;`).


## Example

Short example:

```c
#include "rsort.h"

typedef strcut node {
	int age;
	int a;
} node;

int main() {
	float *f_arr;
	node *n_arr;
	int size;
	// array allocs, inits, remaining code, etc...
	
	RADIX_SORT(f_arr, size, 1, float);
	RADIX_SORT_STRUCT(n_arr, size, 0, node, int, age);

	return 0;
}
```

A testing program `radix_final_test.c` is also provided to test the speed and correctness of all supported types in your machine.

Compiled with (Linux): `gcc -std=c89 -Wall -Ofast radix_final_test.c -o radix`<br>
Best performance results were verified for `-Ofast` when compared to `-O3`, even though the difference is not great.


## Limitations

- Because of the macro expansion mechanics, it is not possible to support rather common types such as `unisgned long long` or `long double`. This is really a limitation of using macros, not so much of the actual algorithm.
- Because there is a need to arrange 256 buckets in each iteration, this algorithm might not be as qsort() for smaller arrays. The turning point should still be for relatively small sizes, nonetheless (typically for arrays of 100 to 1000 elements, depending on the machine).
- It is assumed that a float is no larger than 4 bytes and that a double is no larger than 8 bytes (possibly some problems in some weird system(?)).
- This implementation follows an  **out-of-place**  approach, meaning it uses a helper array to sort the original array, adding some memory overhead that can be critical for memory sensitive applications.
