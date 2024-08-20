#ifndef BUTTON_H
#define BUTTON_H

#include <SDL2/SDL.h>

#include "./texture.h"
#include "./ui_state_object.h"
#include "./text.h"

class Button : public UIStateObject
{
	public:
		Button( std::string content, int x, int y );

		Text& getText();

		void setText( std::string content );

		void loadTextTexture( SDL_Renderer* renderer );

		void render( SDL_Renderer* renderer ) override
		{
			if(getX() <= MINIMUM_WIDTH)
			{
				getTexture().render( getX(), 				 getY(), &getSpriteClip( getCurrentState() ), 			   0.0, NULL, SDL_FLIP_NONE, renderer );
				getTexture().render( getX() + BUTTON_HEIGHT, getY(), &getSpriteClip( OFFSET * 2 + getCurrentState() ), 0.0, NULL, SDL_FLIP_NONE, renderer );
			}
			else
			{
				const int MIDDLE_WIDTH = getX() - MINIMUM_WIDTH;
				getSpriteClip( OFFSET + getCurrentState() ).w = MIDDLE_WIDTH;

				getTexture().render( getX(), 								getY(), &getSpriteClip( getCurrentState() ), 			  0.0, NULL, SDL_FLIP_NONE, renderer );
				getTexture().render( getX() + BUTTON_HEIGHT, 				getY(), &getSpriteClip( OFFSET + getCurrentState() ), 	  0.0, NULL, SDL_FLIP_NONE, renderer );
				getTexture().render( getX() + MIDDLE_WIDTH + BUTTON_HEIGHT, getY(), &getSpriteClip( OFFSET * 2 + getCurrentState() ), 0.0, NULL, SDL_FLIP_NONE, renderer );
			}

			text.loadTexture( renderer );
			text.render     ( renderer );
			}

		void loadSpriteSheet( std::string path, SDL_Renderer* renderer );

	private:
		static const int OFFSET = 4;
		static const int BUTTON_HEIGHT = 32;
		static const int MINIMUM_WIDTH = BUTTON_HEIGHT * 2;

		Text text;
};

#endif // BUTTON_H

Button::Button( std::string content, int x, int y ): UIStateObject( x, y, 0, 0 )
{
	setText( content );

	int fontSize = getFontSize();
	int contentLength = ( content.length() - 1 ) * fontSize;

	setSize( contentLength + MINIMUM_WIDTH, BUTTON_HEIGHT );

	text.setPosition( x + getX() / 2 - contentLength / 2, y );
	setPosition( x, y );

	setCurrentState( UI_MOUSE_OUT );

	// Init left, middle and right sprite clips
	for( int i = 0; i < 12; i++ ) 
	{
		addSpriteClip();
	}
}

Text& Button::getText()
{
	return text;
}

void Button::setText( std::string content )
{
	text.updateContent( content );
}

void Button::loadTextTexture( SDL_Renderer* renderer )
{
	text.loadTexture( renderer );
}

void Button::loadSpriteSheet( std::string path, SDL_Renderer* renderer )
{
	getTexture().loadFromFile( path, renderer );

	// Update size and position for sprite clips
	for( int offset = 0; offset < 3; offset++ ) 	// Three parts: Left, Middle, Right
	{
		for( int index = 0; index < 4; index++ ) 	// Four states: Idle, Mouse Over, Mouse Down, Mouse Up
		{
			getSpriteClip( index + offset * 4 ).x = BUTTON_HEIGHT * offset;
			getSpriteClip( index + offset * 4 ).y = index * getY();
			getSpriteClip( index + offset * 4 ).w = getY();
			getSpriteClip( index + offset * 4 ).h = getY();
		}
	}
}
