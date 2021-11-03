#include <string>
#include <vector>
#include <fstream>
#include "TileMap.h"
#include "TileSet.h"

using namespace std;
TileMap::TileMap(GameObject *associated, string file, TileSet *tile_set) : Component(associated){
	Load(file);

	SetTileSet(tile_set);
}

TileMap::~TileMap(){
	delete tile_set;
}

void TileMap::Load(string path){
	ifstream file(path);
	int i, j, k, aux;
	char char_trash;

	tile_matrix.clear();

	map_width = 0;
	map_height = 0;
	map_depth = 0;

	file >> map_width;
	file.ignore(); //"," ignored
	file >> map_height;
	file.ignore(); //"," ignored
	file  >> map_depth;
	
	file.ignore(); //"," ignored
	file.ignore(); //"\n" ignored
	file.ignore(); //"\n" ignored

	for(k = 0; k < map_depth; k++){
		for(j = 0; j < map_height; j++){
			for(i = 0; i < map_width; i++){
				file >> aux;
				tile_matrix.push_back(aux-1);

				while((file.peek() == ',') || (file.peek() == '\n')){
					file.ignore();
				}
			}
		}
	}
	file.close();
}

void TileMap::SetTileSet(TileSet *tile_set){
	this->tile_set = tile_set;
}

int& TileMap::At(int x, int y, int z){
	return tile_matrix[(z*(map_width*map_height)) + y*(map_width) + x];
}

void TileMap::Render(){
	int k;

	for(k = 0; k < map_depth; k++){
		RenderLayer(k);
	}
}

void TileMap::RenderLayer(int layer, int camera_x, int camera_y){
	int i, j, content;

	for(j = 0; j < map_height; j++){
		for(i = 0; i < map_width; i++){
			content = At(i, j, layer);

			//If the matrix content is greater then -1 then we render the corresponding tile,
			//otherwise we ignore the element, since a content of -1 means the image is blank in this layer.
			if(content > -1){
				tile_set->RenderTile(content, (i*tile_set->GetTileWidth()), (j*tile_set->GetTileHeight()));
			}
		}
	}
}

int TileMap::GetWidth(){
	return map_width;
}

int TileMap::GetHeight(){
	return map_height;
}

int TileMap::GetDepth(){
	return map_depth;
}

void TileMap::Update(float dt){}

bool TileMap::Is(string type){
	if(type == "TileMap"){
		return true;
	}
	else{
		return false;
	}
}
