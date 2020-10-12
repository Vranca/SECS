#pragma once

#ifdef _WIN64
#define uint64_t Entity
#define MAX_POOL_SIZE 18446744073709551615
#elif _WIN32
#define uint32_t Entity
#define MAX_POOL_SIZE 9223372036854775807
#endif
