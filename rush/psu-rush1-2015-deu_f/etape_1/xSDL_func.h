/*
** xSDL_func.h for  in /home/pidoux_q/epikong/etape_1
**
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
**
** Started on  Sat Mar  3 13:58:27 2012 quentin pidoux
** Last update Sat Mar  3 13:58:28 2012 quentin pidoux
*/

#ifndef			__XSDL_FUNC_H__
# define		__XSDL_FUNC_H__

# include		<SDL/SDL.h>
# include		<SDL/SDL_image.h>

SDL_Surface*	xSDL_SetVideoMode(int, int, int, Uint32);
SDL_Surface	*xIMG_Load(const char*);
void		xSDL_BlitSurface(SDL_Surface*, SDL_Rect*, SDL_Surface*, SDL_Rect*);
void		xSDL_Flip(SDL_Surface*);
void		xSDL_FillRect(SDL_Surface*, SDL_Rect*, Uint32);
Uint8		*xSDL_GetKeyState(int*);
void		xSDL_WaitEvent(SDL_Event*);

#endif			/* __XSDL_FUNC_H__ */
