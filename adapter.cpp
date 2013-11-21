#include "adapter.h"

Adapter::Adapter(unsigned char id) : id_(id)
{}

unsigned char const& Adapter::getId() const
{
	return id_;
}