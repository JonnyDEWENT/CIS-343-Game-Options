#ifndef  H_GAME_OPTIONS
#define  H_GAME_OPTIONS

#include "Game.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include <iostream>

/**Added by Nate **/
#include <vector>

#define menuSize 4



class gameOptions{
	public:

		gameOptions();

		gameOptions(sf::RenderWindow&, sf::Music&);

		void stopMusic(sf::Music&);

		void startMusic(sf::Music&);

		void acceptUserInput(sf::RenderWindow&, sf::Music&);

		void displayMenu(sf::RenderWindow&, sf::Music&);
		
		void displayMenu(sf::RenderWindow&);
		
		/**Added by Nate, unconfirmetd if works **/
		void changeResolution(sf::RenderWindow&, int, int);

		void displayCredits();
		
		/** Changed by Nate, unconfirmed **/
		void reset(std::vector<Monster>&, Person&, bool&);

		void highScore();

		void exitToMenu();

		void changeTextColor();

		void fullScreen(sf::RenderWindow&);
	
		/** Following methods where added by Nate, unconfirmed **/
		void setPlayerHealth(Person&, int);
		void resetPlayer(Person&);
		void endGame(bool&);
		//Colors appropriate menu item
		void colorLabel(sf::RenderWindow&, sf::Text&);

		void notFullScreen(sf::RenderWindow&);

		void changeTextColor(sf::RenderWindow window);

		void changeDifficulty(int, std::vector<Monster>&, Person&);
		

	private:

	sf::Font font;

	sf::Color color;
	
	int itemSelected;

	//sf::Music music;


};

#endif

