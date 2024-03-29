#ifndef STATE
#define STATE

	#include <vector>
	#include <memory>
	#include "TileMap.h"
	#include "Music.h"
	#include "GameObject.fwd.h"

	class State{
		private:
		//attributes:
			Sprite* bg;
			Music* music;
			bool quitRequested;
			std::vector< std::unique_ptr <GameObject> > object_array;

		//methods:
			void Input();
			void AddObject(int mouseX, int mouseY);

		public:
		//methods:
			State();
			~State();
			bool QuitRequested();
			void LoadAssets();
			void Update(float dt);
			void Render();
		
	};
	
#endif