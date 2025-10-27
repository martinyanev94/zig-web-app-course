// c_lib.c
#include <stdio.h>

void hello_from_c() {
    printf("Hello from C!\n");
}
const std = @import("std");
const c = @cImport({
    @cInclude("c_lib.c");
});

pub fn main() void {
    c.hello_from_c();
}
