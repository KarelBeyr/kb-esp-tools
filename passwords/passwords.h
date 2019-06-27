#ifndef Passwords_h
#define Passwords_h
#include <Arduino.h>

class Passwords
{
  public:
    Passwords();
    String ApiKey();
    String CurrentLocationName();
    const char *WifiPassword();
    const char *WifiSSID();

  private:
};

#endif
