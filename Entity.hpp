#pragma once

#include <SDL.h>

class Entity
{
public:
    Entity();
    ~Entity() = default;

    virtual void update(double delta_time, Entity& entity);
    virtual void handleEvents(SDL_Event const& event, float delta_time);
    virtual void draw(SDL_Surface* window_surface);

    bool wasHit(int proj_x, int proj_y);
    void takeDamage(int dmg);
    void init(SDL_Surface* window_surface);
    
    SDL_Surface* loadSurface(char const* path, SDL_Surface* window_surface);

protected:
    const int SCREEN_WIDTH{ 1366 };
    const int SCREEN_HEIGHT{ 768 };

    SDL_Surface* image;
    SDL_Rect     position;

    double velocity_x;
    double velocity_y;
    double speed;

    int m_damage;
    int health;
};
