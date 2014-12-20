#include "irrlicht.h"
#include "irrKlang.h"
#include <iostream>

using namespace std;
using namespace irr;
using namespace irrklang;

#pragma comment(lib, "Irrlicht.lib")
#pragma comment(lib, "IrrKlang.lib")


int main()
{
	IrrlichtDevice* device = createDevice(video::EDT_OPENGL, core::dimension2d<u32>(640, 480), 32, 0, 0, 0, 0);
	if (!device) return 1;

	ISoundEngine* soundEngine = createIrrKlangDevice();
	if (!soundEngine) return 1;

	video::IVideoDriver* driver = device->getVideoDriver();
	scene::ISceneManager* smgr = device->getSceneManager();
	gui::IGUIEnvironment* guiEnv = device->getGUIEnvironment();

	device->setWindowCaption(L"First proggy");
	soundEngine->play2D("explosion.wav", 1);


	while (device->run())
	{
		driver->beginScene(1, 1, video::SColor(255, 100, 100, 100));
		guiEnv->addStaticText(L"Hello world", core::rect<s32>(20, 20, 300, 300), 1 );

		guiEnv->drawAll();
		smgr->drawAll();

		driver->endScene();
	}
	return 0;
}