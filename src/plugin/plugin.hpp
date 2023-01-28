#pragma once

#include <rofi/mode.h>

namespace Plugin {
int plugin_init(Mode *sw);
void plugin_destroy(Mode *sw);
unsigned int plugin_get_num_entries(const Mode *sw);
ModeMode plugin_result(Mode *sw, int mretv, char **input, unsigned int selectedLine);
int plugin_token_match(const Mode *sw, rofi_int_matcher **tokens, unsigned int index);
char *plugin_get_display_value(const Mode *sw, unsigned int selectedLine, int *state, GList **attrList, int getEntry);
cairo_surface_t *plugin_get_icon(const Mode *sw, unsigned int selected_line, unsigned int height);
char *plugin_preprocess_input(Mode *sw, const char *input);
char *plugin_get_help_message(const Mode *sw);
} // namespace Plugin
