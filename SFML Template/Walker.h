#pragma once
#include <SFML/Graphics.hpp>
#include "Utility.h"

using namespace sf;
using namespace std;

class Walker {

public:
	Walker(int x, int y)
	{
		if (x + y == NULL) {

			pos = randomPoint();
			stuck = false;
			r = radius();

		} else {
		
			pos = Vector2f(x, y);
			stuck = false;
			r = radius();
		}
	}

	void walk();
	void display(sf::RenderWindow &MainWindow);
	bool update(vector<Walker> other);
	int distSq(Vector2f a, Vector2f b);
	Vector2f randomPoint();

	Vector2f pos;
	bool stuck;
	int r;
};