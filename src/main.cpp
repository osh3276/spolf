#include <SFML/Graphics.hpp>

int main() {
#if SFML_VERSION_MAJOR >= 3
	sf::RenderWindow window(sf::VideoMode({800, 600}), "SFML Window");
#else
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Window");
#endif

	while (window.isOpen()) {
#if SFML_VERSION_MAJOR >= 3
		while (const std::optional event = window.pollEvent()) {
			if (event->is<sf::Event::Closed>())
				window.close();
		}
#else
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}
#endif

		window.clear();
		window.display();
	}
}
