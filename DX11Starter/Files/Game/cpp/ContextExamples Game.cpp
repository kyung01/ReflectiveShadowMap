#include <Game\ContextExamples.h>
#include <Game\Script\FlyingLightSource.h>
#include <Game\Script\Y_Axis_Rotate.h>
#include <Game\Script\X_Axis_Rotate.h>
using namespace NGame;

Entity* NGame::getLightEntity(NGraphic::NScene::Scene &scene, float r, float g, float b, float power)
{

	auto objLight = scene.getObjLight();
	auto objUI = scene.getObjUI();
	objUI->m_meshId = NGraphic::MESH_ID_SPHERE;
	objUI->setScale(Vector3(0.1, 0.1, 0.1));// = NGraphic::MESH_ID_SPHERE;
	objUI->m_textures[NGraphic::TEXTURE_TYPE_DEFAULT] = NGraphic::KEnum::TEXTURE_ID_WHITE;
	auto kEntity = new Entity();
	objLight->m_lightColor = Vector4(r,g,b,power);
	kEntity->m_graphicObjects.push_back(objLight);
	kEntity->m_graphicObjects.push_back(objUI);

	return kEntity;
}
/*
void NGame::LoadExample06(NGame::Context &context)
{
	auto ground = new Entity();

	NGraphic::KEnum meshIds[] = {
		NGraphic::MESH_ID_STONEHENGE_02,
		NGraphic::MESH_ID_STONEHENGE_06,
		NGraphic::MESH_ID_STONEHENGE_03,
		NGraphic::MESH_ID_STONEHENGE_00,
		NGraphic::MESH_ID_STONEHENGE_04,
		NGraphic::MESH_ID_STONEHENGE_05,
		NGraphic::MESH_ID_STONEHENGE_01 };
	NGraphic::KEnum meshIds2[] = {
		NGraphic::MESH_ID_CONE,
		NGraphic::MESH_ID_CUBE,
		NGraphic::MESH_ID_CYLINDER,
		NGraphic::MESH_ID_HELIX,
		NGraphic::MESH_ID_SPHERE,
		NGraphic::MESH_ID_TORUS,
		NGraphic::MESH_ID_SPHERE };
	NGraphic::KEnum normalIds[] = {
		NGraphic::TEXTURE_ID_NORMAL_BRICK,
		NGraphic::TEXTURE_ID_NORMAL_COUCH,
		NGraphic::TEXTURE_ID_NORMAL_DEFAULT,
		NGraphic::TEXTURE_ID_NORMAL_DIRT,
		NGraphic::TEXTURE_ID_NORMAL_ROCK,
		NGraphic::TEXTURE_ID_NORMAL_WOOD };
	NGraphic::KEnum reflectiveIds[] = {
		NGraphic::TEXTURE_ID_HEIGHT_DEFAULT,
		NGraphic::TEXTURE_ID_HEIGHT_BUMP,
		NGraphic::TEXTURE_ID_HEIGHT_CLOUD,
		NGraphic::TEXTURE_ID_HEIGHT_CIRCLES };

	float angle = 0;
	float distance = 3;
	{
		auto obj = context.m_scene->getObjSolid();
		obj.get()->m_meshId = NGraphic::MESH_ID_TERRAIN_00;
		obj.get()->m_textures[NGraphic::TEXTURE_TYPE_DIFFUSE] = NGraphic::KEnum::TEXTURE_ID_TEST_01;
		ground->m_graphicObjects.push_back(obj);
		ground->setPos(-25, 0, -25);
	}
	distance = 3;
	for (int i = 0; i < 6; i++) {
		angle = 3.14 / 6 * i;
		auto obj = context.m_scene->getObjSolid();
		obj.get()->m_meshId = NGraphic::MESH_ID_BUNNY;
		obj.get()->m_textures[NGraphic::TEXTURE_TYPE_NORMAL] = NGraphic::KEnum::TEXTURE_ID_NORMAL_DEFAULT;// normalIds[i % 6];
		obj.get()->m_textures[NGraphic::TEXTURE_TYPE_NORMAL] = normalIds[i % 6];
		obj.get()->m_textures[NGraphic::TEXTURE_TYPE_SPECULAR] = reflectiveIds[i % 4];
		obj.get()->setScale(Vector3(5.5, 5.5, 5.5));
		auto e = new Entity();
		context.addEntity(std::shared_ptr<Entity>(e));
		e->m_graphicObjects.push_back(obj);
		e->setPos(cos(angle)*distance, 0.4, sin(angle)*distance);
	}
	distance = 13;
	for (int i = 0; i < 7; i++) {
		angle = 3.14 / 6 * i;
		auto obj = context.m_scene->getObjSolid();
		obj.get()->m_meshId = meshIds[i];
		auto e = new Entity();
		context.addEntity(std::shared_ptr<Entity>(e));
		e->m_graphicObjects.push_back(obj);
		e->setPos(cos(angle)*distance, -0.25, sin(angle)*distance);
		e->setRotation(Quaternion::CreateFromAxisAngle(Vector3(0, 1, 0), 3.14 / 2 - 3.14 / 6 * i));
	}

	{
		distance = 6;
		angle = 0;
		auto obj = context.m_scene->getObjSolid();
		obj.get()->m_meshId = NGraphic::MESH_ID_CUBE;
		obj.get()->m_textures[NGraphic::TEXTURE_TYPE_NORMAL] = NGraphic::KEnum::TEXTURE_ID_NORMAL_DEFAULT;// normalIds[i % 6];
		obj.get()->m_textures[NGraphic::TEXTURE_TYPE_SPECULAR] = reflectiveIds[0 % 4];
		obj.get()->setScale(Vector3(1, 25, 25));
		auto e = new Entity();
		context.addEntity(std::shared_ptr<Entity>(e));
		e->m_graphicObjects.push_back(obj);
		e->setPos(5 + cos(angle)*distance, 0.3, sin(angle)*distance);
	}
	{
		distance = 3;
		angle = 0;
		auto obj = context.m_scene->getObjUI();
		obj.get()->m_meshId = NGraphic::MESH_ID_PLANE;
		obj.get()->m_textures[NGraphic::TEXTURE_TYPE_DEFAULT] = NGraphic::KEnum::TEXTURE_ID_ICN_LIGHT;
		obj.get()->setScale(Vector3(1, 1, 1));
		auto e = new NGame::Entity();
		context.addEntity(std::shared_ptr<NGame::Entity>(e));
		e->m_graphicObjects.push_back(obj);
		e->setPos(5 + cos(angle)*distance, 0.3, sin(angle)*distance);
	}

	distance = 5;
	for (int i = 0; i < 9; i++) {
		angle = 3.14 / 8 * i;
		auto obj = context.m_scene->getObjSolid();
		obj.get()->m_meshId = meshIds2[i % 7];
		obj.get()->m_textures[NGraphic::TEXTURE_TYPE_NORMAL] = normalIds[i % 6];
		obj.get()->m_textures[NGraphic::TEXTURE_TYPE_SPECULAR] = reflectiveIds[i % 4];
		obj.get()->m_textures[NGraphic::TEXTURE_TYPE_DIFFUSE] = NGraphic::KEnum::TEXTURE_ID_WHITE;
		auto e = new Entity();
		context.addEntity(std::shared_ptr<Entity>(e));
		e->m_graphicObjects.push_back(obj);
		e->setPos(cos(angle)*distance, 0.25, sin(angle)*distance);
	}
	{
		auto entityLight = getLightEntity(*context.m_scene, 1.0, 1.0, 1.0, 30);
		context.addEntity(std::shared_ptr<Entity>(entityLight));


		entityLight->setPos(0, 3.5, 0);
		entityLight->setRotation(Quaternion::CreateFromAxisAngle(Vector3(1, 0, 0), 3.14*0.25f));
		entityLight->addScript(context, std::shared_ptr<Script>(new NScript::Y_Axis_Rotate()));
	}
	{
		//auto obj = context.m_scene->getObjLight();
		//auto light = new Entity();
		//context.addEntity(std::shared_ptr<Entity>(light));
		//obj->m_lightColor = Vector4(1.0, 1.0, 1.0, 10);
		//light->m_graphicObjects.push_back(obj);
		//light->setPos(2, 5.5, 0);
		//light->setRotation(Quaternion::CreateFromAxisAngle(Vector3(1, 0, 0), 3.14*0.55f));
		//light->addScript(context, std::shared_ptr<Script>(new NScript::X_Axis_Rotate()));
	}

}
*/

