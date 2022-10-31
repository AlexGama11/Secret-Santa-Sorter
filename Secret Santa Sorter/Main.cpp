#include <vector>
#include <algorithm>
#include <random>
#include "Utility.h"

int main()
{
	//Variables

	bool isListEnded = false;

	bool isSearchEnded = false;

	std::string name;

	std::string receiverName;

	std::vector<std::string> secretSanta;

	std::string santa;

	std::vector<std::string> giftReceiver;

	int participantNumber = 0;

	int searchLine = 0;

	auto rng = std::default_random_engine{};

// ------------------------------------------------------------------------------- DELIMITOR ------------------------------------------------------------------------------------------------//

	//Utility class from my OpenGL program, here for console colours.
	Utility::Initialize();
	
	Utility::Log("Name everyone who's participating as a secret santa! Write 'end' to finish the list.", Utility::Colour::Red);

	while (!isListEnded)
	{
		//makes a list with the names, uses RNG for it.
		std::cin >> santa;

		//For Loop to convert each character to uppercase, making my check later be case insensitive.
		for (int i = 0; i < santa.size(); i++)
		{
			santa.at(i) = toupper(santa.at(i));
		}

		if (santa == "END")
		{
			std::shuffle(std::begin(giftReceiver), std::end(giftReceiver), rng);
			isListEnded = true;
		}

		secretSanta.push_back(santa);
		giftReceiver.push_back(santa);

		
	}

// ------------------------------------------------------------------------------- DELIMITOR ------------------------------------------------------------------------------------------------//

	//Once list is made, search for who you gotta gift.
	Utility::Log("List Made! Write your name to find out who you have to gift!", Utility::Colour::Red);
	std::cin >> name;

	for (int i = 0; i < name.size(); i++)
	{
		name.at(i) = toupper(name.at(i));
	}

	while (!isSearchEnded)
	{
		if (name == secretSanta.at(searchLine))
		{
			//Reshuffle if its still the same name.
			if (name == giftReceiver.at(searchLine))
			{
				std::shuffle(std::begin(giftReceiver), std::end(giftReceiver), rng);
			}

			else
			{
				//This is so the name isnt printed out in all caps.
				receiverName = giftReceiver.at(searchLine);

				for (int i = 1; i < receiverName.size(); i++)
				{
					receiverName.at(i) = tolower(receiverName.at(i));
				}

				std::string message = "You gotta gift: " + receiverName + "!";

				Utility::Log(message, Utility::Colour::Red);
				isSearchEnded = true;
			}
			
		}

		else
		{
			searchLine++;
		}
	
	}

	Utility::Log("Merry Christmas!", Utility::Colour::Red);
	return 0;

}