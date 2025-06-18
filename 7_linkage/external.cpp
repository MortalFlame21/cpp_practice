// internal
static int g_a{ 3500 };
static int g_b{ 420 };
constexpr auto g_c{ "external.cpp" };

// external
// extern by default
int g_x{ 123 };
extern const int g_y{ 42069 };
extern constexpr int g_z{ 200 };
// ^ extern at times means give this variable external linkage
// or this is a forward declaration for an external variable 
// that is defined somewhere else
