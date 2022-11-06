#ifndef COMMON_GLOBAL_H
#define COMMON_GLOBAL_H

#ifdef COMMON_EXPORT
#define COMMON_EXPORT_API __declspec(dllexport)
#else
#define COMMON_EXPORT_API __declspec(dllimport)
#endif

#endif