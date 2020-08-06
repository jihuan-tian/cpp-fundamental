#ifndef PROXY_CLASS_H_
#define PROXY_CLASS_H_

class Proxy {
public:
  void initialize();
  void destroy();
  int get();
  void set(int vi);
private:
  //! A placeholder for the real class, which is only enough for creating a
  //! pointer. This is easy to understand: the memory occupied by a pointer is
  //! always fixed on a platform. Then with the type fixed, the pointer can be
  //! uniquely determined by the compiler without the need knowing the related
  //! class member variables or functions.
  class RealClass;
  RealClass* obj;
};

#endif /* PROXY_CLASS_H_ */
