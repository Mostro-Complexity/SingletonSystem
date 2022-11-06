#ifndef SINGLETON_REGISTRY_H
#define SINGLETON_REGISTRY_H
#include <functional>
#include <unordered_map>

#include "singleton/singleton.h"


namespace common
{
    class SingletonRegistry : public Singleton<SingletonRegistry>
    {
    public:
        explicit SingletonRegistry() {}

        template <typename T>
        T& Register()
        {
            if (type_names_.find(typeid(T)) != type_names_.end())
            {
                return *static_cast<T*>(type_names_[typeid(T)]);
            }
            type_names_[typeid(T)] = new T;
            return *static_cast<T*>(type_names_[typeid(T)]);
        }

        template <typename T>
        T& Register(T* t)
        {
            if (type_names_.find(typeid(T)) != type_names_.end())
            {
                return *static_cast<T*>(type_names_[typeid(T)]);
            }
            type_names_[typeid(T)] = t;
            return *t;
        }

        using TypeInfoRef = std::reference_wrapper<const std::type_info>;

        struct Hasher
        {
            std::size_t operator()(TypeInfoRef code) const
            {
                return code.get().hash_code();
            }
        };

        struct EqualTo
        {
            bool operator()(TypeInfoRef lhs, TypeInfoRef rhs) const
            {
                return lhs.get() == rhs.get();
            }
        };

    private:
        std::unordered_map<TypeInfoRef, void*, Hasher, EqualTo> type_names_;
    };
}  // namespace common
#endif