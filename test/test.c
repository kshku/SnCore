#include <sncore/utf.h>

int main(void) {
    if (sn_utf8_to_utf16("abc", 3, NULL, 0) == 0) return 1;

    if (sn_utf16_to_utf8(L"abc", 3, NULL, 0) == 0) return 2;

    return 0;
}
