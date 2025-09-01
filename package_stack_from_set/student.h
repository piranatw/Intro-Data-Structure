#ifndef __STACK_STUDENT_H__
#define __STACK_STUDENT_H__
#include "stack.h"

// DO NOT INCLUDE ANYTHING

template <typename T>
CP::stack<T>::stack(typename std::set<T>::iterator first, typename std::set<T>::iterator last)
{
  // write your code ONLY here
  size_t n = 0;
  typename std::set<T>::iterator it = first;
  while (it != last)
  {
    it++;
    n++;
  }
  mCap = n;
  mSize = n;
  mData = new T[mCap]();
  it = first;
  for (int i = n - 1; i >= 0; i--)
  {
    mData[i] = *it;
    it++;
  }
}

#endif