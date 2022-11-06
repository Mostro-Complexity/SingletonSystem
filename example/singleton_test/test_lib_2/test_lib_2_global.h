#ifndef TEST_LIB_2_GLOBAL_H
#define TEST_LIB_2_GLOBAL_H

#ifdef TEST_LIB_2_EXPORT
#define TEST_LIB_2_EXPORT_API __declspec(dllexport)
#else
#define TEST_LIB_2_EXPORT_API __declspec(dllimport)
#endif

#endif // !TEST_LIB_2_GLOBAL_H

