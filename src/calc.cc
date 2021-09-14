
#include <node.h>

namespace sort {
    using v8::FunctionCallbackInfo;
    using v8::Isolate;
    using v8::Local;
    using v8::Object;
    using v8::Number;
    using v8::Value;

    void Method(const FunctionCallbackInfo<Value>&args){
        Isolate* isolate = args.GetIsolate();
        
        int i;
        double x = 100.23123123, y = 200.2141423534;
        for (i = 0; i < 1000000; i++){
            x += y;
        }

        auto total = Number::New(isolate,x);
        args.GetReturnValue().Set(total);
    }


    void Initialize(Local<Object> exports){
        NODE_SET_METHOD(exports, "calc",Method);
    }
    NODE_MODULE(NODE_GYP_MODULE_NAME,Initialize);
}