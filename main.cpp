#include <iostream>
#include <memory>

class foo {
private:
  std::unique_ptr<int> ptr;
public:
  foo(int val_): ptr(new int(val_)){}
  int getValue() const { return *ptr; }
};

int main() {
  std::unique_ptr<int> ptr(new int(10));
  std::unique_ptr<int> ptr2;
  ptr2.reset(new int(10));

  std::unique_ptr<int> ptr3 = std::make_unique<int>(10);

  std::unique_ptr<int> ptr4(std::move(ptr));
  std::unique_ptr<int> ptr5;
  ptr5 = std::move(ptr4);

  if (ptr) std::cout << "ptr has the ownership." << std::endl;
  else std::cout << "ptr doesn't have the ownership." << std::endl;

  std::unique_ptr<std::string> pStr(new std::string("test"));
  std::cout << *pStr << std::endl;

  ptr = std::move(ptr4);
  int* pint;
  pint = ptr.get();

  pint = ptr.release();
  delete pint;

  //
  // shared_ptr
  //

  std::shared_ptr<int> s_ptr;

  {
    std::shared_ptr<int> ptr2(new int(0));

    s_ptr = ptr2;
    *s_ptr += 10;
    *ptr2 += 10;
  }

  std::cout << "s_ptr=" << *s_ptr << std::endl;

  std::shared_ptr<int> s_ptr3(new int(10));
  std::shared_ptr<int> s_ptr4;
  s_ptr4.reset(new int(10));

  std::shared_ptr<int> s_ptr5 = std::make_shared<int>(10);

  typedef std::pair<int,double> int_double_t;
  std::shared_ptr<int_double_t> s_ptr6 = std::make_shared<int_double_t>(10,0.4);

  std::shared_ptr<int> s_ptr7 = std::make_shared<int>(10);
  std::shared_ptr<int> s_ptr8(s_ptr7);
  std::shared_ptr<int> s_ptr9;
  s_ptr9 = s_ptr7;

  std::shared_ptr<int> s_ptr10(std::move(s_ptr7));
  std::shared_ptr<int> s_ptr11;
  s_ptr11 = std::move(s_ptr8);

  std::unique_ptr<int> u_ptr(new int(10));
  std::shared_ptr<int> s_ptr12(std::move(u_ptr));

  std::unique_ptr<int> u_ptr2(new int(10));
  std::shared_ptr<int> s_ptr13;
  s_ptr13 = std::move(u_ptr2);

  std::cout << "use_count=" << s_ptr13.use_count() << std::endl;
  if(s_ptr13.unique()) std::cout << "unique" << std::endl;

  return 0;
}