#ifndef OBJECT_TRANSPORT_PROXY_H
#define OBJECT_TRANSPORT_PROXY_H
#include <vector>

#include "singleton/singleton.h"
#include "common_global.h"

namespace transport 
{
	class COMMON_EXPORT_API ExtendedObjectTransportProxy : public common::Singleton<ExtendedObjectTransportProxy>
	{
	public:
		ExtendedObjectTransportProxy();
		~ExtendedObjectTransportProxy();
		std::vector<std::string> buffer;
	private:
	};

	class COMMON_EXPORT_API RegisteredObjectTransportProxy : public common::Singleton<RegisteredObjectTransportProxy>
	{
	public:
		RegisteredObjectTransportProxy();
		~RegisteredObjectTransportProxy();
		std::vector<std::string> buffer;

	private:
	};
}

#endif // !OBJECT_TRANSPORT_PROXY_H
