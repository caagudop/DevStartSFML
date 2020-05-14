//#include "Game.h"
//#include <iostream>
//#include "ResourceHolder.hpp"
//
//const float Game::PlayerSpeed = 100.f;
//const sf::Time Game::TimePerFrame = sf::seconds(1.f / 60.f);
//
//// Resource ID for sf::Texture
//namespace Textures
//{
//	enum ID
//	{
//		Landscape,
//		Airplane,
//	};
//}
//
//Game::Game()
//	: mWindow(sf::VideoMode(640, 480), "Resources", sf::Style::Close | sf::Style::Resize)
//	, mFont()
//	, landscape();
//	, airplane();
//	, mStatisticsText()
//	, mStatisticsUpdateTime()
//	, mStatisticsNumFrames(0)
//	, mIsMovingUp(false)
//	, mIsMovingDown(false)
//	, mIsMovingRight(false)
//	, mIsMovingLeft(false)
//{
//
//	ResourceHolder<sf::Texture, Textures::ID> textures;
//	try
//	{
//		textures.load(Textures::Landscape, "Media/Textures/Desert.png");
//		textures.load(Textures::Airplane, "Media/Textures/Eagle.png");
//	}
//	catch (std::runtime_error & e)
//	{
//		std::cout << "Exception: " << e.what() << std::endl;
//	}
//
//
//	sf::Sprite landscape(textures.get(Textures::Landscape));
//	sf::Sprite airplane(textures.get(Textures::Airplane));
//	//landscape.~Drawable()
//	airplane.setPosition(200.f, 200.f);
//
//	mFont.loadFromFile("Media/Sansation.ttf");
//	mStatisticsText.setFont(mFont);
//	mStatisticsText.setPosition(5.f, 5.f);
//	mStatisticsText.setCharacterSize(10);
//
//
//}
//void Game::run() 
//{
//	sf::Clock clock;
//	sf::Time timeSinceLAstUpdate = sf::Time::Zero;
//
//	while (mWindow.isOpen())
//	{
//		sf::Time elapsedTime = clock.restart();
//		timeSinceLAstUpdate += elapsedTime;
//		while (timeSinceLAstUpdate > TimePerFrame)
//		{
//			timeSinceLAstUpdate -= TimePerFrame;
//			processEvents();
//			update(TimePerFrame);
//		}
//		updateStatistics(elapsedTime);
//		render();
//	}
//
//}
//void Game::processEvents()
//{
//	sf::Event event;
//	while (mWindow.pollEvent(event))
//	{
//		switch (event.type) {
//		case sf::Event::Closed:
//			mWindow.close();
//			break;
//		case sf::Event::Resized:                                                                                                       
//			printf(" Alto: %i , Ancho %i", event.size.height, event.size.width);
//			break;
//		case sf::Event::KeyPressed:
//			handlePlayerInput(event.key.code, true);
//			break;
//		case sf::Event::KeyReleased:
//			handlePlayerInput(event.key.code, false);
//			break;
//		}
//	}
//}
//void Game::update(sf::Time deltaTime) {
//	sf::Vector2f movement(0.f, 0.f);
//	if (mIsMovingUp)
//		movement.y -= PlayerSpeed;
//	if (mIsMovingDown)
//		movement.y += PlayerSpeed;
//	if (mIsMovingRight)
//		movement.x += PlayerSpeed;
//	if (mIsMovingLeft)
//		movement.x -= PlayerSpeed;
//	/*airplane.move(movement * deltaTime.asSeconds());*/
//}
//void Game::render()
//{
//	mWindow.clear();
//	mWindow.draw(landscape);
//	mWindow.draw(airplane);
//	mWindow.draw(mStatisticsText);
//	mWindow.display();
//}
//void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed) 
//{
//	if (key == sf::Keyboard::W)
//		mIsMovingUp = isPressed;
//	if (key == sf::Keyboard::S)
//		mIsMovingDown = isPressed;
//	if (key == sf::Keyboard::D)
//		mIsMovingRight = isPressed;
//	if (key == sf::Keyboard::A)
//		mIsMovingLeft = isPressed;
//}
//
//void Game::updateStatistics(sf::Time elapsedTime)
//{
//	mStatisticsUpdateTime += elapsedTime;
//	mStatisticsNumFrames += 1;
//
//	if (mStatisticsUpdateTime >= sf::seconds(1.0f))
//	{
//		mStatisticsText.setString(
//			"Frames / Second = " + std::to_string(mStatisticsNumFrames) + "\n"
//			//"Time / Update = " + std::to_string(mStatisticsUpdateTime.asMicroseconds() / mStatisticsNumFrames) + "us");
//		);
//		mStatisticsUpdateTime -= sf::seconds(1.0f);
//		mStatisticsNumFrames = 0;
//	}
//}