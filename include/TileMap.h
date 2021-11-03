#ifndef TILEMAP
#define TILEMAP

	#include <string>
	#include <vector>
	#include "TileSet.h"

	class TileMap : public Component{
		private:
		//attributes:
			std::vector <int> tile_matrix;
			TileSet *tile_set;
			int map_width, map_height, map_depth;

		public:
		//metods:
			TileMap(GameObject *associated, std::string file, TileSet *tile_set);
			~TileMap();
			void Load(std::string path);
			void SetTileSet(TileSet *tile_set);
			int& At(int x, int y, int z = 0);
			void Render();
			void RenderLayer(int layer, int camera_x = 0, int camera_y = 0);
			int GetWidth();
			int GetHeight();
			int GetDepth();
			void Update(float dt);
			bool Is(std::string file);

	};

#endif