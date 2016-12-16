#include "FlyingLightSource.h"
#include <Game\Context.h>
#include <iostream>
void NGame::NScript::FlyingLightSource::init(Context& context, Entity& me)
{
	progress = 0;
	progressDir = 1;
	rotationInit = me.rotation;
}

void NGame::NScript::FlyingLightSource::update(Context & context, Entity & me, float timeElapsed)
{
	progress += progressDir * timeElapsed*0.47;
	//if (abs(progress) > 1) {
	//	progress = progressDir;
	//	progressDir *= -1;
	//}
	me.setPos(-sin(progress)*2.5,2.0,-cos(progress) *2.5);

	me.setRotation(rotationInit
		* Quaternion::CreateFromAxisAngle(Vector3(0, 1, 0), progress));

		//* Quaternion::CreateFromAxisAngle(Vector3(0, 1, 0), progress*(3.14*0.5))
	
}
