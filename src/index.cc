#include <node.h>
#include <nan.h>
#include <v8.h>
#include <stdio.h>
#include "sourceIDToDisplay.h"

using namespace v8;

NAN_METHOD(sourceIDToDisplay)
{
	const int sourceID = info[0]->Int32Value();
	Local<Object> obj = Nan::New<Object>();
	Area a;
	if(!sourceIDToDisplayF(sourceID, &a))
	{
		info.GetReturnValue().Set(Nan::Undefined());
	}
	else
	{
		Nan::Set(obj, Nan::New("x").ToLocalChecked(), Nan::New(a.x));
		Nan::Set(obj, Nan::New("y").ToLocalChecked(), Nan::New(a.y));
		Nan::Set(obj, Nan::New("width").ToLocalChecked(), Nan::New(a.width));
		Nan::Set(obj, Nan::New("height").ToLocalChecked(), Nan::New(a.height));
		info.GetReturnValue().Set(obj);
	}
}

NAN_MODULE_INIT(InitAll)
{
	Nan::Set(target, Nan::New("sourceIDToDisplay").ToLocalChecked(),
		Nan::GetFunction(Nan::New<FunctionTemplate>(sourceIDToDisplay)).ToLocalChecked());
}

NODE_MODULE(sourceIDtoDisplayModule, InitAll)
