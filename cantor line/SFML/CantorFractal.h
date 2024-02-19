#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <math.h>
#include <dos.h>
using namespace sf;
using namespace std;
class CantorFractal {
	float multiplier;
	bool isFirst = true;
public:
	CantorFractal(float multiplier) {
		this->multiplier = multiplier;
	}
	void draw(RenderWindow& window, int iterations, float length, Vector2f startCoordinate) {
		const float OffsetY = 10;//смещение каждой полосы на 10 пикселей

		if (iterations > 0 && isFirst) {
			Vector2f stopCoordinate(startCoordinate.x + length, startCoordinate.y);
			Vertex line[]{ startCoordinate,stopCoordinate };
			window.draw(line, 2, Lines);
			
			iterations--;
			isFirst = false;
		}
		if (iterations > 0 && !isFirst) {
			Vector2f firstLineStart(startCoordinate.x, startCoordinate.y + OffsetY);
			Vector2f firstLineStop(startCoordinate.x + length* multiplier, startCoordinate.y + OffsetY);
			float firstLineLength = sqrt(pow(firstLineStart.x - firstLineStop.x,2) + pow(firstLineStart.y - firstLineStop.y,2));//156025
			Vertex firstLine[]{ firstLineStart, firstLineStop };
			window.draw(firstLine, 2, Lines);
			//if (iterations == 2)
			//window.display();
			iterations--;
			draw(window, iterations, firstLineLength, firstLineStart);

			iterations++;
			Vector2f secondLineStart(startCoordinate.x + (length*(1- multiplier)), startCoordinate.y + OffsetY);
			Vector2f secondLineStop(startCoordinate.x + length, startCoordinate.y + OffsetY);
			float secondLineLength = sqrt(pow(secondLineStart.x - secondLineStop.x,2) + pow(secondLineStart.y - secondLineStop.y,2));
			Vertex secondLine[]{ secondLineStart, secondLineStop };
			window.draw(secondLine, 2, Lines);
			//if(iterations==2)
			//window.display();
			iterations--;
			draw(window, iterations, secondLineLength, secondLineStart);

			//Vertex firstLine[]{ firstLineStart, firstLineStop };
			//Vertex secondLine[]{ secondLineStart, secondLineStop };

			//window.draw(firstLine, 2, Lines);
			//window.draw(secondLine, 2, Lines);
			//window.display();
			//iterations--;
			//draw(window, iterations, firstLineLength, firstLineStart);
			//draw(window, iterations, secondLineLength, secondLineStart);
		}

	}
};