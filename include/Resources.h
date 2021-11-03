#ifndef RESOURCES
#define RESOURCES

	#include <string>
	#include <unordered_map>
	#define INCLUDE_SDL_IMAGE
	#define INCLUDE_SDL_MIXER
	#include "SDL_include.h"

	class Resources{
		private:
		//attributes:
			static std::unordered_map <std::string, SDL_Texture*> image_table;
			static std::unordered_map <std::string, Mix_Music*> music_table;
			static std::unordered_map <std::string, Mix_Chunk*> sound_table;

		public:
		//methods:
			static SDL_Texture* GetImage(std::string file);
			static void ClearImages();

			static Mix_Music* GetMusic(std::string file);
			static void ClearMusics();

			static Mix_Chunk* GetSound(std::string file);
			static void ClearSounds();
		
	};
	
#endif