void NGame::LoadExample00(NGame::Context &context)
{
	//smooth rabit
	float scale = 2.0;
	float fly = (scale) / 2 - 0.5;
	float d = (scale / 1.0) * 0.99;// 0.499;
	{
		//model
		auto obj = context.m_scene->getObjSolid();
		obj.get()->m_meshId = NGraphic::MESH_ID_BUNNY;
		obj->setScale(Vector3(11, 11, 11));

		auto e = new Entity();
		e->m_graphicObjects.push_back(obj);
		e->setRotation(Quaternion::CreateFromAxisAngle(Vector3(0, 1, 0), 3.14));
		e->setPos(-0.1, 0.41250 / 10 * 11, 0);
		context.addEntity(std::shared_ptr<Entity>(e));

	}
	{
		//ground
		auto obj = context.m_scene->getObjSolid();
		obj->setScale(Vector3(scale, scale, scale));
		obj.get()->m_meshId = NGraphic::MESH_ID_PLANE;
		obj.get()->m_textures[NGraphic::TEXTURE_TYPE_DIFFUSE] = NGraphic::TEXTURE_ID_BLUE;
		//ground->m_graphicObjects.push_back(obj);
		//ground->setPos(-25, 0, -25);
		auto e = new Entity();
		e->m_graphicObjects.push_back(obj);
		e->setRotation(Quaternion::CreateFromAxisAngle(Vector3(1, 0, 0), 3.14 * 0.5));
		e->setPos(0, 0, 0);
		context.addEntity(std::shared_ptr<Entity>(e));

	}
	{
		//up
		auto obj = context.m_scene->getObjSolid();
		obj->setScale(Vector3(scale, scale, scale));
		obj.get()->m_meshId = NGraphic::MESH_ID_PLANE;
		obj.get()->m_textures[NGraphic::TEXTURE_TYPE_DIFFUSE] = NGraphic::TEXTURE_ID_WHITE;
		//ground->m_graphicObjects.push_back(obj);
		//ground->setPos(-25, 0, -25);
		auto e = new Entity();
		e->m_graphicObjects.push_back(obj);
		e->setRotation(Quaternion::CreateFromAxisAngle(Vector3(1, 0, 0), 3.14 * -0.5));
		e->setPos(0, d + d / 2, 0);
		context.addEntity(std::shared_ptr<Entity>(e));

	}
	{
		//right
		auto obj = context.m_scene->getObjSolid();
		obj->setScale(Vector3(scale, scale, scale));
		obj.get()->m_meshId = NGraphic::MESH_ID_PLANE;
		obj.get()->m_textures[NGraphic::TEXTURE_TYPE_DIFFUSE] = NGraphic::TEXTURE_ID_GREEN;
		//ground->m_graphicObjects.push_back(obj);
		//ground->setPos(-25, 0, -25);
		auto e = new Entity();
		e->m_graphicObjects.push_back(obj);
		e->setRotation(Quaternion::CreateFromAxisAngle(Vector3(0, 1, 0), 3.14 * 0.5));
		e->setPos(d / 2, +d / 2, 0);
		context.addEntity(std::shared_ptr<Entity>(e));

	}
	{
		//left
		auto obj = context.m_scene->getObjSolid();
		obj->setScale(Vector3(scale, scale, scale));
		obj.get()->m_meshId = NGraphic::MESH_ID_PLANE;
		obj.get()->m_textures[NGraphic::TEXTURE_TYPE_DIFFUSE] = NGraphic::TEXTURE_ID_RED;
		//ground->m_graphicObjects.push_back(obj);
		//ground->setPos(-25, 0, -25);
		auto e = new Entity();
		e->m_graphicObjects.push_back(obj);
		e->setRotation(Quaternion::CreateFromAxisAngle(Vector3(0, 1, 0), 3.14 * -0.5));
		e->setPos(-d / 2, +d / 2, 0);
		context.addEntity(std::shared_ptr<Entity>(e));

	}
	{
		//front
		auto obj = context.m_scene->getObjSolid();
		obj->setScale(Vector3(scale, scale, scale));
		obj.get()->m_meshId = NGraphic::MESH_ID_PLANE;
		obj.get()->m_textures[NGraphic::TEXTURE_TYPE_DIFFUSE] = NGraphic::TEXTURE_ID_WHITE;
		//ground->m_graphicObjects.push_back(obj);
		//ground->setPos(-25, 0, -25);
		auto e = new Entity();
		e->m_graphicObjects.push_back(obj);
		e->setPos(0, 0 + d / 2, d / 2);
		context.addEntity(std::shared_ptr<Entity>(e));

	}
	{
		//back
		//auto obj = context.m_scene->getObjSolid();
		//obj->setScale(Vector3(scale, scale, scale));
		//obj.get()->m_meshId = NGraphic::MESH_ID_PLANE;
		//obj.get()->m_textures[NGraphic::TEXTURE_TYPE_DIFFUSE] = NGraphic::TEXTURE_ID_WHITE;
		////ground->m_graphicObjects.push_back(obj);
		////ground->setPos(-25, 0, -25);
		//auto e = new Entity();
		//e->m_graphicObjects.push_back(obj);
		//e->setRotation(Quaternion::CreateFromAxisAngle(Vector3(0, 1, 0), 3.14));
		//e->setPos(0, 0 + d / 2, -d/2);
		//context.addEntity(std::shared_ptr<Entity>(e));

	}
	{
		auto entityLight = getLightEntity(*context.m_scene, 1.0, 1.0, 1.0, 8.0f);
		context.addEntity(std::shared_ptr<Entity>(entityLight));


		entityLight->setPos(0, 2.0, -2.5);
		entityLight->setRotation(Quaternion::CreateFromAxisAngle(Vector3(1, 0, 0), 3.14*0.20f));
		//entityLight->addScript(context, std::shared_ptr<Script>(new NScript::X_Axis_Rotate()));
	}

}

