#ifndef  H_GAME_OPTIONS
#define  H_GAME_OPTIONS

#include "Game.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include <iostream>
#include <GLFW/glfw3.h>


class gameOptions{
	public:

		gameOptions();

		gameOptions(sf::RenderWindow&, sf::Music&);

		void stopMusic(sf::Music&);

		void startMusic(sf::Music&);

		void acceptUserInput(sf::RenderWindow&, sf::Music&);

		void displayMenu(sf::RenderWindow&, sf::Music&);
		
		void displayMenu(sf::RenderWindow&);

		void displayCredits();

		void reset();

		void highScore();

		void exitToMenu();

		void changeTextColor();

		void fullScreen(sf::RenderWindow&);

	private:

	sf::Font font;
	//sf::Music music;


};

#endif

