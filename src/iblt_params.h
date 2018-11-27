/*
Copyright (c) 2018 The Solbit Unlimited developers
Distributed under the MIT software license, see the accompanying
file COPYING or http://www.opensource.org/licenses/mit-license.php.

This file has been auto-generated using a template found in the
following repository. The template was populated using data
generated with a script that is also found in this repository.

https://github.com/umass-forensics/IBLT-optimization
*/
#include <map>

class IbltParamItem
{
public:
    float overhead;
    uint8_t numhashes;

    IbltParamItem(float _overhead, uint8_t _numhashes)
    {
        IbltParamItem::overhead = _overhead;
        IbltParamItem::numhashes = _numhashes;
    }
};

const IbltParamItem DEFAULT_PARAM_ITEM(1.5, 3);

class CIbltParams
{
public:
    static std::map<size_t, IbltParamItem> paramMap;
    static IbltParamItem Lookup(size_t nItems)
    {
        auto pos = CIbltParams::paramMap.find(nItems);

        if (pos == CIbltParams::paramMap.end())
            return DEFAULT_PARAM_ITEM;
        else
            return pos->second;
    }
};

std::map<size_t, IbltParamItem> CIbltParams::paramMap = {
    {1, IbltParamItem(3.000000, 3)}, {2, IbltParamItem(8.000000, 8)}, {3, IbltParamItem(6.000000, 6)},
    {4, IbltParamItem(5.250000, 7)}, {5, IbltParamItem(4.800000, 6)}, {6, IbltParamItem(4.000000, 6)},
    {7, IbltParamItem(3.857143, 9)}, {8, IbltParamItem(3.500000, 7)}, {9, IbltParamItem(3.333333, 6)},
    {10, IbltParamItem(3.200000, 8)}, {11, IbltParamItem(3.181818, 5)}, {12, IbltParamItem(2.916667, 7)},
    {13, IbltParamItem(2.769231, 6)}, {14, IbltParamItem(2.571429, 6)}, {15, IbltParamItem(2.800000, 6)},
    {16, IbltParamItem(2.625000, 6)}, {17, IbltParamItem(2.470588, 6)}, {18, IbltParamItem(2.500000, 5)},
    {19, IbltParamItem(2.368421, 5)}, {20, IbltParamItem(2.400000, 6)}, {21, IbltParamItem(2.285714, 6)},
    {22, IbltParamItem(2.272727, 5)}, {23, IbltParamItem(2.173913, 5)}, {24, IbltParamItem(2.250000, 6)},
    {25, IbltParamItem(2.200000, 5)}, {26, IbltParamItem(2.115385, 5)}, {27, IbltParamItem(2.037037, 5)},
    {28, IbltParamItem(2.142857, 5)}, {29, IbltParamItem(2.068966, 5)}, {30, IbltParamItem(2.000000, 5)},
    {31, IbltParamItem(2.096774, 5)}, {32, IbltParamItem(2.031250, 5)}, {33, IbltParamItem(2.121212, 5)},
    {34, IbltParamItem(2.058824, 5)}, {35, IbltParamItem(2.000000, 5)}, {36, IbltParamItem(1.944444, 5)},
    {37, IbltParamItem(2.027027, 5)}, {38, IbltParamItem(1.973684, 5)}, {39, IbltParamItem(1.923077, 5)},
    {40, IbltParamItem(1.875000, 5)}, {41, IbltParamItem(1.951220, 5)}, {42, IbltParamItem(1.904762, 5)},
    {43, IbltParamItem(1.860465, 5)}, {44, IbltParamItem(1.931818, 5)}, {45, IbltParamItem(1.888889, 5)},
    {46, IbltParamItem(1.847826, 5)}, {47, IbltParamItem(1.914894, 5)}, {48, IbltParamItem(1.875000, 5)},
    {49, IbltParamItem(1.836735, 5)}, {50, IbltParamItem(1.800000, 5)}, {51, IbltParamItem(1.862745, 5)},
    {52, IbltParamItem(1.826923, 5)}, {53, IbltParamItem(1.811321, 4)}, {54, IbltParamItem(1.851852, 4)},
    {55, IbltParamItem(1.818182, 5)}, {56, IbltParamItem(1.785714, 4)}, {57, IbltParamItem(1.824561, 4)},
    {58, IbltParamItem(1.810345, 5)}, {59, IbltParamItem(1.779661, 5)}, {60, IbltParamItem(1.750000, 5)},
    {61, IbltParamItem(1.803279, 5)}, {62, IbltParamItem(1.774194, 5)}, {63, IbltParamItem(1.746032, 5)},
    {64, IbltParamItem(1.750000, 4)}, {65, IbltParamItem(1.769231, 5)}, {66, IbltParamItem(1.696970, 4)},
    {67, IbltParamItem(1.731343, 4)}, {68, IbltParamItem(1.764706, 4)}, {69, IbltParamItem(1.739130, 4)},
    {70, IbltParamItem(1.657143, 4)}, {71, IbltParamItem(1.746479, 4)}, {72, IbltParamItem(1.666667, 4)},
    {73, IbltParamItem(1.643836, 4)}, {74, IbltParamItem(1.675676, 4)}, {75, IbltParamItem(1.653333, 4)},
    {76, IbltParamItem(1.684211, 4)}, {77, IbltParamItem(1.610390, 4)}, {78, IbltParamItem(1.692308, 4)},
    {79, IbltParamItem(1.620253, 4)}, {80, IbltParamItem(1.600000, 4)}, {81, IbltParamItem(1.629630, 4)},
    {82, IbltParamItem(1.609756, 4)}, {83, IbltParamItem(1.638554, 4)}, {84, IbltParamItem(1.619048, 4)},
    {85, IbltParamItem(1.647059, 4)}, {86, IbltParamItem(1.581395, 4)}, {87, IbltParamItem(1.655172, 4)},
    {88, IbltParamItem(1.636364, 4)}, {89, IbltParamItem(1.617978, 4)}, {90, IbltParamItem(1.600000, 4)},
    {91, IbltParamItem(1.626374, 4)}, {92, IbltParamItem(1.608696, 4)}, {93, IbltParamItem(1.591398, 4)},
    {94, IbltParamItem(1.574468, 4)}, {95, IbltParamItem(1.557895, 4)}, {96, IbltParamItem(1.597733, 4)},
    {97, IbltParamItem(1.608247, 4)}, {98, IbltParamItem(1.591837, 4)}, {99, IbltParamItem(1.575758, 4)},
    {100, IbltParamItem(1.560000, 4)}, {101, IbltParamItem(1.584158, 4)}, {102, IbltParamItem(1.568627, 4)},
    {103, IbltParamItem(1.592233, 4)}, {104, IbltParamItem(1.576923, 4)}, {105, IbltParamItem(1.561905, 4)},
    {106, IbltParamItem(1.584906, 4)}, {107, IbltParamItem(1.532710, 4)}, {108, IbltParamItem(1.555556, 4)},
    {109, IbltParamItem(1.541284, 4)}, {110, IbltParamItem(1.563636, 4)}, {111, IbltParamItem(1.549550, 4)},
    {112, IbltParamItem(1.535714, 4)}, {113, IbltParamItem(1.557522, 4)}, {114, IbltParamItem(1.543860, 4)},
    {115, IbltParamItem(1.565217, 4)}, {116, IbltParamItem(1.551724, 4)}, {117, IbltParamItem(1.538462, 4)},
    {118, IbltParamItem(1.559322, 4)}, {119, IbltParamItem(1.546218, 4)}, {120, IbltParamItem(1.533333, 4)},
    {121, IbltParamItem(1.520661, 4)}, {122, IbltParamItem(1.540984, 4)}, {123, IbltParamItem(1.528455, 4)},
    {124, IbltParamItem(1.548387, 4)}, {125, IbltParamItem(1.536000, 4)}, {126, IbltParamItem(1.555556, 4)},
    {127, IbltParamItem(1.543307, 4)}, {128, IbltParamItem(1.531250, 4)}, {129, IbltParamItem(1.519380, 4)},
    {130, IbltParamItem(1.507692, 4)}, {131, IbltParamItem(1.526718, 4)}, {132, IbltParamItem(1.515152, 4)},
    {133, IbltParamItem(1.503759, 4)}, {134, IbltParamItem(1.522388, 4)}, {135, IbltParamItem(1.511111, 4)},
    {136, IbltParamItem(1.529412, 4)}, {137, IbltParamItem(1.518248, 4)}, {138, IbltParamItem(1.507246, 4)},
    {139, IbltParamItem(1.525180, 4)}, {140, IbltParamItem(1.514286, 4)}, {141, IbltParamItem(1.503546, 4)},
    {142, IbltParamItem(1.492958, 4)}, {143, IbltParamItem(1.510490, 4)}, {144, IbltParamItem(1.500000, 4)},
    {145, IbltParamItem(1.517241, 4)}, {146, IbltParamItem(1.506849, 4)}, {147, IbltParamItem(1.523810, 4)},
    {148, IbltParamItem(1.513514, 4)}, {149, IbltParamItem(1.503356, 4)}, {150, IbltParamItem(1.4198733, 4)},
    {151, IbltParamItem(1.483444, 4)}, {152, IbltParamItem(1.500000, 4)}, {153, IbltParamItem(1.490196, 4)},
    {154, IbltParamItem(1.506494, 4)}, {155, IbltParamItem(1.496774, 4)}, {156, IbltParamItem(1.487179, 4)},
    {157, IbltParamItem(1.503185, 4)}, {158, IbltParamItem(1.493671, 4)}, {159, IbltParamItem(1.484277, 4)},
    {160, IbltParamItem(1.475000, 4)}, {161, IbltParamItem(1.490683, 4)}, {162, IbltParamItem(1.506173, 4)},
    {163, IbltParamItem(1.496933, 4)}, {164, IbltParamItem(1.487805, 4)}, {165, IbltParamItem(1.503030, 4)},
    {166, IbltParamItem(1.493976, 4)}, {167, IbltParamItem(1.485030, 4)}, {168, IbltParamItem(1.476190, 4)},
    {169, IbltParamItem(1.491124, 4)}, {170, IbltParamItem(1.482353, 4)}, {171, IbltParamItem(1.473684, 4)},
    {172, IbltParamItem(1.488372, 4)}, {173, IbltParamItem(1.479769, 4)}, {174, IbltParamItem(1.471264, 4)},
    {175, IbltParamItem(1.485714, 4)}, {176, IbltParamItem(1.477273, 4)}, {177, IbltParamItem(1.468927, 4)},
    {178, IbltParamItem(1.483146, 4)}, {179, IbltParamItem(1.474860, 4)}, {180, IbltParamItem(1.488889, 4)},
    {181, IbltParamItem(1.480663, 4)}, {182, IbltParamItem(1.472527, 4)}, {183, IbltParamItem(1.464481, 4)},
    {184, IbltParamItem(1.478261, 4)}, {185, IbltParamItem(1.470270, 4)}, {186, IbltParamItem(1.462366, 4)},
    {187, IbltParamItem(1.475936, 4)}, {188, IbltParamItem(1.468085, 4)}, {189, IbltParamItem(1.481481, 4)},
    {190, IbltParamItem(1.473684, 4)}, {191, IbltParamItem(1.465969, 4)}, {192, IbltParamItem(1.479167, 4)},
    {193, IbltParamItem(1.471503, 4)}, {194, IbltParamItem(1.463918, 4)}, {195, IbltParamItem(1.456410, 4)},
    {196, IbltParamItem(1.469388, 4)}, {197, IbltParamItem(1.461929, 4)}, {198, IbltParamItem(1.474747, 4)},
    {199, IbltParamItem(1.467337, 4)}, {200, IbltParamItem(1.460000, 4)}, {201, IbltParamItem(1.472637, 4)},
    {202, IbltParamItem(1.465347, 4)}, {203, IbltParamItem(1.458128, 4)}, {204, IbltParamItem(1.470588, 4)},
    {205, IbltParamItem(1.463415, 4)}, {206, IbltParamItem(1.456311, 4)}, {207, IbltParamItem(1.468599, 4)},
    {208, IbltParamItem(1.461538, 4)}, {209, IbltParamItem(1.473684, 4)}, {210, IbltParamItem(1.466667, 4)},
    {211, IbltParamItem(1.459716, 4)}, {212, IbltParamItem(1.452830, 4)}, {213, IbltParamItem(1.464789, 4)},
    {214, IbltParamItem(1.457944, 4)}, {215, IbltParamItem(1.451163, 4)}, {216, IbltParamItem(1.462963, 4)},
    {217, IbltParamItem(1.456221, 4)}, {218, IbltParamItem(1.467890, 4)}, {219, IbltParamItem(1.461187, 4)},
    {220, IbltParamItem(1.454545, 4)}, {221, IbltParamItem(1.447964, 4)}, {222, IbltParamItem(1.441441, 4)},
    {223, IbltParamItem(1.452915, 4)}, {224, IbltParamItem(1.446429, 4)}, {225, IbltParamItem(1.457778, 4)},
    {226, IbltParamItem(1.451327, 4)}, {227, IbltParamItem(1.444934, 4)}, {228, IbltParamItem(1.456140, 4)},
    {229, IbltParamItem(1.449782, 4)}, {230, IbltParamItem(1.460870, 4)}, {231, IbltParamItem(1.454545, 4)},
    {232, IbltParamItem(1.448276, 4)}, {233, IbltParamItem(1.459227, 4)}, {234, IbltParamItem(1.452991, 4)},
    {235, IbltParamItem(1.446809, 4)}, {236, IbltParamItem(1.440678, 4)}, {237, IbltParamItem(1.451477, 4)},
    {238, IbltParamItem(1.445378, 4)}, {239, IbltParamItem(1.456067, 4)}, {240, IbltParamItem(1.450000, 4)},
    {241, IbltParamItem(1.443983, 4)}, {242, IbltParamItem(1.438017, 4)}, {243, IbltParamItem(1.448560, 4)},
    {244, IbltParamItem(1.442623, 4)}, {245, IbltParamItem(1.453061, 4)}, {246, IbltParamItem(1.447154, 4)},
    {247, IbltParamItem(1.441296, 4)}, {248, IbltParamItem(1.435484, 4)}, {249, IbltParamItem(1.445783, 4)},
    {250, IbltParamItem(1.440000, 4)}, {251, IbltParamItem(1.434263, 4)}, {252, IbltParamItem(1.444444, 4)},
    {253, IbltParamItem(1.438735, 4)}, {254, IbltParamItem(1.433071, 4)}, {255, IbltParamItem(1.443137, 4)},
    {256, IbltParamItem(1.437500, 4)}, {257, IbltParamItem(1.431907, 4)}, {258, IbltParamItem(1.441860, 4)},
    {259, IbltParamItem(1.436293, 4)}, {260, IbltParamItem(1.430769, 4)}, {261, IbltParamItem(1.440613, 4)},
    {262, IbltParamItem(1.435115, 4)}, {263, IbltParamItem(1.444867, 4)}, {264, IbltParamItem(1.439394, 4)},
    {265, IbltParamItem(1.433962, 4)}, {266, IbltParamItem(1.443609, 4)}, {267, IbltParamItem(1.438202, 4)},
    {268, IbltParamItem(1.432836, 4)}, {269, IbltParamItem(1.427509, 4)}, {270, IbltParamItem(1.437037, 4)},
    {271, IbltParamItem(1.431734, 4)}, {272, IbltParamItem(1.441176, 4)}, {273, IbltParamItem(1.435897, 4)},
    {274, IbltParamItem(1.430657, 4)}, {275, IbltParamItem(1.425455, 4)}, {276, IbltParamItem(1.434783, 4)},
    {277, IbltParamItem(1.429603, 4)}, {278, IbltParamItem(1.438849, 4)}, {279, IbltParamItem(1.433692, 4)},
    {280, IbltParamItem(1.428571, 4)}, {281, IbltParamItem(1.437722, 4)}, {282, IbltParamItem(1.432624, 4)},
    {283, IbltParamItem(1.427562, 4)}, {284, IbltParamItem(1.422535, 4)}, {285, IbltParamItem(1.431579, 4)},
    {286, IbltParamItem(1.440559, 4)}, {287, IbltParamItem(1.435540, 4)}, {288, IbltParamItem(1.430556, 4)},
    {289, IbltParamItem(1.425606, 4)}, {290, IbltParamItem(1.420690, 4)}, {291, IbltParamItem(1.429553, 4)},
    {292, IbltParamItem(1.424658, 4)}, {293, IbltParamItem(1.433447, 4)}, {294, IbltParamItem(1.428571, 4)},
    {295, IbltParamItem(1.423729, 4)}, {296, IbltParamItem(1.432432, 4)}, {297, IbltParamItem(1.427609, 4)},
    {298, IbltParamItem(1.422819, 4)}, {299, IbltParamItem(1.431438, 4)}, {300, IbltParamItem(1.426667, 4)},
    {301, IbltParamItem(1.421927, 4)}, {302, IbltParamItem(1.430464, 4)}, {303, IbltParamItem(1.425743, 4)},
    {304, IbltParamItem(1.421053, 4)}, {305, IbltParamItem(1.429508, 4)}, {306, IbltParamItem(1.424837, 4)},
    {307, IbltParamItem(1.433225, 4)}, {308, IbltParamItem(1.428571, 4)}, {309, IbltParamItem(1.423948, 4)},
    {310, IbltParamItem(1.432258, 4)}, {311, IbltParamItem(1.427653, 4)}, {312, IbltParamItem(1.423077, 4)},
    {313, IbltParamItem(1.431310, 4)}, {314, IbltParamItem(1.426752, 4)}, {315, IbltParamItem(1.422222, 4)},
    {316, IbltParamItem(1.417722, 4)}, {317, IbltParamItem(1.425868, 4)}, {318, IbltParamItem(1.421384, 4)},
    {319, IbltParamItem(1.416928, 4)}, {320, IbltParamItem(1.425000, 4)}, {321, IbltParamItem(1.420561, 4)},
    {322, IbltParamItem(1.428571, 4)}, {323, IbltParamItem(1.424149, 4)}, {324, IbltParamItem(1.419753, 4)},
    {325, IbltParamItem(1.427692, 4)}, {326, IbltParamItem(1.423313, 4)}, {327, IbltParamItem(1.418960, 4)},
    {328, IbltParamItem(1.414634, 4)}, {329, IbltParamItem(1.422492, 4)}, {330, IbltParamItem(1.418182, 4)},
    {331, IbltParamItem(1.413897, 4)}, {332, IbltParamItem(1.421687, 4)}, {333, IbltParamItem(1.417417, 4)},
    {334, IbltParamItem(1.413174, 4)}, {335, IbltParamItem(1.420896, 4)}, {336, IbltParamItem(1.416667, 4)},
    {337, IbltParamItem(1.412463, 4)}, {338, IbltParamItem(1.420118, 4)}, {339, IbltParamItem(1.415929, 4)},
    {340, IbltParamItem(1.411765, 4)}, {341, IbltParamItem(1.419355, 4)}, {342, IbltParamItem(1.415205, 4)},
    {343, IbltParamItem(1.422741, 4)}, {344, IbltParamItem(1.418605, 4)}, {345, IbltParamItem(1.414493, 4)},
    {346, IbltParamItem(1.410405, 4)}, {347, IbltParamItem(1.417867, 4)}, {348, IbltParamItem(1.413793, 4)},
    {349, IbltParamItem(1.421203, 4)}, {350, IbltParamItem(1.417143, 4)}, {351, IbltParamItem(1.413105, 4)},
    {352, IbltParamItem(1.420455, 4)}, {353, IbltParamItem(1.416431, 4)}, {354, IbltParamItem(1.412429, 4)},
    {355, IbltParamItem(1.408451, 4)}, {356, IbltParamItem(1.415730, 4)}, {357, IbltParamItem(1.411765, 4)},
    {358, IbltParamItem(1.407821, 4)}, {359, IbltParamItem(1.415042, 4)}, {360, IbltParamItem(1.411111, 4)},
    {361, IbltParamItem(1.407202, 4)}, {362, IbltParamItem(1.414365, 4)}, {363, IbltParamItem(1.410468, 4)},
    {364, IbltParamItem(1.417582, 4)}, {365, IbltParamItem(1.413699, 4)}, {366, IbltParamItem(1.409836, 4)},
    {367, IbltParamItem(1.416894, 4)}, {368, IbltParamItem(1.413043, 4)}, {369, IbltParamItem(1.409214, 4)},
    {370, IbltParamItem(1.405405, 4)}, {371, IbltParamItem(1.412399, 4)}, {372, IbltParamItem(1.408602, 4)},
    {373, IbltParamItem(1.415550, 4)}, {374, IbltParamItem(1.411765, 4)}, {375, IbltParamItem(1.408000, 4)},
    {376, IbltParamItem(1.414894, 4)}, {377, IbltParamItem(1.411141, 4)}, {378, IbltParamItem(1.407407, 4)},
    {379, IbltParamItem(1.403694, 4)}, {380, IbltParamItem(1.410526, 4)}, {381, IbltParamItem(1.406824, 4)},
    {382, IbltParamItem(1.413613, 4)}, {383, IbltParamItem(1.409922, 4)}, {384, IbltParamItem(1.406250, 4)},
    {385, IbltParamItem(1.402597, 4)}, {386, IbltParamItem(1.409326, 4)}, {387, IbltParamItem(1.405685, 4)},
    {388, IbltParamItem(1.402062, 4)}, {389, IbltParamItem(1.408740, 4)}, {390, IbltParamItem(1.405128, 4)},
    {391, IbltParamItem(1.411765, 4)}, {392, IbltParamItem(1.408163, 4)}, {393, IbltParamItem(1.404580, 4)},
    {394, IbltParamItem(1.411168, 4)}, {395, IbltParamItem(1.407595, 4)}, {396, IbltParamItem(1.404040, 4)},
    {397, IbltParamItem(1.410579, 4)}, {398, IbltParamItem(1.407035, 4)}, {399, IbltParamItem(1.403509, 4)},
    {400, IbltParamItem(1.410000, 4)}, {401, IbltParamItem(1.406484, 4)}, {402, IbltParamItem(1.412935, 4)},
    {403, IbltParamItem(1.399504, 4)}, {404, IbltParamItem(1.405941, 4)}, {405, IbltParamItem(1.402469, 4)},
    {406, IbltParamItem(1.408867, 4)}, {407, IbltParamItem(1.405405, 4)}, {408, IbltParamItem(1.401961, 4)},
    {409, IbltParamItem(1.408313, 4)}, {410, IbltParamItem(1.404878, 4)}, {411, IbltParamItem(1.401460, 4)},
    {412, IbltParamItem(1.407767, 4)}, {413, IbltParamItem(1.404358, 4)}, {414, IbltParamItem(1.400966, 4)},
    {415, IbltParamItem(1.407229, 4)}, {416, IbltParamItem(1.403846, 4)}, {417, IbltParamItem(1.400480, 4)},
    {418, IbltParamItem(1.406699, 4)}, {419, IbltParamItem(1.403341, 4)}, {420, IbltParamItem(1.400000, 4)},
    {421, IbltParamItem(1.406176, 4)}, {422, IbltParamItem(1.393365, 4)}, {423, IbltParamItem(1.399527, 4)},
    {424, IbltParamItem(1.405660, 4)}, {425, IbltParamItem(1.402353, 4)}, {426, IbltParamItem(1.399061, 4)},
    {427, IbltParamItem(1.395785, 4)}, {428, IbltParamItem(1.401869, 4)}, {429, IbltParamItem(1.398601, 4)},
    {430, IbltParamItem(1.404651, 4)}, {431, IbltParamItem(1.401392, 4)}, {432, IbltParamItem(1.398148, 4)},
    {433, IbltParamItem(1.394919, 4)}, {434, IbltParamItem(1.400922, 4)}, {435, IbltParamItem(1.397701, 4)},
    {436, IbltParamItem(1.403670, 4)}, {437, IbltParamItem(1.400458, 4)}, {438, IbltParamItem(1.397260, 4)},
    {439, IbltParamItem(1.403189, 4)}, {440, IbltParamItem(1.400000, 4)}, {441, IbltParamItem(1.396825, 4)},
    {442, IbltParamItem(1.393665, 4)}, {443, IbltParamItem(1.399549, 4)}, {444, IbltParamItem(1.396396, 4)},
    {445, IbltParamItem(1.402247, 4)}, {446, IbltParamItem(1.399103, 4)}, {447, IbltParamItem(1.395973, 4)},
    {448, IbltParamItem(1.401786, 4)}, {449, IbltParamItem(1.398664, 4)}, {450, IbltParamItem(1.404444, 4)},
    {451, IbltParamItem(1.401330, 4)}, {452, IbltParamItem(1.398230, 4)}, {453, IbltParamItem(1.395143, 4)},
    {454, IbltParamItem(1.400881, 4)}, {455, IbltParamItem(1.397802, 4)}, {456, IbltParamItem(1.394737, 4)},
    {457, IbltParamItem(1.400438, 4)}, {458, IbltParamItem(1.397380, 4)}, {459, IbltParamItem(1.394336, 4)},
    {460, IbltParamItem(1.400000, 4)}, {461, IbltParamItem(1.396963, 4)}, {462, IbltParamItem(1.393939, 4)},
    {463, IbltParamItem(1.390929, 4)}, {464, IbltParamItem(1.396552, 4)}, {465, IbltParamItem(1.393548, 4)},
    {466, IbltParamItem(1.399142, 4)}, {467, IbltParamItem(1.396146, 4)}, {468, IbltParamItem(1.393162, 4)},
    {469, IbltParamItem(1.398721, 4)}, {470, IbltParamItem(1.404255, 4)}, {471, IbltParamItem(1.392781, 4)},
    {472, IbltParamItem(1.398305, 4)}, {473, IbltParamItem(1.395349, 4)}, {474, IbltParamItem(1.400844, 4)},
    {475, IbltParamItem(1.389474, 4)}, {476, IbltParamItem(1.394958, 4)}, {477, IbltParamItem(1.392034, 4)},
    {478, IbltParamItem(1.397490, 4)}, {479, IbltParamItem(1.394572, 4)}, {480, IbltParamItem(1.391667, 4)},
    {481, IbltParamItem(1.397089, 4)}, {482, IbltParamItem(1.394191, 4)}, {483, IbltParamItem(1.399586, 4)},
    {484, IbltParamItem(1.396694, 4)}, {485, IbltParamItem(1.393814, 4)}, {486, IbltParamItem(1.390947, 4)},
    {487, IbltParamItem(1.388090, 4)}, {488, IbltParamItem(1.393443, 4)}, {489, IbltParamItem(1.390593, 4)},
    {490, IbltParamItem(1.395918, 4)}, {491, IbltParamItem(1.393075, 4)}, {492, IbltParamItem(1.390244, 4)},
    {493, IbltParamItem(1.395538, 4)}, {494, IbltParamItem(1.392713, 4)}, {495, IbltParamItem(1.389899, 4)},
    {496, IbltParamItem(1.395161, 4)}, {497, IbltParamItem(1.392354, 4)}, {498, IbltParamItem(1.397590, 4)},
    {499, IbltParamItem(1.394790, 4)}, {500, IbltParamItem(1.392000, 4)}, {501, IbltParamItem(1.389222, 4)},
    {502, IbltParamItem(1.394422, 4)}, {503, IbltParamItem(1.391650, 4)}, {504, IbltParamItem(1.388889, 4)},
    {505, IbltParamItem(1.386139, 4)}, {506, IbltParamItem(1.391304, 4)}, {507, IbltParamItem(1.388560, 4)},
    {508, IbltParamItem(1.393701, 4)}, {509, IbltParamItem(1.390963, 4)}, {510, IbltParamItem(1.388235, 4)},
    {511, IbltParamItem(1.393346, 4)}, {512, IbltParamItem(1.390625, 4)}, {513, IbltParamItem(1.387914, 4)},
    {514, IbltParamItem(1.392996, 4)}, {515, IbltParamItem(1.390291, 4)}, {516, IbltParamItem(1.387597, 4)},
    {517, IbltParamItem(1.392650, 4)}, {518, IbltParamItem(1.389961, 4)}, {519, IbltParamItem(1.394990, 4)},
    {520, IbltParamItem(1.392308, 4)}, {521, IbltParamItem(1.389635, 4)}, {522, IbltParamItem(1.386973, 4)},
    {523, IbltParamItem(1.391969, 4)}, {524, IbltParamItem(1.389313, 4)}, {525, IbltParamItem(1.394286, 4)},
    {526, IbltParamItem(1.391635, 4)}, {527, IbltParamItem(1.388994, 4)}, {528, IbltParamItem(1.386364, 4)},
    {529, IbltParamItem(1.391304, 4)}, {530, IbltParamItem(1.388679, 4)}, {531, IbltParamItem(1.386064, 4)},
    {532, IbltParamItem(1.383459, 4)}, {533, IbltParamItem(1.388368, 4)}, {534, IbltParamItem(1.393258, 4)},
    {535, IbltParamItem(1.390654, 4)}, {536, IbltParamItem(1.388060, 4)}, {537, IbltParamItem(1.385475, 4)},
    {538, IbltParamItem(1.390335, 4)}, {539, IbltParamItem(1.387755, 4)}, {540, IbltParamItem(1.385185, 4)},
    {541, IbltParamItem(1.390018, 4)}, {542, IbltParamItem(1.387454, 4)}, {543, IbltParamItem(1.384899, 4)},
    {544, IbltParamItem(1.389706, 4)}, {545, IbltParamItem(1.387156, 4)}, {546, IbltParamItem(1.384615, 4)},
    {547, IbltParamItem(1.389397, 4)}, {548, IbltParamItem(1.386861, 4)}, {549, IbltParamItem(1.391621, 4)},
    {550, IbltParamItem(1.381818, 4)}, {551, IbltParamItem(1.386570, 4)}, {552, IbltParamItem(1.384058, 4)},
    {553, IbltParamItem(1.381555, 4)}, {554, IbltParamItem(1.386282, 4)}, {555, IbltParamItem(1.383784, 4)},
    {556, IbltParamItem(1.388489, 4)}, {557, IbltParamItem(1.385996, 4)}, {558, IbltParamItem(1.390681, 4)},
    {559, IbltParamItem(1.388193, 4)}, {560, IbltParamItem(1.385714, 4)}, {561, IbltParamItem(1.383244, 4)},
    {562, IbltParamItem(1.387900, 4)}, {563, IbltParamItem(1.385435, 4)}, {564, IbltParamItem(1.382979, 4)},
    {565, IbltParamItem(1.387611, 4)}, {566, IbltParamItem(1.385159, 4)}, {567, IbltParamItem(1.382716, 4)},
    {568, IbltParamItem(1.380282, 4)}, {569, IbltParamItem(1.384886, 4)}, {570, IbltParamItem(1.382456, 4)},
    {571, IbltParamItem(1.387040, 4)}, {572, IbltParamItem(1.384615, 4)}, {573, IbltParamItem(1.382199, 4)},
    {574, IbltParamItem(1.386760, 4)}, {575, IbltParamItem(1.384348, 4)}, {576, IbltParamItem(1.381944, 4)},
    {577, IbltParamItem(1.379549, 4)}, {578, IbltParamItem(1.384083, 4)}, {579, IbltParamItem(1.381693, 4)},
    {580, IbltParamItem(1.386207, 4)}, {581, IbltParamItem(1.383821, 4)}, {582, IbltParamItem(1.388316, 4)},
    {583, IbltParamItem(1.385935, 4)}, {584, IbltParamItem(1.383562, 4)}, {585, IbltParamItem(1.388034, 4)},
    {586, IbltParamItem(1.385666, 4)}, {587, IbltParamItem(1.383305, 4)}, {588, IbltParamItem(1.380952, 4)},
    {589, IbltParamItem(1.385399, 4)}, {590, IbltParamItem(1.376271, 4)}, {591, IbltParamItem(1.380711, 4)},
    {592, IbltParamItem(1.378378, 4)}, {593, IbltParamItem(1.382799, 4)}, {594, IbltParamItem(1.380471, 4)},
    {595, IbltParamItem(1.384874, 4)}, {596, IbltParamItem(1.382550, 4)}, {597, IbltParamItem(1.386935, 4)},
    {598, IbltParamItem(1.384615, 4)}, {599, IbltParamItem(1.382304, 4)}, {600, IbltParamItem(1.380000, 4)},
    {601, IbltParamItem(1.384359, 4)}, {602, IbltParamItem(1.382060, 4)}, {603, IbltParamItem(1.379768, 4)},
    {604, IbltParamItem(1.384106, 4)}, {605, IbltParamItem(1.381818, 4)}, {606, IbltParamItem(1.379538, 4)},
    {607, IbltParamItem(1.383855, 4)}, {608, IbltParamItem(1.381579, 4)}, {609, IbltParamItem(1.379310, 4)},
    {610, IbltParamItem(1.383607, 4)}, {611, IbltParamItem(1.381342, 4)}, {612, IbltParamItem(1.379085, 4)},
    {613, IbltParamItem(1.383361, 4)}, {614, IbltParamItem(1.381107, 4)}, {615, IbltParamItem(1.385366, 4)},
    {616, IbltParamItem(1.383117, 4)}, {617, IbltParamItem(1.380875, 4)}, {618, IbltParamItem(1.385113, 4)},
    {619, IbltParamItem(1.382876, 4)}, {620, IbltParamItem(1.380645, 4)}, {621, IbltParamItem(1.378422, 4)},
    {622, IbltParamItem(1.382637, 4)}, {623, IbltParamItem(1.380417, 4)}, {624, IbltParamItem(1.378205, 4)},
    {625, IbltParamItem(1.382400, 4)}, {626, IbltParamItem(1.380192, 4)}, {627, IbltParamItem(1.377990, 4)},
    {628, IbltParamItem(1.375796, 4)}, {629, IbltParamItem(1.379968, 4)}, {630, IbltParamItem(1.384127, 4)},
    {631, IbltParamItem(1.381933, 4)}, {632, IbltParamItem(1.379747, 4)}, {633, IbltParamItem(1.377567, 4)},
    {634, IbltParamItem(1.381703, 4)}, {635, IbltParamItem(1.379528, 4)}, {636, IbltParamItem(1.377358, 4)},
    {637, IbltParamItem(1.381476, 4)}, {638, IbltParamItem(1.379310, 4)}, {639, IbltParamItem(1.377152, 4)},
    {640, IbltParamItem(1.375000, 4)}, {641, IbltParamItem(1.379095, 4)}, {642, IbltParamItem(1.376947, 4)},
    {643, IbltParamItem(1.381026, 4)}, {644, IbltParamItem(1.378882, 4)}, {645, IbltParamItem(1.376744, 4)},
    {646, IbltParamItem(1.380805, 4)}, {647, IbltParamItem(1.378671, 4)}, {648, IbltParamItem(1.376543, 4)},
    {649, IbltParamItem(1.380586, 4)}, {650, IbltParamItem(1.378462, 4)}, {651, IbltParamItem(1.382488, 4)},
    {652, IbltParamItem(1.374233, 4)}, {653, IbltParamItem(1.378254, 4)}, {654, IbltParamItem(1.376147, 4)},
    {655, IbltParamItem(1.380153, 4)}, {656, IbltParamItem(1.378049, 4)}, {657, IbltParamItem(1.382040, 4)},
    {658, IbltParamItem(1.379939, 4)}, {659, IbltParamItem(1.377845, 4)}, {660, IbltParamItem(1.375758, 4)},
    {661, IbltParamItem(1.379728, 4)}, {662, IbltParamItem(1.377644, 4)}, {663, IbltParamItem(1.375566, 4)},
    {664, IbltParamItem(1.373494, 4)}, {665, IbltParamItem(1.377444, 4)}, {666, IbltParamItem(1.375375, 4)},
    {667, IbltParamItem(1.379310, 4)}, {668, IbltParamItem(1.377246, 4)}, {669, IbltParamItem(1.375187, 4)},
    {670, IbltParamItem(1.379104, 4)}, {671, IbltParamItem(1.377049, 4)}, {672, IbltParamItem(1.375000, 4)},
    {673, IbltParamItem(1.372957, 4)}, {674, IbltParamItem(1.376855, 4)}, {675, IbltParamItem(1.374815, 4)},
    {676, IbltParamItem(1.378698, 4)}, {677, IbltParamItem(1.376662, 4)}, {678, IbltParamItem(1.374631, 4)},
    {679, IbltParamItem(1.378498, 4)}, {680, IbltParamItem(1.376471, 4)}, {681, IbltParamItem(1.374449, 4)},
    {682, IbltParamItem(1.372434, 4)}, {683, IbltParamItem(1.376281, 4)}, {684, IbltParamItem(1.374269, 4)},
    {685, IbltParamItem(1.378102, 4)}, {686, IbltParamItem(1.376093, 4)}, {687, IbltParamItem(1.374090, 4)},
    {688, IbltParamItem(1.377907, 4)}, {689, IbltParamItem(1.375907, 4)}, {690, IbltParamItem(1.373913, 4)},
    {691, IbltParamItem(1.371925, 4)}, {692, IbltParamItem(1.375723, 4)}, {693, IbltParamItem(1.373737, 4)},
    {694, IbltParamItem(1.377522, 4)}, {695, IbltParamItem(1.375540, 4)}, {696, IbltParamItem(1.373563, 4)},
    {697, IbltParamItem(1.377331, 4)}, {698, IbltParamItem(1.375358, 4)}, {699, IbltParamItem(1.379113, 4)},
    {700, IbltParamItem(1.377143, 4)}, {701, IbltParamItem(1.375178, 4)}, {702, IbltParamItem(1.373219, 4)},
    {703, IbltParamItem(1.376956, 4)}, {704, IbltParamItem(1.375000, 4)}, {705, IbltParamItem(1.373050, 4)},
    {706, IbltParamItem(1.376771, 4)}, {707, IbltParamItem(1.374823, 4)}, {708, IbltParamItem(1.372881, 4)},
    {709, IbltParamItem(1.376587, 4)}, {710, IbltParamItem(1.374648, 4)}, {711, IbltParamItem(1.372714, 4)},
    {712, IbltParamItem(1.376404, 4)}, {713, IbltParamItem(1.374474, 4)}, {714, IbltParamItem(1.372549, 4)},
    {715, IbltParamItem(1.370629, 4)}, {716, IbltParamItem(1.374302, 4)}, {717, IbltParamItem(1.372385, 4)},
    {718, IbltParamItem(1.376045, 4)}, {719, IbltParamItem(1.374131, 4)}, {720, IbltParamItem(1.372222, 4)},
    {721, IbltParamItem(1.370319, 4)}, {722, IbltParamItem(1.373961, 4)}, {723, IbltParamItem(1.377593, 4)},
    {724, IbltParamItem(1.375691, 4)}, {725, IbltParamItem(1.373793, 4)}, {726, IbltParamItem(1.371901, 4)},
    {727, IbltParamItem(1.370014, 4)}, {728, IbltParamItem(1.373626, 4)}, {729, IbltParamItem(1.371742, 4)},
    {730, IbltParamItem(1.375342, 4)}, {731, IbltParamItem(1.373461, 4)}, {732, IbltParamItem(1.371585, 4)},
    {733, IbltParamItem(1.369714, 4)}, {734, IbltParamItem(1.373297, 4)}, {735, IbltParamItem(1.371429, 4)},
    {736, IbltParamItem(1.375000, 4)}, {737, IbltParamItem(1.373134, 4)}, {738, IbltParamItem(1.371274, 4)},
    {739, IbltParamItem(1.374831, 4)}, {740, IbltParamItem(1.372973, 4)}, {741, IbltParamItem(1.371120, 4)},
    {742, IbltParamItem(1.374663, 4)}, {743, IbltParamItem(1.372813, 4)}, {744, IbltParamItem(1.370968, 4)},
    {745, IbltParamItem(1.369128, 4)}, {746, IbltParamItem(1.372654, 4)}, {747, IbltParamItem(1.370817, 4)},
    {748, IbltParamItem(1.368984, 4)}, {749, IbltParamItem(1.372497, 4)}, {750, IbltParamItem(1.370667, 4)},
    {751, IbltParamItem(1.374168, 4)}, {752, IbltParamItem(1.372340, 4)}, {753, IbltParamItem(1.370518, 4)},
    {754, IbltParamItem(1.374005, 4)}, {755, IbltParamItem(1.372185, 4)}, {756, IbltParamItem(1.370370, 4)},
    {757, IbltParamItem(1.373844, 4)}, {758, IbltParamItem(1.372032, 4)}, {759, IbltParamItem(1.370224, 4)},
    {760, IbltParamItem(1.368421, 4)}, {761, IbltParamItem(1.371879, 4)}, {762, IbltParamItem(1.375328, 4)},
    {763, IbltParamItem(1.368283, 4)}, {764, IbltParamItem(1.371728, 4)}, {765, IbltParamItem(1.369935, 4)},
    {766, IbltParamItem(1.373368, 4)}, {767, IbltParamItem(1.371578, 4)}, {768, IbltParamItem(1.369792, 4)},
    {769, IbltParamItem(1.373212, 4)}, {770, IbltParamItem(1.371429, 4)}, {771, IbltParamItem(1.369650, 4)},
    {772, IbltParamItem(1.367876, 4)}, {773, IbltParamItem(1.371281, 4)}, {774, IbltParamItem(1.369509, 4)},
    {775, IbltParamItem(1.372903, 4)}, {776, IbltParamItem(1.371134, 4)}, {777, IbltParamItem(1.369369, 4)},
    {778, IbltParamItem(1.372751, 4)}, {779, IbltParamItem(1.370988, 4)}, {780, IbltParamItem(1.369231, 4)},
    {781, IbltParamItem(1.372599, 4)}, {782, IbltParamItem(1.370844, 4)}, {783, IbltParamItem(1.369093, 4)},
    {784, IbltParamItem(1.367347, 4)}, {785, IbltParamItem(1.370701, 4)}, {786, IbltParamItem(1.374046, 4)},
    {787, IbltParamItem(1.367217, 4)}, {788, IbltParamItem(1.370558, 4)}, {789, IbltParamItem(1.368821, 4)},
    {790, IbltParamItem(1.372152, 4)}, {791, IbltParamItem(1.370417, 4)}, {792, IbltParamItem(1.368687, 4)},
    {793, IbltParamItem(1.372005, 4)}, {794, IbltParamItem(1.370277, 4)}, {795, IbltParamItem(1.368553, 4)},
    {796, IbltParamItem(1.371859, 4)}, {797, IbltParamItem(1.370138, 4)}, {798, IbltParamItem(1.368421, 4)},
    {799, IbltParamItem(1.371715, 4)}, {800, IbltParamItem(1.370000, 4)}, {801, IbltParamItem(1.368290, 4)},
    {802, IbltParamItem(1.366584, 4)}, {803, IbltParamItem(1.364882, 4)}, {804, IbltParamItem(1.368159, 4)},
    {805, IbltParamItem(1.366460, 4)}, {806, IbltParamItem(1.369727, 4)}, {807, IbltParamItem(1.368030, 4)},
    {808, IbltParamItem(1.371287, 4)}, {809, IbltParamItem(1.364648, 4)}, {810, IbltParamItem(1.367901, 4)},
    {811, IbltParamItem(1.371147, 4)}, {812, IbltParamItem(1.369458, 4)}, {813, IbltParamItem(1.367774, 4)},
    {814, IbltParamItem(1.371007, 4)}, {815, IbltParamItem(1.369325, 4)}, {816, IbltParamItem(1.362745, 4)},
    {817, IbltParamItem(1.365973, 4)}, {818, IbltParamItem(1.369193, 4)}, {819, IbltParamItem(1.367521, 4)},
    {820, IbltParamItem(1.370732, 4)}, {821, IbltParamItem(1.369062, 4)}, {822, IbltParamItem(1.367397, 4)},
    {823, IbltParamItem(1.365735, 4)}, {824, IbltParamItem(1.368932, 4)}, {825, IbltParamItem(1.367273, 4)},
    {826, IbltParamItem(1.370460, 4)}, {827, IbltParamItem(1.368803, 4)}, {828, IbltParamItem(1.367150, 4)},
    {829, IbltParamItem(1.370326, 4)}, {830, IbltParamItem(1.363855, 4)}, {831, IbltParamItem(1.367028, 4)},
    {832, IbltParamItem(1.365385, 4)}, {833, IbltParamItem(1.368547, 4)}, {834, IbltParamItem(1.366906, 4)},
    {835, IbltParamItem(1.370060, 4)}, {836, IbltParamItem(1.368421, 4)}, {837, IbltParamItem(1.371565, 4)},
    {838, IbltParamItem(1.365155, 4)}, {839, IbltParamItem(1.363528, 4)}, {840, IbltParamItem(1.366667, 4)},
    {841, IbltParamItem(1.365042, 4)}, {842, IbltParamItem(1.368171, 4)}, {843, IbltParamItem(1.366548, 4)},
    {844, IbltParamItem(1.364929, 4)}, {845, IbltParamItem(1.368047, 4)}, {846, IbltParamItem(1.366430, 4)},
    {847, IbltParamItem(1.369540, 4)}, {848, IbltParamItem(1.367925, 4)}, {849, IbltParamItem(1.366313, 4)},
    {850, IbltParamItem(1.364706, 4)}, {851, IbltParamItem(1.367803, 4)}, {852, IbltParamItem(1.366197, 4)},
    {853, IbltParamItem(1.369285, 4)}, {854, IbltParamItem(1.367681, 4)}, {855, IbltParamItem(1.366082, 4)},
    {856, IbltParamItem(1.369159, 4)}, {857, IbltParamItem(1.367561, 4)}, {858, IbltParamItem(1.365967, 4)},
    {859, IbltParamItem(1.364377, 4)}, {860, IbltParamItem(1.367442, 4)}, {861, IbltParamItem(1.365854, 4)},
    {862, IbltParamItem(1.368910, 4)}, {863, IbltParamItem(1.367323, 4)}, {864, IbltParamItem(1.365741, 4)},
    {865, IbltParamItem(1.364162, 4)}, {866, IbltParamItem(1.367206, 4)}, {867, IbltParamItem(1.365629, 4)},
    {868, IbltParamItem(1.364055, 4)}, {869, IbltParamItem(1.367089, 4)}, {870, IbltParamItem(1.365517, 4)},
    {871, IbltParamItem(1.363949, 4)}, {872, IbltParamItem(1.366972, 4)}, {873, IbltParamItem(1.365407, 4)},
    {874, IbltParamItem(1.368421, 4)}, {875, IbltParamItem(1.362286, 4)}, {876, IbltParamItem(1.365297, 4)},
    {877, IbltParamItem(1.363740, 4)}, {878, IbltParamItem(1.366743, 4)}, {879, IbltParamItem(1.365188, 4)},
    {880, IbltParamItem(1.363636, 4)}, {881, IbltParamItem(1.362089, 4)}, {882, IbltParamItem(1.369615, 4)},
    {883, IbltParamItem(1.363533, 4)}, {884, IbltParamItem(1.366516, 4)}, {885, IbltParamItem(1.364972, 4)},
    {886, IbltParamItem(1.363431, 4)}, {887, IbltParamItem(1.366404, 4)}, {888, IbltParamItem(1.364865, 4)},
    {889, IbltParamItem(1.367829, 4)}, {890, IbltParamItem(1.366292, 4)}, {891, IbltParamItem(1.364759, 4)},
    {892, IbltParamItem(1.363229, 4)}, {893, IbltParamItem(1.361702, 4)}, {894, IbltParamItem(1.364653, 4)},
    {895, IbltParamItem(1.363128, 4)}, {896, IbltParamItem(1.366071, 4)}, {897, IbltParamItem(1.364548, 4)},
    {898, IbltParamItem(1.363029, 4)}, {899, IbltParamItem(1.361513, 4)}, {900, IbltParamItem(1.364444, 4)},
    {901, IbltParamItem(1.362930, 4)}, {902, IbltParamItem(1.361419, 4)}, {903, IbltParamItem(1.364341, 4)},
    {904, IbltParamItem(1.362832, 4)}, {905, IbltParamItem(1.365746, 4)}, {906, IbltParamItem(1.364238, 4)},
    {907, IbltParamItem(1.362734, 4)}, {908, IbltParamItem(1.365639, 4)}, {909, IbltParamItem(1.364136, 4)},
    {910, IbltParamItem(1.362637, 4)}, {911, IbltParamItem(1.365532, 4)}, {912, IbltParamItem(1.364035, 4)},
    {913, IbltParamItem(1.366922, 4)}, {914, IbltParamItem(1.365427, 4)}, {915, IbltParamItem(1.363934, 4)},
    {916, IbltParamItem(1.362445, 4)}, {917, IbltParamItem(1.365322, 4)}, {918, IbltParamItem(1.363834, 4)},
    {919, IbltParamItem(1.362350, 4)}, {920, IbltParamItem(1.365217, 4)}, {921, IbltParamItem(1.363735, 4)},
    {922, IbltParamItem(1.366594, 4)}, {923, IbltParamItem(1.360780, 4)}, {924, IbltParamItem(1.363636, 4)},
    {925, IbltParamItem(1.362162, 4)}, {926, IbltParamItem(1.360691, 4)}, {927, IbltParamItem(1.363538, 4)},
    {928, IbltParamItem(1.362069, 4)}, {929, IbltParamItem(1.364909, 4)}, {930, IbltParamItem(1.363441, 4)},
    {931, IbltParamItem(1.361976, 4)}, {932, IbltParamItem(1.360515, 4)}, {933, IbltParamItem(1.363344, 4)},
    {934, IbltParamItem(1.366167, 4)}, {935, IbltParamItem(1.360428, 4)}, {936, IbltParamItem(1.363248, 4)},
    {937, IbltParamItem(1.366062, 4)}, {938, IbltParamItem(1.364606, 4)}, {939, IbltParamItem(1.363152, 4)},
    {940, IbltParamItem(1.361702, 4)}, {941, IbltParamItem(1.364506, 4)}, {942, IbltParamItem(1.363057, 4)},
    {943, IbltParamItem(1.361612, 4)}, {944, IbltParamItem(1.360169, 4)}, {945, IbltParamItem(1.362963, 4)},
    {946, IbltParamItem(1.361522, 4)}, {947, IbltParamItem(1.364308, 4)}, {948, IbltParamItem(1.362869, 4)},
    {949, IbltParamItem(1.361433, 4)}, {950, IbltParamItem(1.360000, 4)}, {951, IbltParamItem(1.362776, 4)},
    {952, IbltParamItem(1.361345, 4)}, {953, IbltParamItem(1.364113, 4)}, {954, IbltParamItem(1.362683, 4)},
    {955, IbltParamItem(1.365445, 4)}, {956, IbltParamItem(1.359833, 4)}, {957, IbltParamItem(1.362591, 4)},
    {958, IbltParamItem(1.361169, 4)}, {959, IbltParamItem(1.359750, 4)}, {960, IbltParamItem(1.362500, 4)},
    {961, IbltParamItem(1.361082, 4)}, {962, IbltParamItem(1.359667, 4)}, {963, IbltParamItem(1.362409, 4)},
    {964, IbltParamItem(1.365145, 4)}, {965, IbltParamItem(1.363731, 4)}, {966, IbltParamItem(1.362319, 4)},
    {967, IbltParamItem(1.360910, 4)}, {968, IbltParamItem(1.363636, 4)}, {969, IbltParamItem(1.362229, 4)},
    {970, IbltParamItem(1.360825, 4)}, {971, IbltParamItem(1.359423, 4)}, {972, IbltParamItem(1.362140, 4)},
    {973, IbltParamItem(1.364851, 4)}, {974, IbltParamItem(1.363450, 4)}, {975, IbltParamItem(1.362051, 4)},
    {976, IbltParamItem(1.360656, 4)}, {977, IbltParamItem(1.363357, 4)}, {978, IbltParamItem(1.361963, 4)},
    {979, IbltParamItem(1.360572, 4)}, {980, IbltParamItem(1.363265, 4)}, {981, IbltParamItem(1.361876, 4)},
    {982, IbltParamItem(1.360489, 4)}, {983, IbltParamItem(1.359105, 4)}, {984, IbltParamItem(1.361789, 4)},
    {985, IbltParamItem(1.360406, 4)}, {986, IbltParamItem(1.359026, 4)}, {987, IbltParamItem(1.361702, 4)},
    {988, IbltParamItem(1.360324, 4)}, {989, IbltParamItem(1.362993, 4)}, {990, IbltParamItem(1.361616, 4)},
    {991, IbltParamItem(1.360242, 4)}, {992, IbltParamItem(1.358871, 4)}, {993, IbltParamItem(1.361531, 4)},
    {994, IbltParamItem(1.360161, 4)}, {995, IbltParamItem(1.362814, 4)}, {996, IbltParamItem(1.357430, 4)},
    {997, IbltParamItem(1.360080, 4)}, {998, IbltParamItem(1.362725, 4)}, {999, IbltParamItem(1.361361, 4)},
    {1000, IbltParamItem(1.360000, 4)},
};