void NGame::LoadExample01(NGame::Context &context)
{
	//smooth rabit
	float scale = 2.0;
	float fly = (scale) / 2 - 0.5;
	float d = (scale / 1.0) * 0.99;// 0.499;
	{
		//model
		auto obj = context.m_scene->getObjSolid();
		obj.get()->m_meshId = NGraphic::MESH_ID_SPHERE;
		obj->setScale(Vector3(1.5, 1.5, 1.5));

		auto e = new Entity();
		e->m_graphicObjects.push_back(obj);
		e->setRotation(Quaternion::CreateFromAxisAngle(Vector3(0, 1, 0), 3.14));
		e->setPos(0, 1.5/2, 0);
		context.addEntity(std::shared_ptr<Entity>(e));

	}
	{
		//ground
		auto obj = context.m_scene->getObjSolid();
		obj->setScale(Vector3(scale, scale, scale));
		obj.get()->m_meshId = NGraphic::MESH_ID_PLANE;
		obj.get()->m_textures[NGraphic::TEXTURE_TYPE_DIFFUSE] = NGraphic::TEXTURE_ID_BLUE;
		//ground->m_graphicObjects.push_back(obj);
		//ground->setPos(-25, 0, -25);
		auto e = new Entity();
		e->m_graphicObjects.push_back(obj);
		e->setRotation(Quaternion::CreateFromAxisAngle(Vector3(1, 0, 0), 3.14 * 0.5));
		e->setPos(0, 0, 0);
		context.addEntity(std::shared_ptr<Entity>(e));

	}
	{
		//up
		auto obj = context.m_scene->getObjSolid();
		obj->setScale(Vector3(scale, scale, scale));
		obj.get()->m_meshId = NGraphic::MESH_ID_PLANE;
		obj.get()->m_textures[NGraphic::TEXTURE_TYPE_DIFFUSE] = NGraphic::TEXTURE_ID_WHITE;
		//ground->m_graphicObjects.push_back(obj);
		//ground->setPos(-25, 0, -25);
		auto e = new Entity();
		e->m_graphicObjects.push_back(obj);
		e->setRotation(Quaternion::CreateFromAxisAngle(Vector3(1, 0, 0), 3.14 * -0.5));
		e->setPos(0, d + d / 2, 0);
		context.addEntity(std::shared_ptr<Entity>(e));

	}
	{
		//right
		auto obj = context.m_scene->getObjSolid();
		obj->setScale(Vector3(scale, scale, scale));
		obj.get()->m_meshId = NGraphic::MESH_ID_PLANE;
		obj.get()->m_textures[NGraphic::TEXTURE_TYPE_DIFFUSE] = NGraphic::TEXTURE_ID_GREEN;
		//ground->m_graphicObjects.push_back(obj);
		//ground->setPos(-25, 0, -25);
		auto e = new Entity();
		e->m_graphicObjects.push_back(obj);
		e->setRotation(Quaternion::CreateFromAxisAngle(Vector3(0, 1, 0), 3.14 * 0.5));
		e->setPos(d / 2, +d / 2, 0);
		context.addEntity(std::shared_ptr<Entity>(e));

	}
	{
		//left
		auto obj = context.m_scene->getObjSolid();
		obj->setScale(Vector3(scale, scale, scale));
		obj.get()->m_meshId = NGraphic::MESH_ID_PLANE;
		obj.get()->m_textures[NGraphic::TEXTURE_TYPE_DIFFUSE] = NGraphic::TEXTURE_ID_RED;
		//ground->m_graphicObjects.push_back(obj);
		//ground->setPos(-25, 0, -25);
		auto e = new Entity();
		e->m_graphicObjects.push_back(obj);
		e->setRotation(Quaternion::CreateFromAxisAngle(Vector3(0, 1, 0), 3.14 * -0.5));
		e->setPos(-d / 2, +d / 2, 0);
		context.addEntity(std::shared_ptr<Entity>(e));

	}
	{
		//front
		auto obj = context.m_scene->getObjSolid();
		obj->setScale(Vector3(scale, scale, scale));
		obj.get()->m_meshId = NGraphic::MESH_ID_PLANE;
		obj.get()->m_textures[NGraphic::TEXTURE_TYPE_DIFFUSE] = NGraphic::TEXTURE_ID_WHITE;
		//ground->m_graphicObjects.push_back(obj);
		//ground->setPos(-25, 0, -25);
		auto e = new Entity();
		e->m_graphicObjects.push_back(obj);
		e->setPos(0, 0 + d / 2, d / 2);
		context.addEntity(std::shared_ptr<Entity>(e));

	}
	{
		//back
		//auto obj = context.m_scene->getObjSolid();
		//obj->setScale(Vector3(scale, scale, scale));
		//obj.get()->m_meshId = NGraphic::MESH_ID_PLANE;
		//obj.get()->m_textures[NGraphic::TEXTURE_TYPE_DIFFUSE] = NGraphic::TEXTURE_ID_WHITE;
		////ground->m_graphicObjects.push_back(obj);
		////ground->setPos(-25, 0, -25);
		//auto e = new Entity();
		//e->m_graphicObjects.push_back(obj);
		//e->setRotation(Quaternion::CreateFromAxisAngle(Vector3(0, 1, 0), 3.14));
		//e->setPos(0, 0 + d / 2, -d/2);
		//context.addEntity(std::shared_ptr<Entity>(e));

	}
	{
		auto entityLight = getLightEntity(*context.m_scene, 1.0, 1.0, 1.0, 8.0f);
		context.addEntity(std::shared_ptr<Entity>(entityLight));


		entityLight->setPos(0, 2.0, -2.5);
		entityLight->setRotation(Quaternion::CreateFromAxisAngle(Vector3(1, 0, 0), 3.14*0.20f));
		//entityLight->addScript(context, std::shared_ptr<Script>(new NScript::X_Axis_Rotate()));
	}

}

