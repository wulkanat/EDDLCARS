#include "stdafx.h"
#include "SFML/Graphics.hpp"
#include <vector>
#include <thread>
#include "RoundedRectangle.h"
#include "Button.h"
#include "Element.h"
#include "StaticValues.h"
#include "Swept.h"
#include "SegmentButton.h"
#include "EDDInterface64.h"

using namespace std;

std::thread mainLoop;

void render(sf::RenderWindow &window, vector<lcars::Element> &elements) {
	
}

void createButton(vector<lcars::Element> &elements, double hSpan, double vSpan) {
	//LcarsButton button;
	///elements.push_back(button);
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(1600, 900), "Customizable LCARS");
	vector<lcars::Element*> elements;

	lcars::Swept swept;
	swept.relativeElement = nullptr;
	swept.pos[0] = padding;
	swept.pos[1] = padding;
	swept.size[0] = 4;
	swept.size[1] = 3;
	swept.arrangement[0] = 1;
	swept.arrangement[1] = 0;
	swept.relativeArrangement = 0;
	swept.orientation = 3;
	swept.output_height = 1;
	swept.output_width = 2;
	elements.push_back(&swept);

	lcars::SegmentButton button;
	button.relativeElement = &swept;
	button.pos[0] = 0;
	button.pos[1] = 0;
	button.size[0] = 2;
	button.size[1] = 2;
	button.arrangement[0] = 0;
	button.arrangement[1] = 2;
	button.relativeArrangement = 0;
	elements.push_back(&button);

	lcars::SegmentButton button2;
	button2.relativeElement = &button;
	button2.pos[0] = 0;
	button2.pos[1] = 0;
	button2.size[0] = 2;
	button2.size[1] = 3;
	button2.arrangement[0] = 0;
	button2.arrangement[1] = 2;
	button2.relativeArrangement = 0;
	elements.push_back(&button2);

	lcars::Button button3;
	button3.relativeElement = &swept;
	button3.pos[0] = 0;
	button3.pos[1] = 0;
	button3.size[0] = 2;
	button3.size[1] = 0.75;
	button3.arrangement[0] = 1;
	button3.arrangement[1] = 0;
	button3.relativeArrangement = 1;
	elements.push_back(&button3);

	lcars::Swept swept1;
	swept1.relativeElement = &button2;
	swept1.pos[0] = 0;
	swept1.pos[1] = 0;
	swept1.size[0] = 9;
	swept1.size[1] = 2;
	swept1.arrangement[0] = 0;
	swept1.arrangement[1] = 2;
	swept1.relativeArrangement = 0;
	swept1.orientation = 1;
	swept1.output_height = 0.5;
	swept1.output_width = 2;
	elements.push_back(&swept1);

	lcars::Swept swept2;
	swept2.relativeElement = &swept1;
	swept2.pos[0] = 0;
	swept2.pos[1] = 0;
	swept2.size[0] = 9;
	swept2.size[1] = 2;
	swept2.arrangement[0] = 0;
	swept2.arrangement[1] = 2;
	swept2.relativeArrangement = 0;
	swept2.orientation = 0;
	swept2.output_height = 0.5;
	swept2.output_width = 2;
	elements.push_back(&swept2);

	lcars::Swept swept3;
	swept3.relativeElement = &swept2;
	swept3.pos[0] = 0;
	swept3.pos[1] = 0;
	swept3.size[0] = 9;
	swept3.size[1] = 3;
	swept3.arrangement[0] = 0;
	swept3.arrangement[1] = 2;
	swept3.relativeArrangement = 0;
	swept3.orientation = 1;
	swept3.output_height = 0.5;
	swept3.output_width = 2;
	elements.push_back(&swept3);

	lcars::Button button4;
	button4.relativeElement = &swept1;
	button4.pos[0] = 0;
	button4.pos[1] = 0;
	button4.size[0] = 2;
	button4.size[1] = 0.75;
	button4.arrangement[0] = 0;
	button4.arrangement[1] = 2;
	button4.relativeArrangement = 1;
	elements.push_back(&button4);



	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();


		//render(window, elements);

		/*swept.render(window);
		swept1.render(window);
		button.render(window);
		button2.render(window);
		button3.render(window);
		button4.render(window);
		*/

		for (lcars::Element * element : elements) {
			element->render(window);
		}

		window.display();
	}

	return 0;
}

EDD_API BSTR __cdecl EDDInitialise(BSTR ver, BSTR dllfolder, EDDCallBacks requestcallback) {
	mainLoop = std::thread(main);
	mainLoop.detach();

	return ::SysAllocString(L"Hello World");
}

EDD_API BSTR __cdecl EDDActionCommand(BSTR action, SAFEARRAY& args) {
	return ::SysAllocString(L"FALSE");
}

EDD_API void EDDTerminate() {

}