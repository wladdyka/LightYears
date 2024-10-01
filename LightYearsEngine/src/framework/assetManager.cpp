#include "framework/assetManager.h"

namespace ly {
    unique<AssetManager> AssetManager::instance{nullptr};

    AssetManager & AssetManager::Get() {
        if (!AssetManager::instance) {
            instance = unique<AssetManager>{new AssetManager};
        }

        return *instance;
    }

    AssetManager::AssetManager() {

    }
}