void NGame::LoadExample02(NGame::Context &context)
{
	//smooth rabit
	float scale = 2.0;
	float fly = (scale) / 2 - 0.5;
	float d = (scale / 1.0) * 0.99;// 0.499;
	{
		//model
		auto obj = context.m_scene->getObjSolid();
		obj.get()->m_meshId = NGraphic::MESH_ID_BUNNY;
		obj.get()->m_textures[NGraphic::TEXTURE_TYPE_NORMAL] = NGraphic::TEXTURE_ID_NORMAL_DIRT;
		obj->setScale(Vector3(11, 11, 11));

		auto e = new Entity();
		e->m_graphicObjects.push_back(obj);
		e->setRotation(Quaternion::CreateFromAxisAngle(Vector3(0, 1, 0), 3.14));
		e->setPos(-0.1, 0.41250 / 10 * 11, 0);
		context.addEntity(std::shared_ptr<Entity>(e));

	}
	{
		//ground
		auto obj = context.m_scene->getObjSolid();
		obj->setScale(Vector3(scale, scale, scale));
		obj.get()->m_meshId = NGraphic::MESH_ID_PLANE;
		obj.get()->m_textures[NGraphic::TEXTURE_TYPE_DIFFUSE] = NGraphic::TEXTURE_ID_BLUE;
		//ground->m_graphicObjects.push_back(obj);
		//ground->setPos(-25, 0, -25);
		auto e = new Entity();
		e->m_graphicObjects.push_back(obj);
		e->setRotation(Quaternion::CreateFromAxisAngle(Vector3(1, 0, 0), 3.14 * 0.5));
		e->setPos(0, 0, 0);
		context.addEntity(std::shared_ptr<Entity>(e));

	}
	{
		//up
		auto obj = context.m_scene->getObjSolid();
		obj->setScale(Vector3(scale, scale, scale));
		obj.get()->m_meshId = NGraphic::MESH_ID_PLANE;
		obj.get()->m_textures[NGraphic::TEXTURE_TYPE_DIFFUSE] = NGraphic::TEXTURE_ID_WHITE;
		//ground->m_graphicObjects.push_back(obj);
		//ground->setPos(-25, 0, -25);
		auto e = new Entity();
		e->m_graphicObjects.push_back(obj);
		e->setRotation(Quaternion::CreateFromAxisAngle(Vector3(1, 0, 0), 3.14 * -0.5));
		e->setPos(0, d + d / 2, 0);
		context.addEntity(std::shared_ptr<Entity>(e));

	}
	{
		//right
		auto obj = context.m_scene->getObjSolid();
		obj->setScale(Vector3(scale, scale, scale));
		obj.get()->m_meshId = NGraphic::MESH_ID_PLANE;
		obj.get()->m_textures[NGraphic::TEXTURE_TYPE_DIFFUSE] = NGraphic::TEXTURE_ID_GREEN;
		//ground->m_graphicObjects.push_back(obj);
		//ground->setPos(-25, 0, -25);
		auto e = new Entity();
		e->m_graphicObjects.push_back(obj);
		e->setRotation(Quaternion::CreateFromAxisAngle(Vector3(0, 1, 0), 3.14 * 0.5));
		e->setPos(d / 2, +d / 2, 0);
		context.addEntity(std::shared_ptr<Entity>(e));

	}
	{
		//left
		auto obj = context.m_scene->getObjSolid();
		obj->setScale(Vector3(scale, scale, scale));
		obj.get()->m_meshId = NGraphic::MESH_ID_PLANE;
		obj.get()->m_textures[NGraphic::TEXTURE_TYPE_DIFFUSE] = NGraphic::TEXTURE_ID_RED;
		//ground->m_graphicObjects.push_back(obj);
		//ground->setPos(-25, 0, -25);
		auto e = new Entity();
		e->m_graphicObjects.push_back(obj);
		e->setRotation(Quaternion::CreateFromAxisAngle(Vector3(0, 1, 0), 3.14 * -0.5));
		e->setPos(-d / 2, +d / 2, 0);
		context.addEntity(std::shared_ptr<Entity>(e));

	}
	{
		//front
		auto obj = context.m_scene->getObjSolid();
		obj->setScale(Vector3(scale, scale, scale));
		obj.get()->m_meshId = NGraphic::MESH_ID_PLANE;
		obj.get()->m_textures[NGraphic::TEXTURE_TYPE_DIFFUSE] = NGraphic::TEXTURE_ID_WHITE;
		//ground->m_graphicObjects.push_back(obj);
		//ground->setPos(-25, 0, -25);
		auto e = new Entity();
		e->m_graphicObjects.push_back(obj);
		e->setPos(0, 0 + d / 2, d / 2);
		context.addEntity(std::shared_ptr<Entity>(e));

	}
	{
		//back
		//auto obj = context.m_scene->getObjSolid();
		//obj->setScale(Vector3(scale, scale, scale));
		//obj.get()->m_meshId = NGraphic::MESH_ID_PLANE;
		//obj.get()->m_textures[NGraphic::TEXTURE_TYPE_DIFFUSE] = NGraphic::TEXTURE_ID_WHITE;
		////ground->m_graphicObjects.push_back(obj);
		////ground->setPos(-25, 0, -25);
		//auto e = new Entity();
		//e->m_graphicObjects.push_back(obj);
		//e->setRotation(Quaternion::CreateFromAxisAngle(Vector3(0, 1, 0), 3.14));
		//e->setPos(0, 0 + d / 2, -d/2);
		//context.addEntity(std::shared_ptr<Entity>(e));

	}
	{
		auto entityLight = getLightEntity(*context.m_scene, 1.0, 1.0, 1.0, 8.0f);
		context.addEntity(std::shared_ptr<Entity>(entityLight));


		entityLight->setPos(0, 2.0, -2.5);
		entityLight->setRotation(Quaternion::CreateFromAxisAngle(Vector3(1, 0, 0), 3.14*0.20f));
		//entityLight->addScript(context, std::shared_ptr<Script>(new NScript::X_Axis_Rotate()));
	}

}

