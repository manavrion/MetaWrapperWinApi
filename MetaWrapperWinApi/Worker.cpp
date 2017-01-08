#include "stdafx.h"
#include "Worker.h"
Worker::Worker() {}

Worker::Worker(String name, float exp) : name(name), exp(exp), user(nullptr){}

Worker::~Worker() {}
