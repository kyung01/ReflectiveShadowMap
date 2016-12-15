#include "imgui\DirectX\UIMain.h"
#include "imgui\imgui.h"
#include <Game\ContextExamples.h>
using namespace NImGui;
using namespace NGraphic;


void NImGui::UIMain::init(GraphicMain * graphicMain)
{
	this->graphicMain = graphicMain;
}
void NImGui::UIMain::render(std::map<KEnum, std::shared_ptr<RenderTexture>> renderTexutres)
{
	ImGui::Begin("RenderTextures Demo", 0, ImGuiWindowFlags_ShowBorders);

	for (auto it = renderTexutres.begin(); it != renderTexutres.end(); it++) {
		ImGui::Text("RenderTextures", 500, 500);
		ImTextureID tex_id = it->second->getShaderResourceView();
		//ImTextureID tex_id = ImGui::GetIO().Fonts->TexID;
		ImGui::Text("%.0fx%.0f", 500, 500);
		ImGui::Image(tex_id, ImVec2(500, 500), ImVec2(0, 0), ImVec2(1, 1), ImColor(255, 255, 255, 255), ImColor(255, 255, 255, 128));

	}
	ImGui::End();
}
void NImGui::UIMain::render(std::map<int, DepthTexture*> textures)
{
	ImGui::Begin("LightSource DepthTextures Demo", 0, ImGuiWindowFlags_ShowBorders);

	for (auto it = textures.begin(); it != textures.end(); it++) {
		ImGui::Text("" + it->first, 500, 500);
		ImTextureID tex_id = it->second->getShaderResourceView();
		//ImTextureID tex_id = ImGui::GetIO().Fonts->TexID;
		//ImGui::Text("%.0fx%.0f", 500, 500);
		ImGui::Image(tex_id, ImVec2(500, 500), ImVec2(0, 0), ImVec2(1, 1), ImColor(255, 255, 255, 255), ImColor(255, 255, 255, 128));

	}
	ImGui::End();
}
void NImGui::UIMain::render(std::map<KEnum, std::shared_ptr<DepthTexture>> textures)
{
	ImGui::Begin("DepthTextures Demo", 0, ImGuiWindowFlags_ShowBorders);

	for (auto it = textures.begin(); it != textures.end(); it++) {
		ImGui::Text("" + it->first, 500, 500);
		ImTextureID tex_id = it->second->getShaderResourceView();
		//ImTextureID tex_id = ImGui::GetIO().Fonts->TexID;
		//ImGui::Text("%.0fx%.0f", 500, 500);
		ImGui::Image(tex_id, ImVec2(500, 500), ImVec2(0, 0), ImVec2(1, 1), ImColor(255, 255, 255, 255), ImColor(255, 255, 255, 128));

	}
	ImGui::End();
}
void NImGui::UIMain::render(std::map<int, ReflectiveShadowMap> textures)
{
	ImGui::Begin("ReflectiveShadowMaps", 0, ImGuiWindowFlags_ShowBorders);
	for (auto it = textures.begin(); it != textures.end(); it++) {
		ImGui::Text("REFLECTIVE SHADOW MAP", 500, 500);
		ImTextureID normal = it->second.normal->getShaderResourceView();
		ImTextureID flux = it->second.flux->getShaderResourceView();
		ImTextureID depth = it->second.depth->getShaderResourceView();
		ImGui::Image(normal, ImVec2(500, 500), ImVec2(0, 0), ImVec2(1, 1), ImColor(255, 255, 255, 255), ImColor(255, 255, 255, 128));
		ImGui::Image(flux, ImVec2(500, 500), ImVec2(0, 0), ImVec2(1, 1), ImColor(255, 255, 255, 255), ImColor(255, 255, 255, 128));
		ImGui::Image(it->second.fluxEye->getShaderResourceView(), ImVec2(500, 500), ImVec2(0, 0), ImVec2(1, 1), ImColor(255, 255, 255, 255), ImColor(255, 255, 255, 128));
		ImGui::Image(depth, ImVec2(500, 500), ImVec2(0, 0), ImVec2(1, 1), ImColor(255, 255, 255, 255), ImColor(255, 255, 255, 128));
	}
	ImGui::End();
}
void NImGui::UIMain::update() {
	if (levelSelected != -1) {
		gameContext->clear();
		switch (levelSelected) {
		default:
		case 0:
		case 1:
			NGame::LoadExample01(*gameContext);
			break;
		}
	}
}
void NImGui::UIMain::render()
{
	if (!graphicMain) return; // I don't have a pointer to the instance needed to initate drawing cycle

	//ImGui::ShowTestWindow();
	levelSelected = -1;
	ImGui::BeginMainMenuBar();
	if (ImGui::BeginMenu("Load"))
	{
		ImGui::Text("Please select different options in order to load different example scenes");
		
		if (ImGui::MenuItem("Smooth", "Best case, smooth surfaces with less number of objects in a scene")) {
			levelSelected = 0;
		}
		ImGui::Text("However due to the fact that I am over-rendering high quality pixels at certain pixels\n(because low resolution reflective map is insufficient for detailed areas), you can see tiny stripe patterns");
		if (ImGui::MenuItem("Rough", "Increased performance requirement. Rough normals")) {
			levelSelected = 1;
		}
		if (ImGui::MenuItem("Smooth vs Rough", "Take a look at both of them to compare")) {
			levelSelected = 2;
		}
		if (ImGui::MenuItem("Multiple Objects", "The imperfect nature of reflective shadowmap is more visible. Increasing sampling can reduce the artifacts.")) {
			levelSelected = 3;
		}
		if (ImGui::MenuItem("Walls", "Reflective Shadowmap doesn't consider obstacles blocking ray's path")) {
			levelSelected = 4;
		}
		if (ImGui::MenuItem("Moving Light Source", "Due to the sampling pattern, there is spot where it lightens brighter than the other parts. Better sampling pattern can reduce artifacts.")) {
			levelSelected = 5;
		}
		if (ImGui::MenuItem("Crazy", "Go crazy.")) {
			levelSelected = 6;
		}


		//ShowExampleMenuFile();
		ImGui::EndMenu();
	}
	render(graphicMain->m_RSM);
	render(graphicMain->m_renderTextures);

	if (ImGui::BeginMenu("Edit"))
	{
		if (ImGui::MenuItem("Undo", "CTRL+Z")) {}
		ImGui::Separator();
		ImGui::EndMenu();
	}


	ImGui::EndMainMenuBar();
	
}
/*

render(graphicMain->m_renderTextures);
render(graphicMain->m_depthTextures);
//render(graphicMain->m_lightDepthTextures);
render(graphicMain->m_RSM);
ImGui::Begin("SceneSelector", 0, 0);
ImGui::Text("BestScenarios");
for (int i = 0; i < 7; i++)
{
if (i > 0) ImGui::SameLine();
ImGui::PushID(i);
ImGui::PushStyleColor(ImGuiCol_Button, ImColor::HSV(i / 7.0f, 0.6f, 0.6f));
ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImColor::HSV(i / 7.0f, 0.7f, 0.7f));
ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImColor::HSV(i / 7.0f, 0.8f, 0.8f));
ImGui::Button("Click");
ImGui::PopStyleColor(3);
ImGui::PopID();
}
ImGui::End();

/*
ImGui::Begin("Other window", 0, ImGuiWindowFlags_ShowBorders);

if (ImGui::TreeNode("Images"))
{
ImGui::TextWrapped("Below we are displaying the font texture (which is the only texture we have access to in this demo). Use the 'ImTextureID' type as storage to pass pointers or identifier to your own texture data. Hover the texture for a zoomed view!");
ImVec2 tex_screen_pos = ImGui::GetCursorScreenPos();
float tex_w = 100;
float tex_h = 100;
ImTextureID tex_id = graphicMain->m_renderTextures.begin()->second->GetShaderResourceView();
//ImTextureID tex_id = ImGui::GetIO().Fonts->TexID;
ImGui::Text("%.0fx%.0f", tex_w, tex_h);
ImGui::Image(tex_id, ImVec2(tex_w, tex_h), ImVec2(0, 0), ImVec2(1, 1), ImColor(255, 255, 255, 255), ImColor(255, 255, 255, 128));
if (ImGui::IsItemHovered())
{
ImGui::BeginTooltip();
float focus_sz = 32.0f;
float focus_x = ImGui::GetMousePos().x - tex_screen_pos.x - focus_sz * 0.5f; if (focus_x < 0.0f) focus_x = 0.0f; else if (focus_x > tex_w - focus_sz) focus_x = tex_w - focus_sz;
float focus_y = ImGui::GetMousePos().y - tex_screen_pos.y - focus_sz * 0.5f; if (focus_y < 0.0f) focus_y = 0.0f; else if (focus_y > tex_h - focus_sz) focus_y = tex_h - focus_sz;
ImGui::Text("Min: (%.2f, %.2f)", focus_x, focus_y);
ImGui::Text("Max: (%.2f, %.2f)", focus_x + focus_sz, focus_y + focus_sz);
ImVec2 uv0 = ImVec2((focus_x) / tex_w, (focus_y) / tex_h);
ImVec2 uv1 = ImVec2((focus_x + focus_sz) / tex_w, (focus_y + focus_sz) / tex_h);
ImGui::Image(tex_id, ImVec2(128, 128), uv0, uv1, ImColor(255, 255, 255, 255), ImColor(255, 255, 255, 128));
ImGui::EndTooltip();
}
ImGui::TextWrapped("And now some textured buttons..");
static int pressed_count = 0;
for (int i = 0; i < 8; i++)
{
ImGui::PushID(i);
int frame_padding = -1 + i;     // -1 = uses default padding
if (ImGui::ImageButton(tex_id, ImVec2(32, 32), ImVec2(0, 0), ImVec2(32.0f / tex_w, 32 / tex_h), frame_padding, ImColor(0, 0, 0, 255)))
pressed_count += 1;
ImGui::PopID();
ImGui::SameLine();
}
ImGui::NewLine();
ImGui::Text("Pressed %d times.", pressed_count);
ImGui::TreePop();
}
ImGui::End();


ImGui::ShowTestWindow();
ImGui::Text("hiworld");
**/
