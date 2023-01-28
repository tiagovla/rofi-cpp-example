#include "plugin/plugin.hpp"
#include <plugin/rofi.hpp>
#include <rofi/mode-private.h>
#include <rofi/mode.h>

Mode mode = {
    .abi_version = ABI_VERSION,
    .name = (char *)"example",
    .cfg_name_key = "display-example",
    ._init = Plugin::plugin_init,
    ._destroy = Plugin::plugin_destroy,
    ._get_num_entries = Plugin::plugin_get_num_entries,
    ._result = Plugin::plugin_result,
    ._token_match = Plugin::plugin_token_match,
    ._get_display_value = Plugin::plugin_get_display_value,
    ._get_icon = Plugin::plugin_get_icon,
    ._get_completion = nullptr,
    ._preprocess_input = Plugin::plugin_preprocess_input,
    ._get_message = Plugin::plugin_get_help_message,
    .private_data = nullptr,
    .free = nullptr,
    .ed = nullptr,
    .module = nullptr,
};
