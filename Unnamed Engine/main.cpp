#include <string>
#include <iostream>
//#include <glm/glm.hpp>

using namespace std;
//using namespace glm;

#include "unnamed.h"

Window game;


int main(int argc, char *argv[])
{
	try
	{
		game.RunGame();
	}
	catch (int e)
	{
		cout << e << endl;
	}

	return 0;
}