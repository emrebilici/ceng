#include <iostream>

#include "tpbst.hpp"

int main() {
    TwoPhaseBST<int> tpbst;

    tpbst.print();
         tpbst.print("ceng213");
          tpbst.print("ceng213", "sec1");
        tpbst.insert("ceng213", "sec4", 4)
            .insert("ceng213", "sec2", 2)
            .insert("ceng213", "sec3", 3)
            .insert("ceng213", "sec10", 1)
            .insert("ceng213", "sec0", 0)
            .insert("ceng213", "sec6", 6)
            .insert("ceng213", "sec5", 5)
            .insert("ceng213", "sec8", 8)
            .insert("ceng213", "sec7", 7)
            .insert("ceng213", "sec9", 9)   
            .insert("ceng477", "sec2", 50)
            .insert("ceng477", "sec1", 49)
            .insert("ceng140", "sec1", 3)
            .insert("ceng140", "sec2", 9)
            .insert("ceng280", "sec1", 11)
            .insert("ceng232", "sec1", 12)
            .insert("ceng281", "sec1", 13)
            .insert("ceng499", "sec1", 133)

            .print()
          .print("ceng213")
          .print("ceng497")
          .print("ceng213", "sec1")
            .print("ceng477", "sec1")
            .remove("ceng140", "sec1")
            .remove("ceng140", "sec2")
             .remove("ceng499", "sec1")
            .print("ceng213", "")
            .print("ceng477","")
            .print()
        .print("ceng477","sec1");


    std::cout << "Number of enrolled students in ceng213 - sec3 is " << (tpbst.find("ceng213", "sec4")) << std::endl;

    return 0;
}