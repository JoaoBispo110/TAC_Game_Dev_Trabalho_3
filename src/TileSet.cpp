#include <string>
#include "TileSet.h"
#include "GameObject.h"
#include "Sprite.h"

using namespace std;
TileSet::TileSet(int tile_width, int tile_height, string file){
	this->tile_width = tile_width;
	this->tile_height = tile_height;

	GameObject *sprite_obj = new GameObject();

	try{
		tile_set = new Sprite(sprite_obj, file);
		sprite_obj->AddComponent(tile_set);

		collumns = tile_set->GetWidth()/tile_width;
		rows = tile_set->GetHeight()/tile_height;

	}catch(const char* error_msg){
		throw error_msg;
	}
}

TileSet::~TileSet(){
	tile_set->Clear();
}

void TileSet::RenderTile(unsigned index, float x, float y){
	int row, collumn;

	if((index >= 0) && (index <= ((rows*collumns) - 1))){
		row = index/collumns;
		collumn = index%collumns;
		tile_set->SetClip((collumn*tile_width), (row*tile_height), tile_width, tile_height);
		tile_set->Render(x, y, tile_width, tile_height);
	}
}

int TileSet::GetTileWidth(){
	return tile_width;
}

int TileSet::GetTileHeight(){
	return tile_height;
}
