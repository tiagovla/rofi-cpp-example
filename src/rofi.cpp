#include "plugin/rofi.hpp"
#include <exception>
#include <rofi/mode-private.h>
#include <rofi/mode.h>
#include <rofi/rofi-icon-fetcher.h>
#include <iostream>

extern "C" {
extern RofiViewState *rofi_view_get_active(void);
extern Mode *rofi_view_get_mode(RofiViewState *state);
extern void rofi_view_reload(void);
extern void rofi_view_switch_mode(RofiViewState *state, Mode *mode);
extern void rofi_view_set_overlay(RofiViewState *state, const char *text);
extern const char *rofi_view_get_user_input(const RofiViewState *state);
extern void rofi_view_clear_input(RofiViewState *state);
extern void rofi_view_handle_text(RofiViewState *state, char *text);
}


Rofi::Rofi(Mode *mode) : m_current_mode(mode){
};

void Rofi::fetch_state(){
    RofiViewState* view_state = rofi_view_get_active();
    if (view_state == nullptr) {
      std::cout << ("rofi view state is null");
    }
    Mode* current_mode = rofi_view_get_mode(view_state);
    if (current_mode == nullptr) {
      std::cout << ("rofi view mode is null");
    }
    auto user_input = rofi_view_get_user_input(view_state);
    std::cout << user_input;
};
