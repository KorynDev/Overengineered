#pragma once
#include <string>

struct Material {
    std::string name;
    std::string desc;
    int value;
    int meltspeed;
};

namespace GlobalMaterials {
    namespace Ores {
        Material StoneOre {
            "Stone Ore",
            "Not too rare, but a good way to make some quick cash!",
            10,
            7
        };
        Material MetalOre {
            "Metal Ore",
            "A stepping stone to, stone ore, makes good cash!",
            25,
            9
        };
        Material GoldOre {
            "Gold Ore",
            "A massive step to metal ore, makes alot of cash!",
            65,
            14
        };
    };
    namespace CompressedOres {
        Material CompressedStoneOre {
            "Compressed Stone Ore",
            "A denser, more valuable version of stone ore!",
            45,
            14
        };
        Material CompressedMetalOre {
            "Compressed Metal Ore",
            "A denser, more valuable version of metal ore brings in a good chunk of cash!",
            95,
            17
        };
        Material CompressedGoldOre {
            "Compressed Gold Ore",
            "A denser, more valuable version of gold ore brings in a very big chunk of cash!",
            200,
            23
        };
    };
};