#include "adapter.h"

Adapter::Adapter(
		const unsigned char& id,
		const unsigned char& frontendId,
		const Antenna& antenna,
		const std::vector<AntennaType>& compat) :
    id_(id),
    frontendId_(frontendId),
    antenna_(antenna),
    compat_(compat)
{}

unsigned char const& Adapter::getId() const
{
	return id_;
}

unsigned char const& Adapter::getFrontendId() const
{
	return frontendId_;
}
