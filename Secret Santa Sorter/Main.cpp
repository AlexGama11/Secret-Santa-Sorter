#include "Tools.h"
#include <string>
#include <algorithm>
#include <vector>
#include <random>
#include <fstream>

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

	std::string seedString;

	int participantNumber = 0;

	int searchLine = 0;

	std::string saveList;

// ------------------------------------------------------------------------------- DELIMITOR ------------------------------------------------------------------------------------------------//

	//Utility class from my OpenGL program, here for console colours.
	Tools::Initialize();

	Tools::Log("Enter the Seed you wish to use!", Tools::Colour::Red);

	std::getline(std::cin, seedString);

	for (int i = 0; i < seedString.size(); i++)
	{
		seedString.at(i) = towupper(seedString.at(i));
	}

	std::seed_seq seed(seedString.begin(), seedString.end());

	std::default_random_engine rng(seed);
	
	Tools::Log("Now, name everyone who's participating as a secret santa! Write 'end' to finish the list.", Tools::Colour::Red);

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

			for (int i = 0; i < secretSanta.size(); i++)
			{
				saveList += secretSanta.at(i) + "\n";
			}

			auto save = "Seed: " + seedString + "\n\nSantas: \n" + saveList;

			std::ofstream saveFile("../Seed/SantaListSeed.txt");

			saveFile << save;

			saveFile.close();

			isListEnded = true;
		}

		else
		{
			secretSanta.push_back(santa);
			giftReceiver.push_back(santa);
		}
		
	}

// ------------------------------------------------------------------------------- DELIMITOR ------------------------------------------------------------------------------------------------//

	//Once list is made, search for who you gotta gift.
	Tools::Log("List Made! Write your name to find out who you have to gift!", Tools::Colour::Red);
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

				std::string message = "You gotta gift " + receiverName + "!";

				Tools::Log(message, Tools::Colour::Red);
				isSearchEnded = true;
			}
			
		}

		else
		{
			searchLine++;
		}
	
	}

	Tools::Log("Merry Christmas!", Tools::Colour::Red);
	return 0;

}