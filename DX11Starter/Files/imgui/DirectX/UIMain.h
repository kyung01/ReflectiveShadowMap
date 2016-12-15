#pragma once
#include "Graphic\GraphicMain.h"
#include "Graphic\RenderTexture.h"
namespace NGame {
	class Context;
}
namespace NImGui {
	class UIMain {
	private:
		NGraphic::GraphicMain * graphicMain = 0;
		void render(std::map<NGraphic::KEnum,std::shared_ptr<NGraphic::RenderTexture>> renderTexutres);
		void render(std::map<NGraphic::KEnum, std::shared_ptr<NGraphic::DepthTexture>> depthTextures);
		void render(std::map<int, NGraphic::DepthTexture*> textures);
		void render(std::map<int, NGraphic::ReflectiveShadowMap> textures);
	protected:
	public:
		NGame::Context* gameContext;
		NGraphic::GraphicMain * graphicContext;
		void init(NGraphic::GraphicMain * graphicMain);
		void render();
		void update();

		int levelSelected = -1;
	};
}