#include "UI.h"

static UI* g_ui = 0;

using namespace framework;

#define UI_HEIGHT 79

UI::UI(ultralight::Ref<ultralight::Renderer> renderer, ultralight::GPUDriver* driver, framework::Window& window) :
  renderer_(renderer),
  driver_(driver),
  window_(window),
  screen_width_(window.width()),
  ui_height_(UI_HEIGHT),
  tab_height_(window.height() - UI_HEIGHT),
  scale_((float)window.scale()),
  Overlay(renderer, driver, window.width(), UI_HEIGHT, 0, 0, (float)window.scale()) {
  g_ui = this;

  view()->set_load_listener(this);
  view()->LoadURL("file:///ui.html");
}

UI::~UI() {
  view()->set_load_listener(nullptr);
  g_ui = nullptr;
}

void UI::Draw() {
	Overlay::Draw();
}

void UI::Resize(int width, int height) {
	screen_width_ = window_.width();
	tab_height_ = window_.height() - UI_HEIGHT;
	Overlay::Resize(window_.width(), UI_HEIGHT);
}

void UI::OnDOMReady(ultralight::View* caller) {

}

//
// void UI::OnBack(const JSObject& obj, const JSArgs& args) {
//   if (active_tab())
//     active_tab()->view()->GoBack();
// }
//
// void UI::OnForward(const JSObject& obj, const JSArgs& args) {
//   if (active_tab())
//     active_tab()->view()->GoForward();
// }
//
// void UI::OnRefresh(const JSObject& obj, const JSArgs& args) {
//   if (active_tab())
//     active_tab()->view()->Reload();
// }
//
// void UI::OnStop(const JSObject& obj, const JSArgs& args) {
//   if (active_tab())
//     active_tab()->view()->Stop();
// }

//
// void UI::FireKeyEvent(const ultralight::KeyEvent& evt) {
//   if (tab_has_focus_ && !tabs_.empty())
//     tabs_[active_tab_id_]->FireKeyEvent(evt);
//   else
//     Overlay::FireKeyEvent(evt);
// }
//
// void UI::FireMouseEvent(const ultralight::MouseEvent& evt) {
//   if (evt.type == ultralight::MouseEvent::kType_MouseMoved) {
//     if (!tabs_.empty())
//       tabs_[active_tab_id_]->FireMouseEvent(evt);
//
//     Overlay::FireMouseEvent(evt);
//     return;
//   } else if (evt.type == ultralight::MouseEvent::kType_MouseDown &&
//              evt.button == ultralight::MouseEvent::kButton_Left) {
//     // Do Hit-Testing and Focus UI or Tab
//     tab_has_focus_ = evt.y > ui_height_;
//   }
//
//   if (tab_has_focus_ && !tabs_.empty())
//     tabs_[active_tab_id_]->FireMouseEvent(evt);
//   else
//     Overlay::FireMouseEvent(evt);
// }
//
// void UI::FireScrollEvent(const ultralight::ScrollEvent& evt) {
//   if (!tabs_.empty())
//     tabs_[active_tab_id_]->FireScrollEvent(evt);
// }

// void UI::OnBack(const JSObject& obj, const JSArgs& args) {
// 	if (active_tab())
// 		active_tab()->view()->GoBack();
// }

// void UI::OnDOMReady(ultralight::View* caller) {
// 	// Set the context for all subsequent JS* calls
// 	SetJSContext(view()->js_context());
//
// 	JSObject global = JSGlobalObject();
// 	updateBack = global["updateBack"];
// 	updateForward = global["updateForward"];
// 	updateLoading = global["updateLoading"];
// 	updateURL = global["updateURL"];
// 	addTab = global["addTab"];
// 	updateTab = global["updateTab"];
// 	closeTab = global["closeTab"];
//
// 	global["OnBack"] = BindJSCallback(&UI::OnBack);
// 	global["OnForward"] = BindJSCallback(&UI::OnForward);
// 	global["OnRefresh"] = BindJSCallback(&UI::OnRefresh);
// 	global["OnStop"] = BindJSCallback(&UI::OnStop);
// 	global["OnRequestNewTab"] = BindJSCallback(&UI::OnRequestNewTab);
// 	global["OnRequestTabClose"] = BindJSCallback(&UI::OnRequestTabClose);
// 	global["OnActiveTabChange"] = BindJSCallback(&UI::OnActiveTabChange);
// 	global["OnRequestChangeURL"] = BindJSCallback(&UI::OnRequestChangeURL);
//
// 	CreateNewTab();
// }