#include "Utility.h"

HANDLE Utility::consoleHandle{ nullptr };

void Utility::Initialize()
{
	consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
}

void Utility::Log(const std::string& outputMessage, Colour colour)
{
	//Did you forget to call Initialize()?
	assert(consoleHandle);

	SetConsoleTextAttribute(consoleHandle, static_cast<WORD>(colour));
	std::cout << outputMessage << std::endl;
	SetConsoleTextAttribute(consoleHandle, static_cast<WORD>(Colour::Green));
}
