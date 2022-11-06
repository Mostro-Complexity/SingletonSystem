#ifndef SINGLETON_H
#define SINGLETON_H

#include <mutex>
#include "common_global.h"

namespace common
{
    template <typename T>
    class COMMON_EXPORT_API Singleton
    {
    public:
        static T& Instance();
        Singleton(const Singleton&) = delete;
        Singleton& operator=(const Singleton) = delete;

    protected:
        Singleton() = default;
    };

    template <typename T>
    inline T& Singleton<T>::Instance()
    {
        static const std::unique_ptr<T> Instance{ new T{} };
        return *Instance;
    }
}  // namespace common

#endif