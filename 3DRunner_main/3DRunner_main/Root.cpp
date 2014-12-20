#include "Root.h"


Root::Root()
{
	inputs.AntiAlias = 1;
	inputs.Bits = 32;
	inputs.DeviceType = EIDT_BEST;
	inputs.DriverType = video::EDT_OPENGL;
	inputs.UsePerformanceTimer = true;
	inputs.Vsync = true;
	inputs.WindowSize = core::dimension2d<u32>(640, 480);
	inputs.ZBufferBits = 16;
	
	device = createDeviceEx(inputs);
	soundEngine = createIrrKlangDevice();
	driver = device->getVideoDriver();
	smgr = device->getSceneManager();
	guiEnv = device->getGUIEnvironment();
}

void Root::playMedia()
{
	device->setWindowCaption(L"First proggy");
	soundEngine->play2D("explosion.wav", 1);
}

void Root::runGameLoop()
{
	while (device->run())
	{
		driver->beginScene(1, 1, video::SColor(255, 100, 100, 100));
		guiEnv->addStaticText(L"Hello world", core::rect<s32>(20, 20, 300, 300), 1);

		guiEnv->drawAll();
		smgr->drawAll();

		driver->endScene();
	}
}


Root::~Root()
{
	soundEngine->drop();
	device->closeDevice();
	
	// do we still need to do this?
	device = NULL;
	soundEngine = NULL;
	driver = NULL;
	smgr = NULL;
	guiEnv = NULL;
}
