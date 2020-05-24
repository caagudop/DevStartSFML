#include <SFML\System\NonCopyable.hpp>
#include <SFML\Graphics\RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <array>
#include "Aircraft.hpp"
#include "SceneNode.hpp"

#include "ResourceHolder.hpp"
#include "SpriteNode.hpp"

#pragma once
class World: private sf::NonCopyable
{
public:
	explicit	World(sf::RenderWindow& window);
	void	    update(sf::Time dt);
	void		draw();


private:
	void		loadTextures();
	void		buildScene();


private:
	enum Layer
	{
		Background,
		Air,
		LayerCount
	};


private:
	sf::RenderWindow& mWindow;
	sf::View							mWorldView;
	TextureHolder						mTextures;

	SceneNode							mSceneGraph;
	std::array<SceneNode*, LayerCount>	mSceneLayers;

	sf::FloatRect						mWorldBounds;
	sf::Vector2f						mSpawnPosition;
	float								mScrollSpeed;
	Aircraft* mPlayerAircraft;
};

