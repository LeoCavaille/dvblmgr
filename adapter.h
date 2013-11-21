class Adapter {
public:
	Adapter(unsigned char id, unsigned char frontendId);

	unsigned char const& getId() const;
	unsigned char const& getFrontendId() const;

private:
	unsigned char id_;
	unsigned char frontendId_;
};
