#include "Root.h"


Root::Root()
{
	/* First thing we do is to create an event receiver and set it as our current event receiver.
	 This way we can create mutiple event receivers and switch between them.*/
	MastEventReceiver eventReceiver;
	currentEventReceiver = &eventReceiver;

	/* Next set all parameters for initial creation of the engine.*/
	inputs.AntiAlias = 1;
	inputs.Bits = 32;
	inputs.DeviceType = EIDT_BEST;
	inputs.DriverType = video::EDT_OPENGL;
	//inputs.EventReceiver = currentEventReceiver;
	inputs.UsePerformanceTimer = true;
	inputs.Vsync = true;
	inputs.WindowSize = core::dimension2d<u32>(640, 480);
	inputs.ZBufferBits = 16;
	
	/* Finally request pointers to all useful objects in Irrlicht.*/
	device = createDeviceEx(inputs);
	soundEngine = createIrrKlangDevice();
	driver = device->getVideoDriver();
	smgr = device->getSceneManager();
	guiEnv = device->getGUIEnvironment();

	device->setEventReceiver(&eventReceiver);
}

void Root::init()
{
	//currentEventReceiver->init();

	device->setWindowCaption(L"First proggy");

	soundEngine->play2D("explosion.wav", 1);
}

void Root::update()
{
	while (device->run())
	{
		/* Wait for events to be generated.*/
		//currentEventReceiver->endEventProcess();

		driver->beginScene(1, 1, video::SColor(255, 100, 100, 100));
		guiEnv->addStaticText(L"Hello world", core::rect<s32>(20, 20, 300, 300), 1);

		guiEnv->drawAll();
		smgr->drawAll();

		driver->endScene();

		/* Start processing generated events from this finished frame.*/
		//currentEventReceiver->startEventProcess();
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
