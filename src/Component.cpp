#include "Component.h"
#include "GameObject.h"

Component::Component(GameObject *associated){
	this->associated = associated;
}

Component::~Component(){}

void Component::Clear(){
	delete associated;
}