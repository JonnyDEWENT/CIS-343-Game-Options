#include "Game.hpp"
#include "Monster.hpp"
#include "gameOptions.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include <iostream>
#include "Settings.hpp"

/**Added by Nate **/
#include "Person.hpp"
#include <vector>






/*************************************************************************
* Default constructor
*************************************************************************/
gameOptions::gameOptions() {


}
/*************************************************************************
* Constructor ()
*************************************************************************/
gameOptions::gameOptions(sf::RenderWindow& window, sf::Music& music){

    if(!font.loadFromFile("fonts/Notable-Regular.ttf")){
		std::cerr << "We should be throwing exceptions here... font can't load." << std::endl;
	}
}

/*************************************************************************
* Pauses the music
*************************************************************************/
void gameOptions::stopMusic(sf::Music& music) {
    music.pause();
}

/*************************************************************************
* Starts the music
*************************************************************************/
void gameOptions::startMusic(sf::Music& music) {
    music.play();
}

/*************************************************************************
*
*************************************************************************/
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
	txtChangeDisplay.setString("FullScreen On");
	txtChangeDisplay.setCharacterSize(24);
	txtChangeDisplay.setFillColor(sf::Color::White);
	txtChangeDisplay.setPosition(175,300);

	sf::Text txtChangeDisplay2;
	txtChangeDisplay2.setFont(font);
	txtChangeDisplay2.setString("FullScreen Off");
	txtChangeDisplay2.setCharacterSize(24);
	txtChangeDisplay2.setFillColor(sf::Color::White);
	txtChangeDisplay2.setPosition(175,350);

    sf::Text txtExit;
	txtExit.setFont(font);
	txtExit.setString("Exit");
	txtExit.setCharacterSize(24);
	txtExit.setFillColor(sf::Color::White);
	txtExit.setPosition(175,400);
	


    sf::Text txtMusic;
	txtMusic.setFont(font);
	txtMusic.setString("Music On/Off");
	txtMusic.setCharacterSize(24);
	txtMusic.setFillColor(sf::Color::White);
	txtMusic.setPosition(175,450);


	
	if (itemSelected == menuSize)
		itemSelected = 0;
	else if(itemSelected == -1) {
		itemSelected = 3;
	}
	switch (itemSelected) {

		case 0: 
		colorLabel(window,txtChangeDisplay);
		//txtChangeDisplay.setFillColor(sf::Color::Yellow);
		break;


		case 1:
		colorLabel(window,txtChangeDisplay2);
		//txtExit.setFillColor(sf::Color::Yellow);
		break;


		case 2:
		colorLabel(window,txtExit);
		//txtExit.setFillColor(sf::Color::Yellow);
		break;

		case 3:
		colorLabel(window,txtMusic);
		//txtMusic.setFillColor(sf::Color::Yellow);
		break;

		default:
		break;
		
	}

    window.draw(txtTitle);
    window.draw(txtChangeDisplay);
	window.draw(txtChangeDisplay2);
    window.draw(txtMusic);
    window.draw(txtExit);

    window.display();
   
}

/*************************************************************************
* Overloaded displayMenu to include music when calling acceptUserInput
*************************************************************************/
void gameOptions::displayMenu(sf::RenderWindow& window, sf::Music& music){
	itemSelected = 0;
    displayMenu(window);
    acceptUserInput(window,music);
}

/*********************************************************************************
* This function runs the duration of the game options screen listening for
* user input.
********************************************************************************/
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
				if(event.key.code == sf::Keyboard::Return){
					switch (itemSelected) {

					case 0: 
						fullScreen(window);
					break;

					case 1:
						notFullScreen(window);
						break;

					case 2:
						window.clear();
						return;
						break;

					
					case 3:
						if(music.getStatus()==sf::Music::Paused)
                    	music.play();
            		else
            			stopMusic(music);
						break;

					default:
					break;

		
			}
				}
				

				
				if(event.key.code == sf::Keyboard::Up){
					itemSelected--;
					displayMenu(window);
			
				}
				if(event.key.code == sf::Keyboard::Down){
					itemSelected++;
					displayMenu(window);
			
				}

                
			}

		}
}
}

