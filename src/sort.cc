#include <napi.h>
#include <iostream>

Napi::Array Sort(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  const Napi::Array inputArray = info[0].As<Napi::Array>();
  int length = inputArray.Length();
  int *array = new int [length];

  for (int i = 0; i < length; i++){
  array[i] = inputArray[i].As<Napi::Number>().Uint32Value();
  }

  for (int iteration = 0; iteration < length; iteration++){
          for (int i = length -1; i >iteration; i--){
              if (array[i-1] > array[i]){
                  int tmp = array[i-1];
                  array[i-1] = array[i];
                  array[i] = tmp;
              }
          }
      }


    Napi::Array outputArray = Napi::Array::New(env,length);
    for (int i = 0; i < length; i++){
            outputArray[i] = array[i];
           }


  return outputArray;
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set(Napi::String::New(env, "bubbleSort"), Napi::Function::New(env, Sort));
  return exports;
}

NODE_API_MODULE(addon, Init)