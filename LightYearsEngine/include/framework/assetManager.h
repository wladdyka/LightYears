#pragma once
#include "framework/core.h"

namespace ly {
    class AssetManager {
    public:
        static AssetManager& Get();
    protected:
        AssetManager();
    private:
        static unique<AssetManager> instance;
    };
}