#include <SFML/Graphics.hpp>
#include <cassert>
#include <string>


template<typename Resource, typename Identifier>
class ResourceHolder
{
private:

	std::map<Identifier,
		std::unique_ptr<sf::Texture>>	mResourceMap;
private:

	void insertResource(Identifier id, std::unique_ptr<Resource> resource);

public:

	void load(Identifier id, const std::string& filename);
	template <typename Parameter>
	void load(Identifier id, const std::string& filename, const Parameter& secondParam);

	Resource& get(Identifier id);
	const Resource& get(Identifier id) const;

};
#include "ResourceHolder.inl"

