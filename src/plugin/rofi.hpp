#pragma once

#include <string>

typedef struct rofi_mode Mode;
typedef struct RofiViewState RofiViewState;
typedef char *(*PreprocessInputCallback)(Mode *sw, const char *input);

class Rofi {
  public:
    explicit Rofi(Mode *mode);
    ~Rofi(){};
    void fetch_state();

  private:
    std::string m_input;
    std::string m_overlay;
    RofiViewState *m_view_state = nullptr;
    Mode *m_current_mode = nullptr;
};