void NGame::LoadExample03(NGame::Context &context)
{
	//smooth rabit
	float scale = 2.0;
	float fly = (scale) / 2 - 0.5;
	float d = (scale / 1.0) * 0.99;// 0.499;
	{
		//model
		auto obj = context.m_scene->getObjSolid();
		obj.get()->m_meshId = NGraphic::MESH_ID_SPHERE;
		obj.get()->m_textures[NGraphic::TEXTURE_TYPE_NORMAL] = NGraphic::TEXTURE_ID_NORMAL_ROCK;
		obj->setScale(Vector3(1.5, 1.5, 1.5));

		auto e = new Entity();
		e->m_graphicObjects.push_back(obj);
		//e->setRotation(Quaternion::CreateFromAxisAngle(Vector3(0, 1, 0), 3.14));
		e->setPos(0, 1.5 / 2, 0);
		context.addEntity(std::shared_ptr<Entity>(e));

	}
	{
		//ground
		auto obj = context.m_scene->getObjSolid();
		obj->setScale(Vector3(scale, scale, scale));
		obj.get()->m_meshId = NGraphic::MESH_ID_PLANE;
		obj.get()->m_textures[NGraphic::TEXTURE_TYPE_DIFFUSE] = NGraphic::TEXTURE_ID_BLUE;
		//ground->m_graphicObjects.push_back(obj);
		//ground->setPos(-25, 0, -25);
		auto e = new Entity();
		e->m_graphicObjects.push_back(obj);
		e->setRotation(Quaternion::CreateFromAxisAngle(Vector3(1, 0, 0), 3.14 * 0.5));
		e->setPos(0, 0, 0);
		context.addEntity(std::shared_ptr<Entity>(e));

	}
	{
		//up
		auto obj = context.m_scene->getObjSolid();
		obj->setScale(Vector3(scale, scale, scale));
		obj.get()->m_meshId = NGraphic::MESH_ID_PLANE;
		obj.get()->m_textures[NGraphic::TEXTURE_TYPE_DIFFUSE] = NGraphic::TEXTURE_ID_WHITE;
		//ground->m_graphicObjects.push_back(obj);
		//ground->setPos(-25, 0, -25);
		auto e = new Entity();
		e->m_graphicObjects.push_back(obj);
		e->setRotation(Quaternion::CreateFromAxisAngle(Vector3(1, 0, 0), 3.14 * -0.5));
		e->setPos(0, d + d / 2, 0);
		context.addEntity(std::shared_ptr<Entity>(e));

	}
	{
		//right
		auto obj = context.m_scene->getObjSolid();
		obj->setScale(Vector3(scale, scale, scale));
		obj.get()->m_meshId = NGraphic::MESH_ID_PLANE;
		obj.get()->m_textures[NGraphic::TEXTURE_TYPE_DIFFUSE] = NGraphic::TEXTURE_ID_GREEN;
		//ground->m_graphicObjects.push_back(obj);
		//ground->setPos(-25, 0, -25);
		auto e = new Entity();
		e->m_graphicObjects.push_back(obj);
		e->setRotation(Quaternion::CreateFromAxisAngle(Vector3(0, 1, 0), 3.14 * 0.5));
		e->setPos(d / 2, +d / 2, 0);
		context.addEntity(std::shared_ptr<Entity>(e));

	}
	{
		//left
		auto obj = context.m_scene->getObjSolid();
		obj->setScale(Vector3(scale, scale, scale));
		obj.get()->m_meshId = NGraphic::MESH_ID_PLANE;
		obj.get()->m_textures[NGraphic::TEXTURE_TYPE_DIFFUSE] = NGraphic::TEXTURE_ID_RED;
		//ground->m_graphicObjects.push_back(obj);
		//ground->setPos(-25, 0, -25);
		auto e = new Entity();
		e->m_graphicObjects.push_back(obj);
		e->setRotation(Quaternion::CreateFromAxisAngle(Vector3(0, 1, 0), 3.14 * -0.5));
		e->setPos(-d / 2, +d / 2, 0);
		context.addEntity(std::shared_ptr<Entity>(e));

	}
	{
		//front
		auto obj = context.m_scene->getObjSolid();
		obj->setScale(Vector3(scale, scale, scale));
		obj.get()->m_meshId = NGraphic::MESH_ID_PLANE;
		obj.get()->m_textures[NGraphic::TEXTURE_TYPE_DIFFUSE] = NGraphic::TEXTURE_ID_WHITE;
		//ground->m_graphicObjects.push_back(obj);
		//ground->setPos(-25, 0, -25);
		auto e = new Entity();
		e->m_graphicObjects.push_back(obj);
		e->setPos(0, 0 + d / 2, d / 2);
		context.addEntity(std::shared_ptr<Entity>(e));

	}
	{
		//back
		//auto obj = context.m_scene->getObjSolid();
		//obj->setScale(Vector3(scale, scale, scale));
		//obj.get()->m_meshId = NGraphic::MESH_ID_PLANE;
		//obj.get()->m_textures[NGraphic::TEXTURE_TYPE_DIFFUSE] = NGraphic::TEXTURE_ID_WHITE;
		////ground->m_graphicObjects.push_back(obj);
		////ground->setPos(-25, 0, -25);
		//auto e = new Entity();
		//e->m_graphicObjects.push_back(obj);
		//e->setRotation(Quaternion::CreateFromAxisAngle(Vector3(0, 1, 0), 3.14));
		//e->setPos(0, 0 + d / 2, -d/2);
		//context.addEntity(std::shared_ptr<Entity>(e));

	}
	{
		auto entityLight = getLightEntity(*context.m_scene, 1.0, 1.0, 1.0, 8.0f);
		context.addEntity(std::shared_ptr<Entity>(entityLight));


		entityLight->setPos(0, 2.0, -2.5);
		entityLight->setRotation(Quaternion::CreateFromAxisAngle(Vector3(1, 0, 0), 3.14*0.20f));
		//entityLight->addScript(context, std::shared_ptr<Script>(new NScript::X_Axis_Rotate()));
	}

}

