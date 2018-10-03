#ifndef  H_GAME_OPTIONS
#define  H_GAME_OPTIONS

#include "Game.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"


class gameOptions{
	public:

		gameOptions(sf::Window, sf::Music);

		void pause();

		void displayCredits();

		void reset();

		void highScore();

		void exitToMenu();

		void changeTextColor();


	private:


};

#endif

