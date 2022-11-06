#include "test_lib_1_header.h"

#include "transport/object_transport_proxy.h"

void lib_1_test_foo(const std::string& text) 
{
	auto &proxy = transport::ExtendedObjectTransportProxy::Instance();
	proxy.buffer.emplace_back(text);
}