#include <string>
#include "Music.h"
#include "Resources.h"

using namespace std;
Music::Music(){
	music = nullptr;
}

Music::Music(string file){
	music = nullptr;

	try{
		Open(file);
	}catch(const char* error_msg){
			throw error_msg;
	}
}

void Music::Play(int times){
	if(music != nullptr){
		try{
			Mix_PlayMusic(music, times);
		}catch(const char* error_msg){
			throw error_msg;
		}
	}
	else{
		throw "Tried to play a song, but song pointer is Null";
	}
}

void Music::Stop(int msToStop){
	Mix_FadeOutMusic(msToStop);
}

void Music::Open(string file){
	try{
		music = Resources::GetMusic(file);
	}catch(const char* error_msg){
		throw error_msg;
	}
}

bool Music::IsOpen(){
	return (music != nullptr);//Returns true if music is allocated
}

Music::~Music(){
	if(music != nullptr){
		Stop();
		Mix_FreeMusic(music);
		music = nullptr;
	}
}