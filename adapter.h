#ifndef ADAPTER_H_
#define ADAPTER_H_

#include "antenna.h"
#include "antennatype.h"

#include <vector>

class Adapter {
public:
	Adapter(
		const unsigned char& id,
		const unsigned char& frontendId,
		const Antenna& antenna,
		const std::vector<AntennaType>& compat
	);

	unsigned char const& getId() const;
	unsigned char const& getFrontendId() const;
	Antenna const& getAntenna() const;
	std::vector<AntennaType> const& getAntennaTypeCompat() const;

	bool isCompatible(const AntennaType& at) const;

private:
	unsigned char id_;
	unsigned char frontendId_;
	Antenna antenna_;
	std::vector<AntennaType> compat_;
};

#endif /* ADAPTER_H_ */
