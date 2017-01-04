#pragma once

//standart types
#include <vector>
#include <unordered_map>
namespace MetaFrame {
    typedef unsigned char byte;
    typedef wchar_t wchar;

    template<typename T1, typename T2>
    using HashMap = std::unordered_map<T1, T2>;

    template<typename T>
    using ArrayList = std::vector<T>;

}

#include "Color.h"
#include "Margin.h"
#include "Alignment.h"
#include "String.h"
#include "Point.h"
#define null nullptr