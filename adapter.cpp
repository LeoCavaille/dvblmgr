#include "adapter.h"

Adapter::Adapter(unsigned char id, unsigned char frontendId) : id_(id), frontendId_(frontendId)
{}

unsigned char const& Adapter::getId() const
{
	return id_;
}

unsigned char const& Adapter::getFrontendId() const
{
	return frontendId_;
}
