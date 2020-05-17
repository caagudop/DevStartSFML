#include <SFML/Graphics.hpp>

class Game {
public:
	Game();
	void run();
private:
	void processEvents();
	void update(sf::Time deltaTime);
	void render();

	void updateStatistics(sf::Time elapsedTime);
	void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);

private:

	static const float		PlayerSpeed;
	static const sf::Time	TimePerFrame;

	sf::RenderWindow mWindow;
	sf::Font		mFont;
	sf::Sprite		landscape;
	sf::Sprite		airplane;
	sf::Text		mStatisticsText;
	sf::Time		mStatisticsUpdateTime;
	std::size_t		mStatisticsNumFrames;

	bool mIsMovingUp;
	bool mIsMovingDown;
	bool mIsMovingRight;
	bool mIsMovingLeft;
};
