#ifndef TEST_LIB_1_GLOBAL_H
#define TEST_LIB_1_GLOBAL_H

#ifdef TEST_LIB_1_EXPORT
#define TEST_LIB_1_EXPORT_API __declspec(dllexport)
#else
#define TEST_LIB_1_EXPORT_API __declspec(dllimport)
#endif

#endif // !TEST_LIB_1_GLOBAL_H

