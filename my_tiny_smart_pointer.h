#ifndef MY_TINY_SMART_POINTER_H
#define MY_TINY_SMART_POINTER_H

#include <memory> // for std::unique_ptr
#include <utility> // for std::move

template<typename T>
class my_unique_ptr{
public:
    T* ptr;
    my_unique_ptr(T* p = nullptr):ptr(p){   }
    ~my_unique_ptr(){
        if(ptr != nullptr){
            delete ptr;
            ptr = nullptr;
        }
    }
    //禁止拷贝与赋值 disable direct copy or assignment
    my_unique_ptr(const my_unique_ptr & p) = delete;
    my_unique_ptr& operator=(const my_unique_ptr & p) = delete;
    //允许右值移动拷贝赋值 able move constructor and move assignment
    my_unique_ptr(my_unique_ptr && p):ptr(p.ptr){
        p.ptr = nullptr;
    } 
    my_unique_ptr& operator=(const my_unique_ptr && p){
        if(this==&ptr){
            return *this;
        }
        delete ptr;
        ptr = p.ptr;
        p.ptr = nullptr;
        return *this;
    }
    //support pointer operation * ->
    T& operator*() const{
        return *ptr;
    }
    T* operator->() const{
        return ptr;
    }
    //other api
    T* get() const{
        return ptr;
    }
    void reset(T* p = nullptr) {
        delete ptr;
        ptr = p;
    }
    T* release() const{
        T* res = ptr;
        ptr = nullptr;
        return res;
    }
    bool isNull() const{
        return ptr == nullptr;
    }
};

template<typename T, typename ...Args>
my_unique_ptr<T> make_unique( Args&& ...args ) {
  return my_unique_ptr<T>( new T( std::forward<Args>(args)... ) );
}
#endif