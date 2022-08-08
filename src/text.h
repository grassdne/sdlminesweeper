#ifndef TEXT_H
#define TEXT_H

#include <SDL_ttf.h>
#include <SDL.h>
#include <string>
#include "texture.h"

class Text {
public:
    Text(TTF_Font *font = nullptr, std::string string_={}, SDL_Color color_ = {0,0,0,0});
    ~Text() = default;

    void render();
    void load();

    void setFont(TTF_Font *font_) {
        font = font_;
        loaded = false;
    }
    void setString(std::string string_) {
        string = string_;
        loaded = false;
    }
    void setColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a = 0xFF) {
        color.r = r;
        color.g = g;
        color.b = b;
        color.a = a;
        loaded = false;
    }
    void setScale(double scale_) {
        scale = scale_;
        // Update texture if loaded
        if (loaded) tex.setScale(scale);
    }

    [[nodiscard]] int getWidth() const { return tex.getWidth(); }
    [[nodiscard]] int getHeight() const { return tex.getHeight(); }

    int x, y;

    bool loaded = false;
    TTF_Font *font;
    std::string string;
    SDL_Color color;
    float scale;

private:
    Texture tex;
};

#endif
