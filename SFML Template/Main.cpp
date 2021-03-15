#include <SFML/Graphics.hpp>
#include <iostream>
#include "Walker.h"
#include "Utility.h"

using namespace std;
using namespace sf;

vector<Walker> tree;
vector<Walker> walkers;

int iterations = 2;
int maxWalkers = 400;

int main()
{

	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	sf::RenderWindow window(sf::VideoMode(WindowWidth(), WindowHeight()), "Diffusion-Limited Aggregation", 0, settings);

	tree.push_back(Walker(WindowWidth()/2, WindowHeight()/2));
	
	for (int i = 0; i < maxWalkers; i++) {
		walkers.push_back(Walker(NULL, NULL));
	}

	int r = walkers[walkers.size() - 1].r;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();

		if (tree.size() < maxWalkers) {

	

			for (int i = 0; i < walkers.size(); i++) {
	    		walkers[i].display(window);
			}
		}

		for (int n = 0; n < iterations; n++) {
			for (int i = 0; i < walkers.size(); i++) {
				walkers[i].walk();
				if (walkers[i].update(tree)) {
					tree.push_back(walkers[i]);
				    walkers.erase(walkers.begin() + i);
					cout << tree.size() << "\n";
					//P% * X = Y 
					// ^ to cal percentage
				}
			}
		}

		for (int i = 0; i < tree.size(); i++) {
			tree[i].display(window);
		}

		//while (walkers.size() < maxWalkers && tree.size() < maxWalkers) {
		//	walkers.push_back(Walker(NULL, NULL));		
		//}

		window.display();

	}
	return NULL;
}