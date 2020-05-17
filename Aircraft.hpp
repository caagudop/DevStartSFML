#pragma once
#include "Entity.hpp"
#include <SFML\Graphics\Sprite.hpp>
#include "ResourceHolder.hpp"

typedef ResourceHolder<sf::Texture, Textures::ID> TextureHolder;

class Aircraft : public Entity
{
	public:
		enum Type
		{
			Eagle, 
			Raptor,
		};

	public:
		explicit Aircraft(Type type, const TextureHolder& textures);
		virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

	private:
		Type mType;
		sf::Sprite mSprite;
};