void NGame::LoadExample04(NGame::Context &context)
{
	//walls
	float scale = 4.0;
	float fly = (scale) / 2 - 0.5;
	float d = (scale / 1.0) * 0.99;// 0.499;
	{
		//model
		auto obj = context.m_scene->getObjSolid();
		obj.get()->m_meshId = NGraphic::MESH_ID_CUBE;
		obj.get()->m_textures[NGraphic::TEXTURE_TYPE_DIFFUSE] = NGraphic::TEXTURE_ID_RED;
		obj->setScale(Vector3(0.25, 1, 3));

		auto e = new Entity();
		e->m_graphicObjects.push_back(obj);
		e->setRotation(Quaternion::CreateFromAxisAngle(Vector3(0, 1, 0), 3.14));
		e->setPos(-1.5, .5, 0);
		context.addEntity(std::shared_ptr<Entity>(e));

	}
	{
		//model
		auto obj = context.m_scene->getObjSolid();
		obj.get()->m_meshId = NGraphic::MESH_ID_CUBE;
		obj.get()->m_textures[NGraphic::TEXTURE_TYPE_DIFFUSE] = NGraphic::TEXTURE_ID_RED;
		obj->setScale(Vector3(0.25, 1, 3));

		auto e = new Entity();
		e->m_graphicObjects.push_back(obj);
		e->setRotation(Quaternion::CreateFromAxisAngle(Vector3(0, 1, 0), 3.14));
		e->setPos(-1.0, .5, 0);
		context.addEntity(std::shared_ptr<Entity>(e));

	}
	{
		//model
		auto obj = context.m_scene->getObjSolid();
		obj.get()->m_meshId = NGraphic::MESH_ID_CUBE;
		obj.get()->m_textures[NGraphic::TEXTURE_TYPE_DIFFUSE] = NGraphic::TEXTURE_ID_RED;
		obj->setScale(Vector3(0.25, 1, 3));

		auto e = new Entity();
		e->m_graphicObjects.push_back(obj);
		e->setRotation(Quaternion::CreateFromAxisAngle(Vector3(0, 1, 0), 3.14));
		e->setPos(-0.5, .5, 0);
		context.addEntity(std::shared_ptr<Entity>(e));

	}

	{
		//model
		auto obj = context.m_scene->getObjSolid();
		obj.get()->m_meshId = NGraphic::MESH_ID_CUBE;
		obj.get()->m_textures[NGraphic::TEXTURE_TYPE_DIFFUSE] = NGraphic::TEXTURE_ID_GREEN;
		obj->setScale(Vector3(0.25, 2, 3));

		auto e = new Entity();
		e->m_graphicObjects.push_back(obj);
		e->setRotation(Quaternion::CreateFromAxisAngle(Vector3(0, 1, 0), 3.14));
		e->setPos(0.0, 1.0, 0);
		context.addEntity(std::shared_ptr<Entity>(e));

	}
	{
		//model
		auto obj = context.m_scene->getObjSolid();
		obj.get()->m_meshId = NGraphic::MESH_ID_CUBE;
		obj.get()->m_textures[NGraphic::TEXTURE_TYPE_DIFFUSE] = NGraphic::TEXTURE_ID_GREEN;
		obj->setScale(Vector3(0.25, 2, 3));

		auto e = new Entity();
		e->m_graphicObjects.push_back(obj);
		e->setRotation(Quaternion::CreateFromAxisAngle(Vector3(0, 1, 0), 3.14));
		e->setPos(0.5, 1.0, 0);
		context.addEntity(std::shared_ptr<Entity>(e));

	}
	{
		//model
		auto obj = context.m_scene->getObjSolid();
		obj.get()->m_meshId = NGraphic::MESH_ID_CUBE;
		obj.get()->m_textures[NGraphic::TEXTURE_TYPE_DIFFUSE] = NGraphic::TEXTURE_ID_GREEN;
		obj->setScale(Vector3(0.25, 2, 3));

		auto e = new Entity();
		e->m_graphicObjects.push_back(obj);
		e->setRotation(Quaternion::CreateFromAxisAngle(Vector3(0, 1, 0), 3.14));
		e->setPos(1.0, 1.0, 0);
		context.addEntity(std::shared_ptr<Entity>(e));

	}

	{
		//model
		auto obj = context.m_scene->getObjSolid();
		obj.get()->m_meshId = NGraphic::MESH_ID_CUBE;
		obj.get()->m_textures[NGraphic::TEXTURE_TYPE_DIFFUSE] = NGraphic::TEXTURE_ID_BLUE;
		obj->setScale(Vector3(0.25, 3, 3));

		auto e = new Entity();
		e->m_graphicObjects.push_back(obj);
		e->setRotation(Quaternion::CreateFromAxisAngle(Vector3(0, 1, 0), 3.14));
		e->setPos(1.5, 1.5, 0);
		context.addEntity(std::shared_ptr<Entity>(e));

	}
	{
		//ground
		auto obj = context.m_scene->getObjSolid();
		obj->setScale(Vector3(scale, scale, scale));
		obj.get()->m_meshId = NGraphic::MESH_ID_PLANE;
		obj.get()->m_textures[NGraphic::TEXTURE_TYPE_DIFFUSE] = NGraphic::TEXTURE_ID_WHITE;
		//ground->m_graphicObjects.push_back(obj);
		//ground->setPos(-25, 0, -25);
		auto e = new Entity();
		e->m_graphicObjects.push_back(obj);
		e->setRotation(Quaternion::CreateFromAxisAngle(Vector3(1, 0, 0), 3.14 * 0.5));
		e->setPos(0, 0, 0);
		context.addEntity(std::shared_ptr<Entity>(e));

	}
	{
		//up
		auto obj = context.m_scene->getObjSolid();
		obj->setScale(Vector3(scale, scale, scale));
		obj.get()->m_meshId = NGraphic::MESH_ID_PLANE;
		obj.get()->m_textures[NGraphic::TEXTURE_TYPE_DIFFUSE] = NGraphic::TEXTURE_ID_WHITE;
		//ground->m_graphicObjects.push_back(obj);
		//ground->setPos(-25, 0, -25);
		auto e = new Entity();
		e->m_graphicObjects.push_back(obj);
		e->setRotation(Quaternion::CreateFromAxisAngle(Vector3(1, 0, 0), 3.14 * -0.5));
		e->setPos(0, d + d / 2, 0);
		context.addEntity(std::shared_ptr<Entity>(e));

	}
	{
		//right
		auto obj = context.m_scene->getObjSolid();
		obj->setScale(Vector3(scale, scale, scale));
		obj.get()->m_meshId = NGraphic::MESH_ID_PLANE;
		obj.get()->m_textures[NGraphic::TEXTURE_TYPE_DIFFUSE] = NGraphic::TEXTURE_ID_WHITE;
		//ground->m_graphicObjects.push_back(obj);
		//ground->setPos(-25, 0, -25);
		auto e = new Entity();
		e->m_graphicObjects.push_back(obj);
		e->setRotation(Quaternion::CreateFromAxisAngle(Vector3(0, 1, 0), 3.14 * 0.5));
		e->setPos(d / 2, +d / 2, 0);
		context.addEntity(std::shared_ptr<Entity>(e));

	}
	
	{
		//front
		auto obj = context.m_scene->getObjSolid();
		obj->setScale(Vector3(scale, scale, scale));
		obj.get()->m_meshId = NGraphic::MESH_ID_PLANE;
		obj.get()->m_textures[NGraphic::TEXTURE_TYPE_DIFFUSE] = NGraphic::TEXTURE_ID_WHITE;
		//ground->m_graphicObjects.push_back(obj);
		//ground->setPos(-25, 0, -25);
		auto e = new Entity();
		e->m_graphicObjects.push_back(obj);
		e->setPos(0, 0 + d / 2, d / 2);
		context.addEntity(std::shared_ptr<Entity>(e));

	}
	{
		auto entityLight = getLightEntity(*context.m_scene, 1.0, 1.0, 1.0, 20.0f);
		context.addEntity(std::shared_ptr<Entity>(entityLight));


		entityLight->setPos(-3.5, 2.0, 0);
		entityLight->setRotation(
			Quaternion::CreateFromAxisAngle(Vector3(1, 0, 0), 3.14*0.10f)
			*Quaternion::CreateFromAxisAngle(Vector3(0, 1, 0), 3.14*0.50f));
		//entityLight->addScript(context, std::shared_ptr<Script>(new NScript::X_Axis_Rotate()));
	}

}

