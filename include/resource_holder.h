#ifndef RESOURCE_HOLDER_H_
#define RESOURCE_HOLDER_H_

#include <memory>
#include <string>
#include <map>
#include <cassert>

namespace sf {
    class Texture;
    class Font;
}

namespace Textures {
    enum ID { BACKGROUND, GRASS, STONE, CLOUD, EARTH, ICE, COIN, DOODLE };
}

namespace Fonts {
    enum ID { MAIN };
}

template <typename Resource, typename Identifier>
class ResourceHolder {
 public:
    static ResourceHolder* getInstance();
    void load(Identifier id, const std::string &filepath);
    Resource& get(Identifier id);
    const Resource& get(Identifier id) const;

 private:
    ResourceHolder();
    ~ResourceHolder();

    static ResourceHolder* resource_holder_;
    std::map<Identifier, std::unique_ptr<Resource > > resource_map_;
};

typedef ResourceHolder<sf::Texture, Textures::ID> TextureHolder;
typedef ResourceHolder<sf::Font, Fonts::ID> FontHolder;

#include "resource_holder.inl"

#endif  // RESOURCE_HOLDER_H_
