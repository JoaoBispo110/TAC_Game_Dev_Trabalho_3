#ifndef TILESET
#define TILESET

	#include <string>
	#include "Sprite.h"

	class TileSet{
		private:
		//attributes:
			Sprite *tile_set;
			int rows, collumns, tile_width, tile_height;

		public:
		//metods:
			TileSet(int tile_width, int tile_height, std::string file);
			~TileSet();
			void RenderTile(unsigned index, float x, float y);
			int GetTileWidth();
			int GetTileHeight();
	};

#endif