/** Added by Nate, unconfirmed if works **/
void gameOptions::changeResolution(sf::RenderWindow& window, int x, int y) {
	window.setSize(sf::Vector2<unsigned int>(x, y));
	window.setPosition(sf::Vector2<int>(0,0));
	
}


void gameOptions::displayCredits(){

}

/**Added by Nate, unconfirmed if works **/
void gameOptions::reset(std::vector<Monster>& monsters, Person& player, bool& done){
	resetPlayer(player); //player.initialize() would work too
	monsters.clear(); //Clearing monster vector
	monsters.push_back(Monster()); //Adding a single monster like game says.
	done = false; //Maybe this isnt neccecary
}

void gameOptions::highScore(){
	
}

/*************************************************************************
* Should effectively quit the game and return to the main screen
*************************************************************************/
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
    //window.create(sf::VideoMode(1300, 1400), "Not on my block.", 3 << 3);
	const std::vector<sf::VideoMode>& fullscreenModes = sf::VideoMode::getFullscreenModes();
	changeResolution(window,fullscreenModes[0].width,fullscreenModes[0].height);
	window.clear();
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
void gameOptions::endGame(bool& done){
	done = true; //Should break the loop, see Game::run function
}

//Colors the appropriate
void gameOptions::colorLabel(sf::RenderWindow& window, sf::Text& text){
	text.setFillColor(sf::Color::Yellow);
	 window.draw(text);

}

void gameOptions::notFullScreen(sf::RenderWindow& window){

	window.setSize(sf::Vector2<unsigned int>(WIDTH, HEIGHT + 100));
	displayMenu(window);
}

/***********************************************************************************************************************
* This funtion change the game title and game text color
* Add by Runquan Ye
* My idea is this, the option panel will show the text to inform user that press key to change the text and title's colors
* 	i.e.: press "F3" function key invold changeTextColor method
*	      then press "1" for turning the text color to red, "2" for blue
*		"1 - red, 2 - white, 3 - blue, 4 - green, 5 - purple"
*		"6 - brown, 7 - gray, 8 - orange, 9 - yellow, 0 - pink"
* Request, need the game object g pass in (Maybe)
*	or just modify the window object's title and text feature.
*	or just modify the text and title feature and then update the window, since option is a part inside of the game
************************************************************************************************************************/
// void gameOptions::changeTextColor(sf::RenderWindow window){
// 	/**This one I think we would have to ask to change his render funcion - Nate **/
// 	switch(event.key.code){
// 		std::cout << event.key.code;
// 		case sf::Keyboard::Num1:
			
// 			color = sf::Color::White; 
// 		break;
		
// 		case sf::Keyboard::Num2:
// 			color = sf::Color::Red;
// 		break;

// 		case sf::Keyboard::Num3:
// 			color = sf::Color::Green;
// 		break;

// 		case sf::Keyboard::Num4:
// 			color = sf::Color::Blue;
// 		break;

// 		case sf::Keyboard::Num5:
// 			color = sf::Color::Yellow;
// 		break;
	
// 		case sf::Keyboard::Num6:
// 			color = sf::Color::Magenta;
// 		break;

// 		case sf::Keyboard::Num7:
// 			color = sf::Color::Cyan;
// 		break;
		
// 	}
// 	displayMenu(window);
// }


/**Change Difficulty**/
// void gameOptions::changeDifficulty(int diff, std::vector<Monster>& monsters, Person& player){
// 	switch (diff){
// 		case 1:
// 			//Easy
// 			setPlayerHealth(player, 200);
// 			break;
// 		case 2:
// 			//Medium
// 			setPlayerHealth(player, 100);
// 			//Will this work? or will the moster dissapear when the function ends?
// 			monsters.push_back(monster().updatePosition(50, 50));
// 			break;
// 		case 3:
// 			//Hard
// 			setPlayerHealth(player, 50);
// 			monsters.push_back(monster().updatePosition(50, 50));
// 			monster.push_back(monster().updatePosition(25, 25));
// 			break;
// 		default:
// 			break;
// 	}
// }


