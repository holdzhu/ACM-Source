#include <SFML/Graphics.hpp>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <fstream>
#include <algorithm>

using namespace std;

const double pi = acos(-1);
const double eps = 1e-9;

struct Point
{
	double x, y;
	int flag;
	int ID;
	bool operator < (const Point& rhs) const
	{
		return atan2(y, x) < atan2(rhs.y, rhs.x);
	}
};

typedef Point Vector;

double randeps()
{
	return rand() * eps * 2 / RAND_MAX - eps;
}

Vector operator - (const Point& A, const Point& B)
{
	return (Vector){A.x - B.x, A.y - B.y};
}

Vector operator * (const double& k, const Vector& A)
{
	return (Vector){A.x * k, A.y * k};
}

Point operator + (const Point& A, const Vector& B)
{
	return (Point){A.x + B.x, A.y + B.y};
}

double dot(const Vector& A, const Vector& B)
{
	return A.x * B.x + A.y * B.y;
}

double cross(const Vector& A, const Vector& B)
{
	return A.x * B.y - A.y * B.x;
}

double len(const Vector& A)
{
	return sqrt(dot(A, A));
}

double dis(const Point& A, const Point& B)
{
	return fabs(cross(B - A, A) / len(B - A));
}

double angle(const Vector& A, const Vector& B)
{
	double a = atan2(A.y, A.x);
	double b = atan2(B.y, B.x);
	double res = a - b;
	if (res < 0)
	{
		res += pi * 2;
	}
	return res;
}

double solve1(const double& a, const double& b, const double& c)
{
	return (-b - sqrt(b * b - 4 * a * c)) / 2 / a;
}

double solve2(const double& a, const double& b, const double& c)
{
	return (-b + sqrt(b * b - 4 * a * c)) / 2 / a;
}

int R, N;
Point p[100];
int nxt[100];
sf::RenderWindow window(sf::VideoMode(600, 600), "Geometry Visualize");
sf::CircleShape cs;
sf::RectangleShape rs;
sf::CircleShape Cs;

void drawPoint(const Point& A)
{
	cs.setPosition(300 + A.x * 0.25, 300 - A.y * 0.25);
	cs.setOrigin(sf::Vector2f(2, 2));
	window.draw(cs);
}

void drawLine(const Point& A, const Point& B)
{
	rs.setSize(sf::Vector2f(len(B - A) * 0.25, 1));
	rs.setRotation(-atan2(B.y - A.y, B.x - A.x) / pi * 180);
	rs.setPosition(300 + A.x * 0.25, 300 - A.y * 0.25);
	window.draw(rs);
}

int main()
{
	sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    window.create(sf::VideoMode(600, 600), "Geometry Visualize", sf::Style::Default, settings);
	ifstream is("5.in");
	is >> R;
	is >> N;
	for (int i = 0; i < N; ++i)
	{
		is >> p[i].x >> p[i].y;
		p[i].flag = 0;
	}
	cs.setRadius(2);
	cs.setFillColor(sf::Color::Red);
	rs.setFillColor(sf::Color::Black);
	Cs.setRadius(R * 0.25);
	Cs.setFillColor(sf::Color::Red);
	Cs.setOrigin(sf::Vector2f(R * 0.25, R * 0.25));
	Cs.setPosition(sf::Vector2f(300, 300));
	is.close();
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			default:
				break;
			}
		}
		window.clear(sf::Color::White);
		window.draw(Cs);
		for (int i = 0; i < N; ++i)
		{
			drawPoint(p[i]);
			drawLine(p[i], p[(i + 1) % N]);
		}
		window.display();
	}
	return 0;
}
