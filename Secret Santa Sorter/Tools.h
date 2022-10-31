#pragma once
#include <iostream>
#include <Windows.h>
#include <assert.h>

class Tools
{

public:

	enum class Colour
	{
		Purple = 5,
		Green = 10,
		Yellow = 14,
		Red = 12
	};

	static void Initialize();

	static void Log(const std::string& outputMessage, Colour colour = Colour::Green);

private:
	
	static HANDLE consoleHandle;
};
