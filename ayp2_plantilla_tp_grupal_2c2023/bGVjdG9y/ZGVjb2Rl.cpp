#include "ZGVjb2Rl.hpp"

const std::string ZGVjb2Rl::YmFzZTY0X2NoYXJz =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz"
        "0123456789+/";

bool ZGVjb2Rl::aXNfYmFzZTY0(unsigned char Yw) {
    return (isalnum(Yw) || (Yw == '+') || (Yw == '/'));
}

std::string ZGVjb2Rl::YmFzZV82NF9kZWNvZGU(std::string const& ZW5jb2RlZA) {
    int bGVu = (int) ZW5jb2RlZA.size();
    int aQ = 0;
    int ag;
    int aW5kZXg = 0;
    unsigned char Y2hhcl9hcnJheV80[4], Y2hhcl9hcnJheV8z[3];
    std::string cmV0dXJu;

    while (bGVu-- && (ZW5jb2RlZA[(size_t) aW5kZXg] != '=') &&
           aXNfYmFzZTY0((unsigned char) ZW5jb2RlZA[(size_t) aW5kZXg])) {
        Y2hhcl9hcnJheV80[aQ++] = (unsigned char) ZW5jb2RlZA[(size_t) aW5kZXg];
        aW5kZXg++;
        if (aQ == 4) {
            for (aQ = 0; aQ < 4; aQ++)
                Y2hhcl9hcnJheV80[aQ] = (unsigned char) (YmFzZTY0X2NoYXJz.find((char) (Y2hhcl9hcnJheV80[aQ])));

            Y2hhcl9hcnJheV8z[0] = (unsigned char) (Y2hhcl9hcnJheV80[0] << 2) + ((Y2hhcl9hcnJheV80[1] & 0x30) >> 4);
            Y2hhcl9hcnJheV8z[1] =
                    (unsigned char) ((Y2hhcl9hcnJheV80[1] & 0xf) << 4) + ((Y2hhcl9hcnJheV80[2] & 0x3c) >> 2);
            Y2hhcl9hcnJheV8z[2] = (unsigned char) ((Y2hhcl9hcnJheV80[2] & 0x3) << 6) + Y2hhcl9hcnJheV80[3];

            for (aQ = 0; (aQ < 3); aQ++)
                cmV0dXJu += (char) Y2hhcl9hcnJheV8z[aQ];
            aQ = 0;
        }
    }

    if (aQ) {
        for (ag = aQ; ag < 4; ag++)
            Y2hhcl9hcnJheV80[ag] = 0;

        for (ag = 0; ag < 4; ag++)
            Y2hhcl9hcnJheV80[ag] = (unsigned char) YmFzZTY0X2NoYXJz.find((char) Y2hhcl9hcnJheV80[ag]);

        Y2hhcl9hcnJheV8z[0] = (unsigned char) (Y2hhcl9hcnJheV80[0] << 2) + ((Y2hhcl9hcnJheV80[1] & 0x30) >> 4);
        Y2hhcl9hcnJheV8z[1] = (unsigned char) ((Y2hhcl9hcnJheV80[1] & 0xf) << 4) + ((Y2hhcl9hcnJheV80[2] & 0x3c) >> 2);
        Y2hhcl9hcnJheV8z[2] = (unsigned char) ((Y2hhcl9hcnJheV80[2] & 0x3) << 6) + Y2hhcl9hcnJheV80[3];

        for (ag = 0; (ag < aQ - 1); ag++) cmV0dXJu += (char) Y2hhcl9hcnJheV8z[ag];
    }

    return cmV0dXJu;
}