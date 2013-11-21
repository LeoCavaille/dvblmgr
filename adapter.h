class Adapter {
public:
	Adapter(unsigned char id);
	unsigned char const& getId() const;
private:
	unsigned char id_;
};