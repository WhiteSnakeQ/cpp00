#pragma once

#include "iostream"

template<typename T>
void iter(T *array_address, int length, void(* function)(T &target)) {
  for (int i = 0; i < length; i++) 
    function(array_address[i]);
}

template<typename T>
void iter(T *array_address, int length, void(* function)(const T &target)) {
  for (int i = 0; i < length; i++) 
    function(array_address[i]);
}