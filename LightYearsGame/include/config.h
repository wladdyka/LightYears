#pragma once
#include <string>

std::string GetResourceDir() {
#ifdef NDEBUG // release mode
  return "assets/";
#else // debug mode
  return "C:/Users/wladdyka/Projects/LightYears/LightYearsGame/assets/";
#endif
}
