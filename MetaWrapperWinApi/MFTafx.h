#pragma once

//standart types
#include <vector>
#include <unordered_map>
#include <queue>
#include <set>
namespace MetaFrame {



    typedef unsigned char byte;
    typedef wchar_t wchar;

    template<typename T1, typename T2>
    using Pair = std::pair<T1, T2>;

    template<typename T1, typename T2>
    using HashMap = std::unordered_map<T1, T2>;

    template<typename T>
    using ArrayList = std::vector<T>;

    template<typename T>
    using Set = std::set<T>;

    template<typename T>
    using Queue = std::queue<T>;


}

#include "Color.h"
#include "Margin.h"
#include "Alignment.h"
#include "String.h"
#include "Point.h"
#include "Size.h"
#include "Rect.h"
#include "RectF.h"
#include "Border.h"
#include "Layout.h"
#include "Image.h"
#include "Time.h"
#include "MouseEvent.h"
#define null nullptr
