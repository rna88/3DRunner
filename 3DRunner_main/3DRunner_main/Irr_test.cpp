#include "irrlicht.h"
#include "irrKlang.h"
#include <iostream>
#include "Root.h"

using namespace std;
using namespace irr;
using namespace irrklang;

#pragma comment(lib, "Irrlicht.lib")
#pragma comment(lib, "IrrKlang.lib")


int main()
{
	Root Runner3D;
	Runner3D.playMedia();
	Runner3D.runGameLoop();

//	SIrrlichtCreationParameters inputs;
//	inputs.AntiAlias = 1;
//	inputs.Bits = 32;
//	inputs.DeviceType = EIDT_BEST;
//	inputs.DriverType = video::EDT_OPENGL;
//	inputs.UsePerformanceTimer = true;
//	inputs.Vsync = true;
//	inputs.WindowSize = core::dimension2d<u32>(640, 480);
//	inputs.ZBufferBits = 16;
//
////	IrrlichtDevice* device = createDevice(video::EDT_OPENGL, core::dimension2d<u32>(640, 480), 32, 0, 0, 0, 0);
//	IrrlichtDevice* device = createDeviceEx(inputs);
//	if (!device) return 1;
//
//	ISoundEngine* soundEngine = createIrrKlangDevice();
//	if (!soundEngine) return 1;
//
//	video::IVideoDriver* driver = device->getVideoDriver();
//	scene::ISceneManager* smgr = device->getSceneManager();
//	gui::IGUIEnvironment* guiEnv = device->getGUIEnvironment();
//
//	device->setWindowCaption(L"First proggy");
//	soundEngine->play2D("explosion.wav", 1);
//
//
//	while (device->run())
//	{
//		driver->beginScene(1, 1, video::SColor(255, 100, 100, 100));
//		guiEnv->addStaticText(L"Hello world", core::rect<s32>(20, 20, 300, 300), 1 );
//
//		guiEnv->drawAll();
//		smgr->drawAll();
//
//		driver->endScene();
//	}
//
//	device->closeDevice();
//
//	device = NULL;
//	soundEngine = NULL;
//	driver = NULL;
//	smgr = NULL;
//	guiEnv = NULL;
	return 0;
}