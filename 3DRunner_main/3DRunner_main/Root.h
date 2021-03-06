#pragma once
#include <irrlicht.h>
#include <irrKlang.h>
#include "MastiffEventReceiver.cpp"
#include <iostream> // Debug purposes

using namespace irr;
using namespace irrklang;

class Root
{
public:
	/* Default Constructor
	 Uses createDeviceEx to set some extra parameters. 
	 Parameters which werent included are left at their defaults.*/
	Root();

	/*Plays demo media.*/
	void Root::init();

	void Root::update();

	/* Destructor*/
	~Root();

private:

	SIrrlichtCreationParameters inputs;
	IrrlichtDevice* device;
	ISoundEngine* soundEngine;

	video::IVideoDriver* driver;
	scene::ISceneManager* smgr;
	gui::IGUIEnvironment* guiEnv;

	//MastEventReceiver eventReceiver;
	MastEventReceiver* currentEventReceiver;
	//IEventReceiver* currentEventReceiver;
};