void NGame::LoadExample05(NGame::Context &context)
{
	//Moving light source
	float scale = 2.0;
	float fly = (scale) / 2 - 0.5;
	float d = (scale / 1.0) * 0.99;// 0.499;
	{
		//model
		auto obj = context.m_scene->getObjSolid();
		obj.get()->m_meshId = NGraphic::MESH_ID_BUNNY;
		obj->setScale(Vector3(11, 11, 11));

		auto e = new Entity();
		e->m_graphicObjects.push_back(obj);
		e->setRotation(Quaternion::CreateFromAxisAngle(Vector3(0, 1, 0), 3.14));
		e->setPos(-0.1, 0.41250 / 10 * 11, 0);
		context.addEntity(std::shared_ptr<Entity>(e));

	}
	{
		//ground
		auto obj = context.m_scene->getObjSolid();
		obj->setScale(Vector3(scale, scale, scale));
		obj.get()->m_meshId = NGraphic::MESH_ID_PLANE;
		obj.get()->m_textures[NGraphic::TEXTURE_TYPE_DIFFUSE] = NGraphic::TEXTURE_ID_BLUE;
		//ground->m_graphicObjects.push_back(obj);
		//ground->setPos(-25, 0, -25);
		auto e = new Entity();
		e->m_graphicObjects.push_back(obj);
		e->setRotation(Quaternion::CreateFromAxisAngle(Vector3(1, 0, 0), 3.14 * 0.5));
		e->setPos(0, 0, 0);
		context.addEntity(std::shared_ptr<Entity>(e));

	}
	{
		//up
		auto obj = context.m_scene->getObjSolid();
		obj->setScale(Vector3(scale, scale, scale));
		obj.get()->m_meshId = NGraphic::MESH_ID_PLANE;
		obj.get()->m_textures[NGraphic::TEXTURE_TYPE_DIFFUSE] = NGraphic::TEXTURE_ID_WHITE;
		//ground->m_graphicObjects.push_back(obj);
		//ground->setPos(-25, 0, -25);
		auto e = new Entity();
		e->m_graphicObjects.push_back(obj);
		e->setRotation(Quaternion::CreateFromAxisAngle(Vector3(1, 0, 0), 3.14 * -0.5));
		e->setPos(0, d + d / 2, 0);
		context.addEntity(std::shared_ptr<Entity>(e));

	}
	{
		//right
		auto obj = context.m_scene->getObjSolid();
		obj->setScale(Vector3(scale, scale, scale));
		obj.get()->m_meshId = NGraphic::MESH_ID_PLANE;
		obj.get()->m_textures[NGraphic::TEXTURE_TYPE_DIFFUSE] = NGraphic::TEXTURE_ID_GREEN;
		//ground->m_graphicObjects.push_back(obj);
		//ground->setPos(-25, 0, -25);
		auto e = new Entity();
		e->m_graphicObjects.push_back(obj);
		e->setRotation(Quaternion::CreateFromAxisAngle(Vector3(0, 1, 0), 3.14 * 0.5));
		e->setPos(d / 2, +d / 2, 0);
		context.addEntity(std::shared_ptr<Entity>(e));

	}
	{
		//left
		auto obj = context.m_scene->getObjSolid();
		obj->setScale(Vector3(scale, scale, scale));
		obj.get()->m_meshId = NGraphic::MESH_ID_PLANE;
		obj.get()->m_textures[NGraphic::TEXTURE_TYPE_DIFFUSE] = NGraphic::TEXTURE_ID_RED;
		//ground->m_graphicObjects.push_back(obj);
		//ground->setPos(-25, 0, -25);
		auto e = new Entity();
		e->m_graphicObjects.push_back(obj);
		e->setRotation(Quaternion::CreateFromAxisAngle(Vector3(0, 1, 0), 3.14 * -0.5));
		e->setPos(-d / 2, +d / 2, 0);
		context.addEntity(std::shared_ptr<Entity>(e));

	}
	{
		//front
		auto obj = context.m_scene->getObjSolid();
		obj->setScale(Vector3(scale, scale, scale));
		obj.get()->m_meshId = NGraphic::MESH_ID_PLANE;
		obj.get()->m_textures[NGraphic::TEXTURE_TYPE_DIFFUSE] = NGraphic::TEXTURE_ID_WHITE;
		//ground->m_graphicObjects.push_back(obj);
		//ground->setPos(-25, 0, -25);
		auto e = new Entity();
		e->m_graphicObjects.push_back(obj);
		e->setPos(0, 0 + d / 2, d / 2);
		context.addEntity(std::shared_ptr<Entity>(e));

	}
	{
		//back
		auto obj = context.m_scene->getObjSolid();
		obj->setScale(Vector3(scale, scale, scale));
		obj.get()->m_meshId = NGraphic::MESH_ID_PLANE;
		obj.get()->m_textures[NGraphic::TEXTURE_TYPE_DIFFUSE] = NGraphic::TEXTURE_ID_WHITE;
		//ground->m_graphicObjects.push_back(obj);
		//ground->setPos(-25, 0, -25);
		auto e = new Entity();
		e->m_graphicObjects.push_back(obj);
		e->setRotation(Quaternion::CreateFromAxisAngle(Vector3(0, 1, 0), 3.14));
		e->setPos(0, 0 + d / 2, -d/2);
		context.addEntity(std::shared_ptr<Entity>(e));

	}
	{
		auto entityLight = getLightEntity(*context.m_scene, 1.0, 1.0, 1.0, 8.0f);
		context.addEntity(std::shared_ptr<Entity>(entityLight));


		entityLight->setPos(0, 2.0, -2.5);
		entityLight->setRotation(Quaternion::CreateFromAxisAngle(Vector3(1, 0, 0), 3.14*0.20f));
		entityLight->addScript(context, std::shared_ptr<Script>(new NScript::FlyingLightSource()));
	}

}

