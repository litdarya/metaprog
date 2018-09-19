class MayersSingleton
{
public:
  static MayersSingleton& Instance() {
    static MayersSingleton singleton;
    return singleton;
  }

private:
  MayersSingleton() {}
  ~MayersSingleton() {}
  MayersSingleton(const MayersSingleton&);
  MayersSingleton& operator=(const MayersSingleton&);
};