#include <iostream>
#include <string>

using std::string;

class Singleton {
private:
  static Singleton* mInstance;
  int mID;
  string mText;
  Singleton(int _id, string _text) {
    this->mID = _id;
    this->mText = _text;
  }
public:
  static void initialise(int _id, string _text) {
    mInstance = new Singleton(_id, _text);
  }
  static Singleton* getInstance() {
    if (mInstance) {
      return mInstance;
    }
    mInstance = new Singleton();
  }
};


