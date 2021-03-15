#include "Walker.h"
#include "VectorMath.h"

float random_float(float min, float max) {
	return ((float)rand() / RAND_MAX) * (max - min) + min;
}

void Walker::walk()
{
	Vector2f vel = Vector2f(random_float(-10.0f, 10.0f), random_float(-10.0f, 10.0f));
	pos += vel;
	pos.x = constrain(pos.x, 0, WindowWidth());
	pos.y = constrain(pos.y, 0, WindowHeight());

}

void Walker::display(sf::RenderWindow &MainWindow)
{
	if (this->stuck == true) {
	CircleShape Walker(r);
	Walker.setOrigin(5, 5);
	Walker.setFillColor(Color(100, 0, 0, 255));
	Walker.setOutlineColor(Color(0,0,0));
	Walker.setOutlineThickness(2);
	Walker.setPosition(pos);
	MainWindow.draw(Walker);

	} else {
	
		CircleShape Walker(r);
		Walker.setOrigin(5, 5);
		Walker.setFillColor(Color(0,0,0,0));
		Walker.setOutlineColor(Color(255, 255, 255, 255));
		Walker.setOutlineThickness(1);
		Walker.setPosition(pos);
		MainWindow.draw(Walker);
	}

}

bool Walker::update(vector<Walker> other) {
	for (int i = 0; i < other.size(); i++) {
		int d = distSq(pos, other[i].pos);
		if (d < (r * r + other[i].r * other[i].r + 2 * other[i].r * r)) {
			stuck = true;
			return true;
			break;
		}
	}
	return false;
}

int Walker::distSq(Vector2f a, Vector2f b)
{
	int dx = b.x - a.x;
	int dy = b.y - a.y;
	return dx * dx + dy * dy;
}

Vector2f Walker::randomPoint()
{
	int i = floor(rand() % 4);

	if (i == 0) {
		int x = rand() % WindowWidth();
		return Vector2f(x, 0);
	}
	else if (i == 1) {
		int x = rand() % WindowWidth();
		return Vector2f(x, WindowHeight());
	}
	else if (i == 2) {
		int y = rand() % WindowHeight();
		return Vector2f(0, y);
	}
	else {
		int y = rand() % WindowHeight();
		return Vector2f(WindowWidth(), y);
	}
}
