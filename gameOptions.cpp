#include "Game.hpp"
#include "gameOptions.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include <iostream>

/**Added by Nate **/
#include "Person.hpp"
#include <vector>







gameOptions::gameOptions() {


}
gameOptions::gameOptions(sf::RenderWindow& window, sf::Music& music){

    if(!font.loadFromFile("fonts/Notable-Regular.ttf")){
		std::cerr << "We should be throwing exceptions here... font can't load." << std::endl;
	}
}

void gameOptions::stopMusic(sf::Music& music) {
    music.pause();
}

void gameOptions::startMusic(sf::Music& music) {
    music.play();
}

void gameOptions::displayMenu(sf::RenderWindow& window){
    window.clear();

    sf::Text txtTitle;
	txtTitle.setFont(font);
	txtTitle.setString("Options");
	txtTitle.setCharacterSize(44);
	txtTitle.setFillColor(sf::Color::White);
	txtTitle.setPosition(175,200);

    sf::Text txtChangeDisplay;
	txtChangeDisplay.setFont(font);
	txtChangeDisplay.setString("FullScreen On/Off V");
	txtChangeDisplay.setCharacterSize(24);
	txtChangeDisplay.setFillColor(sf::Color::White);
	txtChangeDisplay.setPosition(175,300);

    sf::Text txtExit;
	txtExit.setFont(font);
	txtExit.setString("Exit - 'Backspace'");
	txtExit.setCharacterSize(24);
	txtExit.setFillColor(sf::Color::White);
	txtExit.setPosition(175,350);


    sf::Text txtMusic;
	txtMusic.setFont(font);
	txtMusic.setString("Music On/Off 'M'");
	txtMusic.setCharacterSize(24);
	txtMusic.setFillColor(sf::Color::White);
	txtMusic.setPosition(175,400);

    window.draw(txtTitle);
    window.draw(txtChangeDisplay);
    window.draw(txtMusic);
    window.draw(txtExit);

    window.display();
   
}

void gameOptions::displayMenu(sf::RenderWindow& window, sf::Music& music){
    displayMenu(window);
    acceptUserInput(window,music);
}

void gameOptions::acceptUserInput(sf::RenderWindow& window, sf::Music& music){
    while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed){
				window.close();
				music.stop();
				exit(0);
			}

			if(event.type == sf::Event::KeyPressed){
				if(event.key.code == sf::Keyboard::BackSpace){
					window.clear();
					return;
				}
				if(event.key.code == sf::Keyboard::M){
                    if(music.getStatus()==sf::Music::Paused)
                        music.play();
                    else 
					    stopMusic(music);
				}

                
				if(event.key.code == sf::Keyboard::V){
					fullScreen(window);
				}
			}

		}
}
}

/** Added by Nate, unconfirmed if works **/
void gameOptions::changeResolution(sf::RenderWindow& window, int x, int y) {
	window.setSize(sf::Vector2<unsigned int>(x, y));
}


void gameOptions::displayCredits(){

}

/**Added by Nate, unconfirmed if works **/
void gameOptions::reset(std::vector<Monster>& monsters, Person& player, boolean& done){
	resetPlayer(player); //player.initialize() would work too
	monsters.clear(); //Clearing monster vector
	monsters.push_back(Monster()); //Adding a single monster like game says.
	done = false; //Maybe this isnt neccecary
}

void gameOptions::highScore(){
	
}

void gameOptions::exitToMenu(){
}

void gameOptions::changeTextColor(/**sf::RenderWindow& window, sf::Color color **/){
	/**This one I think we would have to ask to change his render funcion - Nate **/
}

void gameOptions::fullScreen(sf::RenderWindow& window) 
{
	/**I think that window.setSize(sf::Vector2<unsigned int>(1300, 1400));
	* might work here instead of .create. Thats what I used before and it
	* seemed to work. Its worth a shot. */
    window.create(sf::VideoMode(1300, 1400), "Not on my block.");
    displayMenu(window);
}

/**Added by Nate, unconfirmed if works **/
void gameOptions::setPlayerHealth(Person& player, int health){
	player.setHealth(health);
	/** player->setHealth(health)? idk if its on stack or heap **/
}

/**Added by Nate, unconfirmed if works **/
void gameOptions::resetPlayer(Person& player){
	/**I belive this will reset the player back to its original position and health **/
	player.initialize(); //player->initialize()?
}

/**Added by Nate, unconfirmed if works **/
void gameOptions::resetGame(std::vector<Monster>& monsters, Person& player, boolean& done){
	resetPlayer(player); //player.initialize() would work too
	monsters.clear(); //Clearing monster vector
	monsters.push_back(Monster()); //Adding a single monster like game says.
	done = false; //Maybe this isnt neccecary
}

/**Added by Nate, unconfirmed if works **/
void gameOptions::endGame(boolean& done){
	done = true; //Should break the loop, see Game::run function
}

