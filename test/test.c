#include <sncore/defines.h>
#include <sncore/types.h>
#include <sncore/utf.h>

int main(void) {
    if (sn_utf8_to_utf16("abc", NULL, 0) == 0) return 1;

    if (sn_utf16_to_utf8(L"abc", NULL, 0) == 0) return 2;

    void *mem = sn_std_allocator.alloc(sn_std_allocator.data, 100, 50);
    if (!SN_IS_ALIGNED(mem, 50)) return 3;
    void *new_mem = sn_std_allocator.realloc(sn_std_allocator.data, mem, 500, 30);
    if (!new_mem) return 4;
    if (!SN_IS_ALIGNED(new_mem, 30)) return 5;
    sn_std_allocator.free(sn_std_allocator.data, new_mem);

    return 0;
}
