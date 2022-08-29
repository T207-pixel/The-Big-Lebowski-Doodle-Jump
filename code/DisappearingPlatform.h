#include "Settings.h"
#include "Platform.h"

class DisappearingPlatform final : public Platform{
private:
    int frames;
    int comparable;
    int transparency;
    bool flag;
public:
    DisappearingPlatform(const float &layerHeight, const float &current, bool flag, const char* fileName = FILENAMEDISAPPEARINGPLATFORM);
    DisappearingPlatform(Platform* otherPlatform, const char* fileName = FILENAMEDISAPPEARINGPLATFORM);
    virtual const char* getPlatformType() const override;
    int getFramesCounter() const;
    bool getFlag() const;
    void setPositiveFlag();
    void setNegativeFlag();
    void increaseFrames();
    void resetFrames();
    void increaseComparable();
    int getComparable() const;
    void increaseTransparency();
    int getTransparency() const;
    void resetTransparency();
    void resetComparable();
    void setFrames(const int _frames);
    void setFlag(const bool _flag);
    void setComparable(const int _comparable);
    void setTransparency(const int _transparency);
    void copyFields(DisappearingPlatform* right);
    void operator=(const DisappearingPlatform &right);
};