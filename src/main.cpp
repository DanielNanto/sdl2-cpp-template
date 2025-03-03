#if __linux__
  #include <SDL.h>
  #include <SDL_image.h>
  #include <SDL_mixer.h>
  #include <SDL_ttf.h>
#else
  #include <SDL2/SDL.h>
  #include <SDL2/SDL_image.h>
  #include <SDL2/SDL_mixer.h>
  #include <SDL2/SDL_ttf.h>
#endif

#include <iostream>
#include <cstdint>
#include "../include/utils.h"

int main(int argc, char** argv)
{
  int errors = 0;
  // Suppress compiler warnings:
  (void)argc;
  (void)argv;
 
  // Initialize SDL:
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
  {
    std::cout << "SDL_Init failed. SDL Error: "
              << SDL_GetError()
              << std::endl;
    ++errors;
  }
  else if (IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG)
  {
    std::cout << "IMG_Init failed. SDL_IMG Error: "
              << IMG_GetError()
              << std::endl;
    ++errors;
  }
  else if (TTF_Init() == -1)
  {
    std::cout << "TTF_Init failed. SDL_TTF Error: "
              << TTF_GetError()
              << std::endl;
    ++errors;
  }
  else if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) == -1)
  {
    std::cout << "Mix_OpenAudio failed. SDL_mixer Error: "
              << Mix_GetError()
              << std::endl;
    ++errors;
  }
  SDL_Window* Window = SDL_CreateWindow("sdl2-cpp-template",
                                        SDL_WINDOWPOS_CENTERED,
                                        SDL_WINDOWPOS_CENTERED,
                                        640,
                                        480,
                                        SDL_WINDOW_RESIZABLE);
  if (!Window)
  {
    std::cout << "SDL_CreateWindow failed. SDL Error: "
              << SDL_GetError()
              << std::endl;
    ++errors;
  }
  SDL_Renderer* Renderer = SDL_CreateRenderer(Window,
                                              -1,
                                              SDL_RENDERER_ACCELERATED |
                                              SDL_RENDERER_TARGETTEXTURE);
  if (!Renderer)
  {
    std::cout << "SDL_CreateRenderer failed. SDL Error: "
              << SDL_GetError()
              << std::endl;
    ++errors;
  }
  // TTF_Font* Font_hack_regular = TTF_OpenFont("data/ttf/Hack-Regular.ttf", 20);
  TTF_Font* Font_hack_regular = TTF_OpenFont(PROJECT_DIR "/data/ttf/Hack-Regular.ttf", 20);
  if (!Font_hack_regular)
  {
    std::cout << "TTF_OpenFont failed. SDL_TTF Error: "
              << TTF_GetError()
              << std::endl;
    ++errors;
  }
  if (errors != 0)
  {
    return errors; // If any of these initializations failed, exit from main.
  }
  // Various example variables:
  SDL_Color Background_color = {0xDA, 0xDA, 0xDA, 0xFF}; // RGBA
  SDL_Rect Background_rect = {0, 0, 0, 0}; // X Y W H
  SDL_GetWindowSize(Window,
                    &Background_rect.w,
                    &Background_rect.h);
  SDL_Color Font_color = {0xff, 0x00, 0x00, 0xff};
  SDL_Surface* Tmp_surface = TTF_RenderText_Blended(Font_hack_regular,
                                                    "-TEST-",
                                                    Font_color);
  SDL_Texture* Str_texture = SDL_CreateTextureFromSurface(Renderer,
                                                          Tmp_surface);
  SDL_FreeSurface(Tmp_surface);
  SDL_Rect Str_rect = {0, 0, 0, 0};
  SDL_QueryTexture(Str_texture,
                   NULL,
                   NULL,
                   &Str_rect.w,
                   &Str_rect.h);
  Str_rect.x = (Background_rect.w / 2) - (Str_rect.w / 2);
  Str_rect.y = (Background_rect.h / 2) - (Str_rect.h / 2);
  uint32_t time_last_rendered = SDL_GetTicks();
  uint32_t render_delay_ms = 1000 / 120; // 120 FPS
  bool live = (errors == 0) ? true : false;
  while (live == true)
  {
    uint32_t runtime_ms = SDL_GetTicks();
    if (unsigned_subtraction(runtime_ms, time_last_rendered) > render_delay_ms)
    {
      // Render the Background_rect:
      SDL_SetRenderDrawColor(Renderer,
                             Background_color.r,
                             Background_color.g,
                             Background_color.b,
                             Background_color.a);
      SDL_RenderFillRect(Renderer, &Background_rect);
      // Render the text:
      Str_rect.x = (Background_rect.w / 2) - (Str_rect.w / 2);
      Str_rect.y = (Background_rect.h / 2) - (Str_rect.h / 2);
      SDL_RenderCopy(Renderer,
                     Str_texture,
                     NULL,
                     &Str_rect);
      SDL_RenderPresent(Renderer);
      time_last_rendered = runtime_ms;
    }
    // Example events:
    SDL_Event Event;
    while (SDL_PollEvent(&Event))
    {
      // Exit event:
      if (Event.type == SDL_QUIT ||
          (Event.type == SDL_KEYDOWN && Event.key.keysym.sym == SDLK_ESCAPE))
      {
        std::cout << "Exiting...\n";
        live = false;
      }
      // Resize event:
      else if (Event.type == SDL_WINDOWEVENT &&
               Event.window.event == SDL_WINDOWEVENT_RESIZED)
      {
        std::cout << "Resizing SDL window...\n";
        SDL_GetWindowSize(Window,
                          &Background_rect.w,
                          &Background_rect.h);
      }
    }
  }
  // Memory clean-up upon exit:
  TTF_CloseFont(Font_hack_regular);
  SDL_DestroyTexture(Str_texture);
  SDL_DestroyRenderer(Renderer);
  SDL_DestroyWindow(Window);
  // De-initialize SDL and associated libraries:
  TTF_Quit();
  IMG_Quit();
  Mix_Quit();
  SDL_Quit();
  return errors;
}
