#include "plugin/plugin.hpp"
#include "plugin/rofi.hpp"
#include <exception>
#include <iostream>
#include <rofi/mode-private.h>
#include <rofi/mode.h>

namespace {
Rofi *get_pd(Mode *sw) { return reinterpret_cast<Rofi *>(mode_get_private_data(sw)); }
void set_pd(Mode *sw, void *data) { mode_set_private_data(sw, data); }
} // namespace

int Plugin::plugin_init(Mode *sw) {
    if (mode_get_private_data(sw) == NULL) {
        void *pd = reinterpret_cast<void *>(new Rofi(sw));
        mode_set_private_data(sw, pd);
    }
    return TRUE;
}

void Plugin::plugin_destroy(Mode *sw) {
    auto *rofi = get_pd(sw);
    if (rofi != nullptr) {
        set_pd(sw, nullptr);
        delete rofi;
    }
}

unsigned int Plugin::plugin_get_num_entries(const Mode *) { return 0; }

ModeMode Plugin::plugin_result(Mode *sw, int mretv, char **input, unsigned int selectedLine) {
    if (mretv & MENU_NEXT) {
        std::cout << ("MENU_NEXT");
        return NEXT_DIALOG;
    }
    else if (mretv & MENU_PREVIOUS) {
      std::cout << ("MENU_PREVIOUS");
        return PREVIOUS_DIALOG;
    }
    else if (mretv & MENU_OK) {
      std::cout << ("MENU_OK");
        return RELOAD_DIALOG;
    }
    else if (mretv & MENU_ENTRY_DELETE) {
      std::cout << ("MENU_ENTRY_DELETE");
        return RELOAD_DIALOG;
    }
    else if (mretv & MENU_CUSTOM_INPUT) {
      auto *rofi = get_pd(sw);
      rofi->fetch_state();
      std::cout << ("MENU_CUSTOM_INPUT");
        return RELOAD_DIALOG;
    }
    else if (mretv & MENU_CANCEL) {
      std::cout << ("MENU_CANCEL");
        return MODE_EXIT;
    }
    else if (mretv & MENU_QUICK_SWITCH) {
      std::cout << ("MENU_QUICK_SWITCH");
        return static_cast<ModeMode>(mretv & MENU_LOWER_MASK);
    }
    return MODE_EXIT;
}

int Plugin::plugin_token_match(const Mode *, rofi_int_matcher **tokens, unsigned int index) { return TRUE; }
char *Plugin::plugin_get_display_value(const Mode *, unsigned int selectedLine, int *state, GList **, int getEntry) {
    return nullptr;
}
char *Plugin::plugin_get_help_message(const Mode *) { return nullptr; }
char *Plugin::plugin_preprocess_input(Mode *sw, const char *input) { return nullptr; }
cairo_surface_t *Plugin::plugin_get_icon(const Mode *sw, unsigned int selected_line, unsigned int height) {
    return nullptr;
}
