#pragma once

class TileSet{
	private:
		std::vector<sf::Vector2i> coords;
		sf::IntRect tileRect;
		sf::Texture texture;
		sf::Vector2i tmpcoord;

		int tileSizeX, tileSizeY;
		int temp;
	public:
		TileSet(){}
		~TileSet(){}
		sf::Texture tileSet(std::string path, int _tileSizeX, int _tileSizeY);
		sf::IntRect getTileSet(int tileNum);
};
