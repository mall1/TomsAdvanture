#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <vector>
#include <string>
class Texture{
public:
    SDL_Surface * surface;
    std::string name;
    int id;
};

class TextureLib{
    static int maxid;
    std::vector<Texture> texture;

public:
    SDL_Surface * getTextureByName(std::string name);
    SDL_Surface * addTextureByName(std::string name);
    bool findTextureByName(std::string filename, SDL_Surface * &textureNum);
};
int TextureLib::maxid=0;

bool TextureLib::findTextureByName(std::string name, SDL_Surface * &surface){
    for(unsigned int i=0; i< texture.size();i++){
        if(texture[i].name==name){
            surface=texture[i].surface;
            return true;
        }
    }
    return false;
}


SDL_Surface * TextureLib::getTextureByName(std::string name){
    SDL_Surface * surface;
    if(findTextureByName(name, surface))
        return surface;
    else
        return addTextureByName(name);
}

SDL_Surface * TextureLib::addTextureByName(std::string name){
    SDL_Surface * surface;
    if(findTextureByName(name,surface))
        return surface;
    else{
        SDL_Surface* loadedImage = IMG_Load( name.c_str() );
        if( loadedImage != NULL )
        {
            surface = SDL_DisplayFormat( loadedImage );
            SDL_FreeSurface( loadedImage );
            if( surface != NULL ){
                Texture texture;
                texture.surface=surface;
                texture.id=maxid;
                texture.name=name;
                maxid++;
                this->texture.push_back(texture);

                SDL_SetColorKey( surface, SDL_SRCCOLORKEY, SDL_MapRGB( surface->format, 0, 0xFF, 0) );
                return surface;
            }
        }
        return NULL;
    }
}

#endif // TEXTURE_HPP
