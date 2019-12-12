template <typename Resource, typename Identifier>
ResourceHolder<Resource, Identifier>* ResourceHolder<Resource, Identifier>::resource_holder_ = nullptr;

template <typename Resource, typename Identifier>
ResourceHolder<Resource, Identifier>::ResourceHolder() {
}

template <typename Resource, typename Identifier>
ResourceHolder<Resource, Identifier>::~ResourceHolder() {
}

template <typename Resource, typename Identifier>
ResourceHolder<Resource, Identifier>* ResourceHolder<Resource, Identifier>::getInstance() {
    if (ResourceHolder<Resource, Identifier>::resource_holder_ == nullptr) {
        ResourceHolder<Resource, Identifier>::resource_holder_ = new ResourceHolder<Resource, Identifier>();
    }
    return ResourceHolder<Resource, Identifier>::resource_holder_;
}

template <typename Resource, typename Identifier>
void ResourceHolder<Resource, Identifier>::load(Identifier id, const std::string& filename) {
    std::unique_ptr<Resource> resource(new Resource());
    if (!resource->loadFromFile(filename)) {
        throw std::runtime_error("ResourceHolder::load - Failed to load " + filename);
    }

    auto inserted = resource_map_.insert(std::make_pair(id, std::move(resource)));
    assert(inserted.second);
}

template <typename Resource, typename Identifier>
Resource& ResourceHolder<Resource, Identifier>::get(Identifier id) {
    auto found = resource_map_.find(id);
    assert(found != resource_map_.end());

    return *found->second;
}

template <typename Resource, typename Identifier>
const Resource& ResourceHolder<Resource, Identifier>::get(Identifier id) const {
    auto found = resource_map_.find(id);
    assert(found != resource_map_.end());

    return *found->second;
}
