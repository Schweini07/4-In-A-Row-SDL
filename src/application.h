#ifndef _APPLICATION_
#define _APPLICATION_

class Application {
    public:
        Application();
        ~Application();
        void renderObj(SDL_Rect rect, char *path);
        SDL_Renderer *renderer;
    
    private:
        SDL_Window *window;
};

#endif