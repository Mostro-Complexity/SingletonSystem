// SingletonSystem.cpp: 定义应用程序的入口点。
//

#include "singleton_system.h"
#include "test_lib_1/test_lib_1_header.h"
#include "test_lib_2/test_lib_2_header.h"
#include "transport/object_transport_proxy.h"
int main()
{
	lib_1_test_foo("test1");
	lib_2_test_foo("test2");
	auto& proxy = transport::ExtendedObjectTransportProxy::Instance();
	for (auto i : proxy.buffer)
	{
		std::cout << i << std::endl;
	}
	return 0;
}