void NGame::LoadExample06(NGame::Context &context)
{
	//smooth rabit
	float scale = 2.0;
	float fly = (scale) / 2 - 0.5;
	float d = (scale / 1.0) * 0.99;// 0.499;
	{
		//model
		auto obj = context.m_scene->getObjSolid();
		obj.get()->m_meshId = NGraphic::MESH_ID_BUNNY;
		obj->setScale(Vector3(10, 10, 10));

		auto e = new Entity();
		e->m_graphicObjects.push_back(obj);
		e->setRotation(Quaternion::CreateFromAxisAngle(Vector3(0, 1, 0), 3.14));
		e->setPos(0.00, 0.41250 / 10 * 10, 0);
		context.addEntity(std::shared_ptr<Entity>(e));
		e->addScript(context, std::shared_ptr<Script>(new NScript::Y_Axis_Rotate()));

	}
	{
		//ground
		auto obj = context.m_scene->getObjSolid();
		obj->setScale(Vector3(scale, scale, scale));
		obj.get()->m_meshId = NGraphic::MESH_ID_PLANE;
		obj.get()->m_textures[NGraphic::TEXTURE_TYPE_DIFFUSE] = NGraphic::TEXTURE_ID_BLUE;
		//ground->m_graphicObjects.push_back(obj);
		//ground->setPos(-25, 0, -25);
		auto e = new Entity();
		e->m_graphicObjects.push_back(obj);
		e->setRotation(Quaternion::CreateFromAxisAngle(Vector3(1, 0, 0), 3.14 * 0.5));
		e->setPos(0, 0, 0);
		context.addEntity(std::shared_ptr<Entity>(e));

	}
	{
		//up
		auto obj = context.m_scene->getObjSolid();
		obj->setScale(Vector3(scale, scale, scale));
		obj.get()->m_meshId = NGraphic::MESH_ID_PLANE;
		obj.get()->m_textures[NGraphic::TEXTURE_TYPE_DIFFUSE] = NGraphic::TEXTURE_ID_WHITE;
		//ground->m_graphicObjects.push_back(obj);
		//ground->setPos(-25, 0, -25);
		auto e = new Entity();
		e->m_graphicObjects.push_back(obj);
		e->setRotation(Quaternion::CreateFromAxisAngle(Vector3(1, 0, 0), 3.14 * -0.5));
		e->setPos(0, d + d / 2, 0);
		context.addEntity(std::shared_ptr<Entity>(e));

	}
	{
		//right
		auto obj = context.m_scene->getObjSolid();
		obj->setScale(Vector3(scale, scale, scale));
		obj.get()->m_meshId = NGraphic::MESH_ID_PLANE;
		obj.get()->m_textures[NGraphic::TEXTURE_TYPE_DIFFUSE] = NGraphic::TEXTURE_ID_GREEN;
		//ground->m_graphicObjects.push_back(obj);
		//ground->setPos(-25, 0, -25);
		auto e = new Entity();
		e->m_graphicObjects.push_back(obj);
		e->setRotation(Quaternion::CreateFromAxisAngle(Vector3(0, 1, 0), 3.14 * 0.5));
		e->setPos(d / 2, +d / 2, 0);
		context.addEntity(std::shared_ptr<Entity>(e));

	}
	{
		//left
		auto obj = context.m_scene->getObjSolid();
		obj->setScale(Vector3(scale, scale, scale));
		obj.get()->m_meshId = NGraphic::MESH_ID_PLANE;
		obj.get()->m_textures[NGraphic::TEXTURE_TYPE_DIFFUSE] = NGraphic::TEXTURE_ID_RED;
		//ground->m_graphicObjects.push_back(obj);
		//ground->setPos(-25, 0, -25);
		auto e = new Entity();
		e->m_graphicObjects.push_back(obj);
		e->setRotation(Quaternion::CreateFromAxisAngle(Vector3(0, 1, 0), 3.14 * -0.5));
		e->setPos(-d / 2, +d / 2, 0);
		context.addEntity(std::shared_ptr<Entity>(e));

	}
	{
		//front
		auto obj = context.m_scene->getObjSolid();
		obj->setScale(Vector3(scale, scale, scale));
		obj.get()->m_meshId = NGraphic::MESH_ID_PLANE;
		obj.get()->m_textures[NGraphic::TEXTURE_TYPE_DIFFUSE] = NGraphic::TEXTURE_ID_WHITE;
		//ground->m_graphicObjects.push_back(obj);
		//ground->setPos(-25, 0, -25);
		auto e = new Entity();
		e->m_graphicObjects.push_back(obj);
		e->setPos(0, 0 + d / 2, d / 2);
		context.addEntity(std::shared_ptr<Entity>(e));

	}
	{
		//back
		//auto obj = context.m_scene->getObjSolid();
		//obj->setScale(Vector3(scale, scale, scale));
		//obj.get()->m_meshId = NGraphic::MESH_ID_PLANE;
		//obj.get()->m_textures[NGraphic::TEXTURE_TYPE_DIFFUSE] = NGraphic::TEXTURE_ID_WHITE;
		////ground->m_graphicObjects.push_back(obj);
		////ground->setPos(-25, 0, -25);
		//auto e = new Entity();
		//e->m_graphicObjects.push_back(obj);
		//e->setRotation(Quaternion::CreateFromAxisAngle(Vector3(0, 1, 0), 3.14));
		//e->setPos(0, 0 + d / 2, -d/2);
		//context.addEntity(std::shared_ptr<Entity>(e));

	}
	{
		auto entityLight = getLightEntity(*context.m_scene, 1.0, 1.0, 1.0, 8.0f);
		context.addEntity(std::shared_ptr<Entity>(entityLight));


		entityLight->setPos(0, 2.0, -2.5);
		entityLight->setRotation(Quaternion::CreateFromAxisAngle(Vector3(1, 0, 0), 3.14*0.20f));
		//entityLight->addScript(context, std::shared_ptr<Script>(new NScript::X_Axis_Rotate()));
	}

}
