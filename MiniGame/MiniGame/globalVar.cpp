#include <mutex>

float lerpBegin = 0;
float lerpEnd = 0;
float lerpT = 0;

std::recursive_mutex _lock;