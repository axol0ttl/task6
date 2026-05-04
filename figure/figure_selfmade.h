//
// Created by arseny on 24/04/2026.
//
#pragma once

class figure_selfmade {
protected:
    float x, y;
    float r, g, b;
public:

    figure_selfmade(float x, float y, float r, float g, float b);
    virtual ~figure_selfmade();

    virtual void draw() = 0;
    virtual void erase() = 0;

    void move(float dx, float dy);
    void change_color(float r, float g, float b);
};