#include "Settings.h"
#include "Platform.h"

class RemovablePlatform final : public Platform{
private:
    int frames;
    bool flagRem;
    int transparency;
public:
    RemovablePlatform(const float &layerHeight, const float &current, bool flag, const char* fileName = FILENAMEREMOVABLEPLATFORM);
    RemovablePlatform(Platform* otherPlatform, const char* fileName = FILENAMEREMOVABLEPLATFORM);
    virtual const char* getPlatformType() const;
    int getFrames() const;
    bool getFlag() const;
    int getTransparency() const;
    void setPositiveFlag();
    void increaseFrames();
    void increaseTransparency();
    void decreaseTransparency();
    void setRandomPosition();
    void resetFrames();
    void resetTransparency();
    void setNegativeFlag();
    void operator=(const RemovablePlatform &right);
};