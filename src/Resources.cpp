#include <string>
#include <unordered_map>
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#include "SDL_include.h"
#include "Resources.h"
#include "Game.h"

SDL_Texture* Resources::GetImage(std::string file){
	auto image = image_table.find(file);
	SDL_Texture* texture;

	if(image == image_table.end()){
		texture = IMG_LoadTexture(Game::GetInstance().GetRenderer(), file.c_str());
		if(texture == nullptr){
			throw SDL_GetError();
		}

		image_table.emplace(file, texture);
	}
	else{
		texture = image->second;
	}
	
	return texture;
}

void Resources::ClearImages(){
	image_table.clear();
}

Mix_Music* Resources::GetMusic(std::string file){
	auto music_it = music_table.find(file);
	Mix_Music* music;

	if(music_it == music_table.end()){
		music = Mix_LoadMUS(file.c_str());
		if(music == nullptr){
			throw SDL_GetError();
		}

		music_table.emplace(file, music);
	}
	else{
		music = music_it->second;
	}
	
	return music;
}

void Resources::ClearMusics(){
	music_table.clear();
}

Mix_Chunk* Resources::GetSound(std::string file){
	auto sound = sound_table.find(file);
	Mix_Chunk* chunk;

	if(sound == sound_table.end()){
		chunk = Mix_LoadWAV(file.c_str());
		if(chunk == nullptr){
			throw SDL_GetError();
		}

		sound_table.emplace(file, chunk);
	}
	else{
		chunk = sound->second;
	}
	
	return chunk;
}

void Resources::ClearSounds(){
	sound_table.clear();
}

std::unordered_map <std::string, SDL_Texture*> Resources::image_table;
std::unordered_map <std::string, Mix_Music*> Resources::music_table;
std::unordered_map <std::string, Mix_Chunk*> Resources::sound_table;