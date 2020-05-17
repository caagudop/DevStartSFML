#pragma once
#include <vector>
#include <memory>
#include <SFML\Graphics\Transformable.hpp>
#include <SFML\Graphics\Drawable.hpp>
#include <SFML\Graphics\RenderStates.hpp>
#include <SFML\System\NonCopyable.hpp>
#include <SFML\System\Time.hpp>

class SceneNode: public sf::Transformable, public sf::Drawable, private sf::NonCopyable
{
	public:
		typedef std::unique_ptr<SceneNode> Ptr;
	
	public:
								SceneNode();
		void					update(sf::Time dt);
		void					attachChild(Ptr child);
		Ptr						detachChild(const SceneNode& node);

	private:

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
		virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
		void drawChildren(sf::RenderTarget& target, sf::RenderStates states) const;

		virtual void updateCurrent(sf::Time dt);
		void updateChildren(sf::Time dt);

		sf::Vector2f getWorldPosition() const;

		sf::Transform getWorldTransform() const;

	private:
		std::vector<Ptr> mChildren;
		SceneNode* mParent;

};

