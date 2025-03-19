
#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <cstdint>
# include <string>

struct Data{
	std::string content = "hello void";
};

class Serializer {
	private:
		Serializer() = delete;
		Serializer(Serializer const& other) = delete;
		Serializer& operator=(Serializer const& serializer) = delete;
		~Serializer() = delete;
	public:
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};

#endif